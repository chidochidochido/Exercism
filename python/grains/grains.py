def square(number):
    if number >= 1 and number <= 64:
        total_grains = 2 ** (number - 1)
    else:
        raise ValueError("square must be between 1 and 64")
    
    return total_grains


def total():
    total_grains = 0
    for i in range (1,65):
        total_grains += square(i)

    return total_grains