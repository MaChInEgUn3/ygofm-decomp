nonmatching func_8003FFFC, 0x30

glabel func_8003FFFC
    /* 307FC 8003FFFC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 30800 80040000 1000BFAF */  sw         $ra, 0x10($sp)
    /* 30804 80040004 F31C010C */  jal        func_800473CC
    /* 30808 80040008 21200000 */   addu      $a0, $zero, $zero
    /* 3080C 8004000C F31C010C */  jal        func_800473CC
    /* 30810 80040010 00800434 */   ori       $a0, $zero, 0x8000
    /* 30814 80040014 B11F010C */  jal        func_80047EC4
    /* 30818 80040018 00000000 */   nop
    /* 3081C 8004001C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 30820 80040020 00000000 */  nop
    /* 30824 80040024 0800E003 */  jr         $ra
    /* 30828 80040028 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003FFFC
