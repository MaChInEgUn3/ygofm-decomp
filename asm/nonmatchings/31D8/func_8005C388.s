nonmatching func_8005C388, 0xDC

glabel func_8005C388
    /* 4CB88 8005C388 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 4CB8C 8005C38C 2000B0AF */  sw         $s0, 0x20($sp)
    /* 4CB90 8005C390 21808000 */  addu       $s0, $a0, $zero
    /* 4CB94 8005C394 2800B2AF */  sw         $s2, 0x28($sp)
    /* 4CB98 8005C398 2190A000 */  addu       $s2, $a1, $zero
    /* 4CB9C 8005C39C 2400B1AF */  sw         $s1, 0x24($sp)
    /* 4CBA0 8005C3A0 2188C000 */  addu       $s1, $a2, $zero
    /* 4CBA4 8005C3A4 0980023C */  lui        $v0, %hi(D_8009151C)
    /* 4CBA8 8005C3A8 1C154524 */  addiu      $a1, $v0, %lo(D_8009151C)
    /* 4CBAC 8005C3AC 80101000 */  sll        $v0, $s0, 2
    /* 4CBB0 8005C3B0 21184500 */  addu       $v1, $v0, $a1
    /* 4CBB4 8005C3B4 3000BFAF */  sw         $ra, 0x30($sp)
    /* 4CBB8 8005C3B8 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 4CBBC 8005C3BC 02006294 */  lhu        $v0, 0x2($v1)
    /* 4CBC0 8005C3C0 00000000 */  nop
    /* 4CBC4 8005C3C4 02004010 */  beqz       $v0, .L8005C3D0
    /* 4CBC8 8005C3C8 2198E000 */   addu      $s3, $a3, $zero
    /* 4CBCC 8005C3CC 21884000 */  addu       $s1, $v0, $zero
  .L8005C3D0:
    /* 4CBD0 8005C3D0 21200000 */  addu       $a0, $zero, $zero
    /* 4CBD4 8005C3D4 0800001A */  blez       $s0, .L8005C3F8
    /* 4CBD8 8005C3D8 21308000 */   addu      $a2, $a0, $zero
    /* 4CBDC 8005C3DC 2118A000 */  addu       $v1, $a1, $zero
  .L8005C3E0:
    /* 4CBE0 8005C3E0 00006294 */  lhu        $v0, 0x0($v1)
    /* 4CBE4 8005C3E4 01008424 */  addiu      $a0, $a0, 0x1
    /* 4CBE8 8005C3E8 2130C200 */  addu       $a2, $a2, $v0
    /* 4CBEC 8005C3EC 2A109000 */  slt        $v0, $a0, $s0
    /* 4CBF0 8005C3F0 FBFF4014 */  bnez       $v0, .L8005C3E0
    /* 4CBF4 8005C3F4 04006324 */   addiu     $v1, $v1, 0x4
  .L8005C3F8:
    /* 4CBF8 8005C3F8 0F80023C */  lui        $v0, %hi(D_800E9EB4)
    /* 4CBFC 8005C3FC B49E448C */  lw         $a0, %lo(D_800E9EB4)($v0)
    /* 4CC00 8005C400 1800A527 */  addiu      $a1, $sp, 0x18
    /* 4CC04 8005C404 80F9010C */  jal        func_8007E600
    /* 4CC08 8005C408 21208600 */   addu      $a0, $a0, $a2
    /* 4CC0C 8005C40C C4F9010C */  jal        func_8007E710
    /* 4CC10 8005C410 1800A427 */   addiu     $a0, $sp, 0x18
    /* 4CC14 8005C414 1800A427 */  addiu      $a0, $sp, 0x18
    /* 4CC18 8005C418 0980053C */  lui        $a1, %hi(D_8009151C)
    /* 4CC1C 8005C41C 1C15A524 */  addiu      $a1, $a1, %lo(D_8009151C)
    /* 4CC20 8005C420 80181000 */  sll        $v1, $s0, 2
    /* 4CC24 8005C424 21186500 */  addu       $v1, $v1, $a1
    /* 4CC28 8005C428 21284002 */  addu       $a1, $s2, $zero
    /* 4CC2C 8005C42C 00006794 */  lhu        $a3, 0x0($v1)
    /* 4CC30 8005C430 4800A38F */  lw         $v1, 0x48($sp)
    /* 4CC34 8005C434 21302002 */  addu       $a2, $s1, $zero
    /* 4CC38 8005C438 1000B3AF */  sw         $s3, 0x10($sp)
    /* 4CC3C 8005C43C 21384700 */  addu       $a3, $v0, $a3
    /* 4CC40 8005C440 286E010C */  jal        func_8005B8A0
    /* 4CC44 8005C444 1400A3AF */   sw        $v1, 0x14($sp)
    /* 4CC48 8005C448 3000BF8F */  lw         $ra, 0x30($sp)
    /* 4CC4C 8005C44C 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 4CC50 8005C450 2800B28F */  lw         $s2, 0x28($sp)
    /* 4CC54 8005C454 2400B18F */  lw         $s1, 0x24($sp)
    /* 4CC58 8005C458 2000B08F */  lw         $s0, 0x20($sp)
    /* 4CC5C 8005C45C 0800E003 */  jr         $ra
    /* 4CC60 8005C460 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8005C388
