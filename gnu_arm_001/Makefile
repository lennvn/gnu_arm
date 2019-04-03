
CC		= arm-none-eabi-gcc
LD		= arm-none-eabi-ld -v
CP		= arm-none-eabi-objcopy
OD		= arm-none-eabi-objdump
SIZE    = arm-none-eabi-size

CFLAGS	= -I./ -c -fno-common -O0 -g -mcpu=cortex-m4 -mthumb
LFLAGS  = -Tflash.ld -nostartfiles
LFLAGS += -Map=main.map
CPBIN   = -O binary
CPHEX   = -O ihex
ODFLAGS = -D -S -r

all: test
clean:
	-rm main.lst main.o main.elf main.bin main.map main.hex

test: main.elf
	@echo "++ step 3 --> copying"
	$(CP) $(CPBIN) main.elf main.bin
	$(CP) $(CPHEX) main.elf main.hex
	$(OD) $(ODFLAGS) main.elf > main.lst
	$(SIZE) main.elf

main.elf: main.o flash.ld
	@echo "++ step 2 --> linking"
	$(LD) $(LFLAGS) -o main.elf main.o

main.o: main.c
	@echo "++ step 1 --> compiling"
	$(CC) $(CFLAGS) -o main.o main.c
