
/* Use contiguous memory regions for simple. */
MEMORY
{
    isr_rom     (rx): ORIGIN = 0x00000000, LENGTH = 1K
    icg_rom     (rx): ORIGIN = 0x00000400, LENGTH = 1K
    rom         (rx): ORIGIN = 0x00000800, LENGTH = 510K
    ram        (rwx): ORIGIN = 0x1FFF8000, LENGTH = 188K
    stack_ram  (rwx): ORIGIN = 0x20027000, LENGTH = 0K
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

    . = ORIGIN(icg_rom);
    .icg_sec :
    {
        KEEP(*(.icg_sec))
    } >icg_rom

    .text :
    {
        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata.*)
    } >rom

    .data_lma_start :
    {
        . = ALIGN(4);
        _data_lma_start_ = .;
        . = ALIGN(4);
    } >rom

    .data :
    {
        . = ALIGN(4);
        _data_vma_start_ = .;
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        _data_vma_end_ = .;
    } >ram AT >rom

    .data_lma_end :
    {
        . = ALIGN(4);
        _data_lma_end_ = .;
        . = ALIGN(4);
    } >rom

    .bss :
    {
        _bss_start_ = .;
        *(.bss)
        *(COMMON)
        _bss_end_ = .;
    } >ram

    .heap :
    {
        _heap_start_ = .;
    } >ram

    .stack :
    {
        . = ALIGN(8);
        _stack_top_ = .;
        . = ALIGN(8);
    } >stack_ram
}

