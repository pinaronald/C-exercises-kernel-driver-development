/*
 * =====================================================================================
 *
 *       Filename:  fahrenheit.c
 *
 *    Description:  Convert centigrad to fahrenheit
 *
 *        Version:  1.0
 *        Created:  04/11/2020 12:39:56 PM
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

char line[10];
float centigrad;
float fahr;


int main()
{
	printf("Enter a centigrad value: ");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%f", &centigrad);
	fahr = (9.0 * centigrad / 5.0 ) + 32.0;
	
	printf("Vlera e temperaturen ne fahrenheit eshte %f\n", fahr);
	return (0);

}



