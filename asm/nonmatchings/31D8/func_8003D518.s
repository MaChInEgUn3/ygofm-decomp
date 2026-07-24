nonmatching func_8003D518, 0xFC

glabel func_8003D518
    /* 2DD18 8003D518 B9048393 */  lbu        $v1, %gp_rel(D_8009B3C1)($gp)
    /* 2DD1C 8003D51C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2DD20 8003D520 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2DD24 8003D524 21888000 */  addu       $s1, $a0, $zero
    /* 2DD28 8003D528 1800BFAF */  sw         $ra, 0x18($sp)
    /* 2DD2C 8003D52C 80006230 */  andi       $v0, $v1, 0x80
    /* 2DD30 8003D530 1E004014 */  bnez       $v0, .L8003D5AC
    /* 2DD34 8003D534 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2DD38 8003D538 80006234 */  ori        $v0, $v1, 0x80
    /* 2DD3C 8003D53C B90482A3 */  sb         $v0, %gp_rel(D_8009B3C1)($gp)
    /* 2DD40 8003D540 0B00010C */  jal        func_8004002C
    /* 2DD44 8003D544 00000000 */   nop
    /* 2DD48 8003D548 21204000 */  addu       $a0, $v0, $zero
    /* 2DD4C 8003D54C 2B00010C */  jal        func_800400AC
    /* 2DD50 8003D550 06000524 */   addiu     $a1, $zero, 0x6
    /* 2DD54 8003D554 21804000 */  addu       $s0, $v0, $zero
    /* 2DD58 8003D558 21200002 */  addu       $a0, $s0, $zero
    /* 2DD5C 8003D55C A0000224 */  addiu      $v0, $zero, 0xA0
    /* 2DD60 8003D560 300002A6 */  sh         $v0, 0x30($s0)
    /* 2DD64 8003D564 78000224 */  addiu      $v0, $zero, 0x78
    /* 2DD68 8003D568 320002A6 */  sh         $v0, 0x32($s0)
    /* 2DD6C 8003D56C 80000224 */  addiu      $v0, $zero, 0x80
    /* 2DD70 8003D570 480002A6 */  sh         $v0, 0x48($s0)
    /* 2DD74 8003D574 E0000224 */  addiu      $v0, $zero, 0xE0
    /* 2DD78 8003D578 460A010C */  jal        func_80042918
    /* 2DD7C 8003D57C 4A0002A6 */   sh        $v0, 0x4A($s0)
    /* 2DD80 8003D580 0A80053C */  lui        $a1, %hi(D_8009AF76)
    /* 2DD84 8003D584 76AFA590 */  lbu        $a1, %lo(D_8009AF76)($a1)
    /* 2DD88 8003D588 21200002 */  addu       $a0, $s0, $zero
    /* 2DD8C 8003D58C FDFFA524 */  addiu      $a1, $a1, -0x3
    /* 2DD90 8003D590 002E0500 */  sll        $a1, $a1, 24
    /* 2DD94 8003D594 3B0A010C */  jal        func_800428EC
    /* 2DD98 8003D598 032E0500 */   sra       $a1, $a1, 24
    /* 2DD9C 8003D59C 0480023C */  lui        $v0, %hi(func_80042C08)
    /* 2DDA0 8003D5A0 082C4224 */  addiu      $v0, $v0, %lo(func_80042C08)
    /* 2DDA4 8003D5A4 4C0002AE */  sw         $v0, 0x4C($s0)
    /* 2DDA8 8003D5A8 040030AE */  sw         $s0, 0x4($s1)
  .L8003D5AC:
    /* 2DDAC 8003D5AC B9048493 */  lbu        $a0, %gp_rel(D_8009B3C1)($gp)
    /* 2DDB0 8003D5B0 0400308E */  lw         $s0, 0x4($s1)
    /* 2DDB4 8003D5B4 40008230 */  andi       $v0, $a0, 0x40
    /* 2DDB8 8003D5B8 04004010 */  beqz       $v0, .L8003D5CC
    /* 2DDBC 8003D5BC 00000000 */   nop
    /* 2DDC0 8003D5C0 B90480A3 */  sb         $zero, %gp_rel(D_8009B3C1)($gp)
    /* 2DDC4 8003D5C4 80F50008 */  j          .L8003D600
    /* 2DDC8 8003D5C8 00000000 */   nop
  .L8003D5CC:
    /* 2DDCC 8003D5CC 4A000296 */  lhu        $v0, 0x4A($s0)
    /* 2DDD0 8003D5D0 48000396 */  lhu        $v1, 0x48($s0)
    /* 2DDD4 8003D5D4 F8FF4224 */  addiu      $v0, $v0, -0x8
    /* 2DDD8 8003D5D8 F8FF6324 */  addiu      $v1, $v1, -0x8
    /* 2DDDC 8003D5DC 480003A6 */  sh         $v1, 0x48($s0)
    /* 2DDE0 8003D5E0 001C0300 */  sll        $v1, $v1, 16
    /* 2DDE4 8003D5E4 0600601C */  bgtz       $v1, .L8003D600
    /* 2DDE8 8003D5E8 4A0002A6 */   sh        $v0, 0x4A($s0)
    /* 2DDEC 8003D5EC 40008234 */  ori        $v0, $a0, 0x40
    /* 2DDF0 8003D5F0 B90482A3 */  sb         $v0, %gp_rel(D_8009B3C1)($gp)
    /* 2DDF4 8003D5F4 40000224 */  addiu      $v0, $zero, 0x40
    /* 2DDF8 8003D5F8 480000A6 */  sh         $zero, 0x48($s0)
    /* 2DDFC 8003D5FC 4A0002A6 */  sh         $v0, 0x4A($s0)
  .L8003D600:
    /* 2DE00 8003D600 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2DE04 8003D604 1400B18F */  lw         $s1, 0x14($sp)
    /* 2DE08 8003D608 1000B08F */  lw         $s0, 0x10($sp)
    /* 2DE0C 8003D60C 0800E003 */  jr         $ra
    /* 2DE10 8003D610 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003D518
