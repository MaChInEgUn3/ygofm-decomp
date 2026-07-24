nonmatching func_8007FD30, 0xC0

glabel func_8007FD30
    /* 70530 8007FD30 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 70534 8007FD34 1800B2AF */  sw         $s2, 0x18($sp)
    /* 70538 8007FD38 0980123C */  lui        $s2, %hi(D_8009466A)
    /* 7053C 8007FD3C 6A465226 */  addiu      $s2, $s2, %lo(D_8009466A)
    /* 70540 8007FD40 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 70544 8007FD44 1400B1AF */  sw         $s1, 0x14($sp)
    /* 70548 8007FD48 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7054C 8007FD4C 00004292 */  lbu        $v0, 0x0($s2)
    /* 70550 8007FD50 00000000 */  nop
    /* 70554 8007FD54 0200422C */  sltiu      $v0, $v0, 0x2
    /* 70558 8007FD58 08004014 */  bnez       $v0, .L8007FD7C
    /* 7055C 8007FD5C 21888000 */   addu      $s1, $a0, $zero
    /* 70560 8007FD60 0180043C */  lui        $a0, %hi(D_800122DC)
    /* 70564 8007FD64 DC228424 */  addiu      $a0, $a0, %lo(D_800122DC)
    /* 70568 8007FD68 0980023C */  lui        $v0, %hi(D_80094664)
    /* 7056C 8007FD6C 6446428C */  lw         $v0, %lo(D_80094664)($v0)
    /* 70570 8007FD70 00000000 */  nop
    /* 70574 8007FD74 09F84000 */  jalr       $v0
    /* 70578 8007FD78 21282002 */   addu      $a1, $s1, $zero
  .L8007FD7C:
    /* 7057C 8007FD7C 1C003026 */  addiu      $s0, $s1, 0x1C
    /* 70580 8007FD80 21200002 */  addu       $a0, $s0, $zero
    /* 70584 8007FD84 C401020C */  jal        func_80080710
    /* 70588 8007FD88 21282002 */   addu      $a1, $s1, $zero
    /* 7058C 8007FD8C FF00043C */  lui        $a0, (0xFFFFFF >> 16)
    /* 70590 8007FD90 FFFF8434 */  ori        $a0, $a0, (0xFFFFFF & 0xFFFF)
    /* 70594 8007FD94 21280002 */  addu       $a1, $s0, $zero
    /* 70598 8007FD98 40000624 */  addiu      $a2, $zero, 0x40
    /* 7059C 8007FD9C 1C00228E */  lw         $v0, 0x1C($s1)
    /* 705A0 8007FDA0 0980033C */  lui        $v1, %hi(D_80094660)
    /* 705A4 8007FDA4 6046638C */  lw         $v1, %lo(D_80094660)($v1)
    /* 705A8 8007FDA8 25104400 */  or         $v0, $v0, $a0
    /* 705AC 8007FDAC 1C0022AE */  sw         $v0, 0x1C($s1)
    /* 705B0 8007FDB0 1800648C */  lw         $a0, 0x18($v1)
    /* 705B4 8007FDB4 0800628C */  lw         $v0, 0x8($v1)
    /* 705B8 8007FDB8 00000000 */  nop
    /* 705BC 8007FDBC 09F84000 */  jalr       $v0
    /* 705C0 8007FDC0 21380000 */   addu      $a3, $zero, $zero
    /* 705C4 8007FDC4 0E004426 */  addiu      $a0, $s2, 0xE
    /* 705C8 8007FDC8 21282002 */  addu       $a1, $s1, $zero
    /* 705CC 8007FDCC E438020C */  jal        func_8008E390
    /* 705D0 8007FDD0 5C000624 */   addiu     $a2, $zero, 0x5C
    /* 705D4 8007FDD4 21102002 */  addu       $v0, $s1, $zero
    /* 705D8 8007FDD8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 705DC 8007FDDC 1800B28F */  lw         $s2, 0x18($sp)
    /* 705E0 8007FDE0 1400B18F */  lw         $s1, 0x14($sp)
    /* 705E4 8007FDE4 1000B08F */  lw         $s0, 0x10($sp)
    /* 705E8 8007FDE8 0800E003 */  jr         $ra
    /* 705EC 8007FDEC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007FD30
