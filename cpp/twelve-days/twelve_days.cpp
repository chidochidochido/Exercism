#include "twelve_days.h"

#include <map>
#include <string>
#include <utility>

namespace twelve_days {

const std::map<int, std::pair<std::string, std::string>> LYRICS = {
    {1, {"first", "a Partridge in a Pear Tree.\n"}},
    {2, {"second", "two Turtle Doves, and "}},
    {3, {"third", "three French Hens, "}},
    {4, {"fourth", "four Calling Birds, "}},
    {5, {"fifth", "five Gold Rings, "}},
    {6, {"sixth", "six Geese-a-Laying, "}},
    {7, {"seventh", "seven Swans-a-Swimming, "}},
    {8, {"eighth", "eight Maids-a-Milking, "}},
    {9, {"ninth", "nine Ladies Dancing, "}},
    {10, {"tenth", "ten Lords-a-Leaping, "}},
    {11, {"eleventh", "eleven Pipers Piping, "}},
    {12, {"twelfth", "twelve Drummers Drumming, "}}
};

std::string recite(int start_verse, int end_verse)
{
    if(start_verse <= 0 || end_verse <= 0 || start_verse > end_verse)
        return "";
    
    std::string result = "";
    result.reserve(2000);
    for(int day_index = start_verse; day_index <= end_verse; day_index++)
    {
        result += "On the " + LYRICS.at(day_index).first + " day of Christmas my true love gave to me: ";
        for(int gift_index = day_index; gift_index >= 1; gift_index--)
        {
            result += LYRICS.at(gift_index).second;
        }

        if(day_index < end_verse) {
            result += '\n';
        }
    }

    return result;
}

}  // namespace twelve_days
