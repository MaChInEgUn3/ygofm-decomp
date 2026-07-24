nonmatching func_80047278, 0x30

glabel func_80047278
    /* 37A78 80047278 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 37A7C 8004727C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 37A80 80047280 21808000 */  addu       $s0, $a0, $zero
    /* 37A84 80047284 1400BFAF */  sw         $ra, 0x14($sp)
    /* 37A88 80047288 AA1C010C */  jal        func_800472A8
    /* 37A8C 8004728C 02241000 */   srl       $a0, $s0, 16
    /* 37A90 80047290 B41E010C */  jal        func_80047AD0
    /* 37A94 80047294 FFFF0432 */   andi      $a0, $s0, 0xFFFF
    /* 37A98 80047298 1400BF8F */  lw         $ra, 0x14($sp)
    /* 37A9C 8004729C 1000B08F */  lw         $s0, 0x10($sp)
    /* 37AA0 800472A0 0800E003 */  jr         $ra
    /* 37AA4 800472A4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80047278
