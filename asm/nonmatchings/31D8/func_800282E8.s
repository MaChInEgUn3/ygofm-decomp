nonmatching func_800282E8, 0x28

glabel func_800282E8
    /* 18AE8 800282E8 40038393 */  lbu        $v1, %gp_rel(D_8009B248)($gp)
    /* 18AEC 800282EC 00000000 */  nop
    /* 18AF0 800282F0 80006230 */  andi       $v0, $v1, 0x80
    /* 18AF4 800282F4 03004010 */  beqz       $v0, .L80028304
    /* 18AF8 800282F8 80006234 */   ori       $v0, $v1, 0x80
    /* 18AFC 800282FC 0800E003 */  jr         $ra
    /* 18B00 80028300 01000224 */   addiu     $v0, $zero, 0x1
  .L80028304:
    /* 18B04 80028304 400382A3 */  sb         $v0, %gp_rel(D_8009B248)($gp)
    /* 18B08 80028308 0800E003 */  jr         $ra
    /* 18B0C 8002830C 21100000 */   addu      $v0, $zero, $zero
endlabel func_800282E8
