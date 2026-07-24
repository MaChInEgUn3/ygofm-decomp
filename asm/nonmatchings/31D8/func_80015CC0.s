nonmatching func_80015CC0, 0x3C

glabel func_80015CC0
    /* 64C0 80015CC0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 64C4 80015CC4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 64C8 80015CC8 2E56000C */  jal        func_800158B8
    /* 64CC 80015CCC 00000000 */   nop
    /* 64D0 80015CD0 0F80033C */  lui        $v1, %hi(D_800E9EC8)
    /* 64D4 80015CD4 C89E6324 */  addiu      $v1, $v1, %lo(D_800E9EC8)
    /* 64D8 80015CD8 06006290 */  lbu        $v0, 0x6($v1)
    /* 64DC 80015CDC 00000000 */  nop
    /* 64E0 80015CE0 06004234 */  ori        $v0, $v0, 0x6
    /* 64E4 80015CE4 1C56000C */  jal        func_80015870
    /* 64E8 80015CE8 060062A0 */   sb        $v0, 0x6($v1)
    /* 64EC 80015CEC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 64F0 80015CF0 00000000 */  nop
    /* 64F4 80015CF4 0800E003 */  jr         $ra
    /* 64F8 80015CF8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80015CC0
