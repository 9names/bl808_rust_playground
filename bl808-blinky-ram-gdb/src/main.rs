#![no_std]
#![no_main]

use panic_halt as _;

const SYSFREQ: u32 = 320_000_000;
use bl808_pac as pac;
use embedded_hal::blocking::delay::DelayMs;
use embedded_hal::blocking::delay::DelayUs;
use riscv::delay::McycleDelay;

#[riscv_rt::entry]
fn main() -> ! {
    let mut delay = McycleDelay::new(SYSFREQ);
    let peris = unsafe { pac::Peripherals::steal() };
    let led = &peris.GLB.gpio_config[18];
    // Configure GP8 as an output pin
    led.modify(|_, w| {
        w.pin_mode().output();
        w.output_function().set_bit();
        w.input_function().clear_bit();
        w.pull_up().clear_bit();
        w.pull_down().clear_bit();
        w
    });

    let tms = &peris.GLB.gpio_config[27];
    let tclk = &peris.GLB.gpio_config[26];
    tms.modify(|_, w| {
        // w.input_function().variant(true);
        // w.output_function().variant(true);
        w.pull_down().clear_bit();
        w.output_function().clear_bit();
        w.input_function().clear_bit();
        w.pull_up().set_bit();
        w.pin_mode().alternate();
        w.alternate().jtag_lp();
        unsafe { w.drive().bits(1) };
        w.schmitt().set_bit();
        // unsafe {w.alternate().bits(14)};
        w
    });
    tclk.modify(|_, w| {
        w.pull_down().clear_bit();
        w.pull_up().clear_bit();
        w.output_function().clear_bit();
        w.input_function().clear_bit();
        w.pin_mode().alternate();
        // w.input_function().variant(true);
        // w.output_function().variant(true);
        w.alternate().jtag_lp();
        unsafe { w.drive().bits(1) };
        w.schmitt().set_bit();
        // unsafe {w.alternate().bits(14)};
        w
    });

    // HALT
    // case GLB_CORE_ID_LP:
    // PDS_Set_LP_Clock_Disable();
    // arch_delay_us(1);
    // tmpVal = BL_RD_REG(GLB_BASE, GLB_SWRST_CFG2);
    // tmpVal = BL_SET_REG_BIT(tmpVal, GLB_REG_CTRL_PICO_RESET);
    // BL_WR_REG(GLB_BASE, GLB_SWRST_CFG2, tmpVal);
    // break;

    // RELEASE:
    // PDS_Set_LP_Clock_Enable();
    // arch_delay_us(1);
    // tmpVal = BL_RD_REG(GLB_BASE, GLB_SWRST_CFG2);
    // tmpVal = BL_CLR_REG_BIT(tmpVal, GLB_REG_CTRL_PICO_RESET);
    // BL_WR_REG(GLB_BASE, GLB_SWRST_CFG2, tmpVal);

    // &peris.PDS.
    // PDS_BASE         ((uint32_t)0x4000E000)
    // PDS_CPU_CORE_CFG0_OFFSET (0x110)
    // PDS_REG_PICO_CLK_EN_POS  (28U)
    const PDS_BASE:usize = 0x4000E000;
    const PDS_CPU_CORE_CFG0_OFFSET:usize = 0x100;
    const PDS_REG_PICO_CLK_EN_POS:usize = 28;
    let core_cfg = (PDS_BASE + PDS_CPU_CORE_CFG0_OFFSET) as *mut u32;

    // GLB_SWRST_CFG2_OFFSET           (0x548)
    // GLB_REG_CTRL_PICO_RESET_POS     (3U)
    const GLB_BASE:usize = 0x20000000;
    const GLB_SWRST_CFG2_OFFSET:usize = 0x548;
    const GLB_REG_CTRL_PICO_RESET_POS:usize = 3;
    let sw_rst = (GLB_BASE + GLB_SWRST_CFG2_OFFSET) as *mut u32;
    
    unsafe {
       *core_cfg = *core_cfg | (1 << PDS_REG_PICO_CLK_EN_POS);
       delay.delay_us(1);
       *sw_rst = *sw_rst & !(1 << GLB_REG_CTRL_PICO_RESET_POS);
    }

    loop {
        // Enable LED
        led.modify(|_, w| {
            
            w.output_clear().set_bit();
            w.output_set().clear_bit();
            w
        });
        delay.delay_ms(200);

        // Disable LED
        led.modify(|_, w| {
            w.output_set().set_bit();
            w.output_clear().clear_bit();
            w
        });
        delay.delay_ms(200);
    }
}
