#ifndef PYTHAGOREAN_TRIPLET_H
#define PYTHAGOREAN_TRIPLET_H

#include <stdint.h>

typedef struct
{
    uint16_t a;
    uint16_t b;
    uint16_t c;
} triplet_t;

typedef struct
{
    triplet_t* triplets;
    uint16_t count;
} triplets_t; 

triplets_t* triplets_with_sum(uint16_t);
void free_triplets(triplets_t*);

#endif
