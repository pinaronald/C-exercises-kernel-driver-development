/*
 * ==========================================================================
 *
 *       Filename:  lab1_interrupt.c
 *
 *    Description:  LAB 1: Shared Interrupts
 *	
 *	Write a module that shares its IRQ with your network card. 
 *	
 *	Check /proc/interrupts interrupts while it is loaded.
 *
 *	Have the module to keep track of the number of times the
 *	interrupt handler gets called. 
 *
 *        Version:  1.0
 *        Created:  11/17/2020 08:39:22 PM
 *
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * ========================================================================
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>

#define SHARED_IRQ 31

static int irq = SHARED_IRQ, drv_dev_id, irq_counter = 0;
module_param(irq, int, S_IRUGO);

static irqreturn_t drv_interrupt(int irq, void *dev_id)
{
	irq_counter++;
	pr_info("In the ISR: counter = %d\n", irq_counter++);
	return IRQ_NONE;  /* return IRQ_NONE as we are just observing */
}

static int __init my_init(void)
{
	if(request_irq(irq, drv_interrupt, IRQF_SHARED, "my_interrupt", &drv_dev_id)) {
		pr_info("Failed to reseve irq %d\n", irq);
		return -1;
	}
	pr_info("Succesfully loading ISR handler\n");
	return 0;
}

static void __exit my_exit(void)
{
	synchronize_irq(irq);
	free_irq(irq, &drv_dev_id);
	pr_info("Succesfully unloading,  irq_counter = %d\n", irq_counter);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: Chap8: interrupts");
MODULE_LICENSE("GPL v2");

