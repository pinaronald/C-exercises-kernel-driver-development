/*
 * =====================================================================================
 *
 *       Filename:  nonwhite.c
 *
 *    Description:  Program that returns a pointer to the first nonwhite 
 *    char in a string.
 *
 *        Version:  1.0
 *        Created:  04/26/2020 06:04:25 PM
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

char line[60]; /* line to be taken from input*/
char *string_ptr;


char *find_nonwhite( char *string_ptr)
{
	while (*string_ptr != '\0'){
		if( *string_ptr != ' ') 
			return (string_ptr);
		++string_ptr;
	}
	return (NULL);
}

int main()
{
	char *nonwhite_ptr;
	printf("Enter the string:");
	fgets(line, sizeof(line), stdin);
	nonwhite_ptr = find_nonwhite(line);
	
	if ( nonwhite_ptr == NULL){
		fprintf(stderr, "Error: unable to find a nonwhite char in the string");
		exit (8);
	}
	printf("\nThe address of pinter of the first nonwhite char is %p \n\n", nonwhite_ptr);
	printf("The formated string is %s \n\n", nonwhite_ptr);

	return (0);
}

