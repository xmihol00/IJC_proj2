
//================================================================================================
// File:        htab_const_dest.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Functions that, allocate and free dynamic memory needed for operations with hash table.
// Notes:       I put all of these functions in one file, because there would be a high chance of
//              memory leaks (or segmentation faults at worse), if one of the functions would be
//              redefined seperately.
//================================================================================================

#include "private_htab.h"
#include "htab.h"

//initilazis memory for hash table on size n
htab_t *htab_init(size_t n)
{
    //table cannot have 0 rows
    if (n == 0)
    {
        fprintf(stderr, "htab_init: Cannot allocate 0 item table\n");
        return NULL;
    }

    //everything is initialized to 0
    struct htab *table = calloc(sizeof(struct htab) + n*sizeof(struct htab_item*), 1);
    if (table == NULL)
    {
        fprintf(stderr, "htab_init: Memory allocation failed\n");
        return NULL;
    }
    //initial data are filled
    table->size = 0;
    table->arr_size = n;
    return table;
}

//frees the allocated resources needed by hash table (including it's items)
void htab_free(htab_t * t)
{
    if (t != NULL)
    {
        htab_clear(t);
        free(t);
    }
}