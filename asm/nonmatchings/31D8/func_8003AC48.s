nonmatching func_8003AC48, 0x124

glabel func_8003AC48
    /* 2B448 8003AC48 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2B44C 8003AC4C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2B450 8003AC50 21988000 */  addu       $s3, $a0, $zero
    /* 2B454 8003AC54 2000BFAF */  sw         $ra, 0x20($sp)
    /* 2B458 8003AC58 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2B45C 8003AC5C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2B460 8003AC60 C7E7000C */  jal        func_80039F1C
    /* 2B464 8003AC64 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2B468 8003AC68 15004014 */  bnez       $v0, .L8003ACC0
    /* 2B46C 8003AC6C 21206002 */   addu      $a0, $s3, $zero
    /* 2B470 8003AC70 0050053C */  lui        $a1, (0x50000000 >> 16)
    /* 2B474 8003AC74 32006292 */  lbu        $v0, 0x32($s3)
    /* 2B478 8003AC78 0000638E */  lw         $v1, 0x0($s3)
    /* 2B47C 8003AC7C 10004234 */  ori        $v0, $v0, 0x10
    /* 2B480 8003AC80 320062A2 */  sb         $v0, 0x32($s3)
    /* 2B484 8003AC84 16007280 */  lb         $s2, 0x16($v1)
    /* 2B488 8003AC88 67007190 */  lbu        $s1, 0x67($v1)
    /* 2B48C 8003AC8C 10E9000C */  jal        func_8003A440
    /* 2B490 8003AC90 21304002 */   addu      $a2, $s2, $zero
    /* 2B494 8003AC94 21206002 */  addu       $a0, $s3, $zero
    /* 2B498 8003AC98 0C007026 */  addiu      $s0, $s3, 0xC
    /* 2B49C 8003AC9C 21280002 */  addu       $a1, $s0, $zero
    /* 2B4A0 8003ACA0 7BE8000C */  jal        func_8003A1EC
    /* 2B4A4 8003ACA4 21302002 */   addu      $a2, $s1, $zero
    /* 2B4A8 8003ACA8 21200002 */  addu       $a0, $s0, $zero
    /* 2B4AC 8003ACAC 0060053C */  lui        $a1, (0x60000000 >> 16)
    /* 2B4B0 8003ACB0 10E9000C */  jal        func_8003A440
    /* 2B4B4 8003ACB4 FFFF4626 */   addiu     $a2, $s2, -0x1
    /* 2B4B8 8003ACB8 80000224 */  addiu      $v0, $zero, 0x80
    /* 2B4BC 8003ACBC 400062A6 */  sh         $v0, 0x40($s3)
  .L8003ACC0:
    /* 2B4C0 8003ACC0 0A80033C */  lui        $v1, %hi(D_8009B0D8)
    /* 2B4C4 8003ACC4 D8B0638C */  lw         $v1, %lo(D_8009B0D8)($v1)
    /* 2B4C8 8003ACC8 40006296 */  lhu        $v0, 0x40($s3)
    /* 2B4CC 8003ACCC C0180300 */  sll        $v1, $v1, 3
    /* 2B4D0 8003ACD0 23104300 */  subu       $v0, $v0, $v1
    /* 2B4D4 8003ACD4 400062A6 */  sh         $v0, 0x40($s3)
    /* 2B4D8 8003ACD8 00140200 */  sll        $v0, $v0, 16
    /* 2B4DC 8003ACDC 03140200 */  sra        $v0, $v0, 16
    /* 2B4E0 8003ACE0 0800401C */  bgtz       $v0, .L8003AD04
    /* 2B4E4 8003ACE4 21204000 */   addu      $a0, $v0, $zero
    /* 2B4E8 8003ACE8 330060A2 */  sb         $zero, 0x33($s3)
    /* 2B4EC 8003ACEC E4E7000C */  jal        func_80039F90
    /* 2B4F0 8003ACF0 0C006426 */   addiu     $a0, $s3, 0xC
    /* 2B4F4 8003ACF4 F5E7000C */  jal        func_80039FD4
    /* 2B4F8 8003ACF8 21206002 */   addu      $a0, $s3, $zero
    /* 2B4FC 8003ACFC 54EB0008 */  j          .L8003AD50
    /* 2B500 8003AD00 00000000 */   nop
  .L8003AD04:
    /* 2B504 8003AD04 00120400 */  sll        $v0, $a0, 8
    /* 2B508 8003AD08 001C0400 */  sll        $v1, $a0, 16
    /* 2B50C 8003AD0C 25104300 */  or         $v0, $v0, $v1
    /* 2B510 8003AD10 25208200 */  or         $a0, $a0, $v0
    /* 2B514 8003AD14 02000524 */  addiu      $a1, $zero, 0x2
    /* 2B518 8003AD18 08006326 */  addiu      $v1, $s3, 0x8
  .L8003AD1C:
    /* 2B51C 8003AD1C 0000628C */  lw         $v0, 0x0($v1)
    /* 2B520 8003AD20 00000000 */  nop
    /* 2B524 8003AD24 02004010 */  beqz       $v0, .L8003AD30
    /* 2B528 8003AD28 00000000 */   nop
    /* 2B52C 8003AD2C 0C0044AC */  sw         $a0, 0xC($v0)
  .L8003AD30:
    /* 2B530 8003AD30 0C00628C */  lw         $v0, 0xC($v1)
    /* 2B534 8003AD34 00000000 */  nop
    /* 2B538 8003AD38 02004010 */  beqz       $v0, .L8003AD44
    /* 2B53C 8003AD3C 00000000 */   nop
    /* 2B540 8003AD40 0C0044AC */  sw         $a0, 0xC($v0)
  .L8003AD44:
    /* 2B544 8003AD44 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 2B548 8003AD48 F4FFA104 */  bgez       $a1, .L8003AD1C
    /* 2B54C 8003AD4C FCFF6324 */   addiu     $v1, $v1, -0x4
  .L8003AD50:
    /* 2B550 8003AD50 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2B554 8003AD54 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2B558 8003AD58 1800B28F */  lw         $s2, 0x18($sp)
    /* 2B55C 8003AD5C 1400B18F */  lw         $s1, 0x14($sp)
    /* 2B560 8003AD60 1000B08F */  lw         $s0, 0x10($sp)
    /* 2B564 8003AD64 0800E003 */  jr         $ra
    /* 2B568 8003AD68 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003AC48
