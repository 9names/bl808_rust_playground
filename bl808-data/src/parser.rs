use core::fmt;

use crate::{parseit, ParseState};

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Register {
    name: String,
    description: String,
    address_offset: String,
    fields: Vec<Field>,
    reset_value: Option<String>,
}

impl Register {
    fn new() -> Register {
        Register {
            name: "".to_string(),
            description: "".to_string(),
            address_offset: "".to_string(),
            fields: vec![],
            reset_value: None,
        }
    }
}

impl fmt::Display for Register {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        // Assuming u32 register sizes for now
        // Calculate reset value
        let mut reset_value: u32 = 0;
        for field in &self.fields {
            if let Some(reset_value_str) = field.reset_value.strip_prefix("0x") {
                let value = u32::from_str_radix(reset_value_str, 16).unwrap();
                let offset = field.lsb.parse::<u32>().unwrap();
                reset_value += value << offset;
            }
        }
        write!(f, "<register>\n<name>{}</name>\n<description>{}</description>\n<addressOffset>{}</addressOffset>\n<resetValue>{:#010X}</resetValue>\n<fields>\n", self.name, self.description, self.address_offset, reset_value)?;
        for field in &self.fields {
            write!(f, "{}", field)?;
        }
        write!(f, "</fields>\n</register>",)
    }
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct Field {
    name: String,
    description: String,
    lsb: String,
    msb: String,
    access: String,
    reset_value: String,
}

impl Field {
    fn new() -> Field {
        Field {
            name: "".to_string(),
            description: "".to_string(),
            lsb: "".to_string(),
            msb: "".to_string(),
            access: "".to_string(),
            reset_value: "".to_string(),
        }
    }
}

/// SVD uses different strings to represent access modifiers than what is used in the SDK headers.
/// map these through to SVD versions
fn svd_access_map(access: &str) -> &str {
    match access {
        "r/w" => "read-write",
        "r" => "read-only",
        "w" => "write-only",
        "rsvd" => "read-only",
        _ => "UNMAPPED_PLZ_FIX",
    }
}

impl fmt::Display for Field {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(
            f,
            "<field>\n<name>{}</name>\n<description>{}</description>\n<bitRange>[{}:{}]</bitRange>\n<access>{}</access>\n</field>\n",
            self.name, self.description, self.msb, self.lsb, svd_access_map(&self.access),
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
                            // [0] is the field name
                            // [1] is field width
                            // [2] is range of bits
                            // [3] is access modifier
                            // [4] is reset value

                            field.name = c[0].trim().to_string();
                            // c[1] is number of bits, we don't need that.
                            if c[2].contains(':') {
                                let mut c_arr = c[2].split(':');
                                let msb = c_arr.next();
                                let lsb = c_arr.next();
                                field.msb = msb.unwrap().trim().to_string();
                                field.lsb = lsb.unwrap().trim().to_string();
                            } else {
                                field.msb = c[2].trim().to_string();
                                field.lsb = field.msb.clone();
                            }
                            field.access = c[3].trim().to_string();
                            field.reset_value = c[4].trim().to_string();
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
                            field.name = c[0].trim().to_string();
                            // c[1] is number of bits, we don't need that.
                            if c[2].contains(':') {
                                let mut c_arr = c[2].split(':');
                                let msb = c_arr.next();
                                let lsb = c_arr.next();
                                field.msb = msb.unwrap().trim().to_string();
                                field.lsb = lsb.unwrap().trim().to_string();
                            } else {
                                field.msb = c[2].trim().to_string();
                                field.lsb = field.msb.clone();
                            }
                            field.access = c[3].trim().to_string();
                            field.reset_value = c[4].trim().to_string();
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
