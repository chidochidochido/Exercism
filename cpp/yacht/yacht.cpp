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

    if (category == "full house") {
        bool has_three = std::any_of(counts.begin(), counts.end(), [](int c) { return c == 3; });
        bool has_two   = std::any_of(counts.begin(), counts.end(), [](int c) { return c == 2; });
        return (has_three && has_two) ? total_sum : 0;
    }

    "four of a kind"
    "little straight"
    "big straight"
    "choice"
    "yacht"

}

}  // namespace yacht
