#include "resistor_color_trio.h"
#include <stdio.h>
resistor_value_t color_code(resistor_band_t resistorBand[])
{
    resistor_value_t resistorReturnValue;
    unsigned long long resistorRawValue = (10u * (uint16_t)resistorBand[0] + (uint16_t)resistorBand[1]) * (unsigned long long)round(pow(10, resistorBand[2]));

    if(resistorRawValue / GIGAOHMS != 0)
    {
        resistorReturnValue.unit  = GIGAOHMS;
        resistorReturnValue.value = resistorRawValue / GIGAOHMS;
    }
    else if(resistorRawValue / MEGAOHMS != 0)
    {
        resistorReturnValue.unit  = MEGAOHMS;
        resistorReturnValue.value = resistorRawValue / MEGAOHMS;
    }
    else if(resistorRawValue / KILOOHMS != 0)
    {
        resistorReturnValue.unit  = KILOOHMS;
        resistorReturnValue.value = resistorRawValue / KILOOHMS;
    }
    else
    {
        resistorReturnValue.unit  = OHMS;
        resistorReturnValue.value = (uint16_t)resistorRawValue;
    }

    return resistorReturnValue;
}