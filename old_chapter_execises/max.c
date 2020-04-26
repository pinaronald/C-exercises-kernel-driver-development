/*
 * =====================================================================================
 *
 *       Filename:  max.c
 *
 *    Description:  Finding max balue of a an array
 *
 *        Version:  1.0
 *        Created:  04/15/2020 12:07:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>
char line[100];
int array[100];

int max(int array[])
{
	int maximum = 1;
	int i;
	for (i = 0 ; i < 5 ; ++i) {
		if ( maximum < array[i] )
			maximum = array[i] ; 			
	}
	return (maximum);
}

int main()
{
				
	printf("Enter 5 numbers: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d %d %d %d %d", &array[0], &array[1], 
											&array[2],&array[3], &array[4] );
	printf("Max is %d\n", max(array));
	return (0);
}
