nonmatching func_80059A50, 0x58

glabel func_80059A50
    /* 4A250 80059A50 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 4A254 80059A54 3000BFAF */  sw         $ra, 0x30($sp)
    /* 4A258 80059A58 0000C38C */  lw         $v1, 0x0($a2)
    /* 4A25C 80059A5C 0400C78C */  lw         $a3, 0x4($a2)
    /* 4A260 80059A60 0800C88C */  lw         $t0, 0x8($a2)
    /* 4A264 80059A64 0C00C98C */  lw         $t1, 0xC($a2)
    /* 4A268 80059A68 1000A3AF */  sw         $v1, 0x10($sp)
    /* 4A26C 80059A6C 1400A7AF */  sw         $a3, 0x14($sp)
    /* 4A270 80059A70 1800A8AF */  sw         $t0, 0x18($sp)
    /* 4A274 80059A74 1C00A9AF */  sw         $t1, 0x1C($sp)
    /* 4A278 80059A78 1000C38C */  lw         $v1, 0x10($a2)
    /* 4A27C 80059A7C 1400C78C */  lw         $a3, 0x14($a2)
    /* 4A280 80059A80 1800C88C */  lw         $t0, 0x18($a2)
    /* 4A284 80059A84 2000A3AF */  sw         $v1, 0x20($sp)
    /* 4A288 80059A88 2400A7AF */  sw         $a3, 0x24($sp)
    /* 4A28C 80059A8C 2800A8AF */  sw         $t0, 0x28($sp)
    /* 4A290 80059A90 9F62010C */  jal        func_80058A7C
    /* 4A294 80059A94 1000A627 */   addiu     $a2, $sp, 0x10
    /* 4A298 80059A98 3000BF8F */  lw         $ra, 0x30($sp)
    /* 4A29C 80059A9C 00000000 */  nop
    /* 4A2A0 80059AA0 0800E003 */  jr         $ra
    /* 4A2A4 80059AA4 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_80059A50
