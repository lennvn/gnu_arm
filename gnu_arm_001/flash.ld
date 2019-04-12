
MEMORY
{
    rom1        (rx): ORIGIN = 0x00000000, LENGTH = 1024    /* 1K */
    icg         (rx): ORIGIN = 0x00000400, LENGTH = 32      /* 32Bytes */
    func        (rx): ORIGIN = 0x00000420, LENGTH = 992     /* 1K - 32Bytes */
    rom2        (rx): ORIGIN = 0x00000800, LENGTH = 510K
    ram1       (rwx): ORIGIN = 0x1FFF8000, LENGTH = 188K
    ram2       (rwx): ORIGIN = 0x200F0000, LENGTH = 4K
}

SECTIONS
{
    . = ORIGIN(rom1);
    .vectors :
    {
        KEEP(*(.vectors))
    } >rom1

    /*. = ORIGIN(icg);*/
    .icg_sec :
    {
        KEEP(*(.icg_sec))
    } >icg

    /*. = ORIGIN(func);*/
    .func_sec :
    {
        KEEP(*(.func_sec))
    } >func

    /*. = ORIGIN(rom2);*/
    .text :
    {
        *(.text)
        KEEP(*(.rodata))
    } >rom2

    _data_in_rom_start = .;

    .data : AT (_data_in_rom_start)
    {
        *(.data)
    } >ram1

    .bss :
    {
        *(.bss)
    } >ram1
}

