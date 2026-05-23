#include <stdlib.h>
#include <string.h>
#include "rna_transcription.h"

char *to_rna(const char *dna)
{
    char* rna = (char *)malloc(sizeof(char) * 13);

    memset(rna, '\0', sizeof(char) * 13);

    if(dna[0] != (char)'\0')
    {
        int i = 0;
        while(dna[i] != '\0')
        {
            switch(dna[i])
            {
                case 'G':
                    rna[i] = 'C';
                    break;
                case 'C':
                    rna[i] = 'G';
                    break;
                case 'T':
                    rna[i] = 'A';
                    break;
                case 'A':
                    rna[i] = 'U';
                    break;
            }
            
            i++;
        }

    }

    return rna;
}