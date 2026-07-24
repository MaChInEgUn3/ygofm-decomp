nonmatching func_8007AA94, 0x1F0

glabel func_8007AA94
    /* 6B294 8007AA94 88FFBD27 */  addiu      $sp, $sp, -0x78
    /* 6B298 8007AA98 6C00B7AF */  sw         $s7, 0x6C($sp)
    /* 6B29C 8007AA9C 21B8A000 */  addu       $s7, $a1, $zero
    /* 6B2A0 8007AAA0 6800B6AF */  sw         $s6, 0x68($sp)
    /* 6B2A4 8007AAA4 21B08000 */  addu       $s6, $a0, $zero
    /* 6B2A8 8007AAA8 5400B1AF */  sw         $s1, 0x54($sp)
    /* 6B2AC 8007AAAC 21880000 */  addu       $s1, $zero, $zero
    /* 6B2B0 8007AAB0 1000A327 */  addiu      $v1, $sp, 0x10
    /* 6B2B4 8007AAB4 7400BFAF */  sw         $ra, 0x74($sp)
    /* 6B2B8 8007AAB8 7000BEAF */  sw         $fp, 0x70($sp)
    /* 6B2BC 8007AABC 6400B5AF */  sw         $s5, 0x64($sp)
    /* 6B2C0 8007AAC0 6000B4AF */  sw         $s4, 0x60($sp)
    /* 6B2C4 8007AAC4 5C00B3AF */  sw         $s3, 0x5C($sp)
    /* 6B2C8 8007AAC8 5800B2AF */  sw         $s2, 0x58($sp)
    /* 6B2CC 8007AACC 5000B0AF */  sw         $s0, 0x50($sp)
  .L8007AAD0:
    /* 6B2D0 8007AAD0 000060AC */  sw         $zero, 0x0($v1)
    /* 6B2D4 8007AAD4 040060AC */  sw         $zero, 0x4($v1)
    /* 6B2D8 8007AAD8 01003126 */  addiu      $s1, $s1, 0x1
    /* 6B2DC 8007AADC 0800222A */  slti       $v0, $s1, 0x8
    /* 6B2E0 8007AAE0 FBFF4014 */  bnez       $v0, .L8007AAD0
    /* 6B2E4 8007AAE4 08006324 */   addiu     $v1, $v1, 0x8
    /* 6B2E8 8007AAE8 0F80033C */  lui        $v1, %hi(D_800F5EE0)
    /* 6B2EC 8007AAEC E05E6324 */  addiu      $v1, $v1, %lo(D_800F5EE0)
    /* 6B2F0 8007AAF0 21200000 */  addu       $a0, $zero, $zero
    /* 6B2F4 8007AAF4 FFFF1524 */  addiu      $s5, $zero, -0x1
    /* 6B2F8 8007AAF8 0800628C */  lw         $v0, 0x8($v1)
    /* 6B2FC 8007AAFC 0000748C */  lw         $s4, 0x0($v1)
    /* 6B300 8007AB00 30004018 */  blez       $v0, .L8007ABC4
    /* 6B304 8007AB04 21880000 */   addu      $s1, $zero, $zero
    /* 6B308 8007AB08 1000BE27 */  addiu      $fp, $sp, 0x10
    /* 6B30C 8007AB0C 40101400 */  sll        $v0, $s4, 1
    /* 6B310 8007AB10 21105400 */  addu       $v0, $v0, $s4
    /* 6B314 8007AB14 C0980200 */  sll        $s3, $v0, 3
    /* 6B318 8007AB18 0800B227 */  addiu      $s2, $sp, 0x8
  .L8007AB1C:
    /* 6B31C 8007AB1C 0F80103C */  lui        $s0, %hi(D_800F5E20)
    /* 6B320 8007AB20 21801302 */  addu       $s0, $s0, $s3
    /* 6B324 8007AB24 205E108E */  lw         $s0, %lo(D_800F5E20)($s0)
    /* 6B328 8007AB28 00000000 */  nop
    /* 6B32C 8007AB2C 05000412 */  beq        $s0, $a0, .L8007AB44
    /* 6B330 8007AB30 FF00C532 */   andi      $a1, $s6, 0xFF
    /* 6B334 8007AB34 21200002 */  addu       $a0, $s0, $zero
    /* 6B338 8007AB38 C6EB010C */  jal        func_8007AF18
    /* 6B33C 8007AB3C 2130E002 */   addu      $a2, $s7, $zero
    /* 6B340 8007AB40 21200002 */  addu       $a0, $s0, $zero
  .L8007AB44:
    /* 6B344 8007AB44 0F80033C */  lui        $v1, %hi(D_800F5E30)
    /* 6B348 8007AB48 21187300 */  addu       $v1, $v1, $s3
    /* 6B34C 8007AB4C 305E638C */  lw         $v1, %lo(D_800F5E30)($v1)
    /* 6B350 8007AB50 00000000 */  nop
    /* 6B354 8007AB54 0F006010 */  beqz       $v1, .L8007AB94
    /* 6B358 8007AB58 FFFF0724 */   addiu     $a3, $zero, -0x1
    /* 6B35C 8007AB5C 0500A716 */  bne        $s5, $a3, .L8007AB74
    /* 6B360 8007AB60 00000000 */   nop
    /* 6B364 8007AB64 2190C003 */  addu       $s2, $fp, $zero
    /* 6B368 8007AB68 21A80000 */  addu       $s5, $zero, $zero
    /* 6B36C 8007AB6C E4EA0108 */  j          .L8007AB90
    /* 6B370 8007AB70 1000B0AF */   sw        $s0, 0x10($sp)
  .L8007AB74:
    /* 6B374 8007AB74 0000428E */  lw         $v0, 0x0($s2)
    /* 6B378 8007AB78 00000000 */  nop
    /* 6B37C 8007AB7C 05005010 */  beq        $v0, $s0, .L8007AB94
    /* 6B380 8007AB80 00000000 */   nop
    /* 6B384 8007AB84 08005226 */  addiu      $s2, $s2, 0x8
    /* 6B388 8007AB88 0100B526 */  addiu      $s5, $s5, 0x1
    /* 6B38C 8007AB8C 000050AE */  sw         $s0, 0x0($s2)
  .L8007AB90:
    /* 6B390 8007AB90 040043AE */  sw         $v1, 0x4($s2)
  .L8007AB94:
    /* 6B394 8007AB94 01009426 */  addiu      $s4, $s4, 0x1
    /* 6B398 8007AB98 0800822A */  slti       $v0, $s4, 0x8
    /* 6B39C 8007AB9C 03004014 */  bnez       $v0, .L8007ABAC
    /* 6B3A0 8007ABA0 18007326 */   addiu     $s3, $s3, 0x18
    /* 6B3A4 8007ABA4 21980000 */  addu       $s3, $zero, $zero
    /* 6B3A8 8007ABA8 21A00000 */  addu       $s4, $zero, $zero
  .L8007ABAC:
    /* 6B3AC 8007ABAC 0F80023C */  lui        $v0, %hi(D_800F5EE8)
    /* 6B3B0 8007ABB0 E85E428C */  lw         $v0, %lo(D_800F5EE8)($v0)
    /* 6B3B4 8007ABB4 01003126 */  addiu      $s1, $s1, 0x1
    /* 6B3B8 8007ABB8 2A102202 */  slt        $v0, $s1, $v0
    /* 6B3BC 8007ABBC D7FF4014 */  bnez       $v0, .L8007AB1C
    /* 6B3C0 8007ABC0 00000000 */   nop
  .L8007ABC4:
    /* 6B3C4 8007ABC4 21280000 */  addu       $a1, $zero, $zero
    /* 6B3C8 8007ABC8 0F80043C */  lui        $a0, %hi(D_800F5E20)
    /* 6B3CC 8007ABCC 205E8424 */  addiu      $a0, $a0, %lo(D_800F5E20)
    /* 6B3D0 8007ABD0 0F80013C */  lui        $at, %hi(D_800F5EE8)
    /* 6B3D4 8007ABD4 E85E20AC */  sw         $zero, %lo(D_800F5EE8)($at)
    /* 6B3D8 8007ABD8 0F80013C */  lui        $at, %hi(D_800F5EE4)
    /* 6B3DC 8007ABDC E45E20AC */  sw         $zero, %lo(D_800F5EE4)($at)
    /* 6B3E0 8007ABE0 0F80013C */  lui        $at, %hi(D_800F5EE0)
    /* 6B3E4 8007ABE4 E05E20AC */  sw         $zero, %lo(D_800F5EE0)($at)
  .L8007ABE8:
    /* 6B3E8 8007ABE8 03000324 */  addiu      $v1, $zero, 0x3
    /* 6B3EC 8007ABEC 03008224 */  addiu      $v0, $a0, 0x3
    /* 6B3F0 8007ABF0 000080AC */  sw         $zero, 0x0($a0)
    /* 6B3F4 8007ABF4 040080A0 */  sb         $zero, 0x4($a0)
  .L8007ABF8:
    /* 6B3F8 8007ABF8 050040A0 */  sb         $zero, 0x5($v0)
    /* 6B3FC 8007ABFC FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 6B400 8007AC00 FDFF6104 */  bgez       $v1, .L8007ABF8
    /* 6B404 8007AC04 FFFF4224 */   addiu     $v0, $v0, -0x1
    /* 6B408 8007AC08 0C0080AC */  sw         $zero, 0xC($a0)
    /* 6B40C 8007AC0C 100080AC */  sw         $zero, 0x10($a0)
    /* 6B410 8007AC10 140080AC */  sw         $zero, 0x14($a0)
    /* 6B414 8007AC14 0100A524 */  addiu      $a1, $a1, 0x1
    /* 6B418 8007AC18 0800A228 */  slti       $v0, $a1, 0x8
    /* 6B41C 8007AC1C F2FF4014 */  bnez       $v0, .L8007ABE8
    /* 6B420 8007AC20 18008424 */   addiu     $a0, $a0, 0x18
    /* 6B424 8007AC24 0B00A006 */  bltz       $s5, .L8007AC54
    /* 6B428 8007AC28 21880000 */   addu      $s1, $zero, $zero
    /* 6B42C 8007AC2C 1000B027 */  addiu      $s0, $sp, 0x10
    /* 6B430 8007AC30 FF00C432 */  andi       $a0, $s6, 0xFF
  .L8007AC34:
    /* 6B434 8007AC34 2128E002 */  addu       $a1, $s7, $zero
    /* 6B438 8007AC38 0400028E */  lw         $v0, 0x4($s0)
    /* 6B43C 8007AC3C 08001026 */  addiu      $s0, $s0, 0x8
    /* 6B440 8007AC40 09F84000 */  jalr       $v0
    /* 6B444 8007AC44 01003126 */   addiu     $s1, $s1, 0x1
    /* 6B448 8007AC48 2A10B102 */  slt        $v0, $s5, $s1
    /* 6B44C 8007AC4C F9FF4010 */  beqz       $v0, .L8007AC34
    /* 6B450 8007AC50 FF00C432 */   andi      $a0, $s6, 0xFF
  .L8007AC54:
    /* 6B454 8007AC54 7400BF8F */  lw         $ra, 0x74($sp)
    /* 6B458 8007AC58 7000BE8F */  lw         $fp, 0x70($sp)
    /* 6B45C 8007AC5C 6C00B78F */  lw         $s7, 0x6C($sp)
    /* 6B460 8007AC60 6800B68F */  lw         $s6, 0x68($sp)
    /* 6B464 8007AC64 6400B58F */  lw         $s5, 0x64($sp)
    /* 6B468 8007AC68 6000B48F */  lw         $s4, 0x60($sp)
    /* 6B46C 8007AC6C 5C00B38F */  lw         $s3, 0x5C($sp)
    /* 6B470 8007AC70 5800B28F */  lw         $s2, 0x58($sp)
    /* 6B474 8007AC74 5400B18F */  lw         $s1, 0x54($sp)
    /* 6B478 8007AC78 5000B08F */  lw         $s0, 0x50($sp)
    /* 6B47C 8007AC7C 0800E003 */  jr         $ra
    /* 6B480 8007AC80 7800BD27 */   addiu     $sp, $sp, 0x78
endlabel func_8007AA94
