nonmatching func_800151B0, 0x28

glabel func_800151B0
    /* 59B0 800151B0 0F80023C */  lui        $v0, %hi(D_800E9EC8)
    /* 59B4 800151B4 C89E4224 */  addiu      $v0, $v0, %lo(D_800E9EC8)
    /* 59B8 800151B8 08000324 */  addiu      $v1, $zero, 0x8
    /* 59BC 800151BC 060040A0 */  sb         $zero, 0x6($v0)
    /* 59C0 800151C0 040040A0 */  sb         $zero, 0x4($v0)
    /* 59C4 800151C4 050040A0 */  sb         $zero, 0x5($v0)
    /* 59C8 800151C8 070043A0 */  sb         $v1, 0x7($v0)
    /* 59CC 800151CC 3D0280A3 */  sb         $zero, %gp_rel(D_8009B145)($gp)
    /* 59D0 800151D0 0800E003 */  jr         $ra
    /* 59D4 800151D4 00000000 */   nop
endlabel func_800151B0
