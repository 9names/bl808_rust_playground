# BL808 blinky

A very minimal POC blinky for the M0 core on BL808
Used https://github.com/YdrMaster/try-bl808 as a reference, along with setup from bl602-hal and notes from Brennan Ashton

Note: Update baud rate and port to match your board - these settings work fine for me on sipeed m1s

```system
cargo objcopy --release -- -O binary blinky.bin && bflb-iot-tool --chipname bl808 --firmware blinky.bin --baudrate 2000000 --port /dev/ttyUSB1
```