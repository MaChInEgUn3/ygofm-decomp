nonmatching func_80012CD4, 0x78

glabel func_80012CD4
    /* 34D4 80012CD4 9401828F */  lw         $v0, %gp_rel(D_8009B09C)($gp)
    /* 34D8 80012CD8 00000000 */  nop
    /* 34DC 80012CDC 01004224 */  addiu      $v0, $v0, 0x1
    /* 34E0 80012CE0 940182AF */  sw         $v0, %gp_rel(D_8009B09C)($gp)
    /* 34E4 80012CE4 BC01828F */  lw         $v0, %gp_rel(D_8009B0C4)($gp)
    /* 34E8 80012CE8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 34EC 80012CEC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 34F0 80012CF0 01004224 */  addiu      $v0, $v0, 0x1
    /* 34F4 80012CF4 BC0182AF */  sw         $v0, %gp_rel(D_8009B0C4)($gp)
    /* 34F8 80012CF8 C001828F */  lw         $v0, %gp_rel(D_8009B0C8)($gp)
    /* 34FC 80012CFC 01001024 */  addiu      $s0, $zero, 0x1
    /* 3500 80012D00 1400BFAF */  sw         $ra, 0x14($sp)
    /* 3504 80012D04 BB0190A3 */  sb         $s0, %gp_rel(D_8009B0C3)($gp)
    /* 3508 80012D08 01004224 */  addiu      $v0, $v0, 0x1
    /* 350C 80012D0C C00182AF */  sw         $v0, %gp_rel(D_8009B0C8)($gp)
    /* 3510 80012D10 0EF3000C */  jal        func_8003CC38
    /* 3514 80012D14 00000000 */   nop
    /* 3518 80012D18 04008293 */  lbu        $v0, %gp_rel(D_8009AF0C)($gp)
    /* 351C 80012D1C 00000000 */  nop
    /* 3520 80012D20 06004014 */  bnez       $v0, .L80012D3C
    /* 3524 80012D24 00000000 */   nop
    /* 3528 80012D28 040090A3 */  sb         $s0, %gp_rel(D_8009AF0C)($gp)
    /* 352C 80012D2C 141C010C */  jal        func_80047050
    /* 3530 80012D30 00000000 */   nop
    /* 3534 80012D34 040080A3 */  sb         $zero, %gp_rel(D_8009AF0C)($gp)
    /* 3538 80012D38 BB0180A3 */  sb         $zero, %gp_rel(D_8009B0C3)($gp)
  .L80012D3C:
    /* 353C 80012D3C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3540 80012D40 1000B08F */  lw         $s0, 0x10($sp)
    /* 3544 80012D44 0800E003 */  jr         $ra
    /* 3548 80012D48 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80012CD4
