nonmatching func_80059CD0, 0x14

glabel func_80059CD0
    /* 4A4D0 80059CD0 92008283 */  lb         $v0, %gp_rel(D_8009AF9A)($gp)
    /* 4A4D4 80059CD4 FEFF0324 */  addiu      $v1, $zero, -0x2
    /* 4A4D8 80059CD8 26104300 */  xor        $v0, $v0, $v1
    /* 4A4DC 80059CDC 0800E003 */  jr         $ra
    /* 4A4E0 80059CE0 0100422C */   sltiu     $v0, $v0, 0x1
endlabel func_80059CD0
