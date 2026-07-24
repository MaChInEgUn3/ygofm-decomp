nonmatching func_80035598, 0x30

glabel func_80035598
    /* 25D98 80035598 0000838C */  lw         $v1, 0x0($a0)
    /* 25D9C 8003559C 0000A58C */  lw         $a1, 0x0($a1)
    /* 25DA0 800355A0 00000000 */  nop
    /* 25DA4 800355A4 05006510 */  beq        $v1, $a1, .L800355BC
    /* 25DA8 800355A8 2B186500 */   sltu      $v1, $v1, $a1
    /* 25DAC 800355AC 04006010 */  beqz       $v1, .L800355C0
    /* 25DB0 800355B0 01000224 */   addiu     $v0, $zero, 0x1
    /* 25DB4 800355B4 0800E003 */  jr         $ra
    /* 25DB8 800355B8 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L800355BC:
    /* 25DBC 800355BC 21100000 */  addu       $v0, $zero, $zero
  .L800355C0:
    /* 25DC0 800355C0 0800E003 */  jr         $ra
    /* 25DC4 800355C4 00000000 */   nop
endlabel func_80035598
