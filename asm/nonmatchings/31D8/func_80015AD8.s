nonmatching func_80015AD8, 0x28

glabel func_80015AD8
    /* 62D8 80015AD8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 62DC 80015ADC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 62E0 80015AE0 2E56000C */  jal        func_800158B8
    /* 62E4 80015AE4 00000000 */   nop
    /* 62E8 80015AE8 6656000C */  jal        func_80015998
    /* 62EC 80015AEC 00000000 */   nop
    /* 62F0 80015AF0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 62F4 80015AF4 00000000 */  nop
    /* 62F8 80015AF8 0800E003 */  jr         $ra
    /* 62FC 80015AFC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80015AD8
