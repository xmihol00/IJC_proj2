
//================================================================================================
// File:        tail.h
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: API for tail functions
//================================================================================================

#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_SIZE 1025
#define MAX_LINE_IDX 1024

#define PRINT_USAGE do{ fprintf(stderr, "tail: usage: [-n NUMBER_OF_LINES] [--] [file_name]\n"); }while(0)

typedef struct line_list
{
    struct line_list *next;
    char line[];
}line_list_t;

/**
 * @brief prints specified number of lines counted from the end of the file to stdin
 * @param filename name of the file, form which the text is printed
 * @param number_of_lines number of lines that should be printed from the ned of the file
 * @param print_filename when true filename is printed, otherwise not
 * @return on success 0 otherwise 1
 */
int inspect_file(char *filename, unsigned long number_of_lines, bool print_filename);

/**
 * @brief skips specified number of lines and prints the rest of the file
 * @param filename name of the file, form which the text is printed
 * @param number_of_lines number of lines that should be skipped
 * @param print_filename when true filename is printed, otherwise not
 * @return on success 0 otherwise 1
 */
int inspect_file_plus(char *filename, unsigned long number_of_ignored_lines, bool print_filename);

/**
 * @brief prints specified number of lines counted from the end of input from stdin
 * @param number_of_lines number of lines to be printed, counted from the end of the file
 * @return on success 0 otherwise 1 when memory allcation fails, 3 when line exceeding the implementation limit is encountered
 */
int inspect_stdin(unsigned long number_of_lines);

/**
 * @brief skipps number_of_ignored_lines - 1 lines and prints the rest of the input from stdin
 * @param number_of_ignored_lines number that specifies the starting line, which should already be printed
 * @return on success 0 otherwise 1 when memory allcation fails, 3 when line exceeding the implementation limit is encountered
 */
int inspect_stdin_plus(unsigned long number_of_ignored_lines);

/**
 * @brief ads a new item to a linked list to the next position pointed by tail
 * @pre tail has to be valid item
 * @param tail poninter to the end of a linked list
 * @param line line of text to be added to the new item
 * @return on success pointer to a newly created item, otherwise NULL 
 */
line_list_t *line_list_add(line_list_t *tail, const char* line);

/**
 * @brief skips the firs item of the linked and then prints the rest, the whole linked list is deallocated
 * @param head pointer to the start of the linked list
 */
void line_list_print_free(line_list_t *head);

/**
 * @brief deallocates all the memory occupied by the linked list
 * @param head pointer to the start of the linked list
 */
void line_list_free(line_list_t *head);