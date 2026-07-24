nonmatching func_80025EE0, 0x5C

glabel func_80025EE0
    /* 166E0 80025EE0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 166E4 80025EE4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 166E8 80025EE8 8993000C */  jal        func_80024E24
    /* 166EC 80025EEC 00000000 */   nop
    /* 166F0 80025EF0 0D004014 */  bnez       $v0, .L80025F28
    /* 166F4 80025EF4 00000000 */   nop
    /* 166F8 80025EF8 A3B1000C */  jal        func_8002C68C
    /* 166FC 80025EFC 12000424 */   addiu     $a0, $zero, 0x12
    /* 16700 80025F00 02000424 */  addiu      $a0, $zero, 0x2
    /* 16704 80025F04 A0000324 */  addiu      $v1, $zero, 0xA0
    /* 16708 80025F08 000043A4 */  sh         $v1, 0x0($v0)
    /* 1670C 80025F0C 78000324 */  addiu      $v1, $zero, 0x78
    /* 16710 80025F10 020043A4 */  sh         $v1, 0x2($v0)
    /* 16714 80025F14 01000324 */  addiu      $v1, $zero, 0x1
    /* 16718 80025F18 B8FF000C */  jal        func_8003FEE0
    /* 1671C 80025F1C 1A0043A4 */   sh        $v1, 0x1A($v0)
    /* 16720 80025F20 CB970008 */  j          .L80025F2C
    /* 16724 80025F24 00000000 */   nop
  .L80025F28:
    /* 16728 80025F28 180380A7 */  sh         $zero, %gp_rel(D_8009B220)($gp)
  .L80025F2C:
    /* 1672C 80025F2C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 16730 80025F30 00000000 */  nop
    /* 16734 80025F34 0800E003 */  jr         $ra
    /* 16738 80025F38 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80025EE0
