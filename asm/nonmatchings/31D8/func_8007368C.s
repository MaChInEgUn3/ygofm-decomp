nonmatching func_8007368C, 0x38

glabel func_8007368C
    /* 63E8C 8007368C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 63E90 80073690 1000BFAF */  sw         $ra, 0x10($sp)
    /* 63E94 80073694 63C1010C */  jal        func_8007058C
    /* 63E98 80073698 00000000 */   nop
    /* 63E9C 8007369C 0F80033C */  lui        $v1, %hi(D_800F5B98)
    /* 63EA0 800736A0 985B6324 */  addiu      $v1, $v1, %lo(D_800F5B98)
    /* 63EA4 800736A4 80100200 */  sll        $v0, $v0, 2
    /* 63EA8 800736A8 21104300 */  addu       $v0, $v0, $v1
    /* 63EAC 800736AC 00004390 */  lbu        $v1, 0x0($v0)
    /* 63EB0 800736B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 63EB4 800736B4 0F80023C */  lui        $v0, %hi(D_800EAE8F)
    /* 63EB8 800736B8 8FAE43A0 */  sb         $v1, %lo(D_800EAE8F)($v0)
    /* 63EBC 800736BC 0800E003 */  jr         $ra
    /* 63EC0 800736C0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007368C
