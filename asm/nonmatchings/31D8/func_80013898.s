nonmatching func_80013898, 0x5C

glabel func_80013898
    /* 4098 80013898 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 409C 8001389C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 40A0 800138A0 100284AF */  sw         $a0, %gp_rel(D_8009B118)($gp)
    /* 40A4 800138A4 080280A3 */  sb         $zero, %gp_rel(D_8009B110)($gp)
    /* 40A8 800138A8 000280A3 */  sb         $zero, %gp_rel(D_8009B108)($gp)
    /* 40AC 800138AC EC0180AF */  sw         $zero, %gp_rel(D_8009B0F4)($gp)
    /* 40B0 800138B0 180280AF */  sw         $zero, %gp_rel(D_8009B120)($gp)
    /* 40B4 800138B4 E80180AF */  sw         $zero, %gp_rel(D_8009B0F0)($gp)
    /* 40B8 800138B8 2C0280AF */  sw         $zero, %gp_rel(D_8009B134)($gp)
    /* 40BC 800138BC 0A0280A7 */  sh         $zero, %gp_rel(D_8009B112)($gp)
    /* 40C0 800138C0 040280AF */  sw         $zero, %gp_rel(D_8009B10C)($gp)
    /* 40C4 800138C4 240280AF */  sw         $zero, %gp_rel(D_8009B12C)($gp)
    /* 40C8 800138C8 1C0280A7 */  sh         $zero, %gp_rel(D_8009B124)($gp)
    /* 40CC 800138CC E00180AF */  sw         $zero, %gp_rel(D_8009B0E8)($gp)
    /* 40D0 800138D0 280280AF */  sw         $zero, %gp_rel(D_8009B130)($gp)
  .L800138D4:
    /* 40D4 800138D4 E9EB010C */  jal        func_8007AFA4
    /* 40D8 800138D8 00000000 */   nop
    /* 40DC 800138DC FDFF4010 */  beqz       $v0, .L800138D4
    /* 40E0 800138E0 01000224 */   addiu     $v0, $zero, 0x1
    /* 40E4 800138E4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 40E8 800138E8 F40182AF */  sw         $v0, %gp_rel(D_8009B0FC)($gp)
    /* 40EC 800138EC 0800E003 */  jr         $ra
    /* 40F0 800138F0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80013898
