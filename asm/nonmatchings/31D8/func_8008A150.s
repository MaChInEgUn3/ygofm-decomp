nonmatching func_8008A150, 0x12C

glabel func_8008A150
    /* 7A950 8008A150 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 7A954 8008A154 2400BFAF */  sw         $ra, 0x24($sp)
    /* 7A958 8008A158 2000B4AF */  sw         $s4, 0x20($sp)
    /* 7A95C 8008A15C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 7A960 8008A160 1800B2AF */  sw         $s2, 0x18($sp)
    /* 7A964 8008A164 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7A968 8008A168 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7A96C 8008A16C 0400828C */  lw         $v0, 0x4($a0)
    /* 7A970 8008A170 2188C000 */  addu       $s1, $a2, $zero
    /* 7A974 8008A174 000022AE */  sw         $v0, 0x0($s1)
    /* 7A978 8008A178 0400938C */  lw         $s3, 0x4($a0)
    /* 7A97C 8008A17C 040025AE */  sw         $a1, 0x4($s1)
    /* 7A980 8008A180 0000A38C */  lw         $v1, 0x0($a1)
    /* 7A984 8008A184 0E000224 */  addiu      $v0, $zero, 0xE
    /* 7A988 8008A188 23104300 */  subu       $v0, $v0, $v1
    /* 7A98C 8008A18C 080022AE */  sw         $v0, 0x8($s1)
    /* 7A990 8008A190 0800A38C */  lw         $v1, 0x8($a1)
    /* 7A994 8008A194 1080023C */  lui        $v0, %hi(D_800FE240)
    /* 7A998 8008A198 40E2428C */  lw         $v0, %lo(D_800FE240)($v0)
    /* 7A99C 8008A19C FFFF1424 */  addiu      $s4, $zero, -0x1
    /* 7A9A0 8008A1A0 100022AE */  sw         $v0, 0x10($s1)
    /* 7A9A4 8008A1A4 0C0023AE */  sw         $v1, 0xC($s1)
    /* 7A9A8 8008A1A8 21106002 */  addu       $v0, $s3, $zero
  .L8008A1AC:
    /* 7A9AC 8008A1AC 000033AE */  sw         $s3, 0x0($s1)
    /* 7A9B0 8008A1B0 0000738E */  lw         $s3, 0x0($s3)
    /* 7A9B4 8008A1B4 04004324 */  addiu      $v1, $v0, 0x4
    /* 7A9B8 8008A1B8 000023AE */  sw         $v1, 0x0($s1)
    /* 7A9BC 8008A1BC 0400458C */  lw         $a1, 0x4($v0)
    /* 7A9C0 8008A1C0 00000000 */  nop
    /* 7A9C4 8008A1C4 0000A28C */  lw         $v0, 0x0($a1)
    /* 7A9C8 8008A1C8 00000000 */  nop
    /* 7A9CC 8008A1CC 0C004010 */  beqz       $v0, .L8008A200
    /* 7A9D0 8008A1D0 21800000 */   addu      $s0, $zero, $zero
    /* 7A9D4 8008A1D4 14002426 */  addiu      $a0, $s1, 0x14
    /* 7A9D8 8008A1D8 2118A000 */  addu       $v1, $a1, $zero
  .L8008A1DC:
    /* 7A9DC 8008A1DC 0400628C */  lw         $v0, 0x4($v1)
    /* 7A9E0 8008A1E0 04006324 */  addiu      $v1, $v1, 0x4
    /* 7A9E4 8008A1E4 01001026 */  addiu      $s0, $s0, 0x1
    /* 7A9E8 8008A1E8 000082AC */  sw         $v0, 0x0($a0)
    /* 7A9EC 8008A1EC 0000A28C */  lw         $v0, 0x0($a1)
    /* 7A9F0 8008A1F0 00000000 */  nop
    /* 7A9F4 8008A1F4 2B100202 */  sltu       $v0, $s0, $v0
    /* 7A9F8 8008A1F8 F8FF4014 */  bnez       $v0, .L8008A1DC
    /* 7A9FC 8008A1FC 04008424 */   addiu     $a0, $a0, 0x4
  .L8008A200:
    /* 7AA00 8008A200 0000238E */  lw         $v1, 0x0($s1)
    /* 7AA04 8008A204 21800000 */  addu       $s0, $zero, $zero
    /* 7AA08 8008A208 04006224 */  addiu      $v0, $v1, 0x4
    /* 7AA0C 8008A20C 000022AE */  sw         $v0, 0x0($s1)
    /* 7AA10 8008A210 0400728C */  lw         $s2, 0x4($v1)
    /* 7AA14 8008A214 08006324 */  addiu      $v1, $v1, 0x8
    /* 7AA18 8008A218 0E004012 */  beqz       $s2, .L8008A254
    /* 7AA1C 8008A21C 000023AE */   sw        $v1, 0x0($s1)
  .L8008A220:
    /* 7AA20 8008A220 0000238E */  lw         $v1, 0x0($s1)
    /* 7AA24 8008A224 21202002 */  addu       $a0, $s1, $zero
    /* 7AA28 8008A228 0000628C */  lw         $v0, 0x0($v1)
    /* 7AA2C 8008A22C 04006324 */  addiu      $v1, $v1, 0x4
    /* 7AA30 8008A230 09F84000 */  jalr       $v0
    /* 7AA34 8008A234 000023AE */   sw        $v1, 0x0($s1)
    /* 7AA38 8008A238 1080033C */  lui        $v1, %hi(D_800FE240)
    /* 7AA3C 8008A23C 40E2638C */  lw         $v1, %lo(D_800FE240)($v1)
    /* 7AA40 8008A240 01001026 */  addiu      $s0, $s0, 0x1
    /* 7AA44 8008A244 000022AE */  sw         $v0, 0x0($s1)
    /* 7AA48 8008A248 2B101202 */  sltu       $v0, $s0, $s2
    /* 7AA4C 8008A24C F4FF4014 */  bnez       $v0, .L8008A220
    /* 7AA50 8008A250 100023AE */   sw        $v1, 0x10($s1)
  .L8008A254:
    /* 7AA54 8008A254 D5FF7416 */  bne        $s3, $s4, .L8008A1AC
    /* 7AA58 8008A258 21106002 */   addu      $v0, $s3, $zero
    /* 7AA5C 8008A25C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 7AA60 8008A260 2000B48F */  lw         $s4, 0x20($sp)
    /* 7AA64 8008A264 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 7AA68 8008A268 1800B28F */  lw         $s2, 0x18($sp)
    /* 7AA6C 8008A26C 1400B18F */  lw         $s1, 0x14($sp)
    /* 7AA70 8008A270 1000B08F */  lw         $s0, 0x10($sp)
    /* 7AA74 8008A274 0800E003 */  jr         $ra
    /* 7AA78 8008A278 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8008A150
    /* 7AA7C 8008A27C 00000000 */  nop
