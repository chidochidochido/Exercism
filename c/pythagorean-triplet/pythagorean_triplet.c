#include "pythagorean_triplet.h"
#include <stdbool.h>

triplets_t* triplets_with_sum(uint16_t N)
{
    triplet_t testTriplet;
    uint16_t sumSides;
    //bool noMoreTripletsToTest = false;

    bool isTriplet;
    
    for(uint16_t a = 1; ; a++)
    {
        for(uint16_t b = a + 1; ; b++)
        {
            for(uint16_t c = b + 1; (sumSides = a + b + c <= N); c++)
            {
                if(sumSides == N)
                {
                    isTriplet = isPythagoreanTryplet(&testTriplet);
                    if(isTriplet)
                    {

                    }
                }
                
            }
        }
    }
    return 0;
}

void free_triplets(triplets_t* triplets)
{
    (void)triplets;
}