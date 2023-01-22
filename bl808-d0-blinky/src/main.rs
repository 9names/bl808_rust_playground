#![no_std]
#![no_main]

use panic_halt as _;

const SYSFREQ: u32 = 320_000_000;
use bl808_pac as pac;
use embedded_hal::blocking::delay::DelayMs;
use riscv::delay::McycleDelay;

#[riscv_rt::entry]
fn main() -> ! {
    let mut delay = McycleDelay::new(SYSFREQ);
    let peris = unsafe { pac::Peripherals::steal() };

    // Use GPIO16
    // Assume this is configured by m0 first
    let led = &peris.GLB.gpio_cfg16;


    loop {
        // Set LED high
        led.modify(|_, w| {
            w.reg_gpio_16_o().clear_bit();
            w
        });

        delay.delay_ms(1100);
        // Set LED low
        led.modify(|_, w| {
            w.reg_gpio_16_o().set_bit();
            w
        });
        delay.delay_ms(1100);
    }
}
