nonmatching func_800736C4, 0x40

glabel func_800736C4
    /* 63EC4 800736C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 63EC8 800736C8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 63ECC 800736CC 63C1010C */  jal        func_8007058C
    /* 63ED0 800736D0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 63ED4 800736D4 0180043C */  lui        $a0, %hi(D_80011908)
    /* 63ED8 800736D8 08198424 */  addiu      $a0, $a0, %lo(D_80011908)
    /* 63EDC 800736DC 1C3A020C */  jal        func_8008E870
    /* 63EE0 800736E0 21804000 */   addu      $s0, $v0, $zero
    /* 63EE4 800736E4 0180043C */  lui        $a0, %hi(D_80011918)
    /* 63EE8 800736E8 18198424 */  addiu      $a0, $a0, %lo(D_80011918)
    /* 63EEC 800736EC 1C3A020C */  jal        func_8008E870
    /* 63EF0 800736F0 21280002 */   addu      $a1, $s0, $zero
    /* 63EF4 800736F4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 63EF8 800736F8 1000B08F */  lw         $s0, 0x10($sp)
    /* 63EFC 800736FC 0800E003 */  jr         $ra
    /* 63F00 80073700 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800736C4
