nonmatching func_80059C88, 0x14

glabel func_80059C88
    /* 4A488 80059C88 92008283 */  lb         $v0, %gp_rel(D_8009AF9A)($gp)
    /* 4A48C 80059C8C FEFF0324 */  addiu      $v1, $zero, -0x2
    /* 4A490 80059C90 26104300 */  xor        $v0, $v0, $v1
    /* 4A494 80059C94 0800E003 */  jr         $ra
    /* 4A498 80059C98 0100422C */   sltiu     $v0, $v0, 0x1
endlabel func_80059C88
