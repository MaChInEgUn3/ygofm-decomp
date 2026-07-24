nonmatching func_8003A1EC, 0x254

glabel func_8003A1EC
    /* 2A9EC 8003A1EC B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 2A9F0 8003A1F0 3000B2AF */  sw         $s2, 0x30($sp)
    /* 2A9F4 8003A1F4 21908000 */  addu       $s2, $a0, $zero
    /* 2A9F8 8003A1F8 4800BEAF */  sw         $fp, 0x48($sp)
    /* 2A9FC 8003A1FC 21F0A000 */  addu       $fp, $a1, $zero
    /* 2AA00 8003A200 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 2AA04 8003A204 4400B7AF */  sw         $s7, 0x44($sp)
    /* 2AA08 8003A208 4000B6AF */  sw         $s6, 0x40($sp)
    /* 2AA0C 8003A20C 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 2AA10 8003A210 3800B4AF */  sw         $s4, 0x38($sp)
    /* 2AA14 8003A214 3400B3AF */  sw         $s3, 0x34($sp)
    /* 2AA18 8003A218 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 2AA1C 8003A21C 2800B0AF */  sw         $s0, 0x28($sp)
    /* 2AA20 8003A220 3C004292 */  lbu        $v0, 0x3C($s2)
    /* 2AA24 8003A224 00000000 */  nop
    /* 2AA28 8003A228 07004010 */  beqz       $v0, .L8003A248
    /* 2AA2C 8003A22C 21B0C000 */   addu      $s6, $a2, $zero
    /* 2AA30 8003A230 F6FF1524 */  addiu      $s5, $zero, -0xA
    /* 2AA34 8003A234 1B80023C */  lui        $v0, %hi(D_801AF800)
    /* 2AA38 8003A238 00F85124 */  addiu      $s1, $v0, %lo(D_801AF800)
    /* 2AA3C 8003A23C 1A001424 */  addiu      $s4, $zero, 0x1A
    /* 2AA40 8003A240 97E80008 */  j          .L8003A25C
    /* 2AA44 8003A244 02021324 */   addiu     $s3, $zero, 0x202
  .L8003A248:
    /* 2AA48 8003A248 F2FF1524 */  addiu      $s5, $zero, -0xE
    /* 2AA4C 8003A24C 1B80023C */  lui        $v0, %hi(D_801AF000)
    /* 2AA50 8003A250 00F05124 */  addiu      $s1, $v0, %lo(D_801AF000)
    /* 2AA54 8003A254 1D001424 */  addiu      $s4, $zero, 0x1D
    /* 2AA58 8003A258 00021324 */  addiu      $s3, $zero, 0x200
  .L8003A25C:
    /* 2AA5C 8003A25C 21202002 */  addu       $a0, $s1, $zero
    /* 2AA60 8003A260 2128C002 */  addu       $a1, $s6, $zero
    /* 2AA64 8003A264 21300000 */  addu       $a2, $zero, $zero
    /* 2AA68 8003A268 66E8000C */  jal        func_8003A198
    /* 2AA6C 8003A26C 2138C000 */   addu      $a3, $a2, $zero
    /* 2AA70 8003A270 67004010 */  beqz       $v0, .L8003A410
    /* 2AA74 8003A274 21100000 */   addu      $v0, $zero, $zero
    /* 2AA78 8003A278 0B00010C */  jal        func_8004002C
    /* 2AA7C 8003A27C 0041173C */   lui       $s7, (0x41000000 >> 16)
    /* 2AA80 8003A280 21204000 */  addu       $a0, $v0, $zero
    /* 2AA84 8003A284 2B00010C */  jal        func_800400AC
    /* 2AA88 8003A288 02000524 */   addiu     $a1, $zero, 0x2
    /* 2AA8C 8003A28C 21804000 */  addu       $s0, $v0, $zero
    /* 2AA90 8003A290 21200002 */  addu       $a0, $s0, $zero
    /* 2AA94 8003A294 34004586 */  lh         $a1, 0x34($s2)
    /* 2AA98 8003A298 36004686 */  lh         $a2, 0x36($s2)
    /* 2AA9C 8003A29C 2138C002 */  addu       $a3, $s6, $zero
    /* 2AAA0 8003A2A0 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2AAA4 8003A2A4 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2AAA8 8003A2A8 1800B4AF */  sw         $s4, 0x18($sp)
    /* 2AAAC 8003A2AC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2AAB0 8003A2B0 2A0A010C */  jal        func_800428A8
    /* 2AAB4 8003A2B4 2000B1AF */   sw        $s1, 0x20($sp)
    /* 2AAB8 8003A2B8 460A010C */  jal        func_80042918
    /* 2AABC 8003A2BC 21200002 */   addu      $a0, $s0, $zero
    /* 2AAC0 8003A2C0 21200002 */  addu       $a0, $s0, $zero
    /* 2AAC4 8003A2C4 3B0A010C */  jal        func_800428EC
    /* 2AAC8 8003A2C8 2128A002 */   addu      $a1, $s5, $zero
    /* 2AACC 8003A2CC 21202002 */  addu       $a0, $s1, $zero
    /* 2AAD0 8003A2D0 2128C002 */  addu       $a1, $s6, $zero
    /* 2AAD4 8003A2D4 01000624 */  addiu      $a2, $zero, 0x1
    /* 2AAD8 8003A2D8 21380000 */  addu       $a3, $zero, $zero
    /* 2AADC 8003A2DC 0400028E */  lw         $v0, 0x4($s0)
    /* 2AAE0 8003A2E0 08000396 */  lhu        $v1, 0x8($s0)
    /* 2AAE4 8003A2E4 25105700 */  or         $v0, $v0, $s7
    /* 2AAE8 8003A2E8 08006334 */  ori        $v1, $v1, 0x8
    /* 2AAEC 8003A2EC 040002AE */  sw         $v0, 0x4($s0)
    /* 2AAF0 8003A2F0 080003A6 */  sh         $v1, 0x8($s0)
    /* 2AAF4 8003A2F4 66E8000C */  jal        func_8003A198
    /* 2AAF8 8003A2F8 0000D0AF */   sw        $s0, 0x0($fp)
    /* 2AAFC 8003A2FC 1D004010 */  beqz       $v0, .L8003A374
    /* 2AB00 8003A300 21800000 */   addu      $s0, $zero, $zero
    /* 2AB04 8003A304 0B00010C */  jal        func_8004002C
    /* 2AB08 8003A308 00000000 */   nop
    /* 2AB0C 8003A30C 21204000 */  addu       $a0, $v0, $zero
    /* 2AB10 8003A310 2B00010C */  jal        func_800400AC
    /* 2AB14 8003A314 02000524 */   addiu     $a1, $zero, 0x2
    /* 2AB18 8003A318 21804000 */  addu       $s0, $v0, $zero
    /* 2AB1C 8003A31C 21200002 */  addu       $a0, $s0, $zero
    /* 2AB20 8003A320 2138C002 */  addu       $a3, $s6, $zero
    /* 2AB24 8003A324 34004586 */  lh         $a1, 0x34($s2)
    /* 2AB28 8003A328 36004686 */  lh         $a2, 0x36($s2)
    /* 2AB2C 8003A32C 01000224 */  addiu      $v0, $zero, 0x1
    /* 2AB30 8003A330 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2AB34 8003A334 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2AB38 8003A338 1800B4AF */  sw         $s4, 0x18($sp)
    /* 2AB3C 8003A33C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2AB40 8003A340 2A0A010C */  jal        func_800428A8
    /* 2AB44 8003A344 2000B1AF */   sw        $s1, 0x20($sp)
    /* 2AB48 8003A348 460A010C */  jal        func_80042918
    /* 2AB4C 8003A34C 21200002 */   addu      $a0, $s0, $zero
    /* 2AB50 8003A350 21200002 */  addu       $a0, $s0, $zero
    /* 2AB54 8003A354 3B0A010C */  jal        func_800428EC
    /* 2AB58 8003A358 0100A536 */   ori       $a1, $s5, 0x1
    /* 2AB5C 8003A35C 0400028E */  lw         $v0, 0x4($s0)
    /* 2AB60 8003A360 08000396 */  lhu        $v1, 0x8($s0)
    /* 2AB64 8003A364 25105700 */  or         $v0, $v0, $s7
    /* 2AB68 8003A368 08006334 */  ori        $v1, $v1, 0x8
    /* 2AB6C 8003A36C 040002AE */  sw         $v0, 0x4($s0)
    /* 2AB70 8003A370 080003A6 */  sh         $v1, 0x8($s0)
  .L8003A374:
    /* 2AB74 8003A374 0400D0AF */  sw         $s0, 0x4($fp)
    /* 2AB78 8003A378 21202002 */  addu       $a0, $s1, $zero
    /* 2AB7C 8003A37C 2128C002 */  addu       $a1, $s6, $zero
    /* 2AB80 8003A380 02000624 */  addiu      $a2, $zero, 0x2
    /* 2AB84 8003A384 66E8000C */  jal        func_8003A198
    /* 2AB88 8003A388 21380000 */   addu      $a3, $zero, $zero
    /* 2AB8C 8003A38C 1E004010 */  beqz       $v0, .L8003A408
    /* 2AB90 8003A390 21800000 */   addu      $s0, $zero, $zero
    /* 2AB94 8003A394 0B00010C */  jal        func_8004002C
    /* 2AB98 8003A398 00000000 */   nop
    /* 2AB9C 8003A39C 21204000 */  addu       $a0, $v0, $zero
    /* 2ABA0 8003A3A0 2B00010C */  jal        func_800400AC
    /* 2ABA4 8003A3A4 02000524 */   addiu     $a1, $zero, 0x2
    /* 2ABA8 8003A3A8 21804000 */  addu       $s0, $v0, $zero
    /* 2ABAC 8003A3AC 21200002 */  addu       $a0, $s0, $zero
    /* 2ABB0 8003A3B0 2138C002 */  addu       $a3, $s6, $zero
    /* 2ABB4 8003A3B4 34004586 */  lh         $a1, 0x34($s2)
    /* 2ABB8 8003A3B8 36004686 */  lh         $a2, 0x36($s2)
    /* 2ABBC 8003A3BC 02000224 */  addiu      $v0, $zero, 0x2
    /* 2ABC0 8003A3C0 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2ABC4 8003A3C4 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2ABC8 8003A3C8 1800B4AF */  sw         $s4, 0x18($sp)
    /* 2ABCC 8003A3CC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2ABD0 8003A3D0 2A0A010C */  jal        func_800428A8
    /* 2ABD4 8003A3D4 2000B1AF */   sw        $s1, 0x20($sp)
    /* 2ABD8 8003A3D8 460A010C */  jal        func_80042918
    /* 2ABDC 8003A3DC 21200002 */   addu      $a0, $s0, $zero
    /* 2ABE0 8003A3E0 21200002 */  addu       $a0, $s0, $zero
    /* 2ABE4 8003A3E4 3B0A010C */  jal        func_800428EC
    /* 2ABE8 8003A3E8 0100A536 */   ori       $a1, $s5, 0x1
    /* 2ABEC 8003A3EC 0041043C */  lui        $a0, (0x41000000 >> 16)
    /* 2ABF0 8003A3F0 0400028E */  lw         $v0, 0x4($s0)
    /* 2ABF4 8003A3F4 08000396 */  lhu        $v1, 0x8($s0)
    /* 2ABF8 8003A3F8 25104400 */  or         $v0, $v0, $a0
    /* 2ABFC 8003A3FC 08006334 */  ori        $v1, $v1, 0x8
    /* 2AC00 8003A400 040002AE */  sw         $v0, 0x4($s0)
    /* 2AC04 8003A404 080003A6 */  sh         $v1, 0x8($s0)
  .L8003A408:
    /* 2AC08 8003A408 0800D0AF */  sw         $s0, 0x8($fp)
    /* 2AC0C 8003A40C 01000224 */  addiu      $v0, $zero, 0x1
  .L8003A410:
    /* 2AC10 8003A410 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 2AC14 8003A414 4800BE8F */  lw         $fp, 0x48($sp)
    /* 2AC18 8003A418 4400B78F */  lw         $s7, 0x44($sp)
    /* 2AC1C 8003A41C 4000B68F */  lw         $s6, 0x40($sp)
    /* 2AC20 8003A420 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 2AC24 8003A424 3800B48F */  lw         $s4, 0x38($sp)
    /* 2AC28 8003A428 3400B38F */  lw         $s3, 0x34($sp)
    /* 2AC2C 8003A42C 3000B28F */  lw         $s2, 0x30($sp)
    /* 2AC30 8003A430 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 2AC34 8003A434 2800B08F */  lw         $s0, 0x28($sp)
    /* 2AC38 8003A438 0800E003 */  jr         $ra
    /* 2AC3C 8003A43C 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_8003A1EC
