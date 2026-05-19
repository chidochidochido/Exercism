def equilateral(sides):

    isEquilateral = False

    if is_triangle(sides):
        if (sides[0] == sides[1]) and (sides[0] == sides[2]) and (sides[1] == sides[2]):
            isEquilateral = True
    
    return isEquilateral

def isosceles(sides):

    isIsosceles = False

    if is_triangle(sides):
        if sides[0] == sides[1] or sides[0] == sides[2] or sides[1] == sides[2]:
            isIsosceles = True

    return isIsosceles


def scalene(sides):
    isScalene = False

    if is_triangle(sides):
        if (sides[0] != sides[1]) and (sides[0] != sides[2]) and (sides[1] != sides[2]):
            isScalene = True

    return isScalene

def is_triangle(sides):
    isTriangle = False

    if (sides[0] != 0) and (sides[1] != 0) and (sides[2] != 0):
        if (sides[0] + sides[1] >= sides[2]) and (sides[1] + sides[2] >= sides[0]) and (sides[0] + sides[2] >= sides[1]):
            isTriangle = True
    
    return isTriangle

