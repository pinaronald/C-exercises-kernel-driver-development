/*
 * =====================================================================================
 *
 *       Filename:  len.c
 *
 *    Description:  iCaluclate the length of the line:
 *
 *        Version:  1.0
 *        Created:  04/14/2020 02:58:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

int length( char string[])
{

	int index;
	for (index = 0; string[index] != '\0'; ++index )
		continue;
	return (index - 1);

}

int main()
{
	char line[100];

	while (1) {
		printf("Enter line: ");
		fgets(line, sizeof(line), stdin);
	
		printf("Leng includeing  is %d\n", length(line));

	}
}
