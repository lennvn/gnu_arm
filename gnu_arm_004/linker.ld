
/* Use contiguous memory regions for simple. */
MEMORY
{
    isr_rom     (rx): ORIGIN = 0x00000000, LENGTH = 1K
    icg_rom     (rx): ORIGIN = 0x00000400, LENGTH = 1K
    rom         (rx): ORIGIN = 0x00000800, LENGTH = 510K
    ram        (rwx): ORIGIN = 0x1FFF8000, LENGTH = 188K
}

ENTRY(Reset_Handler)

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

    .heap (COPY) :
    {
        /*_heap_start_ = .;*/
        _end_ = .;
        PROVIDE(end = .);
        *(.heap*)
        _heap_limit_ = .;
    } >ram
/*
    .stack :
    {
        . = ALIGN(8);
        _stack_top_ = .;
        . = ALIGN(8);
    } >stack_ram
*/
    .stack_dummy (COPY) :
    {
        *(.stack*)
    } >ram

    _stack_top_ = ORIGIN(ram) + LENGTH(ram);
    _stack_limit = _stack_top_ - SIZEOF(.stack_dummy);
    PROVIDE(_stack = _stack_top_);
}

