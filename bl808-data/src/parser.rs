use core::fmt;

use crate::{parseit, ParseState};

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Register {
    name: String,
    description: String,
    address_offset: String,
    fields: Vec<Field>,
}

impl Register {
    fn new() -> Register {
        Register {
            name: "".to_string(),
            description: "".to_string(),
            address_offset: "".to_string(),
            fields: vec![],
        }
    }
}

impl fmt::Display for Register {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "<register>\n<name>{}</name>\n<description>{}</description>\n<address_offset>{}</address_offset>\n<fields>\n", self.name, self.description, self.address_offset)?;
        for field in &self.fields {
            write!(f, "{}", field)?;
        }
        write!(f, "</fields>\n</register>")
    }
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Field {
    name: String,
    description: String,
    lsb: String,
    msb: String,
}

impl Field {
    fn new() -> Field {
        Field {
            name: "".to_string(),
            description: "".to_string(),
            lsb: "".to_string(),
            msb: "".to_string(),
        }
    }
}

impl fmt::Display for Field {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(
            f,
            "<field>\n<name>{}</name>\n<description>{}</description>\n<lsb>{}</lsb>\n<msb>{}</msb>\n</field>\n",
            self.name, self.description, self.lsb, self.msb,
        )
    }
}

#[derive(Debug)]
pub struct Parser {
    state: ParseState,
    register: Option<Register>,
    registers: Vec<Register>,
}

impl Parser {
    pub fn new() -> Parser {
        Parser {
            state: ParseState::NoMatch,
            register: None,
            registers: vec![],
        }
    }

    pub fn parse(&mut self, line_num: usize, line: String) {
        let (newstate, parse_result) = parseit(self.state, line, line_num);
        match newstate {
            ParseState::NoMatch => {}
            ParseState::BlockName => {
                if let Some(parse) = parse_result {
                    match parse {
                        crate::ParseResult::Match(_n) => {
                            // println!("whats my name? {n:?}")
                        }
                        crate::ParseResult::Capture(c) => {
                            if let Some(reg) = self.register.as_mut() {
                                reg.name = c[0].clone();
                            }
                        }
                    }
                }
            }
            ParseState::BlockAddr => {
                if let Some(parse) = parse_result {
                    if let Some(reg) = &self.register {
                        self.registers.push(reg.clone());
                    }
                    let mut reg = Register::new();
                    match parse {
                        crate::ParseResult::Match(_) => panic!("Not expecting match"),
                        crate::ParseResult::Capture(c) => {
                            reg.address_offset = c[0].clone();
                            reg.description = c[1].clone();
                        }
                    }
                    self.register = Some(reg);
                }
            }
            ParseState::UnionStr => {}
            ParseState::StructStr => {
                if let Some(parse) = parse_result {
                    let mut field = Field::new();
                    match parse {
                        crate::ParseResult::Match(_m) => {
                            // println!("what a match: {m:?}")
                        }
                        crate::ParseResult::Capture(c) => {
                            field.name = c[0].clone();
                            // c[1] is number of bits, we don't need that.
                            if c[2].contains(':') {
                                let mut c_arr = c[2].split(':');
                                let msb = c_arr.next();
                                let lsb = c_arr.next();
                                field.msb = msb.unwrap().to_string();
                                field.lsb = lsb.unwrap().to_string();
                            } else {
                                field.msb = c[2].clone();
                                field.lsb = c[2].clone();
                            }
                            field.name = c[0].clone();
                        }
                    }
                    if let Some(reg) = self.register.as_mut() {
                        // TODO: don't generate empty field so we don't have to skip it
                        if !field.name.trim().is_empty() {
                            reg.fields.push(field);
                        }
                    }
                }
            }
            ParseState::Field => {
                if let Some(parse) = parse_result {
                    let mut field = Field::new();
                    match parse {
                        crate::ParseResult::Match(_) => panic!("Not expecting match"),
                        crate::ParseResult::Capture(c) => {
                            field.name = c[0].clone();
                            // c[1] is number of bits, we don't need that.
                            if c[2].contains(':') {
                                let mut c_arr = c[2].split(':');
                                let msb = c_arr.next();
                                let lsb = c_arr.next();
                                field.msb = msb.unwrap().to_string();
                                field.lsb = lsb.unwrap().to_string();
                            } else {
                                field.msb = c[2].clone();
                                field.lsb = c[2].clone();
                            }
                            field.name = c[0].clone();
                        }
                    }
                    // println!("field  {field:?}");
                    if let Some(reg) = self.register.as_mut() {
                        reg.fields.push(field);
                    }
                } else {
                    // println!("fielding the wrong question?");
                }
            }
            ParseState::Size => {}
            ParseState::Name => {
                if let Some(parse) = parse_result {
                    match parse {
                        crate::ParseResult::Match(_n) => {
                            // println!("whats my name? {n:?}")
                        }
                        crate::ParseResult::Capture(c) => {
                            if let Some(reg) = self.register.as_mut() {
                                reg.name = c[0].clone();
                            }
                        }
                    }
                }
            }
        }
        self.state = newstate
    }
    pub fn registers(&self) -> Vec<Register> {
        self.registers.clone()
    }
}

impl Default for Parser {
    fn default() -> Self {
        Self::new()
    }
}
