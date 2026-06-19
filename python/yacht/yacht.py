"""Module for scoring a Yacht dice game roll based on categories."""

def YACHT(dice):
    """Score 50 points if all dice have the same value."""
    return 50 if len(set(dice)) == 1 else 0


def ONES(dice):
    """Score the sum of dice showing 1."""
    return dice.count(1) * 1


def TWOS(dice):
    """Score the sum of dice showing 2."""
    return dice.count(2) * 2


def THREES(dice):
    """Score the sum of dice showing 3."""
    return dice.count(3) * 3


def FOURS(dice):
    """Score the sum of dice showing 4."""
    return dice.count(4) * 4


def FIVES(dice):
    """Score the sum of dice showing 5."""
    return dice.count(5) * 5


def SIXES(dice):
    """Score the sum of dice showing 6."""
    return dice.count(6) * 6


def FULL_HOUSE(dice):
    """Score the sum of all dice if there is a three-of-a-kind and a pair."""
    return sum(dice) if sorted(dice.count(die) for die in set(dice)) == [2, 3] else 0


def FOUR_OF_A_KIND(dice):
    """Score the sum of 4 identical dice if they exist."""
    return next((die * 4 for die in set(dice) if dice.count(die) >= 4), 0)


def LITTLE_STRAIGHT(dice):
    """Score 30 points if the dice are 1-2-3-4-5."""
    return 30 if sorted(dice) == [1, 2, 3, 4, 5] else 0


def BIG_STRAIGHT(dice):
    """Score 30 points if the dice are 2-3-4-5-6."""
    return 30 if sorted(dice) == [2, 3, 4, 5, 6] else 0


def CHOICE(dice):
    """Score the sum of all dice."""
    return sum(dice)


def score(dice, category):
    """Calculate the score of a 5-dice roll for a given category."""
    return category(dice)