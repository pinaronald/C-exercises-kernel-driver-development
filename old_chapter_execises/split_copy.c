/*
 * =====================================================================================
 *
 *       Filename:  split_copy.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/26/2020 12:06:05 AM
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

/* search_string function  - return a string to the finded char
 * parameters :  a pointer to the string and the char to find */

char *search_string(char * string_ptr, char find)
{

	while (*string_ptr != find ) {

		if(*string_ptr == '\0') /* has reached the end on the line without findin it */
			return (NULL);

		++string_ptr;
	}
	return(string_ptr); /* Return the pointer to the slash char, 
						which is the bigining of the second part of the string */
}


int main()
{
	char line[80];				/* Input line */
	char *first_ptr;			/* Pointer to first name */
	char *last_ptr;				/* Ponter to last name */
	
	fgets(line, sizeof(line), stdin);

	/* Get rid of the newline char*/
	line[strlen(line) - 1] = '\0';

	last_ptr = line;			/* Lastname beging in the first part of the string  */
	first_ptr = search_string(line, '/'); 

	/* Check for error */
	if (first_ptr == NULL) {
		fprintf(stderr, "Error: Unable to find slash in the %s\n", line);
		exit (8);
	}
		
	*first_ptr = '\0'; /* Zero the slash char */
	++first_ptr; /* move the pointer to the fisr char of the name*/
	
	printf("First: %s  Last: %s\n", first_ptr, last_ptr);
	return (0);
}
