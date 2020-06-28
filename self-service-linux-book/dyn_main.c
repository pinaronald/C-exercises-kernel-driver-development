#include <stdio.h>
#include <dlfcn.h>

int main(void)
{
	void *dlhandle = NULL;
	void (*func1_ref) (void);

	printf("Dynamically opening libdyn.so ...\n");

	dlhandle = dlopen("./libdyn.so", RTLD_NOW);

	func1_ref = dlsym(dlhandle, "func1");
	func1_ref();

	exit:
	
	return 0;

}



