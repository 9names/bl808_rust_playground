# BL616 blinky

A very minimal POC blinky for BL616.

```system
cargo objcopy --release -- -O binary blinky.bin && bflb-iot-tool --chipname bl616 --firmware blinky.bin --baudrate 2000000 --port /dev/ttyACM0
```