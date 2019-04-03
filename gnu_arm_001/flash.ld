
MEMORY
{
    rom (rx)        : ORIGIN = 0x00000000, LENGTH = 512K
    icg (rx)        : ORIGIN = 0x00000400, LENGTH = 32
    func(rx)        : ORIGIN = 0x00000200, LENGTH = 2K
    ram (rwx)       : ORIGIN = 0x20000000, LENGTH = 192K
}

SECTIONS
{
    . = ORIGIN(rom);
    .text :
    {
        *(vectors)
        *(.text)
        KEEP(*(.rodata))

        /*. = ORIGIN(func);
        *(.func_sec)

        . = ORIGIN(icg);
        KEEP(*(.icg_sec))*/
    } >rom

    . = ORIGIN(func);
    .func_sec :
    {
        KEEP(*(.func_sec))
    } >func

    . = ORIGIN(icg);
    .icg_sec :
    {
        KEEP(*(.icg_sec))
    } >icg

    . = ORIGIN(ram);
    .data :
    {
        *(.data)
    } >ram AT >rom

    .bss :
    {
        *(.bss)
    } >ram AT >rom
}

