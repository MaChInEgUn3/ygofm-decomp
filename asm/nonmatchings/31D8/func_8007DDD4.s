nonmatching func_8007DDD4, 0x64

glabel func_8007DDD4
    /* 6E5D4 8007DDD4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6E5D8 8007DDD8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6E5DC 8007DDDC 0980103C */  lui        $s0, %hi(D_80093A38)
    /* 6E5E0 8007DDE0 383A1026 */  addiu      $s0, $s0, %lo(D_80093A38)
    /* 6E5E4 8007DDE4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6E5E8 8007DDE8 0000038E */  lw         $v1, 0x0($s0)
    /* 6E5EC 8007DDEC 01000224 */  addiu      $v0, $zero, 0x1
    /* 6E5F0 8007DDF0 0C006214 */  bne        $v1, $v0, .L8007DE24
    /* 6E5F4 8007DDF4 00000000 */   nop
    /* 6E5F8 8007DDF8 F4FF048E */  lw         $a0, -0xC($s0)
    /* 6E5FC 8007DDFC 18FA010C */  jal        func_8007E860
    /* 6E600 8007DE00 00000000 */   nop
    /* 6E604 8007DE04 F8FF048E */  lw         $a0, -0x8($s0)
    /* 6E608 8007DE08 20FA010C */  jal        func_8007E880
    /* 6E60C 8007DE0C 00000000 */   nop
    /* 6E610 8007DE10 09000424 */  addiu      $a0, $zero, 0x9
    /* 6E614 8007DE14 21280000 */  addu       $a1, $zero, $zero
    /* 6E618 8007DE18 21300000 */  addu       $a2, $zero, $zero
    /* 6E61C 8007DE1C 7DEC010C */  jal        func_8007B1F4
    /* 6E620 8007DE20 FFFF0724 */   addiu     $a3, $zero, -0x1
  .L8007DE24:
    /* 6E624 8007DE24 000000AE */  sw         $zero, 0x0($s0)
    /* 6E628 8007DE28 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6E62C 8007DE2C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6E630 8007DE30 0800E003 */  jr         $ra
    /* 6E634 8007DE34 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007DDD4
