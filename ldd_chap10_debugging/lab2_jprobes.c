/*
 * =====================================================================================
 *
 *       Filename:  lab2_jprobes.c
 *
 *    Description:  lab2: Using jprobes
 *
 * 	  Test the jprbes functionallity by instrumenting a commonly used
 * 	  exported function. 
 *
 * 	  Keep a counter of how many times the function is called. 
 *
 *        Version:  1.0
 *        Created:  11/21/2020 03:17:22 AM
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/kallsyms.h>

static long mod_timer_count = 0;

static void mod_timer_inst(struct timer_list *timer, unsigned long expires)
{
	mod_timer_count++;
	if (mod_timer_count % 10 == 0)
		pr_info("mod_timer_count=%ld\n", mod_timer_count);
	jprobe_return();
}

static struct jprobe jp = {
	.kp.addr = (kprobe_opcode_t *) mod_timer,
	.entry = (kprobe_opcode_t *) mod_timer_inst,
};

static int __init my_init(void)
{
	register_jprobe(&jp);
	pr_info("plant jprobe at %p, handler addr %p\n", jp.kp.addr, jp.entry);
	return 0;
}

static void __exit my_exit(void)
{
	unregister_jprobe(&jp);
	pr_info("jprobe unregistered\n");
	pr_info("FINAL: mod_timer_count=%d\n", mod_timer_count);
}


module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("Lab2: Chap10: jprobes");
MODULE_LICENSE("GPL v2");
