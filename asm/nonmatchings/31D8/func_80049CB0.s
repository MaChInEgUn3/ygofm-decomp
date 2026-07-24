nonmatching func_80049CB0, 0x48

glabel func_80049CB0
    /* 3A4B0 80049CB0 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3A4B4 80049CB4 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3A4B8 80049CB8 00000000 */  nop
    /* 3A4BC 80049CBC E0076284 */  lh         $v0, 0x7E0($v1)
    /* 3A4C0 80049CC0 FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 3A4C4 80049CC4 0A004410 */  beq        $v0, $a0, .L80049CF0
    /* 3A4C8 80049CC8 01000224 */   addiu     $v0, $zero, 0x1
    /* 3A4CC 80049CCC 000562A0 */  sb         $v0, 0x500($v1)
    /* 3A4D0 80049CD0 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3A4D4 80049CD4 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3A4D8 80049CD8 7F000324 */  addiu      $v1, $zero, 0x7F
    /* 3A4DC 80049CDC E00744A4 */  sh         $a0, 0x7E0($v0)
    /* 3A4E0 80049CE0 E20740A4 */  sh         $zero, 0x7E2($v0)
    /* 3A4E4 80049CE4 E60743A4 */  sh         $v1, 0x7E6($v0)
    /* 3A4E8 80049CE8 E40743A4 */  sh         $v1, 0x7E4($v0)
    /* 3A4EC 80049CEC 000540A0 */  sb         $zero, 0x500($v0)
  .L80049CF0:
    /* 3A4F0 80049CF0 0800E003 */  jr         $ra
    /* 3A4F4 80049CF4 00000000 */   nop
endlabel func_80049CB0
