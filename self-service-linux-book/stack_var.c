/*
 * =====================================================================================
 *
 *       Filename:  stack_var.c
 *
 *    Description:  small prog that declares local var and print the var address
 *
 *        Version:  1.0
 *        Created:  05/21/2020 12:27:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <stdio.h>
extern char **environ;

int main(int argc, char *argv[])
{
	int stackVar = 3;
	char szCommand[64];

	printf("Address of stackVar is 0x%x\n", &stackVar);
    printf("Address of argc is 0x%x\n", &argc);
    printf("Address of argv is 0x%x\n", &argv);
    printf("Address of environ is 0x%x\n", &environ);
    printf("Address of argv[0] is 0x%x\n", &argv[0]);
    printf("Address of *environ is 0x%x\n", *environ);

	/* Write the command to szCommand var */
	sprintf(szCommand, "cat /proc/%d/maps", getpid());
	/* execute a shell command, in this case the cat..*/
	system(szCommand);
	
	return 0;
}
