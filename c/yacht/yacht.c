#include <stdbool.h>
#include <stdio.h>
#include "yacht.h"

#define NUMBER_OF_DICES  ((int)5)
#define KEY_INIT_VALUE   ((int)0)

static int evalNumbers(dice_t dice, int numberToLookFor)
{
    int numberOfCoincidences = 0;

    for(int faceIndex = 0; faceIndex < NUMBER_OF_DICES; faceIndex++)
    {
        if(dice.faces[faceIndex] == numberToLookFor)
        {
            numberOfCoincidences++;
        }
    }

    return numberToLookFor * numberOfCoincidences;
}

static int evalFullHouse(dice_t dice)
{
    int keyValue1 = dice.faces[0], keyValue2 = 0, score = 0;
    int keyValue1CoincidencesCounter = 1, keyValue2CoincidencesCounter = 0;
    int possibleFullHouse = true;
    
    int faceIndex = 1;
    
    while(faceIndex < NUMBER_OF_DICES && possibleFullHouse == true)
    {
        if(dice.faces[faceIndex] == keyValue1)
        {
            keyValue1CoincidencesCounter++;
        }
        else if(keyValue2 == KEY_INIT_VALUE)
        {
            keyValue2 = dice.faces[faceIndex];
            keyValue2CoincidencesCounter++;
        }
        else if(dice.faces[faceIndex] == keyValue2)
        {
            keyValue2CoincidencesCounter++;
        }
        else
        {
            possibleFullHouse = false;
        }
    
        faceIndex++;
    }

    if(possibleFullHouse == true)
    {
        if( (keyValue1CoincidencesCounter == 3 && keyValue2CoincidencesCounter == 2) || \
            (keyValue1CoincidencesCounter == 2 && keyValue2CoincidencesCounter == 3))
        {
            score = keyValue1CoincidencesCounter * keyValue1 + \
                    keyValue2CoincidencesCounter * keyValue2;
        }
    }

    return score;
}

static int evalFourOfAKind(dice_t dice)
{
    int keyValue1 = dice.faces[0], keyValue2 = 0, score = 0;
    int keyValue1CoincidencesCounter = 1, keyValue2CoincidencesCounter = 0;
    int possibleFourOfAKind = true;
    
    int faceIndex = 1;
    while(faceIndex < NUMBER_OF_DICES && possibleFourOfAKind == true)
    {
        if(dice.faces[faceIndex] == keyValue1)
        {
            keyValue1CoincidencesCounter++;
        }
        else if(keyValue2 == KEY_INIT_VALUE)
        {
            keyValue2 = dice.faces[faceIndex];
            keyValue2CoincidencesCounter++;
        }
        else if(dice.faces[faceIndex] == keyValue2)
        {
            keyValue2CoincidencesCounter++;
        }
        else
        {
            possibleFourOfAKind = false;
        }
    
        faceIndex++;
    }

    if(possibleFourOfAKind == true)
    {
        if(keyValue1CoincidencesCounter >= 4)
        {
            score = 4 * keyValue1;
        }
        else if(keyValue2CoincidencesCounter >= 4)
        {
            score = 4 * keyValue2;
        }
    }

    return score;
}

static int evalStraight(dice_t dice, category_t category)
{
    bool evalDiceFlags[7] = {false, false, false, false, false, false, false};
    bool straight = true;

    int origin, limit;
    int score = 0;

    for(int faceIndex = 0; faceIndex < NUMBER_OF_DICES; faceIndex++)
    {
        evalDiceFlags[dice.faces[faceIndex]] = true;
    }

    if(category == LITTLE_STRAIGHT)
    {
        origin = 1;
        limit = 5;
    }
    else if(category == BIG_STRAIGHT)
    {
        origin = 2;
        limit = 6;
    }

    for(int faceIndex = origin; faceIndex <= limit && straight == true; faceIndex++)
    {
        if(evalDiceFlags[faceIndex] != true)
        {
            straight = false;
        }
    }

    if(straight == true)
    {
        score = 30;
    }

    return score;
}

static int evalChoice(dice_t dice)
{
    int score = 0;

    for(int faceIndex = 0; faceIndex < NUMBER_OF_DICES; faceIndex++)
    {
        score += dice.faces[faceIndex];
    }

    return score;
}

static int evalYatch(dice_t dice)
{
    bool equal = true;
    int score = 0;
    int key = dice.faces[0];


    int faceIndex = 1; 
    
    while((equal == true) && (faceIndex < NUMBER_OF_DICES))
    {
        if(key != dice.faces[faceIndex])
        {
            equal = false;
        }

        faceIndex++;
    }

    if(equal == true)
    {
        score = 50;
    }

    return score;
}


int score(dice_t dice, category_t category)
{
    int score;

    switch(category)
    {
        case ONES:
            score = evalNumbers(dice, 1);
            break;
        case TWOS:
            score = evalNumbers(dice, 2);
            break;
        case THREES:
            score = evalNumbers(dice, 3);
            break;
        case FOURS:
            score = evalNumbers(dice, 4);
            break;
        case FIVES:
            score = evalNumbers(dice, 5);
            break;
        case SIXES:
            score = evalNumbers(dice, 6);
            break;
        case FULL_HOUSE:
            score = evalFullHouse(dice);
            break;
        case FOUR_OF_A_KIND:
            score = evalFourOfAKind(dice);
            break;
        case LITTLE_STRAIGHT:
            score = evalStraight(dice, LITTLE_STRAIGHT);
            break;
        case BIG_STRAIGHT:
            score = evalStraight(dice, BIG_STRAIGHT);
            break;
        case CHOICE:
            score = evalChoice(dice);
            break;
        case YACHT:
            score = evalYatch(dice);
            break;
    }
    
    return score;
}