/*
 * ==========================================================================
 *
 *       Filename:  lab3_module2.c
 *
 *    Description:  LAB 3: Dynamic module loading
 *	
 *	Take the previous exercise driver and adapt it to use dynamic
 *	loading:
 *
 *	Construct a trivial second module and have it dynamically loaded
 *	during character driver's entry point. 
 *
 *	Add a small function to your character driver and have it
 *	referenced by the second module. 
 *
 *	Make sure you place modules in a place modprobe can find them,
 *	installing with modules_install and running "depmod -ae"
 * 	
 *	You can use either cat or the main program from the character
 *	driver lab to exercise your module . What happens when you
 *	request to load more than one.
 *
 *        Version:  1.0
 *        Created:  11/18/2020 08:56:19 PM
 *	
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * ========================================================================
 */

#include <linux/module.h>
#include <linux/init.h>

extern void mod_fun1(void);

static int __init my_init(void)
{
	pr_info("Hello from my mod \n");
	mod_fun1();
	return 0;
}

static void __exit my_exit(void)
{
	pr_info("Goodbye world from mymod\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: Chap9: Lab3: mod2");
MODULE_LICENSE("GPL v2");


