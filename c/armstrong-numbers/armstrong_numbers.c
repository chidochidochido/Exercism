#include "armstrong_numbers.h"
#include <math.h>

bool is_armstrong_number(int candidate)
{
    int num_digits = 0;
    int candidate_temp_copy;
    int sum = 0;
    int digit;

    candidate_temp_copy = candidate;
    while(candidate_temp_copy > 0) {
       num_digits++;
       candidate_temp_copy /= 10;
    }

    if(num_digits > 0) {
        candidate_temp_copy = candidate;
        while(candidate_temp_copy > 0) {
            digit = candidate_temp_copy % 10;
            sum += pow(digit, num_digits);
            candidate_temp_copy /= 10;
        }
    }

    if(sum == candidate)
        return true;

    else
        return false;
}