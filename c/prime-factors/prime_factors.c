#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
    uint64_t updatedDividend = n;
    uint64_t divisor;
    uint64_t factorsIndex = 0;

    while(updatedDividend > 1)
    {
        divisor = 2;
        while((updatedDividend % divisor != 0) && (divisor <= updatedDividend))
        {
            divisor++;
        }

        factors[factorsIndex] = divisor;
        factorsIndex++;

        updatedDividend /= divisor;
    }

    return factorsIndex;
}
