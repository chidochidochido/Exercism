#include <stdlib.h>
#include <string.h>
#include "rotational_cipher.h"

char *rotate(const char *text, int shift_key)
{
    int index, adjustedKey;
    int intRotatedChar;
    char *newText = malloc(strlen(text) + 1);

    memset(newText, '\0', strlen(text) + 1);

    adjustedKey = shift_key % 26;

    index = 0;
    while(text[index] != '\0')
    {
        if(text[index] >= 'a' && text[index] <= 'z')
        {
            intRotatedChar = (int)text[index] + adjustedKey;
        
            if(intRotatedChar > (int)'z')
            {
                intRotatedChar = intRotatedChar % ((int)'z' + 1) + (int)'a';
            }
            
            newText[index] = (char)intRotatedChar;

        }
        else if(text[index] >= 'A' && text[index] <= 'Z')
        {
            intRotatedChar = (int)text[index] + adjustedKey;
            
            if(intRotatedChar > (int)'Z')
            {
                intRotatedChar = intRotatedChar % ((int)'Z' + 1) + (int)'A';
            }

            newText[index] = (char)intRotatedChar;
        }
        else
        {
            newText[index] = text[index];
        }

        index++;
    }
    

    return newText;
}
