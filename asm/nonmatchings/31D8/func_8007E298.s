nonmatching func_8007E298, 0x50

glabel func_8007E298
    /* 6EA98 8007E298 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6EA9C 8007E29C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6EAA0 8007E2A0 0980103C */  lui        $s0, %hi(D_80093A38)
    /* 6EAA4 8007E2A4 383A1026 */  addiu      $s0, $s0, %lo(D_80093A38)
    /* 6EAA8 8007E2A8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6EAAC 8007E2AC 0000038E */  lw         $v1, 0x0($s0)
    /* 6EAB0 8007E2B0 01000224 */  addiu      $v0, $zero, 0x1
    /* 6EAB4 8007E2B4 07006214 */  bne        $v1, $v0, .L8007E2D4
    /* 6EAB8 8007E2B8 00000000 */   nop
    /* 6EABC 8007E2BC F4FF048E */  lw         $a0, -0xC($s0)
    /* 6EAC0 8007E2C0 18FA010C */  jal        func_8007E860
    /* 6EAC4 8007E2C4 00000000 */   nop
    /* 6EAC8 8007E2C8 F8FF048E */  lw         $a0, -0x8($s0)
    /* 6EACC 8007E2CC 20FA010C */  jal        func_8007E880
    /* 6EAD0 8007E2D0 00000000 */   nop
  .L8007E2D4:
    /* 6EAD4 8007E2D4 000000AE */  sw         $zero, 0x0($s0)
    /* 6EAD8 8007E2D8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6EADC 8007E2DC 1000B08F */  lw         $s0, 0x10($sp)
    /* 6EAE0 8007E2E0 0800E003 */  jr         $ra
    /* 6EAE4 8007E2E4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007E298
    /* 6EAE8 8007E2E8 00000000 */  nop
    /* 6EAEC 8007E2EC 00000000 */  nop
