/*
 * =====================================================================================
 *
 *       Filename:  total.c
 *
 *    Description:  Sum of all number till press 0 to break.
 *
 *        Version:  1.0
 *        Created:  04/11/2020 11:43:20 PM
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
int item;
int total;

int main()
{
	total = 0;
	while(1) {
	    printf("Enter # to add \nor 0 to stop:");                                   
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &item);
		
		if (item == 0)
			break;

		total += item;
		printf("Total: %d\n", total);

	}
	printf("Final total: %d", total);
	return (0);
}
