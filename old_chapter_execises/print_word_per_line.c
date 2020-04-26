#include <stdio.h>

#define IN 1 	/* inside the word */
#define OUT 0   /* out of the word */

/* print one word per line of the input */

main()
{
	int c, i, state;
	state = OUT;

	int words[10];

	for (i = 0 ; i <= 10; ++i)
		words[i] = 0;
	
	i = 0;
	while ((c = getchar()) != EOF ){
		if (c == ' ' || c == '\t' || c == '\n'){
			if (state == IN) {
		//		putchar('\n'); 		/* finish the word */
				state = OUT;
				++i;
			}
		}			
		else if (state == OUT) { 
			state = IN; 			/* beginning of word */
			putchar(c);		
		}

		else {
		//	putchar(c);				/* inside a word */
			++words[i-'0'];
		}
	}

	for (i = 0; i < 11; ++i)
    	printf (" %d \n ", ++words[i]);

}
