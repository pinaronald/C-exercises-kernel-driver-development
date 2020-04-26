/*
 * =====================================================================================
 *
 *       Filename:  print.c
 *
 *    Description:  Formats files for printing. This programs can read 
 *    comand line parameters and act accrodingly. 
 *    print_file [-v] [-lleng] [-oname] [file1] [file2]...
 *		file1.. are the filelist to print, if no file is given it will 
 *		print print.in file.
 *			Usage:  print [options] file(s)
 *		  Options:  
 *					-v			produces verbose messaging
 *					-o<file>	Sends outout to a file, default= print.out
 *					-l<lines>	Sets the number of lines/page (defalult=66)
 *
 *        Version:  1.0
 *        Created:  04/26/2020 12:44:17 PM
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

int verbose = 0;							/* Verbose mode default=false */
char *out_file = "print.out";				/* output filename  */
char *program_name;							/* name of the program for errors */
int line_max = 66;							/* number of lines per page */

/*******************************************************************************
 * do_file - Dummy routine to handle  file
 * 
 * Parameters: 
 *				name -- Name of the file to print 
 * ****************************************************************************/

void do_file(char *name)
{
	printf("Verbose %d, Lines %d, Input %s, Output %s\n", verbose, line_max, 
		name, out_file);
}

/*****************************************************************************
 * usage  -- tell the users how to use this program and exits
 *
 * ***************************************************************************/

void usage(void)
{
	fprintf(stderr, "Usage is %s [options] [file-list]\n", program_name);
	fprintf(stderr, "Options\n");
	fprintf(stderr, "     -v				verbose\n");
    fprintf(stderr, "     -l<number>        Number of lines\n");   
    fprintf(stderr, "     -o<name>          Set output file name\n");      
	exit (8);                          
}

int main(int argc, char *argv[])
{

	/* Save the program name for future use */
	program_name = argv[0];

	/* loop for each option 
	*		stop if we run out of arguments
	*		or we get an argument without a dash	
	*/			

	while ((argc > 1)  && (argv[1][0] == '-')) {

		/* argv[1][1] is the actual option character */
		switch(argv[1][1]) {
			case 'v':				/* verbose*/
				verbose = 1;
				break;
			/* -o<file> output file
			*  [0] is the dash
			*  [1] is "o"
			*  [2] starts the name 
			*/		
			case 'o':
				out_file = &argv[1][2];
				break;

			/* -l<number>	set max nuber of lines
			 * atoi() is used to convert the string to interger
			 * we know that argv[1][2] is the first char of the string
			 * containing the number thus  we pass taht to atoi()
			 */		
			case 'l':
				line_max = atoi(&argv[1][2]);	
				break;
					
			default: 
				fprintf(stderr, "Bad option %s\n", argv[1])	;
				usage();
		}
		/*
		*	move the argument list up one
		*	move the count down one
		*	this consimes an argument, one less option
		*	after the pointer increases argv[0] no longes points to the 
		*	program name, the switch option is used to decode the options
		*/
		++argv;
		--argc;
	}	

	/* At this point all of the options have been processed
	 * check to see if we have no files in the list, it will execute 
	 * do_file for each file argument
	 * If no files exists we need to process just standart input stream
	 */
	if (argc == 1){
		do_file("print.in");
    } else{
		while (argc > 1){
			do_file(argv[1]);
			++argv;
			--argc;
		}
			
	}
	return (0);
}

