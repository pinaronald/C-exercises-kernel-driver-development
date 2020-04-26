/*
 * =====================================================================================
 *
 *       Filename:  double.c
 *
 *    Description:  Double a number get from fgets and firmat to int using 
 *    sscanf. 
 *
 *        Version:  1.0
 *        Created:  04/10/2020 10:31:17 PM
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

char line[100];
int value;

int main()
{

	printf("Enter a number to double: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &value );

	printf("Twice %d is %d. \n", value, value * 2);
	return (0);

}

