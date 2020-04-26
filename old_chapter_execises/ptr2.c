/*
 * =====================================================================================
 *
 *       Filename:  ptr2.c
 *
 *    Description:  Count number of non zero elemnts in an array
 *
 *        Version:  1.0
 *        Created:  04/25/2020 07:59:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

int array[] = {4, 4, 6 ,9, 0, 3, 1, 8, 3, 2, 0, 4};

int main()
{

	int	index = 0;
	while(array[index] != 0)
		++index;

	printf(" Number of elements before zero %d\n", index);
	return (0);


}
