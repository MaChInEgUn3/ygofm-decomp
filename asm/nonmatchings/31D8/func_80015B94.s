nonmatching func_80015B94, 0x44

glabel func_80015B94
    /* 6394 80015B94 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6398 80015B98 1000BFAF */  sw         $ra, 0x10($sp)
    /* 639C 80015B9C 2E56000C */  jal        func_800158B8
    /* 63A0 80015BA0 00000000 */   nop
    /* 63A4 80015BA4 0F80033C */  lui        $v1, %hi(D_800E9EC8)
    /* 63A8 80015BA8 C89E6324 */  addiu      $v1, $v1, %lo(D_800E9EC8)
    /* 63AC 80015BAC 06006290 */  lbu        $v0, 0x6($v1)
    /* 63B0 80015BB0 00000000 */  nop
    /* 63B4 80015BB4 06004234 */  ori        $v0, $v0, 0x6
    /* 63B8 80015BB8 1C56000C */  jal        func_80015870
    /* 63BC 80015BBC 060062A0 */   sb        $v0, 0x6($v1)
    /* 63C0 80015BC0 6656000C */  jal        func_80015998
    /* 63C4 80015BC4 00000000 */   nop
    /* 63C8 80015BC8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 63CC 80015BCC 00000000 */  nop
    /* 63D0 80015BD0 0800E003 */  jr         $ra
    /* 63D4 80015BD4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80015B94
