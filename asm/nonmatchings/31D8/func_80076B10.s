nonmatching func_80076B10, 0x24

glabel func_80076B10
    /* 67310 80076B10 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 67314 80076B14 1000BFAF */  sw         $ra, 0x10($sp)
    /* 67318 80076B18 CC000424 */  addiu      $a0, $zero, 0xCC
    /* 6731C 80076B1C D0DA010C */  jal        func_80076B40
    /* 67320 80076B20 CD000524 */   addiu     $a1, $zero, 0xCD
    /* 67324 80076B24 1000BF8F */  lw         $ra, 0x10($sp)
    /* 67328 80076B28 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6732C 80076B2C 0800E003 */  jr         $ra
    /* 67330 80076B30 00000000 */   nop
endlabel func_80076B10
    /* 67334 80076B34 00000000 */  nop
    /* 67338 80076B38 00000000 */  nop
    /* 6733C 80076B3C 00000000 */  nop
