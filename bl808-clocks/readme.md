# BL808 clocks

Working with ROM functions and porting clock code to get to something function

```system
cargo objcopy --release -- -O binary clocks.bin && bflb-iot-tool --chipname bl808 --firmware clocks.bin --baudrate 2000000 --port /dev/ttyUSB1
```