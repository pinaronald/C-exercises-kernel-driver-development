#include <stdio.h>

void func2(void)
{
	printf("This function is not referenced in dyn_main.c\n");
	return;
}

void func1(void)
{
	printf("This func is in libdyn.so\n");
	func2();
	
	return;
}




