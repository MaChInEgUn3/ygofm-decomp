nonmatching func_800743F0, 0x30

glabel func_800743F0
    /* 64BF0 800743F0 0980023C */  lui        $v0, %hi(D_80092A88)
    /* 64BF4 800743F4 882A428C */  lw         $v0, %lo(D_80092A88)($v0)
    /* 64BF8 800743F8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 64BFC 800743FC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 64C00 80074400 0400428C */  lw         $v0, 0x4($v0)
    /* 64C04 80074404 00000000 */  nop
    /* 64C08 80074408 09F84000 */  jalr       $v0
    /* 64C0C 8007440C 00000000 */   nop
    /* 64C10 80074410 1000BF8F */  lw         $ra, 0x10($sp)
    /* 64C14 80074414 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 64C18 80074418 0800E003 */  jr         $ra
    /* 64C1C 8007441C 00000000 */   nop
endlabel func_800743F0
