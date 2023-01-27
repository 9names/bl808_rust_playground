#![no_std]
#![no_main]

use panic_halt as _;

const SYSFREQ: u32 = 320_000_000;
// TODO: switch to bl616 pac. the gpio peripheral is the same and at the same address so this is fine for now
use bl808_pac as pac;
use embedded_hal::blocking::delay::DelayMs;
use riscv::delay::McycleDelay;

#[riscv_rt::entry]
fn main() -> ! {
    let mut delay = McycleDelay::new(SYSFREQ);
    let peris = unsafe { pac::Peripherals::steal() };
    let led = &peris.GLB.gpio_config[27];
    let led2 = &peris.GLB.gpio_config[28];
    // Configure our LED pins as output pins
    led.modify(|_, w| {
        w.pin_mode().output();
        w.output_function().set_bit();
        w.input_function().clear_bit();
        w.pull_up().clear_bit();
        w.pull_down().clear_bit();
        w
    });
    led2.modify(|_, w| {
        w.pin_mode().output();
        w.output_function().set_bit();
        w.input_function().clear_bit();
        w.pull_up().clear_bit();
        w.pull_down().clear_bit();
        w
    });
    loop {
        // Blink the first LED for 1 second
        led.modify(|_, w| {
            w.output_clear().set_bit();
            w.output_set().clear_bit();
            w
        });
        delay.delay_ms(1000);
        
        led.modify(|_, w| {
            w.output_set().set_bit();
            w.output_clear().clear_bit();
            w
        });
        delay.delay_ms(1000);

        // Blinky the second LED twice, and twice as fast
        for _ in 0..2 {
            led2.modify(|_, w| {
                w.output_clear().set_bit();
                w.output_set().clear_bit();
                w
            });
            delay.delay_ms(500);

            led2.modify(|_, w| {
                w.output_set().set_bit();
                w.output_clear().clear_bit();
                w
            });
            delay.delay_ms(500);
        }
        
    }
}
