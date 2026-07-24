nonmatching func_8002CDE8, 0x20

glabel func_8002CDE8
    /* 1D5E8 8002CDE8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1D5EC 8002CDEC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 1D5F0 8002CDF0 63B3000C */  jal        func_8002CD8C
    /* 1D5F4 8002CDF4 00000000 */   nop
    /* 1D5F8 8002CDF8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1D5FC 8002CDFC 00000000 */  nop
    /* 1D600 8002CE00 0800E003 */  jr         $ra
    /* 1D604 8002CE04 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002CDE8
