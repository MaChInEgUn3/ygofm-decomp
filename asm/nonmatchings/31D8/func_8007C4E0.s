nonmatching func_8007C4E0, 0x110

glabel func_8007C4E0
    /* 6CCE0 8007C4E0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6CCE4 8007C4E4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6CCE8 8007C4E8 2190A000 */  addu       $s2, $a1, $zero
    /* 6CCEC 8007C4EC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6CCF0 8007C4F0 21888000 */  addu       $s1, $a0, $zero
    /* 6CCF4 8007C4F4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6CCF8 8007C4F8 FF003032 */  andi       $s0, $s1, 0xFF
    /* 6CCFC 8007C4FC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 6CD00 8007C500 F7F2010C */  jal        func_8007CBDC
    /* 6CD04 8007C504 21200002 */   addu      $a0, $s0, $zero
    /* 6CD08 8007C508 0980043C */  lui        $a0, %hi(D_800938C4)
    /* 6CD0C 8007C50C C4388424 */  addiu      $a0, $a0, %lo(D_800938C4)
    /* 6CD10 8007C510 02000224 */  addiu      $v0, $zero, 0x2
    /* 6CD14 8007C514 040080AC */  sw         $zero, 0x4($a0)
    /* 6CD18 8007C518 0D000216 */  bne        $s0, $v0, .L8007C550
    /* 6CD1C 8007C51C 000080AC */   sw        $zero, 0x0($a0)
    /* 6CD20 8007C520 C0FF8390 */  lbu        $v1, -0x40($a0)
    /* 6CD24 8007C524 01000524 */  addiu      $a1, $zero, 0x1
    /* 6CD28 8007C528 09006510 */  beq        $v1, $a1, .L8007C550
    /* 6CD2C 8007C52C 09000224 */   addiu     $v0, $zero, 0x9
    /* 6CD30 8007C530 06006214 */  bne        $v1, $v0, .L8007C54C
    /* 6CD34 8007C534 FF00033C */   lui       $v1, (0xFF00FF >> 16)
    /* 6CD38 8007C538 F0FF828C */  lw         $v0, -0x10($a0)
    /* 6CD3C 8007C53C FF006334 */  ori        $v1, $v1, (0xFF00FF & 0xFFFF)
    /* 6CD40 8007C540 24104300 */  and        $v0, $v0, $v1
    /* 6CD44 8007C544 02004014 */  bnez       $v0, .L8007C550
    /* 6CD48 8007C548 00000000 */   nop
  .L8007C54C:
    /* 6CD4C 8007C54C 0C0085A0 */  sb         $a1, 0xC($a0)
  .L8007C550:
    /* 6CD50 8007C550 0980033C */  lui        $v1, %hi(D_80093898)
    /* 6CD54 8007C554 98386324 */  addiu      $v1, $v1, %lo(D_80093898)
    /* 6CD58 8007C558 00006290 */  lbu        $v0, 0x0($v1)
    /* 6CD5C 8007C55C 00000000 */  nop
    /* 6CD60 8007C560 10004230 */  andi       $v0, $v0, 0x10
    /* 6CD64 8007C564 02004010 */  beqz       $v0, .L8007C570
    /* 6CD68 8007C568 00000000 */   nop
    /* 6CD6C 8007C56C 05001124 */  addiu      $s1, $zero, 0x5
  .L8007C570:
    /* 6CD70 8007C570 0400638C */  lw         $v1, 0x4($v1)
    /* 6CD74 8007C574 1F000224 */  addiu      $v0, $zero, 0x1F
    /* 6CD78 8007C578 05006210 */  beq        $v1, $v0, .L8007C590
    /* 6CD7C 8007C57C 20000224 */   addiu     $v0, $zero, 0x20
    /* 6CD80 8007C580 08006210 */  beq        $v1, $v0, .L8007C5A4
    /* 6CD84 8007C584 FF002432 */   andi      $a0, $s1, 0xFF
    /* 6CD88 8007C588 6DF10108 */  j          .L8007C5B4
    /* 6CD8C 8007C58C 00000000 */   nop
  .L8007C590:
    /* 6CD90 8007C590 FF002432 */  andi       $a0, $s1, 0xFF
    /* 6CD94 8007C594 7CF1010C */  jal        func_8007C5F0
    /* 6CD98 8007C598 21284002 */   addu      $a1, $s2, $zero
    /* 6CD9C 8007C59C 6FF10108 */  j          .L8007C5BC
    /* 6CDA0 8007C5A0 00000000 */   nop
  .L8007C5A4:
    /* 6CDA4 8007C5A4 F5F1010C */  jal        func_8007C7D4
    /* 6CDA8 8007C5A8 21284002 */   addu      $a1, $s2, $zero
    /* 6CDAC 8007C5AC 6FF10108 */  j          .L8007C5BC
    /* 6CDB0 8007C5B0 00000000 */   nop
  .L8007C5B4:
    /* 6CDB4 8007C5B4 97F2010C */  jal        func_8007CA5C
    /* 6CDB8 8007C5B8 21284002 */   addu      $a1, $s2, $zero
  .L8007C5BC:
    /* 6CDBC 8007C5BC 0980033C */  lui        $v1, %hi(D_800938C4)
    /* 6CDC0 8007C5C0 C4386324 */  addiu      $v1, $v1, %lo(D_800938C4)
    /* 6CDC4 8007C5C4 0000628C */  lw         $v0, 0x0($v1)
    /* 6CDC8 8007C5C8 00000000 */  nop
    /* 6CDCC 8007C5CC 02004014 */  bnez       $v0, .L8007C5D8
    /* 6CDD0 8007C5D0 21000224 */   addiu     $v0, $zero, 0x21
    /* 6CDD4 8007C5D4 D8FF62AC */  sw         $v0, -0x28($v1)
  .L8007C5D8:
    /* 6CDD8 8007C5D8 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 6CDDC 8007C5DC 1800B28F */  lw         $s2, 0x18($sp)
    /* 6CDE0 8007C5E0 1400B18F */  lw         $s1, 0x14($sp)
    /* 6CDE4 8007C5E4 1000B08F */  lw         $s0, 0x10($sp)
    /* 6CDE8 8007C5E8 0800E003 */  jr         $ra
    /* 6CDEC 8007C5EC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007C4E0
