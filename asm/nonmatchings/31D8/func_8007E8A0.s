nonmatching func_8007E8A0, 0x24

glabel func_8007E8A0
    /* 6F0A0 8007E8A0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6F0A4 8007E8A4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6F0A8 8007E8A8 21288000 */  addu       $a1, $a0, $zero
    /* 6F0AC 8007E8AC FCD0010C */  jal        func_800743F0
    /* 6F0B0 8007E8B0 03000424 */   addiu     $a0, $zero, 0x3
    /* 6F0B4 8007E8B4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6F0B8 8007E8B8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6F0BC 8007E8BC 0800E003 */  jr         $ra
    /* 6F0C0 8007E8C0 00000000 */   nop
endlabel func_8007E8A0
    /* 6F0C4 8007E8C4 00000000 */  nop
    /* 6F0C8 8007E8C8 00000000 */  nop
    /* 6F0CC 8007E8CC 00000000 */  nop
