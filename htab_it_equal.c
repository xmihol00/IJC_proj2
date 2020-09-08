
//================================================================================================
// File:        htab_it_equal.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Extern definition of Function that resturns wheather two iterators are equal or not.
//================================================================================================

#include "private_htab.h"
#include "htab.h"

extern bool htab_iterator_equal(htab_iterator_t it1, htab_iterator_t it2);