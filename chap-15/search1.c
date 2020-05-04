/*
 * =====================================================================================
 *
 *       Filename:  search1.c
 *
 *    Description: Searches a set of numbers, you will be asked for the nr to search
 *          Files: number.dat , 1 number per line and ordered.       
 *
 *        Version:  1.0
 *        Created:  05/05/2020 12:48:43 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_NUMBERS     1000            /* max number in a file */

const char DATA_FILE[] = "numbers.dat"; /* files with numbers */
int data[MAX_NUMBERS];                  /* array of numbers to search */
int max_count;                          /* numbers of valid elemnts in the array/file */

int main()
{
    FILE *in_file;
    int middle;                         /* middle of our search range */
    int low, high;                      /* upper/lower bound */
    int search;                         /* number to search for */
    char line[80];                      /* input line */

    in_file = fopen(DATA_FILE, "r");
    if (in_file == NULL) {
        fprintf(stderr, "Error, unable to open %s\n", DATA_FILE);
        exit (8);
    }

    /* read in data */
    max_count = 0;
    while (1) {
        if (fgets(line, sizeof(line), in_file) == NULL)
            break;
 
        /* convert number */
        sscanf(line, "%d", &data[max_count]);
        ++max_count;
    }
    
    while(1) {
        printf("Enter number to search for or -1 to quit: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &search);

        if (search == -1)
            break;
        low = 0;
        high = max_count;

        while (1) {
            middle = (low + high) / 2;

            if (data[middle] == search)
                printf("Found at index %d.\n", middle);

            if (low == high){
                printf("Not found\n");
                break;
            }

            if (data[middle] < search)
                low = search;
            else
                high = search;
        }

    }
    return (0);
}
