nonmatching func_8005F3B8, 0x1AC

glabel func_8005F3B8
    /* 4FBB8 8005F3B8 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 4FBBC 8005F3BC 2800B2AF */  sw         $s2, 0x28($sp)
    /* 4FBC0 8005F3C0 5000B28F */  lw         $s2, 0x50($sp)
    /* 4FBC4 8005F3C4 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 4FBC8 8005F3C8 21988000 */  addu       $s3, $a0, $zero
    /* 4FBCC 8005F3CC 3400B5AF */  sw         $s5, 0x34($sp)
    /* 4FBD0 8005F3D0 21A8A000 */  addu       $s5, $a1, $zero
    /* 4FBD4 8005F3D4 3000B4AF */  sw         $s4, 0x30($sp)
    /* 4FBD8 8005F3D8 21A0C000 */  addu       $s4, $a2, $zero
    /* 4FBDC 8005F3DC 3800B6AF */  sw         $s6, 0x38($sp)
    /* 4FBE0 8005F3E0 21B0E000 */  addu       $s6, $a3, $zero
    /* 4FBE4 8005F3E4 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 4FBE8 8005F3E8 2400B1AF */  sw         $s1, 0x24($sp)
    /* 4FBEC 8005F3EC 7F64010C */  jal        func_800591FC
    /* 4FBF0 8005F3F0 2000B0AF */   sw        $s0, 0x20($sp)
    /* 4FBF4 8005F3F4 8264010C */  jal        func_80059208
    /* 4FBF8 8005F3F8 21804000 */   addu      $s0, $v0, $zero
    /* 4FBFC 8005F3FC 21884000 */  addu       $s1, $v0, $zero
    /* 4FC00 8005F400 73018393 */  lbu        $v1, %gp_rel(D_8009B07B)($gp)
    /* 4FC04 8005F404 01000224 */  addiu      $v0, $zero, 0x1
    /* 4FC08 8005F408 05006214 */  bne        $v1, $v0, .L8005F420
    /* 4FC0C 8005F40C 00000000 */   nop
    /* 4FC10 8005F410 74018293 */  lbu        $v0, %gp_rel(D_8009B07C)($gp)
    /* 4FC14 8005F414 00000000 */  nop
    /* 4FC18 8005F418 48004310 */  beq        $v0, $v1, .L8005F53C
    /* 4FC1C 8005F41C 00000000 */   nop
  .L8005F420:
    /* 4FC20 8005F420 0C006006 */  bltz       $s3, .L8005F454
    /* 4FC24 8005F424 21206002 */   addu      $a0, $s3, $zero
    /* 4FC28 8005F428 EC63010C */  jal        func_80058FB0
    /* 4FC2C 8005F42C 1800A527 */   addiu     $a1, $sp, 0x18
    /* 4FC30 8005F430 1800A287 */  lh         $v0, 0x18($sp)
    /* 4FC34 8005F434 00000000 */  nop
    /* 4FC38 8005F438 0C0002AE */  sw         $v0, 0xC($s0)
    /* 4FC3C 8005F43C 1A00A287 */  lh         $v0, 0x1A($sp)
    /* 4FC40 8005F440 00000000 */  nop
    /* 4FC44 8005F444 100002AE */  sw         $v0, 0x10($s0)
    /* 4FC48 8005F448 1C00A287 */  lh         $v0, 0x1C($sp)
    /* 4FC4C 8005F44C 00000000 */  nop
    /* 4FC50 8005F450 140002AE */  sw         $v0, 0x14($s0)
  .L8005F454:
    /* 4FC54 8005F454 17004012 */  beqz       $s2, .L8005F4B4
    /* 4FC58 8005F458 00000000 */   nop
    /* 4FC5C 8005F45C 0200601E */  bgtz       $s3, .L8005F468
    /* 4FC60 8005F460 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 4FC64 8005F464 01000424 */  addiu      $a0, $zero, 0x1
  .L8005F468:
    /* 4FC68 8005F468 00004286 */  lh         $v0, 0x0($s2)
    /* 4FC6C 8005F46C 00000000 */  nop
    /* 4FC70 8005F470 18004400 */  mult       $v0, $a0
    /* 4FC74 8005F474 0C00028E */  lw         $v0, 0xC($s0)
    /* 4FC78 8005F478 12400000 */  mflo       $t0
    /* 4FC7C 8005F47C 21104800 */  addu       $v0, $v0, $t0
    /* 4FC80 8005F480 0C0002AE */  sw         $v0, 0xC($s0)
    /* 4FC84 8005F484 02004386 */  lh         $v1, 0x2($s2)
    /* 4FC88 8005F488 1000028E */  lw         $v0, 0x10($s0)
    /* 4FC8C 8005F48C 00000000 */  nop
    /* 4FC90 8005F490 21104300 */  addu       $v0, $v0, $v1
    /* 4FC94 8005F494 100002AE */  sw         $v0, 0x10($s0)
    /* 4FC98 8005F498 04004286 */  lh         $v0, 0x4($s2)
    /* 4FC9C 8005F49C 00000000 */  nop
    /* 4FCA0 8005F4A0 18004400 */  mult       $v0, $a0
    /* 4FCA4 8005F4A4 1400028E */  lw         $v0, 0x14($s0)
    /* 4FCA8 8005F4A8 12400000 */  mflo       $t0
    /* 4FCAC 8005F4AC 21104800 */  addu       $v0, $v0, $t0
    /* 4FCB0 8005F4B0 140002AE */  sw         $v0, 0x14($s0)
  .L8005F4B4:
    /* 4FCB4 8005F4B4 0600601E */  bgtz       $s3, .L8005F4D0
    /* 4FCB8 8005F4B8 000035A6 */   sh        $s5, 0x0($s1)
    /* 4FCBC 8005F4BC 001C8326 */  addiu      $v1, $s4, 0x1C00
    /* 4FCC0 8005F4C0 07006104 */  bgez       $v1, .L8005F4E0
    /* 4FCC4 8005F4C4 21106000 */   addu      $v0, $v1, $zero
    /* 4FCC8 8005F4C8 387D0108 */  j          .L8005F4E0
    /* 4FCCC 8005F4CC FF2B8226 */   addiu     $v0, $s4, 0x2BFF
  .L8005F4D0:
    /* 4FCD0 8005F4D0 00148326 */  addiu      $v1, $s4, 0x1400
    /* 4FCD4 8005F4D4 02006104 */  bgez       $v1, .L8005F4E0
    /* 4FCD8 8005F4D8 21106000 */   addu      $v0, $v1, $zero
    /* 4FCDC 8005F4DC FF238226 */  addiu      $v0, $s4, 0x23FF
  .L8005F4E0:
    /* 4FCE0 8005F4E0 03130200 */  sra        $v0, $v0, 12
    /* 4FCE4 8005F4E4 00130200 */  sll        $v0, $v0, 12
    /* 4FCE8 8005F4E8 23106200 */  subu       $v0, $v1, $v0
    /* 4FCEC 8005F4EC 020022A6 */  sh         $v0, 0x2($s1)
    /* 4FCF0 8005F4F0 0010C326 */  addiu      $v1, $s6, 0x1000
    /* 4FCF4 8005F4F4 02006104 */  bgez       $v1, .L8005F500
    /* 4FCF8 8005F4F8 21106000 */   addu      $v0, $v1, $zero
    /* 4FCFC 8005F4FC FF1FC226 */  addiu      $v0, $s6, 0x1FFF
  .L8005F500:
    /* 4FD00 8005F500 01000424 */  addiu      $a0, $zero, 0x1
    /* 4FD04 8005F504 00100524 */  addiu      $a1, $zero, 0x1000
    /* 4FD08 8005F508 03130200 */  sra        $v0, $v0, 12
    /* 4FD0C 8005F50C 00130200 */  sll        $v0, $v0, 12
    /* 4FD10 8005F510 23106200 */  subu       $v0, $v1, $v0
    /* 4FD14 8005F514 040022A6 */  sh         $v0, 0x4($s1)
    /* 4FD18 8005F518 21108000 */  addu       $v0, $a0, $zero
    /* 4FD1C 8005F51C 21300000 */  addu       $a2, $zero, $zero
    /* 4FD20 8005F520 2138C000 */  addu       $a3, $a2, $zero
    /* 4FD24 8005F524 0D61010C */  jal        func_80058434
    /* 4FD28 8005F528 1000A2AF */   sw        $v0, 0x10($sp)
    /* 4FD2C 8005F52C 1C7C010C */  jal        func_8005F070
    /* 4FD30 8005F530 01000424 */   addiu     $a0, $zero, 0x1
    /* 4FD34 8005F534 AF67010C */  jal        func_80059EBC
    /* 4FD38 8005F538 FFFF0424 */   addiu     $a0, $zero, -0x1
  .L8005F53C:
    /* 4FD3C 8005F53C 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 4FD40 8005F540 3800B68F */  lw         $s6, 0x38($sp)
    /* 4FD44 8005F544 3400B58F */  lw         $s5, 0x34($sp)
    /* 4FD48 8005F548 3000B48F */  lw         $s4, 0x30($sp)
    /* 4FD4C 8005F54C 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 4FD50 8005F550 2800B28F */  lw         $s2, 0x28($sp)
    /* 4FD54 8005F554 2400B18F */  lw         $s1, 0x24($sp)
    /* 4FD58 8005F558 2000B08F */  lw         $s0, 0x20($sp)
    /* 4FD5C 8005F55C 0800E003 */  jr         $ra
    /* 4FD60 8005F560 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8005F3B8
