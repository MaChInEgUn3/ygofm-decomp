nonmatching func_8007A820, 0x20

glabel func_8007A820
    /* 6B020 8007A820 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6B024 8007A824 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6B028 8007A828 5DE6010C */  jal        func_80079974
    /* 6B02C 8007A82C 00000000 */   nop
    /* 6B030 8007A830 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6B034 8007A834 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6B038 8007A838 0800E003 */  jr         $ra
    /* 6B03C 8007A83C 00000000 */   nop
endlabel func_8007A820
