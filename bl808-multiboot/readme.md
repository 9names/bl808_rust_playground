# BL808 multiboot

Attempts to get D0 and LP cores up and going

```system
cargo objcopy --release -- -O binary firmware.bin && bflb-iot-tool --chipname bl808 --firmware firmware.bin --baudrate 2000000 --port /dev/ttyACM1
```