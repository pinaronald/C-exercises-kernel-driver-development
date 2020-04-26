/*
 * =====================================================================================
 *
 *       Filename:  full2.c
 *
 *    Description:  print full name entered from keyboard
 *
 *        Version:  1.0
 *        Created:  04/10/2020 09:18:16 PM
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

char first[100];
char last[100];
char full[100];

int main()

{
	printf("Enter first name: ");
	fgets(first, sizeof(first), stdin);
	/*trim first by removing end of line char \n*/
	first[strlen(first)-1] = '\0';

	printf("Enter last name: ");                                               
    fgets(last, sizeof(last), stdin);                                         
    /*trim last by removing end of line char \n*/                              
    last[strlen(last)-1] = '\0';    

	strcpy(full, first);
	strcat(full, " ");
	strcat(full, last);

	printf("Emri i plote eshte: %s\n", full);
	return (0);                                          
                                      
}

