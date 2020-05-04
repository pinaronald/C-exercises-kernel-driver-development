/*
 * =====================================================================================
 *
 *       Filename:  seven.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2020 12:38:55 AM
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
#include <stdlib.h>

char line[100]; 					/* line if input */
int seven_count; 					/* number of seven in the data */
int three_count;					/* the number of threes in the data */
int data[5];
void get_data(int data[]);

int main()
{
	seven_count = 0;
	three_count = 0;
	int index;
	
	get_data(data);

	for (index = 1; index <= 5; ++index) {
	
		if (data[index] == 3)
			++three_count;

		if (data[index] == 7)
			++seven_count;
	}

	printf("Threes %d Sevens %d\n", three_count, seven_count);
	
	return (0);
}


void get_data(int data[])
{
	printf("Enter 5 numbers: \n");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d %d %d %d %d", &data[1], &data[2], &data[3], &data[4], &data[5]);
}
