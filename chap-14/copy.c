/*
 * =====================================================================================
 *
 *       Filename:  copy.c
 *
 *    Description:  Count the number of characters in a file using fgetc()
 *
 *        Version:  1.0
 *        Created:  04/26/2020 10:36:34 PM
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

const char FILENAME[] = "input.txt";

int main()
{
	int count = 0;
	FILE	*in_file;  /* Input file */
	int ch;			   /* Character or EOF flag from input */

	in_file = fopen(FILENAME, "r");
	if ( in_file == NULL) {
		printf("Can not open file %s\n", FILENAME);
		exit (8);
	}	

	while (1) {
		ch = fgetc(in_file);
		if (ch == EOF)
			break;
		++count;
	}
	printf("Number of characters in %s is %d\n", FILENAME, count);
	
	fclose(in_file);
	return (0);
}


