/*
 * =====================================================================================
 *
 *       Filename:  lab2_module_taints.c
 *
 *    Description:  Find Tainted Modules
 *		
 *	  Write a module that walks through module linked list and prints
 *	  out the value of taints and any other vales of interest. 
 *		
 *        Version:  1.0
 *        Created:  11/16/2020 01:21:36 AM
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 * =====================================================================================
 */

#include <linux/module.h>
#include <linux/init.h>

/**
 * struct module {
 *     enum module_state state;
 *
 * // Member of list of modules
 *    struct list_head list;
 *
 * // Unique handle for this module 
 *   char name[MODULE_NAME_LEN];
 * 
 * unsigned long taints;   
 */


static int __init my_init(void)
{
	int j = 0;
	struct list_head *modules_list;
	struct module *m = THIS_MODULE;
	modules_list = &m->list;  
	modules_list = modules_list->prev;
    pr_info("\n");
	list_for_each_entry(m, modules_list, list) {
		pr_info("%3d MOD:%20s, taints = %u\n", j++, m->name, m->taints);
	}
	return 0;
}

static void __exit my_exit(void)
{
	pr_info("Bye, module unloaded from 0x%p\n", my_exit);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: Chap7: Lab2");
MODULE_LICENSE("GPL: v2");


