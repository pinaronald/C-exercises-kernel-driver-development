/*
 * =====================================================================================
 *
 *       Filename:  stack4.c
 *
 *    Description:  A somall exmaple for assmly listings.
 *
 *        Version:  1.0
 *        Created:  05/21/2020 03:18:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

void function1(int param)
{
	int localVar = 99;
}

int main(void)
{

	int stackVar = 3;
	
	function1(stackVar);

	return 0;
}
