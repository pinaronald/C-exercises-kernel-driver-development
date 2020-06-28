/*
 * =====================================================================================
 *
 *       Filename:  stack_corruption.c
 *
 *    Description:  Stack corruption demonstration
 *
 *        Version:  1.0
 *        Created:  05/22/2020 01:32:18 AM
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

int main(int argc, char *argv[])
{
		int foo = 3;
		int bar = 9;
		char string[8];

		strcpy(string, argv[1]);

		printf("foo = %d\n", foo);
		printf("bar = %d\n", bar);

		return 0;
}	
