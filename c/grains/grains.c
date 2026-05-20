#include "grains.h"
#include <math.h>
uint64_t square(uint8_t index){
    uint64_t total = (uint8_t)0;
    
    if(index > 0)
    {
        total = (uint64_t)pow(2, index - 1);
    }

    return total; 
}

uint64_t total(void){
    uint64_t totalGrains = 0;
    int squareIndex;

    for(squareIndex = 0; squareIndex < 64; squareIndex++)
    {
        totalGrains += (uint64_t)pow(2, squareIndex);
    }

    return totalGrains;
}