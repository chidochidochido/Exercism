#include <string.h>
#include <stdlib.h>
#include "two_fer.h"

void two_fer(char *buffer, const char *name)
{
    memset(buffer, '\0', 100);

    strcat(buffer, "One for ");

    if(name == NULL)
    {
        strcat(buffer, "you");
    }
    else
    {
        strcat(buffer, name);
    }

    strcat(buffer, ", one for me.");

}