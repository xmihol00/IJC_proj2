
//================================================================================================
// File:        io.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Function that loads a word from file. 
//================================================================================================

#include "io.h"

int get_word(char *s, int max, FILE *f)
{
    static bool error;
    if (max < 1)
    {
        fprintf(stderr, "invalid max size (must be larger than 0)\n");
        return 0;
    }
    if (f == NULL)
    {
        fprintf(stderr, "Invalid file pointer\n");
        return 0;
    }
    
    int c;
    while((c = fgetc(f)) != EOF && isspace(c)); //clears whitespaces infront of word

    if (c == EOF)
    {
        s[0] = '\0';
        return EOF;
    }
    
    s[0] = c; //the first character that is not whitespace
        
    int i = 1;
    for (; (c = fgetc(f)) != EOF && !isspace(c) && i < (max -1); i++)
        s[i] = c;

    s[i] = '\0';
    if (c == EOF)
        return EOF;
    
    if (i == max - 1 && !isspace(c))
    {
        if (!error)
        {   
            fprintf(stderr, "get_word: Word longer than buffer size occured, remaining characters were striped\n");
            error = true;
        }

        while ((c = fgetc(f)) != EOF && !isspace(c)); //removes exceeding characters of the word

        return i + 2;
    }

    return i;
}