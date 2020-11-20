/*
 * ==========================================================================
 *
 *       Filename:  lab1_interrupt.c
 *
 *    Description:  LAB 1: Using kprobes
 *
 *    Place a kprobe at an ofen executed place in the kernel, a good
 *    choice would be the do_fork() function, which is executed whenever
 *    a child is born. 
 *
 *    Put in simple handler function. 
 *
 *    Test the module by loading it and executing simple comands which
 *    cause the probed instruction to execute, such as starting a new
 *    shell with bash.
 *
 *        Version:  1.0
 *        Created:  11/18/2020 17:52:54 PM
 *
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * ========================================================================
 */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kprobes.h>
#include <linux/kallsyms.h>

#define PRCUR(t) pr_info("current->comm=%s, current->pid=%d\n", t->comm, t->pid);

static char *name = "vfs_read";
module_param(name, charp, S_IRUGO);

static struct kprobe kp;

static int handler_pre(struct kprobe *p, struct pt_regs *regs)
{
	pr_info("pre_handler: p->addr=0x%p\n", p->addr);
	PRCUR(current);
	return 0;
}

static void handler_post(struct kprobe *p, struct pt_regs *regs, unsigned long flags)
{
	pr_info("post_handler: p->addr=0x%p\n", p->addr);
        PRCUR(current);
}

static int handler_fault(struct kprobe *p, struct pt_regs *regs, int trapnr)
{
	pr_info("fault_handler:p->addr=0x%p\n", p->addr);
	PRCUR(current);
	return 0;
}

static int __init my_init(void)
{
	/* set the handler functions */
	
	kp.pre_handler = handler_pre;
	kp.post_handler = handler_post;
	kp.fault_handler = handler_fault;
	kp.symbol_name = name;  /* symbol name of the probe */

	if (register_kprobe(&kp)) {
		pr_info("Failed to register kprobe, quitting\n");
		return -1;
	}
	pr_info("Hello: module loaded at 0x%p\n", my_init);
	return 0;
}

static void __exit my_exit(void)
{
	unregister_kprobe(&kp);
	pr_info("Bye: module unloaded from 0x%p\n", my_exit);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LAB1: Chap10: kprobes");
MODULE_LICENSE("GPL v2");
