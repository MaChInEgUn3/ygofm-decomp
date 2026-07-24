nonmatching func_80078FBC, 0x2C

glabel func_80078FBC
    /* 697BC 80078FBC 0800C010 */  beqz       $a2, .L80078FE0
    /* 697C0 80078FC0 21180000 */   addu      $v1, $zero, $zero
  .L80078FC4:
    /* 697C4 80078FC4 0000A28C */  lw         $v0, 0x0($a1)
    /* 697C8 80078FC8 0400A524 */  addiu      $a1, $a1, 0x4
    /* 697CC 80078FCC 01006324 */  addiu      $v1, $v1, 0x1
    /* 697D0 80078FD0 000082AC */  sw         $v0, 0x0($a0)
    /* 697D4 80078FD4 2B106600 */  sltu       $v0, $v1, $a2
    /* 697D8 80078FD8 FAFF4014 */  bnez       $v0, .L80078FC4
    /* 697DC 80078FDC 04008424 */   addiu     $a0, $a0, 0x4
  .L80078FE0:
    /* 697E0 80078FE0 0800E003 */  jr         $ra
    /* 697E4 80078FE4 00000000 */   nop
endlabel func_80078FBC
