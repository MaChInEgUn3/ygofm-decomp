nonmatching func_8003D288, 0x30

glabel func_8003D288
    /* 2DA88 8003D288 3403838C */  lw         $v1, 0x334($a0)
    /* 2DA8C 8003D28C 3403A28C */  lw         $v0, 0x334($a1)
    /* 2DA90 8003D290 00000000 */  nop
    /* 2DA94 8003D294 06006214 */  bne        $v1, $v0, .L8003D2B0
    /* 2DA98 8003D298 05000224 */   addiu     $v0, $zero, 0x5
    /* 2DA9C 8003D29C FFFF4224 */  addiu      $v0, $v0, -0x1
  .L8003D2A0:
    /* 2DAA0 8003D2A0 FFFF4104 */  bgez       $v0, .L8003D2A0
    /* 2DAA4 8003D2A4 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 2DAA8 8003D2A8 0800E003 */  jr         $ra
    /* 2DAAC 8003D2AC 01000224 */   addiu     $v0, $zero, 0x1
  .L8003D2B0:
    /* 2DAB0 8003D2B0 0800E003 */  jr         $ra
    /* 2DAB4 8003D2B4 21100000 */   addu      $v0, $zero, $zero
endlabel func_8003D288
