
//================================================================================================
// File:        tail-func.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: Tail functions
//================================================================================================ 

#include "tail.h"

int inspect_file(char *filename, unsigned long number_of_lines, bool print_filename)
{
    unsigned long nl_count = 0;
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        perror("tail:");
        return 1;
    }
    else if (print_filename) //printing the file name if there are multiple files and those files can be opened for reading
        printf("==> %s <==\n", filename);

    fseek(fptr, 0, SEEK_END);

    if (ftell(fptr) == 0) //nothing to be read
    {
        if (fclose(fptr))
        {
            perror("tail:");
            return 1;
        }
        return 0;
    }

    int c;
    while(ftell(fptr) > 1 && nl_count < number_of_lines)
    {
        fseek(fptr, -2, SEEK_CUR);
        if (getc(fptr) == '\n')
            nl_count++;
    }
    if (ftell(fptr) == 1 && nl_count < number_of_lines) //to load the first character of a file
        fseek(fptr, -1, SEEK_CUR);

    else if (ftell(fptr) == 1) //if new line is the first character in a file and the correct number of lines were loaded 
    {
        fseek(fptr, -1, SEEK_CUR);
        if (getc(fptr) != '\n')
            fseek(fptr, -1, SEEK_CUR);
    }
    
    while ((c = getc(fptr)) != EOF)
    {
        putchar(c);
    }

    //to add a new line after a line which ended directly with EOF
    fseek(fptr, -1, SEEK_CUR);
    if (getc(fptr) != '\n')
        putchar('\n');    

    if (fclose(fptr))
    {
        perror("tail:");
        return 1;
    }
    return 0;
}

int inspect_stdin(unsigned long number_of_lines)
{
    unsigned long offset = 0; //the position in the buffer (the first index of 2D array)
    unsigned long position = 0; //the second index in the 2D array
    bool line_dump = false;
    int exit_value = 0;

    //allocating one block of memory, using it as a string_buffer[][]
    char *string_buffer = calloc(MAX_LINE_SIZE * number_of_lines, sizeof(char)); 
    if (string_buffer == NULL)
    {
        fprintf(stderr, "tail: Memory allocation failed.\n");
        return 1;
    }

    int c;
    while((c = getchar()) != EOF)
    {
        if (line_dump) //dumping characters after an exceeding line was read
        {
            if (c == '\n')
            line_dump = false;
        }
        else
        {
            string_buffer[offset * MAX_LINE_SIZE + position++] = c;
            
            if (c == '\n' && position < 1025) 
            {
                string_buffer[offset++ * MAX_LINE_SIZE + position] = '\0';
                position = 0;
                if (offset == number_of_lines) //moving back to the first line of the buffer
                    offset = 0;
            }
            else if (position == 1024) //when too long line occures
            {
                if (!exit_value)
                    fprintf(stderr, "tail: Number of charatcers on a single line exceeded the limit, remaining characters were striped.\n");
                exit_value = 3;
                line_dump = true;
                string_buffer[offset * MAX_LINE_SIZE + MAX_LINE_IDX - 1] = '\n';
                string_buffer[offset++ * MAX_LINE_SIZE + MAX_LINE_IDX] = '\0';
                position = 0;
                if (offset == number_of_lines) //moving back to the first line of the buffer
                    offset = 0;
            }
        }
    }
    if (position) //when file ended with EOF directly after the last line
    {
        string_buffer[offset * MAX_LINE_SIZE + position++] = '\n';
        string_buffer[offset++ * MAX_LINE_SIZE + position] = '\0';
        position = 0;
        if (offset == number_of_lines) //moving back to the first line of the buffer
            offset = 0;
    }

    for (unsigned long i = 0; i < number_of_lines; i++)
    {
        printf("%s", &string_buffer[offset * MAX_LINE_SIZE]);
        
        if (++offset == number_of_lines) //moving back to the first line of the buffer
            offset = 0;
    }

    free(string_buffer);
    return exit_value;
}

int inspect_file_plus(char *filename, unsigned long number_of_ignored_lines, bool print_filename)
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        perror("tail");
        return 1;
    }
    else if (print_filename) //if the file was opened successfuly and multiple files are searched, than it's name is printed
        printf("==> %s <==\n", filename);

    int c;
    long unsigned i = 1;

    while((c = getc(fptr)) != EOF)
    {
        if (i == number_of_ignored_lines || !number_of_ignored_lines) //rest of the lines are printed
            putchar(c);
        else
            if (c == '\n') //ignores the number of ignored lines (i.e. prameter -n +5 means 4 lines are ignored 5th is printed)
                i++;
    }

    fseek(fptr, -1, SEEK_CUR);
    if (getc(fptr) != '\n' && i == number_of_ignored_lines) //new line when the file wasn't terminated successfuly
        putchar('\n');

    if (fclose(fptr))
    {
        perror("tail:");
        return 1;
    }
    return 0;
}

int inspect_stdin_plus(unsigned long number_of_ignored_lines)
{
    int c;
    long unsigned i = 1;
    char line_buff[MAX_LINE_SIZE] = {0,};
    unsigned idx = 0;
    int ret_val = 0;
    bool line_dump = false;

    line_list_t *head = calloc(1, sizeof(line_list_t)); //first unused item of the list is created
    if (head == NULL)
        return 1;
    
    line_list_t *tail = head; 

    while((c = getchar()) != EOF) 
    {
        if (i == number_of_ignored_lines || !number_of_ignored_lines)
        {
            if (line_dump)
            {
                if (c == '\n')
                    line_dump = false;
            }
            else
            {
                line_buff[idx++] = c;

                if (c == '\n' && idx < MAX_LINE_SIZE)
                {
                    line_buff[idx - 1] = '\0';
                    if ((tail = line_list_add(tail, line_buff)) == NULL)
                    {
                        line_list_free(head);
                        return 1;
                    }
                    idx = 0;
                }
                else if (idx == 1024)
                {
                    if(!ret_val)
                    {
                        ret_val = 3;
                        fprintf(stderr, "tail: Number of charatcers on a single line exceeded the limit, reamaining characters were striped.\n");
                    }
                    line_buff[MAX_LINE_IDX] = '\0';
                    line_dump = true;
                    if ((tail = line_list_add(tail, line_buff)) == NULL)
                    {
                        line_list_free(head);
                        return 1;
                    }
                    idx = 0;
                }
            }
        }
        else
        {
            if (c == '\n')
                i++;
        }
    }

    line_list_print_free(head);
    
    if (idx) //prints the last line if there was EOF directly after the characters without '\n'
    {
        line_buff[idx] = '\0';
        puts(line_buff);
    }

    return ret_val;
}

//function expects, that the list already has at least one item, tail cannot be NULL
line_list_t *line_list_add(line_list_t *tail, const char* line)
{
    if (tail != NULL)
    {
        tail->next = malloc(sizeof(line_list_t) + strlen(line) + 1); // new item is created
        if (tail->next == NULL)
        {
            fprintf(stderr, "tail: Memory allocation failed\n");
            return NULL;
        }

        strcpy(tail->next->line, line); //text is copied on the item
        tail->next->next = NULL;
        return tail->next;
    }
    return NULL;
}

void line_list_print_free(line_list_t *head)
{
    if (head == NULL)
        return;

    line_list_t *tmp = head; //empty head is freed
    head = head->next;
    free(tmp);

    while (head != NULL) //rest of the list is printed and freed
    {
        puts(head->line);
        tmp = head;
        head = head->next;
        free(tmp);
    }
    head = NULL;
}

void line_list_free(line_list_t *head)
{
    line_list_t *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    head = NULL;
}