#include "clock.h"
#include <string.h>
#include <stdlib.h>

static int get_hour(clock_t clock);
static int get_minute(clock_t clock);


clock_t clock_create(int hour, int minute)
{
    clock_t return_clock = {"##:##"};

    int total_minutes;

    total_minutes = hour * 60 + minute;

    total_minutes = total_minutes % (24 * 60);

    if(total_minutes < 0)
    {
        total_minutes = (24 * 60) - abs(total_minutes);
    }

    hour   = total_minutes / 60;
    minute = total_minutes % 60;

    return_clock.text[0] = (char)((hour / 10)   + (int)'0');
    return_clock.text[1] = (char)((hour % 10)   + (int)'0');
    return_clock.text[3] = (char)((minute / 10) + (int)'0');
    return_clock.text[4] = (char)((minute % 10) + (int)'0');

    return return_clock;
}

clock_t clock_add(clock_t clock, int minute_add)
{
    int hour;
    int minute;

    hour = get_hour(clock);
    minute = get_minute(clock);

    minute = minute + minute_add;

    if(minute > 60)
    {
        hour += (minute / 60);
        minute %= 60;
    }
    
    if(hour >= 24)
    {
        hour %= 24;
    }

    return clock_create(hour, minute);
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    int hour;
    int minute;

    hour = get_hour(clock);
    minute = get_minute(clock);

    minute = minute - minute_subtract;

    if(minute < 0)
    {
        hour--;
        minute = 60 + minute;
    }
    
    if(hour < 0)
    {
        hour = 24 + hour;
    }

    return clock_create(hour, minute); 
}

bool clock_is_equal(clock_t a, clock_t b)
{
    return (bool)strcmp(a.text,b.text) ? false: true;
}

static int get_hour(clock_t clock)
{
    int hour;

    hour = ((((int)clock.text[0] - (int)'0') * 10) + ((int)clock.text[1] - (int)'0'));

    return hour;
}

static int get_minute(clock_t clock)
{
    int minute;

    minute = ((((int)clock.text[3] - (int)'0') * 10) + ((int)clock.text[4] - (int)'0'));

    return minute; 
}