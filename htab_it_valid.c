
//================================================================================================
// File:        htab_it valid.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: extern definition on inline function, that returns if the iterator is valid
//================================================================================================

#include "private_htab.h"
#include "htab.h"

extern bool htab_iterator_valid(htab_iterator_t it);