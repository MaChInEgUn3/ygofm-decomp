nonmatching func_80071688, 0x3C

glabel func_80071688
    /* 61E88 80071688 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 61E8C 8007168C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 61E90 80071690 63C1010C */  jal        func_8007058C
    /* 61E94 80071694 00000000 */   nop
    /* 61E98 80071698 0F80043C */  lui        $a0, %hi(D_800F5B98)
    /* 61E9C 8007169C 985B8424 */  addiu      $a0, $a0, %lo(D_800F5B98)
    /* 61EA0 800716A0 80100200 */  sll        $v0, $v0, 2
    /* 61EA4 800716A4 0F80033C */  lui        $v1, %hi(D_800F5C82)
    /* 61EA8 800716A8 825C6390 */  lbu        $v1, %lo(D_800F5C82)($v1)
    /* 61EAC 800716AC 21104400 */  addu       $v0, $v0, $a0
    /* 61EB0 800716B0 000043AC */  sw         $v1, 0x0($v0)
    /* 61EB4 800716B4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 61EB8 800716B8 00000000 */  nop
    /* 61EBC 800716BC 0800E003 */  jr         $ra
    /* 61EC0 800716C0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80071688
