
//================================================================================================
// File:        htab_print.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Function that prints out the current state of a hash table
// Notes:       This function wans't specified in the assigment, it is mainly for debugging purposes.
//================================================================================================ 

#include "htab.h"
#include "private_htab.h"

void htab_print(const htab_t *t)
{
    if (t == NULL)
        return;

    struct htab_item *tmp = NULL;

    for (size_t i = 0; i < t->arr_size; i++) //iterates through the whole hash table
    {
        tmp = t->arr[i]; //loades sallocated all elemets of the list
        {
            printf(" %s ->", tmp->key);
            tmp = tmp->next;
        }
        puts(" ||"); //formats the end of a line
    }

}