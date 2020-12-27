/*
 * =====================================================================================
 *
 *       Filename:  lab2_multitimer.c
 *
 *    Description:  Multiple kernel times
 *    
 *    Make the period in the firs lab long enough so youcan issue
 *    multiple writes before the timer function run. 
 *
 *    How many times doe sthe function get run?
 *
 *		Fix the solution so multiple timers work properly.
 *        Version:  1.0
 *        Created:  11/12/2020 11:11:02 PM
 *
 *         Author:  Ronald Pina (), rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 * =====================================================================================
 */

#include <linux/module.h>
#include <linux/fs.h> 		/* for filesystem operations */
#include <linux/uaccess.h> 	/* copy_(to,from)_user */
#include <linux/init.h>		/* module_init, module_exit */
#include <linux/slab.h>		/* for kmalloc  */
#include <linux/cdev.h>         /* cdev utilities */
#include <linux/timer.h>
#include <linux/delay.h>

#define  MYDEV_NAME "chardrv"

static atomic_t ntimers;

struct my_dat {
	int l;
	struct timer_list *tl;
};

static dev_t first;
static unsigned int count = 1;
static int major = 511, minor = 0;
static struct cdev *drv_cdev;
static size_t ramdisk_size = (16*PAGE_SIZE);



static void my_timer_function(unsigned long ptr)
{	

	struct my_dat *tl = (struct my_dat *)ptr;
	pr_info("I am in my_timer_fun, jiffies = %ld\n", jiffies);
	pr_info("I think my curret task pid: current->pid = %d\n", (int)current->pid);
	pr_info(" my data is: %d\n", tl->l);
	kfree(tl->tl);
	kfree(tl);
	atomic_dec(&ntimers);
	pr_info("ntimers deced to %d\n", atomic_read(&ntimers));
}




static int char_drv_open(struct inode *inode, struct file *file)
{
	
	static int counter = 0;
	char *ramdisk = kmalloc(ramdisk_size, GFP_KERNEL);
	file->private_data = ramdisk;
	pr_info("OPENING device: %s\n\n", MYDEV_NAME);
	pr_info("DEVICE %s   Major:Minor %d:%d  \n", MYDEV_NAME, major, minor);
	counter ++;
	pr_info("DEVICE %s has been opened %d times since loaded.\n", MYDEV_NAME, counter);
	return 0;

}

static int char_drv_release(struct inode *inode, struct file *file)
{
	char *ramdisk = file->private_data;
	pr_info("CLOSING DEVICE %s\n", MYDEV_NAME);
	kfree(ramdisk);
    	return 0;
	        /* turn this on to inhibit seeking */
        /* file->f_mode = file->f_mode & ~FMODE_LSEEK; */

}


static ssize_t 
char_drv_read(struct file *file, char __user * buf, size_t lbuf, loff_t * ppos)
{
	char *ramdisk=file->private_data;
	int nbytes, maxbytes, bytes_to_do;
	maxbytes = ramdisk_size - *ppos;
	bytes_to_do = maxbytes > lbuf ? lbuf : maxbytes;
	if (bytes_to_do == 0)
                pr_info("Reached end of the device on a read");
        nbytes = bytes_to_do - copy_to_user(buf, ramdisk + *ppos, bytes_to_do);
	*ppos += nbytes;
	pr_info("\n Leaving the READ function, nbytes=%d, pos=%d\n", nbytes, (int)*ppos);
    	return nbytes;
}

static ssize_t
char_drv_write( struct file *file, const char __user * buf, size_t lbuf,
			loff_t * ppos)
{
	struct timer_list *tl;
	struct my_dat *mdata;
	static int len = 100;
	atomic_inc(&ntimers);
	pr_info("ntimers upped to %d\n", atomic_read(&ntimers));
	tl = (struct timer_list *)kmalloc(sizeof(struct timer_list), GFP_KERNEL);
	pr_info(" Entring the write function\n");
	pr_info(" my current task pid is %d\n", (int)current->pid);
	init_timer(tl); /* initialize timer */
	tl->function = my_timer_function;
	tl->expires = jiffies + 4 * HZ; /* four second delay */
	mdata = (struct my_dat *)kmalloc(sizeof(struct my_dat), GFP_KERNEL);
	tl->data = (unsigned long)mdata;
    pr_info("Adding timmer at jiffies = %ld\n", jiffies);
	add_timer(tl);
	len += 100;

	char *ramdisk=file->private_data;
	int nbytes, maxbytes, bytes_to_do;
	maxbytes = ramdisk_size - *ppos;
        bytes_to_do = maxbytes > lbuf ? lbuf : maxbytes;
        if (bytes_to_do == 0)
                pr_info("Reached end of the device on a write");
        nbytes = bytes_to_do - copy_from_user(ramdisk + *ppos, buf, bytes_to_do);
	*ppos += nbytes;
	pr_info("\n Leaving the WRITE function, nbytes=%d, pos=%d\n", nbytes, (int)*ppos);
	return nbytes;
}

static loff_t char_drv_lseek(struct file *file, loff_t offset, int flag)
{
	loff_t testpos;
	switch(flag) {
	case SEEK_SET:
		testpos = offset;
		break;
	case SEEK_CUR:
		testpos = file->f_pos + offset;
                break;
	case SEEK_END:
		testpos = ramdisk_size + offset;
		break;
	default:
		return -EINVAL;
	}
	testpos = testpos < ramdisk_size ? testpos : ramdisk_size;
	testpos = testpos >= 0 ? testpos : 0;
	file->f_pos = testpos;
	pr_info("Seeking to pos=%ld\n", (long)testpos);
	return testpos; 

}


static const struct file_operations char_drv_fops = {
	.owner = THIS_MODULE,
	.read = char_drv_read,
	.write = char_drv_write,
	.open = char_drv_open,
	.release = char_drv_release,
	.llseek = char_drv_lseek
};

static int __init char_drv_init(void)
{
	atomic_set(&ntimers, 0);

	first = MKDEV(major, minor);
	if (register_chrdev_region(first, count, MYDEV_NAME) < 0) {
		pr_err("failed to register character device region\n");
		return -1;
	}
	if (!(drv_cdev = cdev_alloc())) { 
		pr_err("cdev_alloc() failed\n");
		unregister_chrdev_region(first, count);
		return -1;
	}
	cdev_init(drv_cdev, &char_drv_fops);
	if (cdev_add(drv_cdev, first, count) < 0) {
		pr_err("cdev_add() failed");
		cdev_del(drv_cdev);
		unregister_chrdev_region(first, count);
		return -1;
	}	
	pr_info("Sucessfully registering the char device %s\n", MYDEV_NAME);
	return 0;	
}

static void __exit char_drv_exit(void)
{
	/* waiting forall timers to finish */
	pr_info("ntimers in remove routine to %d\n", atomic_read(&ntimers));
	while(atomic_read(&ntimers)) {
		pr_info("sleeping, nimers still %d\n", atomic_read(&ntimers));
		msleep(1000); /* wait a second */
	}

	cdev_del(drv_cdev);
	unregister_chrdev_region(first, count);
	pr_info("\nDEVICE unregistered\n");
}

module_init(char_drv_init);
module_exit(char_drv_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: Chap11: Lab2: multitimers");
MODULE_LICENSE("GPL v2");
