
//================================================================================================
// File:        wordcount.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: main file for the program wordcount, which prints the number of appearences of different
//              words in an input from stdin
// Notes:       On success 0 is returned, when memory allocation fails 1 is returned, when line
//              exceeding the limitation limit is encountered, 3 is returned
//================================================================================================

#include <stdio.h>
#include "htab.h"
#include "io.h"

/*
    The majority of plain UTF-8 text books on https://www.gutenberg.org/ is smaller than 1 MB. I estimate that the avergage
    file size is somewhere around 400 KB.
    The average lenght of an english word is 4,7 characters (rounding it to 5) + 1 white space character == 6 characters. 
    400000 / 6 ~~ 67 000, that means approximately 67 000 words per file.
    According to WWW the best load factor for hashtable is 0.75
    (0.75 == number_of_keys / bucket_size) --> bucket_size == (number_of_keys / 0.75), bucket_size ~~ 89 000
    The words in a book will repeat (f.e. and, but, if, ...) will be wery frequent
    Words appeard 7 times in a book on average (tested on 6 books) --> bucket_size == 89 000 / 7  bucket_size ~~ 12 500
    But the averge number of keys (on this test sample) was only 10 650 and the average file size was 580 KB
    Considering that the program won't be always used for counting words in books, but also for lot smaller files, 
    I devided the number by 3 --> 10650 / 3 ~~ 3500
    
    So I chose the number 3 500 for the BUCKET_CONSTANT 
*/

#define BUCKET_CONSTANT 3500
#define MAX_WORD_LEN 128

//hash function, which is used when HASHTEST is defined (see: Makefile: DEF += -DHASHTEST)
//function was copied from http://www.cse.yorku.ca/~oz/hash.html - variant dbj2
#ifdef HASHTEST
size_t htab_hash_fun(htab_key_t str)
{
    size_t hash = 5381;
    int last;

    while ((last = *str++))
        hash = ((hash << 5) + hash) + last; 

    return hash;
}
#endif

int main ()
{
    htab_t *table = htab_init(BUCKET_CONSTANT);
    
    char key_arr[MAX_WORD_LEN] = {0,};
    int status;
    int ret_val = 0;

    while(true) //to ensure, that line, which ends directly with EOF is also loaded
    {
        status = get_word(key_arr, MAX_WORD_LEN, stdin);

        if(status > MAX_WORD_LEN)
            ret_val = 3;

        if (status == EOF && key_arr[0] == '\0') //when EOF is on a new line (the file is teminated correctly)
            break;

        //the newly loaded key is added to the hash table
        if (!htab_iterator_valid(htab_lookup_add(table, key_arr)))
        {
            htab_free(table);
            return 1;
        }
        
        //if REHASH_FUNC is defined, then the rehashing functions is placed here. (see: htab_rehash.c, Makefile)
        HTAB_REHASH(table);

        //the loop ends when EOF was read
        if (status == EOF)
            break; 
    }

    htab_iterator_t iterator = htab_begin(table);

    while(htab_iterator_valid(iterator)) //prints all items of the hash table 
    {
        printf("%s\t%d\n", htab_iterator_get_key(iterator), htab_iterator_get_value(iterator));
        iterator = htab_iterator_next(iterator);
    }

    //frees all the allocated resources
    htab_free(table);

    return ret_val;
}
