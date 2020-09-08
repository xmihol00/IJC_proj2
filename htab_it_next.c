
//================================================================================================
// File:        htab_it_next.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Function that increases the iterator. (Moves the iterator to point to the next item)
//================================================================================================

#include "private_htab.h"
#include "htab.h"

htab_iterator_t htab_iterator_next(htab_iterator_t it)
{
    //checks if the iterator is valid
    if (it.ptr == NULL && it.t == NULL)
        return (htab_iterator_t) {.ptr = NULL, .t = NULL, .idx = 0};
    
    if (it.ptr == NULL && it.t != NULL)
        return (htab_iterator_t) {.ptr = NULL, .t = it.t, .idx = (it.t->arr_size - 1)};

    //if the item pointed to by the iterator has a direct next item in the linked list, than the item is returned
    if (it.ptr->next != NULL)
        return (htab_iterator_t) {.ptr = it.ptr->next, .t = it.t, .idx = it.idx};

    for (size_t i = it.idx + 1; i < it.t->arr_size; i++)//if not, the rest of the hash table is searched
    {
        if (it.t->arr[i] != NULL)
            return (htab_iterator_t) {.ptr = it.t->arr[i], .t = it.t, .idx = i};
    }

    //if there is no other item in the elemt, the iterator to end() is returned
    return (htab_iterator_t) {.ptr = NULL, .t = it.t, .idx = (it.t->arr_size - 1)};
}