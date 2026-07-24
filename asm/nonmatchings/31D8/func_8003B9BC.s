nonmatching func_8003B9BC, 0x58

glabel func_8003B9BC
    /* 2C1BC 8003B9BC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2C1C0 8003B9C0 21200000 */  addu       $a0, $zero, $zero
    /* 2C1C4 8003B9C4 0480023C */  lui        $v0, %hi(func_8003B808)
    /* 2C1C8 8003B9C8 08B84224 */  addiu      $v0, $v0, %lo(func_8003B808)
    /* 2C1CC 8003B9CC 21288000 */  addu       $a1, $a0, $zero
    /* 2C1D0 8003B9D0 881E0624 */  addiu      $a2, $zero, 0x1E88
    /* 2C1D4 8003B9D4 57000724 */  addiu      $a3, $zero, 0x57
    /* 2C1D8 8003B9D8 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2C1DC 8003B9DC 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2C1E0 8003B9E0 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2C1E4 8003B9E4 8753000C */  jal        func_80014E1C
    /* 2C1E8 8003B9E8 1800A0AF */   sw        $zero, 0x18($sp)
    /* 2C1EC 8003B9EC F94D000C */  jal        func_800137E4
    /* 2C1F0 8003B9F0 00000000 */   nop
    /* 2C1F4 8003B9F4 0180043C */  lui        $a0, %hi(D_80010000)
    /* 2C1F8 8003B9F8 0000848C */  lw         $a0, %lo(D_80010000)($a0)
    /* 2C1FC 8003B9FC 93A0050C */  jal        func_8016824C
    /* 2C200 8003BA00 00000000 */   nop
    /* 2C204 8003BA04 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2C208 8003BA08 00000000 */  nop
    /* 2C20C 8003BA0C 0800E003 */  jr         $ra
    /* 2C210 8003BA10 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003B9BC
