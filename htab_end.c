
//================================================================================================
// File:        htab_end.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Function that returns iterator to the item behind the last item of the hash table.
//              (The returned pointer to the hash table item will be allways NULL)
//================================================================================================

#include "private_htab.h"
#include "htab.h"

//returns iterator to the end of the given hash table (on to one item after the last item)
htab_iterator_t htab_end(const htab_t * t)
{
    if (t == NULL)
        return (htab_iterator_t) {.ptr = NULL, .t = NULL, .idx = 0};
    
    return (htab_iterator_t) {.ptr = NULL, .t = t, .idx = (t->arr_size -1)};
}