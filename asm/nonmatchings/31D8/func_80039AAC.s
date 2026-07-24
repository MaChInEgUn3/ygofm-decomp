nonmatching func_80039AAC, 0x28

glabel func_80039AAC
    /* 2A2AC 80039AAC 13008390 */  lbu        $v1, 0x13($a0)
    /* 2A2B0 80039AB0 00000000 */  nop
    /* 2A2B4 80039AB4 80006230 */  andi       $v0, $v1, 0x80
    /* 2A2B8 80039AB8 03004010 */  beqz       $v0, .L80039AC8
    /* 2A2BC 80039ABC 80006234 */   ori       $v0, $v1, 0x80
    /* 2A2C0 80039AC0 0800E003 */  jr         $ra
    /* 2A2C4 80039AC4 01000224 */   addiu     $v0, $zero, 0x1
  .L80039AC8:
    /* 2A2C8 80039AC8 130082A0 */  sb         $v0, 0x13($a0)
    /* 2A2CC 80039ACC 0800E003 */  jr         $ra
    /* 2A2D0 80039AD0 21100000 */   addu      $v0, $zero, $zero
endlabel func_80039AAC
