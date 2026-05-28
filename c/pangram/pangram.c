#include "pangram.h"
#include <stdbool.h>
#include <string.h>

bool is_pangram(const char *sentence)
{
    bool letter_used['z' - 'a'];
    char letter;
    unsigned int  index;
    bool all_letters_used = true;

    memset(letter_used, false, sizeof(letter_used));

    if(sentence != NULL)
    {
        for(index = 0; (letter = sentence[index]) != '\0'; index++)
        {
            if(letter >= 'a' && letter <= 'z')
            {
                letter_used[letter - 'a'] = true;
            }
            else if(letter >= 'A' && letter <= 'Z')
            {
                letter_used[letter - 'A'] = true;
            }
       }
     
       for(index = 0; (index < (unsigned int)(sizeof(letter_used) / sizeof(bool))) &&  all_letters_used; index++) 
       {
           if(letter_used[index] == false)
           {
               all_letters_used = false;
           }
       } 
    }
    else
    {
        all_letters_used = false;
    }

    return all_letters_used;
}
