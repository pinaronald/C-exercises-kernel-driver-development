#include <stdio.h>

void function3 (int *passedByReference)
{
	int dummy = '\0';

	printf("My pid is %d; Press <ENTER> to continue", getpid());
	dummy = fgetc(stdin);
	*passedByReference = 9;
}

void function2(char *paramString)
{
	int localInt = 1;

	function3(&localInt);
	printf("Value of localInt = %d\n", localInt);
}

void function1(int parmInt)
{
	char localString[] = "This is a string.";
	
	function2(localString);
}

int main(void)
{
	int stackVar = 3;
	function1(stackVar);
	
	return 0;
}

