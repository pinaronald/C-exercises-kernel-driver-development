/*
 * =====================================================================================
 *
 *       Filename:  exc-14-1.c
 *
 *    Description:  Program that reads a file and then counts the number o 
 *    lines in it.
 *
 *        Version:  1.0
 *        Created:  04/30/2020 11:35:53 PM
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
#include <string.h>

char file_name[50];

int main()
{
	int count = 0;
	FILE *fd_file;
	char ch; /* the character to be tested for the ned of file or new line*/
	printf("Enter filename to count lines: ");
	fgets(file_name, sizeof(file_name), stdin);	
	file_name[strlen(file_name) - 1]= '\0'; /* trims the new line char*/

	fd_file = fopen(file_name, "r");
	if (fd_file == NULL) {
		printf("Error: can not open %s.\n", file_name);
		exit(8);
	}

	while (1) {
		ch = fgetc(fd_file);
		if (ch == EOF)
			break;
		if (ch == '\n')
			++count;
	}

	printf("Number of lines in %s is %d\n", file_name, count);

	fclose(fd_file);
	return (0);
}
