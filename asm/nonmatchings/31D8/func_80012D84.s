nonmatching func_80012D84, 0x30

glabel func_80012D84
    /* 3584 80012D84 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3588 80012D88 1000B0AF */  sw         $s0, 0x10($sp)
    /* 358C 80012D8C 21808000 */  addu       $s0, $a0, $zero
    /* 3590 80012D90 1400BFAF */  sw         $ra, 0x14($sp)
  .L80012D94:
    /* 3594 80012D94 534B000C */  jal        func_80012D4C
    /* 3598 80012D98 FFFF1026 */   addiu     $s0, $s0, -0x1
    /* 359C 80012D9C FDFF0016 */  bnez       $s0, .L80012D94
    /* 35A0 80012DA0 00000000 */   nop
    /* 35A4 80012DA4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 35A8 80012DA8 1000B08F */  lw         $s0, 0x10($sp)
    /* 35AC 80012DAC 0800E003 */  jr         $ra
    /* 35B0 80012DB0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012D84
