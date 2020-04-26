/*
 * =====================================================================================
 *
 *       Filename:  init-a.c
 *
 *    Description:  Way that an array can be passed into a subroutine
 *
 *        Version:  1.0
 *        Created:  04/25/2020 09:20:49 PM
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

/* Parameters data, the array to zero out*/

void init_array_1(int data[])
{
	int index;
	for (index=0; index < MAX; ++index)
		data[index] = 0;
}


/* Tarameters data_ptr -- Pointer to array to zero*/

void init_array_2(int *data_ptr)
{
	int i;
	for (i = 0; i < MAX; ++i )
		*(data_ptr + i) = 0;
	
}

int main()
{
	int array[MAX];

	void init_array_1();
	void init_array_2();                                                        

	/*one way of initializing the array*/
	init_array_1(array);

	/* Another way */
	init_array_1(&array[0]);

	/*Works but complier generates a warning*/
	init_array_1(&array);

	/*similar to the first method but different functio*
	* &array[0] eshte e njete me array */
	init_array_2(array);

	return (0);
}
