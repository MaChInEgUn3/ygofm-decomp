nonmatching func_8003FF34, 0x24

glabel func_8003FF34
    /* 30734 8003FF34 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 30738 8003FF38 F8FF0424 */  addiu      $a0, $zero, -0x8
    /* 3073C 8003FF3C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 30740 8003FF40 0C1D010C */  jal        func_80047430
    /* 30744 8003FF44 21280000 */   addu      $a1, $zero, $zero
    /* 30748 8003FF48 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3074C 8003FF4C 00000000 */  nop
    /* 30750 8003FF50 0800E003 */  jr         $ra
    /* 30754 8003FF54 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003FF34
