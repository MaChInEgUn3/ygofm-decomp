nonmatching func_8003FD14, 0x100

glabel func_8003FD14
    /* 30514 8003FD14 E5048393 */  lbu        $v1, %gp_rel(D_8009B3ED)($gp)
    /* 30518 8003FD18 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3051C 8003FD1C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 30520 8003FD20 1400B1AF */  sw         $s1, 0x14($sp)
    /* 30524 8003FD24 80006230 */  andi       $v0, $v1, 0x80
    /* 30528 8003FD28 05004014 */  bnez       $v0, .L8003FD40
    /* 3052C 8003FD2C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 30530 8003FD30 80006234 */  ori        $v0, $v1, 0x80
    /* 30534 8003FD34 E50482A3 */  sb         $v0, %gp_rel(D_8009B3ED)($gp)
    /* 30538 8003FD38 28000224 */  addiu      $v0, $zero, 0x28
    /* 3053C 8003FD3C B80482A3 */  sb         $v0, %gp_rel(D_8009B3C0)($gp)
  .L8003FD40:
    /* 30540 8003FD40 36FF000C */  jal        func_8003FCD8
    /* 30544 8003FD44 00000000 */   nop
    /* 30548 8003FD48 21884000 */  addu       $s1, $v0, $zero
    /* 3054C 8003FD4C 01000224 */  addiu      $v0, $zero, 0x1
    /* 30550 8003FD50 2B002216 */  bne        $s1, $v0, .L8003FE00
    /* 30554 8003FD54 21102002 */   addu      $v0, $s1, $zero
    /* 30558 8003FD58 1D80023C */  lui        $v0, %hi(D_801D1200)
    /* 3055C 8003FD5C 00124324 */  addiu      $v1, $v0, %lo(D_801D1200)
    /* 30560 8003FD60 00106524 */  addiu      $a1, $v1, 0x1000
    /* 30564 8003FD64 21200000 */  addu       $a0, $zero, $zero
    /* 30568 8003FD68 1D80023C */  lui        $v0, %hi(D_801D5608)
    /* 3056C 8003FD6C 08564624 */  addiu      $a2, $v0, %lo(D_801D5608)
    /* 30570 8003FD70 01000824 */  addiu      $t0, $zero, 0x1
    /* 30574 8003FD74 02000724 */  addiu      $a3, $zero, 0x2
    /* 30578 8003FD78 0A000224 */  addiu      $v0, $zero, 0xA
    /* 3057C 8003FD7C E20482A3 */  sb         $v0, %gp_rel(D_8009B3EA)($gp)
    /* 30580 8003FD80 24000224 */  addiu      $v0, $zero, 0x24
    /* 30584 8003FD84 B80482A3 */  sb         $v0, %gp_rel(D_8009B3C0)($gp)
  .L8003FD88:
    /* 30588 8003FD88 00006294 */  lhu        $v0, 0x0($v1)
    /* 3058C 8003FD8C 00000000 */  nop
    /* 30590 8003FD90 03004014 */  bnez       $v0, .L8003FDA0
    /* 30594 8003FD94 21100000 */   addu      $v0, $zero, $zero
    /* 30598 8003FD98 80FF0008 */  j          .L8003FE00
    /* 3059C 8003FD9C 4000C8AC */   sw        $t0, 0x40($a2)
  .L8003FDA0:
    /* 305A0 8003FDA0 0000A294 */  lhu        $v0, 0x0($a1)
    /* 305A4 8003FDA4 00000000 */  nop
    /* 305A8 8003FDA8 04004014 */  bnez       $v0, .L8003FDBC
    /* 305AC 8003FDAC 01008424 */   addiu     $a0, $a0, 0x1
    /* 305B0 8003FDB0 4000C7AC */  sw         $a3, 0x40($a2)
    /* 305B4 8003FDB4 80FF0008 */  j          .L8003FE00
    /* 305B8 8003FDB8 21100000 */   addu      $v0, $zero, $zero
  .L8003FDBC:
    /* 305BC 8003FDBC 02006324 */  addiu      $v1, $v1, 0x2
    /* 305C0 8003FDC0 28008228 */  slti       $v0, $a0, 0x28
    /* 305C4 8003FDC4 F0FF4014 */  bnez       $v0, .L8003FD88
    /* 305C8 8003FDC8 0200A524 */   addiu     $a1, $a1, 0x2
    /* 305CC 8003FDCC 1B80043C */  lui        $a0, %hi(D_801B122B)
    /* 305D0 8003FDD0 2B128424 */  addiu      $a0, $a0, %lo(D_801B122B)
    /* 305D4 8003FDD4 1D80103C */  lui        $s0, %hi(D_801D160C)
    /* 305D8 8003FDD8 0C161026 */  addiu      $s0, $s0, %lo(D_801D160C)
    /* 305DC 8003FDDC 21280002 */  addu       $a1, $s0, $zero
    /* 305E0 8003FDE0 10EF000C */  jal        func_8003BC40
    /* 305E4 8003FDE4 06000624 */   addiu     $a2, $zero, 0x6
    /* 305E8 8003FDE8 1B80043C */  lui        $a0, %hi(D_801B1238)
    /* 305EC 8003FDEC 38128424 */  addiu      $a0, $a0, %lo(D_801B1238)
    /* 305F0 8003FDF0 00100526 */  addiu      $a1, $s0, 0x1000
    /* 305F4 8003FDF4 10EF000C */  jal        func_8003BC40
    /* 305F8 8003FDF8 06000624 */   addiu     $a2, $zero, 0x6
    /* 305FC 8003FDFC 21102002 */  addu       $v0, $s1, $zero
  .L8003FE00:
    /* 30600 8003FE00 1800BF8F */  lw         $ra, 0x18($sp)
    /* 30604 8003FE04 1400B18F */  lw         $s1, 0x14($sp)
    /* 30608 8003FE08 1000B08F */  lw         $s0, 0x10($sp)
    /* 3060C 8003FE0C 0800E003 */  jr         $ra
    /* 30610 8003FE10 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003FD14
