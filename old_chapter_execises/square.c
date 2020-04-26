/*
 * =====================================================================================
 *
 *       Filename:  square.c
 *
 *    Description:  Bitmap to draw a 10X10 bitmap squared
 *
 *        Version:  1.0
 *        Created:  04/18/2020 11:30:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

#define X_SIZE 11
#define Y_SIZE 11
char square[X_SIZE/8][Y_SIZE];

#define SET_BIT(x,y) square[x/8][y] |= (0x80 >> ((x) % 8))

int main()
{
	int y;
	int x;
	void print_array(void);
	for (y = 0; y < Y_SIZE ; ++y){
		for (x = 0; x < X_SIZE; ++x){
			if (y == 0 || y == (Y_SIZE - 1))
				SET_BIT(x, y);
			else{
			    SET_BIT(0,y) ;                                                   
				SET_BIT((X_SIZE-1),y) ;                                                   

			}

		}
	}
		

	print_array();
	return (0);
}

void print_array(void)
{
	int x;
	int y;
	unsigned int bit;

	for (y= 0; y < Y_SIZE; ++y) {
		for (x = 0 ; x < X_SIZE/8; ++x) {
			for ( bit = 0x80; bit > 0; bit = (bit >> 1) ){
				if ((square[x][y] & bit) != 0)
					printf("X");		
				else
					printf("G");
			}		
		}
	}
}
