.section .text.startup
.globl _start
.type _start, @function

_start:
    /* Jump to main function */
    j main
    
    /* If main returns, loop forever */
1:  j 1b

