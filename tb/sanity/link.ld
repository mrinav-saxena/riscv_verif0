MEMORY {
  IMEM (rx)  : ORIGIN = 0x00000000, LENGTH = 4K
  DMEM (rwx) : ORIGIN = 0x10000000, LENGTH = 4K
}

SECTIONS {
  .text : {
    *(.text .text*)
    *(.rodata .rodata*)
  } > IMEM

  .data : {
    *(.data .data*)
  } > DMEM AT> IMEM

  .bss (NOLOAD) : {
    *(.bss .bss*)
    *(COMMON)
  } > DMEM

  /DISCARD/ : { *(.comment*) *(.eh_frame*) }
}


