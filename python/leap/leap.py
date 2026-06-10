"""
FUNCTION: is_leap_year
ARGS:    int (year)
RETURNS: bool
DESCRIPTION: TRUE - if input_year is a leap year
             FALSE - if input_year is not a leap year
"""

def leap_year(year):
    return (year % 4 == 0) and (year % 100 != 0 or year % 400 == 0)