nonmatching func_80074390, 0x30

glabel func_80074390
    /* 64B90 80074390 0980023C */  lui        $v0, %hi(D_80092A88)
    /* 64B94 80074394 882A428C */  lw         $v0, %lo(D_80092A88)($v0)
    /* 64B98 80074398 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 64B9C 8007439C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 64BA0 800743A0 0C00428C */  lw         $v0, 0xC($v0)
    /* 64BA4 800743A4 00000000 */  nop
    /* 64BA8 800743A8 09F84000 */  jalr       $v0
    /* 64BAC 800743AC 00000000 */   nop
    /* 64BB0 800743B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 64BB4 800743B4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 64BB8 800743B8 0800E003 */  jr         $ra
    /* 64BBC 800743BC 00000000 */   nop
endlabel func_80074390
