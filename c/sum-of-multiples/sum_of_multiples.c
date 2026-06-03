#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit)
{
    unsigned int sum = 0, result, multiplier;
    bool *multiplierVector = malloc(limit * sizeof(bool));

    memset(multiplierVector, 0, limit * sizeof(bool));
    
    for(size_t i = 0; i < number_of_factors; i++)
    {
        multiplier = 1;

        if(factors[i] > 0)
        {
            result = factors[i] * multiplier;

            while (result < limit)
            {
                multiplierVector[result] = true;
                multiplier++;
                result = factors[i] * multiplier;
            }
        }
    }

    for(unsigned int i = 1; i < limit; i++)
    {
        if(multiplierVector[i] == true)
        {
            sum += i;
        }
    }

    return sum;
}