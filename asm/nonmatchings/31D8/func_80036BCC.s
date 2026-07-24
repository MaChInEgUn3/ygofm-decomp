nonmatching func_80036BCC, 0x48

glabel func_80036BCC
    /* 273CC 80036BCC 1E80023C */  lui        $v0, %hi(D_801D9174)
    /* 273D0 80036BD0 74914624 */  addiu      $a2, $v0, %lo(D_801D9174)
    /* 273D4 80036BD4 1E80023C */  lui        $v0, %hi(D_801D9174)
    /* 273D8 80036BD8 74914524 */  addiu      $a1, $v0, %lo(D_801D9174)
  .L80036BDC:
    /* 273DC 80036BDC 0000A290 */  lbu        $v0, 0x0($a1)
    /* 273E0 80036BE0 0100A390 */  lbu        $v1, 0x1($a1)
    /* 273E4 80036BE4 00120200 */  sll        $v0, $v0, 8
    /* 273E8 80036BE8 25104300 */  or         $v0, $v0, $v1
    /* 273EC 80036BEC 03004014 */  bnez       $v0, .L80036BFC
    /* 273F0 80036BF0 00000000 */   nop
    /* 273F4 80036BF4 0800E003 */  jr         $ra
    /* 273F8 80036BF8 21100000 */   addu      $v0, $zero, $zero
  .L80036BFC:
    /* 273FC 80036BFC 03004410 */  beq        $v0, $a0, .L80036C0C
    /* 27400 80036C00 0200A524 */   addiu     $a1, $a1, 0x2
    /* 27404 80036C04 F7DA0008 */  j          .L80036BDC
    /* 27408 80036C08 1E00C624 */   addiu     $a2, $a2, 0x1E
  .L80036C0C:
    /* 2740C 80036C0C 0800E003 */  jr         $ra
    /* 27410 80036C10 2110C000 */   addu      $v0, $a2, $zero
endlabel func_80036BCC
