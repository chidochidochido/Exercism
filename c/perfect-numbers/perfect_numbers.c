#include "perfect_numbers.h"

kind classify_number(long int inputNumber)
{
    long int aliquotSum = 0;
    long int aliquotIndex = 1;
    kind numberKind;

    if(inputNumber > 0)
    {
        while(aliquotIndex <= (inputNumber / 2))
        {
            if(inputNumber % aliquotIndex == 0)
                aliquotSum += aliquotIndex;
    
            aliquotIndex++;
        }
    }

    if(inputNumber <= 0)
        numberKind = ERROR;
    else if(aliquotSum == inputNumber)
        numberKind = PERFECT_NUMBER;
    else if(aliquotSum > inputNumber)
        numberKind = ABUNDANT_NUMBER;
    else
        numberKind = DEFICIENT_NUMBER;

    return numberKind;
}