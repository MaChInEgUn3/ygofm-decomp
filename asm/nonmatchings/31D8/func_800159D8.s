nonmatching func_800159D8, 0x28

glabel func_800159D8
    /* 61D8 800159D8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 61DC 800159DC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 61E0 800159E0 E055000C */  jal        func_80015780
    /* 61E4 800159E4 00000000 */   nop
    /* 61E8 800159E8 6656000C */  jal        func_80015998
    /* 61EC 800159EC 00000000 */   nop
    /* 61F0 800159F0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 61F4 800159F4 00000000 */  nop
    /* 61F8 800159F8 0800E003 */  jr         $ra
    /* 61FC 800159FC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800159D8
