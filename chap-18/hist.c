/*
 * =====================================================================================
 *
 *       Filename:  hist.c
 *
 *    Description:  Generates a historgram of an array of numbers. 
 *
 *        Version:  1.0
 *        Created:  05/13/2020 11:18:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include "ia.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/*
* Define the number of lines in the histogram
*/

#define NUMBER_OF_LINES 30
const int DATA_MIN = 1;
const int DATA_MAX = 30;

const int WIDTH = 60;

static struct infinite_array data_array;
static int data_items;

int main(int argc, char *argv[])
{
    void read_data(const char name[]);    /* function to read data */

    void print_histogram(void);           /* function to print the hostogram */

    if (argc != 2) {
        fprintf(stderr, "Usage: host <data file>\n");
        exit (8);
    }

    ia_init(&data_array);
    data_items = 0;

    read_data(argv[1]);
    print_histogram();

    return (0);

}

/***********************************************************************************************
 *  read_data -- reads data from the input file into the data array.
 * 
 *  Parameters: 
 *         name -- name of the file to read       
 * 
 ***********************************************************************************************/

void read_data(const char name[])
{
    char line[100];         /*line from the input file */
    FILE *in_file;
    int data;               /* data from input */

    in_file = fopen(name, "r");

    if(in_file == NULL) {
        fprintf(stderr, "Error:  unable to open");
        exit (8);
    } 

    while (1) {
        if (fgets(line, sizeof(line), in_file) == NULL)
            break;
        
        if (sscanf(line, "%d", &data) != 1) {            
            fprintf(stderr, "Error: input data not integer\n");
        }

        ia_store(&data_array, data_items, data);
        ++data_items;
    }
    
    fclose(in_file);
}

/***********************************************************************************************   
 *  print_histogram  -- Prints the histogram output. 
 ***********************************************************************************************/
void print_histogram(void)
{
    /* Uper bound for printouts */
    int counters[NUMBER_OF_LINES];

    int out_of_range = 0;  /* number of items out of bounds */
    int max_count = 0;     /* biggest counter */
    float scale;           /* scale for outputting dots */
    int i;             /* index into the data */

    memset(counters, '\0', sizeof(counters));

    for (i = 0; i < data_items; ++i) {
        int data; /* data for this point */
        data = ia_get(&data_array, i);

        if ((data < DATA_MIN) || (data > DATA_MAX))
            ++out_of_range;
        else {
            ++counters[data - DATA_MIN];
            if (counters[data - DATA_MIN] > max_count)
                max_count = counters[data - DATA_MIN];
        }
    }

    scale = ((float) max_count) / ((float) WIDTH);

    for (i = 0; i < NUMBER_OF_LINES; ++i) {

    	/* index for outputing the dots */
    	int char_index;
    	int number_of_dots;

    	printf("%2d (%4d): ", i + DATA_MIN, counters[i]);

   		number_of_dots = (int) (((float) counters[i]) / scale);

    	for (char_index = 0; char_index < number_of_dots; ++char_index)
        	printf("*");

    	printf("\n"); 
    }
    printf("%d items out of range \n", out_of_range);
}
