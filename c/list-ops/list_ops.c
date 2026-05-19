#include "list_ops.h"
#include <stdio.h>
// constructs a new list
list_t *new_list(size_t length, list_element_t* elements){
    list_element_t *p_listElement = malloc(length * sizeof(list_element_t));
    list_t *p_list = malloc(sizeof(list_t));

    p_list->length = length;
    memcpy(p_listElement, elements, length * sizeof(list_element_t));
    p_list->elements = p_listElement;

    return p_list;
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2) {
    
    size_t totalLength = 0;
    size_t list1Length = 0; 
    list_t* appendedList = (list_t*)malloc(sizeof(list_t));
    
    if(list1 != NULL)
        totalLength = list1Length = list1->length;
    
    if(list2 != NULL)
        totalLength += list2->length;

    appendedList->length = totalLength;
    appendedList->elements = malloc(totalLength * sizeof(list_element_t));

    memset(appendedList->elements, 0, totalLength);

    if(list1 != NULL)
        for(size_t i = 0; i < list1->length; i++)
            appendedList->elements[i] = list1->elements[i];

    if(list2 != NULL)
    {
        for(size_t i = list1Length, j = 0; i < list1Length + list2->length; i++, j++)
            appendedList->elements[i] = list2->elements[j];
    }

    return appendedList;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
    
    list_t *filteredList = malloc(sizeof(list_t));
    
    filteredList->length = 0;
    filteredList->elements = NULL;

    if(list != NULL)
    {        
        for(size_t i = 0; i < list->length; i++)
        {
            if(filter(list->elements[i]))
            {
                filteredList->elements = realloc(filteredList->elements, (filteredList->length + 1) * sizeof(list_element_t));
                filteredList->elements[filteredList->length] = list->elements[i];
                filteredList->length++;
            }
        }
    }

    return filteredList;
}

// returns the length of the list
size_t length_list(list_t *list) {
    size_t length = 0;

    if(list != NULL)
    {
        length = list->length;
    }

    return length;
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)) {
    list_t* mappedList = NULL;

    if(list != NULL)
    {
        mappedList = (list_t*)malloc(sizeof(list_t));
        mappedList->length = list->length;
        mappedList->elements = (list_element_t*)malloc(list->length * sizeof(list_element_t));

        for(size_t i = 0; i < list->length; i++)
        {
            mappedList->elements[i] = map(list->elements[i]);
        }
    }

    return mappedList;
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t)) {
    list_element_t result = initial;

    if(list != NULL)
    {
        for (size_t i = 0; i < list->length; i++)
        {
            result = foldl(list->elements[i], result);
        }
    }
    
    return result;
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t)) {
    list_element_t result = initial;
    
    if(list != NULL)
    {
        for (size_t i = list->length; i > 0; i--)
        {
            result = foldr(list->elements[i - 1], result);
        }
    }
    
    return result;
}

// reverse the elements of the list
list_t *reverse_list(list_t *list) {
    list_t* reversedList = NULL;
    
    if(list != NULL)
    {
        reversedList = (list_t*)malloc(sizeof(list_t));
        reversedList->length = list->length;
        reversedList->elements = (list_element_t*)malloc(list->length * sizeof(list_element_t));

        for(size_t i = 0; i < list->length; i++)
        {
            reversedList->elements[i] = list->elements[list->length - 1 - i];
        }
    }
    
    return reversedList;
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list) {
    (void)list;
}