nonmatching func_8002EE20, 0x3C

glabel func_8002EE20
    /* 1F620 8002EE20 8803828F */  lw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1F624 8002EE24 00000000 */  nop
    /* 1F628 8002EE28 02004324 */  addiu      $v1, $v0, 0x2
    /* 1F62C 8002EE2C 880383AF */  sw         $v1, %gp_rel(D_8009B290)($gp)
    /* 1F630 8002EE30 00004390 */  lbu        $v1, 0x0($v0)
    /* 1F634 8002EE34 01004290 */  lbu        $v0, 0x1($v0)
    /* 1F638 8002EE38 740380A7 */  sh         $zero, %gp_rel(D_8009B27C)($gp)
    /* 1F63C 8002EE3C 00120200 */  sll        $v0, $v0, 8
    /* 1F640 8002EE40 25186200 */  or         $v1, $v1, $v0
    /* 1F644 8002EE44 1B80023C */  lui        $v0, %hi(D_801A8000)
    /* 1F648 8002EE48 00804224 */  addiu      $v0, $v0, %lo(D_801A8000)
    /* 1F64C 8002EE4C 21186200 */  addu       $v1, $v1, $v0
    /* 1F650 8002EE50 880383AF */  sw         $v1, %gp_rel(D_8009B290)($gp)
    /* 1F654 8002EE54 0800E003 */  jr         $ra
    /* 1F658 8002EE58 00000000 */   nop
endlabel func_8002EE20
