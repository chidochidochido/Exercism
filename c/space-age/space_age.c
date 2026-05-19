#include "space_age.h"

float relativeOrbitalPeriod[] =
{
    0.2408467f,
    0.61519726f,
    1.0f,
    1.8808158f,
    11.862615f,
    29.447498f,
    84.016846f,
    164.79132f
};

const float secondsInAYear = 31557600.0f;

float age(planet_t planet, int64_t seconds)
{
    float years = -1.0f;
    
    if(planet >= MERCURY && planet <= NEPTUNE)
    {
        years = (seconds / relativeOrbitalPeriod[planet]) / secondsInAYear;
    }

    return years;
}