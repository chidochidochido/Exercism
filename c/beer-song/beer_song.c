#include "beer_song.h"
#include <stdio.h>

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
    uint16_t song_index = 0;
    
    while(take_down > 0)
    {
        if(start_bottles >= 1)
        {
            if(start_bottles > 1)
                sprintf(song[song_index], "%d bottles of beer on the wall, %d bottles of beer.", start_bottles, start_bottles);
            else if(start_bottles == 1)
                sprintf(song[song_index], "%d bottle of beer on the wall, %d bottle of beer.", start_bottles, start_bottles);

            song_index++;
            
            if(start_bottles - 1 > 1)
                sprintf(song[song_index], "Take one down and pass it around, %d bottles of beer on the wall.", start_bottles - 1);
            else if(start_bottles - 1 == 1)
                sprintf(song[song_index], "Take one down and pass it around, %d bottle of beer on the wall.", start_bottles - 1);
            else
                sprintf(song[song_index], "Take it down and pass it around, no more bottles of beer on the wall.");
            
            song_index++;
        }
        else
        {
            sprintf(song[song_index++], "No more bottles of beer on the wall, no more bottles of beer.");
            sprintf(song[song_index++], "Go to the store and buy some more, 99 bottles of beer on the wall.");
        }
        
        start_bottles--;
        take_down--;
        song_index++;
    }
}
