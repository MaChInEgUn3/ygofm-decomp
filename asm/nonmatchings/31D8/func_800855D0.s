nonmatching func_800855D0, 0x2C

glabel func_800855D0
    /* 75DD0 800855D0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 75DD4 800855D4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 75DD8 800855D8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 75DDC 800855DC EC1D020C */  jal        func_800877B0
    /* 75DE0 800855E0 21808000 */   addu      $s0, $a0, $zero
    /* 75DE4 800855E4 101E020C */  jal        func_80087840
    /* 75DE8 800855E8 21200002 */   addu      $a0, $s0, $zero
    /* 75DEC 800855EC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 75DF0 800855F0 1000B08F */  lw         $s0, 0x10($sp)
    /* 75DF4 800855F4 0800E003 */  jr         $ra
    /* 75DF8 800855F8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800855D0
    /* 75DFC 800855FC 00000000 */  nop
