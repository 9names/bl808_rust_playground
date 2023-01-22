# BL808 d0 blinky

A very minimal POC blinky for the D0 core on BL808.

Needs to be bundled with a loader for the D0 core.

Currently only testing with bl808-multiboot

```system
cargo objcopy --release -- -O binary d0_blinky.bin
```