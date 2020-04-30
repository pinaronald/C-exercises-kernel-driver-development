/*
 * =====================================================================================
 *
 *       Filename:  exc-14-2.c
 *
 *    Description:  Program to copy a file, and expanding all tabs to 
 *    multiple spaces. 
 *
 *        Version:  1.0
 *        Created:  05/01/2020 12:28:15 AM
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
	FILE *infile, *outfile;

	if (argc != 3 ){
		fprintf(stderr, "Error, wrong number of arguments\n");
		fprintf(stderr, "Usage is: copy3 <input file>  <output file>\n");
		exit (8);
	}
		
	infile = fopen(argv[1], "r");
	if (infile == NULL) {
		fprintf(stderr, "Error, unable to open the input file\n");
		exit (8);
	}
	
	outfile = fopen(argv[2], "w");                                               
	if (outfile == NULL) {                                                        
        fprintf(stderr, "Error, unable to open the output file\n");              
        exit (8);                                                               
    } 
		
	while ((ch = fgetc(infile)) != EOF ) {
		if ( ch != ' ')
			fputc(ch, outfile);                                                           
		else
			fputc('_', outfile);       
	}

	fclose(infile);                                                            
	fclose(outfile);                                                            
	return (0);
}

