#include <stdlib.h>
#include "dnd_character.h"

#define INITIAL_HITPOINTS  10
#define NUM_DICES          4

int ability(void)
{
    int dice_sum = 0;
    int min_roll = 7;

    for (int i = 0; i < NUM_DICES; i++)
    {
        int roll = 1 + (rand() % 6);
        dice_sum += roll;

        if (roll < min_roll)
            min_roll = roll;
    }

    return dice_sum - min_roll;
}

int modifier(int score)
{
    int diff = score - 10;
    return diff < 0 ? (diff - 1) / 2 : diff / 2;
}

dnd_character_t make_dnd_character(void)
{
    dnd_character_t character;
    character.strength = ability();
    character.dexterity = ability();
    character.constitution = ability();
    character.intelligence = ability();
    character.wisdom = ability();
    character.charisma = ability();
    character.hitpoints = INITIAL_HITPOINTS + modifier(character.constitution);
    
    return character;
}
