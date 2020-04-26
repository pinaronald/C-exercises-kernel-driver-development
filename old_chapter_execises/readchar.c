#include <stdio.h>

/* Copy the input to output */

main() 
{
	int c;
	
	c = getchar();
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}
}
