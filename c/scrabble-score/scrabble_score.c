#include "scrabble_score.h"

unsigned int score(const char *word)
{
    unsigned int scrabbleScore = 0;

    for(unsigned int wordIndex = 0; word[wordIndex] != '\0'; wordIndex++)
    {
        switch (word[wordIndex])
        {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U':
            case 'u':
            case 'L':
            case 'l':
            case 'N':
            case 'n':
            case 'R':
            case 'r':
            case 'S':
            case 's':
            case 'T':
            case 't':
                scrabbleScore += 1;
                break;

            case 'D':
            case 'd':
            case 'G':
            case 'g':
                scrabbleScore += 2;
                break;

            case 'B':
            case 'b':
            case 'C':
            case 'c':
            case 'M':
            case 'm':
            case 'P':
            case 'p':
                scrabbleScore += 3;
                break;

            case 'F':
            case 'f':
            case 'H':
            case 'h':
            case 'V':
            case 'v':
            case 'W':
            case 'w':
            case 'Y':
            case 'y':
                scrabbleScore += 4;
                break;

            case 'K':
            case 'k':
                scrabbleScore += 5;
                break;

            case 'J':
            case 'j':
            case 'X':
            case 'x':
                scrabbleScore += 8;
                break;

            case 'Q':
            case 'q':
            case 'Z':
            case 'z':
                scrabbleScore += 10;
                break;

            default:
                break;
        }
    }

    return scrabbleScore;
}