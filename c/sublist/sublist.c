#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "sublist.h"

#define LIST_END   ((size_t)0)

static bool checkEqual(int *list_to_compare, int *base_list, size_t base_list_element_count)
{
    bool isEqual = false;

    if(memcmp(list_to_compare, base_list, base_list_element_count * sizeof(int)) == 0)
    {
        isEqual = true;
    }

    return isEqual;
}

static void findSublistStart(int list_to_compare_init_value, int *base_list, const int *base_list_limit)
{
    while(list_to_compare_init_value != *base_list && base_list < base_list_limit)
    {
        base_list++;
    }
}

static bool checkSublist(int *list_to_compare, int *base_list,size_t list_to_compare_element_count, size_t base_list_element_count)
{
    bool isSublist = false;
    const int *base_list_limit = base_list + base_list_element_count - 1;

    findSublistStart(list_to_compare[0], base_list, base_list_limit);

    while((base_list + list_to_compare_element_count - 1 <=  base_list_limit) && isSublist == false)
    {
        isSublist = checkEqual(list_to_compare, base_list, list_to_compare_element_count);

        if(isSublist == false)
        {
            base_list++;
            findSublistStart(list_to_compare[0], base_list, base_list_limit);
        }
    }

    return isSublist;
}

comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count)
{
    comparison_result_t result = UNEQUAL;

    if(list_to_compare_element_count == base_list_element_count)
    {
        if(checkEqual(list_to_compare, base_list, base_list_element_count) == true)
        {
            result = EQUAL;
        }
    }
    else if(list_to_compare_element_count < base_list_element_count)
    {
        if(list_to_compare == NULL || checkSublist(list_to_compare, base_list, list_to_compare_element_count, base_list_element_count) == true)
        {
            result = SUBLIST;
        }
    }
    else if(list_to_compare_element_count > base_list_element_count)
    {
        if(base_list == NULL || checkSublist(base_list, list_to_compare, base_list_element_count, list_to_compare_element_count) == true)
        {
            result = SUPERLIST;
        }
    }

    return result;
}