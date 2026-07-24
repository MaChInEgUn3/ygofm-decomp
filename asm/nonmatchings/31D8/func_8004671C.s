nonmatching func_8004671C, 0x4C

glabel func_8004671C
    /* 36F1C 8004671C C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 36F20 80046720 C3020224 */  addiu      $v0, $zero, 0x2C3
    /* 36F24 80046724 1000A2AF */  sw         $v0, 0x10($sp)
    /* 36F28 80046728 FF3F0224 */  addiu      $v0, $zero, 0x3FFF
    /* 36F2C 8004672C 1400A2A7 */  sh         $v0, 0x14($sp)
    /* 36F30 80046730 1600A2A7 */  sh         $v0, 0x16($sp)
    /* 36F34 80046734 FF7F0224 */  addiu      $v0, $zero, 0x7FFF
    /* 36F38 80046738 2000A2A7 */  sh         $v0, 0x20($sp)
    /* 36F3C 8004673C 2200A2A7 */  sh         $v0, 0x22($sp)
    /* 36F40 80046740 01000224 */  addiu      $v0, $zero, 0x1
    /* 36F44 80046744 1000A427 */  addiu      $a0, $sp, 0x10
    /* 36F48 80046748 3800BFAF */  sw         $ra, 0x38($sp)
    /* 36F4C 8004674C 2400A0AF */  sw         $zero, 0x24($sp)
    /* 36F50 80046750 1CDF010C */  jal        func_80077C70
    /* 36F54 80046754 2800A2AF */   sw        $v0, 0x28($sp)
    /* 36F58 80046758 3800BF8F */  lw         $ra, 0x38($sp)
    /* 36F5C 8004675C 00000000 */  nop
    /* 36F60 80046760 0800E003 */  jr         $ra
    /* 36F64 80046764 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8004671C
