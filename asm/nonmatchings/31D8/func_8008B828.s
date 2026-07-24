nonmatching func_8008B828, 0x28

glabel func_8008B828
    /* 7C028 8008B828 1080043C */  lui        $a0, %hi(D_800FE3A0)
    /* 7C02C 8008B82C A0E3848C */  lw         $a0, %lo(D_800FE3A0)($a0)
    /* 7C030 8008B830 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7C034 8008B834 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7C038 8008B838 3533020C */  jal        func_8008CCD4
    /* 7C03C 8008B83C 00000000 */   nop
    /* 7C040 8008B840 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7C044 8008B844 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7C048 8008B848 0800E003 */  jr         $ra
    /* 7C04C 8008B84C 00000000 */   nop
endlabel func_8008B828
