/*
 * =====================================================================================
 *
 *       Filename:  total5f.c
 *
 *    Description:  Calc total by using for
 *
 *        Version:  1.0
 *        Created:  04/12/2020 04:10:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

char line[60];
int total;
int current;
int counter;

int main()
{
	total=0;

	for (counter = 0; counter < 5; ++counter) {
		printf("Number ? ");
		
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &current);
		total += current;
	}
	
	printf("Total is %d\n ", total);
	return (0);
}
