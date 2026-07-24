nonmatching func_80070988, 0x38

glabel func_80070988
    /* 61188 80070988 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6118C 8007098C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 61190 80070990 6BC1010C */  jal        func_800705AC
    /* 61194 80070994 00000000 */   nop
    /* 61198 80070998 0F80033C */  lui        $v1, %hi(D_800F5BE8)
    /* 6119C 8007099C E85B6324 */  addiu      $v1, $v1, %lo(D_800F5BE8)
    /* 611A0 800709A0 0400648C */  lw         $a0, 0x4($v1)
    /* 611A4 800709A4 00000000 */  nop
    /* 611A8 800709A8 21104400 */  addu       $v0, $v0, $a0
    /* 611AC 800709AC 080062AC */  sw         $v0, 0x8($v1)
    /* 611B0 800709B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 611B4 800709B4 00000000 */  nop
    /* 611B8 800709B8 0800E003 */  jr         $ra
    /* 611BC 800709BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80070988
