nonmatching func_80039A60, 0x4C

glabel func_80039A60
    /* 2A260 80039A60 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2A264 80039A64 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2A268 80039A68 21808000 */  addu       $s0, $a0, $zero
    /* 2A26C 80039A6C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2A270 80039A70 34000296 */  lhu        $v0, 0x34($s0)
    /* 2A274 80039A74 00000000 */  nop
    /* 2A278 80039A78 000A4234 */  ori        $v0, $v0, 0xA00
    /* 2A27C 80039A7C 340002A6 */  sh         $v0, 0x34($s0)
  .L80039A80:
    /* 2A280 80039A80 ECE4000C */  jal        func_800393B0
    /* 2A284 80039A84 21200002 */   addu      $a0, $s0, $zero
    /* 2A288 80039A88 34000296 */  lhu        $v0, 0x34($s0)
    /* 2A28C 80039A8C 00000000 */  nop
    /* 2A290 80039A90 00204230 */  andi       $v0, $v0, 0x2000
    /* 2A294 80039A94 FAFF4010 */  beqz       $v0, .L80039A80
    /* 2A298 80039A98 00000000 */   nop
    /* 2A29C 80039A9C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2A2A0 80039AA0 1000B08F */  lw         $s0, 0x10($sp)
    /* 2A2A4 80039AA4 0800E003 */  jr         $ra
    /* 2A2A8 80039AA8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80039A60
