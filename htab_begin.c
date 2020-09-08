
//================================================================================================
// File:        htab_begin.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Functions that finds the first elemnt of hash table and returns iterator to it.
//================================================================================================

#include "private_htab.h"
#include "htab.h"

htab_iterator_t htab_begin(const htab_t * t)
{
    if (t == NULL) //if invalid table is entered
        return (htab_iterator_t) {.ptr = NULL, .t = NULL, .idx = 0};
    
    for (size_t i = 0; i < t->arr_size; i++)
    {
        if (t->arr[i] != NULL) //finds the firs row of the hash table, that has an item
            return (htab_iterator_t) {.ptr = t->arr[i], .t = t, .idx = i};
    }

    //if the hash table is empty, than iterator to the end() is returned
    return (htab_iterator_t) {.ptr = NULL, .t = NULL, .idx = (t->arr_size - 1)};
}