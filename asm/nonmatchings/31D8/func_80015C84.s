nonmatching func_80015C84, 0x3C

glabel func_80015C84
    /* 6484 80015C84 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6488 80015C88 1000BFAF */  sw         $ra, 0x10($sp)
    /* 648C 80015C8C 2E56000C */  jal        func_800158B8
    /* 6490 80015C90 00000000 */   nop
    /* 6494 80015C94 0F80033C */  lui        $v1, %hi(D_800E9EC8)
    /* 6498 80015C98 C89E6324 */  addiu      $v1, $v1, %lo(D_800E9EC8)
    /* 649C 80015C9C 06006290 */  lbu        $v0, 0x6($v1)
    /* 64A0 80015CA0 00000000 */  nop
    /* 64A4 80015CA4 02004234 */  ori        $v0, $v0, 0x2
    /* 64A8 80015CA8 1C56000C */  jal        func_80015870
    /* 64AC 80015CAC 060062A0 */   sb        $v0, 0x6($v1)
    /* 64B0 80015CB0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 64B4 80015CB4 00000000 */  nop
    /* 64B8 80015CB8 0800E003 */  jr         $ra
    /* 64BC 80015CBC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80015C84
