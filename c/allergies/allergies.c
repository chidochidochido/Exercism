#include <math.h>
#include "allergies.h"

allergen_list_t get_allergens(unsigned int count)
{
    allergen_list_t myList = {0, {0}};
    allergen_t alergies = ALLERGEN_EGGS;

    count %= 256;

    while(count > 0)
    {
        if(count % 2 != 0)
        {
            myList.allergens[alergies] = true;
            myList.count++;
        }
        
        alergies++;
        count /= 2;
    }

    return myList;
}

bool is_allergic_to(allergen_t alergy, unsigned int count)
{
    allergen_list_t myList = get_allergens(count);

    return myList.allergens[alergy];
}