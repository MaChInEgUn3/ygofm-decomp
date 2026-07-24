nonmatching func_800743C0, 0x30

glabel func_800743C0
    /* 64BC0 800743C0 0980023C */  lui        $v0, %hi(D_80092A88)
    /* 64BC4 800743C4 882A428C */  lw         $v0, %lo(D_80092A88)($v0)
    /* 64BC8 800743C8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 64BCC 800743CC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 64BD0 800743D0 0800428C */  lw         $v0, 0x8($v0)
    /* 64BD4 800743D4 00000000 */  nop
    /* 64BD8 800743D8 09F84000 */  jalr       $v0
    /* 64BDC 800743DC 00000000 */   nop
    /* 64BE0 800743E0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 64BE4 800743E4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 64BE8 800743E8 0800E003 */  jr         $ra
    /* 64BEC 800743EC 00000000 */   nop
endlabel func_800743C0
