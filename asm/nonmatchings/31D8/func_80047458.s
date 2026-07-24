nonmatching func_80047458, 0x28

glabel func_80047458
    /* 37C58 80047458 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 37C5C 8004745C 00240400 */  sll        $a0, $a0, 16
    /* 37C60 80047460 03240400 */  sra        $a0, $a0, 16
    /* 37C64 80047464 1000BFAF */  sw         $ra, 0x10($sp)
    /* 37C68 80047468 3C24010C */  jal        func_800490F0
    /* 37C6C 8004746C FF00A530 */   andi      $a1, $a1, 0xFF
    /* 37C70 80047470 1000BF8F */  lw         $ra, 0x10($sp)
    /* 37C74 80047474 00000000 */  nop
    /* 37C78 80047478 0800E003 */  jr         $ra
    /* 37C7C 8004747C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80047458
