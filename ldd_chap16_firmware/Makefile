obj-m += lab1_firmware.o

export KROOT=/lib/modules/5.3.18-lp152.63-default/build

MY_CFLAGS += -g -DDEBUG
ccflags-y += ${MY_CFLAGS}
CC += ${MY_CFLAGS}
JUNK := *.o .*.cmd *.mod.c modules.order .tmp_versions Module.symvers

allofit: modules
modules: 
	@$(MAKE) -C $(KROOT) M=$(PWD) modules

debug:     
	@$(MAKE) -C $(KROOT) M=$(PWD) modules 
	EXTRA_CFLAGS="$(MY_CFLAGS)"

modules_install: 
	@$(MAKE) -C $(KROOT) M=$(PWD) modules_install
	depmod -A -F /boot/System.map-5.3.18-lp152.63-default
kernel_clean:
	@$(MAKE) -C $(KROOT) M=$(PWD) clean

clean: kernel_clean
	rm -rf Module.symvers modules.order
	
scrub:
	rm -rf $(JUNK)
