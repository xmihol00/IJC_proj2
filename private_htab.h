
//================================================================================================
// File:        private_htab.h
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Definitions of private data types (Definition of opaque structures)
//================================================================================================

#ifndef __P_HTAB_H__
#define __P_HTAB_H__

#include "htab.h"

//definition of type htab_item
struct htab_item
{
    htab_value_t data;
    struct htab_item *next;
    char key[];
};

//definition of type htab
struct htab
{
    size_t arr_size;
    size_t size;
    struct htab_item *arr[];
};

//function used by the rehashing function. It stores already allocated item to a new hash table
void store_item(size_t index, struct htab_item *item, htab_t *table);

#endif //__P_HTAB_H__