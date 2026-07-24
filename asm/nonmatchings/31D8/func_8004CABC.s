nonmatching func_8004CABC, 0x50

glabel func_8004CABC
    /* 3D2BC 8004CABC 0A80043C */  lui        $a0, %hi(D_8009B458)
    /* 3D2C0 8004CAC0 58B4848C */  lw         $a0, %lo(D_8009B458)($a0)
    /* 3D2C4 8004CAC4 00000000 */  nop
    /* 3D2C8 8004CAC8 FA078294 */  lhu        $v0, 0x7FA($a0)
    /* 3D2CC 8004CACC 00000000 */  nop
    /* 3D2D0 8004CAD0 0C004010 */  beqz       $v0, .L8004CB04
    /* 3D2D4 8004CAD4 21180000 */   addu      $v1, $zero, $zero
    /* 3D2D8 8004CAD8 01000624 */  addiu      $a2, $zero, 0x1
    /* 3D2DC 8004CADC 21284000 */  addu       $a1, $v0, $zero
  .L8004CAE0:
    /* 3D2E0 8004CAE0 3C058290 */  lbu        $v0, 0x53C($a0)
    /* 3D2E4 8004CAE4 00000000 */  nop
    /* 3D2E8 8004CAE8 03004610 */  beq        $v0, $a2, .L8004CAF8
    /* 3D2EC 8004CAEC 01006324 */   addiu     $v1, $v1, 0x1
    /* 3D2F0 8004CAF0 0800E003 */  jr         $ra
    /* 3D2F4 8004CAF4 01000224 */   addiu     $v0, $zero, 0x1
  .L8004CAF8:
    /* 3D2F8 8004CAF8 2A106500 */  slt        $v0, $v1, $a1
    /* 3D2FC 8004CAFC F8FF4014 */  bnez       $v0, .L8004CAE0
    /* 3D300 8004CB00 2C008424 */   addiu     $a0, $a0, 0x2C
  .L8004CB04:
    /* 3D304 8004CB04 0800E003 */  jr         $ra
    /* 3D308 8004CB08 03000224 */   addiu     $v0, $zero, 0x3
endlabel func_8004CABC
