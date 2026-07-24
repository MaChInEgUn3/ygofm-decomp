nonmatching func_8008E6F0, 0x44

glabel func_8008E6F0
    /* 7EEF0 8008E6F0 0E008010 */  beqz       $a0, .L8008E72C
    /* 7EEF4 8008E6F4 21100000 */   addu      $v0, $zero, $zero
    /* 7EEF8 8008E6F8 0C00A010 */  beqz       $a1, .L8008E72C
    /* 7EEFC 8008E6FC 21188000 */   addu      $v1, $a0, $zero
    /* 7EF00 8008E700 0000A290 */  lbu        $v0, 0x0($a1)
    /* 7EF04 8008E704 0100A524 */  addiu      $a1, $a1, 0x1
    /* 7EF08 8008E708 01006424 */  addiu      $a0, $v1, 0x1
    /* 7EF0C 8008E70C 06004010 */  beqz       $v0, .L8008E728
    /* 7EF10 8008E710 000062A0 */   sb        $v0, 0x0($v1)
  .L8008E714:
    /* 7EF14 8008E714 0000A290 */  lbu        $v0, 0x0($a1)
    /* 7EF18 8008E718 0100A524 */  addiu      $a1, $a1, 0x1
    /* 7EF1C 8008E71C 000082A0 */  sb         $v0, 0x0($a0)
    /* 7EF20 8008E720 FCFF4014 */  bnez       $v0, .L8008E714
    /* 7EF24 8008E724 01008424 */   addiu     $a0, $a0, 0x1
  .L8008E728:
    /* 7EF28 8008E728 21106000 */  addu       $v0, $v1, $zero
  .L8008E72C:
    /* 7EF2C 8008E72C 0800E003 */  jr         $ra
    /* 7EF30 8008E730 00000000 */   nop
endlabel func_8008E6F0
    /* 7EF34 8008E734 00000000 */  nop
    /* 7EF38 8008E738 00000000 */  nop
    /* 7EF3C 8008E73C 00000000 */  nop
