"""
Module providing a function to recite verses of "The Twelve Days of Christmas".
"""

LYRICS = {
    1: ("first", "a Partridge in a Pear Tree."),
    2: ("second", "two Turtle Doves, and "),
    3: ("third", "three French Hens, "),
    4: ("fourth", "four Calling Birds, "),
    5: ("fifth", "five Gold Rings, "),
    6: ("sixth", "six Geese-a-Laying, "),
    7: ("seventh", "seven Swans-a-Swimming, "),
    8: ("eighth", "eight Maids-a-Milking, "),
    9: ("ninth", "nine Ladies Dancing, "),
    10: ("tenth", "ten Lords-a-Leaping, "),
    11: ("eleventh", "eleven Pipers Piping, "),
    12: ("twelfth", "twelve Drummers Drumming, ")
}

def recite(start_verse, end_verse):
    """
    Returns a list of verses from start_verse to end_verse.
    """
    if start_verse <= 0 or end_verse <= 0 or start_verse > end_verse:
        return []
        
    result = []
    for day_index in range(start_verse, end_verse + 1):
        current_verse = "On the " + LYRICS[day_index][0] + " day of Christmas my true love gave to me: "
        for gift_index in range(day_index, 0, -1):
            current_verse += LYRICS[gift_index][1]
        result.append(current_verse)

    return result
