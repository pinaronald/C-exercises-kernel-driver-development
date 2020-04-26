/*
 * =====================================================================================
 *
 *       Filename:  ptr3.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/25/2020 08:24:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

int array[] = { 2, 4, 4, 9, 0, 2, 1, 1, 9, 0, 2};
int *array_ptr;

int main()
{
	array_ptr = array;
	while( *array_ptr != 0 )
		++array_ptr;

	printf("Number of elements before zero is %ld\n", array_ptr - array);

	return (0);

}

