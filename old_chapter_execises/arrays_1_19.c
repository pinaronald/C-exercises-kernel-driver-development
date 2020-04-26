#include <stdio.h>
#define MAXLINE 1000

/* prog to reverse the input line */


int getlinne(char line[], int maxline);
void reversse(char orig[], char rev[]);


main()
{
	char line[MAXLINE];
	char rev[MAXLINE];

	while ( getlinne(line, MAXLINE) > 0){
		reversse(line,rev);
		printf("%s", rev);
	}
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


void reversse(char orig[], char rev[])
{
	int i, j;
	i = j = 0;

	while ( orig[i] != '\n') 	/* find the line length */
		++i;
	for (j = 0; j <= i; ++j)
		rev[j] = orig[i-j];
	rev[i+1] = '\n';
	rev[i+2] = '\0';  
}
