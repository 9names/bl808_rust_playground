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

    // Set up GPIO18 as an output LED now
    // this will make it easier to test LP/D0 firmware
    // without pulling in PAC
    let led = &peris.GLB.gpio_cfg18;
    led.modify(|_, w| {
        unsafe {
            w.reg_gpio_18_func_sel().bits(11);
        }
        w.reg_gpio_18_ie().clear_bit();
        w.reg_gpio_18_oe().set_bit();
        w.reg_gpio_18_pd().clear_bit();
        w.reg_gpio_18_pu().clear_bit();
        w
    });

    // Set LED high now
    led.modify(|_, w| {
        w.reg_gpio_18_o().clear_bit();
        w
    });

    peris.GLB.swrst_cfg2.modify(|_,w| {
        w.reg_ctrl_cpu2_reset().clear_bit();
        w.reg_ctrl_pico_reset().clear_bit();
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

    // Update LP code start address
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
        delay.delay_ms(200);
    }
}
