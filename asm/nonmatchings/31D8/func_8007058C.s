nonmatching func_8007058C, 0x20

glabel func_8007058C
    /* 60D8C 8007058C 0F80033C */  lui        $v1, %hi(D_800F5BE8)
    /* 60D90 80070590 E85B6324 */  addiu      $v1, $v1, %lo(D_800F5BE8)
    /* 60D94 80070594 0800648C */  lw         $a0, 0x8($v1)
    /* 60D98 80070598 00000000 */  nop
    /* 60D9C 8007059C 00008290 */  lbu        $v0, 0x0($a0)
    /* 60DA0 800705A0 01008424 */  addiu      $a0, $a0, 0x1
    /* 60DA4 800705A4 0800E003 */  jr         $ra
    /* 60DA8 800705A8 080064AC */   sw        $a0, 0x8($v1)
endlabel func_8007058C
