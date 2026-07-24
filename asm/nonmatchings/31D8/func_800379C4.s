nonmatching func_800379C4, 0x34

glabel func_800379C4
    /* 281C4 800379C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 281C8 800379C8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 281CC 800379CC 1400BFAF */  sw         $ra, 0x14($sp)
    /* 281D0 800379D0 4824010C */  jal        func_80049120
    /* 281D4 800379D4 21808000 */   addu      $s0, $a0, $zero
    /* 281D8 800379D8 01000324 */  addiu      $v1, $zero, 0x1
    /* 281DC 800379DC 02004310 */  beq        $v0, $v1, .L800379E8
    /* 281E0 800379E0 00000000 */   nop
    /* 281E4 800379E4 510000A2 */  sb         $zero, 0x51($s0)
  .L800379E8:
    /* 281E8 800379E8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 281EC 800379EC 1000B08F */  lw         $s0, 0x10($sp)
    /* 281F0 800379F0 0800E003 */  jr         $ra
    /* 281F4 800379F4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800379C4
