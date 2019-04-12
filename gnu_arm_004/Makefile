
#用readelf -s 或 objdump -t 查看符号表
#用readelf -S 或 objdump -h 查看段表


TARGET  = gnu_arm_demo_004
HEXDIR  = /run/user/1000/gvfs/smb-share:server=192.168.32.51,share=vmshare

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

dbg:
	-openocd -f interface/jlink.cfg -c "transport select swd" -f target/stm32f4x.cfg
#	-openocd -f interface/jlink.cfg -f target/hc32f46x.cfg

clean:
	-rm $(TARGET).map
	-rm $(TARGET).lst
	-rm $(TARGET).elf
	-rm $(TARGET).hex
	-rm $(TARGET).bin
	-rm *.o
	-rm $(HEXDIR)/*.hex

test: $(TARGET).elf
	@echo "++ step 3 --> copying"
	$(CP) $(CPBINFLAGS) $(TARGET).elf $(TARGET).bin
	$(CP) $(CPHEXFLAGS) $(TARGET).elf $(TARGET).hex
	$(OD) $(ODFLAGS) $(TARGET).elf > $(TARGET).lst
	$(RDELF) $(RDSYBFLAGS) $(TARGET).elf > $(TARGET).symbol_table
	$(RDELF) $(RDSECFLAGS) $(TARGET).elf > $(TARGET).section_talbe
	$(SIZE) $(TARGET).elf
	-cp $(TARGET).hex $(HEXDIR)

$(TARGET).elf: main.o led.o icg.o startup.o linker.ld
	@echo "++ step 2 --> linking"
	$(LD) $(LFLAGS) -o $(TARGET).elf main.o led.o icg.o startup.o

main.o: main.c
	@echo "++ step 1 --> compiling"
	$(CC) $(CFLAGS) -o main.o main.c

led.o: led.c
	@echo "++ step 1 --> compiling, led"
	$(CC) $(CFLAGS) -o led.o led.c

icg.o: icg.c
	@echo "++ step 1 --> compiling"
	$(CC) $(CFLAGS) -o icg.o icg.c

startup.o: startup.c
	@echo "++ step 1 --> compiling"
	$(CC) $(CFLAGS) -o startup.o startup.c

