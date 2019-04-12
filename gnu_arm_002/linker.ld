

/* Use contiguous memory regions for sample. */
MEMORY
{
    isr_rom     (rx): ORIGIN = 0x00000000, LENGTH = 1K
    icg_rom     (rx): ORIGIN = 0x00000400, LENGTH = 1K
    rom         (rx): ORIGIN = 0x00000800, LENGTH = 510K
    ram        (rwx): ORIGIN = 0x1FFF8000, LENGTH = 188K
}

SECTIONS
{
    . = ORIGIN(isr_rom);
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } >isr_rom

    .icg_sec :
    {
        . = ALIGN(4);
        KEEP(*(.icg_sec))
        . = ALIGN(4);
    } >icg_rom

    .text :
    {
        *(.text)
        KEEP(*(.rodata))
    } >rom

    _data_in_rom_start = .;

    .data : AT (_data_in_rom_start)
    {
        *(.data)
    } >ram

    .bss :
    {
        *(.bss)
    } >ram
}

