/*
 * =====================================================================================
 *
 *       Filename:  stack1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/20/2020 03:53:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */
#include <stdio.h>

int main(void)
{
	double stackVar1 = 1;
	double stackVar2 = 2;
	char szCommand[65];

	printf("Address if stackVar1 is 0x%x\n\n", &stackVar1);
	printf("Address is stackVar2 is 0x%x\n\n", &stackVar2);

	sprintf( szCommand, "cat /proc/%d/maps", getpid());
			
	system(szCommand);

	return 0;
}

