/*
 *
 *       Filename:  lab1_sem3.c
 *
 *    Description:  Semaphore Contention
 *
 *       Sencond and third module to test semaphore contention.
 *
 *        Created:  01/01/2021 09:10:03 PM
 *
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 */

#include <linux/module.h>
#include <linux/init.h>
#include <asm/atomic.h>
#include <linux/errno.h>
#include <linux/version.h>
#include <linux/semaphore.h>

static char *modname = __stringify(KBUILD_BASENAME);

extern struct semaphore my_sem;

static int __init my_init(void)
{
	pr_info("Trying to load module %s\n", modname);
	pr_info("semaphore_count=%u\n", my_sem.count);
	
#if 0
	/* this branch should hang if not available */
	if (down_trylock(&my_sem)) {
		pr_info("Not loading %s; down_trylock() failed\n", modname);
		return -EBUSY;
	}
#else
	/* this branch should return with failure if not available */
	if(down_interruptible(&my_sem)) {
		pr_info("Not loading %s, interrupted by signal\n", modname);
		return -EBUSY;
	}
#endif

	pr_info("\n Grabbed semaphore in %s, ", modname);
	pr_info("semaphore_count=%u\n", my_sem.count);
	return 0;
}

static void __exit my_exit(void)
{
	up(&my_sem);
	pr_info("\nExiting semaphore in %s, ", modname);
	pr_info("semaphore_count=%u\n", my_sem.count);
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: chap12: lab1.2 : semaphores");
MODULE_LICENSE("GPL v2");
