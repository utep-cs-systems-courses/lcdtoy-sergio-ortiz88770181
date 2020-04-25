/COMMON_OBJECTS =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS         = -L/opt/ti/msp430_gcc/include

CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: blinky_buzzy.elf

blinky_buzzy.elf: ${COMMON_OBJECTS} blinky_buzzy.o led.o switches.o buzzer.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: blinky_buzzy.elf
	msp430loader.sh blinky_buzzy.elf

clean:
	rm -f *.o *.elf *~ *#

blinky_buzzy.c: switches.h led.h buzzer.h
led.c: led.h
switches.c: switches.h led.h
buzzer.c: buzzer.h
