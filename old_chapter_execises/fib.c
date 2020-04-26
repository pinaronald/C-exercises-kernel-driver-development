/*
 * =====================================================================================
 *
 *       Filename:  fib.c
 *
 *    Description:  fibonacci numers
 *
 *        Version:  1.0
 *        Created:  04/11/2020 11:28:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

int old_nr;
int current_nr;
int next_nr;

int main()
{

	/* Starting the count*/
	old_nr = 1;
	current_nr = 1;

	printf("1\n");

	while(current_nr < 100) {

		printf("%d\n", current_nr);
		next_nr = current_nr + old_nr;
		old_nr = current_nr;
		current_nr = next_nr;
	}
	return (0);
}
