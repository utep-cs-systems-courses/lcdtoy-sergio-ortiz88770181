/COMMON_OBJECTS =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS         = -L/opt/ti/msp430_gcc/include

CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

OBJECTS         = ../shapeLib/shape.o ../shapeLib/region.o ../shapeLib/rect.o ../shapeLib/vec2.o ../shapeLib/layer.o ../shapeLib/rarrow.o

all: blinky_buzzy.elf libShape.a 

libShape.a: $(OBJECTS)
	$(AR) crs $@ $^

$(OBJECTS): ../shapeLib/shape.h

install: libShape.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

blinky_buzzy.elf: ${COMMON_OBJECTS} blinky_buzzy.o led.o switches.o buzzer.o screen.o libShape.a ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} $^ -L../lib -lTimer -lLcd -o $@

load: blinky_buzzy.elf
	msp430loader.sh blinky_buzzy.elf

clean:
	rm -f *.o *.elf *~ *#

blinky_buzzy.c: switches.h led.h buzzer.h 
led.c: led.h
switches.c: switches.h led.h screen.h
buzzer.c: buzzer.h
