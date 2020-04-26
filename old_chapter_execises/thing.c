/*
 * =====================================================================================
 *
 *       Filename:  thing.c
 *
 *    Description:  Demonstrating pointer usage
 *        Version:  1.0
 *        Created:  04/19/2020 11:32:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */
#include <stdio.h>

int main()
{
	int thing_var; /* define a variable for thing */
	int *thing_ptr; /* define a pointer to thing */
	
	thing_var = 2;
	printf("Thing %d\n", thing_var);
	
	thing_ptr = &thing_var;
	*thing_ptr = 3;

	 printf("Thing %d\n", thing_var);                                              
     printf("Thing %d\n", *thing_ptr);                                             

	return (0);

}

