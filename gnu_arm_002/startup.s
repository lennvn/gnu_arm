
    .syntax unified
    .cpu cortex-m4
    .fpu softvfp
    .thumb

    .global Default_Handler
    .global g_pfnVectors
    .global .isr_vector


    .section .text.Default_Handler, "ax", %progbits
Default_Handler:
Infinite_Loop:
    nop
    b       Infinite_Loop
    .size   Default_Handler, .-Default_Handler


    .section .isr_vector, "a", %progbits
    .type g_pfnVectors, %object
    .size g_pfnVectors, .-g_pfnVectors

g_pfnVectors:
# stack top is 0x20027000
    .word   0x20027000
    .word   main
    .word   Default_Handler
    .word   Default_Handler
    