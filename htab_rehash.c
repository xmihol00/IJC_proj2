
//================================================================================================
// File:        htab_rehash.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Function that resezis the hash table (changes the bucket size) and rehashes the items
//              to a new order according the new size 
// Notes:       This function wans't specified in the assigment, I implemented it based on the assigment,
//              that was discusssed on last year lecture.
//================================================================================================ 

#include "htab.h"
#include "private_htab.h"

void htab_rehash(htab_t **t)
{
    if (t == NULL)
        return;

    //size is always > 0 (see: htab_init.c)
    long double load_factor = ((long double)((*t)->size))/((long double)((*t)->arr_size));

    if (load_factor > 0.75)
    {
        //fprintf(stderr, "Rehashing...\n");
        htab_t *tmp_table = NULL;
        struct htab_item *item_hold = NULL;
        struct htab_item *next_item = NULL;
        size_t index;

        if ((tmp_table = htab_init((*t)->arr_size * 2)) == NULL)
        {
            fprintf(stderr, "htab_rehash: Rehashing failed, program continues with the old hash table size.");
            return;
        }

        for (size_t i = 0; i < (*t)->arr_size; i++)
        {
            item_hold = (*t)->arr[i]; //loads the single linked list from hash table
            while(item_hold != NULL) //stores all items of the linked list to a new hash table
            {
                next_item = item_hold->next; //stores the pointer to the next item
                index = htab_hash_fun(item_hold->key) % tmp_table->arr_size; //calculation of the new idex of already stored key
                store_item(index, item_hold, tmp_table); //item is stored to the new hash table
                item_hold = next_item; //moving to the next item
            }
        }

        tmp_table->size = (*t)->size; //the size of the new hash table has to copied
        free((*t)); //old hash table is freed
        (*t) = tmp_table; //old hash table is replaced with the new one
    }
}

void store_item(size_t index, struct htab_item *item, htab_t *table)
{
    struct htab_item *tmp = NULL;

    item->next = NULL; //newly stored item does not have next item

    if (table->arr[index] == NULL) //when there isn't any item stored at current row of hash table
    {
        table->arr[index] = item;
    }
    else //when there are already items stored, than searched the end of single linked list and stores the item there
    {
        tmp = table->arr[index];
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = item;
    }
}