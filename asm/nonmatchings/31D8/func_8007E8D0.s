nonmatching func_8007E8D0, 0x40

glabel func_8007E8D0
    /* 6F0D0 8007E8D0 0D008004 */  bltz       $a0, .L8007E908
    /* 6F0D4 8007E8D4 00000000 */   nop
    /* 6F0D8 8007E8D8 0980023C */  lui        $v0, %hi(D_80093C08)
    /* 6F0DC 8007E8DC 083C428C */  lw         $v0, %lo(D_80093C08)($v0)
    /* 6F0E0 8007E8E0 00000000 */  nop
    /* 6F0E4 8007E8E4 2A104400 */  slt        $v0, $v0, $a0
    /* 6F0E8 8007E8E8 07004014 */  bnez       $v0, .L8007E908
    /* 6F0EC 8007E8EC 00000000 */   nop
    /* 6F0F0 8007E8F0 0880023C */  lui        $v0, %hi(func_8007EF84)
    /* 6F0F4 8007E8F4 84EF4224 */  addiu      $v0, $v0, %lo(func_8007EF84)
    /* 6F0F8 8007E8F8 0980013C */  lui        $at, %hi(D_80093C0C)
    /* 6F0FC 8007E8FC 0C3C24AC */  sw         $a0, %lo(D_80093C0C)($at)
    /* 6F100 8007E900 0980013C */  lui        $at, %hi(D_80094664)
    /* 6F104 8007E904 644622AC */  sw         $v0, %lo(D_80094664)($at)
  .L8007E908:
    /* 6F108 8007E908 0800E003 */  jr         $ra
    /* 6F10C 8007E90C 00000000 */   nop
endlabel func_8007E8D0
