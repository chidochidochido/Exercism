#include "eliuds_eggs.h"

unsigned int egg_count(unsigned int decimal)
{
    int mask, eggs = 0;
    for(unsigned int i = 0; i < sizeof(decimal) * 8; i++)
    {
        mask = 1 << i;
        if(decimal & mask)
        {
            eggs++;
        }
    }
    
    return eggs;
}