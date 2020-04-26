/*
 * =====================================================================================
 *
 *       Filename:  totalb.c
 *
 *    Description:  Calc total, by using "continue" statemanet
 *
 *        Version:  1.0
 *        Created:  04/12/2020 12:35:06 AM
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
int minus_item;

int main()
{
	total = 0;
	minus_item = 0;

	while (1) {
		printf("Add # to add \nor 0 to stop:");
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &item);

		if (item == 0)
			break;

		if (item < 0) {
			++minus_item;
			continue;
		}
		
		total  += item;
		printf("Total: %d .\n", total);
	}
	printf("Final total %d\n", total);
	printf("With %d negative item omitted\n", minus_item);
	return (0);                                          
}
