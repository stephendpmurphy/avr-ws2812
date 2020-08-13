# avr-ws2812

This repo houses ASM & C driver code for the popular WS2812 Addressable LEDs. Full credit goes to [Łukasz Podkalicki](https://github.com/lpodkalicki) and his source license of BSD-3-Clause License has been honored and brought over with this repository. I have simply taken the source and packaged it into a module that can be added cleanly into an existing Git repository as a submodule and configured using a config header file.

This has been tested on an ATtiny87 running at 8Mhz, and it works without any issues. The module will also scale with the Target clock speed since the delay functionality within is based on the F_CPU macro used in AVR projects.

## Adding the driver as a submodule to your repo
If you already have a git repo for you AVR source code, you can easily include this WS2812 driver by including it as a submodule to your repository.
```
$ cd ./${DIR_WHERE_YOU_WANT_TO_ADD_THE_MODULE}
$ git submodule add https://github.com/stephendpmurphy/avr-ws2812.git
```
## Including the driver in your project
Now that the source has been added as a submodule (or just added to your project directory if it's a non Git based project) you can simply include the **avr_ws2812.c** as a source file in your project, and add the **inc/** folder in your include directories.

From there, you will need to add a new **ws2812_config.h** file to your project. You can find a template one in the **template/** folder. The config file is there for the user to define what PORT and PIN the WS2812 Data line will be connected to. Dependig on what PN# of LEDs you use you might need to change the **ws2812_resettime** to an appropriate value.

## Implementing the driver source
Actually adding the module into your source is really straight forward. An example **main.c** can be found in the templates folder as well and shows the bare minimum to get your AVR driving a Rainbow on your WS2812 LEDs.

Simple include the header, create an array of pixels to match the number of LEDs you have, and a temporary "Pixel" for updating your RGB values.

```
#include <stdio.h>
#include <util/delay.h>
#include "avr_ws2812.h"

#define PIXEL_NUM (8)

ws2812_RGB_t pixels[PIXEL_NUM] = {0};

int main(void)
{
    uint8_t i;
    ws2812_RGB_t p = {255, 0, 0};

    while (1)
    {
        if (p.r > 0 && p.b == 0)
        {
            p.r--;
            p.g++;
        }
        if (p.g > 0 && p.r == 0)
        {
            p.g--;
            p.b++;
        }
        if (p.b > 0 && p.g == 0)
        {
            p.r++;
            p.b--;
        }

        for (i = 0; i < PIXEL_NUM; ++i)
        {
            pixels[i] = p;
        }
        ws2812_setleds(pixels, PIXEL_NUM);
        _delay_ms(10);
    }
}
```

Let me know if you have any questions or issues with usage or integration. The best way to reach me with these problems is to create an issue on this repository! Enjoy!
