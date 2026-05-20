#include "resistor_color.h"
#include <stdlib.h>
#include <string.h>

int color_code(resistor_band_t color)
{
    return (int)color; 
}

resistor_band_t *colors(void)
{
    const resistor_band_t color_names[] = {BLACK, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE};
    
    resistor_band_t *colors_var = (resistor_band_t*)malloc(sizeof(color_names));
    
    memcpy(colors_var, color_names, sizeof(color_names));
    
    return colors_var;
}