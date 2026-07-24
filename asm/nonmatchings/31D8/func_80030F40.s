nonmatching func_80030F40, 0x40

glabel func_80030F40
    /* 21740 80030F40 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 21744 80030F44 D0710224 */  addiu      $v0, $zero, 0x71D0
    /* 21748 80030F48 FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 2174C 80030F4C 01000524 */  addiu      $a1, $zero, 0x1
    /* 21750 80030F50 00800634 */  ori        $a2, $zero, 0x8000
    /* 21754 80030F54 1000BFAF */  sw         $ra, 0x10($sp)
    /* 21758 80030F58 0A80013C */  lui        $at, %hi(D_8009B36A)
    /* 2175C 80030F5C 6AB322A4 */  sh         $v0, %lo(D_8009B36A)($at)
    /* 21760 80030F60 0A80013C */  lui        $at, %hi(D_8009B368)
    /* 21764 80030F64 68B320A0 */  sb         $zero, %lo(D_8009B368)($at)
    /* 21768 80030F68 7293000C */  jal        func_80024DC8
    /* 2176C 80030F6C 2138C000 */   addu      $a3, $a2, $zero
    /* 21770 80030F70 1000BF8F */  lw         $ra, 0x10($sp)
    /* 21774 80030F74 00000000 */  nop
    /* 21778 80030F78 0800E003 */  jr         $ra
    /* 2177C 80030F7C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80030F40
