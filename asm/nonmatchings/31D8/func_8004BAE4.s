nonmatching func_8004BAE4, 0x50

glabel func_8004BAE4
    /* 3C2E4 8004BAE4 21288000 */  addu       $a1, $a0, $zero
    /* 3C2E8 8004BAE8 0A80043C */  lui        $a0, %hi(D_8009B458)
    /* 3C2EC 8004BAEC 58B4848C */  lw         $a0, %lo(D_8009B458)($a0)
    /* 3C2F0 8004BAF0 0000A38C */  lw         $v1, 0x0($a1)
    /* 3C2F4 8004BAF4 DC07828C */  lw         $v0, 0x7DC($a0)
    /* 3C2F8 8004BAF8 00000000 */  nop
    /* 3C2FC 8004BAFC 21104300 */  addu       $v0, $v0, $v1
    /* 3C300 8004BB00 00004690 */  lbu        $a2, 0x0($v0)
    /* 3C304 8004BB04 01006324 */  addiu      $v1, $v1, 0x1
    /* 3C308 8004BB08 0000A3AC */  sw         $v1, 0x0($a1)
    /* 3C30C 8004BB0C EC07828C */  lw         $v0, 0x7EC($a0)
    /* 3C310 8004BB10 00000000 */  nop
    /* 3C314 8004BB14 2B104300 */  sltu       $v0, $v0, $v1
    /* 3C318 8004BB18 03004014 */  bnez       $v0, .L8004BB28
    /* 3C31C 8004BB1C 01000224 */   addiu     $v0, $zero, 0x1
    /* 3C320 8004BB20 0800E003 */  jr         $ra
    /* 3C324 8004BB24 2110C000 */   addu      $v0, $a2, $zero
  .L8004BB28:
    /* 3C328 8004BB28 2400A2A0 */  sb         $v0, 0x24($a1)
    /* 3C32C 8004BB2C 0800E003 */  jr         $ra
    /* 3C330 8004BB30 FFFF0224 */   addiu     $v0, $zero, -0x1
endlabel func_8004BAE4
