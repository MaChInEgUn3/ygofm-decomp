nonmatching func_800716C4, 0x3C

glabel func_800716C4
    /* 61EC4 800716C4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 61EC8 800716C8 1000BFAF */  sw         $ra, 0x10($sp)
    /* 61ECC 800716CC 63C1010C */  jal        func_8007058C
    /* 61ED0 800716D0 00000000 */   nop
    /* 61ED4 800716D4 0F80043C */  lui        $a0, %hi(D_800F5B98)
    /* 61ED8 800716D8 985B8424 */  addiu      $a0, $a0, %lo(D_800F5B98)
    /* 61EDC 800716DC 80100200 */  sll        $v0, $v0, 2
    /* 61EE0 800716E0 0F80033C */  lui        $v1, %hi(D_800F5C83)
    /* 61EE4 800716E4 835C6390 */  lbu        $v1, %lo(D_800F5C83)($v1)
    /* 61EE8 800716E8 21104400 */  addu       $v0, $v0, $a0
    /* 61EEC 800716EC 000043AC */  sw         $v1, 0x0($v0)
    /* 61EF0 800716F0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 61EF4 800716F4 00000000 */  nop
    /* 61EF8 800716F8 0800E003 */  jr         $ra
    /* 61EFC 800716FC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800716C4
