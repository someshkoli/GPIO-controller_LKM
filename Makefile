obj-m+=hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) -o $(pwd)/build modules

clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) -o $(pwd)/build clean