nonmatching func_80073FBC, 0x40

glabel func_80073FBC
    /* 647BC 80073FBC 0980033C */  lui        $v1, %hi(D_80091980)
    /* 647C0 80073FC0 8019638C */  lw         $v1, %lo(D_80091980)($v1)
    /* 647C4 80073FC4 00000000 */  nop
    /* 647C8 80073FC8 0400628C */  lw         $v0, 0x4($v1)
    /* 647CC 80073FCC 00000000 */  nop
    /* 647D0 80073FD0 01004230 */  andi       $v0, $v0, 0x1
    /* 647D4 80073FD4 07004010 */  beqz       $v0, .L80073FF4
    /* 647D8 80073FD8 21100000 */   addu      $v0, $zero, $zero
    /* 647DC 80073FDC 0000628C */  lw         $v0, 0x0($v1)
    /* 647E0 80073FE0 00000000 */  nop
    /* 647E4 80073FE4 01004230 */  andi       $v0, $v0, 0x1
    /* 647E8 80073FE8 02004014 */  bnez       $v0, .L80073FF4
    /* 647EC 80073FEC 01000224 */   addiu     $v0, $zero, 0x1
    /* 647F0 80073FF0 21100000 */  addu       $v0, $zero, $zero
  .L80073FF4:
    /* 647F4 80073FF4 0800E003 */  jr         $ra
    /* 647F8 80073FF8 00000000 */   nop
endlabel func_80073FBC
    /* 647FC 80073FFC 00000000 */  nop
