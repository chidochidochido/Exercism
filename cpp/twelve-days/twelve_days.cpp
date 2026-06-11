#include "twelve_days.h"

#include <array>
#include <string>

namespace twelve_days {

const std::array<std::string, 12> DAYS = {
    "first", "second", "third", "fourth", "fifth", "sixth",
    "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth"
};

const std::array<std::string, 12> GIFTS = {
    "a Partridge in a Pear Tree.\n",
    "two Turtle Doves, and ",
    "three French Hens, ",
    "four Calling Birds, ",
    "five Gold Rings, ",
    "six Geese-a-Laying, ",
    "seven Swans-a-Swimming, ",
    "eight Maids-a-Milking, ",
    "nine Ladies Dancing, ",
    "ten Lords-a-Leaping, ",
    "eleven Pipers Piping, ",
    "twelve Drummers Drumming, "
};

std::string recite(int start_verse, int end_verse)
{
    if(start_verse <= 0 || end_verse <= 0 || start_verse > end_verse)
        return "";

    const int start_day = start_verse - 1;
    const int end_day = end_verse - 1;
    
    std::string result = "";
    for(int day_index = start_day; day_index <= end_day; day_index++)
    {
        std::string current_verse = "On the " + DAYS[day_index] + " day of Christmas my true love gave to me: ";
        for(int gift_index = day_index; gift_index >= 0; gift_index--)
        {
            current_verse += GIFTS[gift_index];
        }

        if(day_index < end_day) {
            current_verse += '\n';
        }

        result += current_verse;
    }

    return result;
}

}  // namespace twelve_days
