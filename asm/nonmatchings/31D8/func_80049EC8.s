nonmatching func_80049EC8, 0x48

glabel func_80049EC8
    /* 3A6C8 80049EC8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3A6CC 80049ECC 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3A6D0 80049ED0 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3A6D4 80049ED4 7F008430 */  andi       $a0, $a0, 0x7F
    /* 3A6D8 80049ED8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3A6DC 80049EDC E2074384 */  lh         $v1, 0x7E2($v0)
    /* 3A6E0 80049EE0 7F00A530 */  andi       $a1, $a1, 0x7F
    /* 3A6E4 80049EE4 E40744A4 */  sh         $a0, 0x7E4($v0)
    /* 3A6E8 80049EE8 E60745A4 */  sh         $a1, 0x7E6($v0)
    /* 3A6EC 80049EEC 02000224 */  addiu      $v0, $zero, 0x2
    /* 3A6F0 80049EF0 03006210 */  beq        $v1, $v0, .L80049F00
    /* 3A6F4 80049EF4 00000000 */   nop
    /* 3A6F8 80049EF8 BE28010C */  jal        func_8004A2F8
    /* 3A6FC 80049EFC 00000000 */   nop
  .L80049F00:
    /* 3A700 80049F00 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3A704 80049F04 00000000 */  nop
    /* 3A708 80049F08 0800E003 */  jr         $ra
    /* 3A70C 80049F0C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80049EC8
