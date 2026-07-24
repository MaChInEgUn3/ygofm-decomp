nonmatching func_80035DF4, 0x2C

glabel func_80035DF4
    /* 265F4 80035DF4 6C020324 */  addiu      $v1, $zero, 0x26C
    /* 265F8 80035DF8 0F80023C */  lui        $v0, %hi(D_800EB288)
    /* 265FC 80035DFC 88B24224 */  addiu      $v0, $v0, %lo(D_800EB288)
    /* 26600 80035E00 18004224 */  addiu      $v0, $v0, 0x18
  .L80035E04:
    /* 26604 80035E04 F9FF40A0 */  sb         $zero, -0x7($v0)
    /* 26608 80035E08 000040A0 */  sb         $zero, 0x0($v0)
    /* 2660C 80035E0C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 26610 80035E10 FCFF6014 */  bnez       $v1, .L80035E04
    /* 26614 80035E14 1C004224 */   addiu     $v0, $v0, 0x1C
    /* 26618 80035E18 0800E003 */  jr         $ra
    /* 2661C 80035E1C 00000000 */   nop
endlabel func_80035DF4
