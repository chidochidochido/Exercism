#include "dnd_character.h"
#include <random>
#include <algorithm> // for std::min or std::min_element

namespace dnd_character {

int modifier(int score) {
    int diff = score - 10;
    return diff < 0 ? (diff - 1) / 2 : diff / 2;
}

int ability() {
    // Thread-safe / static random engine setup
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 6);

    int dice_sum = 0;
    int min_roll = 7;

    for (int i = 0; i < 4; ++i) {
        int roll = dist(gen);
        dice_sum += roll;
        if (roll < min_roll) {
            min_roll = roll;
        }
    }
    return dice_sum - min_roll;
}

Character::Character()
    : strength(ability()),
      dexterity(ability()),
      constitution(ability()),
      intelligence(ability()),
      wisdom(ability()),
      charisma(ability()),
      hitpoints(10 + modifier(constitution)) {}

}  // namespace dnd_character
