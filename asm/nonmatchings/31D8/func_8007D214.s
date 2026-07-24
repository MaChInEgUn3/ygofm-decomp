nonmatching func_8007D214, 0x20

glabel func_8007D214
    /* 6DA14 8007D214 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6DA18 8007D218 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6DA1C 8007D21C 8DF4010C */  jal        func_8007D234
    /* 6DA20 8007D220 21200000 */   addu      $a0, $zero, $zero
    /* 6DA24 8007D224 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6DA28 8007D228 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6DA2C 8007D22C 0800E003 */  jr         $ra
    /* 6DA30 8007D230 00000000 */   nop
endlabel func_8007D214
