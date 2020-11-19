/*
 * ==========================================================================
 *
 *       Filename:  lab1_module1.c
 *
 *    Description:  LAB 1: Modules and exporting symbols: Module 1
 *
 *        Version:  1.0
 *        Created:  11/18/2020 07:16:19 PM
 *	
 *	Write a pair of modules where the second one calls a function in
 *	the first one. 
 *
 *	Load them in correct order and make sure all symbols are
 *	resolved. 
 *
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * ========================================================================
 */

#include <linux/module.h>
#include <linux/init.h>

extern void mod1fun(void);

static int __init my_init(void)
{
	pr_info("Hello world from mod2 \n");
	mod1fun();
	return 0;
}

static void __exit my_exit(void)
{
	pr_info("Goodbye from mod2 \n");
}


module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: Chap9: Lab1: mod2");
MODULE_LICENSE("GPL v2");


