/*
 * =====================================================================================
 *
 *       Filename:  average.c
 *
 *    Description:  Calc the average
 *
 *        Version:  1.0
 *        Created:  04/13/2020 11:11:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

char line[100];
int number[100];
int total;
int i;
int count;
float average;

int main ()
{
	
	total = 0;
	printf("Enter number count: " );
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &count);

	for (i=0; i<count; i++){
		printf("Enter number \n");
		fgets(line, sizeof(line), stdin);                                           
		sscanf(line, "%d", &number[i]);   
		total += number[i];
	}
	average = total/count;
	printf("Average is %f\n", average);
	return (0);
}
