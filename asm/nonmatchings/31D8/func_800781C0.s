nonmatching func_800781C0, 0x2C

glabel func_800781C0
    /* 689C0 800781C0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 689C4 800781C4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 689C8 800781C8 0F80013C */  lui        $at, %hi(D_800F5D78)
    /* 689CC 800781CC 785D24AC */  sw         $a0, %lo(D_800F5D78)($at)
    /* 689D0 800781D0 0F80013C */  lui        $at, %hi(D_800F5D7C)
    /* 689D4 800781D4 9CE0010C */  jal        func_80078270
    /* 689D8 800781D8 7C5D25AC */   sw        $a1, %lo(D_800F5D7C)($at)
    /* 689DC 800781DC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 689E0 800781E0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 689E4 800781E4 0800E003 */  jr         $ra
    /* 689E8 800781E8 00000000 */   nop
endlabel func_800781C0
    /* 689EC 800781EC 00000000 */  nop
