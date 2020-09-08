
//================================================================================================
// File:        io.h
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: API for function get_word
//================================================================================================

#ifndef __IO_H__
#define __IO_H__

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int get_word(char *s, int max, FILE *f);

#endif //__IO_H__