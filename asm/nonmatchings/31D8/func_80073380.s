nonmatching func_80073380, 0x28

glabel func_80073380
    /* 63B80 80073380 1F000324 */  addiu      $v1, $zero, 0x1F
    /* 63B84 80073384 0F80023C */  lui        $v0, %hi(D_800F5BE8)
    /* 63B88 80073388 E85B4224 */  addiu      $v0, $v0, %lo(D_800F5BE8)
    /* 63B8C 8007338C 3E004224 */  addiu      $v0, $v0, 0x3E
  .L80073390:
    /* 63B90 80073390 3E0040A4 */  sh         $zero, 0x3E($v0)
    /* 63B94 80073394 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 63B98 80073398 FDFF6104 */  bgez       $v1, .L80073390
    /* 63B9C 8007339C FEFF4224 */   addiu     $v0, $v0, -0x2
    /* 63BA0 800733A0 0800E003 */  jr         $ra
    /* 63BA4 800733A4 00000000 */   nop
endlabel func_80073380
