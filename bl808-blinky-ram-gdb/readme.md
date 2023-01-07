# BL808 blinky in RAM with GDB

Getting a more workable testing environment up and going by loading programs into RAM via JTAG.

```system
cargo build --release
gdb-multiarch target/riscv32imac-unknown-none-elf/release/bl808-blinky
(gdb) target remote :1025
load
continue
```
or
```system
cargo build --release && gdb-multiarch target/riscv32imac-unknown-none-elf/release/bl808-blinky-ram-gdb -ex "target remote :1025" -ex "load" -ex "continue" --batch
```
