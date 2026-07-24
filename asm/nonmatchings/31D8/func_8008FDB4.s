nonmatching func_8008FDB4, 0x20

glabel func_8008FDB4
    /* 805B4 8008FDB4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 805B8 8008FDB8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 805BC 8008FDBC 0840020C */  jal        func_80090020
    /* 805C0 8008FDC0 00000000 */   nop
    /* 805C4 8008FDC4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 805C8 8008FDC8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 805CC 8008FDCC 0800E003 */  jr         $ra
    /* 805D0 8008FDD0 00000000 */   nop
endlabel func_8008FDB4
