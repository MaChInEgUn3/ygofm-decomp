nonmatching func_80073734, 0x24

glabel func_80073734
    /* 63F34 80073734 2138C000 */  addu       $a3, $a2, $zero
    /* 63F38 80073738 2130A000 */  addu       $a2, $a1, $zero
    /* 63F3C 8007373C 21288000 */  addu       $a1, $a0, $zero
    /* 63F40 80073740 CD410000 */  break      0, 263
    /* 63F44 80073744 02004010 */  beqz       $v0, .L80073750
    /* 63F48 80073748 21106000 */   addu      $v0, $v1, $zero
    /* 63F4C 8007374C FFFF0224 */  addiu      $v0, $zero, -0x1
  .L80073750:
    /* 63F50 80073750 0800E003 */  jr         $ra
    /* 63F54 80073754 00000000 */   nop
endlabel func_80073734
