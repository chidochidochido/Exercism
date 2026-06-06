#include "sieve.h"
#include <math.h>
#include <stdbool.h>
#include <string.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
    uint32_t primes_count = 0;
    bool prime_flags[limit + 1];
    unsigned int index;
    unsigned int inner_index;
    unsigned int count;

    memset(prime_flags, true, sizeof(prime_flags));

    for(index = 2; index <= (int)sqrt(limit); index++)
    {
        for(inner_index = 2; (count = (index * inner_index)) <= (unsigned int)sizeof(prime_flags); inner_index++)
        {
            prime_flags[count] = false;
        }
    }

    for(index = 2; index < sizeof(prime_flags) && primes_count <= max_primes; index++)
    {
        if(prime_flags[index])
        {
            primes[primes_count] = index;
            primes_count++;
        }
    }

    if(primes_count > max_primes)
        primes_count = max_primes;
    
    return primes_count;
}