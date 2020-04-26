/*
 * =====================================================================================
 *
 *       Filename:  size.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/15/2020 01:05:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#define SIZE 10;
#define FUDGE SIZE -2;

int main()
{
	int size; 

	size = FUDGE;
	printf("Size is %d\n", size);
	return (0);

}
