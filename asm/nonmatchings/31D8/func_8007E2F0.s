nonmatching func_8007E2F0, 0x24

glabel func_8007E2F0
    /* 6EAF0 8007E2F0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6EAF4 8007E2F4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6EAF8 8007E2F8 21288000 */  addu       $a1, $a0, $zero
    /* 6EAFC 8007E2FC BDE5010C */  jal        func_800796F4
    /* 6EB00 8007E300 01000424 */   addiu     $a0, $zero, 0x1
    /* 6EB04 8007E304 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6EB08 8007E308 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6EB0C 8007E30C 0800E003 */  jr         $ra
    /* 6EB10 8007E310 00000000 */   nop
endlabel func_8007E2F0
    /* 6EB14 8007E314 00000000 */  nop
    /* 6EB18 8007E318 00000000 */  nop
    /* 6EB1C 8007E31C 00000000 */  nop
