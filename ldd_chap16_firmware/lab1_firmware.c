/*
 * Loading firmware
 *
 * Write a module that loads some firmware from filesystem. It should
 * print out the contents.
 *
 * In order to do this you'll need to place a firmware file under
 * /lib/firmware
 *
 * Since this is just a pseudo device, you will have to declare and
 * inititalize a device structure. Minimally you must set void
 * (*release) (struct device *dev) field in this structure and call
 * 
 * 	int dev_set_name(struct device *dev, const char *fmt, ...);
 * 
 * to set the device name, which can be read out with:
 * 	
 * 	const char *dev_name(const struct device *dev);
 *
 * (You may want to see what happens if you neglect setting one of these
 * quantities.)
 *
 * Make sure you call	
 * 	
 * 	device_register (struct device *dev);
 * 	device_unregister (struct device *dev);
 *
 * before requesting and after releasing the firmware.
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/firmware.h>

#define FWFILE "my_fwfile"
static const struct firmware *fw;

static void my_release(struct device *dev)
{
	pr_info("releasing firmware device\n");
}

static struct device dev = {
	.release = my_release
};

static int __init my_init(void)
{
	dev_set_name(&dev, "my0");
	device_register(&dev);
	pr_info("firmware_example: my device inserted\n");

	if (request_firmware(&fw, FWFILE, &dev)) {
		pr_err("requested firmware failed\n");
		device_unregister(&dev);
		return -1;
	}
	pr_info("firmware contents=\n%s\n", fw->data);
	return 0;
}

static void __exit my_exit(void)
{
	release_firmware(fw);
	device_unregister(&dev);
	pr_info("release firmware and unreggister device\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");

