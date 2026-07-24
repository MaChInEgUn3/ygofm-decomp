nonmatching func_800440B4, 0x3C

glabel func_800440B4
    /* 348B4 800440B4 36058283 */  lb         $v0, %gp_rel(D_8009B43E)($gp)
    /* 348B8 800440B8 00000000 */  nop
    /* 348BC 800440BC 0A004104 */  bgez       $v0, .L800440E8
    /* 348C0 800440C0 0A000324 */   addiu     $v1, $zero, 0xA
    /* 348C4 800440C4 340583A3 */  sb         $v1, %gp_rel(D_8009B43C)($gp)
    /* 348C8 800440C8 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 348CC 800440CC 2F0584A3 */  sb         $a0, %gp_rel(D_8009B437)($gp)
    /* 348D0 800440D0 360585A3 */  sb         $a1, %gp_rel(D_8009B43E)($gp)
    /* 348D4 800440D4 470580A3 */  sb         $zero, %gp_rel(D_8009B44F)($gp)
    /* 348D8 800440D8 350580A3 */  sb         $zero, %gp_rel(D_8009B43D)($gp)
    /* 348DC 800440DC 480583AF */  sw         $v1, %gp_rel(D_8009B450)($gp)
    /* 348E0 800440E0 0800E003 */  jr         $ra
    /* 348E4 800440E4 01000224 */   addiu     $v0, $zero, 0x1
  .L800440E8:
    /* 348E8 800440E8 0800E003 */  jr         $ra
    /* 348EC 800440EC 21100000 */   addu      $v0, $zero, $zero
endlabel func_800440B4
