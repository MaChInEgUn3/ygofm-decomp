nonmatching func_80030F80, 0x20

glabel func_80030F80
    /* 21780 80030F80 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21784 80030F84 1000BFAF */  sw         $ra, 0x10($sp)
    /* 21788 80030F88 24CF000C */  jal        func_80033C90
    /* 2178C 80030F8C 00000000 */   nop
    /* 21790 80030F90 1000BF8F */  lw         $ra, 0x10($sp)
    /* 21794 80030F94 00000000 */  nop
    /* 21798 80030F98 0800E003 */  jr         $ra
    /* 2179C 80030F9C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80030F80
