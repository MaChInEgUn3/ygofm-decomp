nonmatching func_8007D2D0, 0x1C

glabel func_8007D2D0
    /* 6DAD0 8007D2D0 0200822C */  sltiu      $v0, $a0, 0x2
    /* 6DAD4 8007D2D4 03004010 */  beqz       $v0, .L8007D2E4
    /* 6DAD8 8007D2D8 00000000 */   nop
    /* 6DADC 8007D2DC 0980013C */  lui        $at, %hi(D_800939E4)
    /* 6DAE0 8007D2E0 E43924AC */  sw         $a0, %lo(D_800939E4)($at)
  .L8007D2E4:
    /* 6DAE4 8007D2E4 0800E003 */  jr         $ra
    /* 6DAE8 8007D2E8 00000000 */   nop
endlabel func_8007D2D0
    /* 6DAEC 8007D2EC 00000000 */  nop
