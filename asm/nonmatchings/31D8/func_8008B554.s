nonmatching func_8008B554, 0x2C

glabel func_8008B554
    /* 7BD54 8008B554 0A006F94 */  lhu        $t7, 0xA($v1)
    /* 7BD58 8008B558 0000083C */  lui        $t0, (0x0 >> 16)
    /* 7BD5C 8008B55C 25C0E201 */  or         $t8, $t7, $v0
    /* 7BD60 8008B560 12001937 */  ori        $t9, $t8, 0x12
    /* 7BD64 8008B564 0A0079A4 */  sh         $t9, 0xA($v1)
    /* 7BD68 8008B568 28000824 */  addiu      $t0, $zero, 0x28
  .L8008B56C:
    /* 7BD6C 8008B56C FFFF0825 */  addiu      $t0, $t0, -0x1
    /* 7BD70 8008B570 FEFF0015 */  bnez       $t0, .L8008B56C
    /* 7BD74 8008B574 00000000 */   nop
    /* 7BD78 8008B578 0800E003 */  jr         $ra
    /* 7BD7C 8008B57C 00000000 */   nop
endlabel func_8008B554
