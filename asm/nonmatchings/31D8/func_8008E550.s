nonmatching func_8008E550, 0x3C

glabel func_8008E550
    /* 7ED50 8008E550 21408000 */  addu       $t0, $a0, $zero
    /* 7ED54 8008E554 2148A000 */  addu       $t1, $a1, $zero
    /* 7ED58 8008E558 0A00C010 */  beqz       $a2, .L8008E584
    /* 7ED5C 8008E55C 21380000 */   addu      $a3, $zero, $zero
  .L8008E560:
    /* 7ED60 8008E560 21180701 */  addu       $v1, $t0, $a3
    /* 7ED64 8008E564 21202701 */  addu       $a0, $t1, $a3
    /* 7ED68 8008E568 00006590 */  lbu        $a1, 0x0($v1)
    /* 7ED6C 8008E56C 00008290 */  lbu        $v0, 0x0($a0)
    /* 7ED70 8008E570 0100E724 */  addiu      $a3, $a3, 0x1
    /* 7ED74 8008E574 000062A0 */  sb         $v0, 0x0($v1)
    /* 7ED78 8008E578 2B10E600 */  sltu       $v0, $a3, $a2
    /* 7ED7C 8008E57C F8FF4014 */  bnez       $v0, .L8008E560
    /* 7ED80 8008E580 000085A0 */   sb        $a1, 0x0($a0)
  .L8008E584:
    /* 7ED84 8008E584 0800E003 */  jr         $ra
    /* 7ED88 8008E588 00000000 */   nop
endlabel func_8008E550
    /* 7ED8C 8008E58C 00000000 */  nop
