#include "word_count.h"
#include <ctype.h>
#include <stdbool.h>

int count_words(const char *sentence, word_count_word_t *words)
{
    unsigned short charInSentenceIndex = 0;
    unsigned short wordCounter = 0;
    unsigned short charInWordIndex = 0;
    char testChar;

    do
    {
        testChar = tolower(sentence[charInSentenceIndex]);

        switch(testChar)
        {
            case '\0':
            case ' ' :
                charInWordIndex = 0;
                wordCounter++;
                break;

            default:
                words[wordCounter].count = 1;
                words[wordCounter].text[charInWordIndex] = testChar;
                charInWordIndex++;
                break;

        }

        charInSentenceIndex++;

    } while(testChar != '\0');

    return wordCounter;
}