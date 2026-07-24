nonmatching func_8002E9A0, 0x6C

glabel func_8002E9A0
    /* 1F1A0 8002E9A0 8803848F */  lw         $a0, %gp_rel(D_8009B290)($gp)
    /* 1F1A4 8002E9A4 00000000 */  nop
    /* 1F1A8 8002E9A8 02008624 */  addiu      $a2, $a0, 0x2
    /* 1F1AC 8002E9AC 880386AF */  sw         $a2, %gp_rel(D_8009B290)($gp)
    /* 1F1B0 8002E9B0 00008390 */  lbu        $v1, 0x0($a0)
    /* 1F1B4 8002E9B4 01008290 */  lbu        $v0, 0x1($a0)
    /* 1F1B8 8002E9B8 04008724 */  addiu      $a3, $a0, 0x4
    /* 1F1BC 8002E9BC 880387AF */  sw         $a3, %gp_rel(D_8009B290)($gp)
    /* 1F1C0 8002E9C0 00120200 */  sll        $v0, $v0, 8
    /* 1F1C4 8002E9C4 25186200 */  or         $v1, $v1, $v0
    /* 1F1C8 8002E9C8 A00383A7 */  sh         $v1, %gp_rel(D_8009B2A8)($gp)
    /* 1F1CC 8002E9CC 02008590 */  lbu        $a1, 0x2($a0)
    /* 1F1D0 8002E9D0 0100C290 */  lbu        $v0, 0x1($a2)
    /* 1F1D4 8002E9D4 06008324 */  addiu      $v1, $a0, 0x6
    /* 1F1D8 8002E9D8 880383AF */  sw         $v1, %gp_rel(D_8009B290)($gp)
    /* 1F1DC 8002E9DC 00120200 */  sll        $v0, $v0, 8
    /* 1F1E0 8002E9E0 2528A200 */  or         $a1, $a1, $v0
    /* 1F1E4 8002E9E4 A20385A7 */  sh         $a1, %gp_rel(D_8009B2AA)($gp)
    /* 1F1E8 8002E9E8 04008490 */  lbu        $a0, 0x4($a0)
    /* 1F1EC 8002E9EC 0100E290 */  lbu        $v0, 0x1($a3)
    /* 1F1F0 8002E9F0 07000324 */  addiu      $v1, $zero, 0x7
    /* 1F1F4 8002E9F4 740383A7 */  sh         $v1, %gp_rel(D_8009B27C)($gp)
    /* 1F1F8 8002E9F8 00120200 */  sll        $v0, $v0, 8
    /* 1F1FC 8002E9FC 25208200 */  or         $a0, $a0, $v0
    /* 1F200 8002EA00 940384A7 */  sh         $a0, %gp_rel(D_8009B29C)($gp)
    /* 1F204 8002EA04 0800E003 */  jr         $ra
    /* 1F208 8002EA08 00000000 */   nop
endlabel func_8002E9A0
