#include "roman_numerals.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

const char romanNumberalStringSize = 10;

char *to_roman_numeral(unsigned int number)
{
    char* romanNumber = (char*)malloc(sizeof(char) * romanNumberalStringSize);
    memset(romanNumber, '\0', sizeof(char) * romanNumberalStringSize);

    uint8_t romanDigitsCounter = 0;

    switch(number / 1000)
    {
        case 1:
            romanNumber[0] = 'M';
            romanDigitsCounter = 1;
            break;
        case 2:
            romanNumber[0] = 'M';
            romanNumber[1] = 'M';
            romanDigitsCounter = 2;
            break;
        case 3:
            romanNumber[0] = 'M';
            romanNumber[1] = 'M';
            romanNumber[2] = 'M';
            romanDigitsCounter = 3;
            break;
    }

    number %= 1000;

    switch(number / 100)
    {
        case 1:
            romanNumber[romanDigitsCounter] = 'C';
            romanDigitsCounter++;
            break;
        case 2:
            romanNumber[romanDigitsCounter] = 'C';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'C';
            romanDigitsCounter++;
            break;
        case 3:
            romanNumber[romanDigitsCounter] = 'C';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'C';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'C';
            romanDigitsCounter++;

            break;
        case 4:
            romanNumber[romanDigitsCounter] = 'C';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'D';
            romanDigitsCounter++;
            break;
        case 5:
            romanNumber[romanDigitsCounter] = 'D';
            romanDigitsCounter++;
            break;
        case 6:
            romanNumber[romanDigitsCounter] = 'D';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'C';
            romanDigitsCounter++;
            break;
        case 7:
            romanNumber[romanDigitsCounter] = 'D';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'C';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'C';
            romanDigitsCounter++;
            break;
        case 8:
            romanNumber[romanDigitsCounter] = 'D';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'C';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'C';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'C';
            romanDigitsCounter++;
            break;
        case 9:
            romanNumber[romanDigitsCounter] = 'C';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'M';
            romanDigitsCounter++;
            break;
    }

    number %= 100;

    switch(number / 10)
    {
        case 1:
            romanNumber[romanDigitsCounter] = 'X';
            romanDigitsCounter++;
            break;
        case 2:
            romanNumber[romanDigitsCounter] = 'X';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'X';
            romanDigitsCounter++;
            break;
        case 3:
            romanNumber[romanDigitsCounter] = 'X';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'X';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'X';
            romanDigitsCounter++;
            break;
        case 4:
            romanNumber[romanDigitsCounter] = 'X';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'L';
            romanDigitsCounter++;
            break;
        case 5:
            romanNumber[romanDigitsCounter] = 'L';
            romanDigitsCounter++;
            break;
        case 6:
            romanNumber[romanDigitsCounter] = 'L';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'X';
            romanDigitsCounter++;
            break;
        case 7:
            romanNumber[romanDigitsCounter] = 'L';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'X';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'X';
            romanDigitsCounter++;
            break;
        case 8:
            romanNumber[romanDigitsCounter] = 'L';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'X';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'X';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'X';
            romanDigitsCounter++;
            break;
        case 9:
            romanNumber[romanDigitsCounter] = 'X';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'C';
            romanDigitsCounter++;
            break;
    }
    
    number %= 10;

    switch(number)
    {
       case 1:
            romanNumber[romanDigitsCounter] = 'I';
            romanDigitsCounter++;
            break;
        case 2:
            romanNumber[romanDigitsCounter] = 'I';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'I';
            romanDigitsCounter++;
            break;
        case 3:
            romanNumber[romanDigitsCounter] = 'I';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'I';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'I';
            romanDigitsCounter++;
            break;
        case 4:
            romanNumber[romanDigitsCounter] = 'I';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'V';
            romanDigitsCounter++;
            break;
        case 5:
            romanNumber[romanDigitsCounter] = 'V';
            romanDigitsCounter++;
            break;
        case 6:
            romanNumber[romanDigitsCounter] = 'V';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'I';
            romanDigitsCounter++;
            break;
        case 7:
            romanNumber[romanDigitsCounter] = 'V';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'I';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'I';
            romanDigitsCounter++;
            break;
        case 8:
            romanNumber[romanDigitsCounter] = 'V';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'I';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'I';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'I';
            romanDigitsCounter++;
            break;
        case 9:
            romanNumber[romanDigitsCounter] = 'I';
            romanDigitsCounter++;
            romanNumber[romanDigitsCounter] = 'X';
            romanDigitsCounter++;
            break;
    }

    return romanNumber;
}