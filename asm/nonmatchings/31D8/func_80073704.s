nonmatching func_80073704, 0x20

glabel func_80073704
    /* 63F04 80073704 2130A000 */  addu       $a2, $a1, $zero
    /* 63F08 80073708 21288000 */  addu       $a1, $a0, $zero
    /* 63F0C 8007370C CD400000 */  break      0, 259
    /* 63F10 80073710 02004010 */  beqz       $v0, .L8007371C
    /* 63F14 80073714 21106000 */   addu      $v0, $v1, $zero
    /* 63F18 80073718 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8007371C:
    /* 63F1C 8007371C 0800E003 */  jr         $ra
    /* 63F20 80073720 00000000 */   nop
endlabel func_80073704
