
//================================================================================================
// File:        htab_item_size.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Function that returns the size (number of items) of hash table 
//================================================================================================

#include "private_htab.h"
#include "htab.h"

size_t htab_size(const htab_t * t)
{
    if (t == NULL) //if the table isn't valid, 0 is returned as a valid table has to have at least 1 row
        return 0;

    return t->size; //the bucket size is returned
}