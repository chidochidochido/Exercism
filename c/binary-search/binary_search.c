#include "binary_search.h"
const int *binary_search(int value, const int *arr, size_t length)
{
    int* foundValuePtr = NULL;
    int top = length - 1;
    int bottom = 0;
    int middle;

    if(length > 0 && arr != NULL)
    {
        do
        {
            middle = (top + bottom) / 2;
            if(arr[middle] == value)
            {
                foundValuePtr = (int*)(arr + middle);
            }
            else if(arr[middle] > value)
            {
                top = middle - 1;
            }
            else
            {
                bottom = middle + 1;
            }
        } while((top >= bottom)  && (foundValuePtr == NULL));
    }

    return foundValuePtr;
}