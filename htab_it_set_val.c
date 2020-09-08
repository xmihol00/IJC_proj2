
//================================================================================================
// File:        htab_it_set_val.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Function that set a value (number of appearences) of key ponted by the iterator
//================================================================================================

#include "private_htab.h"
#include "htab.h"

htab_value_t htab_iterator_set_value(htab_iterator_t it, htab_value_t val)
{
    if (it.ptr == NULL || it.t == NULL) // if the iterator isn't valid -1 is returned, as this value cannot represent valid value
        return -1;

    it.ptr->data = val; //changes the value
    return val;
}