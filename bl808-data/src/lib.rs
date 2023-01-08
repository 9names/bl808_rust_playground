use tracing::{event, instrument, Level};

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum ParseState {
    NoMatch,
    BlockName,
    BlockAddr,
    UnionStr,
    StructStr,
    Field,
    Size,
    Name,
}

pub enum ParseResult {
    Match(Vec<String>),
    Capture(Vec<String>),
}

#[macro_export]
macro_rules! regex {
    ($re:literal) => {{
        ::ref_thread_local::ref_thread_local! {
            static managed REGEX: ::regex::Regex = ::regex::Regex::new($re).unwrap();
        }
        <REGEX as ::ref_thread_local::RefThreadLocal<::regex::Regex>>::borrow(&REGEX)
    }};
}

#[instrument]
pub fn parse(state: ParseState, line: String, linenum: usize) -> (ParseState, Option<ParseResult>) {
    let mut state = state;
    let mut data: Vec<String> = vec![];
    match state {
        // Looking for start of register block: "struct glb_reg {"
        ParseState::NoMatch => if let Some(m) = regex!(r"\s*struct\s*([a-zA-Z_\d]*)\s*\{").captures(&line) {
            state = ParseState::BlockName;
            data.push(String::from(m.get(1).unwrap().as_str()));
            event!(Level::TRACE, "\nCaptures: {}", data[0]);
            (state, Some(ParseResult::Capture(data)))
        }else {
            event!(Level::TRACE, "\nMode {state:?} unhandled line {linenum}:{line}");
            (state, None)
        },
        // Looking for register address: "/* 0x0 : soc_info0 */""
        ParseState::BlockName => if let Some(m) = regex!(r"\s*\.*/* (0x\d*) : (.*) \*/").captures(&line) {
            state = ParseState::BlockAddr;
            data.push(String::from(m.get(1).unwrap().as_str()));
            data.push(String::from(m.get(2).unwrap().as_str()));
            event!(Level::TRACE, "\nCaptures: {}, {}", data[0], data[1]);
            (state, Some(ParseResult::Capture(data)))
        }else {
            event!(Level::TRACE, "\nMode {state:?} unhandled line {linenum}:{line}");
            (state, None)
        },
        // Looking for start of union: "union {"
        ParseState::BlockAddr => if let Some(m) = regex!(r"\s*union\s*\{").captures(&line) {
            state = ParseState::UnionStr;
            data.push(String::from(m.get(0).unwrap().as_str()));
            event!(Level::TRACE,"\nMatch: {}", data[0]);
            (state, Some(ParseResult::Match(data)))
        }else {
            event!(Level::TRACE, "\nMode {state:?} unhandled line {linenum}:{line}");
            (state, None)
        },
        // Looking for start of struct: "struct {"
        ParseState::UnionStr => if let Some(m) = regex!(r"\s*struct\s*\{").captures(&line) {
            state = ParseState::StructStr;
            data.push(String::from(m.get(0).unwrap().as_str()));
            event!(Level::TRACE,"\nMatch: {}", data[0]);
            (state, Some(ParseResult::Match(data)))
        }else {
            event!(Level::TRACE, "\nMode {state:?} unhandled line {linenum}:{line}");
            (state, None)
        },
        // Looking for field or end of struct:
        // Field: "uint32_t reserved_0_26 : 27; /* [26: 0],       rsvd,        0x0 */"
        // End of struct:  "} BF;"
        ParseState::StructStr => {
            if let Some(m) = regex!(r"\s*uint32_t *([a-zA-Z_\d]*) *: *(\d*); */\* *\[([\d: ]*)\],\s*([r/wsvd]*)\s*,\s*(0x[\da-fA-F]*) \*/.*").captures(&line) {
                state = ParseState::StructStr;
                data.push(String::from(m.get(1).unwrap().as_str()));
                data.push(String::from(m.get(2).unwrap().as_str()));
                data.push(String::from(m.get(3).unwrap().as_str()));
                data.push(String::from(m.get(4).unwrap().as_str()));
                data.push(String::from(m.get(5).unwrap().as_str()));
                event!(Level::TRACE,"\nCaptures: {}, {}, {}, {}, {}", data[0], data[1], data[2], data[3], data[4]);
                (state, Some(ParseResult::Capture(data)))
            }
            else {
                event!(Level::TRACE,"BF capture, moving to field parsing");
                if let Some(m) = regex!(r"\s*} *BF;").captures(&line) {
                    state = ParseState::Size;
                    data.push(String::from(m.get(0).unwrap().as_str()));
                    event!(Level::TRACE,"\nMatch: {}", data[0]);
                    (state, Some(ParseResult::Match(data)))
                } else {
                    event!(Level::TRACE, "\nMode {state:?} unhandled line {linenum}:{line}");
                    event!(Level::TRACE,"No Capture, moving to field parsing");
                    state = ParseState::Field;
                    (state, None)
                }
                
            }
        },
        // End of struct (in case we missed it):  "} BF;"
        ParseState::Field => if let Some(m) = regex!(r"\s*} *BF;").captures(&line) {
            state = ParseState::Size;
            data.push(String::from(m.get(0).unwrap().as_str()));
            event!(Level::TRACE,"\nMatch: {}", data[0]);
            (state, Some(ParseResult::Match(data)))
        } else {
            event!(Level::TRACE, "\nMode {state:?} unhandled line {linenum}:{line}");
            (state, None)
        },
        // Looking for 2nd union member: "uint32_t WORD;"
        ParseState::Size => if let Some(m) = regex!(r"\s*uint32_t WORD;").captures(&line) {
            state = ParseState::Name;
            data.push(String::from(m.get(0).unwrap().as_str()));
            event!(Level::TRACE,"\nMatch: {}", data[0]);
            (state, Some(ParseResult::Match(data))) 
        }else {
            event!(Level::TRACE, "\nMode {state:?} unhandled line {linenum}:{line}");
            (state, None)
        },
        // Looking for name of the union: "} soc_info0;"
        ParseState::Name => if let Some(m) = regex!(r"\s*} ([a-z_\-\d]*);").captures(&line) {
            state = ParseState::BlockName;
            data.push(String::from(m.get(1).unwrap().as_str()));
            event!(Level::TRACE,"\nCaptures: {}", data[0]);
            (state, Some(ParseResult::Capture(data)))
        }else {
            event!(Level::TRACE, "\nMode {state:?} unhandled line {linenum}:{line}");
            (state, None)
        },
    }
}
