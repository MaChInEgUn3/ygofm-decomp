nonmatching func_8007FEC8, 0x34

glabel func_8007FEC8
    /* 706C8 8007FEC8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 706CC 8007FECC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 706D0 8007FED0 21808000 */  addu       $s0, $a0, $zero
    /* 706D4 8007FED4 0980053C */  lui        $a1, %hi(D_80094678)
    /* 706D8 8007FED8 7846A524 */  addiu      $a1, $a1, %lo(D_80094678)
    /* 706DC 8007FEDC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 706E0 8007FEE0 E438020C */  jal        func_8008E390
    /* 706E4 8007FEE4 5C000624 */   addiu     $a2, $zero, 0x5C
    /* 706E8 8007FEE8 21100002 */  addu       $v0, $s0, $zero
    /* 706EC 8007FEEC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 706F0 8007FEF0 1000B08F */  lw         $s0, 0x10($sp)
    /* 706F4 8007FEF4 0800E003 */  jr         $ra
    /* 706F8 8007FEF8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007FEC8
