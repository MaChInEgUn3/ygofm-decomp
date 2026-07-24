nonmatching func_8007E370, 0x20

glabel func_8007E370
    /* 6EB70 8007E370 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6EB74 8007E374 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6EB78 8007E378 D8EF010C */  jal        func_8007BF60
    /* 6EB7C 8007E37C 00000000 */   nop
    /* 6EB80 8007E380 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6EB84 8007E384 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6EB88 8007E388 0800E003 */  jr         $ra
    /* 6EB8C 8007E38C 00000000 */   nop
endlabel func_8007E370
