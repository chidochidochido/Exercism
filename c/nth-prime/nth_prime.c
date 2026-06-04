#include <stdbool.h>
#include "nth_prime.h"

static bool isPrime(uint32_t testNumber)
{
    bool prime = true;
    uint32_t divisor = 2;
    
    while(divisor <= testNumber / 2 && prime == true)
    {
        if(testNumber % divisor == 0)
        {
            prime = false;
        }

        divisor++;
    }

    return prime;
}

static uint32_t getNextPrimeNumber(uint32_t nextPrimeNumber)
{
    
    do
    {
        nextPrimeNumber++;
    } while (isPrime(nextPrimeNumber) == false);
    
    return nextPrimeNumber;
}

uint32_t nth(uint32_t n)
{
    uint32_t currentPrimeNumber = 1;
    uint32_t currentPrimeCount = 1;
    uint32_t result = 0;

    if(n >= 1)
    {
        while(currentPrimeCount <= n)
        {
            currentPrimeNumber = getNextPrimeNumber(currentPrimeNumber);
            currentPrimeCount++;
        }

        result = currentPrimeNumber;
    }

    return result;
}
