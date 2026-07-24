nonmatching func_8008E360, 0x30

glabel func_8008E360
    /* 7EB60 8008E360 09008010 */  beqz       $a0, .L8008E388
    /* 7EB64 8008E364 21100000 */   addu      $v0, $zero, $zero
    /* 7EB68 8008E368 0300A01C */  bgtz       $a1, .L8008E378
    /* 7EB6C 8008E36C 21108000 */   addu      $v0, $a0, $zero
    /* 7EB70 8008E370 E2380208 */  j          .L8008E388
    /* 7EB74 8008E374 21100000 */   addu      $v0, $zero, $zero
  .L8008E378:
    /* 7EB78 8008E378 000080A0 */  sb         $zero, 0x0($a0)
    /* 7EB7C 8008E37C FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 7EB80 8008E380 FDFFA01C */  bgtz       $a1, .L8008E378
    /* 7EB84 8008E384 01008424 */   addiu     $a0, $a0, 0x1
  .L8008E388:
    /* 7EB88 8008E388 0800E003 */  jr         $ra
    /* 7EB8C 8008E38C 00000000 */   nop
endlabel func_8008E360
