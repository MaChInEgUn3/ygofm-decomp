nonmatching func_8003C4E0, 0x88

glabel func_8003C4E0
    /* 2CCE0 8003C4E0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2CCE4 8003C4E4 1D80033C */  lui        $v1, %hi(D_801D5708)
    /* 2CCE8 8003C4E8 04000224 */  addiu      $v0, $zero, 0x4
    /* 2CCEC 8003C4EC 085762A0 */  sb         $v0, %lo(D_801D5708)($v1)
    /* 2CCF0 8003C4F0 08576324 */  addiu      $v1, $v1, %lo(D_801D5708)
    /* 2CCF4 8003C4F4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2CCF8 8003C4F8 010062A0 */  sb         $v0, 0x1($v1)
    /* 2CCFC 8003C4FC 020062A0 */  sb         $v0, 0x2($v1)
    /* 2CD00 8003C500 030062A0 */  sb         $v0, 0x3($v1)
    /* 2CD04 8003C504 040062A0 */  sb         $v0, 0x4($v1)
    /* 2CD08 8003C508 21108300 */  addu       $v0, $a0, $v1
    /* 2CD0C 8003C50C 04008010 */  beqz       $a0, .L8003C520
    /* 2CD10 8003C510 000040A0 */   sb        $zero, 0x0($v0)
    /* 2CD14 8003C514 02000224 */  addiu      $v0, $zero, 0x2
    /* 2CD18 8003C518 4AF10008 */  j          .L8003C528
    /* 2CD1C 8003C51C 030062A0 */   sb        $v0, 0x3($v1)
  .L8003C520:
    /* 2CD20 8003C520 02000224 */  addiu      $v0, $zero, 0x2
    /* 2CD24 8003C524 040062A0 */  sb         $v0, 0x4($v1)
  .L8003C528:
    /* 2CD28 8003C528 01000424 */  addiu      $a0, $zero, 0x1
    /* 2CD2C 8003C52C 20010224 */  addiu      $v0, $zero, 0x120
    /* 2CD30 8003C530 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2CD34 8003C534 00010224 */  addiu      $v0, $zero, 0x100
    /* 2CD38 8003C538 EF000524 */  addiu      $a1, $zero, 0xEF
    /* 2CD3C 8003C53C 18000624 */  addiu      $a2, $zero, 0x18
    /* 2CD40 8003C540 38000724 */  addiu      $a3, $zero, 0x38
    /* 2CD44 8003C544 F9D6000C */  jal        func_80035BE4
    /* 2CD48 8003C548 1400A2AF */   sw        $v0, 0x14($sp)
    /* 2CD4C 8003C54C 0F80043C */  lui        $a0, %hi(D_800EB15C)
    /* 2CD50 8003C550 85E6000C */  jal        func_80039A14
    /* 2CD54 8003C554 5CB18424 */   addiu     $a0, $a0, %lo(D_800EB15C)
    /* 2CD58 8003C558 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2CD5C 8003C55C 00000000 */  nop
    /* 2CD60 8003C560 0800E003 */  jr         $ra
    /* 2CD64 8003C564 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003C4E0
