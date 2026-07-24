nonmatching func_80049694, 0x30

glabel func_80049694
    /* 39E94 80049694 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 39E98 80049698 1000BFAF */  sw         $ra, 0x10($sp)
    /* 39E9C 8004969C B629010C */  jal        func_8004A6D8
    /* 39EA0 800496A0 00000000 */   nop
    /* 39EA4 800496A4 0D25010C */  jal        func_80049434
    /* 39EA8 800496A8 00000000 */   nop
    /* 39EAC 800496AC D8D6010C */  jal        func_80075B60
    /* 39EB0 800496B0 00000000 */   nop
    /* 39EB4 800496B4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 39EB8 800496B8 00000000 */  nop
    /* 39EBC 800496BC 0800E003 */  jr         $ra
    /* 39EC0 800496C0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80049694
