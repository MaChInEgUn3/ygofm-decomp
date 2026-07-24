nonmatching func_80015B28, 0x28

glabel func_80015B28
    /* 6328 80015B28 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 632C 80015B2C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6330 80015B30 5156000C */  jal        func_80015944
    /* 6334 80015B34 00000000 */   nop
    /* 6338 80015B38 6656000C */  jal        func_80015998
    /* 633C 80015B3C 00000000 */   nop
    /* 6340 80015B40 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6344 80015B44 00000000 */  nop
    /* 6348 80015B48 0800E003 */  jr         $ra
    /* 634C 80015B4C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80015B28
