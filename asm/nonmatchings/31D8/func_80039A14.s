nonmatching func_80039A14, 0x4C

glabel func_80039A14
    /* 2A214 80039A14 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A218 80039A18 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2A21C 80039A1C 21808000 */  addu       $s0, $a0, $zero
    /* 2A220 80039A20 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2A224 80039A24 34000296 */  lhu        $v0, 0x34($s0)
    /* 2A228 80039A28 00000000 */  nop
    /* 2A22C 80039A2C 00084234 */  ori        $v0, $v0, 0x800
    /* 2A230 80039A30 340002A6 */  sh         $v0, 0x34($s0)
  .L80039A34:
    /* 2A234 80039A34 ECE4000C */  jal        func_800393B0
    /* 2A238 80039A38 21200002 */   addu      $a0, $s0, $zero
    /* 2A23C 80039A3C 34000296 */  lhu        $v0, 0x34($s0)
    /* 2A240 80039A40 00000000 */  nop
    /* 2A244 80039A44 00204230 */  andi       $v0, $v0, 0x2000
    /* 2A248 80039A48 FAFF4010 */  beqz       $v0, .L80039A34
    /* 2A24C 80039A4C 00000000 */   nop
    /* 2A250 80039A50 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2A254 80039A54 1000B08F */  lw         $s0, 0x10($sp)
    /* 2A258 80039A58 0800E003 */  jr         $ra
    /* 2A25C 80039A5C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80039A14
