nonmatching func_8007E320, 0x24

glabel func_8007E320
    /* 6EB20 8007E320 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6EB24 8007E324 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6EB28 8007E328 21288000 */  addu       $a1, $a0, $zero
    /* 6EB2C 8007E32C 5DE6010C */  jal        func_80079974
    /* 6EB30 8007E330 01000424 */   addiu     $a0, $zero, 0x1
    /* 6EB34 8007E334 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6EB38 8007E338 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6EB3C 8007E33C 0800E003 */  jr         $ra
    /* 6EB40 8007E340 00000000 */   nop
endlabel func_8007E320
    /* 6EB44 8007E344 00000000 */  nop
    /* 6EB48 8007E348 00000000 */  nop
    /* 6EB4C 8007E34C 00000000 */  nop
