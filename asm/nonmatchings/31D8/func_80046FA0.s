nonmatching func_80046FA0, 0x68

glabel func_80046FA0
    /* 377A0 80046FA0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 377A4 80046FA4 21288000 */  addu       $a1, $a0, $zero
    /* 377A8 80046FA8 5405838F */  lw         $v1, %gp_rel(D_8009B45C)($gp)
    /* 377AC 80046FAC 00240400 */  sll        $a0, $a0, 16
    /* 377B0 80046FB0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 377B4 80046FB4 48006290 */  lbu        $v0, 0x48($v1)
    /* 377B8 80046FB8 03240400 */  sra        $a0, $a0, 16
    /* 377BC 80046FBC 0E004410 */  beq        $v0, $a0, .L80046FF8
    /* 377C0 80046FC0 00000000 */   nop
    /* 377C4 80046FC4 05008014 */  bnez       $a0, .L80046FDC
    /* 377C8 80046FC8 480065A0 */   sb        $a1, 0x48($v1)
    /* 377CC 80046FCC 7725010C */  jal        func_800495DC
    /* 377D0 80046FD0 00000000 */   nop
    /* 377D4 80046FD4 F91B0108 */  j          .L80046FE4
    /* 377D8 80046FD8 00000000 */   nop
  .L80046FDC:
    /* 377DC 80046FDC 7B25010C */  jal        func_800495EC
    /* 377E0 80046FE0 00000000 */   nop
  .L80046FE4:
    /* 377E4 80046FE4 5405828F */  lw         $v0, %gp_rel(D_8009B45C)($gp)
    /* 377E8 80046FE8 00000000 */  nop
    /* 377EC 80046FEC 10054484 */  lh         $a0, 0x510($v0)
    /* 377F0 80046FF0 7013010C */  jal        func_80044DC0
    /* 377F4 80046FF4 00000000 */   nop
  .L80046FF8:
    /* 377F8 80046FF8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 377FC 80046FFC 00000000 */  nop
    /* 37800 80047000 0800E003 */  jr         $ra
    /* 37804 80047004 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80046FA0
