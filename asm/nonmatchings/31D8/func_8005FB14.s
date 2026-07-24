nonmatching func_8005FB14, 0x1C

glabel func_8005FB14
    /* 50314 8005FB14 70018293 */  lbu        $v0, %gp_rel(D_8009B078)($gp)
    /* 50318 8005FB18 00000000 */  nop
    /* 5031C 8005FB1C 02004010 */  beqz       $v0, .L8005FB28
    /* 50320 8005FB20 21180000 */   addu      $v1, $zero, $zero
    /* 50324 8005FB24 6C01838F */  lw         $v1, %gp_rel(D_8009B074)($gp)
  .L8005FB28:
    /* 50328 8005FB28 0800E003 */  jr         $ra
    /* 5032C 8005FB2C 21106000 */   addu      $v0, $v1, $zero
endlabel func_8005FB14
