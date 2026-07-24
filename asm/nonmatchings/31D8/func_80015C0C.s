nonmatching func_80015C0C, 0x3C

glabel func_80015C0C
    /* 640C 80015C0C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6410 80015C10 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6414 80015C14 E055000C */  jal        func_80015780
    /* 6418 80015C18 00000000 */   nop
    /* 641C 80015C1C 0F80033C */  lui        $v1, %hi(D_800E9EC8)
    /* 6420 80015C20 C89E6324 */  addiu      $v1, $v1, %lo(D_800E9EC8)
    /* 6424 80015C24 06006290 */  lbu        $v0, 0x6($v1)
    /* 6428 80015C28 00000000 */  nop
    /* 642C 80015C2C 02004234 */  ori        $v0, $v0, 0x2
    /* 6430 80015C30 CB55000C */  jal        func_8001572C
    /* 6434 80015C34 060062A0 */   sb        $v0, 0x6($v1)
    /* 6438 80015C38 1000BF8F */  lw         $ra, 0x10($sp)
    /* 643C 80015C3C 00000000 */  nop
    /* 6440 80015C40 0800E003 */  jr         $ra
    /* 6444 80015C44 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80015C0C
