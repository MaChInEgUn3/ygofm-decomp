nonmatching func_8003C2B4, 0x74

glabel func_8003C2B4
    /* 2CAB4 8003C2B4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2CAB8 8003C2B8 21200000 */  addu       $a0, $zero, $zero
    /* 2CABC 8003C2BC 21288000 */  addu       $a1, $a0, $zero
    /* 2CAC0 8003C2C0 15210624 */  addiu      $a2, $zero, 0x2115
    /* 2CAC4 8003C2C4 32000724 */  addiu      $a3, $zero, 0x32
    /* 2CAC8 8003C2C8 0480023C */  lui        $v0, %hi(func_8003C120)
    /* 2CACC 8003C2CC 20C14224 */  addiu      $v0, $v0, %lo(func_8003C120)
    /* 2CAD0 8003C2D0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2CAD4 8003C2D4 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2CAD8 8003C2D8 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2CADC 8003C2DC 8753000C */  jal        func_80014E1C
    /* 2CAE0 8003C2E0 1800A0AF */   sw        $zero, 0x18($sp)
    /* 2CAE4 8003C2E4 F94D000C */  jal        func_800137E4
    /* 2CAE8 8003C2E8 00000000 */   nop
    /* 2CAEC 8003C2EC 21200000 */  addu       $a0, $zero, $zero
    /* 2CAF0 8003C2F0 21288000 */  addu       $a1, $a0, $zero
    /* 2CAF4 8003C2F4 47210624 */  addiu      $a2, $zero, 0x2147
    /* 2CAF8 8003C2F8 10000724 */  addiu      $a3, $zero, 0x10
    /* 2CAFC 8003C2FC 1480023C */  lui        $v0, (0x80140000 >> 16)
    /* 2CB00 8003C300 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2CB04 8003C304 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2CB08 8003C308 8753000C */  jal        func_80014E1C
    /* 2CB0C 8003C30C 1800A2AF */   sw        $v0, 0x18($sp)
    /* 2CB10 8003C310 F94D000C */  jal        func_800137E4
    /* 2CB14 8003C314 00000000 */   nop
    /* 2CB18 8003C318 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2CB1C 8003C31C 00000000 */  nop
    /* 2CB20 8003C320 0800E003 */  jr         $ra
    /* 2CB24 8003C324 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003C2B4
