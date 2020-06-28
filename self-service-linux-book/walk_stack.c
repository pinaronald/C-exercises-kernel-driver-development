/*
 * =====================================================================================
 *
 *       Filename:  walk_stack.c
 *
 *    Description:  Exmaple of walk stack
 *
 *        Version:  1.0
 *        Created:  05/22/2020 01:11:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>

void **getRBP(long dummy)
{
	void **rbp = (void **)&dummy + 1;
	return (rbp);
}

void print_walk_backtrace(void)
{

	long dummy;
	int frame = 0;
	Dl_info dlip;

	void **rbp = getRBP(dummy);
	void *ret = *(rbp + 1);
	void *save_rbp = *rbp;

	printf("Stack backtrace:\n");
	while(save_rbp) {
		dladdr(ret, &dlip);
		printf("	Frame %d: [rbp=0x%016lx] [ret=0x%016lx] %s\n", frame++,
				save_rbp, ret, dlip.dli_sname);
		rbp = (void**)save_rbp;
		save_rbp = *rbp;
		ret = (rbp + 1);
	}
}

int foo(void)
{
	print_walk_backtrace();
	return 0;
}

int bar(void)
{
	foo();
	return 0;
}

int boo(void)
{
	bar();
	return 0;
}

int baz(void)
{
	boo();
	return 0;
}

int main(void)
{
	baz();
	return 0;
}
