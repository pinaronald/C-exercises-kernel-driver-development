/*
 * =====================================================================================
 *
 *       Filename:  lab3_probe_module.c
 *
 *    Description:  Lab3: Probing a module
 *
 *	  Take an earlier character driver module and write a new module
 *	  that uses kprobes and jprobesto instrumantation the character
 *	  device driver. 
 *
 *	  Does the function you are probing needs to be exported to be
 *	  accessible to the prone utilities?
 
 *        Version:  1.0
 *        Created:  11/21/2020 01:17:15 PM
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <linux/module.h>
#include <linux/kprobes.h>
#include <linux/kallsyms.h>

static int drvcdr_open_probe(struct inode *inode, struct file *file)
{
	pr_info("\n\n ***JPROBE*** in drvcdr_open_debug\n\n");
	jprobe_return();
	return 0;
}

static char *name = "char_drv_open";
static struct kprobe kp;

static int handler_pre(struct kprobe *p, struct pt_regs *regs)
{
	pr_info("pre_handler: p->addr=0x%p\n", p->addr);
	return 0;
}

static void handler_post(struct kprobe *p, struct pt_regs *regs)
{
	pr_info("post_handler: p->addr=0x%p\n", p->addr);
}

static int handler_fault(struct kprobe *p, struct pt_regs *regs, int trapnr)
{
	pr_info("fault_handler: p->addr=%p\n", p->addr);
	return 0;
}

static struct jprobe jp = {
	.kp.symbol_name = "char_drv_open",
	.entry = (kprobe_opcode_t *) drvcdr_open_probe,
};

static int __init my_init(void)
{
	/* set the handler functions */
    kp.pre_handler = handler_pre;
    kp.post_handler = handler_post;
    kp.fault_handler = handler_fault;
    kp.symbol_name = name;  

	
	if (register_kprobe(&kp)) {
		pr_info("Failed to register krpobe, quiting\n");
		return -1;
	} 
	register_jprobe(&jp);
	pr_info("plant jprobe at %p, handler addr %p\n", jp.kp.addr, jp.entry);
	return 0;
}

static void __exit my_exit(void)
{
	unregister_jprobe(&jp);
	unregister_kprobe(&kp);
	pr_info("k,jprobes unregistered\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: Chap10: Lab3: Probing a module");
MODULE_LICENSE("GPL v2"); 

