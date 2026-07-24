nonmatching func_8008B8CC, 0x40

glabel func_8008B8CC
    /* 7C0CC 8008B8CC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7C0D0 8008B8D0 1080033C */  lui        $v1, %hi(D_800FE348)
    /* 7C0D4 8008B8D4 48E36324 */  addiu      $v1, $v1, %lo(D_800FE348)
    /* 7C0D8 8008B8D8 1000BFAF */  sw         $ra, 0x10($sp)
  .L8008B8DC:
    /* 7C0DC 8008B8DC 0000628C */  lw         $v0, 0x0($v1)
    /* 7C0E0 8008B8E0 00000000 */  nop
    /* 7C0E4 8008B8E4 FDFF4014 */  bnez       $v0, .L8008B8DC
    /* 7C0E8 8008B8E8 07000424 */   addiu     $a0, $zero, 0x7
    /* 7C0EC 8008B8EC 15D1010C */  jal        func_80074454
    /* 7C0F0 8008B8F0 21280000 */   addu      $a1, $zero, $zero
    /* 7C0F4 8008B8F4 2B35020C */  jal        func_8008D4AC
    /* 7C0F8 8008B8F8 00000000 */   nop
    /* 7C0FC 8008B8FC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7C100 8008B900 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7C104 8008B904 0800E003 */  jr         $ra
    /* 7C108 8008B908 00000000 */   nop
endlabel func_8008B8CC
