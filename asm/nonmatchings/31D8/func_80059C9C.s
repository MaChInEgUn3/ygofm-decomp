nonmatching func_80059C9C, 0x34

glabel func_80059C9C
    /* 4A49C 80059C9C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4A4A0 80059CA0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4A4A4 80059CA4 F64C010C */  jal        func_800533D8
    /* 4A4A8 80059CA8 00000000 */   nop
    /* 4A4AC 80059CAC 314C010C */  jal        func_800530C4
    /* 4A4B0 80059CB0 00000000 */   nop
    /* 4A4B4 80059CB4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4A4B8 80059CB8 14000224 */  addiu      $v0, $zero, 0x14
    /* 4A4BC 80059CBC 8C0082A3 */  sb         $v0, %gp_rel(D_8009AF94)($gp)
    /* 4A4C0 80059CC0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 4A4C4 80059CC4 920082A3 */  sb         $v0, %gp_rel(D_8009AF9A)($gp)
    /* 4A4C8 80059CC8 0800E003 */  jr         $ra
    /* 4A4CC 80059CCC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80059C9C
