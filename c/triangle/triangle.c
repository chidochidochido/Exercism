#include "triangle.h"

static bool is_triangle(triangle_t sides);

bool is_equilateral(triangle_t sides)
{
    bool isEquilateral = false;

    if(is_triangle(sides))
    {
        if(sides.a == sides.b && sides.a == sides.c && sides.a == sides.c)
        {
            isEquilateral = true;
        }
    }

    return isEquilateral;
}

bool is_isosceles(triangle_t sides)
{
    bool isIsosceles = false;

    if(is_triangle(sides))
    {
        if( sides.a == sides.b ||
            sides.a == sides.c ||
            sides.b == sides.c)
        {
            isIsosceles = true;
        }
    }

    return isIsosceles;
}

bool is_scalene(triangle_t sides)
{
    bool isScalene = false;
    
    if(is_triangle(sides))
    {
        if( sides.a != sides.b && 
            sides.a != sides.c &&
            sides.b != sides.c)
        {
            isScalene = true;
        }
    }

    return isScalene;
}

static bool is_triangle(triangle_t sides)
{
    bool isTriangle = false;

    if(sides.a != 0 && sides.b != 0 && sides.c != 0)
    {
        if( sides.a + sides.b >= sides.c &&
            sides.b + sides.c >= sides.a &&
            sides.a + sides.c >= sides.b)
        {
            isTriangle = true;
        }
    }

    return isTriangle;
}
