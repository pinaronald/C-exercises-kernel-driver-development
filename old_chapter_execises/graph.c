/*
 * =====================================================================================
 *
 *       Filename:  graph.c
 *
 *    Description:  Draw a diagonal line across the graphics array and 
 *    prints the array on terminal. 
 *
 *        Version:  1.0
 *        Created:  04/18/2020 07:59:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>

#define X_SIZE 40 /* X array size */
#define Y_SIZE 60 /* Y array size */                                              

/* We use X_SIZE/8 because we pack 8 bits per byte*/
char graphics[X_SIZE/8][Y_SIZE]; /* the prphics data*/

#define SET_BIT(x,y) graphics[(x)/8][y] |= (0x80 >> ((x) % 8))

int main()
{
	int loc; /* current location we are setting */
	void print_graphics(void);  /* Print data  function initialization */

	/* set the diagonal pixels, set_bit will fill the graphics array with 
	* the byte values 
	* */
	for (loc=0; loc < X_SIZE; ++loc)
		SET_BIT(loc, loc);

	/* print the data seted on graphics array */
	print_graphics();
	return (0);

}

/*  Function print_graphics prints the graphics bit arry */

void print_graphics(void)
{
	int x; /* current x byte location */
	int y; /* current y locatio */
	unsigned int bit ; /* Bit we are testing in current byte */

	/* loop for each row */
	for (y = 0; y < Y_SIZE; ++y ){
	
		/* loop for each byte in the array */
		for (x = 0; x < X_SIZE/8 ; ++x){
			
			/* Handle each bit by shifting it i the right by 1 and testing it value*/
			for (bit = 0x80; bit > 0; bit = (bit >> 1)){
				if  ((graphics[x][y] & bit) != 0)
					printf("X");
				else
					printf(".");
			}
		}
	}
}


