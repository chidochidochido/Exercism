#include "nucleotide_count.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const size_t outputStringSize = 50;

char *count(const char *dna_strand)
{
    unsigned short  countA = 0,
                    countC = 0,
                    countG = 0,
                    countT = 0;
    unsigned short  index  = 0;
    char *outputString = (char*)malloc(outputStringSize * sizeof(char));
    bool validDnaStrand = true;

    memset(outputString, '\0', (outputStringSize * sizeof(char)));
    
    while(dna_strand[index] != '\0' && validDnaStrand == true)
    {
        switch(dna_strand[index])
        {
            case 'A':
                countA++;
                break;
            case 'C':
                countC++;
                break;
            case 'G':
                countG++;
                break;
            case 'T':
                countT++;
                break;
            default:
                validDnaStrand = false;
        }
        
        index++;
    }

    if(validDnaStrand == true)
        sprintf(outputString, "A:%d C:%d G:%d T:%d", countA, countC, countG, countT);

    return outputString;
}