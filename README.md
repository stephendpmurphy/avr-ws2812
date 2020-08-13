# avr-ws2812

This repo houses ASM & C driver code for the popular WS2812 Addressable LEDs. Full credit goes to [Łukasz Podkalicki](https://github.com/lpodkalicki) and his source license of BSD-3-Clause License has been honored and brought over with this repository. I have simply taken the source and packaged it into a module that can be added cleanly into an existing Git repository as a submodule and configured using a config header file.

This has been tested on an ATtiny87 running at 8Mhz, and it works without any issues. The module will also scaled with the target Clock speed since the delay functionality within is based on the F_CPU macro used in AVR projects. Please create an issue on this repository if any issues arrise during use or integration

## Adding a submodule to your repo