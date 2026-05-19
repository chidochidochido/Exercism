#include "acronym.h"
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_ACRONYM_SIZE     20u

char acronym[MAX_ACRONYM_SIZE];

char *abbreviate(const char *phrase)
{
    bool inASpaceOrInitSentence = true;
    unsigned short acronymIndex = 0;
    char* acronym = NULL; 

    if((phrase != NULL) && *phrase != '\0')
    {
        acronym = malloc(MAX_ACRONYM_SIZE * sizeof(char));
        memset(acronym, '\0', MAX_ACRONYM_SIZE);

        for(unsigned short i = 0u; phrase[i] != '\0'; i++)
        {
            if(phrase[i] == ' ' || phrase[i] == '-' || phrase[i] == '_')
            {
                inASpaceOrInitSentence = true;
            }
            else
            {
                if(inASpaceOrInitSentence == true)
                {
                    inASpaceOrInitSentence = false;
                    acronym[acronymIndex] = (char)toupper(phrase[i]);
                    acronymIndex++;
                }
            }
        }
    }
    
    return acronym;
}