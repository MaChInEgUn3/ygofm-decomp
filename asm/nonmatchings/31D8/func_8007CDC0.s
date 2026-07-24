nonmatching func_8007CDC0, 0x20

glabel func_8007CDC0
    /* 6D5C0 8007CDC0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6D5C4 8007CDC4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6D5C8 8007CDC8 12E8010C */  jal        func_8007A048
    /* 6D5CC 8007CDCC 00000000 */   nop
    /* 6D5D0 8007CDD0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6D5D4 8007CDD4 01000224 */  addiu      $v0, $zero, 0x1
    /* 6D5D8 8007CDD8 0800E003 */  jr         $ra
    /* 6D5DC 8007CDDC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007CDC0
