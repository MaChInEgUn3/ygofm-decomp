nonmatching func_80015BF0, 0x1C

glabel func_80015BF0
    /* 63F0 80015BF0 0F80023C */  lui        $v0, %hi(D_800E9EC8)
    /* 63F4 80015BF4 C89E4224 */  addiu      $v0, $v0, %lo(D_800E9EC8)
    /* 63F8 80015BF8 80000324 */  addiu      $v1, $zero, 0x80
    /* 63FC 80015BFC 040044A0 */  sb         $a0, 0x4($v0)
    /* 6400 80015C00 050044A0 */  sb         $a0, 0x5($v0)
    /* 6404 80015C04 0800E003 */  jr         $ra
    /* 6408 80015C08 060043A0 */   sb        $v1, 0x6($v0)
endlabel func_80015BF0
