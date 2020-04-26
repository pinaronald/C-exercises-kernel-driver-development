#include <stdio.h>

#define IN 1 	/* inside word */
#define OUT 0	/* outside word */

/* Count words, lines, characters in input */
main()
{
	int c, nl, nw, nc, state;
	
	state = OUT;
	nl = nc = nw = 0;
	while ((c = getchar()) != EOF){
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if ( state == OUT) {
			state = IN;
			++nw;
		}
		
	}
	printf("%d %d %d\n", nl, nw, nc );
}



