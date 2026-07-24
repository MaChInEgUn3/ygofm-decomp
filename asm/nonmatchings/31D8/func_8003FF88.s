nonmatching func_8003FF88, 0x2C

glabel func_8003FF88
    /* 30788 8003FF88 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3078C 8003FF8C FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 30790 8003FF90 00808434 */  ori        $a0, $a0, 0x8000
    /* 30794 8003FF94 FF000524 */  addiu      $a1, $zero, 0xFF
    /* 30798 8003FF98 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3079C 8003FF9C 9621010C */  jal        func_80048658
    /* 307A0 8003FFA0 21300000 */   addu      $a2, $zero, $zero
    /* 307A4 8003FFA4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 307A8 8003FFA8 00000000 */  nop
    /* 307AC 8003FFAC 0800E003 */  jr         $ra
    /* 307B0 8003FFB0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003FF88
