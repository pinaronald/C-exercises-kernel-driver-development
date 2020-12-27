/*
 *
 *       Filename:  lab5_hrtimer.c
 *
 *    Description:  High resolution timers
 *
 *   	Do the same as in the first exercise, setting up twp periodic
 *   	timers by using hrtimer interface
 *
 *        Created:  12/26/2020 08:36:29 PM
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 */

#include <linux/module.h>
#include <linux/kernel.h> /* for container_of */
#include <linux/timer.h>
#include <linux/init.h>
#include <linux/ktime.h>
#include <linux/hrtimer.h>
#include <linux/slab.h>

static struct my_data {
	ktime_t period;
	int period_in_secs;
	unsigned long start_time; /* jiffies */
	struct hrtimer timer;
	char struct_id;  /* A or B*/
} *data_array;       /* will kmalloc an array of those */

/*
 *  my_timer_func -- the timer is embedded inside an instance of "struct
 *  my data". Use container_of macro to recover a pointer to the
 *  containing structure.
 */

static enum hrtimer_restart my_timer_func(struct hrtimer *var)
{
	struct my_data *dat = container_of(var, struct my_data, timer);
	ktime_t now;

	pr_info("%c: period = %d elapsed = %ld\n",
		dat->struct_id, dat->period_in_secs, dat->start_time);

	now = var->base->get_time();
	dat->start_time = jiffies;
	hrtimer_forward(var, now, dat->period);
	return HRTIMER_RESTART;
}

static int __init my_init(void)
{
	int i;
	struct my_data *d;

	data_array = kmalloc(2 * sizeof(struct my_data), GFP_KERNEL);

	for (d = data_array, i = 0; i < 2; i++, d++ ){
		d->period_in_secs = (i == 0) ? 1 : 10;
		d->period = ktime_set(d->period_in_secs, 0);
		d->struct_id = 'A' + i;
		
		hrtimer_init(&d->timer, CLOCK_REALTIME, HRTIMER_MODE_REL);

		d->timer.function = my_timer_func;
		d->start_time = jiffies;

		hrtimer_start(&d->timer, d->period, HRTIMER_MODE_REL);
	}
	
	pr_info("Module loaded, two HRimers started\n");
	return 0;
}

static void __exit my_exit(void)
{
	int i;
	struct my_data *d = data_array;

	for (i = 0; i < 2; i++, d++) {
		pr_info("deleted timer %c: rc = %d\n", d->struct_id, hrtimer_cancel(&d->timer));
	}
	kfree(data_array);
	pr_info("Module unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: Chap11: Lab5: multiple HRTimers");
MODULE_LICENSE("GPL v2");



