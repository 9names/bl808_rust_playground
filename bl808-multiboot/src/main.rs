#![no_std]
#![no_main]

use panic_halt as _;

const SYSFREQ: u32 = 320_000_000;
use bl808_pac as pac;
use embedded_hal::blocking::delay::DelayMs;
use embedded_hal::blocking::delay::DelayUs;
use riscv::delay::McycleDelay;

// include the D0 firmware in this binary. doesn't work yet. TODO.

// const D0_FIRMWARE_SIZE:usize = include_bytes!("../../bl808-d0-blinky/d0_blinky.bin").len();
// #[link_section = ".d0"]
// #[used]
// pub static D0_FIRMWARE: [u8; D0_FIRMWARE_SIZE] = *include_bytes!("../../bl808-d0-blinky/d0_blinky.bin");

#[riscv_rt::entry]
fn main() -> ! {
    let mut delay = McycleDelay::new(SYSFREQ);
    let peris = unsafe { pac::Peripherals::steal() };

    // Set up GPIOs as outputs now
    // this will make it easier to test LP/D0 firmware
    // GPIO18 is used for LP core
    // GPIO17 is used for M0 core
    // GPIO16 is used for D0 core
    let led_lp = &peris.GLB.gpio_cfg18;
    led_lp.modify(|_, w| {
        unsafe {
            w.reg_gpio_18_func_sel().bits(11);
        }
        w.reg_gpio_18_ie().clear_bit();
        w.reg_gpio_18_oe().set_bit();
        w.reg_gpio_18_pd().clear_bit();
        w.reg_gpio_18_pu().clear_bit();
        w
    });

    // Set up GPIO 17 for m0
    let led = &peris.GLB.gpio_cfg17;
    led.modify(|_, w| {
        unsafe {
            w.reg_gpio_17_func_sel().bits(11);
        }
        w.reg_gpio_17_ie().clear_bit();
        w.reg_gpio_17_oe().set_bit();
        w.reg_gpio_17_pd().clear_bit();
        w.reg_gpio_17_pu().clear_bit();
        w
    });

    // And GPIO 16 for d0
    let led3 = &peris.GLB.gpio_cfg16;
    led3.modify(|_, w| {
        unsafe {
            w.reg_gpio_16_func_sel().bits(11);
        }
        w.reg_gpio_16_ie().clear_bit();
        w.reg_gpio_16_oe().set_bit();
        w.reg_gpio_16_pd().clear_bit();
        w.reg_gpio_16_pu().clear_bit();
        w
    });

    // Set LED high now
    led.modify(|_, w| {
        w.reg_gpio_17_o().clear_bit();
        w
    });

    // Put both D0 and LP into reset
    peris.GLB.swrst_cfg2.modify(|_,w| {
        w.reg_ctrl_cpu2_reset().set_bit();
        w.reg_ctrl_pico_reset().set_bit();
        w
    });

    // wait a jiffy
    delay.delay_us(1);    

    // // Update LP code start address
    peris.PDS_BASE.cpu_core_cfg13.modify(|_,w| {
        unsafe{
            w.e902_rst_addr().bits(0x58002000);
        }
        w
    });

    // Update D0 code start address
    peris.PDS_BASE.cpu_core_cfg14.modify(|_,w| {
        unsafe{
            w.e906_rst_addr().bits(0x58004000);
        }
        w
    });

    // not sure i need a delay here but whatever...
    delay.delay_us(1);

    // Bring D0 and LP out of reset
    peris.GLB.swrst_cfg2.modify(|_,w| {
        w.reg_ctrl_cpu2_reset().clear_bit();
        w.reg_ctrl_pico_reset().clear_bit();
        w
    });

    loop {
        // Set LED high
        led.modify(|_, w| {
            w.reg_gpio_17_o().clear_bit();
            w
        });
        delay.delay_ms(2000);
        // // // Set LED low
        led.modify(|_, w| {
            w.reg_gpio_17_o().set_bit();
            w
        });
        delay.delay_ms(2000);
    }
}
