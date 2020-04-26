/*
 * =====================================================================================
 *
 *       Filename:  array2.c
 *
 *    Description:  Prograp that set each element of an array to zero 
 *
 *        Version:  1.0
 *        Created:  04/26/2020 05:28:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>
#define MAX 20


void set_zero(int *array_ptr)
{

	int i;
	for (i =0 ; i < MAX ; ++i)
		*(array_ptr + i) = 0;

}


void print_array(int *array_ptr)
{
	                                                                                   
    int i;                                                                      
	printf("\nAddress            Value\n");
    for (i =0 ; i < MAX ; ++i)                                                  
       printf("%-5p     %d\n", (array_ptr+i), *(array_ptr+i)); 
}



int main()
{
	int array[MAX];
	set_zero(array);
	print_array(array);
	return (0);

}
