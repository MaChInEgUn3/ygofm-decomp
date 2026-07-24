nonmatching func_80044278, 0x6C

glabel func_80044278
    /* 34A78 80044278 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 34A7C 8004427C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 34A80 80044280 21808000 */  addu       $s0, $a0, $zero
    /* 34A84 80044284 1800B2AF */  sw         $s2, 0x18($sp)
    /* 34A88 80044288 2190A000 */  addu       $s2, $a1, $zero
    /* 34A8C 8004428C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 34A90 80044290 2188C000 */  addu       $s1, $a2, $zero
    /* 34A94 80044294 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 34A98 80044298 2D10010C */  jal        func_800440B4
    /* 34A9C 8004429C 0B000524 */   addiu     $a1, $zero, 0xB
    /* 34AA0 800442A0 09004010 */  beqz       $v0, .L800442C8
    /* 34AA4 800442A4 0F80043C */   lui       $a0, %hi(D_800F2AE0)
    /* 34AA8 800442A8 440591A7 */  sh         $s1, %gp_rel(D_8009B44C)($gp)
    /* 34AAC 800442AC 280592AF */  sw         $s2, %gp_rel(D_8009B430)($gp)
    /* 34AB0 800442B0 520F010C */  jal        func_80043D48
    /* 34AB4 800442B4 E02A8424 */   addiu     $a0, $a0, %lo(D_800F2AE0)
    /* 34AB8 800442B8 CC2C020C */  jal        func_8008B330
    /* 34ABC 800442BC 21200002 */   addu      $a0, $s0, $zero
    /* 34AC0 800442C0 B3100108 */  j          .L800442CC
    /* 34AC4 800442C4 01000224 */   addiu     $v0, $zero, 0x1
  .L800442C8:
    /* 34AC8 800442C8 21100000 */  addu       $v0, $zero, $zero
  .L800442CC:
    /* 34ACC 800442CC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 34AD0 800442D0 1800B28F */  lw         $s2, 0x18($sp)
    /* 34AD4 800442D4 1400B18F */  lw         $s1, 0x14($sp)
    /* 34AD8 800442D8 1000B08F */  lw         $s0, 0x10($sp)
    /* 34ADC 800442DC 0800E003 */  jr         $ra
    /* 34AE0 800442E0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80044278
