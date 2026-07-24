nonmatching func_8008B6F0, 0x34

glabel func_8008B6F0
    /* 7BEF0 8008B6F0 80DF0234 */  ori        $v0, $zero, 0xDF80
    /* 7BEF4 8008B6F4 09800A3C */  lui        $t2, %hi(func_8008B554)
    /* 7BEF8 8008B6F8 54B54A25 */  addiu      $t2, $t2, %lo(func_8008B554)
    /* 7BEFC 8008B6FC 0980093C */  lui        $t1, %hi(func_8008B5C4)
    /* 7BF00 8008B700 C4B52925 */  addiu      $t1, $t1, %lo(func_8008B5C4)
  .L8008B704:
    /* 7BF04 8008B704 0000438D */  lw         $v1, 0x0($t2)
    /* 7BF08 8008B708 00000000 */  nop
    /* 7BF0C 8008B70C 000043AC */  sw         $v1, 0x0($v0)
    /* 7BF10 8008B710 04004A25 */  addiu      $t2, $t2, 0x4
    /* 7BF14 8008B714 FBFF4915 */  bne        $t2, $t1, .L8008B704
    /* 7BF18 8008B718 04004224 */   addiu     $v0, $v0, 0x4
    /* 7BF1C 8008B71C 0800E003 */  jr         $ra
    /* 7BF20 8008B720 00000000 */   nop
endlabel func_8008B6F0
    /* 7BF24 8008B724 00000000 */  nop
    /* 7BF28 8008B728 00000000 */  nop
    /* 7BF2C 8008B72C 00000000 */  nop
