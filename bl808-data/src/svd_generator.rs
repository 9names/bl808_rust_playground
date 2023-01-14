use bl808_data::parser::Parser;
use bl808_data::svd_fragments;
use tracing::Level;
use tracing_subscriber::FmtSubscriber;

#[macro_export]
macro_rules! regex {
    ($re:literal) => {{
        ::ref_thread_local::ref_thread_local! {
            static managed REGEX: ::regex::Regex = ::regex::Regex::new($re).unwrap();
        }
        <REGEX as ::ref_thread_local::RefThreadLocal<::regex::Regex>>::borrow(&REGEX)
    }};
}

fn peripheral(filename: &str, fragment: &str) -> Result<(), std::io::Error> {
    let f = std::fs::read(filename)?;

    // Create our parse context
    let mut parser = Parser::new();

    println!("<peripheral>\n{}", fragment);
    // Run all the input through the parser
    for (linenum, l) in f.split(|b| b == &b'\n').enumerate() {
        let l = String::from_utf8_lossy(l);
        parser.parse(linenum, l.to_string());
    }

    // Dump out all the registers
    for register in parser.registers() {
        print!("{}", register);
    }
    print!("\n</peripheral>");
    Ok(())
}

fn main() -> anyhow::Result<()> {
    // Use tracing to get good debug tracing, and register stdout as a tracing subscriber
    let subscriber = FmtSubscriber::builder()
        .with_max_level(Level::INFO) // Set this to DEBUG or TRACE to get debugging info
        .finish();
    tracing::subscriber::set_global_default(subscriber).expect("setting default subscriber failed");
    println!("{}", svd_fragments::HEADER);
    let _ = peripheral("sources/headers/bl_mcu_sdk/glb_reg.h", svd_fragments::GLB);
    println!("{}", svd_fragments::FOOTER);

    Ok(())
}
