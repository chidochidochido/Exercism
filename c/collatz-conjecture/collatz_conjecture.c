#include "collatz_conjecture.h"

int steps(int start)
{
    int num_steps = -1;

    if(start >= 1)
    {
        num_steps = 0;
        while(start > 1)
        {
            if(start % 2 == 0)
            {
                start /= 2;
            }
            else
            {
                start = 3*start + 1;
            }

            num_steps++;
        }
    }

    return num_steps;
}