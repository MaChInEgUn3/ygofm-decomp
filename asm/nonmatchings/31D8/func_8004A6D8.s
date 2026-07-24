nonmatching func_8004A6D8, 0x20

glabel func_8004A6D8
    /* 3AED8 8004A6D8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3AEDC 8004A6DC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3AEE0 8004A6E0 4629010C */  jal        func_8004A518
    /* 3AEE4 8004A6E4 00000000 */   nop
    /* 3AEE8 8004A6E8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3AEEC 8004A6EC 00000000 */  nop
    /* 3AEF0 8004A6F0 0800E003 */  jr         $ra
    /* 3AEF4 8004A6F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004A6D8
