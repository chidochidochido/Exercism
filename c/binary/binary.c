#include "binary.h"
#include <math.h>
static unsigned int get_number_of_digits(const char *input);

int convert(const char *input)
{
    int number_of_digits;
    int adjusted_index_number_of_digits;
    int digits_index;
    int total_decimal = 0;
    char digit;

    number_of_digits = get_number_of_digits(input);
    digits_index = adjusted_index_number_of_digits = number_of_digits - 1;

    while(digits_index >= 0 && total_decimal != INVALID)
    {
        digit = input[digits_index];

        if(digit == '1')
        {
            total_decimal += pow(2, adjusted_index_number_of_digits - digits_index);
        }
        else if(digit != '0')
        {
            total_decimal = INVALID;
        }

        digits_index--;
    }

    return total_decimal;
}

static unsigned int get_number_of_digits(const char *input)
{
    unsigned int num_digits = 0;
    
    while(input[num_digits] != '\0')
    {
        num_digits++;
    }

    return num_digits;
}