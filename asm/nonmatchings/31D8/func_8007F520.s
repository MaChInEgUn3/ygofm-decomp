nonmatching func_8007F520, 0xA4

glabel func_8007F520
    /* 6FD20 8007F520 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6FD24 8007F524 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6FD28 8007F528 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6FD2C 8007F52C 0980113C */  lui        $s1, %hi(D_80094669)
    /* 6FD30 8007F530 69463126 */  addiu      $s1, $s1, %lo(D_80094669)
    /* 6FD34 8007F534 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6FD38 8007F538 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6FD3C 8007F53C 01002292 */  lbu        $v0, 0x1($s1)
    /* 6FD40 8007F540 00003292 */  lbu        $s2, 0x0($s1)
    /* 6FD44 8007F544 0200422C */  sltiu      $v0, $v0, 0x2
    /* 6FD48 8007F548 08004014 */  bnez       $v0, .L8007F56C
    /* 6FD4C 8007F54C 21808000 */   addu      $s0, $a0, $zero
    /* 6FD50 8007F550 0180043C */  lui        $a0, %hi(D_800121E0)
    /* 6FD54 8007F554 E0218424 */  addiu      $a0, $a0, %lo(D_800121E0)
    /* 6FD58 8007F558 0980023C */  lui        $v0, %hi(D_80094664)
    /* 6FD5C 8007F55C 6446428C */  lw         $v0, %lo(D_80094664)($v0)
    /* 6FD60 8007F560 00000000 */  nop
    /* 6FD64 8007F564 09F84000 */  jalr       $v0
    /* 6FD68 8007F568 21280002 */   addu      $a1, $s0, $zero
  .L8007F56C:
    /* 6FD6C 8007F56C 00002292 */  lbu        $v0, 0x0($s1)
    /* 6FD70 8007F570 00000000 */  nop
    /* 6FD74 8007F574 0D000212 */  beq        $s0, $v0, .L8007F5AC
    /* 6FD78 8007F578 21104002 */   addu      $v0, $s2, $zero
    /* 6FD7C 8007F57C 0980023C */  lui        $v0, %hi(D_80094660)
    /* 6FD80 8007F580 6046428C */  lw         $v0, %lo(D_80094660)($v0)
    /* 6FD84 8007F584 00000000 */  nop
    /* 6FD88 8007F588 3400428C */  lw         $v0, 0x34($v0)
    /* 6FD8C 8007F58C 00000000 */  nop
    /* 6FD90 8007F590 09F84000 */  jalr       $v0
    /* 6FD94 8007F594 01000424 */   addiu     $a0, $zero, 0x1
    /* 6FD98 8007F598 02000424 */  addiu      $a0, $zero, 0x2
    /* 6FD9C 8007F59C 21280000 */  addu       $a1, $zero, $zero
    /* 6FDA0 8007F5A0 FCD0010C */  jal        func_800743F0
    /* 6FDA4 8007F5A4 000030A2 */   sb        $s0, 0x0($s1)
    /* 6FDA8 8007F5A8 21104002 */  addu       $v0, $s2, $zero
  .L8007F5AC:
    /* 6FDAC 8007F5AC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6FDB0 8007F5B0 1800B28F */  lw         $s2, 0x18($sp)
    /* 6FDB4 8007F5B4 1400B18F */  lw         $s1, 0x14($sp)
    /* 6FDB8 8007F5B8 1000B08F */  lw         $s0, 0x10($sp)
    /* 6FDBC 8007F5BC 0800E003 */  jr         $ra
    /* 6FDC0 8007F5C0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007F520
