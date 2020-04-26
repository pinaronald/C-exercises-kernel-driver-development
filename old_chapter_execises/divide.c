/*
 * =====================================================================================
 *
 *       Filename:  divide.c
 *
 *    Description:  Macro that turns true if devidable by 10
 *
 *        Version:  1.0
 *        Created:  04/18/2020 12:05:04 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>
#define DEVIDABLE(x)  (((x) % 10) == 0)
char line[100];


int main()
{
	int number;

	while (1) {
		
	
		printf("Enter the number to check if it is devidable by 10: ");
		fgets(line, sizeof(line), stdin); 
	
		sscanf(line, "%d", &number);

		if DEVIDABLE(number)
			printf("Number %d is devidable by 10.\n", number);
		else
			printf("Number %d is not devidable by 10.\n", number);                      

		}
	return (0);
}



