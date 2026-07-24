nonmatching func_80035CE4, 0x2C

glabel func_80035CE4
    /* 264E4 80035CE4 0F80023C */  lui        $v0, %hi(D_800EAF08)
    /* 264E8 80035CE8 08AF4224 */  addiu      $v0, $v0, %lo(D_800EAF08)
    /* 264EC 80035CEC EF000324 */  addiu      $v1, $zero, 0xEF
  .L80035CF0:
    /* 264F0 80035CF0 000040A0 */  sb         $zero, 0x0($v0)
    /* 264F4 80035CF4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 264F8 80035CF8 FDFF6104 */  bgez       $v1, .L80035CF0
    /* 264FC 80035CFC 01004224 */   addiu     $v0, $v0, 0x1
    /* 26500 80035D00 1C0480A3 */  sb         $zero, %gp_rel(D_8009B324)($gp)
    /* 26504 80035D04 1D0480A3 */  sb         $zero, %gp_rel(D_8009B325)($gp)
    /* 26508 80035D08 0800E003 */  jr         $ra
    /* 2650C 80035D0C 00000000 */   nop
endlabel func_80035CE4
