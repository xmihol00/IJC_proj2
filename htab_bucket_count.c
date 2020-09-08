
//================================================================================================
// File:        htab_bucket_count.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Function that returns the number of rows of the hash table
//================================================================================================

#include "private_htab.h"
#include "htab.h"

//returns the array size of the given hash table
size_t htab_bucket_count(const htab_t * t)
{
    if (t == NULL)
        return 0;

    return t->arr_size;
}
