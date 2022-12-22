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
