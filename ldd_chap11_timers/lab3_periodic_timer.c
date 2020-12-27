/*
 * =====================================================================================
 *
 *       Filename:  lab3_periodic_timer.c
 *
 *    Description:  Write a module that launches a periodic kernel timer
 *    function, i.e it should reinstall itself.
 *
 *        Version:  1.0
 *        Created:  12/26/2020 06:15:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <linux/module.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
#include <linux/init.h>

static struct timer_list timer;
static struct kt_data {
	unsigned long period;
	unsigned long start_time; /* jiffies value when we start the timer */
	unsigned long timer_start;  /* jiffies when timr was queued */
	unsigned long timer_end; /* jiffies when timer is executed */
} data;


static void ktfun(unsigned long var)
{
	struct kt_data *tdata = (struct kt_data *)var;
	
	pr_info("ktime: period = %ld elapsed = %ld\n", tdata->period, jiffies - tdata->start_time);
	/* resubmit */
	mod_timer(&timer, tdata->period + jiffies);
}

static int __init my_init(void)
{
	data.period = 2 * HZ; /* short period, 2 secs */
	
	init_timer(&timer);
	timer.function = ktfun;
	timer.data = (unsigned long)&data;
	timer.expires = jiffies +  data.period;
	data.start_time = jiffies;
	add_timer(&timer);
	
	return 0;
}	


static void __exit my_exit(void)
{
	/* delete any running timers */
	pr_info("Deleted timer rc= %d\n", del_timer_sync(&timer));
	pr_info("Module succesfully unloaded \n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: chap 11: lab3_periodic_timer.c");
MODULE_LICENSE("GPL v2");

