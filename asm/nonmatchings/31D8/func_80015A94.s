nonmatching func_80015A94, 0x44

glabel func_80015A94
    /* 6294 80015A94 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6298 80015A98 1000BFAF */  sw         $ra, 0x10($sp)
    /* 629C 80015A9C E055000C */  jal        func_80015780
    /* 62A0 80015AA0 00000000 */   nop
    /* 62A4 80015AA4 0F80033C */  lui        $v1, %hi(D_800E9EC8)
    /* 62A8 80015AA8 C89E6324 */  addiu      $v1, $v1, %lo(D_800E9EC8)
    /* 62AC 80015AAC 06006290 */  lbu        $v0, 0x6($v1)
    /* 62B0 80015AB0 00000000 */  nop
    /* 62B4 80015AB4 06004234 */  ori        $v0, $v0, 0x6
    /* 62B8 80015AB8 CB55000C */  jal        func_8001572C
    /* 62BC 80015ABC 060062A0 */   sb        $v0, 0x6($v1)
    /* 62C0 80015AC0 6656000C */  jal        func_80015998
    /* 62C4 80015AC4 00000000 */   nop
    /* 62C8 80015AC8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 62CC 80015ACC 00000000 */  nop
    /* 62D0 80015AD0 0800E003 */  jr         $ra
    /* 62D4 80015AD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80015A94
