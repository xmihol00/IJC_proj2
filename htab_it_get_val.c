
//================================================================================================
// File:        htab_it_get_val.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Function that returns the value (number of appearences) of item pointed to by its iterator
//================================================================================================

#include "private_htab.h"
#include "htab.h"

//returns the number of appearances of the given item pointed to by the iterator
htab_value_t htab_iterator_get_value(htab_iterator_t it)
{
    if (it.ptr == NULL || it.t == NULL) //if the iterator isn't valid, negative value is returned (as no item can have negative value)
        return -1;

    return it.ptr->data;
}