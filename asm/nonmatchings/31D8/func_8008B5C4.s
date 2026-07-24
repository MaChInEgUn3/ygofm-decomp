nonmatching func_8008B5C4, 0x24

glabel func_8008B5C4
    /* 7BDC4 8008B5C4 01A0023C */  lui        $v0, %hi(D_A000DFAC)
    /* 7BDC8 8008B5C8 ACDF4224 */  addiu      $v0, $v0, %lo(D_A000DFAC)
    /* 7BDCC 8008B5CC 08004000 */  jr         $v0
    /* 7BDD0 8008B5D0 00000000 */   nop
    /* 7BDD4 8008B5D4 00000000 */  nop
    /* 7BDD8 8008B5D8 01A0083C */  lui        $t0, %hi(D_A000DF80)
    /* 7BDDC 8008B5DC 80DF0825 */  addiu      $t0, $t0, %lo(D_A000DF80)
    /* 7BDE0 8008B5E0 09F80001 */  jalr       $t0
    /* 7BDE4 8008B5E4 00000000 */   nop
endlabel func_8008B5C4
    /* 7BDE8 8008B5E8 00000000 */  nop
