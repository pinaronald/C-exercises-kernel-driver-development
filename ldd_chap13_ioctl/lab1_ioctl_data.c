/*
 *
 *       Filename:  lab1_ioctl_data.c
 *
 *    Description:  Using ioctl's to pass data. 
 *
 *    	Write a simple module that uses the ioctl directional
 *    	information to pass a data buffer of fixed size back and fourth
 *    	beteen the driver and the user-space program. 
 *
 *    	The size and directions of data transfer should be encoded in
 *    	the command number.
 *
 *    	You'll need to write a user-space app to test this.
 *
 *        Created:  01/02/2021 02:41:56 PM
 *
 *         Author:  Ronald Pina, rpina@suse.com
 *        Company:  SUSE Software Solutions GmbH
 *
 */

#include <linux/module.h>
#include "lab_miscdev.h"

struct my_data {
	int i;
	long x;
	char s[256];
};

static struct my_data my_data = {
	.i = -100,
	.x = 100,
	.s = "original string",
};

#define MYIOC_TYPE 'k'

static long
mycdrv_unlocked_ioctl(struct file *fp, unsigned int cmd, unsigned long arg)
{
	int size, rc, direction;
	void __user *ioargp = (void __user *)arg;

	if (_IOC_TYPE(cmd) != MYIOC_TYPE) {
		pr_info(" got invalid case, CMD=%d\n", cmd);
		return -EINVAL;
	}

	direction = _IOC_DIR(cmd);
	size = _IOC_SIZE(cmd);

	switch (direction) {

	case _IOC_WRITE:
		pr_info(" reading = %d bytes from user-space and writing to device\n", size);
		rc = copy_from_user(&my_data, ioargp, size);
		pr_info("	my_data.i = %d\n	(int)my_data.x = %ld\n	my_data.s = %s\n",
						my_data.i, my_data.x, my_data.s);
		return rc;
		break;

	case _IOC_READ:
		pr_info(" reading device and writing = %d bytes to user-space\n", size);
		pr_info(" my_data.i = %d\n    (int)my_data.x = %ld\n  my_data.s = %s\n", 
						my_data.i, my_data.x, my_data.s);
		rc = copy_to_user(ioargp, &my_data, size);
		return rc;
		break;

	default:
		pr_info(" got invalid case, CMD= %d\n", cmd);
		return -EINVAL;
	}

}

static const struct file_operations mycdrv_fops = {
	.owner = THIS_MODULE, 
	.unlocked_ioctl = mycdrv_unlocked_ioctl,
	.open = mycdrv_generic_open,
	.release = mycdrv_generic_release
};

module_init(my_generic_init);
module_exit(my_generic_exit);

MODULE_AUTHOR("Ronald Pina");
MODULE_DESCRIPTION("LDD: chap13: lab1: ioctls");
MODULE_LICENSE("GPL v2");



