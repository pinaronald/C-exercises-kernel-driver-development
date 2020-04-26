#include <stdio.h>


/* histogram to print the fequency of different characte */

main()
{
	int c, ndigit, i, j, nwhite, nchar ;

	int characters[24];

	for (i = 0 ; i <= 24; ++i)
		characters[i] = 0;
	
	i = j = ndigit = nwhite = nchar = 0;

	while ((c = getchar()) != EOF)
			++characters[c];
	
	printf("\n ,white spaces = %d, digits = %d, test = %d", nwhite, ndigit, characters[1]);
	for (j = 0; j <= 24; ++j){
		i = 0;
    	while ( i < characters[j] ){
			printf("=");
			++i;
		}
	  	 printf("\n");

	}
}
