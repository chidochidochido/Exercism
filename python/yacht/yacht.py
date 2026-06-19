"""Module for scoring a Yacht dice game roll based on categories."""

def yacht(dice):
    """Score 50 points if all dice have the same value."""
    return 50 if len(set(dice)) == 1 else 0


def ones(dice):
    """Score the sum of dice showing 1."""
    return dice.count(1) * 1


def twos(dice):
    """Score the sum of dice showing 2."""
    return dice.count(2) * 2


def threes(dice):
    """Score the sum of dice showing 3."""
    return dice.count(3) * 3


def fours(dice):
    """Score the sum of dice showing 4."""
    return dice.count(4) * 4


def fives(dice):
    """Score the sum of dice showing 5."""
    return dice.count(5) * 5


def sixes(dice):
    """Score the sum of dice showing 6."""
    return dice.count(6) * 6


def full_house(dice):
    """Score the sum of all dice if there is a three-of-a-kind and a pair."""
    return sum(dice) if sorted(dice.count(die) for die in set(dice)) == [2, 3] else 0


def four_of_a_kind(dice):
    """Score the sum of 4 identical dice if they exist."""
    return next((die * 4 for die in set(dice) if dice.count(die) >= 4), 0)


def little_straight(dice):
    """Score 30 points if the dice are 1-2-3-4-5."""
    return 30 if sorted(dice) == [1, 2, 3, 4, 5] else 0


def big_straight(dice):
    """Score 30 points if the dice are 2-3-4-5-6."""
    return 30 if sorted(dice) == [2, 3, 4, 5, 6] else 0


def choice(dice):
    """Score the sum of all dice."""
    return sum(dice)


# pylint: disable=invalid-name
# Constants pointing to the functions for the test suite
YACHT = yacht
ONES = ones
TWOS = twos
THREES = threes
FOURS = fours
FIVES = fives
SIXES = sixes
FULL_HOUSE = full_house
FOUR_OF_A_KIND = four_of_a_kind
LITTLE_STRAIGHT = little_straight
BIG_STRAIGHT = big_straight
CHOICE = choice
# pylint: enable=invalid-name


def score(dice, category):
    """Calculate the score of a 5-dice roll for a given category."""
    return category(dice)