
//================================================================================================
// File:        hash_fun.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Function used for creating a hash key from string.
//================================================================================================

#include "private_htab.h"
#include "htab.h"

//function copied and slightly changed from http://www.cse.yorku.ca/~oz/hash.html - sdbm variant 
size_t htab_hash_fun(htab_key_t str)
{
    const unsigned char *p = (const unsigned char*)str;
    uint32_t h = 0;
    unsigned last;

    while ((last = *p++))
        h = (h << 16) + (h << 6) + last - h;

    return h;
}