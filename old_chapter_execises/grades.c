/*
 * =====================================================================================
 *
 *       Filename:  grades.c
 *
 *    Description:  Calulate grades
 *
 *        Version:  1.0
 *        Created:  04/12/2020 01:53:24 AM
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
int score;
char grade;

int main()
{
	score = 0;
	grade = 'Z';

	printf("Enter the number of scores:");
	fgets(line, sizeof(line), stdin);
	sscanf(line, "%d", &score);

	if (score <= 60)
		grade = 'F';
		
	else if (score > 60 && score <= 70)
		grade = 'D';

	else if (score > 81 && score <= 90)
		grade = 'B';

	else if (score > 91 && score <= 100)
		grade = 'A';

	else grade = 'W';


	printf ("your grade is %c", grade);
	return (0) ;
}

