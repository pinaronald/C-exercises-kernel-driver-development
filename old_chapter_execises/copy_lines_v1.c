#include <stdio.h>

#define NONBLANK 'a'

/* Copy input to output 
   replacing each string with more than two blanks
   by a single blank */
main()
{
	int c, lastc; 

	lastc = NONBLANK;	/* initialisies to a nonbalank character */
	while ((c = getchar()) != EOF ){
		if ( c != ' ' )
			putchar(c);
		else if ( c == ' ')
			if ( lastc != ' ')
				putchar(c);
		lastc = c;
	}
}
