/*
 * =====================================================================================
 *
 *       Filename:  test_module.c
 *
 *    Description:  basic modeule, print a string when loaded.
 *
 *        Version:  1.0
 *        Created:  06/27/2020 04:44:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */


#include <linux/module.h>
#include <linux/init.h>

static int __init my_init(void)
{
	printk(KERN_INFO "Hello Ronald: module loaded at 0x%p\n", my_init);
	return 0;
}

static void __exit my_exit(void)
{
	printk(KERN_INFO "Bye Ronald: module loaded from 0x%p\n", my_exit);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR ("Ronald Pina");
MODULE_LICENSE ("GPL v2");
