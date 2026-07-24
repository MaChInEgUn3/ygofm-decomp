nonmatching func_8003BEB8, 0x48

glabel func_8003BEB8
    /* 2C6B8 8003BEB8 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2C6BC 8003BEBC 0480023C */  lui        $v0, %hi(func_8003BD14)
    /* 2C6C0 8003BEC0 14BD4224 */  addiu      $v0, $v0, %lo(func_8003BD14)
    /* 2C6C4 8003BEC4 21200000 */  addu       $a0, $zero, $zero
    /* 2C6C8 8003BEC8 21288000 */  addu       $a1, $a0, $zero
    /* 2C6CC 8003BECC 2F1F0624 */  addiu      $a2, $zero, 0x1F2F
    /* 2C6D0 8003BED0 56000724 */  addiu      $a3, $zero, 0x56
    /* 2C6D4 8003BED4 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2C6D8 8003BED8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2C6DC 8003BEDC 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2C6E0 8003BEE0 8753000C */  jal        func_80014E1C
    /* 2C6E4 8003BEE4 1800A0AF */   sw        $zero, 0x18($sp)
    /* 2C6E8 8003BEE8 F94D000C */  jal        func_800137E4
    /* 2C6EC 8003BEEC 00000000 */   nop
    /* 2C6F0 8003BEF0 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2C6F4 8003BEF4 00000000 */  nop
    /* 2C6F8 8003BEF8 0800E003 */  jr         $ra
    /* 2C6FC 8003BEFC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003BEB8
