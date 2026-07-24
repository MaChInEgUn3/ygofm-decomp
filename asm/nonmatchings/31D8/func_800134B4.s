nonmatching func_800134B4, 0x2C

glabel func_800134B4
    /* 3CB4 800134B4 03000324 */  addiu      $v1, $zero, 0x3
    /* 3CB8 800134B8 0F80023C */  lui        $v0, %hi(D_800E9DB0)
    /* 3CBC 800134BC B09D4224 */  addiu      $v0, $v0, %lo(D_800E9DB0)
    /* 3CC0 800134C0 0C004224 */  addiu      $v0, $v0, 0xC
  .L800134C4:
    /* 3CC4 800134C4 000040AC */  sw         $zero, 0x0($v0)
    /* 3CC8 800134C8 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 3CCC 800134CC FDFF6104 */  bgez       $v1, .L800134C4
    /* 3CD0 800134D0 FCFF4224 */   addiu     $v0, $v0, -0x4
    /* 3CD4 800134D4 B00180AF */  sw         $zero, %gp_rel(D_8009B0B8)($gp)
    /* 3CD8 800134D8 0800E003 */  jr         $ra
    /* 3CDC 800134DC 00000000 */   nop
endlabel func_800134B4
