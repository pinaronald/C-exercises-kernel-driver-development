/*
 * =====================================================================================
 *
 *       Filename:  exc-14-3.v2.c
 *
 *    Description:  Program that reads a file containing a list o numbers 
 *    a writes it to two different files, one containg the numbers 
 *    devisable by 3 and another containing the other. by using getline
 *
 *        Version:  1.0
 *        Created:  05/01/2020 08:07:15 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int number;
	FILE *infile_ptr, *dev3file_ptr, *nondev3file_ptr;
	char *line = NULL;		/* current line of the file*/
	size_t len = 0;			/* current line length*/

	if (argc != 4) {                                                            
        fprintf(stderr, "Error, wrong number of arguments\n");                  
        fprintf(stderr, "Usage is: copy4 <infile_ptr> <file1> <file2> \n");       
        exit (8);                                                               
    }      

	infile_ptr = fopen(argv[1], "r");
	if ( infile_ptr == NULL ){
		fprintf(stderr, "Error, unable to open the input file\n");              
		exit (8);       
	}
	
	dev3file_ptr = fopen(argv[2], "w");                                               
    if ( infile_ptr == NULL ){                                                      
        fprintf(stderr, "Error, unable to open the output file\n");              
        exit (8);                                                               
    }            
	
    nondev3file_ptr = fopen(argv[3], "w");                                             
    if ( infile_ptr == NULL ){                                                      
        fprintf(stderr, "Error, unable to open the output file\n");             
        exit (8);                                                               
    } 
	
	while ( getline(&line, &len, infile_ptr) != -1) {
		sscanf(line,"%d", &number);	
		if ((number % 3) != 0 || ( number == 0) )
			fprintf(nondev3file_ptr, "%d\n", number);
		else
			fprintf(dev3file_ptr, "%d\n", number);
	}

	free(line);	 /* free allocated memory */
	fclose(infile_ptr);
	fclose(dev3file_ptr);
    fclose(nondev3file_ptr);                                                           
		
	return(0);
}

