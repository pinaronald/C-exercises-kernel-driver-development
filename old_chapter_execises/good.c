/*
 * =====================================================================================
 *
 *       Filename:  good.c
 *
 *    Description:  Bingo game, geberate a rand numebr , ask plyer to 
 *    guess it , evrytime a munber is added the bounderies are updaed.
 *
 *
 *        Version:  1.0
 *        Created:  04/12/2020 03:22:51 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

char line[100];
int number_to_guess;
int low_limit;
int high_limit;
int player_number;
int guess_count;

int main()
{
	while (1) {
	/*Generate  a random numbe*/
	number_to_guess = rand() % 100 + 1;

	/*Initialize variables for loop*/
	low_limit = 0;
	high_limit = 100;
	guess_count = 0;

	while (1) {
		printf("Bounderis are %d - %d\n", low_limit, high_limit);
		printf("Value %d ?", guess_count);
	
		++guess_count;
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &player_number);

		/*Did he guess right?*/	
		if ( player_number == number_to_guess )
			break;	

		/*adjust buonds for the next gues*/
		if (player_number < number_to_guess)
			low_limit = player_number;
		else
			high_limit = player_number;
	 }
	
	printf("Bingo\n");

	}
}
