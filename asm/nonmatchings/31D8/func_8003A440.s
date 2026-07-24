nonmatching func_8003A440, 0x120

glabel func_8003A440
    /* 2AC40 8003A440 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 2AC44 8003A444 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2AC48 8003A448 2198A000 */  addu       $s3, $a1, $zero
    /* 2AC4C 8003A44C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 2AC50 8003A450 21A0C000 */  addu       $s4, $a2, $zero
    /* 2AC54 8003A454 2800BFAF */  sw         $ra, 0x28($sp)
    /* 2AC58 8003A458 2400B5AF */  sw         $s5, 0x24($sp)
    /* 2AC5C 8003A45C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2AC60 8003A460 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2AC64 8003A464 1C006016 */  bnez       $s3, .L8003A4D8
    /* 2AC68 8003A468 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2AC6C 8003A46C 02001124 */  addiu      $s1, $zero, 0x2
    /* 2AC70 8003A470 FF8F133C */  lui        $s3, (0x8FFFFFFF >> 16)
    /* 2AC74 8003A474 FFFF7336 */  ori        $s3, $s3, (0x8FFFFFFF & 0xFFFF)
    /* 2AC78 8003A478 0040153C */  lui        $s5, (0x40000000 >> 16)
    /* 2AC7C 8003A47C 08009224 */  addiu      $s2, $a0, 0x8
  .L8003A480:
    /* 2AC80 8003A480 0000508E */  lw         $s0, 0x0($s2)
    /* 2AC84 8003A484 00000000 */  nop
    /* 2AC88 8003A488 0E000012 */  beqz       $s0, .L8003A4C4
    /* 2AC8C 8003A48C 21200002 */   addu      $a0, $s0, $zero
    /* 2AC90 8003A490 002E1400 */  sll        $a1, $s4, 24
    /* 2AC94 8003A494 0400028E */  lw         $v0, 0x4($s0)
    /* 2AC98 8003A498 032E0500 */  sra        $a1, $a1, 24
    /* 2AC9C 8003A49C 24105300 */  and        $v0, $v0, $s3
    /* 2ACA0 8003A4A0 25105500 */  or         $v0, $v0, $s5
    /* 2ACA4 8003A4A4 3B0A010C */  jal        func_800428EC
    /* 2ACA8 8003A4A8 040002AE */   sw        $v0, 0x4($s0)
    /* 2ACAC 8003A4AC 8000033C */  lui        $v1, (0x808080 >> 16)
    /* 2ACB0 8003A4B0 42000296 */  lhu        $v0, 0x42($s0)
    /* 2ACB4 8003A4B4 80806334 */  ori        $v1, $v1, (0x808080 & 0xFFFF)
    /* 2ACB8 8003A4B8 0C0003AE */  sw         $v1, 0xC($s0)
    /* 2ACBC 8003A4BC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 2ACC0 8003A4C0 420002A6 */  sh         $v0, 0x42($s0)
  .L8003A4C4:
    /* 2ACC4 8003A4C4 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 2ACC8 8003A4C8 EDFF2106 */  bgez       $s1, .L8003A480
    /* 2ACCC 8003A4CC FCFF5226 */   addiu     $s2, $s2, -0x4
    /* 2ACD0 8003A4D0 4FE90008 */  j          .L8003A53C
    /* 2ACD4 8003A4D4 00000000 */   nop
  .L8003A4D8:
    /* 2ACD8 8003A4D8 02001124 */  addiu      $s1, $zero, 0x2
    /* 2ACDC 8003A4DC FF8F153C */  lui        $s5, (0x8FFFFFFF >> 16)
    /* 2ACE0 8003A4E0 FFFFB536 */  ori        $s5, $s5, (0x8FFFFFFF & 0xFFFF)
    /* 2ACE4 8003A4E4 00A61400 */  sll        $s4, $s4, 24
    /* 2ACE8 8003A4E8 08009224 */  addiu      $s2, $a0, 0x8
  .L8003A4EC:
    /* 2ACEC 8003A4EC 0000508E */  lw         $s0, 0x0($s2)
    /* 2ACF0 8003A4F0 00000000 */  nop
    /* 2ACF4 8003A4F4 0E000012 */  beqz       $s0, .L8003A530
    /* 2ACF8 8003A4F8 21200002 */   addu      $a0, $s0, $zero
    /* 2ACFC 8003A4FC 0400028E */  lw         $v0, 0x4($s0)
    /* 2AD00 8003A500 032E1400 */  sra        $a1, $s4, 24
    /* 2AD04 8003A504 24105500 */  and        $v0, $v0, $s5
    /* 2AD08 8003A508 25105300 */  or         $v0, $v0, $s3
    /* 2AD0C 8003A50C 3B0A010C */  jal        func_800428EC
    /* 2AD10 8003A510 040002AE */   sw        $v0, 0x4($s0)
    /* 2AD14 8003A514 0060023C */  lui        $v0, (0x60000000 >> 16)
    /* 2AD18 8003A518 04006212 */  beq        $s3, $v0, .L8003A52C
    /* 2AD1C 8003A51C FD000224 */   addiu     $v0, $zero, 0xFD
    /* 2AD20 8003A520 42000296 */  lhu        $v0, 0x42($s0)
    /* 2AD24 8003A524 00000000 */  nop
    /* 2AD28 8003A528 01004224 */  addiu      $v0, $v0, 0x1
  .L8003A52C:
    /* 2AD2C 8003A52C 420002A6 */  sh         $v0, 0x42($s0)
  .L8003A530:
    /* 2AD30 8003A530 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 2AD34 8003A534 EDFF2106 */  bgez       $s1, .L8003A4EC
    /* 2AD38 8003A538 FCFF5226 */   addiu     $s2, $s2, -0x4
  .L8003A53C:
    /* 2AD3C 8003A53C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 2AD40 8003A540 2400B58F */  lw         $s5, 0x24($sp)
    /* 2AD44 8003A544 2000B48F */  lw         $s4, 0x20($sp)
    /* 2AD48 8003A548 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2AD4C 8003A54C 1800B28F */  lw         $s2, 0x18($sp)
    /* 2AD50 8003A550 1400B18F */  lw         $s1, 0x14($sp)
    /* 2AD54 8003A554 1000B08F */  lw         $s0, 0x10($sp)
    /* 2AD58 8003A558 0800E003 */  jr         $ra
    /* 2AD5C 8003A55C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8003A440
