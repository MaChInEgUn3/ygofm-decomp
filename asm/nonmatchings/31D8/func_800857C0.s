nonmatching func_800857C0, 0x20

glabel func_800857C0
    /* 75FC0 800857C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 75FC4 800857C4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 75FC8 800857C8 341E020C */  jal        func_800878D0
    /* 75FCC 800857CC 00000000 */   nop
    /* 75FD0 800857D0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 75FD4 800857D4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 75FD8 800857D8 0800E003 */  jr         $ra
    /* 75FDC 800857DC 00000000 */   nop
endlabel func_800857C0
