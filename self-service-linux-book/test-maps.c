/*
 * =====================================================================================
 *
 *       Filename:  test-maps.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/20/2020 12:43:12 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

int global_var = 4;
int main()
{
	printf("Address of function main is 0x%x\n", &main);
	printf("Sleeping infinitel,y pid is %d\n", getpid());
	printf("Global var address is  0x%x\n", &global_var);


	while (1)
		sleep (5);

	return (0);

}
