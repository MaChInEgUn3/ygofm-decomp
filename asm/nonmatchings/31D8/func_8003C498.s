nonmatching func_8003C498, 0x48

glabel func_8003C498
    /* 2CC98 8003C498 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2CC9C 8003C49C 0480023C */  lui        $v0, %hi(func_8003C328)
    /* 2CCA0 8003C4A0 28C34224 */  addiu      $v0, $v0, %lo(func_8003C328)
    /* 2CCA4 8003C4A4 21200000 */  addu       $a0, $zero, $zero
    /* 2CCA8 8003C4A8 21288000 */  addu       $a1, $a0, $zero
    /* 2CCAC 8003C4AC 57210624 */  addiu      $a2, $zero, 0x2157
    /* 2CCB0 8003C4B0 32000724 */  addiu      $a3, $zero, 0x32
    /* 2CCB4 8003C4B4 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2CCB8 8003C4B8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2CCBC 8003C4BC 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2CCC0 8003C4C0 8753000C */  jal        func_80014E1C
    /* 2CCC4 8003C4C4 1800A0AF */   sw        $zero, 0x18($sp)
    /* 2CCC8 8003C4C8 F94D000C */  jal        func_800137E4
    /* 2CCCC 8003C4CC 00000000 */   nop
    /* 2CCD0 8003C4D0 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2CCD4 8003C4D4 00000000 */  nop
    /* 2CCD8 8003C4D8 0800E003 */  jr         $ra
    /* 2CCDC 8003C4DC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003C498
