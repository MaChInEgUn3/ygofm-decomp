nonmatching func_800744B4, 0x30

glabel func_800744B4
    /* 64CB4 800744B4 0980023C */  lui        $v0, %hi(D_80092A88)
    /* 64CB8 800744B8 882A428C */  lw         $v0, %lo(D_80092A88)($v0)
    /* 64CBC 800744BC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 64CC0 800744C0 1000BFAF */  sw         $ra, 0x10($sp)
    /* 64CC4 800744C4 1800428C */  lw         $v0, 0x18($v0)
    /* 64CC8 800744C8 00000000 */  nop
    /* 64CCC 800744CC 09F84000 */  jalr       $v0
    /* 64CD0 800744D0 00000000 */   nop
    /* 64CD4 800744D4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 64CD8 800744D8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 64CDC 800744DC 0800E003 */  jr         $ra
    /* 64CE0 800744E0 00000000 */   nop
endlabel func_800744B4
