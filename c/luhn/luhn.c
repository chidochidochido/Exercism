#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "luhn.h"

#define MINIMUM_STRING_LENGTH   (size_t)1 

static char* stripSpaces(const char *num)
{
    char* tempNumPtr = malloc(strlen(num));
    int numIndex = 0, tempNumPtrIndex = 0;

    while(num[numIndex] != '\0')
    {
        if(num[numIndex] != ' ')
        {
            tempNumPtr[tempNumPtrIndex] = num[numIndex];
            tempNumPtrIndex++;
        }
        
        numIndex++;
    }

    return tempNumPtr;
}

static bool allCharactersAreNumbers(char *tempNumPtr, size_t inputStringLength)
{
    bool allNumbers = true;

    for(size_t i = 0; i < inputStringLength && allNumbers == true; i++)
    {
        if(tempNumPtr[i] < '0' || tempNumPtr[i] > '9')
        {
            allNumbers = false;
        }
    }

    return allNumbers;
}

static int* convertStringToInt(char *tempNumPtr, size_t inputStringLength)
{
    int* tempIntNumPtr = malloc(inputStringLength * sizeof(int));

    for(size_t i = 0; i < inputStringLength; i++)
    {
        switch(tempNumPtr[i])
        {
            case '0':
                tempIntNumPtr[i] = 0;
                break;
            case '1':
                tempIntNumPtr[i] = 1;
                break;
            case '2':
                tempIntNumPtr[i] = 2;
                break;
            case '3':
                tempIntNumPtr[i] = 3;
                break;
            case '4':
                tempIntNumPtr[i] = 4;
                break;
            case '5':
                tempIntNumPtr[i] = 5;
                break;
            case '6':
                tempIntNumPtr[i] = 6;
                break;
            case '7':
                tempIntNumPtr[i] = 7;
                break;
            case '8':
                tempIntNumPtr[i] = 8;
                break;
            case '9':
                tempIntNumPtr[i] = 9;
                break;
            default:
                tempIntNumPtr[i] = 0;
        }
    }

    return tempIntNumPtr;
}

static void luhnAdjustNumber(int *tempIntNumPtr, size_t inputStringLength)
{
    int tempResultLuhn;

    for(int i = (int)inputStringLength - 2; i >= 0; i-=2)
    {
        tempResultLuhn = 2 * tempIntNumPtr[i];

        if(tempResultLuhn > 9)
        {
            tempResultLuhn -= 9;
        }

        tempIntNumPtr[i] = tempResultLuhn;
    } 
}

static int sumAllNumbers(int *tempIntNumPtr, size_t inputStringLength)
{
    int sum = 0;
    
    for(size_t i = 0; i < inputStringLength; i++)
    {
        sum += tempIntNumPtr[i];
    }

    return sum;
}

bool luhn(const char *num)
{
    size_t inputStringLength, sum;
    bool validString = true, luhnNumber = false;
    char *tempNumPtr = NULL;
    int *tempIntNumPtr = NULL;

    tempNumPtr = stripSpaces(num);

    inputStringLength = strlen(tempNumPtr);
    validString = allCharactersAreNumbers(tempNumPtr, inputStringLength);

    if(inputStringLength > MINIMUM_STRING_LENGTH && validString == true)
    {
        tempIntNumPtr = convertStringToInt(tempNumPtr, inputStringLength);
        luhnAdjustNumber(tempIntNumPtr, inputStringLength);        
        sum = sumAllNumbers(tempIntNumPtr, inputStringLength);

        if(sum % 10 == 0)
        {
            luhnNumber = true;
        }
    }
    else
    {
        validString = false;
    }

    return luhnNumber;
}
