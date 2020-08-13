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
