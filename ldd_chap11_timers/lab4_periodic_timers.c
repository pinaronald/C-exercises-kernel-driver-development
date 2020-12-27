/*
 *
 *       Filename:  lab4_periodic_timers.c
 *
 *    Description:  Multiple Periodic Kernel timers
 *    	 
 *    	 Write a module that lauches two low resolution periodic kernel
 *    	 timers, they should reinstall themselves. 
 *
 *    	 One periodic sequence should be less than 256 ticks (so it
 *    	 should fall on tv1 vector), and the other should be less than
 *    	 16K ticks so it should fal on tv2 vector. 
 *
 *    	 Each time the timer function execute, print out the total
 *    	 elapsed time since the module was loaded.
 *		
 *        Created:  12/26/2020 07:41:24 PM
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 */

#include <linux/module.h>
#include <linux/timer.h>
#include <asm/msr.h> /* needed for Time Stamp Counter function */
#include <linux/init.h>
#include <linux/jiffies.h>
#include <linux/slab.h>

static struct timer_list timer_1, timer_2;

static struct my_timer_data {
	unsigned long timer_period;
	unsigned long timer_start_time; /* jiffies value when we frst start the timer */
} *data_1, *data_2;

static void fun_kernel_timers_a(unsigned long var)
{
	struct my_timer_data *my_dat = (struct my_timer_data *)var;

	pr_info("Timer_1: period = %ld elapsed = %ld \n", 
		my_dat->timer_period, jiffies - my_dat->timer_start_time);

	/*reset again the timer*/
	my_dat->timer_start_time = jiffies;
	mod_timer(&timer_1, my_dat->timer_period + jiffies);
}	

static void fun_kernel_timers_b(unsigned long var)
{
    struct my_timer_data *my_dat = (struct my_timer_data *)var;
 
    pr_info("    Timer_2: period = %ld elapsed = %ld \n",
        my_dat->timer_period, jiffies - my_dat->timer_start_time);

    /*reset again the timer*/
    my_dat->timer_start_time = jiffies;
    mod_timer(&timer_2, my_dat->timer_period + jiffies);
}

static int __init my_init(void)
{
	init_timer(&timer_1);
    init_timer(&timer_2);
	
	timer_1.function = fun_kernel_timers_a;
	timer_2.function = fun_kernel_timers_b;

	data_1 = kmalloc(sizeof(*data_1), GFP_KERNEL);
	data_2 = kmalloc(sizeof(*data_2), GFP_KERNEL);

	timer_1.data = (unsigned long)data_1;
	timer_2.data = (unsigned long)data_2;

	data_1->timer_period = 1 * HZ; /* short period 1 sec */
	data_2->timer_period = 10 * HZ; /* longer period, 10 seconds */

	data_1->timer_start_time = jiffies;
	data_2->timer_start_time = jiffies;

	timer_1.expires = jiffies + data_1->timer_period;
	timer_2.expires = jiffies + data_1->timer_period;

	add_timer(&timer_1);
	add_timer(&timer_2);

	return 0;	
}

static void __exit my_exit(void)
{
	/* delete any running timers */
	pr_info("Deleted timer 1: rc = %d\n", del_timer_sync(&timer_1));
	pr_info("Deleted timer 2: rc = %d\n", del_timer_sync(&timer_2));
	kfree(data_1);
	kfree(data_2);	
	pr_info("Module successfully unloaded");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: Chap11: Lab4: multitimers");
MODULE_LICENSE("GPL v2");




