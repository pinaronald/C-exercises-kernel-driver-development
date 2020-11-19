obj-m += lab3_chardrv.o lab3_module2.o

export KROOT=/lib/modules/5.3.18-lp152.41-default/build

allofit: modules
modules: 
	@$(MAKE) -C $(KROOT) M=$(PWD) modules
modules_install: 
	@$(MAKE) -C $(KROOT) M=$(PWD) modules_install
	depmod -A -F /boot/System.map-5.3.18-lp152.41-default
kernel_clean:
	@$(MAKE) -C $(KROOT) M=$(PWD) clean

clean: kernel_clean
	rm -rf Module.symvers modules.order
	
