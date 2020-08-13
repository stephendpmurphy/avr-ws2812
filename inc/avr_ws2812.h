#ifndef LIGHT_WS2812_H_
#define LIGHT_WS2812_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "ws2812_config.h"

/*
 *  Structure of the LED array
 *
 * cRGB:     RGB  for WS2812S/B/C/D, SK6812, SK6812Mini, SK6812WWA, APA104, APA106
 * cRGBW:    RGBW for SK6812RGBW
 */

typedef struct cRGB {
    uint8_t g;
    uint8_t r;
    uint8_t b;
} ws2812_RGB_t;

typedef struct {
    uint8_t g;
    uint8_t r;
    uint8_t b;
    uint8_t w;
} ws2812_RGBW_t;

/* User Interface
 *
 * Input:
 *         ledarray:           An array of GRB data describing the LED colors
 *         number_of_leds:     The number of LEDs to write
 *         pinmask (optional): Bitmask describing the output bin. e.g. _BV(PB0)
 *
 * The functions will perform the following actions:
 *         - Set the data-out pin as output
 *         - Send out the LED data
 *         - Wait 50µs to reset the LEDs
 */

void ws2812_setleds     (ws2812_RGB_t  *ledarray, uint16_t number_of_leds);
void ws2812_setleds_pin (ws2812_RGB_t  *ledarray, uint16_t number_of_leds,uint8_t pinmask);
void ws2812_setleds_rgbw(ws2812_RGBW_t *ledarray, uint16_t number_of_leds);

/*
 * Old interface / Internal functions
 *
 * The functions take a byte-array and send to the data output as WS2812 bitstream.
 * The length is the number of bytes to send - three per LED.
 */

void ws2812_sendarray     (uint8_t *array,uint16_t length);
void ws2812_sendarray_mask(uint8_t *array,uint16_t length, uint8_t pinmask);

#endif /* LIGHT_WS2812_H_ */
