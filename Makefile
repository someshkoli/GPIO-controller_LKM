obj-m+=ebbchar.o
 
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	# $(CC) ebbchar.c -o test
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
	rm test