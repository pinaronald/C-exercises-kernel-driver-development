/*
 * =====================================================================================
 *
 *       Filename:  max2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/15/2020 12:36:52 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

#define MAX 10

int main()
{
	int counter;
	
	for (counter =MAX; counter > 0; --counter)
		printf("Hello \n");
	
	return (0);
	
}

