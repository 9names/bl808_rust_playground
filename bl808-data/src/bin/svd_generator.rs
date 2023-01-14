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

// Convenience wrapper for calling with a single filename
fn peripheral(filename: &str, fragment: &str) -> Result<(), std::io::Error> {
    peripherals(&[filename], fragment)
}

fn peripherals(filenames: &[&str], fragment: &str) -> Result<(), std::io::Error> {
    // Create our parse context
    let mut parser = Parser::new();

    println!("<peripheral>\n{}<registers>\n", fragment);

    for filename in filenames {
        let f = std::fs::read(filename)?;
        for (linenum, l) in f.split(|b| b == &b'\n').enumerate() {
            let l = String::from_utf8_lossy(l);
            parser.parse(linenum, l.to_string());
        }
    }

    // Dump out all the registers
    for register in parser.registers() {
        print!("{}", register);
    }
    print!("\n</registers>\n</peripheral>");
    Ok(())
}

fn main() -> anyhow::Result<()> {
    // Use tracing to get good debug tracing, and register stdout as a tracing subscriber
    let subscriber = FmtSubscriber::builder()
        .with_max_level(Level::INFO) // Set this to DEBUG or TRACE to get debugging info
        .finish();
    tracing::subscriber::set_global_default(subscriber).expect("setting default subscriber failed");
    print!("{}", svd_fragments::HEADER);
    let _ = peripheral(
        "sources/headers/bl_mcu_sdk/codec_misc_reg.h",
        svd_fragments::CODEC,
    );
    let _ = peripheral("sources/headers/bl_mcu_sdk/aon_reg.h", svd_fragments::AON);
    let _ = peripheral("sources/headers/bl_mcu_sdk/cci_reg.h", svd_fragments::CCI);
    // Display controller?
    // let _ = peripheral("sources/headers/bl_mcu_sdk/dtsrc_reg.h", svd_fragments::);
    let _ = peripherals(
        &[
            "sources/headers/bl_mcu_sdk/ef_ctrl_reg.h",
            "sources/headers/bl_mcu_sdk/ef_data_0_reg.h",
            "sources/headers/bl_mcu_sdk/ef_data_1_reg.h",
        ],
        svd_fragments::EF_DATA,
    );
    let _ = peripheral("sources/headers/bl_mcu_sdk/glb_reg.h", svd_fragments::GLB);
    let _ = peripheral("sources/headers/bl_mcu_sdk/gpip_reg.h", svd_fragments::GPIP);
    let _ = peripheral("sources/headers/bl_mcu_sdk/hbn_reg.h", svd_fragments::HBN);
    let _ = peripheral("sources/headers/bl_mcu_sdk/ipc_reg.h", svd_fragments::IPC0);
    let _ = peripheral(
        "sources/headers/bl_mcu_sdk/mcu_misc_reg.h",
        svd_fragments::MCU_MISC,
    );
    // These might be for c906
    // let _ = peripheral("sources/headers/bl_mcu_sdk/mm_glb_reg.h", svd_fragments::GLB);
    // let _ = peripheral("sources/headers/bl_mcu_sdk/mm_misc_reg.h", svd_fragments::);
    let _ = peripheral("sources/headers/bl_mcu_sdk/pds_reg.h", svd_fragments::PDS);
    let _ = peripherals(
        &[
            "sources/headers/bl_mcu_sdk/psram_reg.h",
            "sources/headers/bl_mcu_sdk/psram_uhs_reg.h",
        ],
        svd_fragments::PSRAM_CTRL,
    );
    let _ = peripheral("sources/headers/bl_mcu_sdk/sdh_reg.h", svd_fragments::SDH);

    // let _ = peripheral("sources/headers/bl_mcu_sdk/sf_ctrl_reg.h", svd_fragments::SF_CTRL);

    // let _ = peripheral("sources/headers/bl_mcu_sdk/tzc_nsec_reg.h", svd_fragments::TZC_NSEC);
    // let _ = peripheral("sources/headers/bl_mcu_sdk/tzc_sec_reg.h", svd_fragments::TZC_SEC);
    // let _ = peripheral("sources/headers/bl_mcu_sdk/.h", svd_fragments::);

    println!("{}", svd_fragments::FOOTER);

    Ok(())
}
