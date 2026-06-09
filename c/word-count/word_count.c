#include "word_count.h"
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int count_words(const char *sentence, word_count_word_t *words)
{
    int unique_words = 0;
    int len = 0;
    char current_word[MAX_WORD_LENGTH + 1];

    for (int i = 0; ; i++)
    {
        char c = sentence[i];
        
        bool is_word_char = false;
        if (isalnum((unsigned char)c))
        {
            is_word_char = true;
        }
        else if (c == '\'')
        {
            char prev = i > 0 ? sentence[i-1] : '\0';
            char next = sentence[i+1];
            if (isalnum((unsigned char)prev) && isalnum((unsigned char)next))
            {
                is_word_char = true;
            }
        }

        if (is_word_char)
        {
            if (len < MAX_WORD_LENGTH)
            {
                current_word[len++] = tolower((unsigned char)c);
            }
            else
            {
                // Word exceeds maximum allowed length
                return EXCESSIVE_LENGTH_WORD;
            }
        }
        else
        {
            // Not a word character, marks end of a word if we were parsing one
            if (len > 0)
            {
                current_word[len] = '\0';
                
                // Check if the word is already in the words array
                int found = 0;
                for (int j = 0; j < unique_words; j++)
                {
                    if (strcmp(words[j].text, current_word) == 0)
                    {
                        words[j].count++;
                        found = 1;
                        break;
                    }
                }
                
                // If not found, add it as a new unique word
                if (!found)
                {
                    if (unique_words >= MAX_WORDS)
                    {
                        return EXCESSIVE_NUMBER_OF_WORDS;
                    }
                    strcpy(words[unique_words].text, current_word);
                    words[unique_words].count = 1;
                    unique_words++;
                }
                
                // Reset length for the next word
                len = 0;
            }
        }
        
        if (c == '\0')
        {
            break;
        }
    }

    return unique_words;
}