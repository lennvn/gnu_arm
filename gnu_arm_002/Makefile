
CC      = arm-none-eabi-gcc
LD      = arm-none-eabi-ld
AR      = arm-none-eabi-ar
AS      = arm-none-eabi-as
CP      = arm-none-eabi-objcopy
OD      = arm-none-eabi-objdump
SIZE    = arm-none-eabi-size

CFLAGS  = -I./ -c -fno-common -O0 -g -mcpu=cortex-m4 -mthumb
AFLAGS  = -ahls -mcpu=cortex-m4 -mthumb
LFLAGS  = -Tlinker.ld -nostartfiles
LFLAGS += -Map=main.map
CPBIN   = -O binary
CPHEX   = -O ihex
ODFLAGS = -D -S -r

all: test
clean:
	-rm main.lst main.o main.elf main.bin main.map main.hex startup.lst startup.o

test: main.elf
	@echo "++ step 3 --> copying"
	$(CP) $(CPBIN) main.elf main.bin
	$(CP) $(CPHEX) main.elf main.hex
	$(OD) $(ODFLAGS) main.elf > main.lst
	$(SIZE) main.elf

main.elf: main.o startup.o linker.ld
	@echo "++ step 2 --> linking"
	$(LD) $(LFLAGS) -o main.elf main.o startup.o

main.o: main.c
	@echo "++ step 1 --> compiling"
	$(CC) $(CFLAGS) -o main.o main.c

startup.o: startup.s
	@echo "++ step 1 --> assembling"
	$(AS) $(AFLAGS) -o startup.o startup.s > startup.lst

