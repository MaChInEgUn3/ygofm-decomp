nonmatching func_80015A00, 0x28

glabel func_80015A00
    /* 6200 80015A00 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6204 80015A04 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6208 80015A08 F755000C */  jal        func_800157DC
    /* 620C 80015A0C 00000000 */   nop
    /* 6210 80015A10 6656000C */  jal        func_80015998
    /* 6214 80015A14 00000000 */   nop
    /* 6218 80015A18 1000BF8F */  lw         $ra, 0x10($sp)
    /* 621C 80015A1C 00000000 */  nop
    /* 6220 80015A20 0800E003 */  jr         $ra
    /* 6224 80015A24 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80015A00
