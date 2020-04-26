/*
 * =====================================================================================
 *
 *       Filename:  full.c
 *
 *    Description:  Dispaly full name 
 *
 *        Version:  1.0
 *        Created:  04/10/2020 08:50:45 PM
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

char first[100];
char last[100];
char full_name[200];

int main()
{

	strcpy(first, "Ronald");
	strcpy(last, "Pina");
	
	strcpy(full_name, first);
	strcat(full_name, " ");
	strcat(full_name, last);

	printf("Full name is %s\n", full_name);
	return (0);
}
