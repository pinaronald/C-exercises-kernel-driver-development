/*
 * =====================================================================================
 *
 *       Filename:  exc-14-3.c
 *
 *    Description:  Program that reads a file containing a list o numbers 
 *    a writes it to two different files, one containg the numbers 
 *    devisable by 3 and another containing the other.
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
	char ch;
	FILE *infile, *outfile1, *outfile2;
	
	if (argc != 4) {                                                            
        fprintf(stderr, "Error, wrong number of arguments\n");                  
        fprintf(stderr, "Usage is: copy4 <infile> <file1> <file2> \n");       
        exit (8);                                                               
    }      

	infile = fopen(argv[1], "r");
	if ( infile == NULL ){
		fprintf(stderr, "Error, unable to open the input file\n");              
		exit (8);       
	}
	
	outfile1 = fopen(argv[2], "w");                                               
    if ( infile == NULL ){                                                      
        fprintf(stderr, "Error, unable to open the output file\n");              
        exit (8);                                                               
    }            
	
    outfile2 = fopen(argv[3], "w");                                             
    if ( infile == NULL ){                                                      
        fprintf(stderr, "Error, unable to open the output file\n");             
        exit (8);                                                               
    } 
	
	while ((ch = fgetc(infile)) != EOF){
		/* Ch is a char, in order to convert it as integer, we use
		* the trick substracting with 48, or by '0' as 48 is '0'*/
		if ( ((ch - '0') % 3) != 0 || (ch == '0') )
			fputc(ch, outfile2);
		else
			fputc(ch, outfile1);
	}
	
	fclose(infile);
	fclose(outfile1);
    fclose(outfile2);                                                           
		
	return(0);
}

