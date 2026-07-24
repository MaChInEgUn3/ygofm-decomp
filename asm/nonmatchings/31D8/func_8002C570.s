nonmatching func_8002C570, 0x28

glabel func_8002C570
    /* 1CD70 8002C570 1D80023C */  lui        $v0, %hi(D_801D0000)
    /* 1CD74 8002C574 00004224 */  addiu      $v0, $v0, %lo(D_801D0000)
    /* 1CD78 8002C578 21208200 */  addu       $a0, $a0, $v0
    /* 1CD7C 8002C57C 4F028390 */  lbu        $v1, 0x24F($a0)
    /* 1CD80 8002C580 00000000 */  nop
    /* 1CD84 8002C584 02006014 */  bnez       $v1, .L8002C590
    /* 1CD88 8002C588 01000224 */   addiu     $v0, $zero, 0x1
    /* 1CD8C 8002C58C FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8002C590:
    /* 1CD90 8002C590 0800E003 */  jr         $ra
    /* 1CD94 8002C594 00000000 */   nop
endlabel func_8002C570
