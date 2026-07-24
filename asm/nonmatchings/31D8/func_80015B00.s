nonmatching func_80015B00, 0x28

glabel func_80015B00
    /* 6300 80015B00 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6304 80015B04 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6308 80015B08 4156000C */  jal        func_80015904
    /* 630C 80015B0C 00000000 */   nop
    /* 6310 80015B10 6656000C */  jal        func_80015998
    /* 6314 80015B14 00000000 */   nop
    /* 6318 80015B18 1000BF8F */  lw         $ra, 0x10($sp)
    /* 631C 80015B1C 00000000 */  nop
    /* 6320 80015B20 0800E003 */  jr         $ra
    /* 6324 80015B24 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80015B00
