nonmatching func_8008CA78, 0x25C

glabel func_8008CA78
    /* 7D278 8008CA78 70FFBD27 */  addiu      $sp, $sp, -0x90
    /* 7D27C 8008CA7C 8000B6AF */  sw         $s6, 0x80($sp)
    /* 7D280 8008CA80 21B08000 */  addu       $s6, $a0, $zero
    /* 7D284 8008CA84 6C00B1AF */  sw         $s1, 0x6C($sp)
    /* 7D288 8008CA88 2188A000 */  addu       $s1, $a1, $zero
    /* 7D28C 8008CA8C 8400B7AF */  sw         $s7, 0x84($sp)
    /* 7D290 8008CA90 21B8C000 */  addu       $s7, $a2, $zero
    /* 7D294 8008CA94 6800B0AF */  sw         $s0, 0x68($sp)
    /* 7D298 8008CA98 1080103C */  lui        $s0, %hi(D_800FE348)
    /* 7D29C 8008CA9C 48E31026 */  addiu      $s0, $s0, %lo(D_800FE348)
    /* 7D2A0 8008CAA0 8C00BFAF */  sw         $ra, 0x8C($sp)
    /* 7D2A4 8008CAA4 8800BEAF */  sw         $fp, 0x88($sp)
    /* 7D2A8 8008CAA8 7C00B5AF */  sw         $s5, 0x7C($sp)
    /* 7D2AC 8008CAAC 7800B4AF */  sw         $s4, 0x78($sp)
    /* 7D2B0 8008CAB0 7400B3AF */  sw         $s3, 0x74($sp)
    /* 7D2B4 8008CAB4 7000B2AF */  sw         $s2, 0x70($sp)
    /* 7D2B8 8008CAB8 5C00A7AF */  sw         $a3, 0x5C($sp)
    /* 7D2BC 8008CABC 0000028E */  lw         $v0, 0x0($s0)
    /* 7D2C0 8008CAC0 A000BE8F */  lw         $fp, 0xA0($sp)
    /* 7D2C4 8008CAC4 06004010 */  beqz       $v0, .L8008CAE0
    /* 7D2C8 8008CAC8 2120C002 */   addu      $a0, $s6, $zero
    /* 7D2CC 8008CACC 0180043C */  lui        $a0, %hi(D_8001261C)
    /* 7D2D0 8008CAD0 1C3A020C */  jal        func_8008E870
    /* 7D2D4 8008CAD4 1C268424 */   addiu     $a0, $a0, %lo(D_8001261C)
    /* 7D2D8 8008CAD8 29330208 */  j          .L8008CCA4
    /* 7D2DC 8008CADC FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8008CAE0:
    /* 7D2E0 8008CAE0 1D34020C */  jal        func_8008D074
    /* 7D2E4 8008CAE4 1000A527 */   addiu     $a1, $sp, 0x10
    /* 7D2E8 8008CAE8 1000A427 */  addiu      $a0, $sp, 0x10
    /* 7D2EC 8008CAEC 7439020C */  jal        func_8008E5D0
    /* 7D2F0 8008CAF0 21282002 */   addu      $a1, $s1, $zero
    /* 7D2F4 8008CAF4 21900000 */  addu       $s2, $zero, $zero
    /* 7D2F8 8008CAF8 21880000 */  addu       $s1, $zero, $zero
    /* 7D2FC 8008CAFC 01000224 */  addiu      $v0, $zero, 0x1
    /* 7D300 8008CB00 5800A0AF */  sw         $zero, 0x58($sp)
    /* 7D304 8008CB04 0C00038E */  lw         $v1, 0xC($s0)
    /* 7D308 8008CB08 0410C202 */  sllv       $v0, $v0, $s6
    /* 7D30C 8008CB0C 25186200 */  or         $v1, $v1, $v0
    /* 7D310 8008CB10 0C0003AE */  sw         $v1, 0xC($s0)
    /* 7D314 8008CB14 A400A88F */  lw         $t0, 0xA4($sp)
    /* 7D318 8008CB18 00000000 */  nop
    /* 7D31C 8008CB1C 2110C803 */  addu       $v0, $fp, $t0
    /* 7D320 8008CB20 5B004018 */  blez       $v0, .L8008CC90
    /* 7D324 8008CB24 21A80000 */   addu      $s5, $zero, $zero
    /* 7D328 8008CB28 21980002 */  addu       $s3, $s0, $zero
    /* 7D32C 8008CB2C 5000A827 */  addiu      $t0, $sp, 0x50
    /* 7D330 8008CB30 6000A8AF */  sw         $t0, 0x60($sp)
    /* 7D334 8008CB34 21A00000 */  addu       $s4, $zero, $zero
  .L8008CB38:
    /* 7D338 8008CB38 32002016 */  bnez       $s1, .L8008CC04
    /* 7D33C 8008CB3C 00000000 */   nop
  .L8008CB40:
    /* 7D340 8008CB40 5835020C */  jal        func_8008D560
    /* 7D344 8008CB44 00000000 */   nop
    /* 7D348 8008CB48 1000A427 */  addiu      $a0, $sp, 0x10
    /* 7D34C 8008CB4C B0CE010C */  jal        func_80073AC0
    /* 7D350 8008CB50 3000A527 */   addiu     $a1, $sp, 0x30
    /* 7D354 8008CB54 21804000 */  addu       $s0, $v0, $zero
    /* 7D358 8008CB58 2F000016 */  bnez       $s0, .L8008CC18
    /* 7D35C 8008CB5C 2A103E02 */   slt       $v0, $s1, $fp
    /* 7D360 8008CB60 D035020C */  jal        func_8008D740
    /* 7D364 8008CB64 00000000 */   nop
    /* 7D368 8008CB68 DD33020C */  jal        func_8008CF74
    /* 7D36C 8008CB6C 21204000 */   addu      $a0, $v0, $zero
    /* 7D370 8008CB70 27004010 */  beqz       $v0, .L8008CC10
    /* 7D374 8008CB74 5800A2AF */   sw        $v0, 0x58($sp)
    /* 7D378 8008CB78 01005226 */  addiu      $s2, $s2, 0x1
    /* 7D37C 8008CB7C 0400422A */  slti       $v0, $s2, 0x4
    /* 7D380 8008CB80 EFFF4014 */  bnez       $v0, .L8008CB40
    /* 7D384 8008CB84 00000000 */   nop
    /* 7D388 8008CB88 3533020C */  jal        func_8008CCD4
    /* 7D38C 8008CB8C 21200000 */   addu      $a0, $zero, $zero
    /* 7D390 8008CB90 0000638E */  lw         $v1, 0x0($s3)
    /* 7D394 8008CB94 1080013C */  lui        $at, %hi(D_800FE3A0)
    /* 7D398 8008CB98 A0E322AC */  sw         $v0, %lo(D_800FE3A0)($at)
    /* 7D39C 8008CB9C 06006018 */  blez       $v1, .L8008CBB8
    /* 7D3A0 8008CBA0 02000824 */   addiu     $t0, $zero, 0x2
    /* 7D3A4 8008CBA4 0180043C */  lui        $a0, %hi(D_80012478)
    /* 7D3A8 8008CBA8 1C3A020C */  jal        func_8008E870
    /* 7D3AC 8008CBAC 78248424 */   addiu     $a0, $a0, %lo(D_80012478)
    /* 7D3B0 8008CBB0 F7320208 */  j          .L8008CBDC
    /* 7D3B4 8008CBB4 21200000 */   addu      $a0, $zero, $zero
  .L8008CBB8:
    /* 7D3B8 8008CBB8 0980043C */  lui        $a0, %hi(func_8008BCF8)
    /* 7D3BC 8008CBBC F8BC8424 */  addiu      $a0, $a0, %lo(func_8008BCF8)
    /* 7D3C0 8008CBC0 000068AE */  sw         $t0, 0x0($s3)
    /* 7D3C4 8008CBC4 040060AE */  sw         $zero, 0x4($s3)
    /* 7D3C8 8008CBC8 080060AE */  sw         $zero, 0x8($s3)
    /* 7D3CC 8008CBCC 1080013C */  lui        $at, %hi(D_800FE358)
    /* 7D3D0 8008CBD0 3834020C */  jal        func_8008D0E0
    /* 7D3D4 8008CBD4 58E336AC */   sw        $s6, %lo(D_800FE358)($at)
    /* 7D3D8 8008CBD8 21200000 */  addu       $a0, $zero, $zero
  .L8008CBDC:
    /* 7D3DC 8008CBDC 21280000 */  addu       $a1, $zero, $zero
    /* 7D3E0 8008CBE0 3A33020C */  jal        func_8008CCE8
    /* 7D3E4 8008CBE4 5800A627 */   addiu     $a2, $sp, 0x58
    /* 7D3E8 8008CBE8 1080043C */  lui        $a0, %hi(D_800FE3A0)
    /* 7D3EC 8008CBEC A0E3848C */  lw         $a0, %lo(D_800FE3A0)($a0)
    /* 7D3F0 8008CBF0 3533020C */  jal        func_8008CCD4
    /* 7D3F4 8008CBF4 00000000 */   nop
    /* 7D3F8 8008CBF8 5800A28F */  lw         $v0, 0x58($sp)
    /* 7D3FC 8008CBFC 29330208 */  j          .L8008CCA4
    /* 7D400 8008CC00 00000000 */   nop
  .L8008CC04:
    /* 7D404 8008CC04 48CE010C */  jal        func_80073920
    /* 7D408 8008CC08 3000A427 */   addiu     $a0, $sp, 0x30
    /* 7D40C 8008CC0C 21804000 */  addu       $s0, $v0, $zero
  .L8008CC10:
    /* 7D410 8008CC10 1F000012 */  beqz       $s0, .L8008CC90
    /* 7D414 8008CC14 2A103E02 */   slt       $v0, $s1, $fp
  .L8008CC18:
    /* 7D418 8008CC18 17004014 */  bnez       $v0, .L8008CC78
    /* 7D41C 8008CC1C 00000000 */   nop
    /* 7D420 8008CC20 1500E012 */  beqz       $s7, .L8008CC78
    /* 7D424 8008CC24 21389702 */   addu      $a3, $s4, $s7
    /* 7D428 8008CC28 3000A627 */  addiu      $a2, $sp, 0x30
  .L8008CC2C:
    /* 7D42C 8008CC2C 0000C28C */  lw         $v0, 0x0($a2)
    /* 7D430 8008CC30 0400C38C */  lw         $v1, 0x4($a2)
    /* 7D434 8008CC34 0800C48C */  lw         $a0, 0x8($a2)
    /* 7D438 8008CC38 0C00C58C */  lw         $a1, 0xC($a2)
    /* 7D43C 8008CC3C 0000E2AC */  sw         $v0, 0x0($a3)
    /* 7D440 8008CC40 0400E3AC */  sw         $v1, 0x4($a3)
    /* 7D444 8008CC44 0800E4AC */  sw         $a0, 0x8($a3)
    /* 7D448 8008CC48 0C00E5AC */  sw         $a1, 0xC($a3)
    /* 7D44C 8008CC4C 1000C624 */  addiu      $a2, $a2, 0x10
    /* 7D450 8008CC50 6000A88F */  lw         $t0, 0x60($sp)
    /* 7D454 8008CC54 00000000 */  nop
    /* 7D458 8008CC58 F4FFC814 */  bne        $a2, $t0, .L8008CC2C
    /* 7D45C 8008CC5C 1000E724 */   addiu     $a3, $a3, 0x10
    /* 7D460 8008CC60 0000C28C */  lw         $v0, 0x0($a2)
    /* 7D464 8008CC64 0400C38C */  lw         $v1, 0x4($a2)
    /* 7D468 8008CC68 0000E2AC */  sw         $v0, 0x0($a3)
    /* 7D46C 8008CC6C 0400E3AC */  sw         $v1, 0x4($a3)
    /* 7D470 8008CC70 28009426 */  addiu      $s4, $s4, 0x28
    /* 7D474 8008CC74 0100B526 */  addiu      $s5, $s5, 0x1
  .L8008CC78:
    /* 7D478 8008CC78 A400A88F */  lw         $t0, 0xA4($sp)
    /* 7D47C 8008CC7C 01003126 */  addiu      $s1, $s1, 0x1
    /* 7D480 8008CC80 2110C803 */  addu       $v0, $fp, $t0
    /* 7D484 8008CC84 2A102202 */  slt        $v0, $s1, $v0
    /* 7D488 8008CC88 ABFF4014 */  bnez       $v0, .L8008CB38
    /* 7D48C 8008CC8C 00000000 */   nop
  .L8008CC90:
    /* 7D490 8008CC90 5C00A88F */  lw         $t0, 0x5C($sp)
    /* 7D494 8008CC94 00000000 */  nop
    /* 7D498 8008CC98 02000011 */  beqz       $t0, .L8008CCA4
    /* 7D49C 8008CC9C 21100000 */   addu      $v0, $zero, $zero
    /* 7D4A0 8008CCA0 000015AD */  sw         $s5, 0x0($t0)
  .L8008CCA4:
    /* 7D4A4 8008CCA4 8C00BF8F */  lw         $ra, 0x8C($sp)
    /* 7D4A8 8008CCA8 8800BE8F */  lw         $fp, 0x88($sp)
    /* 7D4AC 8008CCAC 8400B78F */  lw         $s7, 0x84($sp)
    /* 7D4B0 8008CCB0 8000B68F */  lw         $s6, 0x80($sp)
    /* 7D4B4 8008CCB4 7C00B58F */  lw         $s5, 0x7C($sp)
    /* 7D4B8 8008CCB8 7800B48F */  lw         $s4, 0x78($sp)
    /* 7D4BC 8008CCBC 7400B38F */  lw         $s3, 0x74($sp)
    /* 7D4C0 8008CCC0 7000B28F */  lw         $s2, 0x70($sp)
    /* 7D4C4 8008CCC4 6C00B18F */  lw         $s1, 0x6C($sp)
    /* 7D4C8 8008CCC8 6800B08F */  lw         $s0, 0x68($sp)
    /* 7D4CC 8008CCCC 0800E003 */  jr         $ra
    /* 7D4D0 8008CCD0 9000BD27 */   addiu     $sp, $sp, 0x90
endlabel func_8008CA78
