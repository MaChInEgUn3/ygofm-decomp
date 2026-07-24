nonmatching func_8003FF58, 0x30

glabel func_8003FF58
    /* 30758 8003FF58 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3075C 8003FF5C 02008018 */  blez       $a0, .L8003FF68
    /* 30760 8003FF60 1000BFAF */   sw        $ra, 0x10($sp)
    /* 30764 8003FF64 23200400 */  negu       $a0, $a0
  .L8003FF68:
    /* 30768 8003FF68 00240400 */  sll        $a0, $a0, 16
    /* 3076C 8003FF6C 03240400 */  sra        $a0, $a0, 16
    /* 30770 8003FF70 0C1D010C */  jal        func_80047430
    /* 30774 8003FF74 21280000 */   addu      $a1, $zero, $zero
    /* 30778 8003FF78 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3077C 8003FF7C 00000000 */  nop
    /* 30780 8003FF80 0800E003 */  jr         $ra
    /* 30784 8003FF84 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003FF58
