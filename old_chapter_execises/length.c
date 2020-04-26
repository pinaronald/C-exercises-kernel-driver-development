/*
 * =====================================================================================
 *
 *       Filename:  length.c
 *
 *    Description:  length of string gtom keyboard
 *
 *        Version:  1.0
 *        Created:  04/10/2020 09:04:36 PM
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

char line[100];

int main()
{
	printf("Enter a line: ");
	fgets(line, sizeof(line), stdin);
	
	printf("The length of the line is: %d\n", strlen(line));
	return (0);

}
