/*
 * Dynamical Node Creation (II)
 *
 * Adapt the previous dynamic registration driver to use udev to
 * create the device node on the fly.
 *
 * A second solution is given which includes a header file
 * (lab_header.h) which will be used to simplify the coding in
 * subsequent character drivers we will write.
 *
 @*/

#include <linux/module.h>
#include <lab_char.h>

static const struct file_operations chardrv_fops {
	.owner = THIS_MODULE,
	.read = chardrv_generic_read,
	.write = chardrv_generic_write,
	.open = chardrv_generic_open,
	.release = chardrv_generic_release,
	.llseek = chardrv_generic_lseek,
};


