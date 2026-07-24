nonmatching func_80032328, 0x48

glabel func_80032328
    /* 22B28 80032328 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 22B2C 8003232C 0380023C */  lui        $v0, %hi(func_80032184)
    /* 22B30 80032330 84214224 */  addiu      $v0, $v0, %lo(func_80032184)
    /* 22B34 80032334 21200000 */  addu       $a0, $zero, $zero
    /* 22B38 80032338 21288000 */  addu       $a1, $a0, $zero
    /* 22B3C 8003233C 89210624 */  addiu      $a2, $zero, 0x2189
    /* 22B40 80032340 4C000724 */  addiu      $a3, $zero, 0x4C
    /* 22B44 80032344 2000BFAF */  sw         $ra, 0x20($sp)
    /* 22B48 80032348 1000A2AF */  sw         $v0, 0x10($sp)
    /* 22B4C 8003234C 1400A0AF */  sw         $zero, 0x14($sp)
    /* 22B50 80032350 8753000C */  jal        func_80014E1C
    /* 22B54 80032354 1800A0AF */   sw        $zero, 0x18($sp)
    /* 22B58 80032358 F94D000C */  jal        func_800137E4
    /* 22B5C 8003235C 00000000 */   nop
    /* 22B60 80032360 2000BF8F */  lw         $ra, 0x20($sp)
    /* 22B64 80032364 00000000 */  nop
    /* 22B68 80032368 0800E003 */  jr         $ra
    /* 22B6C 8003236C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80032328
