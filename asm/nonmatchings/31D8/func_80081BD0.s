nonmatching func_80081BD0, 0x34

glabel func_80081BD0
    /* 723D0 80081BD0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 723D4 80081BD4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 723D8 80081BD8 5CD0010C */  jal        func_80074170
    /* 723DC 80081BDC FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 723E0 80081BE0 F0004224 */  addiu      $v0, $v0, 0xF0
    /* 723E4 80081BE4 0980013C */  lui        $at, %hi(D_800947A4)
    /* 723E8 80081BE8 A44722AC */  sw         $v0, %lo(D_800947A4)($at)
    /* 723EC 80081BEC 0980013C */  lui        $at, %hi(D_800947A8)
    /* 723F0 80081BF0 A84720AC */  sw         $zero, %lo(D_800947A8)($at)
    /* 723F4 80081BF4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 723F8 80081BF8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 723FC 80081BFC 0800E003 */  jr         $ra
    /* 72400 80081C00 00000000 */   nop
endlabel func_80081BD0
