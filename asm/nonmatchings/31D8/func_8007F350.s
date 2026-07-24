nonmatching func_8007F350, 0x174

glabel func_8007F350
    /* 6FB50 8007F350 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6FB54 8007F354 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6FB58 8007F358 21888000 */  addu       $s1, $a0, $zero
    /* 6FB5C 8007F35C 07002332 */  andi       $v1, $s1, 0x7
    /* 6FB60 8007F360 03000224 */  addiu      $v0, $zero, 0x3
    /* 6FB64 8007F364 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6FB68 8007F368 0C006210 */  beq        $v1, $v0, .L8007F39C
    /* 6FB6C 8007F36C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6FB70 8007F370 04006228 */  slti       $v0, $v1, 0x4
    /* 6FB74 8007F374 05004010 */  beqz       $v0, .L8007F38C
    /* 6FB78 8007F378 05000224 */   addiu     $v0, $zero, 0x5
    /* 6FB7C 8007F37C 07006010 */  beqz       $v1, .L8007F39C
    /* 6FB80 8007F380 00000000 */   nop
    /* 6FB84 8007F384 18FD0108 */  j          .L8007F460
    /* 6FB88 8007F388 00000000 */   nop
  .L8007F38C:
    /* 6FB8C 8007F38C 0A006210 */  beq        $v1, $v0, .L8007F3B8
    /* 6FB90 8007F390 00000000 */   nop
    /* 6FB94 8007F394 18FD0108 */  j          .L8007F460
    /* 6FB98 8007F398 00000000 */   nop
  .L8007F39C:
    /* 6FB9C 8007F39C 0180043C */  lui        $a0, %hi(D_80012180)
    /* 6FBA0 8007F3A0 80218424 */  addiu      $a0, $a0, %lo(D_80012180)
    /* 6FBA4 8007F3A4 0980053C */  lui        $a1, %hi(D_80094620)
    /* 6FBA8 8007F3A8 2046A524 */  addiu      $a1, $a1, %lo(D_80094620)
    /* 6FBAC 8007F3AC 0980063C */  lui        $a2, %hi(D_80094668)
    /* 6FBB0 8007F3B0 1C3A020C */  jal        func_8008E870
    /* 6FBB4 8007F3B4 6846C624 */   addiu     $a2, $a2, %lo(D_80094668)
  .L8007F3B8:
    /* 6FBB8 8007F3B8 0980103C */  lui        $s0, %hi(D_80094668)
    /* 6FBBC 8007F3BC 68461026 */  addiu      $s0, $s0, %lo(D_80094668)
    /* 6FBC0 8007F3C0 21200002 */  addu       $a0, $s0, $zero
    /* 6FBC4 8007F3C4 21280000 */  addu       $a1, $zero, $zero
    /* 6FBC8 8007F3C8 8A08020C */  jal        func_80082228
    /* 6FBCC 8007F3CC 80000624 */   addiu     $a2, $zero, 0x80
    /* 6FBD0 8007F3D0 E4D0010C */  jal        func_80074390
    /* 6FBD4 8007F3D4 00000000 */   nop
    /* 6FBD8 8007F3D8 FF00023C */  lui        $v0, (0xFFFFFF >> 16)
    /* 6FBDC 8007F3DC 0980043C */  lui        $a0, %hi(D_80094660)
    /* 6FBE0 8007F3E0 6046848C */  lw         $a0, %lo(D_80094660)($a0)
    /* 6FBE4 8007F3E4 FFFF4234 */  ori        $v0, $v0, (0xFFFFFF & 0xFFFF)
    /* 6FBE8 8007F3E8 9408020C */  jal        func_80082250
    /* 6FBEC 8007F3EC 24208200 */   and       $a0, $a0, $v0
    /* 6FBF0 8007F3F0 5606020C */  jal        func_80081958
    /* 6FBF4 8007F3F4 21202002 */   addu      $a0, $s1, $zero
    /* 6FBF8 8007F3F8 10000426 */  addiu      $a0, $s0, 0x10
    /* 6FBFC 8007F3FC 000002A2 */  sb         $v0, 0x0($s0)
    /* 6FC00 8007F400 00000292 */  lbu        $v0, 0x0($s0)
    /* 6FC04 8007F404 01000324 */  addiu      $v1, $zero, 0x1
    /* 6FC08 8007F408 010003A2 */  sb         $v1, 0x1($s0)
    /* 6FC0C 8007F40C 80100200 */  sll        $v0, $v0, 2
    /* 6FC10 8007F410 0980033C */  lui        $v1, %hi(D_800946E8)
    /* 6FC14 8007F414 21186200 */  addu       $v1, $v1, $v0
    /* 6FC18 8007F418 E8466394 */  lhu        $v1, %lo(D_800946E8)($v1)
    /* 6FC1C 8007F41C 00000292 */  lbu        $v0, 0x0($s0)
    /* 6FC20 8007F420 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 6FC24 8007F424 80100200 */  sll        $v0, $v0, 2
    /* 6FC28 8007F428 040003A6 */  sh         $v1, 0x4($s0)
    /* 6FC2C 8007F42C 0980013C */  lui        $at, %hi(D_800946F4)
    /* 6FC30 8007F430 21082200 */  addu       $at, $at, $v0
    /* 6FC34 8007F434 F4462294 */  lhu        $v0, %lo(D_800946F4)($at)
    /* 6FC38 8007F438 5C000624 */  addiu      $a2, $zero, 0x5C
    /* 6FC3C 8007F43C 8A08020C */  jal        func_80082228
    /* 6FC40 8007F440 060002A6 */   sh        $v0, 0x6($s0)
    /* 6FC44 8007F444 6C000426 */  addiu      $a0, $s0, 0x6C
    /* 6FC48 8007F448 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 6FC4C 8007F44C 8A08020C */  jal        func_80082228
    /* 6FC50 8007F450 14000624 */   addiu     $a2, $zero, 0x14
    /* 6FC54 8007F454 00000292 */  lbu        $v0, 0x0($s0)
    /* 6FC58 8007F458 2CFD0108 */  j          .L8007F4B0
    /* 6FC5C 8007F45C 00000000 */   nop
  .L8007F460:
    /* 6FC60 8007F460 0980023C */  lui        $v0, %hi(D_8009466A)
    /* 6FC64 8007F464 6A464290 */  lbu        $v0, %lo(D_8009466A)($v0)
    /* 6FC68 8007F468 00000000 */  nop
    /* 6FC6C 8007F46C 0200422C */  sltiu      $v0, $v0, 0x2
    /* 6FC70 8007F470 08004014 */  bnez       $v0, .L8007F494
    /* 6FC74 8007F474 00000000 */   nop
    /* 6FC78 8007F478 0180043C */  lui        $a0, %hi(D_800121A0)
    /* 6FC7C 8007F47C A0218424 */  addiu      $a0, $a0, %lo(D_800121A0)
    /* 6FC80 8007F480 0980023C */  lui        $v0, %hi(D_80094664)
    /* 6FC84 8007F484 6446428C */  lw         $v0, %lo(D_80094664)($v0)
    /* 6FC88 8007F488 00000000 */  nop
    /* 6FC8C 8007F48C 09F84000 */  jalr       $v0
    /* 6FC90 8007F490 21282002 */   addu      $a1, $s1, $zero
  .L8007F494:
    /* 6FC94 8007F494 0980023C */  lui        $v0, %hi(D_80094660)
    /* 6FC98 8007F498 6046428C */  lw         $v0, %lo(D_80094660)($v0)
    /* 6FC9C 8007F49C 00000000 */  nop
    /* 6FCA0 8007F4A0 3400428C */  lw         $v0, 0x34($v0)
    /* 6FCA4 8007F4A4 00000000 */  nop
    /* 6FCA8 8007F4A8 09F84000 */  jalr       $v0
    /* 6FCAC 8007F4AC 01000424 */   addiu     $a0, $zero, 0x1
  .L8007F4B0:
    /* 6FCB0 8007F4B0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6FCB4 8007F4B4 1400B18F */  lw         $s1, 0x14($sp)
    /* 6FCB8 8007F4B8 1000B08F */  lw         $s0, 0x10($sp)
    /* 6FCBC 8007F4BC 0800E003 */  jr         $ra
    /* 6FCC0 8007F4C0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007F350
