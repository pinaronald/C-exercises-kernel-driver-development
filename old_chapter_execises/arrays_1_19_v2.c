#include <stdio.h>
#define MAXLINE 1000

/* prog to reverse the input line */


int getlinne(char line[], int maxline);
void reversse(char orig[]);


main()
{
	char line[MAXLINE];

	while ( getlinne(line, MAXLINE) > 0){
		reversse(line);
		printf("%s", line);
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


void reversse(char orig[])
{
	int i, j, len;
	char tmp;
	i = j = 0;

	while ( orig[i] != '\n'){ 	/* find the line length */
		++i;
		len = i;
	}

	while ( j < i){
		tmp = orig[j];
		orig[j] = orig[i];
		orig[i] = tmp;
		--i;
		++j;
	}
	if (len > 0){
		orig[len+1] = '\n';
		orig[len+2] = '\0';
	}	
}
