/*
 * =====================================================================================
 *
 *       Filename:  array-p.c
 *
 *    Description:  Print out the array addresses and elemnts of the array
 *
 *        Version:  1.0
 *        Created:  04/25/2020 07:13:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

#define ARRAY_SIZE 10

char array[ARRAY_SIZE + 1]= "0123456789";

int main()
{
	int index;
	printf("&array[index] (array+index) array[index]\n");
	for(index=0;index < ARRAY_SIZE; ++index)
		printf("%-15p %-15p  Ox%c \n", &array[index], (array+index), array[index]);

	return 0;


}
