#include <stdio.h>

#define IN 1 	/* inside the word */
#define OUT 0   /* out of the word */

/* print one word per line of the input */

main()
{
	int c, n, state, i ,j, k;
	state = OUT;

	int words[10];

	for (k = 0 ; k <= 10; ++k)
		words[k] = 0;
	
	n = j = i = 0;
	while ((c = getchar()) != EOF ){
		if (c == ' ' || c == '\t' || c == '\n')
				++n;
		else 
			++words[n];
	}
	
	printf("\n");
	for (j = 0; j <= n; ++j){
		i = 0;
    	while ( i < words[j] ){
			printf("=");
			++i;
		}
	  	 printf("\n");

	}
}
