nonmatching func_8003FFB4, 0x24

glabel func_8003FFB4
    /* 307B4 8003FFB4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 307B8 8003FFB8 FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 307BC 8003FFBC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 307C0 8003FFC0 CD14010C */  jal        func_80045334
    /* 307C4 8003FFC4 00808434 */   ori       $a0, $a0, 0x8000
    /* 307C8 8003FFC8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 307CC 8003FFCC 00000000 */  nop
    /* 307D0 8003FFD0 0800E003 */  jr         $ra
    /* 307D4 8003FFD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003FFB4
