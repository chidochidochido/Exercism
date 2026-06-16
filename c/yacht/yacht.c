#include <stdbool.h>
#include <stdio.h>
#include "yacht.h"


int score(dice_t dice, category_t category)
{
    int counts[7] = {0};
    int total_sum = 0;
    int score = 0;

    bool has_three = false;
    bool has_two = false;

    for(int i = 0; i < 5; i++) {
        counts[dice.faces[i]]++;
        total_sum += dice.faces[i];
    }

    switch(category)
    {
        case ONES:
        case TWOS:
        case THREES:
        case FOURS:
        case FIVES:
        case SIXES:
            return counts[category] * category;

        case FULL_HOUSE:
            for(int i = ONES; i <= SIXES; i++) {
                if(counts[i] == 3) has_three = true;
                if(counts[i] == 2) has_two = true;
            }
            return (has_three && has_two) ? total_sum : 0;

        case FOUR_OF_A_KIND:
            for(int i = ONES; i <= SIXES; i++)
                if(counts[i] >= 4) return i * 4;
            break;

        case LITTLE_STRAIGHT:
            if(counts[1] == 1 && counts[2] == 1 && counts[3] == 1 && counts[4] == 1 && counts[5] == 1) return 30;
            break;

        case BIG_STRAIGHT:
            if(counts[2] == 1 && counts[3] == 1 && counts[4] == 1 && counts[5] == 1 && counts[6] == 1) return 30;
            break;
        
        case CHOICE:
            return total_sum;
            break;
        
        case YACHT:
            for(int i = ONES; i <= SIXES; i++)
                if(counts[i] == 5) return 50;
            break;
    }
    
    return score;
}