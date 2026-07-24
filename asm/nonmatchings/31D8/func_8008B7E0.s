nonmatching func_8008B7E0, 0x20

glabel func_8008B7E0
    /* 7BFE0 8008B7E0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7BFE4 8008B7E4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7BFE8 8008B7E8 2E2D020C */  jal        func_8008B4B8
    /* 7BFEC 8008B7EC 00000000 */   nop
    /* 7BFF0 8008B7F0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7BFF4 8008B7F4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7BFF8 8008B7F8 0800E003 */  jr         $ra
    /* 7BFFC 8008B7FC 00000000 */   nop
endlabel func_8008B7E0
