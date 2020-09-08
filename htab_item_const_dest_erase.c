
//================================================================================================
// File:        htab_item_const_dest_erase.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Functions that allocate and free dynamic memory needed for operations with hash table items
// Notes:       All these functions are in one file, as it would be risky to redefine one without 
//              the others. There cloud be probability of memory leaks, in worse case segmentation faults. 
//================================================================================================

#include "private_htab.h"
#include "htab.h"

//adds new item to the hash table
htab_iterator_t htab_lookup_add(htab_t * t, htab_key_t key)
{
    if (t == NULL) //if invalid table is entered
    {
        fprintf(stderr, "htab_lookup_add: Cannot insert to an empty table\n");
        return (htab_iterator_t) { .ptr = NULL, .t = NULL, .idx = 0};
    }

    size_t index = htab_hash_fun(key) % t->arr_size; //the index of the entered key is calculated
    struct htab_item *tmp = t->arr[index]; //single linked list on this index is loaded

    if (t->arr[index] == NULL) //if the linked list is empty
    {
        //new item has to be created
        t->arr[index] = malloc(sizeof(struct htab_item) + strlen(key) + 1);
        if (t->arr[index] == NULL)
        {
            fprintf(stderr, "htab_lookup_add: Memory allocation failed\n");
            return (htab_iterator_t) { .ptr = NULL, .t = t, .idx = (t->arr_size - 1)};
        }
        tmp = t->arr[index];
    }
    else if (strcmp(tmp->key, key)) //if the linked list is not empty and the first item doesn't match the entered key
    {
        while (tmp->next != NULL) //searching through the linked list
        {
            if (!strcmp(tmp->next->key, key)) //if already existing item matches the entered key
            {
                tmp->next->data++;
                return (htab_iterator_t) { .ptr = tmp->next, .t = t, .idx = index};
            }
            tmp = tmp->next;
        }

        //if no exisiting item matched the entered key, new item has to be created
        tmp->next = malloc(sizeof(struct htab_item) + strlen(key) + 1);
        if (tmp->next == NULL)
        {
            fprintf(stderr, "htab_lookup_add: Memory allocation failed\n");
            return (htab_iterator_t) { .ptr = NULL, .t = t, .idx = (t->arr_size - 1)};
        }
        tmp = tmp->next;
    }
    else //if the first item of the linked list matches the entered key
    {
        tmp->data++;
        return (htab_iterator_t) { .ptr = tmp, .t = t, .idx = index};
    }

    t->size++;                  //the table size (number of items) is increased
    strcpy(tmp->key, key);      //the entered key is copied on to the newly created item
    tmp->data = 1;              //new item data is set to 1
    tmp->next = NULL;           //terminates the linked list

    return (htab_iterator_t) { .ptr = tmp, .t = t, .idx = index};
}

//erases all items in the hash table
void htab_clear(htab_t * t)
{
    if (t == NULL)
        return;

    struct htab_item *tmp;

    for (size_t i = 0; i < t->arr_size; i++) //iterates through the hash table rows
    {
        while(t->arr[i] != NULL) //frees each row (single linked list)
        {
            tmp = t->arr[i];
            t->arr[i] = t->arr[i]->next;
            free(tmp);
        }
    }
}

//erases item pointed to by the iterator from the hashtable
void htab_erase(htab_t * t, htab_iterator_t it)
{
    //checks if the entered data are valid
    if (t == NULL)
        return;
    
    if (t != it.t)
        return;

    if (it.ptr == NULL)
        return;
    
    if (t->arr[it.idx] == NULL)
        return;
    
    struct htab_item *layover = t->arr[it.idx]->next;

    if (t->arr[it.idx] == it.ptr) //if the first item of the hash table row (single linked list) matches the erased item
    {
        free(t->arr[it.idx]);
        t->arr[it.idx] = layover;
        it.ptr = NULL;
        it.idx = t->arr_size;
        t->size--;
        return;
    }

    struct htab_item *tmp = t->arr[it.idx];

    //if the item, that has to be erased isn't the first item of a linked list, then the whole linked list has to be seacrhed
    while (tmp->next != NULL)
    {
        if (tmp->next == it.ptr) //the item that has to be erased is found
        {
            layover = tmp->next->next;
            free(tmp->next);
            tmp->next = layover;

            it.ptr = NULL;
            it.idx = t->arr_size;
            t->size--;
            return;
        }
        tmp = tmp->next;
    }
}