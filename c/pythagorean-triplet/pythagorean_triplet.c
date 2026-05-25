#include "pythagorean_triplet.h"
#include <stdlib.h>

triplets_t* triplets_with_sum(uint16_t N)
{
    uint16_t count = 0;
    uint16_t limit = N / 3;

    // First pass: count valid triplets
    for (uint16_t a = 1; a < limit; a++) {
        uint64_t numerator = (uint64_t)N * (N - 2 * a);
        uint64_t denominator = 2 * (N - a);
        if (numerator % denominator == 0) {
            uint64_t b = numerator / denominator;
            if (b > a) {
                count++;
            }
        }
    }

    triplets_t* result = malloc(sizeof(triplets_t));
    if (!result) {
        return NULL;
    }

    result->count = count;
    if (count > 0) {
        result->triplets = malloc(count * sizeof(triplet_t));
        if (!result->triplets) {
            free(result);
            return NULL;
        }

        // Second pass: populate triplets
        uint16_t index = 0;
        for (uint16_t a = 1; a < limit; a++) {
            uint64_t numerator = (uint64_t)N * (N - 2 * a);
            uint64_t denominator = 2 * (N - a);
            if (numerator % denominator == 0) {
                uint64_t b = numerator / denominator;
                if (b > a) {
                    result->triplets[index].a = a;
                    result->triplets[index].b = (uint16_t)b;
                    result->triplets[index].c = N - a - (uint16_t)b;
                    index++;
                }
            }
        }
    } else {
        result->triplets = NULL;
    }

    return result;
}

void free_triplets(triplets_t* triplets)
{
    if (triplets) {
        free(triplets->triplets);
        free(triplets);
    }
}