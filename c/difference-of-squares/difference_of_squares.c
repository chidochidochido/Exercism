#include "difference_of_squares.h"
#include <math.h>

unsigned int sum_of_squares(unsigned int number)
{
    unsigned int total = 0;
    unsigned int index;
    
    for(index = 1; index <= number ; index++)
    {
        total += pow(index, 2);
    }

    return total;
}

unsigned int square_of_sum(unsigned int number)
{
    unsigned int total = 0;
    unsigned int index;
    
    for(index = 1; index <= number ; index++)
    {
        total += index;
    }

    return pow(total, 2);
}

unsigned int difference_of_squares(unsigned int number)
{
    return square_of_sum(number) - sum_of_squares(number);
}