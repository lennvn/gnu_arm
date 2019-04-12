
#用readelf -s 或 objdump -t 查看符号表
#用readelf -S 或 objdump -h 查看段表


TARGET  = gnu_arm_demo_003

CC      = arm-none-eabi-gcc
LD      = arm-none-eabi-ld
AR      = arm-none-eabi-ar
AS      = arm-none-eabi-as
CP      = arm-none-eabi-objcopy
OD      = arm-none-eabi-objdump
RDELF   = arm-none-eabi-readelf
SIZE    = arm-none-eabi-size

CFLAGS  = -I./ -c -fno-common -O0 -g -mcpu=cortex-m4 -mthumb
AFLAGS  = -ahls -mcpu=cortex-m4 -mthumb
LFLAGS  = -Tlinker.ld -nostartfiles
LFLAGS += -Map=$(TARGET).map
CPBINFLAGS   = -O binary
CPHEXFLAGS   = -O ihex
ODFLAGS      = -D -S -r
RDSECFLAGS   = -S
RDSYBFLAGS   = -s

all: test
clean:
	-rm $(TARGET).map
	-rm $(TARGET).lst
	-rm $(TARGET).elf
	-rm $(TARGET).hex
	-rm $(TARGET).bin
	-rm *.o

test: $(TARGET).elf
	@echo "++ step 3 --> copying"
	$(CP) $(CPBINFLAGS) $(TARGET).elf $(TARGET).bin
	$(CP) $(CPHEXFLAGS) $(TARGET).elf $(TARGET).hex
	$(OD) $(ODFLAGS) $(TARGET).elf > $(TARGET).lst
	$(RDELF) $(RDSYBFLAGS) $(TARGET).elf > $(TARGET).symbol_table
	$(RDELF) $(RDSECFLAGS) $(TARGET).elf > $(TARGET).section_talbe
	$(SIZE) $(TARGET).elf

$(TARGET).elf: main.o icg.o startup.o linker.ld
	@echo "++ step 2 --> linking"
	$(LD) $(LFLAGS) -o $(TARGET).elf main.o startup.o icg.o

main.o: main.c
	@echo "++ step 1 --> compiling"
	$(CC) $(CFLAGS) -o main.o main.c

icg.o: icg.c
	@echo "++ step 1 --> compiling"
	$(CC) $(CFLAGS) -o icg.o icg.c

startup.o: startup.c
	@echo "++ step 1 --> compiling"
	$(CC) $(CFLAGS) -o startup.o startup.c

