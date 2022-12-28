#![no_std]
#![no_main]

// super basic check if atomics cause hardfaults

use core::sync::atomic::{AtomicBool, Ordering};

use panic_halt as _;

const SYSFREQ: u32 = 320_000_000;
use bl808_pac as pac;
use embedded_hal::blocking::delay::DelayMs;
use riscv::delay::McycleDelay;

#[riscv_rt::entry]
fn main() -> ! {
    let mut delay = McycleDelay::new(SYSFREQ);
    let peris = unsafe { pac::Peripherals::steal() };
    let led = &peris.GLB.gpio_config[18];
    let b: AtomicBool = AtomicBool::new(false);

    // Configure GP29 as an output pin
    led.modify(|_, w| {
        w.pin_mode().output();
        w.output_function().set_bit();
        w.input_function().clear_bit();
        w.pull_up().clear_bit();
        w.pull_down().clear_bit();
        //w.drive().variant(3);
        w
    });
    loop {
        let _ = b.fetch_update(Ordering::SeqCst, Ordering::SeqCst, |b| Some(!b));
        if b.load(Ordering::SeqCst) {
            // Enable LED
            led.modify(|_, w| {
                w.output_clear().set_bit();
                w.output_set().clear_bit();
                w
            });
        } else {
            // Disable LED
            led.modify(|_, w| {
                w.output_set().set_bit();
                w.output_clear().clear_bit();
                w
            });
        }
        delay.delay_ms(1000);
    }
}
