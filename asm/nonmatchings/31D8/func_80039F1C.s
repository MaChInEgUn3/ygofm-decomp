nonmatching func_80039F1C, 0x28

glabel func_80039F1C
    /* 2A71C 80039F1C 33008390 */  lbu        $v1, 0x33($a0)
    /* 2A720 80039F20 00000000 */  nop
    /* 2A724 80039F24 80006230 */  andi       $v0, $v1, 0x80
    /* 2A728 80039F28 03004010 */  beqz       $v0, .L80039F38
    /* 2A72C 80039F2C 80006234 */   ori       $v0, $v1, 0x80
    /* 2A730 80039F30 0800E003 */  jr         $ra
    /* 2A734 80039F34 01000224 */   addiu     $v0, $zero, 0x1
  .L80039F38:
    /* 2A738 80039F38 330082A0 */  sb         $v0, 0x33($a0)
    /* 2A73C 80039F3C 0800E003 */  jr         $ra
    /* 2A740 80039F40 21100000 */   addu      $v0, $zero, $zero
endlabel func_80039F1C
