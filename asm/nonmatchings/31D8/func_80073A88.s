nonmatching func_80073A88, 0x34

glabel func_80073A88
    /* 64288 80073A88 FFFF8330 */  andi       $v1, $a0, 0xFFFF
    /* 6428C 80073A8C 03006228 */  slti       $v0, $v1, 0x3
    /* 64290 80073A90 07004010 */  beqz       $v0, .L80073AB0
    /* 64294 80073A94 01000224 */   addiu     $v0, $zero, 0x1
    /* 64298 80073A98 0980043C */  lui        $a0, %hi(D_8009195C)
    /* 6429C 80073A9C 5C19848C */  lw         $a0, %lo(D_8009195C)($a0)
    /* 642A0 80073AA0 00190300 */  sll        $v1, $v1, 4
    /* 642A4 80073AA4 21186400 */  addu       $v1, $v1, $a0
    /* 642A8 80073AA8 ADCE0108 */  j          .L80073AB4
    /* 642AC 80073AAC 000060A4 */   sh        $zero, 0x0($v1)
  .L80073AB0:
    /* 642B0 80073AB0 21100000 */  addu       $v0, $zero, $zero
  .L80073AB4:
    /* 642B4 80073AB4 0800E003 */  jr         $ra
    /* 642B8 80073AB8 00000000 */   nop
endlabel func_80073A88
    /* 642BC 80073ABC 00000000 */  nop
