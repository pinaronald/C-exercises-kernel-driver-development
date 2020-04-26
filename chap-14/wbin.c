/*
 * =====================================================================================
 *
 *       Filename:  wbin.c
 *
 *    Description:  Writes number 0-127 to a binary file called test.out 
 *    using fputc()
 *
 *        Version:  1.0
 *        Created:  04/27/2020 01:03:55 AM
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
#ifndef __MSDOS__
#include <unistd.h>
#endif

int main()
{
	int current_char; /* current char to write */
	FILE *out_file;   /* output file */
	
	out_file = fopen("test.out", "w");
	if (out_file == NULL){
		fprintf(stderr, "Cannot open output file\n");
		exit (8);
	}
	
	for (current_char = 0; current_char < 128; ++current_char)
		fputc(current_char, out_file);

	fclose(out_file);
	return (0);
}
