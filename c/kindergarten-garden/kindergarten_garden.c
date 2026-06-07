#include "kindergarten_garden.h"
#include <string.h>
#include <stdio.h>

typedef enum studentIndexVal_tag
{
    ALICE = 0,
    BOB = 1,
    CHARLIE = 2,
    DAVID = 3,
    EVE = 4,
    FRED = 5,
    GINNY = 6,
    HARRIET = 7,
    ILEANA = 8,
    JOSEPH = 9,
    KINCAID = 10,
    LARRY = 11,
    INVALID = 12
} studentIndexVal_type;

static studentIndexVal_type getStudentIndex(const char *student)
{
    studentIndexVal_type studentIndex = INVALID;
    if(strcmp("Alice", student) == 0)
    {
        studentIndex = ALICE;
    }
    else if(strcmp("Bob", student) == 0)
    {
        studentIndex = BOB;
    }
    else if(strcmp("Charlie", student) == 0)
    {
        studentIndex = CHARLIE;
    }
    else if(strcmp("David", student) == 0)
    {
        studentIndex = DAVID;
    }
    else if(strcmp("Eve", student) == 0)
    {
        studentIndex = EVE;
    }
    else if(strcmp("Fred", student) == 0)
    {
        studentIndex = FRED;
    }
    else if(strcmp("Ginny", student) == 0)
    {
        studentIndex = GINNY;
    }
    else if(strcmp("Harriet", student) == 0)
    {
        studentIndex = HARRIET;
    }
    else if(strcmp("Ileana", student) == 0)
    {
        studentIndex = ILEANA;
    }
    else if(strcmp("Joseph", student) == 0)
    {
        studentIndex = JOSEPH;
    }
    else if(strcmp("Kincaid", student) == 0)
    {
        studentIndex = KINCAID;
    }
    else if(strcmp("Larry", student) == 0)
    {
        studentIndex = LARRY;
    }

    return studentIndex;
}

static int getNumberPlantsFirstRow(const char *diagram)
{
    int numberOfPlantsIndex = 0;
    int numberOfPlants = 0;


    while(diagram[numberOfPlantsIndex] != '\n')
    {
        numberOfPlantsIndex++;
    }

    if(numberOfPlantsIndex > 0)
    {
        numberOfPlants = numberOfPlantsIndex;
    }

    return numberOfPlants;
}

static plant_t getPlant(const char* plantStudent)
{
    plant_t plantResult;

    if(*plantStudent == 'G')
    {
        plantResult = GRASS;
    }
    else if(*plantStudent == 'C')
    {
        plantResult = CLOVER;
    }
    else if(*plantStudent == 'R')
    {
        plantResult = RADISHES;
    }
    else if(*plantStudent == 'V')
    {
        plantResult = VIOLETS;
    }

    return plantResult;
}

plants_t plants(const char *diagram, const char *student)
{
    plants_t plantsResult;

    int numberOfPlants;
    char *diagramSecondRow;
    char *studentPlantsFirstRow;
    char *studentPlantsSecondRow;

    studentIndexVal_type studentIndex = getStudentIndex(student);

    numberOfPlants = getNumberPlantsFirstRow(diagram);

    studentPlantsFirstRow  = (char *)(diagram + (studentIndex * 2));

    diagramSecondRow = (char *)(diagram + numberOfPlants + 1);
    studentPlantsSecondRow = diagramSecondRow + (studentIndex * 2);

    plantsResult.plants[0] = getPlant(studentPlantsFirstRow);
    plantsResult.plants[1] = getPlant(studentPlantsFirstRow + 1);
    plantsResult.plants[2] = getPlant(studentPlantsSecondRow);
    plantsResult.plants[3] = getPlant(studentPlantsSecondRow + 1);

    return plantsResult;
}