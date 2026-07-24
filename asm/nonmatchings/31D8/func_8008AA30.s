nonmatching func_8008AA30, 0x314

glabel func_8008AA30
    /* 7B230 8008AA30 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 7B234 8008AA34 1800B2AF */  sw         $s2, 0x18($sp)
    /* 7B238 8008AA38 2190A000 */  addu       $s2, $a1, $zero
    /* 7B23C 8008AA3C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 7B240 8008AA40 2198C000 */  addu       $s3, $a2, $zero
    /* 7B244 8008AA44 21388000 */  addu       $a3, $a0, $zero
    /* 7B248 8008AA48 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7B24C 8008AA4C 21880000 */  addu       $s1, $zero, $zero
    /* 7B250 8008AA50 64000524 */  addiu      $a1, $zero, 0x64
    /* 7B254 8008AA54 1080063C */  lui        $a2, %hi(D_800FE278)
    /* 7B258 8008AA58 78E2C624 */  addiu      $a2, $a2, %lo(D_800FE278)
    /* 7B25C 8008AA5C 64000824 */  addiu      $t0, $zero, 0x64
    /* 7B260 8008AA60 2000BFAF */  sw         $ra, 0x20($sp)
    /* 7B264 8008AA64 1000B0AF */  sw         $s0, 0x10($sp)
  .L8008AA68:
    /* 7B268 8008AA68 80101100 */  sll        $v0, $s1, 2
    /* 7B26C 8008AA6C 21104600 */  addu       $v0, $v0, $a2
    /* 7B270 8008AA70 000047AC */  sw         $a3, 0x0($v0)
    /* 7B274 8008AA74 4C00E48C */  lw         $a0, 0x4C($a3)
    /* 7B278 8008AA78 00000000 */  nop
    /* 7B27C 8008AA7C 59008014 */  bnez       $a0, .L8008ABE4
    /* 7B280 8008AA80 00000000 */   nop
    /* 7B284 8008AA84 0000E38C */  lw         $v1, 0x0($a3)
    /* 7B288 8008AA88 1080023C */  lui        $v0, %hi(D_800FE0C8)
    /* 7B28C 8008AA8C C8E0428C */  lw         $v0, %lo(D_800FE0C8)($v0)
    /* 7B290 8008AA90 00000000 */  nop
    /* 7B294 8008AA94 03006210 */  beq        $v1, $v0, .L8008AAA4
    /* 7B298 8008AA98 00000000 */   nop
    /* 7B29C 8008AA9C 25006014 */  bnez       $v1, .L8008AB34
    /* 7B2A0 8008AAA0 00000000 */   nop
  .L8008AAA4:
    /* 7B2A4 8008AAA4 0400E28C */  lw         $v0, 0x4($a3)
    /* 7B2A8 8008AAA8 0800E38C */  lw         $v1, 0x8($a3)
    /* 7B2AC 8008AAAC 0C00E48C */  lw         $a0, 0xC($a3)
    /* 7B2B0 8008AAB0 1000E58C */  lw         $a1, 0x10($a3)
    /* 7B2B4 8008AAB4 2400E2AC */  sw         $v0, 0x24($a3)
    /* 7B2B8 8008AAB8 2800E3AC */  sw         $v1, 0x28($a3)
    /* 7B2BC 8008AABC 2C00E4AC */  sw         $a0, 0x2C($a3)
    /* 7B2C0 8008AAC0 3000E5AC */  sw         $a1, 0x30($a3)
    /* 7B2C4 8008AAC4 1400E28C */  lw         $v0, 0x14($a3)
    /* 7B2C8 8008AAC8 1800E38C */  lw         $v1, 0x18($a3)
    /* 7B2CC 8008AACC 1C00E48C */  lw         $a0, 0x1C($a3)
    /* 7B2D0 8008AAD0 2000E58C */  lw         $a1, 0x20($a3)
    /* 7B2D4 8008AAD4 3400E2AC */  sw         $v0, 0x34($a3)
    /* 7B2D8 8008AAD8 3800E3AC */  sw         $v1, 0x38($a3)
    /* 7B2DC 8008AADC 3C00E4AC */  sw         $a0, 0x3C($a3)
    /* 7B2E0 8008AAE0 4000E5AC */  sw         $a1, 0x40($a3)
    /* 7B2E4 8008AAE4 1080023C */  lui        $v0, %hi(D_800FE0C8)
    /* 7B2E8 8008AAE8 C8E0428C */  lw         $v0, %lo(D_800FE0C8)($v0)
    /* 7B2EC 8008AAEC 2400E38C */  lw         $v1, 0x24($a3)
    /* 7B2F0 8008AAF0 2800E48C */  lw         $a0, 0x28($a3)
    /* 7B2F4 8008AAF4 2C00E58C */  lw         $a1, 0x2C($a3)
    /* 7B2F8 8008AAF8 3000E68C */  lw         $a2, 0x30($a3)
    /* 7B2FC 8008AAFC 000043AE */  sw         $v1, 0x0($s2)
    /* 7B300 8008AB00 040044AE */  sw         $a0, 0x4($s2)
    /* 7B304 8008AB04 080045AE */  sw         $a1, 0x8($s2)
    /* 7B308 8008AB08 0C0046AE */  sw         $a2, 0xC($s2)
    /* 7B30C 8008AB0C 3400E38C */  lw         $v1, 0x34($a3)
    /* 7B310 8008AB10 3800E48C */  lw         $a0, 0x38($a3)
    /* 7B314 8008AB14 3C00E58C */  lw         $a1, 0x3C($a3)
    /* 7B318 8008AB18 4000E68C */  lw         $a2, 0x40($a3)
    /* 7B31C 8008AB1C 100043AE */  sw         $v1, 0x10($s2)
    /* 7B320 8008AB20 140044AE */  sw         $a0, 0x14($s2)
    /* 7B324 8008AB24 180045AE */  sw         $a1, 0x18($s2)
    /* 7B328 8008AB28 1C0046AE */  sw         $a2, 0x1C($s2)
    /* 7B32C 8008AB2C 152B0208 */  j          .L8008AC54
    /* 7B330 8008AB30 0000E2AC */   sw        $v0, 0x0($a3)
  .L8008AB34:
    /* 7B334 8008AB34 1600A814 */  bne        $a1, $t0, .L8008AB90
    /* 7B338 8008AB38 0100B124 */   addiu     $s1, $a1, 0x1
    /* 7B33C 8008AB3C 1080023C */  lui        $v0, %hi(D_800FE278)
    /* 7B340 8008AB40 78E2428C */  lw         $v0, %lo(D_800FE278)($v0)
    /* 7B344 8008AB44 00000000 */  nop
    /* 7B348 8008AB48 2400438C */  lw         $v1, 0x24($v0)
    /* 7B34C 8008AB4C 2800448C */  lw         $a0, 0x28($v0)
    /* 7B350 8008AB50 2C00458C */  lw         $a1, 0x2C($v0)
    /* 7B354 8008AB54 3000468C */  lw         $a2, 0x30($v0)
    /* 7B358 8008AB58 000043AE */  sw         $v1, 0x0($s2)
    /* 7B35C 8008AB5C 040044AE */  sw         $a0, 0x4($s2)
    /* 7B360 8008AB60 080045AE */  sw         $a1, 0x8($s2)
    /* 7B364 8008AB64 0C0046AE */  sw         $a2, 0xC($s2)
    /* 7B368 8008AB68 3400438C */  lw         $v1, 0x34($v0)
    /* 7B36C 8008AB6C 3800448C */  lw         $a0, 0x38($v0)
    /* 7B370 8008AB70 3C00458C */  lw         $a1, 0x3C($v0)
    /* 7B374 8008AB74 4000468C */  lw         $a2, 0x40($v0)
    /* 7B378 8008AB78 100043AE */  sw         $v1, 0x10($s2)
    /* 7B37C 8008AB7C 140044AE */  sw         $a0, 0x14($s2)
    /* 7B380 8008AB80 180045AE */  sw         $a1, 0x18($s2)
    /* 7B384 8008AB84 1C0046AE */  sw         $a2, 0x1C($s2)
    /* 7B388 8008AB88 152B0208 */  j          .L8008AC54
    /* 7B38C 8008AB8C 21880000 */   addu      $s1, $zero, $zero
  .L8008AB90:
    /* 7B390 8008AB90 80101100 */  sll        $v0, $s1, 2
    /* 7B394 8008AB94 21104600 */  addu       $v0, $v0, $a2
    /* 7B398 8008AB98 0000428C */  lw         $v0, 0x0($v0)
    /* 7B39C 8008AB9C 00000000 */  nop
    /* 7B3A0 8008ABA0 2400438C */  lw         $v1, 0x24($v0)
    /* 7B3A4 8008ABA4 2800448C */  lw         $a0, 0x28($v0)
    /* 7B3A8 8008ABA8 2C00458C */  lw         $a1, 0x2C($v0)
    /* 7B3AC 8008ABAC 3000468C */  lw         $a2, 0x30($v0)
    /* 7B3B0 8008ABB0 000043AE */  sw         $v1, 0x0($s2)
    /* 7B3B4 8008ABB4 040044AE */  sw         $a0, 0x4($s2)
    /* 7B3B8 8008ABB8 080045AE */  sw         $a1, 0x8($s2)
    /* 7B3BC 8008ABBC 0C0046AE */  sw         $a2, 0xC($s2)
    /* 7B3C0 8008ABC0 3400438C */  lw         $v1, 0x34($v0)
    /* 7B3C4 8008ABC4 3800448C */  lw         $a0, 0x38($v0)
    /* 7B3C8 8008ABC8 3C00458C */  lw         $a1, 0x3C($v0)
    /* 7B3CC 8008ABCC 4000468C */  lw         $a2, 0x40($v0)
    /* 7B3D0 8008ABD0 100043AE */  sw         $v1, 0x10($s2)
    /* 7B3D4 8008ABD4 140044AE */  sw         $a0, 0x14($s2)
    /* 7B3D8 8008ABD8 180045AE */  sw         $a1, 0x18($s2)
    /* 7B3DC 8008ABDC 152B0208 */  j          .L8008AC54
    /* 7B3E0 8008ABE0 1C0046AE */   sw        $a2, 0x1C($s2)
  .L8008ABE4:
    /* 7B3E4 8008ABE4 0000E38C */  lw         $v1, 0x0($a3)
    /* 7B3E8 8008ABE8 1080023C */  lui        $v0, %hi(D_800FE0C8)
    /* 7B3EC 8008ABEC C8E0428C */  lw         $v0, %lo(D_800FE0C8)($v0)
    /* 7B3F0 8008ABF0 00000000 */  nop
    /* 7B3F4 8008ABF4 12006214 */  bne        $v1, $v0, .L8008AC40
    /* 7B3F8 8008ABF8 00000000 */   nop
    /* 7B3FC 8008ABFC 2400E28C */  lw         $v0, 0x24($a3)
    /* 7B400 8008AC00 2800E38C */  lw         $v1, 0x28($a3)
    /* 7B404 8008AC04 2C00E48C */  lw         $a0, 0x2C($a3)
    /* 7B408 8008AC08 3000E58C */  lw         $a1, 0x30($a3)
    /* 7B40C 8008AC0C 000042AE */  sw         $v0, 0x0($s2)
    /* 7B410 8008AC10 040043AE */  sw         $v1, 0x4($s2)
    /* 7B414 8008AC14 080044AE */  sw         $a0, 0x8($s2)
    /* 7B418 8008AC18 0C0045AE */  sw         $a1, 0xC($s2)
    /* 7B41C 8008AC1C 3400E28C */  lw         $v0, 0x34($a3)
    /* 7B420 8008AC20 3800E38C */  lw         $v1, 0x38($a3)
    /* 7B424 8008AC24 3C00E48C */  lw         $a0, 0x3C($a3)
    /* 7B428 8008AC28 4000E58C */  lw         $a1, 0x40($a3)
    /* 7B42C 8008AC2C 100042AE */  sw         $v0, 0x10($s2)
    /* 7B430 8008AC30 140043AE */  sw         $v1, 0x14($s2)
    /* 7B434 8008AC34 180044AE */  sw         $a0, 0x18($s2)
    /* 7B438 8008AC38 152B0208 */  j          .L8008AC54
    /* 7B43C 8008AC3C 1C0045AE */   sw        $a1, 0x1C($s2)
  .L8008AC40:
    /* 7B440 8008AC40 02006014 */  bnez       $v1, .L8008AC4C
    /* 7B444 8008AC44 21388000 */   addu      $a3, $a0, $zero
    /* 7B448 8008AC48 21282002 */  addu       $a1, $s1, $zero
  .L8008AC4C:
    /* 7B44C 8008AC4C 9A2A0208 */  j          .L8008AA68
    /* 7B450 8008AC50 01003126 */   addiu     $s1, $s1, 0x1
  .L8008AC54:
    /* 7B454 8008AC54 2000201A */  blez       $s1, .L8008ACD8
    /* 7B458 8008AC58 80101100 */   sll       $v0, $s1, 2
    /* 7B45C 8008AC5C 1080033C */  lui        $v1, %hi(D_800FE274)
    /* 7B460 8008AC60 74E26324 */  addiu      $v1, $v1, %lo(D_800FE274)
    /* 7B464 8008AC64 21804300 */  addu       $s0, $v0, $v1
  .L8008AC68:
    /* 7B468 8008AC68 0000058E */  lw         $a1, 0x0($s0)
    /* 7B46C 8008AC6C 21204002 */  addu       $a0, $s2, $zero
    /* 7B470 8008AC70 8819020C */  jal        func_80086620
    /* 7B474 8008AC74 0400A524 */   addiu     $a1, $a1, 0x4
    /* 7B478 8008AC78 0000028E */  lw         $v0, 0x0($s0)
    /* 7B47C 8008AC7C FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 7B480 8008AC80 0000438E */  lw         $v1, 0x0($s2)
    /* 7B484 8008AC84 0400448E */  lw         $a0, 0x4($s2)
    /* 7B488 8008AC88 0800458E */  lw         $a1, 0x8($s2)
    /* 7B48C 8008AC8C 0C00468E */  lw         $a2, 0xC($s2)
    /* 7B490 8008AC90 240043AC */  sw         $v1, 0x24($v0)
    /* 7B494 8008AC94 280044AC */  sw         $a0, 0x28($v0)
    /* 7B498 8008AC98 2C0045AC */  sw         $a1, 0x2C($v0)
    /* 7B49C 8008AC9C 300046AC */  sw         $a2, 0x30($v0)
    /* 7B4A0 8008ACA0 1000438E */  lw         $v1, 0x10($s2)
    /* 7B4A4 8008ACA4 1400448E */  lw         $a0, 0x14($s2)
    /* 7B4A8 8008ACA8 1800458E */  lw         $a1, 0x18($s2)
    /* 7B4AC 8008ACAC 1C00468E */  lw         $a2, 0x1C($s2)
    /* 7B4B0 8008ACB0 340043AC */  sw         $v1, 0x34($v0)
    /* 7B4B4 8008ACB4 380044AC */  sw         $a0, 0x38($v0)
    /* 7B4B8 8008ACB8 3C0045AC */  sw         $a1, 0x3C($v0)
    /* 7B4BC 8008ACBC 400046AC */  sw         $a2, 0x40($v0)
    /* 7B4C0 8008ACC0 0000038E */  lw         $v1, 0x0($s0)
    /* 7B4C4 8008ACC4 1080023C */  lui        $v0, %hi(D_800FE0C8)
    /* 7B4C8 8008ACC8 C8E0428C */  lw         $v0, %lo(D_800FE0C8)($v0)
    /* 7B4CC 8008ACCC FCFF1026 */  addiu      $s0, $s0, -0x4
    /* 7B4D0 8008ACD0 E5FF201E */  bgtz       $s1, .L8008AC68
    /* 7B4D4 8008ACD4 000062AC */   sw        $v0, 0x0($v1)
  .L8008ACD8:
    /* 7B4D8 8008ACD8 0000428E */  lw         $v0, 0x0($s2)
    /* 7B4DC 8008ACDC 0400438E */  lw         $v1, 0x4($s2)
    /* 7B4E0 8008ACE0 0800448E */  lw         $a0, 0x8($s2)
    /* 7B4E4 8008ACE4 0C00458E */  lw         $a1, 0xC($s2)
    /* 7B4E8 8008ACE8 000062AE */  sw         $v0, 0x0($s3)
    /* 7B4EC 8008ACEC 040063AE */  sw         $v1, 0x4($s3)
    /* 7B4F0 8008ACF0 080064AE */  sw         $a0, 0x8($s3)
    /* 7B4F4 8008ACF4 0C0065AE */  sw         $a1, 0xC($s3)
    /* 7B4F8 8008ACF8 1000428E */  lw         $v0, 0x10($s2)
    /* 7B4FC 8008ACFC 1400438E */  lw         $v1, 0x14($s2)
    /* 7B500 8008AD00 1800448E */  lw         $a0, 0x18($s2)
    /* 7B504 8008AD04 1C00458E */  lw         $a1, 0x1C($s2)
    /* 7B508 8008AD08 100062AE */  sw         $v0, 0x10($s3)
    /* 7B50C 8008AD0C 140063AE */  sw         $v1, 0x14($s3)
    /* 7B510 8008AD10 180064AE */  sw         $a0, 0x18($s3)
    /* 7B514 8008AD14 1C0065AE */  sw         $a1, 0x1C($s3)
    /* 7B518 8008AD18 1080043C */  lui        $a0, %hi(D_800FE148)
    /* 7B51C 8008AD1C 48E18424 */  addiu      $a0, $a0, %lo(D_800FE148)
    /* 7B520 8008AD20 6819020C */  jal        func_800865A0
    /* 7B524 8008AD24 21286002 */   addu      $a1, $s3, $zero
    /* 7B528 8008AD28 2000BF8F */  lw         $ra, 0x20($sp)
    /* 7B52C 8008AD2C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 7B530 8008AD30 1800B28F */  lw         $s2, 0x18($sp)
    /* 7B534 8008AD34 1400B18F */  lw         $s1, 0x14($sp)
    /* 7B538 8008AD38 1000B08F */  lw         $s0, 0x10($sp)
    /* 7B53C 8008AD3C 0800E003 */  jr         $ra
    /* 7B540 8008AD40 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8008AA30
    /* 7B544 8008AD44 00000000 */  nop
    /* 7B548 8008AD48 00000000 */  nop
    /* 7B54C 8008AD4C 00000000 */  nop
