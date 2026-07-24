nonmatching func_80015A28, 0x28

glabel func_80015A28
    /* 6228 80015A28 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 622C 80015A2C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6230 80015A30 0756000C */  jal        func_8001581C
    /* 6234 80015A34 00000000 */   nop
    /* 6238 80015A38 6656000C */  jal        func_80015998
    /* 623C 80015A3C 00000000 */   nop
    /* 6240 80015A40 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6244 80015A44 00000000 */  nop
    /* 6248 80015A48 0800E003 */  jr         $ra
    /* 624C 80015A4C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80015A28
