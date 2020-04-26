#include <stdio.h>
#define MAXLINE 1000

/* prog to delete trailing blanks and tabs from each line of input and delete entirely the blank lines */

int getlinne(char line[], int maxline);
int remmove(char s[]);


main()
{
	char line[MAXLINE];


	while ( getlinne(line, MAXLINE) > 0)
		if ( remmove(line) > 0)
			printf("%s", line);
	return 0;
}

/* read a line into s[] */
int getlinne(char s[], int lim)
{
	int i, c,
	was_space = 0;
	for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if  ( c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;

}


int remmove(char s[])
{
	int i;
	i = 0;

	while ( s[i] != '\n') 	/* find new line characters */
		++i;
	--i; 					/* backoff from \n charaters */
	
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i;
	if ( i >= 0 ) {  		/* is a nonbalnk line */
		++i;
		s[i] = '\n';
		++i;
		s[i] = '\0';
	}
	return i;

}
