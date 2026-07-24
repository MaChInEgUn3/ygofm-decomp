nonmatching func_80073F54, 0x68

glabel func_80073F54
    /* 64754 80073F54 0980023C */  lui        $v0, %hi(D_8009197C)
    /* 64758 80073F58 7C19428C */  lw         $v0, %lo(D_8009197C)($v0)
    /* 6475C 80073F5C F0FFBD27 */  addiu      $sp, $sp, -0x10
    /* 64760 80073F60 0A0040A4 */  sh         $zero, 0xA($v0)
    /* 64764 80073F64 0A000224 */  addiu      $v0, $zero, 0xA
    /* 64768 80073F68 0000A2AF */  sw         $v0, 0x0($sp)
    /* 6476C 80073F6C 0000A28F */  lw         $v0, 0x0($sp)
    /* 64770 80073F70 00000000 */  nop
    /* 64774 80073F74 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 64778 80073F78 0000A2AF */  sw         $v0, 0x0($sp)
    /* 6477C 80073F7C 0000A38F */  lw         $v1, 0x0($sp)
    /* 64780 80073F80 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 64784 80073F84 0A006210 */  beq        $v1, $v0, .L80073FB0
    /* 64788 80073F88 21100000 */   addu      $v0, $zero, $zero
    /* 6478C 80073F8C FFFF0324 */  addiu      $v1, $zero, -0x1
  .L80073F90:
    /* 64790 80073F90 0000A28F */  lw         $v0, 0x0($sp)
    /* 64794 80073F94 00000000 */  nop
    /* 64798 80073F98 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 6479C 80073F9C 0000A2AF */  sw         $v0, 0x0($sp)
    /* 647A0 80073FA0 0000A28F */  lw         $v0, 0x0($sp)
    /* 647A4 80073FA4 00000000 */  nop
    /* 647A8 80073FA8 F9FF4314 */  bne        $v0, $v1, .L80073F90
    /* 647AC 80073FAC 21100000 */   addu      $v0, $zero, $zero
  .L80073FB0:
    /* 647B0 80073FB0 1000BD27 */  addiu      $sp, $sp, 0x10
    /* 647B4 80073FB4 0800E003 */  jr         $ra
    /* 647B8 80073FB8 00000000 */   nop
endlabel func_80073F54
