#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

#include <stdint.h>
#include <math.h>

typedef enum
{
    OHMS = 0,
    KILOOHMS = 1000ul,
    MEGAOHMS = 1000000ul,
    GIGAOHMS = 1000000000ul
} multiplier_t;

typedef enum
{
    BLACK = 0u,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
} resistor_band_t;

typedef struct
{
    uint16_t value;
    multiplier_t unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t[]);

#endif
