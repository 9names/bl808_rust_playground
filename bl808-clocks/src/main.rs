#![no_std]
#![no_main]

use panic_halt as _;

const SYSFREQ: u32 = 320_000_000;
use bl808_pac as pac;
use bl808_rom_wrapper::{rom::glb, types::bl808_glb::*};
use embedded_hal::blocking::delay::DelayMs;
use riscv::delay::McycleDelay;

fn system_clock_init() {
    // Set MCU and DSP core clocks
    glb::halt_cpu(GLB_CORE_ID_Type::GLB_CORE_ID_D0);
    glb::halt_cpu(GLB_CORE_ID_Type::GLB_CORE_ID_LP);
    glb::power_on_xtal_and_pll_clk(
        GLB_XTAL_Type::GLB_XTAL_40M,
        GLB_PLL_Type::GLB_PLL_WIFIPLL
            | GLB_PLL_Type::GLB_PLL_CPUPLL
            | GLB_PLL_Type::GLB_PLL_UHSPLL
            | GLB_PLL_Type::GLB_PLL_MIPIPLL,
    );
    glb::set_mcu_system_clk(GLB_MCU_SYS_CLK_Type::GLB_MCU_SYS_CLK_WIFIPLL_320M);
    glb::set_dsp_system_clk(GLB_DSP_SYS_CLK_Type::GLB_DSP_SYS_CLK_CPUPLL_400M);
    glb::halt_cpu(GLB_CORE_ID_Type::GLB_CORE_ID_D0);
    glb::halt_cpu(GLB_CORE_ID_Type::GLB_CORE_ID_LP);
}

#[riscv_rt::entry]
fn main() -> ! {
    system_clock_init();

    let mut delay = McycleDelay::new(SYSFREQ);
    let peris = unsafe { pac::Peripherals::steal() };
    let led = &peris.GLB.gpio_config[8];

    // Configure GP8 as an output pin
    led.modify(|_, w| {
        w.pin_mode().output();
        w.output_function().set_bit();
        w.input_function().clear_bit();
        w.pull_up().clear_bit();
        w.pull_down().clear_bit();
        w
    });
    loop {
        // Enable LED
        led.modify(|_, w| {
            w.output_clear().set_bit();
            w.output_set().clear_bit();
            w
        });
        delay.delay_ms(1000);

        // Disable LED
        led.modify(|_, w| {
            w.output_set().set_bit();
            w.output_clear().clear_bit();
            w
        });
        delay.delay_ms(1000);
    }
}
