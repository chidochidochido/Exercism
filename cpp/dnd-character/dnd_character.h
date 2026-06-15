#pragma once

namespace dnd_character {
    struct Character {
        int strength;
        int dexterity;
        int constitution;
        int intelligence;
        int wisdom;
        int charisma;
        int hitpoints;

        // Constructor to generate a character
        Character();
    };

    int ability();
    int modifier(int score);
}  // namespace dnd_character
