/*
 * ==========================================================================
 *
 *       Filename:  lab1_interrupt.c
 *
 *    Description:  LAB 1: Modules and exporting symbols: Module 1
 *
 *        Version:  1.0
 *        Created:  11/18/2020 06:53:42 PM
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

static int __init my_init(void)
{
	pr_info("Hello world from mod1 \n");
	return 0;
}

static void __exit my_exit(void)
{
	pr_info("Goodbye from mod1 \n");
}

static void mod1fun(void)
{
	pr_info(" Cool: I just into mod1_fun, Ronald you rock \n");
}

EXPORT_SYMBOL(mod1fun);

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: Chap9: Lab1: mod1");
MODULE_LICENSE("GPL v2");


