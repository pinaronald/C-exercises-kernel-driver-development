#include <stdio.h>

/* replace tabs and backspaces */

main ()
{
	int c;

	while ((c = getchar()) != EOF){
		if (c == '\t')
			printf("\\t" );
		else if (c == '\b')
			printf("\\b");
		else if (c == '\\')
			printf("\\\\");
		else	
			putchar(c);
		}
}
