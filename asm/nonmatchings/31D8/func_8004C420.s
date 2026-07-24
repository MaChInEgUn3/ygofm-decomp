nonmatching func_8004C420, 0x140

glabel func_8004C420
    /* 3CC20 8004C420 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3CC24 8004C424 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3CC28 8004C428 21808000 */  addu       $s0, $a0, $zero
    /* 3CC2C 8004C42C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3CC30 8004C430 21A00000 */  addu       $s4, $zero, $zero
    /* 3CC34 8004C434 2400BFAF */  sw         $ra, 0x24($sp)
    /* 3CC38 8004C438 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3CC3C 8004C43C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3CC40 8004C440 B92E010C */  jal        func_8004BAE4
    /* 3CC44 8004C444 1400B1AF */   sw        $s1, 0x14($sp)
    /* 3CC48 8004C448 21284000 */  addu       $a1, $v0, $zero
    /* 3CC4C 8004C44C 8000A230 */  andi       $v0, $a1, 0x80
    /* 3CC50 8004C450 05004014 */  bnez       $v0, .L8004C468
    /* 3CC54 8004C454 2120A000 */   addu      $a0, $a1, $zero
    /* 3CC58 8004C458 29001192 */  lbu        $s1, 0x29($s0)
    /* 3CC5C 8004C45C 01000224 */  addiu      $v0, $zero, 0x1
    /* 3CC60 8004C460 20310108 */  j          .L8004C480
    /* 3CC64 8004C464 280002A2 */   sb        $v0, 0x28($s0)
  .L8004C468:
    /* 3CC68 8004C468 FF008330 */  andi       $v1, $a0, 0xFF
    /* 3CC6C 8004C46C FF000224 */  addiu      $v0, $zero, 0xFF
    /* 3CC70 8004C470 02006210 */  beq        $v1, $v0, .L8004C47C
    /* 3CC74 8004C474 2188A000 */   addu      $s1, $a1, $zero
    /* 3CC78 8004C478 290005A2 */  sb         $a1, 0x29($s0)
  .L8004C47C:
    /* 3CC7C 8004C47C 280000A2 */  sb         $zero, 0x28($s0)
  .L8004C480:
    /* 3CC80 8004C480 0180033C */  lui        $v1, %hi(D_80011484)
    /* 3CC84 8004C484 84146324 */  addiu      $v1, $v1, %lo(D_80011484)
    /* 3CC88 8004C488 82101100 */  srl        $v0, $s1, 2
    /* 3CC8C 8004C48C 3C004230 */  andi       $v0, $v0, 0x3C
    /* 3CC90 8004C490 21104300 */  addu       $v0, $v0, $v1
    /* 3CC94 8004C494 0000538C */  lw         $s3, 0x0($v0)
    /* 3CC98 8004C498 00000000 */  nop
    /* 3CC9C 8004C49C 15006012 */  beqz       $s3, .L8004C4F4
    /* 3CCA0 8004C4A0 F0000224 */   addiu     $v0, $zero, 0xF0
    /* 3CCA4 8004C4A4 28000292 */  lbu        $v0, 0x28($s0)
    /* 3CCA8 8004C4A8 00000000 */  nop
    /* 3CCAC 8004C4AC 04004014 */  bnez       $v0, .L8004C4C0
    /* 3CCB0 8004C4B0 21908000 */   addu      $s2, $a0, $zero
    /* 3CCB4 8004C4B4 B92E010C */  jal        func_8004BAE4
    /* 3CCB8 8004C4B8 21200002 */   addu      $a0, $s0, $zero
    /* 3CCBC 8004C4BC 21904000 */  addu       $s2, $v0, $zero
  .L8004C4C0:
    /* 3CCC0 8004C4C0 02000224 */  addiu      $v0, $zero, 0x2
    /* 3CCC4 8004C4C4 05006216 */  bne        $s3, $v0, .L8004C4DC
    /* 3CCC8 8004C4C8 21200002 */   addu      $a0, $s0, $zero
    /* 3CCCC 8004C4CC B92E010C */  jal        func_8004BAE4
    /* 3CCD0 8004C4D0 21200002 */   addu      $a0, $s0, $zero
    /* 3CCD4 8004C4D4 21A04000 */  addu       $s4, $v0, $zero
    /* 3CCD8 8004C4D8 21200002 */  addu       $a0, $s0, $zero
  .L8004C4DC:
    /* 3CCDC 8004C4DC FF002532 */  andi       $a1, $s1, 0xFF
    /* 3CCE0 8004C4E0 FF004632 */  andi       $a2, $s2, 0xFF
    /* 3CCE4 8004C4E4 4530010C */  jal        func_8004C114
    /* 3CCE8 8004C4E8 FF008732 */   andi      $a3, $s4, 0xFF
    /* 3CCEC 8004C4EC 50310108 */  j          .L8004C540
    /* 3CCF0 8004C4F0 21100000 */   addu      $v0, $zero, $zero
  .L8004C4F4:
    /* 3CCF4 8004C4F4 FF008430 */  andi       $a0, $a0, 0xFF
    /* 3CCF8 8004C4F8 0A008210 */  beq        $a0, $v0, .L8004C524
    /* 3CCFC 8004C4FC FF000224 */   addiu     $v0, $zero, 0xFF
    /* 3CD00 8004C500 0C008214 */  bne        $a0, $v0, .L8004C534
    /* 3CD04 8004C504 00000000 */   nop
    /* 3CD08 8004C508 B92E010C */  jal        func_8004BAE4
    /* 3CD0C 8004C50C 21200002 */   addu      $a0, $s0, $zero
    /* 3CD10 8004C510 21200002 */  addu       $a0, $s0, $zero
    /* 3CD14 8004C514 A22F010C */  jal        func_8004BE88
    /* 3CD18 8004C518 FF004530 */   andi      $a1, $v0, 0xFF
    /* 3CD1C 8004C51C 50310108 */  j          .L8004C540
    /* 3CD20 8004C520 21100000 */   addu      $v0, $zero, $zero
  .L8004C524:
    /* 3CD24 8004C524 2B30010C */  jal        func_8004C0AC
    /* 3CD28 8004C528 21200002 */   addu      $a0, $s0, $zero
    /* 3CD2C 8004C52C 50310108 */  j          .L8004C540
    /* 3CD30 8004C530 21100000 */   addu      $v0, $zero, $zero
  .L8004C534:
    /* 3CD34 8004C534 A02F010C */  jal        func_8004BE80
    /* 3CD38 8004C538 00000000 */   nop
    /* 3CD3C 8004C53C 21100000 */  addu       $v0, $zero, $zero
  .L8004C540:
    /* 3CD40 8004C540 2400BF8F */  lw         $ra, 0x24($sp)
    /* 3CD44 8004C544 2000B48F */  lw         $s4, 0x20($sp)
    /* 3CD48 8004C548 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3CD4C 8004C54C 1800B28F */  lw         $s2, 0x18($sp)
    /* 3CD50 8004C550 1400B18F */  lw         $s1, 0x14($sp)
    /* 3CD54 8004C554 1000B08F */  lw         $s0, 0x10($sp)
    /* 3CD58 8004C558 0800E003 */  jr         $ra
    /* 3CD5C 8004C55C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8004C420
