/*
 * =====================================================================================
 *
 *       Filename:  split.c
 *
 *    Description:  my_strchr() finds a char in a string, parameters 
 *						string_ptr -- string to look at
 *						find -- char to find
 *					returns a pointer to first occurrence of the char in 
 *					the string. 
 *
 *        Version:  1.0
 *        Created:  04/25/2020 11:30:26 PM
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

char *my_strchr(char * string_ptr, char find)
{
	while (*string_ptr !=  find) {
		/* Check for the end */
		if (*string_ptr == '\0')
			return (NULL);				/* Not found */
										/* else continue searching by incrementing the pointer*/
		++string_ptr;
	}
	return (string_ptr);				/*Found, return the pointer address of the char*/
}


int main()
{
	char line[80];			/* The input line */
	char *first_ptr;		/* Pointer to the first name */
	char *last_ptr;			/* Pointer to the last name */
	
	fgets(line, sizeof(line), stdin);

	/* Remove the trailer new line */
	line[strlen(line) - 1] = '\0';

	last_ptr = line; /* Last name is at the begining of the line */
	first_ptr = my_strchr(line, '/'); /* Find the schlash */
	
	/* Check for an error */
	if(first_ptr == NULL) {
		fprintf(stderr, "Error: Unable to find slash in %s\n", line);
		exit (8);
	}
	
	*first_ptr = '\0'; /* Zero out the slash */
	
	/* Move to first cagr of the name */
	++first_ptr;

	printf("First: %s Last: %s\n", first_ptr, last_ptr);
	return (0);
}
