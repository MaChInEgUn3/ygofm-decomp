nonmatching func_80042B98, 0x28

glabel func_80042B98
    /* 33398 80042B98 6C008390 */  lbu        $v1, 0x6C($a0)
    /* 3339C 80042B9C 00000000 */  nop
    /* 333A0 80042BA0 80006230 */  andi       $v0, $v1, 0x80
    /* 333A4 80042BA4 03004010 */  beqz       $v0, .L80042BB4
    /* 333A8 80042BA8 80006234 */   ori       $v0, $v1, 0x80
    /* 333AC 80042BAC 0800E003 */  jr         $ra
    /* 333B0 80042BB0 01000224 */   addiu     $v0, $zero, 0x1
  .L80042BB4:
    /* 333B4 80042BB4 6C0082A0 */  sb         $v0, 0x6C($a0)
    /* 333B8 80042BB8 0800E003 */  jr         $ra
    /* 333BC 80042BBC 21100000 */   addu      $v0, $zero, $zero
endlabel func_80042B98
