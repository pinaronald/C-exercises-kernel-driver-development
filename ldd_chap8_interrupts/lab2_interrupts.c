/*
 * ==========================================================================
 *
 *       Filename:  lab2_interrupt.c
 *
 *    Description:  LAB 2: Sharing all interrupts
 *      
 *    Extend the previous solution to construct a character driver that
 *    shares every possible interrupt with already installed interrupt
 *    handlers. The character driver may be very simple, for instance if
 *    no open() and release() methods are specified, sucess is the
 *    default. 
 *    
 *    A read() on the device should return a brief report on the total
 *    number of interrupts handled for each IRQ. 
 *
 *    To do this you'll have to write a short application to retrieve and
 *    print out the data. (Don't forget to create the device node before
 *    you run the application.)
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
#include <linux/interrupt.h>
#include "lab_miscdev.h"

#define MAXIRQS nr_irqs

#define NCOPY (MAXIRQS * sizeof(int))

static int *interrupts;

static irqreturn_t my_interrupt(int irq, void *dev_id)
{
	interrupts[irq]++;
	return IRQ_NONE; /* because we are just observing */
}

static void freeup_irqs(void)
{
	int irq;
	for (irq = 0; irq < MAXIRQS; irq++) {
		if (interrupts[irq] >= 0) {  /* if grater than 0, it was able to share */
			synchronize_irq(irq);
			pr_info("Freeing IRQ= %4d, which had %10d events\n", irq, interrupts[irq]);
			free_irq(irq, interrupts);
		}

	}
}

static void get_irqs(void)
{
	int irq;
	interrupts = (int *)ramdisk;

	for (irq = 0; irq < MAXIRQS; irq++)
