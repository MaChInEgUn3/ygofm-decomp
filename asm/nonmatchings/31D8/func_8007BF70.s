nonmatching func_8007BF70, 0x40

glabel func_8007BF70
    /* 6C770 8007BF70 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C774 8007BF74 0980033C */  lui        $v1, %hi(D_800938C4)
    /* 6C778 8007BF78 C4386324 */  addiu      $v1, $v1, %lo(D_800938C4)
    /* 6C77C 8007BF7C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6C780 8007BF80 0000628C */  lw         $v0, 0x0($v1)
    /* 6C784 8007BF84 00000000 */  nop
    /* 6C788 8007BF88 0500401C */  bgtz       $v0, .L8007BFA0
    /* 6C78C 8007BF8C 21100000 */   addu      $v0, $zero, $zero
    /* 6C790 8007BF90 20000224 */  addiu      $v0, $zero, 0x20
    /* 6C794 8007BF94 D8FF62AC */  sw         $v0, -0x28($v1)
    /* 6C798 8007BF98 ECEF010C */  jal        func_8007BFB0
    /* 6C79C 8007BF9C FF008430 */   andi      $a0, $a0, 0xFF
  .L8007BFA0:
    /* 6C7A0 8007BFA0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6C7A4 8007BFA4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6C7A8 8007BFA8 0800E003 */  jr         $ra
    /* 6C7AC 8007BFAC 00000000 */   nop
endlabel func_8007BF70
