nonmatching func_8005F27C, 0x13C

glabel func_8005F27C
    /* 4FA7C 8005F27C C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 4FA80 8005F280 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 4FA84 8005F284 21988000 */  addu       $s3, $a0, $zero
    /* 4FA88 8005F288 3000B4AF */  sw         $s4, 0x30($sp)
    /* 4FA8C 8005F28C 21A0C000 */  addu       $s4, $a2, $zero
    /* 4FA90 8005F290 C0280500 */  sll        $a1, $a1, 3
    /* 4FA94 8005F294 0980023C */  lui        $v0, %hi(D_80091570)
    /* 4FA98 8005F298 70154224 */  addiu      $v0, $v0, %lo(D_80091570)
    /* 4FA9C 8005F29C 2400B1AF */  sw         $s1, 0x24($sp)
    /* 4FAA0 8005F2A0 2188A200 */  addu       $s1, $a1, $v0
    /* 4FAA4 8005F2A4 73018393 */  lbu        $v1, %gp_rel(D_8009B07B)($gp)
    /* 4FAA8 8005F2A8 01000224 */  addiu      $v0, $zero, 0x1
    /* 4FAAC 8005F2AC 3400BFAF */  sw         $ra, 0x34($sp)
    /* 4FAB0 8005F2B0 2800B2AF */  sw         $s2, 0x28($sp)
    /* 4FAB4 8005F2B4 05006214 */  bne        $v1, $v0, .L8005F2CC
    /* 4FAB8 8005F2B8 2000B0AF */   sw        $s0, 0x20($sp)
    /* 4FABC 8005F2BC 74018293 */  lbu        $v0, %gp_rel(D_8009B07C)($gp)
    /* 4FAC0 8005F2C0 00000000 */  nop
    /* 4FAC4 8005F2C4 34004310 */  beq        $v0, $v1, .L8005F398
    /* 4FAC8 8005F2C8 00000000 */   nop
  .L8005F2CC:
    /* 4FACC 8005F2CC 00002296 */  lhu        $v0, 0x0($s1)
    /* 4FAD0 8005F2D0 00000000 */  nop
    /* 4FAD4 8005F2D4 00940200 */  sll        $s2, $v0, 16
    /* 4FAD8 8005F2D8 0200622A */  slti       $v0, $s3, 0x2
    /* 4FADC 8005F2DC 28004010 */  beqz       $v0, .L8005F380
    /* 4FAE0 8005F2E0 03841200 */   sra       $s0, $s2, 16
    /* 4FAE4 8005F2E4 21206002 */  addu       $a0, $s3, $zero
    /* 4FAE8 8005F2E8 0064010C */  jal        func_80059000
    /* 4FAEC 8005F2EC 1800A527 */   addiu     $a1, $sp, 0x18
    /* 4FAF0 8005F2F0 1E00A287 */  lh         $v0, 0x1E($sp)
    /* 4FAF4 8005F2F4 00000000 */  nop
    /* 4FAF8 8005F2F8 32004228 */  slti       $v0, $v0, 0x32
    /* 4FAFC 8005F2FC 02004010 */  beqz       $v0, .L8005F308
    /* 4FB00 8005F300 32000224 */   addiu     $v0, $zero, 0x32
    /* 4FB04 8005F304 1E00A2A7 */  sh         $v0, 0x1E($sp)
  .L8005F308:
    /* 4FB08 8005F308 1E00A297 */  lhu        $v0, 0x1E($sp)
    /* 4FB0C 8005F30C 00000000 */  nop
    /* 4FB10 8005F310 D4FE4224 */  addiu      $v0, $v0, -0x12C
    /* 4FB14 8005F314 1E00A2A7 */  sh         $v0, 0x1E($sp)
    /* 4FB18 8005F318 00140200 */  sll        $v0, $v0, 16
    /* 4FB1C 8005F31C 031C0200 */  sra        $v1, $v0, 16
    /* 4FB20 8005F320 17006010 */  beqz       $v1, .L8005F380
    /* 4FB24 8005F324 21100002 */   addu      $v0, $s0, $zero
    /* 4FB28 8005F328 04006018 */  blez       $v1, .L8005F33C
    /* 4FB2C 8005F32C EE020424 */   addiu     $a0, $zero, 0x2EE
    /* 4FB30 8005F330 C2171200 */  srl        $v0, $s2, 31
    /* 4FB34 8005F334 21100202 */  addu       $v0, $s0, $v0
    /* 4FB38 8005F338 43100200 */  sra        $v0, $v0, 1
  .L8005F33C:
    /* 4FB3C 8005F33C 18006200 */  mult       $v1, $v0
    /* 4FB40 8005F340 12100000 */  mflo       $v0
    /* 4FB44 8005F344 00000000 */  nop
    /* 4FB48 8005F348 00000000 */  nop
    /* 4FB4C 8005F34C 1A004400 */  div        $zero, $v0, $a0
    /* 4FB50 8005F350 02008014 */  bnez       $a0, .L8005F35C
    /* 4FB54 8005F354 00000000 */   nop
    /* 4FB58 8005F358 0D000700 */  break      7
  .L8005F35C:
    /* 4FB5C 8005F35C FFFF0124 */  addiu      $at, $zero, -0x1
    /* 4FB60 8005F360 04008114 */  bne        $a0, $at, .L8005F374
    /* 4FB64 8005F364 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 4FB68 8005F368 02004114 */  bne        $v0, $at, .L8005F374
    /* 4FB6C 8005F36C 00000000 */   nop
    /* 4FB70 8005F370 0D000600 */  break      6
  .L8005F374:
    /* 4FB74 8005F374 12100000 */  mflo       $v0
    /* 4FB78 8005F378 00000000 */  nop
    /* 4FB7C 8005F37C 21800202 */  addu       $s0, $s0, $v0
  .L8005F380:
    /* 4FB80 8005F380 21206002 */  addu       $a0, $s3, $zero
    /* 4FB84 8005F384 02002686 */  lh         $a2, 0x2($s1)
    /* 4FB88 8005F388 04002786 */  lh         $a3, 0x4($s1)
    /* 4FB8C 8005F38C 21280002 */  addu       $a1, $s0, $zero
    /* 4FB90 8005F390 EE7C010C */  jal        func_8005F3B8
    /* 4FB94 8005F394 1000B4AF */   sw        $s4, 0x10($sp)
  .L8005F398:
    /* 4FB98 8005F398 3400BF8F */  lw         $ra, 0x34($sp)
    /* 4FB9C 8005F39C 3000B48F */  lw         $s4, 0x30($sp)
    /* 4FBA0 8005F3A0 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 4FBA4 8005F3A4 2800B28F */  lw         $s2, 0x28($sp)
    /* 4FBA8 8005F3A8 2400B18F */  lw         $s1, 0x24($sp)
    /* 4FBAC 8005F3AC 2000B08F */  lw         $s0, 0x20($sp)
    /* 4FBB0 8005F3B0 0800E003 */  jr         $ra
    /* 4FBB4 8005F3B4 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8005F27C
