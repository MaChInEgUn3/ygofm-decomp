nonmatching func_8004CB0C, 0x628

glabel func_8004CB0C
    /* 3D30C 8004CB0C B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 3D310 8004CB10 4000B6AF */  sw         $s6, 0x40($sp)
    /* 3D314 8004CB14 21B08000 */  addu       $s6, $a0, $zero
    /* 3D318 8004CB18 C0101600 */  sll        $v0, $s6, 3
    /* 3D31C 8004CB1C 23105600 */  subu       $v0, $v0, $s6
    /* 3D320 8004CB20 00110200 */  sll        $v0, $v0, 4
    /* 3D324 8004CB24 21105600 */  addu       $v0, $v0, $s6
    /* 3D328 8004CB28 40110200 */  sll        $v0, $v0, 5
    /* 3D32C 8004CB2C 0F80033C */  lui        $v1, %hi(D_800F2C40)
    /* 3D330 8004CB30 402C6324 */  addiu      $v1, $v1, %lo(D_800F2C40)
    /* 3D334 8004CB34 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 3D338 8004CB38 21884300 */  addu       $s1, $v0, $v1
    /* 3D33C 8004CB3C 3800B4AF */  sw         $s4, 0x38($sp)
    /* 3D340 8004CB40 21A02002 */  addu       $s4, $s1, $zero
    /* 3D344 8004CB44 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 3D348 8004CB48 5400A5AF */  sw         $a1, 0x54($sp)
    /* 3D34C 8004CB4C 21A8A000 */  addu       $s5, $a1, $zero
    /* 3D350 8004CB50 0200C22A */  slti       $v0, $s6, 0x2
    /* 3D354 8004CB54 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 3D358 8004CB58 4800BEAF */  sw         $fp, 0x48($sp)
    /* 3D35C 8004CB5C 4400B7AF */  sw         $s7, 0x44($sp)
    /* 3D360 8004CB60 3400B3AF */  sw         $s3, 0x34($sp)
    /* 3D364 8004CB64 3000B2AF */  sw         $s2, 0x30($sp)
    /* 3D368 8004CB68 2800B0AF */  sw         $s0, 0x28($sp)
    /* 3D36C 8004CB6C 05004010 */  beqz       $v0, .L8004CB84
    /* 3D370 8004CB70 5800A6AF */   sw        $a2, 0x58($sp)
    /* 3D374 8004CB74 0F80023C */  lui        $v0, %hi(D_800E9D98)
    /* 3D378 8004CB78 989D5E8C */  lw         $fp, %lo(D_800E9D98)($v0)
    /* 3D37C 8004CB7C E4320108 */  j          .L8004CB90
    /* 3D380 8004CB80 2400A0AF */   sw        $zero, 0x24($sp)
  .L8004CB84:
    /* 3D384 8004CB84 0F80023C */  lui        $v0, %hi(D_800E9D9C)
    /* 3D388 8004CB88 9C9D5E8C */  lw         $fp, %lo(D_800E9D9C)($v0)
    /* 3D38C 8004CB8C 2400A0AF */  sw         $zero, 0x24($sp)
  .L8004CB90:
    /* 3D390 8004CB90 2000A0AF */  sw         $zero, 0x20($sp)
    /* 3D394 8004CB94 130E20A2 */  sb         $zero, 0xE13($s1)
    /* 3D398 8004CB98 0900E004 */  bltz       $a3, .L8004CBC0
    /* 3D39C 8004CB9C 120E20A2 */   sb        $zero, 0xE12($s1)
    /* 3D3A0 8004CBA0 7F00E230 */  andi       $v0, $a3, 0x7F
    /* 3D3A4 8004CBA4 110E22A2 */  sb         $v0, 0xE11($s1)
    /* 3D3A8 8004CBA8 8000E230 */  andi       $v0, $a3, 0x80
    /* 3D3AC 8004CBAC 03004010 */  beqz       $v0, .L8004CBBC
    /* 3D3B0 8004CBB0 05000224 */   addiu     $v0, $zero, 0x5
    /* 3D3B4 8004CBB4 F0320108 */  j          .L8004CBC0
    /* 3D3B8 8004CBB8 C70D22A2 */   sb        $v0, 0xDC7($s1)
  .L8004CBBC:
    /* 3D3BC 8004CBBC C70D20A2 */  sb         $zero, 0xDC7($s1)
  .L8004CBC0:
    /* 3D3C0 8004CBC0 A2FE0224 */  addiu      $v0, $zero, -0x15E
    /* 3D3C4 8004CBC4 C60D20A2 */  sb         $zero, 0xDC6($s1)
    /* 3D3C8 8004CBC8 C50D20A2 */  sb         $zero, 0xDC5($s1)
    /* 3D3CC 8004CBCC C40D20A2 */  sb         $zero, 0xDC4($s1)
    /* 3D3D0 8004CBD0 C80D20A6 */  sh         $zero, 0xDC8($s1)
    /* 3D3D4 8004CBD4 CA0D20A6 */  sh         $zero, 0xDCA($s1)
    /* 3D3D8 8004CBD8 CC0D20A6 */  sh         $zero, 0xDCC($s1)
    /* 3D3DC 8004CBDC CE0D20A6 */  sh         $zero, 0xDCE($s1)
    /* 3D3E0 8004CBE0 D00D20A6 */  sh         $zero, 0xDD0($s1)
    /* 3D3E4 8004CBE4 D60D22A6 */  sh         $v0, 0xDD6($s1)
    /* 3D3E8 8004CBE8 0600C012 */  beqz       $s6, .L8004CC04
    /* 3D3EC 8004CBEC D20D22A6 */   sh        $v0, 0xDD2($s1)
    /* 3D3F0 8004CBF0 01000224 */  addiu      $v0, $zero, 0x1
    /* 3D3F4 8004CBF4 0400C212 */  beq        $s6, $v0, .L8004CC08
    /* 3D3F8 8004CBF8 3EFE0224 */   addiu     $v0, $zero, -0x1C2
    /* 3D3FC 8004CBFC 03330108 */  j          .L8004CC0C
    /* 3D400 8004CC00 D40D20A6 */   sh        $zero, 0xDD4($s1)
  .L8004CC04:
    /* 3D404 8004CC04 C2010224 */  addiu      $v0, $zero, 0x1C2
  .L8004CC08:
    /* 3D408 8004CC08 D40D22A6 */  sh         $v0, 0xDD4($s1)
  .L8004CC0C:
    /* 3D40C 8004CC0C 06000224 */  addiu      $v0, $zero, 0x6
    /* 3D410 8004CC10 0E0E22A2 */  sb         $v0, 0xE0E($s1)
    /* 3D414 8004CC14 0200C22A */  slti       $v0, $s6, 0x2
    /* 3D418 8004CC18 0F0E20A2 */  sb         $zero, 0xE0F($s1)
    /* 3D41C 8004CC1C 100E20A2 */  sb         $zero, 0xE10($s1)
    /* 3D420 8004CC20 170E20A2 */  sb         $zero, 0xE17($s1)
    /* 3D424 8004CC24 180E20A2 */  sb         $zero, 0xE18($s1)
    /* 3D428 8004CC28 180D20AE */  sw         $zero, 0xD18($s1)
    /* 3D42C 8004CC2C 140D20AE */  sw         $zero, 0xD14($s1)
    /* 3D430 8004CC30 1C0D20AE */  sw         $zero, 0xD1C($s1)
    /* 3D434 8004CC34 190E20A2 */  sb         $zero, 0xE19($s1)
    /* 3D438 8004CC38 1B0E20A2 */  sb         $zero, 0xE1B($s1)
    /* 3D43C 8004CC3C 1C0E20A2 */  sb         $zero, 0xE1C($s1)
    /* 3D440 8004CC40 E80D20AE */  sw         $zero, 0xDE8($s1)
    /* 3D444 8004CC44 15004010 */  beqz       $v0, .L8004CC9C
    /* 3D448 8004CC48 EC0D20AE */   sw        $zero, 0xDEC($s1)
    /* 3D44C 8004CC4C 0500C012 */  beqz       $s6, .L8004CC64
    /* 3D450 8004CC50 00000000 */   nop
    /* 3D454 8004CC54 0180023C */  lui        $v0, %hi(D_80010020)
    /* 3D458 8004CC58 2000428C */  lw         $v0, %lo(D_80010020)($v0)
    /* 3D45C 8004CC5C 1D330108 */  j          .L8004CC74
    /* 3D460 8004CC60 E80D22AE */   sw        $v0, 0xDE8($s1)
  .L8004CC64:
    /* 3D464 8004CC64 0180023C */  lui        $v0, %hi(D_8001001C)
    /* 3D468 8004CC68 1C00428C */  lw         $v0, %lo(D_8001001C)($v0)
    /* 3D46C 8004CC6C 00000000 */  nop
    /* 3D470 8004CC70 E80D22AE */  sw         $v0, 0xDE8($s1)
  .L8004CC74:
    /* 3D474 8004CC74 0500C012 */  beqz       $s6, .L8004CC8C
    /* 3D478 8004CC78 00000000 */   nop
    /* 3D47C 8004CC7C 0180023C */  lui        $v0, %hi(D_80010028)
    /* 3D480 8004CC80 2800428C */  lw         $v0, %lo(D_80010028)($v0)
    /* 3D484 8004CC84 27330108 */  j          .L8004CC9C
    /* 3D488 8004CC88 EC0D22AE */   sw        $v0, 0xDEC($s1)
  .L8004CC8C:
    /* 3D48C 8004CC8C 0180023C */  lui        $v0, %hi(D_80010024)
    /* 3D490 8004CC90 2400428C */  lw         $v0, %lo(D_80010024)($v0)
    /* 3D494 8004CC94 00000000 */  nop
    /* 3D498 8004CC98 EC0D22AE */  sw         $v0, 0xDEC($s1)
  .L8004CC9C:
    /* 3D49C 8004CC9C F00D20AE */  sw         $zero, 0xDF0($s1)
    /* 3D4A0 8004CCA0 000E20A6 */  sh         $zero, 0xE00($s1)
    /* 3D4A4 8004CCA4 020E20A6 */  sh         $zero, 0xE02($s1)
    /* 3D4A8 8004CCA8 040E20A6 */  sh         $zero, 0xE04($s1)
    /* 3D4AC 8004CCAC F40D20AE */  sw         $zero, 0xDF4($s1)
    /* 3D4B0 8004CCB0 150E20A2 */  sb         $zero, 0xE15($s1)
    /* 3D4B4 8004CCB4 1E0E20A2 */  sb         $zero, 0xE1E($s1)
    /* 3D4B8 8004CCB8 1F0E20A2 */  sb         $zero, 0xE1F($s1)
    /* 3D4BC 8004CCBC 5400A88F */  lw         $t0, 0x54($sp)
    /* 3D4C0 8004CCC0 00000000 */  nop
    /* 3D4C4 8004CCC4 04000015 */  bnez       $t0, .L8004CCD8
    /* 3D4C8 8004CCC8 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 3D4CC 8004CCCC 1D0E20A2 */  sb         $zero, 0xE1D($s1)
    /* 3D4D0 8004CCD0 41340108 */  j          .L8004D104
    /* 3D4D4 8004CCD4 140E22A2 */   sb        $v0, 0xE14($s1)
  .L8004CCD8:
    /* 3D4D8 8004CCD8 5400A48F */  lw         $a0, 0x54($sp)
    /* 3D4DC 8004CCDC A028020C */  jal        func_8008A280
    /* 3D4E0 8004CCE0 0C00B526 */   addiu     $s5, $s5, 0xC
    /* 3D4E4 8004CCE4 5400A58F */  lw         $a1, 0x54($sp)
    /* 3D4E8 8004CCE8 6335010C */  jal        func_8004D58C
    /* 3D4EC 8004CCEC 2120C002 */   addu      $a0, $s6, $zero
    /* 3D4F0 8004CCF0 0000A292 */  lbu        $v0, 0x0($s5)
    /* 3D4F4 8004CCF4 00000000 */  nop
    /* 3D4F8 8004CCF8 1A0E22A2 */  sb         $v0, 0xE1A($s1)
    /* 3D4FC 8004CCFC FF004230 */  andi       $v0, $v0, 0xFF
    /* 3D500 8004CD00 3D00422C */  sltiu      $v0, $v0, 0x3D
    /* 3D504 8004CD04 03004014 */  bnez       $v0, .L8004CD14
    /* 3D508 8004CD08 0400B526 */   addiu     $s5, $s5, 0x4
    /* 3D50C 8004CD0C 3C000224 */  addiu      $v0, $zero, 0x3C
    /* 3D510 8004CD10 1A0E22A2 */  sb         $v0, 0xE1A($s1)
  .L8004CD14:
    /* 3D514 8004CD14 1A0E2292 */  lbu        $v0, 0xE1A($s1)
    /* 3D518 8004CD18 00000000 */  nop
    /* 3D51C 8004CD1C 63004010 */  beqz       $v0, .L8004CEAC
    /* 3D520 8004CD20 21900000 */   addu      $s2, $zero, $zero
    /* 3D524 8004CD24 2400B727 */  addiu      $s7, $sp, 0x24
  .L8004CD28:
    /* 3D528 8004CD28 000080AE */  sw         $zero, 0x0($s4)
    /* 3D52C 8004CD2C 0000A48E */  lw         $a0, 0x0($s5)
    /* 3D530 8004CD30 0400B526 */  addiu      $s5, $s5, 0x4
    /* 3D534 8004CD34 57008010 */  beqz       $a0, .L8004CE94
    /* 3D538 8004CD38 040084AE */   sw        $a0, 0x4($s4)
    /* 3D53C 8004CD3C 21280000 */  addu       $a1, $zero, $zero
    /* 3D540 8004CD40 2130A000 */  addu       $a2, $a1, $zero
    /* 3D544 8004CD44 E027020C */  jal        func_80089F80
    /* 3D548 8004CD48 2138A000 */   addu      $a3, $a1, $zero
  .L8004CD4C:
    /* 3D54C 8004CD4C 21200000 */  addu       $a0, $zero, $zero
  .L8004CD50:
    /* 3D550 8004CD50 1800A527 */  addiu      $a1, $sp, 0x18
    /* 3D554 8004CD54 2130C003 */  addu       $a2, $fp, $zero
    /* 3D558 8004CD58 E027020C */  jal        func_80089F80
    /* 3D55C 8004CD5C 801F073C */   lui       $a3, (0x1F800000 >> 16)
    /* 3D560 8004CD60 4C004010 */  beqz       $v0, .L8004CE94
    /* 3D564 8004CD64 801F133C */   lui       $s3, (0x1F800000 >> 16)
    /* 3D568 8004CD68 1800A38F */  lw         $v1, 0x18($sp)
    /* 3D56C 8004CD6C 00000000 */  nop
    /* 3D570 8004CD70 F6FF6010 */  beqz       $v1, .L8004CD4C
    /* 3D574 8004CD74 02860300 */   srl       $s0, $v1, 24
    /* 3D578 8004CD78 0200022E */  sltiu      $v0, $s0, 0x2
    /* 3D57C 8004CD7C 07004014 */  bnez       $v0, .L8004CD9C
    /* 3D580 8004CD80 8000023C */   lui       $v0, (0x800000 >> 16)
    /* 3D584 8004CD84 0700022E */  sltiu      $v0, $s0, 0x7
    /* 3D588 8004CD88 11004010 */  beqz       $v0, .L8004CDD0
    /* 3D58C 8004CD8C 0500022E */   sltiu     $v0, $s0, 0x5
    /* 3D590 8004CD90 10004014 */  bnez       $v0, .L8004CDD4
    /* 3D594 8004CD94 01000224 */   addiu     $v0, $zero, 0x1
    /* 3D598 8004CD98 8000023C */  lui        $v0, (0x800000 >> 16)
  .L8004CD9C:
    /* 3D59C 8004CD9C 24106200 */  and        $v0, $v1, $v0
    /* 3D5A0 8004CDA0 0C004010 */  beqz       $v0, .L8004CDD4
    /* 3D5A4 8004CDA4 01000224 */   addiu     $v0, $zero, 0x1
    /* 3D5A8 8004CDA8 1C00A58F */  lw         $a1, 0x1C($sp)
    /* 3D5AC 8004CDAC 5400A48F */  lw         $a0, 0x54($sp)
    /* 3D5B0 8004CDB0 0829020C */  jal        func_8008A420
    /* 3D5B4 8004CDB4 00000000 */   nop
    /* 3D5B8 8004CDB8 7FFF033C */  lui        $v1, (0xFF7FFFFF >> 16)
    /* 3D5BC 8004CDBC 140D22AE */  sw         $v0, 0xD14($s1)
    /* 3D5C0 8004CDC0 1800A28F */  lw         $v0, 0x18($sp)
    /* 3D5C4 8004CDC4 FFFF6334 */  ori        $v1, $v1, (0xFF7FFFFF & 0xFFFF)
    /* 3D5C8 8004CDC8 24104300 */  and        $v0, $v0, $v1
    /* 3D5CC 8004CDCC 1800A2AF */  sw         $v0, 0x18($sp)
  .L8004CDD0:
    /* 3D5D0 8004CDD0 01000224 */  addiu      $v0, $zero, 0x1
  .L8004CDD4:
    /* 3D5D4 8004CDD4 15000212 */  beq        $s0, $v0, .L8004CE2C
    /* 3D5D8 8004CDD8 2120C002 */   addu      $a0, $s6, $zero
    /* 3D5DC 8004CDDC 07000012 */  beqz       $s0, .L8004CDFC
    /* 3D5E0 8004CDE0 02000224 */   addiu     $v0, $zero, 0x2
    /* 3D5E4 8004CDE4 1D000212 */  beq        $s0, $v0, .L8004CE5C
    /* 3D5E8 8004CDE8 03000224 */   addiu     $v0, $zero, 0x3
    /* 3D5EC 8004CDEC 20000212 */  beq        $s0, $v0, .L8004CE70
    /* 3D5F0 8004CDF0 1800A427 */   addiu     $a0, $sp, 0x18
    /* 3D5F4 8004CDF4 A0330108 */  j          .L8004CE80
    /* 3D5F8 8004CDF8 00000000 */   nop
  .L8004CDFC:
    /* 3D5FC 8004CDFC 1800A527 */  addiu      $a1, $sp, 0x18
    /* 3D600 8004CE00 21306002 */  addu       $a2, $s3, $zero
    /* 3D604 8004CE04 2000A727 */  addiu      $a3, $sp, 0x20
    /* 3D608 8004CE08 4D34010C */  jal        func_8004D134
    /* 3D60C 8004CE0C 1000B7AF */   sw        $s7, 0x10($sp)
    /* 3D610 8004CE10 040E2396 */  lhu        $v1, 0xE04($s1)
    /* 3D614 8004CE14 1800A427 */  addiu      $a0, $sp, 0x18
    /* 3D618 8004CE18 21186200 */  addu       $v1, $v1, $v0
    /* 3D61C 8004CE1C 1B82010C */  jal        func_8006086C
    /* 3D620 8004CE20 040E23A6 */   sh        $v1, 0xE04($s1)
    /* 3D624 8004CE24 54330108 */  j          .L8004CD50
    /* 3D628 8004CE28 21200000 */   addu      $a0, $zero, $zero
  .L8004CE2C:
    /* 3D62C 8004CE2C 1800A527 */  addiu      $a1, $sp, 0x18
    /* 3D630 8004CE30 21306002 */  addu       $a2, $s3, $zero
    /* 3D634 8004CE34 21380000 */  addu       $a3, $zero, $zero
    /* 3D638 8004CE38 4D34010C */  jal        func_8004D134
    /* 3D63C 8004CE3C 1000B7AF */   sw        $s7, 0x10($sp)
    /* 3D640 8004CE40 040E2396 */  lhu        $v1, 0xE04($s1)
    /* 3D644 8004CE44 1800A427 */  addiu      $a0, $sp, 0x18
    /* 3D648 8004CE48 21186200 */  addu       $v1, $v1, $v0
    /* 3D64C 8004CE4C BB82010C */  jal        func_80060AEC
    /* 3D650 8004CE50 040E23A6 */   sh        $v1, 0xE04($s1)
    /* 3D654 8004CE54 54330108 */  j          .L8004CD50
    /* 3D658 8004CE58 21200000 */   addu      $a0, $zero, $zero
  .L8004CE5C:
    /* 3D65C 8004CE5C 1800A527 */  addiu      $a1, $sp, 0x18
    /* 3D660 8004CE60 8880010C */  jal        func_80060220
    /* 3D664 8004CE64 21306002 */   addu      $a2, $s3, $zero
    /* 3D668 8004CE68 54330108 */  j          .L8004CD50
    /* 3D66C 8004CE6C 21200000 */   addu      $a0, $zero, $zero
  .L8004CE70:
    /* 3D670 8004CE70 A871010C */  jal        func_8005C6A0
    /* 3D674 8004CE74 21282002 */   addu      $a1, $s1, $zero
    /* 3D678 8004CE78 54330108 */  j          .L8004CD50
    /* 3D67C 8004CE7C 21200000 */   addu      $a0, $zero, $zero
  .L8004CE80:
    /* 3D680 8004CE80 1C00A28F */  lw         $v0, 0x1C($sp)
    /* 3D684 8004CE84 0980093C */  lui        $t1, %hi(func_80089E20)
    /* 3D688 8004CE88 209E2925 */  addiu      $t1, $t1, %lo(func_80089E20)
    /* 3D68C 8004CE8C 53330108 */  j          .L8004CD4C
    /* 3D690 8004CE90 000049AC */   sw        $t1, 0x0($v0)
  .L8004CE94:
    /* 3D694 8004CE94 01005226 */  addiu      $s2, $s2, 0x1
    /* 3D698 8004CE98 1A0E2292 */  lbu        $v0, 0xE1A($s1)
    /* 3D69C 8004CE9C 00000000 */  nop
    /* 3D6A0 8004CEA0 2A104202 */  slt        $v0, $s2, $v0
    /* 3D6A4 8004CEA4 A0FF4014 */  bnez       $v0, .L8004CD28
    /* 3D6A8 8004CEA8 08009426 */   addiu     $s4, $s4, 0x8
  .L8004CEAC:
    /* 3D6AC 8004CEAC 08003426 */  addiu      $s4, $s1, 0x8
    /* 3D6B0 8004CEB0 01001224 */  addiu      $s2, $zero, 0x1
    /* 3D6B4 8004CEB4 1A0E2392 */  lbu        $v1, 0xE1A($s1)
    /* 3D6B8 8004CEB8 2400A297 */  lhu        $v0, 0x24($sp)
    /* 3D6BC 8004CEBC FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 3D6C0 8004CEC0 000E22A6 */  sh         $v0, 0xE00($s1)
    /* 3D6C4 8004CEC4 2000A297 */  lhu        $v0, 0x20($sp)
    /* 3D6C8 8004CEC8 2A184302 */  slt        $v1, $s2, $v1
    /* 3D6CC 8004CECC 21105200 */  addu       $v0, $v0, $s2
    /* 3D6D0 8004CED0 16006010 */  beqz       $v1, .L8004CF2C
    /* 3D6D4 8004CED4 020E22A6 */   sh        $v0, 0xE02($s1)
    /* 3D6D8 8004CED8 21180000 */  addu       $v1, $zero, $zero
  .L8004CEDC:
    /* 3D6DC 8004CEDC 170E2292 */  lbu        $v0, 0xE17($s1)
    /* 3D6E0 8004CEE0 00000000 */  nop
    /* 3D6E4 8004CEE4 01004224 */  addiu      $v0, $v0, 0x1
    /* 3D6E8 8004CEE8 170E22A2 */  sb         $v0, 0xE17($s1)
    /* 3D6EC 8004CEEC 0400828E */  lw         $v0, 0x4($s4)
    /* 3D6F0 8004CEF0 00000000 */  nop
    /* 3D6F4 8004CEF4 05004010 */  beqz       $v0, .L8004CF0C
    /* 3D6F8 8004CEF8 00000000 */   nop
    /* 3D6FC 8004CEFC 140D228E */  lw         $v0, 0xD14($s1)
    /* 3D700 8004CF00 00000000 */  nop
    /* 3D704 8004CF04 21104300 */  addu       $v0, $v0, $v1
    /* 3D708 8004CF08 000082AE */  sw         $v0, 0x0($s4)
  .L8004CF0C:
    /* 3D70C 8004CF0C 50006324 */  addiu      $v1, $v1, 0x50
    /* 3D710 8004CF10 01005226 */  addiu      $s2, $s2, 0x1
    /* 3D714 8004CF14 1A0E2292 */  lbu        $v0, 0xE1A($s1)
    /* 3D718 8004CF18 00000000 */  nop
    /* 3D71C 8004CF1C FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 3D720 8004CF20 2A104202 */  slt        $v0, $s2, $v0
    /* 3D724 8004CF24 EDFF4014 */  bnez       $v0, .L8004CEDC
    /* 3D728 8004CF28 08009426 */   addiu     $s4, $s4, 0x8
  .L8004CF2C:
    /* 3D72C 8004CF2C 140D238E */  lw         $v1, 0xD14($s1)
    /* 3D730 8004CF30 00000000 */  nop
    /* 3D734 8004CF34 6A006010 */  beqz       $v1, .L8004D0E0
    /* 3D738 8004CF38 00000000 */   nop
    /* 3D73C 8004CF3C 4C00628C */  lw         $v0, 0x4C($v1)
    /* 3D740 8004CF40 00000000 */  nop
    /* 3D744 8004CF44 06004010 */  beqz       $v0, .L8004CF60
    /* 3D748 8004CF48 21900000 */   addu      $s2, $zero, $zero
  .L8004CF4C:
    /* 3D74C 8004CF4C 50006324 */  addiu      $v1, $v1, 0x50
    /* 3D750 8004CF50 4C00628C */  lw         $v0, 0x4C($v1)
    /* 3D754 8004CF54 00000000 */  nop
    /* 3D758 8004CF58 FCFF4014 */  bnez       $v0, .L8004CF4C
    /* 3D75C 8004CF5C 01005226 */   addiu     $s2, $s2, 0x1
  .L8004CF60:
    /* 3D760 8004CF60 21202002 */  addu       $a0, $s1, $zero
    /* 3D764 8004CF64 80101200 */  sll        $v0, $s2, 2
    /* 3D768 8004CF68 21105200 */  addu       $v0, $v0, $s2
    /* 3D76C 8004CF6C 140D258E */  lw         $a1, 0xD14($s1)
    /* 3D770 8004CF70 00110200 */  sll        $v0, $v0, 4
    /* 3D774 8004CF74 180E32A2 */  sb         $s2, 0xE18($s1)
    /* 3D778 8004CF78 2128A200 */  addu       $a1, $a1, $v0
    /* 3D77C 8004CF7C F468010C */  jal        func_8005A3D0
    /* 3D780 8004CF80 180D25AE */   sw        $a1, 0xD18($s1)
    /* 3D784 8004CF84 170E2392 */  lbu        $v1, 0xE17($s1)
    /* 3D788 8004CF88 190E22A2 */  sb         $v0, 0xE19($s1)
    /* 3D78C 8004CF8C FF004230 */  andi       $v0, $v0, 0xFF
    /* 3D790 8004CF90 2B104300 */  sltu       $v0, $v0, $v1
    /* 3D794 8004CF94 04004014 */  bnez       $v0, .L8004CFA8
    /* 3D798 8004CF98 00000000 */   nop
    /* 3D79C 8004CF9C 180E2292 */  lbu        $v0, 0xE18($s1)
    /* 3D7A0 8004CFA0 00000000 */  nop
    /* 3D7A4 8004CFA4 190E22A2 */  sb         $v0, 0xE19($s1)
  .L8004CFA8:
    /* 3D7A8 8004CFA8 190E2292 */  lbu        $v0, 0xE19($s1)
    /* 3D7AC 8004CFAC 00000000 */  nop
    /* 3D7B0 8004CFB0 80180200 */  sll        $v1, $v0, 2
    /* 3D7B4 8004CFB4 21186200 */  addu       $v1, $v1, $v0
    /* 3D7B8 8004CFB8 140D228E */  lw         $v0, 0xD14($s1)
    /* 3D7BC 8004CFBC 00190300 */  sll        $v1, $v1, 4
    /* 3D7C0 8004CFC0 21804300 */  addu       $s0, $v0, $v1
    /* 3D7C4 8004CFC4 1C0D30AE */  sw         $s0, 0xD1C($s1)
  .L8004CFC8:
    /* 3D7C8 8004CFC8 21A02002 */  addu       $s4, $s1, $zero
    /* 3D7CC 8004CFCC 1A0E2292 */  lbu        $v0, 0xE1A($s1)
    /* 3D7D0 8004CFD0 00000000 */  nop
    /* 3D7D4 8004CFD4 20004010 */  beqz       $v0, .L8004D058
    /* 3D7D8 8004CFD8 21900000 */   addu      $s2, $zero, $zero
    /* 3D7DC 8004CFDC FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 3D7E0 8004CFE0 21284000 */  addu       $a1, $v0, $zero
  .L8004CFE4:
    /* 3D7E4 8004CFE4 0000848E */  lw         $a0, 0x0($s4)
    /* 3D7E8 8004CFE8 00000000 */  nop
    /* 3D7EC 8004CFEC 11008010 */  beqz       $a0, .L8004D034
    /* 3D7F0 8004CFF0 00000000 */   nop
    /* 3D7F4 8004CFF4 0400838E */  lw         $v1, 0x4($s4)
    /* 3D7F8 8004CFF8 00000000 */  nop
    /* 3D7FC 8004CFFC 0D006010 */  beqz       $v1, .L8004D034
    /* 3D800 8004D000 00000000 */   nop
    /* 3D804 8004D004 0000628C */  lw         $v0, 0x0($v1)
    /* 3D808 8004D008 00000000 */  nop
    /* 3D80C 8004D00C 05004614 */  bne        $v0, $a2, .L8004D024
    /* 3D810 8004D010 00000000 */   nop
    /* 3D814 8004D014 0800628C */  lw         $v0, 0x8($v1)
    /* 3D818 8004D018 00000000 */  nop
    /* 3D81C 8004D01C 05004010 */  beqz       $v0, .L8004D034
    /* 3D820 8004D020 00000000 */   nop
  .L8004D024:
    /* 3D824 8004D024 4C00828C */  lw         $v0, 0x4C($a0)
    /* 3D828 8004D028 00000000 */  nop
    /* 3D82C 8004D02C 05005010 */  beq        $v0, $s0, .L8004D044
    /* 3D830 8004D030 00000000 */   nop
  .L8004D034:
    /* 3D834 8004D034 01005226 */  addiu      $s2, $s2, 0x1
    /* 3D838 8004D038 2A104502 */  slt        $v0, $s2, $a1
    /* 3D83C 8004D03C E9FF4014 */  bnez       $v0, .L8004CFE4
    /* 3D840 8004D040 08009426 */   addiu     $s4, $s4, 0x8
  .L8004D044:
    /* 3D844 8004D044 1A0E2292 */  lbu        $v0, 0xE1A($s1)
    /* 3D848 8004D048 00000000 */  nop
    /* 3D84C 8004D04C 2A104202 */  slt        $v0, $s2, $v0
    /* 3D850 8004D050 0E004014 */  bnez       $v0, .L8004D08C
    /* 3D854 8004D054 00000000 */   nop
  .L8004D058:
    /* 3D858 8004D058 21202002 */  addu       $a0, $s1, $zero
    /* 3D85C 8004D05C F468010C */  jal        func_8005A3D0
    /* 3D860 8004D060 21280002 */   addu      $a1, $s0, $zero
    /* 3D864 8004D064 170E2392 */  lbu        $v1, 0xE17($s1)
    /* 3D868 8004D068 21204000 */  addu       $a0, $v0, $zero
    /* 3D86C 8004D06C 2A188300 */  slt        $v1, $a0, $v1
    /* 3D870 8004D070 06006010 */  beqz       $v1, .L8004D08C
    /* 3D874 8004D074 80100400 */   sll       $v0, $a0, 2
    /* 3D878 8004D078 21104400 */  addu       $v0, $v0, $a0
    /* 3D87C 8004D07C 140D238E */  lw         $v1, 0xD14($s1)
    /* 3D880 8004D080 00110200 */  sll        $v0, $v0, 4
    /* 3D884 8004D084 F2330108 */  j          .L8004CFC8
    /* 3D888 8004D088 21806200 */   addu      $s0, $v1, $v0
  .L8004D08C:
    /* 3D88C 8004D08C 4C00058E */  lw         $a1, 0x4C($s0)
    /* 3D890 8004D090 180D228E */  lw         $v0, 0xD18($s1)
    /* 3D894 8004D094 00000000 */  nop
    /* 3D898 8004D098 1100A210 */  beq        $a1, $v0, .L8004D0E0
    /* 3D89C 8004D09C 00000000 */   nop
    /* 3D8A0 8004D0A0 0F00A010 */  beqz       $a1, .L8004D0E0
    /* 3D8A4 8004D0A4 1C0D25AE */   sw        $a1, 0xD1C($s1)
    /* 3D8A8 8004D0A8 140D238E */  lw         $v1, 0xD14($s1)
    /* 3D8AC 8004D0AC 00000000 */  nop
    /* 3D8B0 8004D0B0 2318A300 */  subu       $v1, $a1, $v1
    /* 3D8B4 8004D0B4 40100300 */  sll        $v0, $v1, 1
    /* 3D8B8 8004D0B8 21104300 */  addu       $v0, $v0, $v1
    /* 3D8BC 8004D0BC 00190200 */  sll        $v1, $v0, 4
    /* 3D8C0 8004D0C0 21104300 */  addu       $v0, $v0, $v1
    /* 3D8C4 8004D0C4 001A0200 */  sll        $v1, $v0, 8
    /* 3D8C8 8004D0C8 21104300 */  addu       $v0, $v0, $v1
    /* 3D8CC 8004D0CC 001C0200 */  sll        $v1, $v0, 16
    /* 3D8D0 8004D0D0 21104300 */  addu       $v0, $v0, $v1
    /* 3D8D4 8004D0D4 23100200 */  negu       $v0, $v0
    /* 3D8D8 8004D0D8 03110200 */  sra        $v0, $v0, 4
    /* 3D8DC 8004D0DC 190E22A2 */  sb         $v0, 0xE19($s1)
  .L8004D0E0:
    /* 3D8E0 8004D0E0 E00D228E */  lw         $v0, 0xDE0($s1)
    /* 3D8E4 8004D0E4 00000000 */  nop
    /* 3D8E8 8004D0E8 06004014 */  bnez       $v0, .L8004D104
    /* 3D8EC 8004D0EC 00000000 */   nop
    /* 3D8F0 8004D0F0 5400A88F */  lw         $t0, 0x54($sp)
    /* 3D8F4 8004D0F4 5800A98F */  lw         $t1, 0x58($sp)
    /* 3D8F8 8004D0F8 00000000 */  nop
    /* 3D8FC 8004D0FC 21100901 */  addu       $v0, $t0, $t1
    /* 3D900 8004D100 E00D22AE */  sw         $v0, 0xDE0($s1)
  .L8004D104:
    /* 3D904 8004D104 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 3D908 8004D108 4800BE8F */  lw         $fp, 0x48($sp)
    /* 3D90C 8004D10C 4400B78F */  lw         $s7, 0x44($sp)
    /* 3D910 8004D110 4000B68F */  lw         $s6, 0x40($sp)
    /* 3D914 8004D114 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 3D918 8004D118 3800B48F */  lw         $s4, 0x38($sp)
    /* 3D91C 8004D11C 3400B38F */  lw         $s3, 0x34($sp)
    /* 3D920 8004D120 3000B28F */  lw         $s2, 0x30($sp)
    /* 3D924 8004D124 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 3D928 8004D128 2800B08F */  lw         $s0, 0x28($sp)
    /* 3D92C 8004D12C 0800E003 */  jr         $ra
    /* 3D930 8004D130 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_8004CB0C
