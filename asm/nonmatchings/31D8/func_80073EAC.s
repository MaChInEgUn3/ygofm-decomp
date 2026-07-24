nonmatching func_80073EAC, 0x30

glabel func_80073EAC
    /* 646AC 80073EAC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 646B0 80073EB0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 646B4 80073EB4 04D0010C */  jal        func_80074010
    /* 646B8 80073EB8 00000000 */   nop
    /* 646BC 80073EBC 50CE010C */  jal        func_80073940
    /* 646C0 80073EC0 21200000 */   addu      $a0, $zero, $zero
    /* 646C4 80073EC4 14D0010C */  jal        func_80074050
    /* 646C8 80073EC8 00000000 */   nop
    /* 646CC 80073ECC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 646D0 80073ED0 01000224 */  addiu      $v0, $zero, 0x1
    /* 646D4 80073ED4 0800E003 */  jr         $ra
    /* 646D8 80073ED8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80073EAC
