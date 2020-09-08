
//================================================================================================
// File:        tail-main.c
// Case:        IJC-DU2, 10. 4. 2020
// Author:      David Mihola, FIT, xmihol00@stud.fit.vutbr.cz
// Compiled:    gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
// Description: The main function of program tail.
//              This program should simulate (with limited functionality) the GNU tail.
//              Program prints N (or 10 if not specified) lines from the end of file.
//              Use [-n NUMBER_OF_LINES] to specify the number of printed lines.
// Notes:       On sucess 0 is returned, when memory allocation fails or file could not be opened
//              1 is returned, when line exceeding the limitation limit is encountered 3 is returned
//================================================================================================ 

#include "tail.h"

int main (int argc, char *argv[])
{
    long num_of_lines = 10;
    char *invalid_optarg = NULL;
    bool n = true;
    bool plus_mode = false;
    int ret_val = 0;

    int option;
    opterr = 0;
    while((option = getopt(argc, argv, ":n:")) != -1)
    {
        if (option == 'n')
        {   
            if (n)
            {
                if (*optarg == '+')
                    plus_mode = true;

                num_of_lines = strtol(optarg, &invalid_optarg, 10);

                //to simulate the beahaviour of GNU tail, when the sppecified number of lines is negative
                num_of_lines = (num_of_lines >= 0)?(num_of_lines):(-num_of_lines);

                if ((invalid_optarg != NULL && *invalid_optarg != '\0')) //checks if only numbers were entered
                {
                    fprintf(stderr, "tail: Option -n requires a number as it's parameter\n");
                    PRINT_USAGE;
                    return 1;
                }
                else if (errno == ERANGE) //checks if the rande was in the limit of long
                {
                    fprintf(stderr, "tail: Number of lines is over the limit.\n");
                    PRINT_USAGE;
                    return 1;
                }
                n = false;

                if (num_of_lines == 0 && !plus_mode) //if 0 lines was specified, then there is nothink to print
                    return 0;
            }
            else //when -n is specidfied multiple times
            {
                fprintf(stderr, "tail: Option -n can be specified only once\n");
                PRINT_USAGE;
                return 1;
            }
        }
        else if (option == ':') // -n without parametr
        {
            fprintf(stderr, "tail: Option -n requires a parametr\n");
            PRINT_USAGE;
            return 1;
        }
        else if (option == '?') // invalid option
        {
            fprintf(stderr, "tail: Invalid option %c.\n", optopt);
            PRINT_USAGE;
            return 1;
        }
    }

    if (optind < argc) //when thre are more argumnets, it's expected, that those are file names
    {
        bool name_print = (optind +1) < argc; //if there was just one argument, name of the file is not printed
        for (int i = optind; i < argc; i++)
        {
            if (plus_mode) //when -n +NUMBER is entered (NUMBER - 1 lines are skipped, rest is printed)
            {
                if(inspect_file_plus(argv[i], num_of_lines, name_print))
                    ret_val = 1;

                else if (name_print && i + 1 < argc)
                    putchar('\n');
            }
            else
            {
                if (inspect_file(argv[i], num_of_lines, name_print))
                    ret_val = 1;

                else if (name_print && i + 1 < argc)
                    putchar('\n');
            }   

            //if (name_print && i + 1 < argc)
                //putchar('\n');
        }
    }
    else if (optind == argc) //when no parameters were given, then the input is read from stdin
    {
        if (plus_mode) //when -n +NUMBER is entered (NUMBER - 1 lines are skipped, rest is printed)
        {
            return inspect_stdin_plus(num_of_lines);
        }
        else
        {
            return inspect_stdin(num_of_lines);
        }
    }
    
    return ret_val;
}

