nonmatching func_80042BC0, 0x48

glabel func_80042BC0
    /* 333C0 80042BC0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 333C4 80042BC4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 333C8 80042BC8 0C008390 */  lbu        $v1, 0xC($a0)
    /* 333CC 80042BCC 60008284 */  lh         $v0, 0x60($a0)
    /* 333D0 80042BD0 00000000 */  nop
    /* 333D4 80042BD4 23186200 */  subu       $v1, $v1, $v0
    /* 333D8 80042BD8 05006018 */  blez       $v1, .L80042BF0
    /* 333DC 80042BDC 00000000 */   nop
    /* 333E0 80042BE0 0E0083A0 */  sb         $v1, 0xE($a0)
    /* 333E4 80042BE4 0D0083A0 */  sb         $v1, 0xD($a0)
    /* 333E8 80042BE8 FE0A0108 */  j          .L80042BF8
    /* 333EC 80042BEC 0C0083A0 */   sb        $v1, 0xC($a0)
  .L80042BF0:
    /* 333F0 80042BF0 DB00010C */  jal        func_8004036C
    /* 333F4 80042BF4 00000000 */   nop
  .L80042BF8:
    /* 333F8 80042BF8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 333FC 80042BFC 00000000 */  nop
    /* 33400 80042C00 0800E003 */  jr         $ra
    /* 33404 80042C04 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80042BC0
