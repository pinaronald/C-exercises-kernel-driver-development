/*
 *
 *       Filename:  lab3_mutex_unlock.c
 *
 *    Description:  Mutex Unlocking from an Interrupt
 *
 *      Modify the simple interrupt sharing lab to have a mutex taken
 *      out and then released in the interrupt handler. 
 *
 *      This is suppsed to be illegal. Is this ignored, enforced or
 *      warned against? Why?
 *    
 *
 *        Created:  01/01/2021 10:38:55 PM
 *
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>

static DEFINE_MUTEX(my_mutex);
#define SHARED_IRQ 21
static int irq = SHARED_IRQ, my_dev_id, irq_counter = 0;
module_param(irq, int, S_IRUGO);

static irqreturn_t my_interrupt(int irq, void *dev_id)
{
	irq_counter++;
	mutex_lock(&my_mutex);
	pr_info("\nInit mutex in locked state, count=%d:\n", atomic_read(&my_mutex.count));
	pr_info("In the ISR; counter=%d\n", irq_counter);
	mutex_unlock(&my_mutex);
	return IRQ_NONE; /* we return IRQ_NONE as we are just observing */
}

static int __init my_init(void)
{
	if (request_irq(irq, my_interrupt, IRQF_SHARED, "my_interrupt", &my_dev_id))
		return -1;
	pr_info("Sucessfully loading ISR handler\n");
	return 0;
}

static void __exit my_exit(void)
{
	pr_info("\n Exiting with mutex having count=%d:\n", atomic_read(&my_mutex.count));
	synchronize_irq(irq);
	free_irq(irq, &my_dev_id);
	pr_info("Sucessfully unloading, irq_counter = %d\n", irq_counter);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina, pina.ronald.al@ieee.org");
MODULE_DESCRIPTION("LDD: chap12: lab3: mutex unlock on interrup");
MODULE_LICENSE("GPL v2");


