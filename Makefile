KLIB_BUILD = /lib/modules/$(shell uname -r)/build

obj-m += opp_mptcp.o
opp_mptcp-objs := init.o \
	stats.o \
	relay.o

all:
		${MAKE} -C $(KLIB_BUILD) M=$(PWD) modules

clean:
		${MAKE} -C $(KLIB_BUILD) M=$(PWD) clean
