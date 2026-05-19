#include "leap.h"

#define LEAP_YEAR     true
#define NOT_LEAP_YEAR false

bool leap_year(int testYear)
{
	bool isLeap = LEAP_YEAR;
	
	if(testYear % 4 == 0)
	{
		if(testYear % 100 == 0)
		{
			if(testYear % 400 != 0)
			{
				isLeap = NOT_LEAP_YEAR;
			}
		}
    }
	else
	{
		isLeap = NOT_LEAP_YEAR;
	}

	return isLeap;
}