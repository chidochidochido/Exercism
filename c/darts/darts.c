#include "darts.h"
#include <math.h>

uint8_t score(coordinate_t coordinate) 
{
    float hypotenuse = sqrt(pow(coordinate.x, 2) + pow(coordinate.y, 2));
    uint8_t score = 0;
    
    if(hypotenuse >= -1.0f && hypotenuse <= 1.0f) 
    {
        score = 10;
    } 
    else if(hypotenuse >= -5.0f && hypotenuse <= 5.0f) 
    {
        score = 5;
    }
    else if(hypotenuse >= -10.0f && hypotenuse <= 10.0f)
    {
        score = 1;
    }

    return score;
}