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

    
    