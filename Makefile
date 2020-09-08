
#================================================================================================
# File:        Makefile
# Case:        IJC-DU2, 10. 4. 2020
# Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
# Description: compilation of libraries: libhtab.a libhtab.so 
#			      programs:	 tail, wordcount, wordcount-dynamic
#================================================================================================

CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic -g
OBJ = htab_const_dest.o htab_item_const_dest_erase.o hash_fun.o htab_size.o htab_bucket_count.o htab_find.o htab_print.o htab_rehash.o\
htab_it_get_val.o htab_it_set_val.o htab_it_get_key.o htab_begin.o htab_end.o htab_it_next.o htab_it_valid.o htab_it_equal.o
EXE = tail wordcount wordcount-dynamic
DEF =
#DEF += -DHASHTEST 		#to use htab_hash_fun defined in wordcount.c
#DEF += -DREHASH_FUNC	#to preform hash table rehashing

all: $(EXE)

tail: tail-main.o tail-func.o
	$(CC) tail-main.o tail-func.o $(CFLAGS) -o tail

tail-main.o: tail-main.c tail.h
	$(CC) tail-main.c $(CFLAGS) $(DEF) -c -o tail-main.o

tail-func.o: tail-func.c tail.h
	$(CC) tail-func.c $(CFLAGS) $(DEF) -c -o tail-func.o

wordcount: wordcount.o libhtab.a io.o
	$(CC) wordcount.o io.o -static -L. -lhtab -o wordcount

wordcount-dynamic: wordcount.o libhtab.so io.o
	$(CC) wordcount.o io.o -L. -lhtab -o wordcount-dynamic
#$(CC) wordcount.o io.o -L. -Wl,-rpath=. -lhtab -o wordcount-dynamic 		#for rpath build of the library

wordcount.o: wordcount.c htab.h io.h
	$(CC) wordcount.c $(CFLAGS) $(DEF) -c -o wordcount.o

libhtab.a: $(OBJ)
	ar rcs libhtab.a $(OBJ)

libhtab.so: $(OBJ)
	$(CC) $(OBJ) -shared -o libhtab.so

#compiles all of the *.o files specified in variable OBJ 
%.o: %.c htab.h private_htab.h
	$(CC) $< $(CFLAGS) $(DEF) -fPIC -c -o $@

io.o: io.c io.h
	$(CC) io.c $(CFLAGS) -c -o io.o

.PHONY: clean pack

clean:
	rm *.o $(EXE)

pack:
	zip xmihol00 *.h *.c Makefile
