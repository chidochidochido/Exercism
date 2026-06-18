"""Module for scoring a Yacht dice game roll based on categories."""

YACHT = lambda dice: 50 if len(set(dice)) == 1 else 0
ONES = lambda dice: dice.count(1) * 1
TWOS = lambda dice: dice.count(2) * 2
THREES = lambda dice: dice.count(3) * 3
FOURS = lambda dice: dice.count(4) * 4
FIVES = lambda dice: dice.count(5) * 5
SIXES = lambda dice: dice.count(6) * 6
FULL_HOUSE = lambda dice: sum(dice) if sorted(dice.count(die) for die in set(dice)) == [2, 3] else 0
FOUR_OF_A_KIND = lambda dice: next((die * 4 for die in set(dice) if dice.count(die) >= 4), 0)
LITTLE_STRAIGHT = lambda dice: 30 if sorted(dice) == [1, 2, 3, 4, 5] else 0
BIG_STRAIGHT = lambda dice: 30 if sorted(dice) == [2, 3, 4, 5, 6] else 0
CHOICE = sum


def score(dice, category):
    """Calculate the score of a 5-dice roll for a given category."""
    return category(dice)