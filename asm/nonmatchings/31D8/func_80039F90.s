nonmatching func_80039F90, 0x44

glabel func_80039F90
    /* 2A790 80039F90 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2A794 80039F94 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2A798 80039F98 02001124 */  addiu      $s1, $zero, 0x2
    /* 2A79C 80039F9C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2A7A0 80039FA0 08009024 */  addiu      $s0, $a0, 0x8
    /* 2A7A4 80039FA4 1800BFAF */  sw         $ra, 0x18($sp)
  .L80039FA8:
    /* 2A7A8 80039FA8 0000048E */  lw         $a0, 0x0($s0)
    /* 2A7AC 80039FAC DB00010C */  jal        func_8004036C
    /* 2A7B0 80039FB0 FFFF3126 */   addiu     $s1, $s1, -0x1
    /* 2A7B4 80039FB4 000000AE */  sw         $zero, 0x0($s0)
    /* 2A7B8 80039FB8 FBFF2106 */  bgez       $s1, .L80039FA8
    /* 2A7BC 80039FBC FCFF1026 */   addiu     $s0, $s0, -0x4
    /* 2A7C0 80039FC0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2A7C4 80039FC4 1400B18F */  lw         $s1, 0x14($sp)
    /* 2A7C8 80039FC8 1000B08F */  lw         $s0, 0x10($sp)
    /* 2A7CC 80039FCC 0800E003 */  jr         $ra
    /* 2A7D0 80039FD0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80039F90
