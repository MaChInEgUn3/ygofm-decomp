nonmatching func_800403F0, 0x20

glabel func_800403F0
    /* 30BF0 800403F0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 30BF4 800403F4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 30BF8 800403F8 E400010C */  jal        func_80040390
    /* 30BFC 800403FC 00000000 */   nop
    /* 30C00 80040400 1000BF8F */  lw         $ra, 0x10($sp)
    /* 30C04 80040404 00000000 */  nop
    /* 30C08 80040408 0800E003 */  jr         $ra
    /* 30C0C 8004040C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800403F0
