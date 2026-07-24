nonmatching func_80035DB8, 0x3C

glabel func_80035DB8
    /* 265B8 80035DB8 6C020524 */  addiu      $a1, $zero, 0x26C
    /* 265BC 80035DBC 01008424 */  addiu      $a0, $a0, 0x1
    /* 265C0 80035DC0 0F80023C */  lui        $v0, %hi(D_800EB288)
    /* 265C4 80035DC4 88B24224 */  addiu      $v0, $v0, %lo(D_800EB288)
    /* 265C8 80035DC8 11004324 */  addiu      $v1, $v0, 0x11
  .L80035DCC:
    /* 265CC 80035DCC 01006290 */  lbu        $v0, 0x1($v1)
    /* 265D0 80035DD0 00000000 */  nop
    /* 265D4 80035DD4 02004414 */  bne        $v0, $a0, .L80035DE0
    /* 265D8 80035DD8 00000000 */   nop
    /* 265DC 80035DDC 000060A0 */  sb         $zero, 0x0($v1)
  .L80035DE0:
    /* 265E0 80035DE0 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 265E4 80035DE4 F9FFA014 */  bnez       $a1, .L80035DCC
    /* 265E8 80035DE8 1C006324 */   addiu     $v1, $v1, 0x1C
    /* 265EC 80035DEC 0800E003 */  jr         $ra
    /* 265F0 80035DF0 00000000 */   nop
endlabel func_80035DB8
