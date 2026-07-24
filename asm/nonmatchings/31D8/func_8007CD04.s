nonmatching func_8007CD04, 0x10

glabel func_8007CD04
    /* 6D504 8007CD04 01000224 */  addiu      $v0, $zero, 0x1
    /* 6D508 8007CD08 0980013C */  lui        $at, %hi(D_80093880)
    /* 6D50C 8007CD0C 0800E003 */  jr         $ra
    /* 6D510 8007CD10 803822AC */   sw        $v0, %lo(D_80093880)($at)
endlabel func_8007CD04
