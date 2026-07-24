nonmatching func_8007B1F4, 0x274

glabel func_8007B1F4
    /* 6B9F4 8007B1F4 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 6B9F8 8007B1F8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6B9FC 8007B1FC 2198A000 */  addu       $s3, $a1, $zero
    /* 6BA00 8007B200 2400B5AF */  sw         $s5, 0x24($sp)
    /* 6BA04 8007B204 21A8C000 */  addu       $s5, $a2, $zero
    /* 6BA08 8007B208 2000B4AF */  sw         $s4, 0x20($sp)
    /* 6BA0C 8007B20C 21A08000 */  addu       $s4, $a0, $zero
    /* 6BA10 8007B210 FF008232 */  andi       $v0, $s4, 0xFF
    /* 6BA14 8007B214 80100200 */  sll        $v0, $v0, 2
    /* 6BA18 8007B218 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 6BA1C 8007B21C 2800B6AF */  sw         $s6, 0x28($sp)
    /* 6BA20 8007B220 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6BA24 8007B224 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6BA28 8007B228 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6BA2C 8007B22C 0980013C */  lui        $at, %hi(D_800937E8)
    /* 6BA30 8007B230 21082200 */  addu       $at, $at, $v0
    /* 6BA34 8007B234 E837228C */  lw         $v0, %lo(D_800937E8)($at)
    /* 6BA38 8007B238 00000000 */  nop
    /* 6BA3C 8007B23C 43004010 */  beqz       $v0, .L8007B34C
    /* 6BA40 8007B240 21B0E000 */   addu      $s6, $a3, $zero
    /* 6BA44 8007B244 41006012 */  beqz       $s3, .L8007B34C
    /* 6BA48 8007B248 00000000 */   nop
    /* 6BA4C 8007B24C 0F80023C */  lui        $v0, %hi(D_800F5EE8)
    /* 6BA50 8007B250 E85E428C */  lw         $v0, %lo(D_800F5EE8)($v0)
    /* 6BA54 8007B254 00000000 */  nop
    /* 6BA58 8007B258 08004228 */  slti       $v0, $v0, 0x8
    /* 6BA5C 8007B25C 39004010 */  beqz       $v0, .L8007B344
    /* 6BA60 8007B260 21100000 */   addu      $v0, $zero, $zero
    /* 6BA64 8007B264 0980033C */  lui        $v1, %hi(D_80093868)
    /* 6BA68 8007B268 6838638C */  lw         $v1, %lo(D_80093868)($v1)
    /* 6BA6C 8007B26C 00000000 */  nop
    /* 6BA70 8007B270 01006224 */  addiu      $v0, $v1, 0x1
    /* 6BA74 8007B274 0980013C */  lui        $at, %hi(D_80093868)
    /* 6BA78 8007B278 04004014 */  bnez       $v0, .L8007B28C
    /* 6BA7C 8007B27C 683822AC */   sw        $v0, %lo(D_80093868)($at)
    /* 6BA80 8007B280 02006224 */  addiu      $v0, $v1, 0x2
    /* 6BA84 8007B284 0980013C */  lui        $at, %hi(D_80093868)
    /* 6BA88 8007B288 683822AC */  sw         $v0, %lo(D_80093868)($at)
  .L8007B28C:
    /* 6BA8C 8007B28C 83EA010C */  jal        func_8007AA0C
    /* 6BA90 8007B290 21904000 */   addu      $s2, $v0, $zero
    /* 6BA94 8007B294 21884000 */  addu       $s1, $v0, $zero
    /* 6BA98 8007B298 02000224 */  addiu      $v0, $zero, 0x2
    /* 6BA9C 8007B29C 000032AE */  sw         $s2, 0x0($s1)
    /* 6BAA0 8007B2A0 07006012 */  beqz       $s3, .L8007B2C0
    /* 6BAA4 8007B2A4 040022A2 */   sb        $v0, 0x4($s1)
    /* 6BAA8 8007B2A8 05003026 */  addiu      $s0, $s1, 0x5
    /* 6BAAC 8007B2AC 21200002 */  addu       $a0, $s0, $zero
    /* 6BAB0 8007B2B0 49F3010C */  jal        func_8007CD24
    /* 6BAB4 8007B2B4 21286002 */   addu      $a1, $s3, $zero
    /* 6BAB8 8007B2B8 B1EC0108 */  j          .L8007B2C4
    /* 6BABC 8007B2BC 0C0030AE */   sw        $s0, 0xC($s1)
  .L8007B2C0:
    /* 6BAC0 8007B2C0 0C0020AE */  sw         $zero, 0xC($s1)
  .L8007B2C4:
    /* 6BAC4 8007B2C4 21200000 */  addu       $a0, $zero, $zero
    /* 6BAC8 8007B2C8 100020AE */  sw         $zero, 0x10($s1)
    /* 6BACC 8007B2CC 43D1010C */  jal        func_8007450C
    /* 6BAD0 8007B2D0 140020AE */   sw        $zero, 0x14($s1)
    /* 6BAD4 8007B2D4 0F80033C */  lui        $v1, %hi(D_800F5EE8)
    /* 6BAD8 8007B2D8 E85E638C */  lw         $v1, %lo(D_800F5EE8)($v1)
    /* 6BADC 8007B2DC 00000000 */  nop
    /* 6BAE0 8007B2E0 01006324 */  addiu      $v1, $v1, 0x1
    /* 6BAE4 8007B2E4 0F80013C */  lui        $at, %hi(D_800F5EE8)
    /* 6BAE8 8007B2E8 E85E23AC */  sw         $v1, %lo(D_800F5EE8)($at)
    /* 6BAEC 8007B2EC 43D1010C */  jal        func_8007450C
    /* 6BAF0 8007B2F0 21204000 */   addu      $a0, $v0, $zero
    /* 6BAF4 8007B2F4 BBEF010C */  jal        func_8007BEEC
    /* 6BAF8 8007B2F8 21200000 */   addu      $a0, $zero, $zero
    /* 6BAFC 8007B2FC 01000324 */  addiu      $v1, $zero, 0x1
    /* 6BB00 8007B300 10004314 */  bne        $v0, $v1, .L8007B344
    /* 6BB04 8007B304 21104002 */   addu      $v0, $s2, $zero
    /* 6BB08 8007B308 0F80023C */  lui        $v0, %hi(D_800F5EE4)
    /* 6BB0C 8007B30C E45E428C */  lw         $v0, %lo(D_800F5EE4)($v0)
    /* 6BB10 8007B310 00000000 */  nop
    /* 6BB14 8007B314 40180200 */  sll        $v1, $v0, 1
    /* 6BB18 8007B318 21186200 */  addu       $v1, $v1, $v0
    /* 6BB1C 8007B31C C0180300 */  sll        $v1, $v1, 3
    /* 6BB20 8007B320 0F80023C */  lui        $v0, %hi(D_800F5E20)
    /* 6BB24 8007B324 21104300 */  addu       $v0, $v0, $v1
    /* 6BB28 8007B328 205E428C */  lw         $v0, %lo(D_800F5E20)($v0)
    /* 6BB2C 8007B32C 00000000 */  nop
    /* 6BB30 8007B330 04005214 */  bne        $v0, $s2, .L8007B344
    /* 6BB34 8007B334 21104002 */   addu      $v0, $s2, $zero
    /* 6BB38 8007B338 21EB010C */  jal        func_8007AC84
    /* 6BB3C 8007B33C 00000000 */   nop
    /* 6BB40 8007B340 21104002 */  addu       $v0, $s2, $zero
  .L8007B344:
    /* 6BB44 8007B344 3E004010 */  beqz       $v0, .L8007B440
    /* 6BB48 8007B348 21100000 */   addu      $v0, $zero, $zero
  .L8007B34C:
    /* 6BB4C 8007B34C 0F80023C */  lui        $v0, %hi(D_800F5EE8)
    /* 6BB50 8007B350 E85E428C */  lw         $v0, %lo(D_800F5EE8)($v0)
    /* 6BB54 8007B354 00000000 */  nop
    /* 6BB58 8007B358 08004228 */  slti       $v0, $v0, 0x8
    /* 6BB5C 8007B35C 38004010 */  beqz       $v0, .L8007B440
    /* 6BB60 8007B360 21100000 */   addu      $v0, $zero, $zero
    /* 6BB64 8007B364 0980033C */  lui        $v1, %hi(D_80093868)
    /* 6BB68 8007B368 6838638C */  lw         $v1, %lo(D_80093868)($v1)
    /* 6BB6C 8007B36C 00000000 */  nop
    /* 6BB70 8007B370 01006224 */  addiu      $v0, $v1, 0x1
    /* 6BB74 8007B374 0980013C */  lui        $at, %hi(D_80093868)
    /* 6BB78 8007B378 04004014 */  bnez       $v0, .L8007B38C
    /* 6BB7C 8007B37C 683822AC */   sw        $v0, %lo(D_80093868)($at)
    /* 6BB80 8007B380 02006224 */  addiu      $v0, $v1, 0x2
    /* 6BB84 8007B384 0980013C */  lui        $at, %hi(D_80093868)
    /* 6BB88 8007B388 683822AC */  sw         $v0, %lo(D_80093868)($at)
  .L8007B38C:
    /* 6BB8C 8007B38C 83EA010C */  jal        func_8007AA0C
    /* 6BB90 8007B390 21904000 */   addu      $s2, $v0, $zero
    /* 6BB94 8007B394 21884000 */  addu       $s1, $v0, $zero
    /* 6BB98 8007B398 000032AE */  sw         $s2, 0x0($s1)
    /* 6BB9C 8007B39C 07006012 */  beqz       $s3, .L8007B3BC
    /* 6BBA0 8007B3A0 040034A2 */   sb        $s4, 0x4($s1)
    /* 6BBA4 8007B3A4 05003026 */  addiu      $s0, $s1, 0x5
    /* 6BBA8 8007B3A8 21200002 */  addu       $a0, $s0, $zero
    /* 6BBAC 8007B3AC 49F3010C */  jal        func_8007CD24
    /* 6BBB0 8007B3B0 21286002 */   addu      $a1, $s3, $zero
    /* 6BBB4 8007B3B4 F0EC0108 */  j          .L8007B3C0
    /* 6BBB8 8007B3B8 0C0030AE */   sw        $s0, 0xC($s1)
  .L8007B3BC:
    /* 6BBBC 8007B3BC 0C0020AE */  sw         $zero, 0xC($s1)
  .L8007B3C0:
    /* 6BBC0 8007B3C0 21200000 */  addu       $a0, $zero, $zero
    /* 6BBC4 8007B3C4 100035AE */  sw         $s5, 0x10($s1)
    /* 6BBC8 8007B3C8 43D1010C */  jal        func_8007450C
    /* 6BBCC 8007B3CC 140036AE */   sw        $s6, 0x14($s1)
    /* 6BBD0 8007B3D0 0F80033C */  lui        $v1, %hi(D_800F5EE8)
    /* 6BBD4 8007B3D4 E85E638C */  lw         $v1, %lo(D_800F5EE8)($v1)
    /* 6BBD8 8007B3D8 00000000 */  nop
    /* 6BBDC 8007B3DC 01006324 */  addiu      $v1, $v1, 0x1
    /* 6BBE0 8007B3E0 0F80013C */  lui        $at, %hi(D_800F5EE8)
    /* 6BBE4 8007B3E4 E85E23AC */  sw         $v1, %lo(D_800F5EE8)($at)
    /* 6BBE8 8007B3E8 43D1010C */  jal        func_8007450C
    /* 6BBEC 8007B3EC 21204000 */   addu      $a0, $v0, $zero
    /* 6BBF0 8007B3F0 BBEF010C */  jal        func_8007BEEC
    /* 6BBF4 8007B3F4 21200000 */   addu      $a0, $zero, $zero
    /* 6BBF8 8007B3F8 01000324 */  addiu      $v1, $zero, 0x1
    /* 6BBFC 8007B3FC 10004314 */  bne        $v0, $v1, .L8007B440
    /* 6BC00 8007B400 21104002 */   addu      $v0, $s2, $zero
    /* 6BC04 8007B404 0F80023C */  lui        $v0, %hi(D_800F5EE4)
    /* 6BC08 8007B408 E45E428C */  lw         $v0, %lo(D_800F5EE4)($v0)
    /* 6BC0C 8007B40C 00000000 */  nop
    /* 6BC10 8007B410 40180200 */  sll        $v1, $v0, 1
    /* 6BC14 8007B414 21186200 */  addu       $v1, $v1, $v0
    /* 6BC18 8007B418 C0180300 */  sll        $v1, $v1, 3
    /* 6BC1C 8007B41C 0F80023C */  lui        $v0, %hi(D_800F5E20)
    /* 6BC20 8007B420 21104300 */  addu       $v0, $v0, $v1
    /* 6BC24 8007B424 205E428C */  lw         $v0, %lo(D_800F5E20)($v0)
    /* 6BC28 8007B428 00000000 */  nop
    /* 6BC2C 8007B42C 04005214 */  bne        $v0, $s2, .L8007B440
    /* 6BC30 8007B430 21104002 */   addu      $v0, $s2, $zero
    /* 6BC34 8007B434 21EB010C */  jal        func_8007AC84
    /* 6BC38 8007B438 00000000 */   nop
    /* 6BC3C 8007B43C 21104002 */  addu       $v0, $s2, $zero
  .L8007B440:
    /* 6BC40 8007B440 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 6BC44 8007B444 2800B68F */  lw         $s6, 0x28($sp)
    /* 6BC48 8007B448 2400B58F */  lw         $s5, 0x24($sp)
    /* 6BC4C 8007B44C 2000B48F */  lw         $s4, 0x20($sp)
    /* 6BC50 8007B450 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 6BC54 8007B454 1800B28F */  lw         $s2, 0x18($sp)
    /* 6BC58 8007B458 1400B18F */  lw         $s1, 0x14($sp)
    /* 6BC5C 8007B45C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6BC60 8007B460 0800E003 */  jr         $ra
    /* 6BC64 8007B464 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8007B1F4
