
//================================================================================================
// File:        htab_find.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Function that finds specified item of the hash table and returns iterator to it.
//================================================================================================

#include "private_htab.h"
#include "htab.h"

//finds the given key in the given hash table, if the key doesn't exist, iterator to the end() is returned
htab_iterator_t htab_find(htab_t * t, htab_key_t key)
{
    if (t == NULL) //checks if the table is valid
    {
        fprintf(stderr, "htab_find: Cannot search an empty table\n");
        return (htab_iterator_t) { .ptr = NULL, .t = NULL, .idx = 0};
    }

    size_t index = htab_hash_fun(key) % t->arr_size; //calculates the index of key, that needs to be find
    struct htab_item *tmp = t->arr[index];

    while(tmp != NULL) //searches through a single linked list
    {
        if (!strcmp(tmp->key, key)) //when the keys matches, the desired item is found
            return (htab_iterator_t) { .ptr = tmp, .t = t, .idx = index};
        
        tmp = tmp->next;
    }

    //the entered key wasn't found in the hash table, iterator to the end is returned
    return (htab_iterator_t) { .ptr = NULL, .t = t, .idx = (t->arr_size - 1)};      
}