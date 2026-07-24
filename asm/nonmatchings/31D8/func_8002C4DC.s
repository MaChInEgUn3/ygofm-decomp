nonmatching func_8002C4DC, 0x3C

glabel func_8002C4DC
    /* 1CCDC 8002C4DC 1D80023C */  lui        $v0, %hi(D_801D0200)
    /* 1CCE0 8002C4E0 00024524 */  addiu      $a1, $v0, %lo(D_801D0200)
    /* 1CCE4 8002C4E4 21180000 */  addu       $v1, $zero, $zero
  .L8002C4E8:
    /* 1CCE8 8002C4E8 0000A294 */  lhu        $v0, 0x0($a1)
    /* 1CCEC 8002C4EC 00000000 */  nop
    /* 1CCF0 8002C4F0 07004410 */  beq        $v0, $a0, .L8002C510
    /* 1CCF4 8002C4F4 21106000 */   addu      $v0, $v1, $zero
    /* 1CCF8 8002C4F8 01006324 */  addiu      $v1, $v1, 0x1
    /* 1CCFC 8002C4FC 28006228 */  slti       $v0, $v1, 0x28
    /* 1CD00 8002C500 F9FF4014 */  bnez       $v0, .L8002C4E8
    /* 1CD04 8002C504 0200A524 */   addiu     $a1, $a1, 0x2
    /* 1CD08 8002C508 0800E003 */  jr         $ra
    /* 1CD0C 8002C50C FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8002C510:
    /* 1CD10 8002C510 0800E003 */  jr         $ra
    /* 1CD14 8002C514 00000000 */   nop
endlabel func_8002C4DC
