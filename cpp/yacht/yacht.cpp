#include "yacht.h"
#include <numeric>
#include <algorithm>

namespace yacht {
int score(const std::vector<int>& dice, const std::string& category) {
    std::vector<int> counts(7, 0);
    int total_sum = std::accumulate(dice.begin(), dice.end(), 0);

    for (int die : dice) counts[die]++;

    if (category == "ones")    return counts[1] * 1;
    if (category == "twos")    return counts[2] * 2;
    if (category == "threes")  return counts[3] * 3;
    if (category == "fours")   return counts[4] * 4;
    if (category == "fives")   return counts[5] * 5;
    if (category == "sixes")   return counts[6] * 6;

    if (category == "full house") {
        bool has_three = std::any_of(counts.begin(), counts.end(), [](int c) { return c == 3; });
        bool has_two   = std::any_of(counts.begin(), counts.end(), [](int c) { return c == 2; });
        return (has_three && has_two) ? total_sum : 0;
    }

    if (category == "four of a kind") {
        for (int i = 1; i <= 6; ++i) {
            if (counts[i] >= 4) {
                return i * 4;
            }
        }
        return 0;
    }

    if (category == "little straight")
        if(counts[1] == 1 && counts[2] == 1 && counts[3] == 1 && counts[4] == 1 && counts[5] == 1) return 30;
    
    if (category == "big straight")
        if(counts[2] == 1 && counts[3] == 1 && counts[4] == 1 && counts[5] == 1 && counts[6] == 1) return 30;

    if (category == "choice")
        return total_sum;

    if (category == "yacht")
        return std::any_of(counts.begin(), counts.end(), [](int c) { return c == 5; }) ? 50 : 0;

    return 0;
}

}  // namespace yacht
