nonmatching func_8008B800, 0x28

glabel func_8008B800
    /* 7C000 8008B800 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7C004 8008B804 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7C008 8008B808 3533020C */  jal        func_8008CCD4
    /* 7C00C 8008B80C 21200000 */   addu      $a0, $zero, $zero
    /* 7C010 8008B810 1080013C */  lui        $at, %hi(D_800FE3A0)
    /* 7C014 8008B814 A0E322AC */  sw         $v0, %lo(D_800FE3A0)($at)
    /* 7C018 8008B818 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7C01C 8008B81C 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7C020 8008B820 0800E003 */  jr         $ra
    /* 7C024 8008B824 00000000 */   nop
endlabel func_8008B800
