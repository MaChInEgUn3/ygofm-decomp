nonmatching func_80074484, 0x30

glabel func_80074484
    /* 64C84 80074484 0980023C */  lui        $v0, %hi(D_80092A88)
    /* 64C88 80074488 882A428C */  lw         $v0, %lo(D_80092A88)($v0)
    /* 64C8C 8007448C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 64C90 80074490 1000BFAF */  sw         $ra, 0x10($sp)
    /* 64C94 80074494 1000428C */  lw         $v0, 0x10($v0)
    /* 64C98 80074498 00000000 */  nop
    /* 64C9C 8007449C 09F84000 */  jalr       $v0
    /* 64CA0 800744A0 00000000 */   nop
    /* 64CA4 800744A4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 64CA8 800744A8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 64CAC 800744AC 0800E003 */  jr         $ra
    /* 64CB0 800744B0 00000000 */   nop
endlabel func_80074484
