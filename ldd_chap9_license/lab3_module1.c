/*
 * ==========================================================================
 *
 *       Filename:  lab3_module1.c
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
 *        Created:  11/18/2020 08:35:26 PM
 *	
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * ========================================================================
 */
#include <linux/module.h>
#include "lab_miscdev.h"

/* a small function to be referenced  to the second module */
static void mod_fun(void)
{
	pr_info(" Cool: I just got into mod_fun, Ronald you beast \n");
}

EXPORT_SYMBOL(mod_fun);

/* dyn load of sencond module "lab1_module2", via request_module() */
static int drvcdrv_open(struct inode *inode, struct file *file)
{
	pr_info("/n rc from requesting module mod_fun is %d\n", 
		request_module("%s", "lab3_module2"));
	return mycdrv_generic_open(inode, file);
}

static const struct file_operations drvcdrv_fops = {
	.owner = THIS_MODULE,
	.read = mycdrv_generic_read, 
	.write = mycdrv_generic_write,
	.open = drvcdrv_open,
	.release = mycdrv_generic_release,
};


module_init(my_generic_init);
module_exit(my_generic_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: Chap9: Lab3: mod1");
MODULE_LICENSE("GPL v2");


