nonmatching func_80015C48, 0x3C

glabel func_80015C48
    /* 6448 80015C48 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 644C 80015C4C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6450 80015C50 E055000C */  jal        func_80015780
    /* 6454 80015C54 00000000 */   nop
    /* 6458 80015C58 0F80033C */  lui        $v1, %hi(D_800E9EC8)
    /* 645C 80015C5C C89E6324 */  addiu      $v1, $v1, %lo(D_800E9EC8)
    /* 6460 80015C60 06006290 */  lbu        $v0, 0x6($v1)
    /* 6464 80015C64 00000000 */  nop
    /* 6468 80015C68 06004234 */  ori        $v0, $v0, 0x6
    /* 646C 80015C6C CB55000C */  jal        func_8001572C
    /* 6470 80015C70 060062A0 */   sb        $v0, 0x6($v1)
    /* 6474 80015C74 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6478 80015C78 00000000 */  nop
    /* 647C 80015C7C 0800E003 */  jr         $ra
    /* 6480 80015C80 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80015C48
