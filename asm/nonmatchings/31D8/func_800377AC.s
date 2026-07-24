nonmatching func_800377AC, 0x1C

glabel func_800377AC
    /* 27FAC 800377AC 4F048293 */  lbu        $v0, %gp_rel(D_8009B357)($gp)
    /* 27FB0 800377B0 00000000 */  nop
    /* 27FB4 800377B4 02004014 */  bnez       $v0, .L800377C0
    /* 27FB8 800377B8 00000000 */   nop
    /* 27FBC 800377BC 510080A0 */  sb         $zero, 0x51($a0)
  .L800377C0:
    /* 27FC0 800377C0 0800E003 */  jr         $ra
    /* 27FC4 800377C4 00000000 */   nop
endlabel func_800377AC
