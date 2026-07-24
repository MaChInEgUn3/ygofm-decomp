nonmatching func_80049F10, 0x40

glabel func_80049F10
    /* 3A710 80049F10 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3A714 80049F14 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3A718 80049F18 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3A71C 80049F1C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3A720 80049F20 E2074384 */  lh         $v1, 0x7E2($v0)
    /* 3A724 80049F24 140544A4 */  sh         $a0, 0x514($v0)
    /* 3A728 80049F28 160545A4 */  sh         $a1, 0x516($v0)
    /* 3A72C 80049F2C 02000224 */  addiu      $v0, $zero, 0x2
    /* 3A730 80049F30 03006210 */  beq        $v1, $v0, .L80049F40
    /* 3A734 80049F34 00000000 */   nop
    /* 3A738 80049F38 BE28010C */  jal        func_8004A2F8
    /* 3A73C 80049F3C 00000000 */   nop
  .L80049F40:
    /* 3A740 80049F40 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3A744 80049F44 00000000 */  nop
    /* 3A748 80049F48 0800E003 */  jr         $ra
    /* 3A74C 80049F4C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80049F10
