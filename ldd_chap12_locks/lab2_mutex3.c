/*
 *
 *       Filename:  lab2_mutex3.c
 *
 *    Description:  Mutex Contention
 *    	
 *    	Second or third modle to test the mutexes.
 *
 *        Created:  01/01/2021 09:38:56 PM
 *
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/mutex.h>
#include <asm/atomic.h>
#include <linux/errno.h>

extern struct mutex my_mutex;

static char *modname = __stringify(KBUILD_BASENAME);

static int __init my_init(void)
{
	pr_info("Trying to load module %s\n", modname);
	pr_info("\n%s start count=%d:\n", modname, atomic_read(&my_mutex.count));

#if 0
	/* this branch should hang if not available */
	if(mutex_lock_interruptible(&my_mutex)) {
		pr_info("mutex unlocked by signal in %s\n", modname);
		return -EBUSY;
	}
#else
	/* this branch will return with failure id not available */
	if(!mutex_trylock(&my_mutex)) {
		pr_info("mutex_trylock failed in %s\n", modname);
		return -EBUSY;
	}
#endif
	pr_info("\n%s mutex put mutex, count=%d:\n", modname, atomic_read(&my_mutex.count));
	return 0;
}

static void __exit my_exit(void)
{
	mutex_unlock(&my_mutex);
	pr_info("\n%s mutex end count=%d:\n", modname, atomic_read(&my_mutex.count));
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: chap12: lab2: mutex locks");
MODULE_LICENSE("GPL v2");

