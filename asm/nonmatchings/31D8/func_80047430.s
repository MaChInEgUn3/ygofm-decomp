nonmatching func_80047430, 0x28

glabel func_80047430
    /* 37C30 80047430 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 37C34 80047434 00240400 */  sll        $a0, $a0, 16
    /* 37C38 80047438 03240400 */  sra        $a0, $a0, 16
    /* 37C3C 8004743C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 37C40 80047440 4224010C */  jal        func_80049108
    /* 37C44 80047444 FF00A530 */   andi      $a1, $a1, 0xFF
    /* 37C48 80047448 1000BF8F */  lw         $ra, 0x10($sp)
    /* 37C4C 8004744C 00000000 */  nop
    /* 37C50 80047450 0800E003 */  jr         $ra
    /* 37C54 80047454 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80047430
