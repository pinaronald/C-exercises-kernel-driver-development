/*
 * =====================================================================================
 *
 *       Filename:  my_module.c
 *
 *    Description:  basic moduke which takes an iteger as parameter when
 *    loaded, if there is no parameter take adefault value
 *
 *        Version:  1.0
 *        Created:  06/27/2020 08:51:18 PM
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

/* passing parameter named irq on the module */
static int irq = 8;
module_param(irq, int, S_IRUGO | S_IWUSR);

static int __init my_init(void)
{
	pr_info("R:PINA: Loading module...\n ");
	pr_info("   mod_param = %d\n", irq);
	return 0;
}

static void __exit my_exit(void)
{
	pr_info(" Goodbye Ronald, it was nice knowing you ... Tschüß\n");
}

module_init(my_init);
//module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("Lab1 on WLDD book chap_3");
MODULE_LICENSE("GPL v2");

