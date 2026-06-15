"""Module for generating DND character abilities and modifier calculations."""
import random

class Character: # pylint: disable=too-few-public-methods
    """A class representing a D&D character with attributes and health."""
    @staticmethod
    def ability():
        """Roll 4 six-sided dice and return the sum of the top 3 rolls."""
        rolls = [random.randint(1, 6) for die_roll in range(4)]
        return sum(rolls) - min(rolls)
        
    def __init__(self):
        self.strength = self.ability()
        self.dexterity = self.ability()
        self.constitution = self.ability()
        self.intelligence = self.ability()
        self.wisdom = self.ability()
        self.charisma = self.ability()
        self.hitpoints = 10 + modifier(self.constitution)

def modifier(value):
    """Calculate the ability modifier for a given score."""
    return (value -10) // 2
