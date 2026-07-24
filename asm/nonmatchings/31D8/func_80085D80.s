nonmatching func_80085D80, 0x24

glabel func_80085D80
    /* 76580 80085D80 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 76584 80085D84 1000BFAF */  sw         $ra, 0x10($sp)
    /* 76588 80085D88 1000848C */  lw         $a0, 0x10($a0)
    /* 7658C 80085D8C 30FF010C */  jal        func_8007FCC0
    /* 76590 80085D90 00000000 */   nop
    /* 76594 80085D94 1000BF8F */  lw         $ra, 0x10($sp)
    /* 76598 80085D98 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7659C 80085D9C 0800E003 */  jr         $ra
    /* 765A0 80085DA0 00000000 */   nop
endlabel func_80085D80
    /* 765A4 80085DA4 00000000 */  nop
    /* 765A8 80085DA8 00000000 */  nop
    /* 765AC 80085DAC 00000000 */  nop
