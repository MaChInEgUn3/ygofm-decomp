nonmatching func_8002C598, 0x34

glabel func_8002C598
    /* 1CD98 8002C598 580380A3 */  sb         $zero, %gp_rel(D_8009B260)($gp)
    /* 1CD9C 8002C59C 08000324 */  addiu      $v1, $zero, 0x8
    /* 1CDA0 8002C5A0 FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 1CDA4 8002C5A4 0F80023C */  lui        $v0, %hi(D_800EAD88)
    /* 1CDA8 8002C5A8 88AD4224 */  addiu      $v0, $v0, %lo(D_800EAD88)
    /* 1CDAC 8002C5AC 18004224 */  addiu      $v0, $v0, 0x18
  .L8002C5B0:
    /* 1CDB0 8002C5B0 040040A0 */  sb         $zero, 0x4($v0)
    /* 1CDB4 8002C5B4 000044A4 */  sh         $a0, 0x0($v0)
    /* 1CDB8 8002C5B8 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 1CDBC 8002C5BC FCFF6014 */  bnez       $v1, .L8002C5B0
    /* 1CDC0 8002C5C0 20004224 */   addiu     $v0, $v0, 0x20
    /* 1CDC4 8002C5C4 0800E003 */  jr         $ra
    /* 1CDC8 8002C5C8 00000000 */   nop
endlabel func_8002C598
