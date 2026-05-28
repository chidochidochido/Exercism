#include <math.h>
#include <stdlib.h>
#include "dnd_character.h"

#define INITIAL_HITPOINTS  ((int)10)
#define NUM_DICES ((int)4)

dnd_character_t myCharacter;

int ability(void)
{
    int dice, dice_count = 0;

    int min_value_dice = 6;

    for(int i = 0; i < NUM_DICES; i++)
    {
        dice = 1 + (rand() % 6);
        dice_count += dice;

        if(dice < min_value_dice)
            min_value_dice = dice;
    }

    return dice_count - min_value_dice;
}

int modifier(int score)
{
    return (int)floor(((float)(score - 10)) / 2);
}

dnd_character_t make_dnd_character(void)
{
    myCharacter.charisma = ability();
    myCharacter.constitution = ability();
    myCharacter.dexterity = ability();
    myCharacter.hitpoints = INITIAL_HITPOINTS + modifier(myCharacter.constitution);
    myCharacter.intelligence = ability();
    myCharacter.strength = ability();
    myCharacter.wisdom = ability();
    
    return myCharacter;
}
