nonmatching func_8008C48C, 0x1AC

glabel func_8008C48C
    /* 7CC8C 8008C48C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7CC90 8008C490 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7CC94 8008C494 21888000 */  addu       $s1, $a0, $zero
    /* 7CC98 8008C498 1800BFAF */  sw         $ra, 0x18($sp)
    /* 7CC9C 8008C49C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7CCA0 8008C4A0 0000238E */  lw         $v1, 0x0($s1)
    /* 7CCA4 8008C4A4 0A001024 */  addiu      $s0, $zero, 0xA
    /* 7CCA8 8008C4A8 14007010 */  beq        $v1, $s0, .L8008C4FC
    /* 7CCAC 8008C4AC 0B006228 */   slti      $v0, $v1, 0xB
    /* 7CCB0 8008C4B0 05004010 */  beqz       $v0, .L8008C4C8
    /* 7CCB4 8008C4B4 1E000224 */   addiu     $v0, $zero, 0x1E
    /* 7CCB8 8008C4B8 09006010 */  beqz       $v1, .L8008C4E0
    /* 7CCBC 8008C4BC 21100000 */   addu      $v0, $zero, $zero
    /* 7CCC0 8008C4C0 89310208 */  j          .L8008C624
    /* 7CCC4 8008C4C4 00000000 */   nop
  .L8008C4C8:
    /* 7CCC8 8008C4C8 28006210 */  beq        $v1, $v0, .L8008C56C
    /* 7CCCC 8008C4CC 20000224 */   addiu     $v0, $zero, 0x20
    /* 7CCD0 8008C4D0 4C006210 */  beq        $v1, $v0, .L8008C604
    /* 7CCD4 8008C4D4 21100000 */   addu      $v0, $zero, $zero
    /* 7CCD8 8008C4D8 89310208 */  j          .L8008C624
    /* 7CCDC 8008C4DC 00000000 */   nop
  .L8008C4E0:
    /* 7CCE0 8008C4E0 0980043C */  lui        $a0, %hi(func_8008B974)
    /* 7CCE4 8008C4E4 74B98424 */  addiu      $a0, $a0, %lo(func_8008B974)
    /* 7CCE8 8008C4E8 0A80013C */  lui        $at, %hi(D_80099E94)
    /* 7CCEC 8008C4EC 3834020C */  jal        func_8008D0E0
    /* 7CCF0 8008C4F0 949E20AC */   sw        $zero, %lo(D_80099E94)($at)
    /* 7CCF4 8008C4F4 88310208 */  j          .L8008C620
    /* 7CCF8 8008C4F8 000030AE */   sw        $s0, 0x0($s1)
  .L8008C4FC:
    /* 7CCFC 8008C4FC 1080043C */  lui        $a0, %hi(D_800FE34C)
    /* 7CD00 8008C500 4CE38424 */  addiu      $a0, $a0, %lo(D_800FE34C)
    /* 7CD04 8008C504 0000828C */  lw         $v0, 0x0($a0)
    /* 7CD08 8008C508 00000000 */  nop
    /* 7CD0C 8008C50C 45004014 */  bnez       $v0, .L8008C624
    /* 7CD10 8008C510 01000224 */   addiu     $v0, $zero, 0x1
    /* 7CD14 8008C514 10009024 */  addiu      $s0, $a0, 0x10
  .L8008C518:
    /* 7CD18 8008C518 0000048E */  lw         $a0, 0x0($s0)
    /* 7CD1C 8008C51C 0400058E */  lw         $a1, 0x4($s0)
    /* 7CD20 8008C520 38CE010C */  jal        func_800738E0
    /* 7CD24 8008C524 21300000 */   addu      $a2, $zero, $zero
    /* 7CD28 8008C528 0400038E */  lw         $v1, 0x4($s0)
    /* 7CD2C 8008C52C 00000000 */  nop
    /* 7CD30 8008C530 F9FF4314 */  bne        $v0, $v1, .L8008C518
    /* 7CD34 8008C534 00000000 */   nop
    /* 7CD38 8008C538 5835020C */  jal        func_8008D560
    /* 7CD3C 8008C53C 00000000 */   nop
    /* 7CD40 8008C540 1080103C */  lui        $s0, %hi(D_800FE35C)
    /* 7CD44 8008C544 5CE31026 */  addiu      $s0, $s0, %lo(D_800FE35C)
  .L8008C548:
    /* 7CD48 8008C548 0000048E */  lw         $a0, 0x0($s0)
    /* 7CD4C 8008C54C 0C00058E */  lw         $a1, 0xC($s0)
    /* 7CD50 8008C550 0800068E */  lw         $a2, 0x8($s0)
    /* 7CD54 8008C554 40CE010C */  jal        func_80073900
    /* 7CD58 8008C558 00000000 */   nop
    /* 7CD5C 8008C55C FAFF4014 */  bnez       $v0, .L8008C548
    /* 7CD60 8008C560 1E000224 */   addiu     $v0, $zero, 0x1E
    /* 7CD64 8008C564 88310208 */  j          .L8008C620
    /* 7CD68 8008C568 000022AE */   sw        $v0, 0x0($s1)
  .L8008C56C:
    /* 7CD6C 8008C56C 0636020C */  jal        func_8008D818
    /* 7CD70 8008C570 00000000 */   nop
    /* 7CD74 8008C574 2B004010 */  beqz       $v0, .L8008C624
    /* 7CD78 8008C578 21100000 */   addu      $v0, $zero, $zero
    /* 7CD7C 8008C57C 9A35020C */  jal        func_8008D668
    /* 7CD80 8008C580 00000000 */   nop
    /* 7CD84 8008C584 21204000 */  addu       $a0, $v0, $zero
    /* 7CD88 8008C588 17008010 */  beqz       $a0, .L8008C5E8
    /* 7CD8C 8008C58C 00000000 */   nop
    /* 7CD90 8008C590 0A80023C */  lui        $v0, %hi(D_80099E94)
    /* 7CD94 8008C594 949E428C */  lw         $v0, %lo(D_80099E94)($v0)
    /* 7CD98 8008C598 00000000 */  nop
    /* 7CD9C 8008C59C 01004224 */  addiu      $v0, $v0, 0x1
    /* 7CDA0 8008C5A0 0A80013C */  lui        $at, %hi(D_80099E94)
    /* 7CDA4 8008C5A4 949E22AC */  sw         $v0, %lo(D_80099E94)($at)
    /* 7CDA8 8008C5A8 04004228 */  slti       $v0, $v0, 0x4
    /* 7CDAC 8008C5AC 03004010 */  beqz       $v0, .L8008C5BC
    /* 7CDB0 8008C5B0 04000224 */   addiu     $v0, $zero, 0x4
    /* 7CDB4 8008C5B4 88310208 */  j          .L8008C620
    /* 7CDB8 8008C5B8 000030AE */   sw        $s0, 0x0($s1)
  .L8008C5BC:
    /* 7CDBC 8008C5BC 0A008214 */  bne        $a0, $v0, .L8008C5E8
    /* 7CDC0 8008C5C0 00000000 */   nop
    /* 7CDC4 8008C5C4 5835020C */  jal        func_8008D560
    /* 7CDC8 8008C5C8 00000000 */   nop
    /* 7CDCC 8008C5CC 1080043C */  lui        $a0, %hi(D_800FE358)
    /* 7CDD0 8008C5D0 58E3848C */  lw         $a0, %lo(D_800FE358)($a0)
    /* 7CDD4 8008C5D4 E82C020C */  jal        func_8008B3A0
    /* 7CDD8 8008C5D8 00000000 */   nop
    /* 7CDDC 8008C5DC 20000224 */  addiu      $v0, $zero, 0x20
    /* 7CDE0 8008C5E0 88310208 */  j          .L8008C620
    /* 7CDE4 8008C5E4 000022AE */   sw        $v0, 0x0($s1)
  .L8008C5E8:
    /* 7CDE8 8008C5E8 DD33020C */  jal        func_8008CF74
    /* 7CDEC 8008C5EC 00000000 */   nop
    /* 7CDF0 8008C5F0 1080033C */  lui        $v1, %hi(D_800FE348)
    /* 7CDF4 8008C5F4 48E36324 */  addiu      $v1, $v1, %lo(D_800FE348)
    /* 7CDF8 8008C5F8 040062AC */  sw         $v0, 0x4($v1)
    /* 7CDFC 8008C5FC 89310208 */  j          .L8008C624
    /* 7CE00 8008C600 01000224 */   addiu     $v0, $zero, 0x1
  .L8008C604:
    /* 7CE04 8008C604 1536020C */  jal        func_8008D854
    /* 7CE08 8008C608 00000000 */   nop
    /* 7CE0C 8008C60C 05004010 */  beqz       $v0, .L8008C624
    /* 7CE10 8008C610 21100000 */   addu      $v0, $zero, $zero
    /* 7CE14 8008C614 D035020C */  jal        func_8008D740
    /* 7CE18 8008C618 00000000 */   nop
    /* 7CE1C 8008C61C 000020AE */  sw         $zero, 0x0($s1)
  .L8008C620:
    /* 7CE20 8008C620 21100000 */  addu       $v0, $zero, $zero
  .L8008C624:
    /* 7CE24 8008C624 1800BF8F */  lw         $ra, 0x18($sp)
    /* 7CE28 8008C628 1400B18F */  lw         $s1, 0x14($sp)
    /* 7CE2C 8008C62C 1000B08F */  lw         $s0, 0x10($sp)
    /* 7CE30 8008C630 0800E003 */  jr         $ra
    /* 7CE34 8008C634 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008C48C
