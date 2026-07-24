nonmatching func_8003D174, 0x114

glabel func_8003D174
    /* 2D974 8003D174 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2D978 8003D178 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2D97C 8003D17C 21908000 */  addu       $s2, $a0, $zero
    /* 2D980 8003D180 40030524 */  addiu      $a1, $zero, 0x340
    /* 2D984 8003D184 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 2D988 8003D188 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2D98C 8003D18C AEF3000C */  jal        func_8003CEB8
    /* 2D990 8003D190 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2D994 8003D194 FFFF4330 */  andi       $v1, $v0, 0xFFFF
    /* 2D998 8003D198 78035126 */  addiu      $s1, $s2, 0x378
    /* 2D99C 8003D19C 0F001024 */  addiu      $s0, $zero, 0xF
    /* 2D9A0 8003D1A0 00140300 */  sll        $v0, $v1, 16
    /* 2D9A4 8003D1A4 25106200 */  or         $v0, $v1, $v0
    /* 2D9A8 8003D1A8 600082AF */  sw         $v0, %gp_rel(D_8009AF68)($gp)
    /* 2D9AC 8003D1AC 5C0082AF */  sw         $v0, %gp_rel(D_8009AF64)($gp)
  .L8003D1B0:
    /* 2D9B0 8003D1B0 9DF3000C */  jal        func_8003CE74
    /* 2D9B4 8003D1B4 00000000 */   nop
    /* 2D9B8 8003D1B8 0000238E */  lw         $v1, 0x0($s1)
    /* 2D9BC 8003D1BC 00000000 */  nop
    /* 2D9C0 8003D1C0 2B006214 */  bne        $v1, $v0, .L8003D270
    /* 2D9C4 8003D1C4 21100000 */   addu      $v0, $zero, $zero
    /* 2D9C8 8003D1C8 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 2D9CC 8003D1CC F8FF0016 */  bnez       $s0, .L8003D1B0
    /* 2D9D0 8003D1D0 FCFF3126 */   addiu     $s1, $s1, -0x4
    /* 2D9D4 8003D1D4 80034426 */  addiu      $a0, $s2, 0x380
    /* 2D9D8 8003D1D8 AEF3000C */  jal        func_8003CEB8
    /* 2D9DC 8003D1DC 6C000524 */   addiu     $a1, $zero, 0x6C
    /* 2D9E0 8003D1E0 FFFF4330 */  andi       $v1, $v0, 0xFFFF
    /* 2D9E4 8003D1E4 F8035126 */  addiu      $s1, $s2, 0x3F8
    /* 2D9E8 8003D1E8 04001024 */  addiu      $s0, $zero, 0x4
    /* 2D9EC 8003D1EC 00140300 */  sll        $v0, $v1, 16
    /* 2D9F0 8003D1F0 25106200 */  or         $v0, $v1, $v0
    /* 2D9F4 8003D1F4 600082AF */  sw         $v0, %gp_rel(D_8009AF68)($gp)
    /* 2D9F8 8003D1F8 5C0082AF */  sw         $v0, %gp_rel(D_8009AF64)($gp)
  .L8003D1FC:
    /* 2D9FC 8003D1FC 9DF3000C */  jal        func_8003CE74
    /* 2DA00 8003D200 00000000 */   nop
    /* 2DA04 8003D204 0000238E */  lw         $v1, 0x0($s1)
    /* 2DA08 8003D208 00000000 */  nop
    /* 2DA0C 8003D20C 18006214 */  bne        $v1, $v0, .L8003D270
    /* 2DA10 8003D210 21100000 */   addu      $v0, $zero, $zero
    /* 2DA14 8003D214 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 2DA18 8003D218 F8FF0016 */  bnez       $s0, .L8003D1FC
    /* 2DA1C 8003D21C FCFF3126 */   addiu     $s1, $s1, -0x4
    /* 2DA20 8003D220 00044426 */  addiu      $a0, $s2, 0x400
    /* 2DA24 8003D224 AEF3000C */  jal        func_8003CEB8
    /* 2DA28 8003D228 04020524 */   addiu     $a1, $zero, 0x204
    /* 2DA2C 8003D22C FFFF4330 */  andi       $v1, $v0, 0xFFFF
    /* 2DA30 8003D230 24065126 */  addiu      $s1, $s2, 0x624
    /* 2DA34 8003D234 08001024 */  addiu      $s0, $zero, 0x8
    /* 2DA38 8003D238 00140300 */  sll        $v0, $v1, 16
    /* 2DA3C 8003D23C 25106200 */  or         $v0, $v1, $v0
    /* 2DA40 8003D240 600082AF */  sw         $v0, %gp_rel(D_8009AF68)($gp)
    /* 2DA44 8003D244 5C0082AF */  sw         $v0, %gp_rel(D_8009AF64)($gp)
  .L8003D248:
    /* 2DA48 8003D248 9DF3000C */  jal        func_8003CE74
    /* 2DA4C 8003D24C 00000000 */   nop
    /* 2DA50 8003D250 0000238E */  lw         $v1, 0x0($s1)
    /* 2DA54 8003D254 00000000 */  nop
    /* 2DA58 8003D258 05006214 */  bne        $v1, $v0, .L8003D270
    /* 2DA5C 8003D25C 21100000 */   addu      $v0, $zero, $zero
    /* 2DA60 8003D260 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 2DA64 8003D264 F8FF0016 */  bnez       $s0, .L8003D248
    /* 2DA68 8003D268 FCFF3126 */   addiu     $s1, $s1, -0x4
    /* 2DA6C 8003D26C 01000224 */  addiu      $v0, $zero, 0x1
  .L8003D270:
    /* 2DA70 8003D270 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2DA74 8003D274 1800B28F */  lw         $s2, 0x18($sp)
    /* 2DA78 8003D278 1400B18F */  lw         $s1, 0x14($sp)
    /* 2DA7C 8003D27C 1000B08F */  lw         $s0, 0x10($sp)
    /* 2DA80 8003D280 0800E003 */  jr         $ra
    /* 2DA84 8003D284 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003D174
