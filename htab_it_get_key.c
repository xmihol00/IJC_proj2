
//================================================================================================
// File:        htab_it_get_key.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Function that returns string from given iterator.
//================================================================================================

#include "private_htab.h"
#include "htab.h"

//returns the key of the given item pointed to by the iterator
htab_key_t htab_iterator_get_key(htab_iterator_t it)
{
    if (it.ptr == NULL || it.t == NULL) //if the iterator isn't valid, NULL is returned
        return NULL;

    return it.ptr->key;
}