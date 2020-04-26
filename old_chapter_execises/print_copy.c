/*
 * =====================================================================================
 *
 *       Filename:  print_copy.c
 *
 *    Description:  Copy of the print progaram
 *
 *        Version:  1.0
 *        Created:  04/26/2020 03:49:15 PM
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

char *program_name;
char *output_file = "print.out";
int line_max = 66;
int verbose = 0;

void do_file(char *name)
{
printf("Name: %s, Lines: %d, Verbose: %d, Output file: %s, Input file: %s\n", 
		program_name, line_max, verbose, output_file, name);
}

void usage(void)
{
	fprintf(stderr, "Usage %s is [options]  [input file list]\n", program_name);
	fprintf(stderr, "Options:\n");
    fprintf(stderr, "    -v				Verbose\n");   
    fprintf(stderr, "    -l<number>     Number of lines\n");    
    fprintf(stderr, "    -o<name>       Set output file name\n");                    
    exit (8);                                           
}

int main(int argc, char *argv[])
{

	printf("\n \t\t\t***Program name: print ***\n");
	/*Initialise the orogram name*/
	program_name = argv[0];

	/*Parse all options*/
	while ((argc > 1) && (argv[1][0] == '-')){
		switch (argv[1][1]) {
			case 'v':
				verbose = 1;
				break;
			case 'o':
				output_file = &argv[1][2];
				break;
			case 'l':
				line_max = atoi(&argv[1][2]);
				break;
			default:
				fprintf(stderr, "Bad option %s\n", argv[1]);
				usage();
		}
		
		++argv;
		--argc;
	}

	/* at this point we have consumed all options, now we check for the 
	* input files. 
	*/
	if (argc == 1){
		do_file("print.in");			
	} else {
		 /* in case there are more inour files*/
		 while ( argc > 1) {
			do_file(argv[1]);
			++argv;
			--argc;
		 }
	  }
	printf("\n\n");
	return (0);	
}
