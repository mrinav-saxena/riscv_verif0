MEMORY {
  IMEM (rx)  : ORIGIN = 0x00000000, LENGTH = 4K
  DMEM (rwx) : ORIGIN = 0x10000000, LENGTH = 4K
}

ENTRY(_start)

SECTIONS {
  . = 0x00000000;        /* reset vector address */
  
  /* Startup section that jumps to main */
  .text.startup : {
    *(.text.startup)
  } > IMEM
  
  .text : {
    *(.text .text*)
    *(.rodata .rodata*)
  } > IMEM

  .data : {
    *(.data .data* .*data)
  } > DMEM AT> IMEM

  .bss (NOLOAD) : {
    *(.bss .bss*)
    *(COMMON)
  } > DMEM

  /DISCARD/ : { *(.comment*) *(.eh_frame*) }
}


