nonmatching func_8007E4F0, 0x20

glabel func_8007E4F0
    /* 6ECF0 8007E4F0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6ECF4 8007E4F4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6ECF8 8007E4F8 44F9010C */  jal        func_8007E510
    /* 6ECFC 8007E4FC 00000000 */   nop
    /* 6ED00 8007E500 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6ED04 8007E504 0100422C */  sltiu      $v0, $v0, 0x1
    /* 6ED08 8007E508 0800E003 */  jr         $ra
    /* 6ED0C 8007E50C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007E4F0
