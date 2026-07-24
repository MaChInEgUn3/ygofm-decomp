nonmatching func_8004EB00, 0x132C

glabel func_8004EB00
    /* 3F300 8004EB00 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* 3F304 8004EB04 0180023C */  lui        $v0, %hi(D_800114E8)
    /* 3F308 8004EB08 1D80033C */  lui        $v1, %hi(D_801D4244)
    /* 3F30C 8004EB0C 3C00BFAF */  sw         $ra, 0x3C($sp)
    /* 3F310 8004EB10 3800B2AF */  sw         $s2, 0x38($sp)
    /* 3F314 8004EB14 3400B1AF */  sw         $s1, 0x34($sp)
    /* 3F318 8004EB18 3000B0AF */  sw         $s0, 0x30($sp)
    /* 3F31C 8004EB1C E8144B24 */  addiu      $t3, $v0, %lo(D_800114E8)
    /* 3F320 8004EB20 0000688D */  lw         $t0, 0x0($t3)
    /* 3F324 8004EB24 0400698D */  lw         $t1, 0x4($t3)
    /* 3F328 8004EB28 08006A8D */  lw         $t2, 0x8($t3)
    /* 3F32C 8004EB2C 1800A8AF */  sw         $t0, 0x18($sp)
    /* 3F330 8004EB30 1C00A9AF */  sw         $t1, 0x1C($sp)
    /* 3F334 8004EB34 2000AAAF */  sw         $t2, 0x20($sp)
    /* 3F338 8004EB38 0C00688D */  lw         $t0, 0xC($t3)
    /* 3F33C 8004EB3C 00000000 */  nop
    /* 3F340 8004EB40 2400A8AF */  sw         $t0, 0x24($sp)
    /* 3F344 8004EB44 0F80023C */  lui        $v0, %hi(D_800F4858)
    /* 3F348 8004EB48 58484294 */  lhu        $v0, %lo(D_800F4858)($v0)
    /* 3F34C 8004EB4C 44426324 */  addiu      $v1, $v1, %lo(D_801D4244)
    /* 3F350 8004EB50 80100200 */  sll        $v0, $v0, 2
    /* 3F354 8004EB54 21104300 */  addu       $v0, $v0, $v1
    /* 3F358 8004EB58 0000428C */  lw         $v0, 0x0($v0)
    /* 3F35C 8004EB5C 01001224 */  addiu      $s2, $zero, 0x1
    /* 3F360 8004EB60 83160200 */  sra        $v0, $v0, 26
    /* 3F364 8004EB64 1F004230 */  andi       $v0, $v0, 0x1F
    /* 3F368 8004EB68 02005214 */  bne        $v0, $s2, .L8004EB74
    /* 3F36C 8004EB6C 00000000 */   nop
    /* 3F370 8004EB70 02001224 */  addiu      $s2, $zero, 0x2
  .L8004EB74:
    /* 3F374 8004EB74 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3F378 8004EB78 00000000 */  nop
    /* 3F37C 8004EB7C 01004224 */  addiu      $v0, $v0, 0x1
    /* 3F380 8004EB80 00160200 */  sll        $v0, $v0, 24
    /* 3F384 8004EB84 031E0200 */  sra        $v1, $v0, 24
    /* 3F388 8004EB88 2B00622C */  sltiu      $v0, $v1, 0x2B
    /* 3F38C 8004EB8C 9F044010 */  beqz       $v0, .L8004FE0C
    /* 3F390 8004EB90 0180023C */   lui       $v0, %hi(jtbl_800115AC)
    /* 3F394 8004EB94 AC154224 */  addiu      $v0, $v0, %lo(jtbl_800115AC)
    /* 3F398 8004EB98 80180300 */  sll        $v1, $v1, 2
    /* 3F39C 8004EB9C 21186200 */  addu       $v1, $v1, $v0
    /* 3F3A0 8004EBA0 0000628C */  lw         $v0, 0x0($v1)
    /* 3F3A4 8004EBA4 00000000 */  nop
    /* 3F3A8 8004EBA8 08004000 */  jr         $v0
    /* 3F3AC 8004EBAC 00000000 */   nop
  jlabel .L8004EBB0
    /* 3F3B0 8004EBB0 02000424 */  addiu      $a0, $zero, 0x2
    /* 3F3B4 8004EBB4 00F00524 */  addiu      $a1, $zero, -0x1000
    /* 3F3B8 8004EBB8 2130A000 */  addu       $a2, $a1, $zero
    /* 3F3BC 8004EBBC 7265010C */  jal        func_800595C8
    /* 3F3C0 8004EBC0 2138A000 */   addu      $a3, $a1, $zero
    /* 3F3C4 8004EBC4 21200000 */  addu       $a0, $zero, $zero
    /* 3F3C8 8004EBC8 05000524 */  addiu      $a1, $zero, 0x5
    /* 3F3CC 8004EBCC 21308000 */  addu       $a2, $a0, $zero
    /* 3F3D0 8004EBD0 21388000 */  addu       $a3, $a0, $zero
    /* 3F3D4 8004EBD4 6465010C */  jal        func_80059590
    /* 3F3D8 8004EBD8 1000A0AF */   sw        $zero, 0x10($sp)
    /* 3F3DC 8004EBDC 01000424 */  addiu      $a0, $zero, 0x1
    /* 3F3E0 8004EBE0 05000524 */  addiu      $a1, $zero, 0x5
    /* 3F3E4 8004EBE4 21300000 */  addu       $a2, $zero, $zero
    /* 3F3E8 8004EBE8 2138C000 */  addu       $a3, $a2, $zero
    /* 3F3EC 8004EBEC 6465010C */  jal        func_80059590
    /* 3F3F0 8004EBF0 1000A0AF */   sw        $zero, 0x10($sp)
    /* 3F3F4 8004EBF4 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3F3F8 8004EBF8 823F0108 */  j          .L8004FE08
    /* 3F3FC 8004EBFC 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004EC00
    /* 3F400 8004EC00 8E008497 */  lhu        $a0, %gp_rel(D_8009AF96)($gp)
    /* 3F404 8004EC04 C51C010C */  jal        func_80047314
    /* 3F408 8004EC08 00000000 */   nop
    /* 3F40C 8004EC0C 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3F410 8004EC10 823F0108 */  j          .L8004FE08
    /* 3F414 8004EC14 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004EC18
    /* 3F418 8004EC18 8000838F */  lw         $v1, %gp_rel(D_8009AF88)($gp)
    /* 3F41C 8004EC1C 0A80023C */  lui        $v0, %hi(D_8009AFEC)
    /* 3F420 8004EC20 ECAF4B24 */  addiu      $t3, $v0, %lo(D_8009AFEC)
    /* 3F424 8004EC24 03006889 */  lwl        $t0, 0x3($t3)
    /* 3F428 8004EC28 00006899 */  lwr        $t0, 0x0($t3)
    /* 3F42C 8004EC2C 07006989 */  lwl        $t1, 0x7($t3)
    /* 3F430 8004EC30 04006999 */  lwr        $t1, 0x4($t3)
    /* 3F434 8004EC34 2B00A8AB */  swl        $t0, 0x2B($sp)
    /* 3F438 8004EC38 2800A8BB */  swr        $t0, 0x28($sp)
    /* 3F43C 8004EC3C 2F00A9AB */  swl        $t1, 0x2F($sp)
    /* 3F440 8004EC40 2C00A9BB */  swr        $t1, 0x2C($sp)
    /* 3F444 8004EC44 A0006390 */  lbu        $v1, 0xA0($v1)
    /* 3F448 8004EC48 00000000 */  nop
    /* 3F44C 8004EC4C 0700622C */  sltiu      $v0, $v1, 0x7
    /* 3F450 8004EC50 21004010 */  beqz       $v0, .L8004ECD8
    /* 3F454 8004EC54 78001024 */   addiu     $s0, $zero, 0x78
    /* 3F458 8004EC58 0180023C */  lui        $v0, %hi(jtbl_8001165C)
    /* 3F45C 8004EC5C 5C164224 */  addiu      $v0, $v0, %lo(jtbl_8001165C)
    /* 3F460 8004EC60 80180300 */  sll        $v1, $v1, 2
    /* 3F464 8004EC64 21186200 */  addu       $v1, $v1, $v0
    /* 3F468 8004EC68 0000628C */  lw         $v0, 0x0($v1)
    /* 3F46C 8004EC6C 00000000 */  nop
    /* 3F470 8004EC70 08004000 */  jr         $v0
    /* 3F474 8004EC74 00000000 */   nop
  jlabel .L8004EC78
    /* 3F478 8004EC78 02000424 */  addiu      $a0, $zero, 0x2
    /* 3F47C 8004EC7C 0A000524 */  addiu      $a1, $zero, 0xA
    /* 3F480 8004EC80 9F7C010C */  jal        func_8005F27C
    /* 3F484 8004EC84 21300000 */   addu      $a2, $zero, $zero
    /* 3F488 8004EC88 373B0108 */  j          .L8004ECDC
    /* 3F48C 8004EC8C 21200000 */   addu      $a0, $zero, $zero
  jlabel .L8004EC90
    /* 3F490 8004EC90 697C010C */  jal        func_8005F1A4
    /* 3F494 8004EC94 0A000424 */   addiu     $a0, $zero, 0xA
    /* 3F498 8004EC98 02000424 */  addiu      $a0, $zero, 0x2
    /* 3F49C 8004EC9C 64000524 */  addiu      $a1, $zero, 0x64
    /* 3F4A0 8004ECA0 21804000 */  addu       $s0, $v0, $zero
    /* 3F4A4 8004ECA4 02000686 */  lh         $a2, 0x2($s0)
    /* 3F4A8 8004ECA8 00FC0724 */  addiu      $a3, $zero, -0x400
    /* 3F4AC 8004ECAC 1000A0AF */  sw         $zero, 0x10($sp)
    /* 3F4B0 8004ECB0 EE7C010C */  jal        func_8005F3B8
    /* 3F4B4 8004ECB4 0008C624 */   addiu     $a2, $a2, 0x800
    /* 3F4B8 8004ECB8 00000396 */  lhu        $v1, 0x0($s0)
    /* 3F4BC 8004ECBC 00F00224 */  addiu      $v0, $zero, -0x1000
    /* 3F4C0 8004ECC0 2A00A2A7 */  sh         $v0, 0x2A($sp)
    /* 3F4C4 8004ECC4 2800A3A7 */  sh         $v1, 0x28($sp)
    /* 3F4C8 8004ECC8 04000296 */  lhu        $v0, 0x4($s0)
    /* 3F4CC 8004ECCC 96001024 */  addiu      $s0, $zero, 0x96
    /* 3F4D0 8004ECD0 00044224 */  addiu      $v0, $v0, 0x400
    /* 3F4D4 8004ECD4 2C00A2A7 */  sh         $v0, 0x2C($sp)
  .L8004ECD8:
    /* 3F4D8 8004ECD8 21200000 */  addu       $a0, $zero, $zero
  .L8004ECDC:
    /* 3F4DC 8004ECDC 2800A527 */  addiu      $a1, $sp, 0x28
    /* 3F4E0 8004ECE0 21308000 */  addu       $a2, $a0, $zero
    /* 3F4E4 8004ECE4 477E010C */  jal        func_8005F91C
    /* 3F4E8 8004ECE8 21380002 */   addu      $a3, $s0, $zero
    /* 3F4EC 8004ECEC 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3F4F0 8004ECF0 823F0108 */  j          .L8004FE08
    /* 3F4F4 8004ECF4 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004ECF8
    /* 3F4F8 8004ECF8 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 3F4FC 8004ECFC 402C5024 */  addiu      $s0, $v0, %lo(D_800F2C40)
    /* 3F500 8004ED00 E029028E */  lw         $v0, 0x29E0($s0)
    /* 3F504 8004ED04 00000000 */  nop
    /* 3F508 8004ED08 00084228 */  slti       $v0, $v0, 0x800
    /* 3F50C 8004ED0C 0D004010 */  beqz       $v0, .L8004ED44
    /* 3F510 8004ED10 02000424 */   addiu     $a0, $zero, 0x2
    /* 3F514 8004ED14 A164010C */  jal        func_80059284
    /* 3F518 8004ED18 03000524 */   addiu     $a1, $zero, 0x3
    /* 3F51C 8004ED1C E029028E */  lw         $v0, 0x29E0($s0)
    /* 3F520 8004ED20 E829038E */  lw         $v1, 0x29E8($s0)
    /* 3F524 8004ED24 40004224 */  addiu      $v0, $v0, 0x40
    /* 3F528 8004ED28 E02902AE */  sw         $v0, 0x29E0($s0)
    /* 3F52C 8004ED2C E429028E */  lw         $v0, 0x29E4($s0)
    /* 3F530 8004ED30 40006324 */  addiu      $v1, $v1, 0x40
    /* 3F534 8004ED34 E82903AE */  sw         $v1, 0x29E8($s0)
    /* 3F538 8004ED38 40004224 */  addiu      $v0, $v0, 0x40
    /* 3F53C 8004ED3C 833F0108 */  j          .L8004FE0C
    /* 3F540 8004ED40 E42902AE */   sw        $v0, 0x29E4($s0)
  .L8004ED44:
    /* 3F544 8004ED44 C27E010C */  jal        func_8005FB08
    /* 3F548 8004ED48 00000000 */   nop
    /* 3F54C 8004ED4C 2F044010 */  beqz       $v0, .L8004FE0C
    /* 3F550 8004ED50 00000000 */   nop
    /* 3F554 8004ED54 AF67010C */  jal        func_80059EBC
    /* 3F558 8004ED58 21200000 */   addu      $a0, $zero, $zero
    /* 3F55C 8004ED5C 627D010C */  jal        func_8005F588
    /* 3F560 8004ED60 01000424 */   addiu     $a0, $zero, 0x1
    /* 3F564 8004ED64 21200000 */  addu       $a0, $zero, $zero
    /* 3F568 8004ED68 21288000 */  addu       $a1, $a0, $zero
    /* 3F56C 8004ED6C 21308000 */  addu       $a2, $a0, $zero
    /* 3F570 8004ED70 727D010C */  jal        func_8005F5C8
    /* 3F574 8004ED74 F4FF0724 */   addiu     $a3, $zero, -0xC
    /* 3F578 8004ED78 21200000 */  addu       $a0, $zero, $zero
    /* 3F57C 8004ED7C 21288000 */  addu       $a1, $a0, $zero
    /* 3F580 8004ED80 C57D010C */  jal        func_8005F714
    /* 3F584 8004ED84 00400624 */   addiu     $a2, $zero, 0x4000
    /* 3F588 8004ED88 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3F58C 8004ED8C 823F0108 */  j          .L8004FE08
    /* 3F590 8004ED90 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004ED94
    /* 3F594 8004ED94 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 3F598 8004ED98 402C5024 */  addiu      $s0, $v0, %lo(D_800F2C40)
    /* 3F59C 8004ED9C 1F0E0292 */  lbu        $v0, 0xE1F($s0)
    /* 3F5A0 8004EDA0 00000000 */  nop
    /* 3F5A4 8004EDA4 19044010 */  beqz       $v0, .L8004FE0C
    /* 3F5A8 8004EDA8 00000000 */   nop
    /* 3F5AC 8004EDAC C57E010C */  jal        func_8005FB14
    /* 3F5B0 8004EDB0 00000000 */   nop
    /* 3F5B4 8004EDB4 15044010 */  beqz       $v0, .L8004FE0C
    /* 3F5B8 8004EDB8 00000000 */   nop
    /* 3F5BC 8004EDBC 06004384 */  lh         $v1, 0x6($v0)
    /* 3F5C0 8004EDC0 02000224 */  addiu      $v0, $zero, 0x2
    /* 3F5C4 8004EDC4 11046214 */  bne        $v1, $v0, .L8004FE0C
    /* 3F5C8 8004EDC8 00000000 */   nop
    /* 3F5CC 8004EDCC 627D010C */  jal        func_8005F588
    /* 3F5D0 8004EDD0 01000424 */   addiu     $a0, $zero, 0x1
    /* 3F5D4 8004EDD4 21200000 */  addu       $a0, $zero, $zero
    /* 3F5D8 8004EDD8 21288000 */  addu       $a1, $a0, $zero
    /* 3F5DC 8004EDDC 21308000 */  addu       $a2, $a0, $zero
    /* 3F5E0 8004EDE0 727D010C */  jal        func_8005F5C8
    /* 3F5E4 8004EDE4 F4FF0724 */   addiu     $a3, $zero, -0xC
    /* 3F5E8 8004EDE8 21200000 */  addu       $a0, $zero, $zero
    /* 3F5EC 8004EDEC 21288000 */  addu       $a1, $a0, $zero
    /* 3F5F0 8004EDF0 C57D010C */  jal        func_8005F714
    /* 3F5F4 8004EDF4 00400624 */   addiu     $a2, $zero, 0x4000
    /* 3F5F8 8004EDF8 EC0D048E */  lw         $a0, 0xDEC($s0)
    /* 3F5FC 8004EDFC 1800A28F */  lw         $v0, 0x18($sp)
    /* 3F600 8004EE00 980080A3 */  sb         $zero, %gp_rel(D_8009AFA0)($gp)
    /* 3F604 8004EE04 09F84000 */  jalr       $v0
    /* 3F608 8004EE08 21280000 */   addu      $a1, $zero, $zero
    /* 3F60C 8004EE0C 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3F610 8004EE10 150E00A2 */  sb         $zero, 0xE15($s0)
    /* 3F614 8004EE14 823F0108 */  j          .L8004FE08
    /* 3F618 8004EE18 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004EE1C
    /* 3F61C 8004EE1C 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 3F620 8004EE20 402C5024 */  addiu      $s0, $v0, %lo(D_800F2C40)
    /* 3F624 8004EE24 150E0292 */  lbu        $v0, 0xE15($s0)
    /* 3F628 8004EE28 00000000 */  nop
    /* 3F62C 8004EE2C 0D004014 */  bnez       $v0, .L8004EE64
    /* 3F630 8004EE30 00000000 */   nop
    /* 3F634 8004EE34 EC0D048E */  lw         $a0, 0xDEC($s0)
    /* 3F638 8004EE38 1800A28F */  lw         $v0, 0x18($sp)
    /* 3F63C 8004EE3C 980080A3 */  sb         $zero, %gp_rel(D_8009AFA0)($gp)
    /* 3F640 8004EE40 09F84000 */  jalr       $v0
    /* 3F644 8004EE44 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 3F648 8004EE48 02000324 */  addiu      $v1, $zero, 0x2
    /* 3F64C 8004EE4C EF034314 */  bne        $v0, $v1, .L8004FE0C
    /* 3F650 8004EE50 00000000 */   nop
    /* 3F654 8004EE54 150E0292 */  lbu        $v0, 0xE15($s0)
    /* 3F658 8004EE58 00000000 */  nop
    /* 3F65C 8004EE5C 01004224 */  addiu      $v0, $v0, 0x1
    /* 3F660 8004EE60 150E02A2 */  sb         $v0, 0xE15($s0)
  .L8004EE64:
    /* 3F664 8004EE64 C00D0282 */  lb         $v0, 0xDC0($s0)
    /* 3F668 8004EE68 C00D0392 */  lbu        $v1, 0xDC0($s0)
    /* 3F66C 8004EE6C 07004004 */  bltz       $v0, .L8004EE8C
    /* 3F670 8004EE70 02006224 */   addiu     $v0, $v1, 0x2
    /* 3F674 8004EE74 C00D02A2 */  sb         $v0, 0xDC0($s0)
    /* 3F678 8004EE78 C10D0292 */  lbu        $v0, 0xDC1($s0)
    /* 3F67C 8004EE7C C20D0392 */  lbu        $v1, 0xDC2($s0)
    /* 3F680 8004EE80 02004224 */  addiu      $v0, $v0, 0x2
    /* 3F684 8004EE84 1E3E0108 */  j          .L8004F878
    /* 3F688 8004EE88 02006324 */   addiu     $v1, $v1, 0x2
  .L8004EE8C:
    /* 3F68C 8004EE8C 110E0392 */  lbu        $v1, 0xE11($s0)
    /* 3F690 8004EE90 04000224 */  addiu      $v0, $zero, 0x4
    /* 3F694 8004EE94 03006210 */  beq        $v1, $v0, .L8004EEA4
    /* 3F698 8004EE98 21200000 */   addu      $a0, $zero, $zero
    /* 3F69C 8004EE9C A164010C */  jal        func_80059284
    /* 3F6A0 8004EEA0 03000524 */   addiu     $a1, $zero, 0x3
  .L8004EEA4:
    /* 3F6A4 8004EEA4 21200000 */  addu       $a0, $zero, $zero
    /* 3F6A8 8004EEA8 21288000 */  addu       $a1, $a0, $zero
    /* 3F6AC 8004EEAC 80000624 */  addiu      $a2, $zero, 0x80
    /* 3F6B0 8004EEB0 2138C000 */  addu       $a3, $a2, $zero
    /* 3F6B4 8004EEB4 2180C000 */  addu       $s0, $a2, $zero
    /* 3F6B8 8004EEB8 6465010C */  jal        func_80059590
    /* 3F6BC 8004EEBC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3F6C0 8004EEC0 01000424 */  addiu      $a0, $zero, 0x1
    /* 3F6C4 8004EEC4 21280000 */  addu       $a1, $zero, $zero
    /* 3F6C8 8004EEC8 80000624 */  addiu      $a2, $zero, 0x80
    /* 3F6CC 8004EECC 2138C000 */  addu       $a3, $a2, $zero
    /* 3F6D0 8004EED0 6465010C */  jal        func_80059590
    /* 3F6D4 8004EED4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 3F6D8 8004EED8 21200000 */  addu       $a0, $zero, $zero
    /* 3F6DC 8004EEDC 02000524 */  addiu      $a1, $zero, 0x2
    /* 3F6E0 8004EEE0 BD5E010C */  jal        func_80057AF4
    /* 3F6E4 8004EEE4 01000624 */   addiu     $a2, $zero, 0x1
    /* 3F6E8 8004EEE8 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3F6EC 8004EEEC E10080A3 */  sb         $zero, %gp_rel(D_8009AFE9)($gp)
    /* 3F6F0 8004EEF0 823F0108 */  j          .L8004FE08
    /* 3F6F4 8004EEF4 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004EEF8
    /* 3F6F8 8004EEF8 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 3F6FC 8004EEFC 402C5024 */  addiu      $s0, $v0, %lo(D_800F2C40)
    /* 3F700 8004EF00 110E0392 */  lbu        $v1, 0xE11($s0)
    /* 3F704 8004EF04 04000224 */  addiu      $v0, $zero, 0x4
    /* 3F708 8004EF08 03006210 */  beq        $v1, $v0, .L8004EF18
    /* 3F70C 8004EF0C 21200000 */   addu      $a0, $zero, $zero
    /* 3F710 8004EF10 A164010C */  jal        func_80059284
    /* 3F714 8004EF14 03000524 */   addiu     $a1, $zero, 0x3
  .L8004EF18:
    /* 3F718 8004EF18 0F0E0292 */  lbu        $v0, 0xE0F($s0)
    /* 3F71C 8004EF1C 00000000 */  nop
    /* 3F720 8004EF20 BA034014 */  bnez       $v0, .L8004FE0C
    /* 3F724 8004EF24 00000000 */   nop
    /* 3F728 8004EF28 8763010C */  jal        func_80058E1C
    /* 3F72C 8004EF2C 00000000 */   nop
    /* 3F730 8004EF30 E1008393 */  lbu        $v1, %gp_rel(D_8009AFE9)($gp)
    /* 3F734 8004EF34 00000000 */  nop
    /* 3F738 8004EF38 21186200 */  addu       $v1, $v1, $v0
    /* 3F73C 8004EF3C E10083A3 */  sb         $v1, %gp_rel(D_8009AFE9)($gp)
    /* 3F740 8004EF40 FF006330 */  andi       $v1, $v1, 0xFF
    /* 3F744 8004EF44 3C00632C */  sltiu      $v1, $v1, 0x3C
    /* 3F748 8004EF48 B0036014 */  bnez       $v1, .L8004FE0C
    /* 3F74C 8004EF4C 00000000 */   nop
    /* 3F750 8004EF50 3F1C0292 */  lbu        $v0, 0x1C3F($s0)
    /* 3F754 8004EF54 00000000 */  nop
    /* 3F758 8004EF58 AC034010 */  beqz       $v0, .L8004FE0C
    /* 3F75C 8004EF5C 00000000 */   nop
    /* 3F760 8004EF60 627D010C */  jal        func_8005F588
    /* 3F764 8004EF64 01000424 */   addiu     $a0, $zero, 0x1
    /* 3F768 8004EF68 01000424 */  addiu      $a0, $zero, 0x1
    /* 3F76C 8004EF6C 21280000 */  addu       $a1, $zero, $zero
    /* 3F770 8004EF70 2130A000 */  addu       $a2, $a1, $zero
    /* 3F774 8004EF74 727D010C */  jal        func_8005F5C8
    /* 3F778 8004EF78 F6FF0724 */   addiu     $a3, $zero, -0xA
    /* 3F77C 8004EF7C 01000424 */  addiu      $a0, $zero, 0x1
    /* 3F780 8004EF80 21288000 */  addu       $a1, $a0, $zero
    /* 3F784 8004EF84 C57D010C */  jal        func_8005F714
    /* 3F788 8004EF88 00400624 */   addiu     $a2, $zero, 0x4000
    /* 3F78C 8004EF8C 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3F790 8004EF90 823F0108 */  j          .L8004FE08
    /* 3F794 8004EF94 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004EF98
    /* 3F798 8004EF98 0F80023C */  lui        $v0, %hi(D_800F3A51)
    /* 3F79C 8004EF9C 513A4390 */  lbu        $v1, %lo(D_800F3A51)($v0)
    /* 3F7A0 8004EFA0 04000224 */  addiu      $v0, $zero, 0x4
    /* 3F7A4 8004EFA4 03006210 */  beq        $v1, $v0, .L8004EFB4
    /* 3F7A8 8004EFA8 21200000 */   addu      $a0, $zero, $zero
    /* 3F7AC 8004EFAC A164010C */  jal        func_80059284
    /* 3F7B0 8004EFB0 03000524 */   addiu     $a1, $zero, 0x3
  .L8004EFB4:
    /* 3F7B4 8004EFB4 C57E010C */  jal        func_8005FB14
    /* 3F7B8 8004EFB8 00000000 */   nop
    /* 3F7BC 8004EFBC 93034010 */  beqz       $v0, .L8004FE0C
    /* 3F7C0 8004EFC0 00000000 */   nop
    /* 3F7C4 8004EFC4 06004384 */  lh         $v1, 0x6($v0)
    /* 3F7C8 8004EFC8 02000224 */  addiu      $v0, $zero, 0x2
    /* 3F7CC 8004EFCC 8F036214 */  bne        $v1, $v0, .L8004FE0C
    /* 3F7D0 8004EFD0 01000424 */   addiu     $a0, $zero, 0x1
    /* 3F7D4 8004EFD4 21280000 */  addu       $a1, $zero, $zero
    /* 3F7D8 8004EFD8 9F7C010C */  jal        func_8005F27C
    /* 3F7DC 8004EFDC 2130A000 */   addu      $a2, $a1, $zero
    /* 3F7E0 8004EFE0 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3F7E4 8004EFE4 823F0108 */  j          .L8004FE08
    /* 3F7E8 8004EFE8 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004EFEC
    /* 3F7EC 8004EFEC 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 3F7F0 8004EFF0 402C4424 */  addiu      $a0, $v0, %lo(D_800F2C40)
    /* 3F7F4 8004EFF4 E01B8280 */  lb         $v0, 0x1BE0($a0)
    /* 3F7F8 8004EFF8 E01B8390 */  lbu        $v1, 0x1BE0($a0)
    /* 3F7FC 8004EFFC 08004004 */  bltz       $v0, .L8004F020
    /* 3F800 8004F000 02000524 */   addiu     $a1, $zero, 0x2
    /* 3F804 8004F004 02006224 */  addiu      $v0, $v1, 0x2
    /* 3F808 8004F008 E01B82A0 */  sb         $v0, 0x1BE0($a0)
    /* 3F80C 8004F00C E11B8290 */  lbu        $v0, 0x1BE1($a0)
    /* 3F810 8004F010 E21B8390 */  lbu        $v1, 0x1BE2($a0)
    /* 3F814 8004F014 02004224 */  addiu      $v0, $v0, 0x2
    /* 3F818 8004F018 253F0108 */  j          .L8004FC94
    /* 3F81C 8004F01C 02006324 */   addiu     $v1, $v1, 0x2
  .L8004F020:
    /* 3F820 8004F020 01000424 */  addiu      $a0, $zero, 0x1
    /* 3F824 8004F024 BD5E010C */  jal        func_80057AF4
    /* 3F828 8004F028 21308000 */   addu      $a2, $a0, $zero
    /* 3F82C 8004F02C 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3F830 8004F030 E10080A3 */  sb         $zero, %gp_rel(D_8009AFE9)($gp)
    /* 3F834 8004F034 823F0108 */  j          .L8004FE08
    /* 3F838 8004F038 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004F03C
    /* 3F83C 8004F03C 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 3F840 8004F040 402C5024 */  addiu      $s0, $v0, %lo(D_800F2C40)
    /* 3F844 8004F044 2F1C0292 */  lbu        $v0, 0x1C2F($s0)
    /* 3F848 8004F048 00000000 */  nop
    /* 3F84C 8004F04C 6F034014 */  bnez       $v0, .L8004FE0C
    /* 3F850 8004F050 00000000 */   nop
    /* 3F854 8004F054 8763010C */  jal        func_80058E1C
    /* 3F858 8004F058 00000000 */   nop
    /* 3F85C 8004F05C E1008393 */  lbu        $v1, %gp_rel(D_8009AFE9)($gp)
    /* 3F860 8004F060 00000000 */  nop
    /* 3F864 8004F064 21186200 */  addu       $v1, $v1, $v0
    /* 3F868 8004F068 E10083A3 */  sb         $v1, %gp_rel(D_8009AFE9)($gp)
    /* 3F86C 8004F06C FF006330 */  andi       $v1, $v1, 0xFF
    /* 3F870 8004F070 3C00632C */  sltiu      $v1, $v1, 0x3C
    /* 3F874 8004F074 65036014 */  bnez       $v1, .L8004FE0C
    /* 3F878 8004F078 00000000 */   nop
    /* 3F87C 8004F07C FE0D0292 */  lbu        $v0, 0xDFE($s0)
    /* 3F880 8004F080 00000000 */  nop
    /* 3F884 8004F084 21105000 */  addu       $v0, $v0, $s0
    /* 3F888 8004F088 020D4290 */  lbu        $v0, 0xD02($v0)
    /* 3F88C 8004F08C 00000000 */  nop
    /* 3F890 8004F090 1F004530 */  andi       $a1, $v0, 0x1F
    /* 3F894 8004F094 01000224 */  addiu      $v0, $zero, 0x1
    /* 3F898 8004F098 0A00A210 */  beq        $a1, $v0, .L8004F0C4
    /* 3F89C 8004F09C ECFF0724 */   addiu     $a3, $zero, -0x14
    /* 3F8A0 8004F0A0 0200A228 */  slti       $v0, $a1, 0x2
    /* 3F8A4 8004F0A4 0D004014 */  bnez       $v0, .L8004F0DC
    /* 3F8A8 8004F0A8 02000224 */   addiu     $v0, $zero, 0x2
    /* 3F8AC 8004F0AC 0700A210 */  beq        $a1, $v0, .L8004F0CC
    /* 3F8B0 8004F0B0 03000224 */   addiu     $v0, $zero, 0x3
    /* 3F8B4 8004F0B4 0700A210 */  beq        $a1, $v0, .L8004F0D4
    /* 3F8B8 8004F0B8 03000524 */   addiu     $a1, $zero, 0x3
    /* 3F8BC 8004F0BC 393C0108 */  j          .L8004F0E4
    /* 3F8C0 8004F0C0 0200A22C */   sltiu     $v0, $a1, 0x2
  .L8004F0C4:
    /* 3F8C4 8004F0C4 383C0108 */  j          .L8004F0E0
    /* 3F8C8 8004F0C8 21280000 */   addu      $a1, $zero, $zero
  .L8004F0CC:
    /* 3F8CC 8004F0CC 383C0108 */  j          .L8004F0E0
    /* 3F8D0 8004F0D0 01000524 */   addiu     $a1, $zero, 0x1
  .L8004F0D4:
    /* 3F8D4 8004F0D4 383C0108 */  j          .L8004F0E0
    /* 3F8D8 8004F0D8 02000524 */   addiu     $a1, $zero, 0x2
  .L8004F0DC:
    /* 3F8DC 8004F0DC 03000524 */  addiu      $a1, $zero, 0x3
  .L8004F0E0:
    /* 3F8E0 8004F0E0 0200A22C */  sltiu      $v0, $a1, 0x2
  .L8004F0E4:
    /* 3F8E4 8004F0E4 04004010 */  beqz       $v0, .L8004F0F8
    /* 3F8E8 8004F0E8 21200000 */   addu      $a0, $zero, $zero
    /* 3F8EC 8004F0EC C2170700 */  srl        $v0, $a3, 31
    /* 3F8F0 8004F0F0 2110E200 */  addu       $v0, $a3, $v0
    /* 3F8F4 8004F0F4 43380200 */  sra        $a3, $v0, 1
  .L8004F0F8:
    /* 3F8F8 8004F0F8 727D010C */  jal        func_8005F5C8
    /* 3F8FC 8004F0FC 21308000 */   addu      $a2, $a0, $zero
    /* 3F900 8004F100 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3F904 8004F104 823F0108 */  j          .L8004FE08
    /* 3F908 8004F108 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004F10C
    /* 3F90C 8004F10C C27E010C */  jal        func_8005FB08
    /* 3F910 8004F110 00000000 */   nop
    /* 3F914 8004F114 3D034010 */  beqz       $v0, .L8004FE0C
    /* 3F918 8004F118 01000424 */   addiu     $a0, $zero, 0x1
    /* 3F91C 8004F11C FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 3F920 8004F120 21300000 */  addu       $a2, $zero, $zero
    /* 3F924 8004F124 C667010C */  jal        func_80059F18
    /* 3F928 8004F128 E2FF0724 */   addiu     $a3, $zero, -0x1E
    /* 3F92C 8004F12C 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3F930 8004F130 823F0108 */  j          .L8004FE08
    /* 3F934 8004F134 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004F138
    /* 3F938 8004F138 1E6A010C */  jal        func_8005A878
    /* 3F93C 8004F13C 01000424 */   addiu     $a0, $zero, 0x1
    /* 3F940 8004F140 32034010 */  beqz       $v0, .L8004FE0C
    /* 3F944 8004F144 00000000 */   nop
    /* 3F948 8004F148 8669010C */  jal        func_8005A618
    /* 3F94C 8004F14C 21200000 */   addu      $a0, $zero, $zero
    /* 3F950 8004F150 8763010C */  jal        func_80058E1C
    /* 3F954 8004F154 21804000 */   addu      $s0, $v0, $zero
    /* 3F958 8004F158 02004224 */  addiu      $v0, $v0, 0x2
    /* 3F95C 8004F15C C0100200 */  sll        $v0, $v0, 3
    /* 3F960 8004F160 72058487 */  lh         $a0, %gp_rel(D_8009B47A)($gp)
    /* 3F964 8004F164 00000000 */  nop
    /* 3F968 8004F168 23189000 */  subu       $v1, $a0, $s0
    /* 3F96C 8004F16C 06006004 */  bltz       $v1, .L8004F188
    /* 3F970 8004F170 21284000 */   addu      $a1, $v0, $zero
    /* 3F974 8004F174 2A104300 */  slt        $v0, $v0, $v1
    /* 3F978 8004F178 07004010 */  beqz       $v0, .L8004F198
    /* 3F97C 8004F17C 00000000 */   nop
    /* 3F980 8004F180 833F0108 */  j          .L8004FE0C
    /* 3F984 8004F184 00000000 */   nop
  .L8004F188:
    /* 3F988 8004F188 23100402 */  subu       $v0, $s0, $a0
    /* 3F98C 8004F18C 2A10A200 */  slt        $v0, $a1, $v0
    /* 3F990 8004F190 1E034014 */  bnez       $v0, .L8004FE0C
    /* 3F994 8004F194 00000000 */   nop
  .L8004F198:
    /* 3F998 8004F198 C943010C */  jal        func_80050F24
    /* 3F99C 8004F19C 21200000 */   addu      $a0, $zero, $zero
    /* 3F9A0 8004F1A0 0F80103C */  lui        $s0, %hi(D_800F2C40)
    /* 3F9A4 8004F1A4 402C1026 */  addiu      $s0, $s0, %lo(D_800F2C40)
    /* 3F9A8 8004F1A8 80101200 */  sll        $v0, $s2, 2
    /* 3F9AC 8004F1AC 2110A203 */  addu       $v0, $sp, $v0
    /* 3F9B0 8004F1B0 0C1C048E */  lw         $a0, 0x1C0C($s0)
    /* 3F9B4 8004F1B4 1800428C */  lw         $v0, 0x18($v0)
    /* 3F9B8 8004F1B8 01000324 */  addiu      $v1, $zero, 0x1
    /* 3F9BC 8004F1BC 980083A3 */  sb         $v1, %gp_rel(D_8009AFA0)($gp)
    /* 3F9C0 8004F1C0 09F84000 */  jalr       $v0
    /* 3F9C4 8004F1C4 8E010524 */   addiu     $a1, $zero, 0x18E
    /* 3F9C8 8004F1C8 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3F9CC 8004F1CC FF000324 */  addiu      $v1, $zero, 0xFF
    /* 3F9D0 8004F1D0 351C03A2 */  sb         $v1, 0x1C35($s0)
    /* 3F9D4 8004F1D4 823F0108 */  j          .L8004FE08
    /* 3F9D8 8004F1D8 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004F1DC
    /* 3F9DC 8004F1DC 0F80023C */  lui        $v0, %hi(D_800F486F)
    /* 3F9E0 8004F1E0 6F484390 */  lbu        $v1, %lo(D_800F486F)($v0)
    /* 3F9E4 8004F1E4 05000224 */  addiu      $v0, $zero, 0x5
    /* 3F9E8 8004F1E8 09006210 */  beq        $v1, $v0, .L8004F210
    /* 3F9EC 8004F1EC 06000224 */   addiu     $v0, $zero, 0x6
    /* 3F9F0 8004F1F0 05006210 */  beq        $v1, $v0, .L8004F208
    /* 3F9F4 8004F1F4 08000224 */   addiu     $v0, $zero, 0x8
    /* 3F9F8 8004F1F8 06006214 */  bne        $v1, $v0, .L8004F214
    /* 3F9FC 8004F1FC 21800000 */   addu      $s0, $zero, $zero
    /* 3FA00 8004F200 853C0108 */  j          .L8004F214
    /* 3FA04 8004F204 03001024 */   addiu     $s0, $zero, 0x3
  .L8004F208:
    /* 3FA08 8004F208 853C0108 */  j          .L8004F214
    /* 3FA0C 8004F20C 02001024 */   addiu     $s0, $zero, 0x2
  .L8004F210:
    /* 3FA10 8004F210 01001024 */  addiu      $s0, $zero, 0x1
  .L8004F214:
    /* 3FA14 8004F214 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 3FA18 8004F218 402C4424 */  addiu      $a0, $v0, %lo(D_800F2C40)
    /* 3FA1C 8004F21C 351C8390 */  lbu        $v1, 0x1C35($a0)
    /* 3FA20 8004F220 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 3FA24 8004F224 06006214 */  bne        $v1, $v0, .L8004F240
    /* 3FA28 8004F228 0F80023C */   lui       $v0, %hi(D_800F2C40)
    /* 3FA2C 8004F22C 2F1C8390 */  lbu        $v1, 0x1C2F($a0)
    /* 3FA30 8004F230 08000224 */  addiu      $v0, $zero, 0x8
    /* 3FA34 8004F234 02006214 */  bne        $v1, $v0, .L8004F240
    /* 3FA38 8004F238 0F80023C */   lui       $v0, %hi(D_800F2C40)
    /* 3FA3C 8004F23C 351C80A0 */  sb         $zero, 0x1C35($a0)
  .L8004F240:
    /* 3FA40 8004F240 402C5124 */  addiu      $s1, $v0, %lo(D_800F2C40)
    /* 3FA44 8004F244 351C2292 */  lbu        $v0, 0x1C35($s1)
    /* 3FA48 8004F248 00000000 */  nop
    /* 3FA4C 8004F24C 08004014 */  bnez       $v0, .L8004F270
    /* 3FA50 8004F250 80101200 */   sll       $v0, $s2, 2
    /* 3FA54 8004F254 2110A203 */  addu       $v0, $sp, $v0
    /* 3FA58 8004F258 0C1C248E */  lw         $a0, 0x1C0C($s1)
    /* 3FA5C 8004F25C 1800428C */  lw         $v0, 0x18($v0)
    /* 3FA60 8004F260 01000324 */  addiu      $v1, $zero, 0x1
    /* 3FA64 8004F264 980083A3 */  sb         $v1, %gp_rel(D_8009AFA0)($gp)
    /* 3FA68 8004F268 09F84000 */  jalr       $v0
    /* 3FA6C 8004F26C FFFF0524 */   addiu     $a1, $zero, -0x1
  .L8004F270:
    /* 3FA70 8004F270 0E0E2392 */  lbu        $v1, 0xE0E($s1)
    /* 3FA74 8004F274 02000224 */  addiu      $v0, $zero, 0x2
    /* 3FA78 8004F278 07006214 */  bne        $v1, $v0, .L8004F298
    /* 3FA7C 8004F27C 00000000 */   nop
    /* 3FA80 8004F280 0F0E2292 */  lbu        $v0, 0xE0F($s1)
    /* 3FA84 8004F284 00000000 */  nop
    /* 3FA88 8004F288 08004014 */  bnez       $v0, .L8004F2AC
    /* 3FA8C 8004F28C 00000000 */   nop
    /* 3FA90 8004F290 AB3C0108 */  j          .L8004F2AC
    /* 3FA94 8004F294 04001024 */   addiu     $s0, $zero, 0x4
  .L8004F298:
    /* 3FA98 8004F298 5D7C010C */  jal        func_8005F174
    /* 3FA9C 8004F29C 00000000 */   nop
    /* 3FAA0 8004F2A0 02004014 */  bnez       $v0, .L8004F2AC
    /* 3FAA4 8004F2A4 00000000 */   nop
    /* 3FAA8 8004F2A8 21800000 */  addu       $s0, $zero, $zero
  .L8004F2AC:
    /* 3FAAC 8004F2AC D7020012 */  beqz       $s0, .L8004FE0C
    /* 3FAB0 8004F2B0 00000000 */   nop
    /* 3FAB4 8004F2B4 B868010C */  jal        func_8005A2E0
    /* 3FAB8 8004F2B8 01000424 */   addiu     $a0, $zero, 0x1
    /* 3FABC 8004F2BC 6210043C */  lui        $a0, (0x10624DD3 >> 16)
    /* 3FAC0 8004F2C0 D34D8434 */  ori        $a0, $a0, (0x10624DD3 & 0xFFFF)
    /* 3FAC4 8004F2C4 00190200 */  sll        $v1, $v0, 4
    /* 3FAC8 8004F2C8 23186200 */  subu       $v1, $v1, $v0
    /* 3FACC 8004F2CC 40180300 */  sll        $v1, $v1, 1
    /* 3FAD0 8004F2D0 18006400 */  mult       $v1, $a0
    /* 3FAD4 8004F2D4 C31F0300 */  sra        $v1, $v1, 31
    /* 3FAD8 8004F2D8 10400000 */  mfhi       $t0
    /* 3FADC 8004F2DC 83110800 */  sra        $v0, $t0, 6
    /* 3FAE0 8004F2E0 5D7C010C */  jal        func_8005F174
    /* 3FAE4 8004F2E4 23804300 */   subu      $s0, $v0, $v1
    /* 3FAE8 8004F2E8 02000324 */  addiu      $v1, $zero, 0x2
    /* 3FAEC 8004F2EC 04004314 */  bne        $v0, $v1, .L8004F300
    /* 3FAF0 8004F2F0 21200000 */   addu      $a0, $zero, $zero
    /* 3FAF4 8004F2F4 607C010C */  jal        func_8005F180
    /* 3FAF8 8004F2F8 01000424 */   addiu     $a0, $zero, 0x1
    /* 3FAFC 8004F2FC 21200000 */  addu       $a0, $zero, $zero
  .L8004F300:
    /* 3FB00 8004F300 21288000 */  addu       $a1, $a0, $zero
    /* 3FB04 8004F304 21308000 */  addu       $a2, $a0, $zero
    /* 3FB08 8004F308 477E010C */  jal        func_8005F91C
    /* 3FB0C 8004F30C 21388000 */   addu      $a3, $a0, $zero
    /* 3FB10 8004F310 21380002 */  addu       $a3, $s0, $zero
    /* 3FB14 8004F314 0A00E228 */  slti       $v0, $a3, 0xA
    /* 3FB18 8004F318 02004010 */  beqz       $v0, .L8004F324
    /* 3FB1C 8004F31C 01000424 */   addiu     $a0, $zero, 0x1
    /* 3FB20 8004F320 0A000724 */  addiu      $a3, $zero, 0xA
  .L8004F324:
    /* 3FB24 8004F324 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 3FB28 8004F328 C667010C */  jal        func_80059F18
    /* 3FB2C 8004F32C 21308000 */   addu      $a2, $a0, $zero
    /* 3FB30 8004F330 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3FB34 8004F334 823F0108 */  j          .L8004FE08
    /* 3FB38 8004F338 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004F33C
    /* 3FB3C 8004F33C 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 3FB40 8004F340 402C5024 */  addiu      $s0, $v0, %lo(D_800F2C40)
    /* 3FB44 8004F344 2F1C0392 */  lbu        $v1, 0x1C2F($s0)
    /* 3FB48 8004F348 06000224 */  addiu      $v0, $zero, 0x6
    /* 3FB4C 8004F34C AE026210 */  beq        $v1, $v0, .L8004FE08
    /* 3FB50 8004F350 14000224 */   addiu     $v0, $zero, 0x14
    /* 3FB54 8004F354 351C0292 */  lbu        $v0, 0x1C35($s0)
    /* 3FB58 8004F358 00000000 */  nop
    /* 3FB5C 8004F35C 08004014 */  bnez       $v0, .L8004F380
    /* 3FB60 8004F360 80101200 */   sll       $v0, $s2, 2
    /* 3FB64 8004F364 2110A203 */  addu       $v0, $sp, $v0
    /* 3FB68 8004F368 0C1C048E */  lw         $a0, 0x1C0C($s0)
    /* 3FB6C 8004F36C 1800428C */  lw         $v0, 0x18($v0)
    /* 3FB70 8004F370 01000324 */  addiu      $v1, $zero, 0x1
    /* 3FB74 8004F374 980083A3 */  sb         $v1, %gp_rel(D_8009AFA0)($gp)
    /* 3FB78 8004F378 09F84000 */  jalr       $v0
    /* 3FB7C 8004F37C FFFF0524 */   addiu     $a1, $zero, -0x1
  .L8004F380:
    /* 3FB80 8004F380 1E6A010C */  jal        func_8005A878
    /* 3FB84 8004F384 01000424 */   addiu     $a0, $zero, 0x1
    /* 3FB88 8004F388 A0024010 */  beqz       $v0, .L8004FE0C
    /* 3FB8C 8004F38C 00000000 */   nop
    /* 3FB90 8004F390 C27E010C */  jal        func_8005FB08
    /* 3FB94 8004F394 00000000 */   nop
    /* 3FB98 8004F398 9C024010 */  beqz       $v0, .L8004FE0C
    /* 3FB9C 8004F39C FFFF043C */   lui       $a0, (0xFFFF0000 >> 16)
    /* 3FBA0 8004F3A0 0C0E028E */  lw         $v0, 0xE0C($s0)
    /* 3FBA4 8004F3A4 00000000 */  nop
    /* 3FBA8 8004F3A8 24184400 */  and        $v1, $v0, $a0
    /* 3FBAC 8004F3AC 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 3FBB0 8004F3B0 96026214 */  bne        $v1, $v0, .L8004FE0C
    /* 3FBB4 8004F3B4 00000000 */   nop
    /* 3FBB8 8004F3B8 2C1C028E */  lw         $v0, 0x1C2C($s0)
    /* 3FBBC 8004F3BC 00000000 */  nop
    /* 3FBC0 8004F3C0 24104400 */  and        $v0, $v0, $a0
    /* 3FBC4 8004F3C4 91024314 */  bne        $v0, $v1, .L8004FE0C
    /* 3FBC8 8004F3C8 00000000 */   nop
    /* 3FBCC 8004F3CC 1F1C0292 */  lbu        $v0, 0x1C1F($s0)
    /* 3FBD0 8004F3D0 00000000 */  nop
    /* 3FBD4 8004F3D4 05004010 */  beqz       $v0, .L8004F3EC
    /* 3FBD8 8004F3D8 00000000 */   nop
    /* 3FBDC 8004F3DC 3768010C */  jal        func_8005A0DC
    /* 3FBE0 8004F3E0 78000424 */   addiu     $a0, $zero, 0x78
    /* 3FBE4 8004F3E4 823F0108 */  j          .L8004FE08
    /* 3FBE8 8004F3E8 1E000224 */   addiu     $v0, $zero, 0x1E
  .L8004F3EC:
    /* 3FBEC 8004F3EC 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3FBF0 8004F3F0 823F0108 */  j          .L8004FE08
    /* 3FBF4 8004F3F4 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004F3F8
    /* 3FBF8 8004F3F8 C27E010C */  jal        func_8005FB08
    /* 3FBFC 8004F3FC 00000000 */   nop
    /* 3FC00 8004F400 82024010 */  beqz       $v0, .L8004FE0C
    /* 3FC04 8004F404 01000424 */   addiu     $a0, $zero, 0x1
    /* 3FC08 8004F408 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 3FC0C 8004F40C 21308000 */  addu       $a2, $a0, $zero
    /* 3FC10 8004F410 C667010C */  jal        func_80059F18
    /* 3FC14 8004F414 E2FF0724 */   addiu     $a3, $zero, -0x1E
    /* 3FC18 8004F418 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3FC1C 8004F41C 823F0108 */  j          .L8004FE08
    /* 3FC20 8004F420 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004F424
    /* 3FC24 8004F424 1E6A010C */  jal        func_8005A878
    /* 3FC28 8004F428 01000424 */   addiu     $a0, $zero, 0x1
    /* 3FC2C 8004F42C 77024010 */  beqz       $v0, .L8004FE0C
    /* 3FC30 8004F430 00000000 */   nop
    /* 3FC34 8004F434 8669010C */  jal        func_8005A618
    /* 3FC38 8004F438 01000424 */   addiu     $a0, $zero, 0x1
    /* 3FC3C 8004F43C 8763010C */  jal        func_80058E1C
    /* 3FC40 8004F440 21804000 */   addu      $s0, $v0, $zero
    /* 3FC44 8004F444 02004224 */  addiu      $v0, $v0, 0x2
    /* 3FC48 8004F448 C0100200 */  sll        $v0, $v0, 3
    /* 3FC4C 8004F44C 72058487 */  lh         $a0, %gp_rel(D_8009B47A)($gp)
    /* 3FC50 8004F450 00000000 */  nop
    /* 3FC54 8004F454 23189000 */  subu       $v1, $a0, $s0
    /* 3FC58 8004F458 06006004 */  bltz       $v1, .L8004F474
    /* 3FC5C 8004F45C 21284000 */   addu      $a1, $v0, $zero
    /* 3FC60 8004F460 2A104300 */  slt        $v0, $v0, $v1
    /* 3FC64 8004F464 07004010 */  beqz       $v0, .L8004F484
    /* 3FC68 8004F468 00000000 */   nop
    /* 3FC6C 8004F46C 833F0108 */  j          .L8004FE0C
    /* 3FC70 8004F470 00000000 */   nop
  .L8004F474:
    /* 3FC74 8004F474 23100402 */  subu       $v0, $s0, $a0
    /* 3FC78 8004F478 2A10A200 */  slt        $v0, $a1, $v0
    /* 3FC7C 8004F47C 63024014 */  bnez       $v0, .L8004FE0C
    /* 3FC80 8004F480 00000000 */   nop
  .L8004F484:
    /* 3FC84 8004F484 C943010C */  jal        func_80050F24
    /* 3FC88 8004F488 01000424 */   addiu     $a0, $zero, 0x1
    /* 3FC8C 8004F48C 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3FC90 8004F490 823F0108 */  j          .L8004FE08
    /* 3FC94 8004F494 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004F498
    /* 3FC98 8004F498 0F80023C */  lui        $v0, %hi(D_800F3A4F)
    /* 3FC9C 8004F49C 4F3A4390 */  lbu        $v1, %lo(D_800F3A4F)($v0)
    /* 3FCA0 8004F4A0 05000224 */  addiu      $v0, $zero, 0x5
    /* 3FCA4 8004F4A4 09006210 */  beq        $v1, $v0, .L8004F4CC
    /* 3FCA8 8004F4A8 06000224 */   addiu     $v0, $zero, 0x6
    /* 3FCAC 8004F4AC 05006210 */  beq        $v1, $v0, .L8004F4C4
    /* 3FCB0 8004F4B0 08000224 */   addiu     $v0, $zero, 0x8
    /* 3FCB4 8004F4B4 06006214 */  bne        $v1, $v0, .L8004F4D0
    /* 3FCB8 8004F4B8 21800000 */   addu      $s0, $zero, $zero
    /* 3FCBC 8004F4BC 343D0108 */  j          .L8004F4D0
    /* 3FCC0 8004F4C0 03001024 */   addiu     $s0, $zero, 0x3
  .L8004F4C4:
    /* 3FCC4 8004F4C4 343D0108 */  j          .L8004F4D0
    /* 3FCC8 8004F4C8 02001024 */   addiu     $s0, $zero, 0x2
  .L8004F4CC:
    /* 3FCCC 8004F4CC 01001024 */  addiu      $s0, $zero, 0x1
  .L8004F4D0:
    /* 3FCD0 8004F4D0 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 3FCD4 8004F4D4 402C4424 */  addiu      $a0, $v0, %lo(D_800F2C40)
    /* 3FCD8 8004F4D8 2E1C8390 */  lbu        $v1, 0x1C2E($a0)
    /* 3FCDC 8004F4DC 02000224 */  addiu      $v0, $zero, 0x2
    /* 3FCE0 8004F4E0 07006214 */  bne        $v1, $v0, .L8004F500
    /* 3FCE4 8004F4E4 00000000 */   nop
    /* 3FCE8 8004F4E8 2F1C8290 */  lbu        $v0, 0x1C2F($a0)
    /* 3FCEC 8004F4EC 00000000 */  nop
    /* 3FCF0 8004F4F0 08004014 */  bnez       $v0, .L8004F514
    /* 3FCF4 8004F4F4 00000000 */   nop
    /* 3FCF8 8004F4F8 453D0108 */  j          .L8004F514
    /* 3FCFC 8004F4FC 04001024 */   addiu     $s0, $zero, 0x4
  .L8004F500:
    /* 3FD00 8004F500 5D7C010C */  jal        func_8005F174
    /* 3FD04 8004F504 00000000 */   nop
    /* 3FD08 8004F508 02004014 */  bnez       $v0, .L8004F514
    /* 3FD0C 8004F50C 00000000 */   nop
    /* 3FD10 8004F510 21800000 */  addu       $s0, $zero, $zero
  .L8004F514:
    /* 3FD14 8004F514 3D020012 */  beqz       $s0, .L8004FE0C
    /* 3FD18 8004F518 00000000 */   nop
    /* 3FD1C 8004F51C B868010C */  jal        func_8005A2E0
    /* 3FD20 8004F520 21200000 */   addu      $a0, $zero, $zero
    /* 3FD24 8004F524 6210043C */  lui        $a0, (0x10624DD3 >> 16)
    /* 3FD28 8004F528 D34D8434 */  ori        $a0, $a0, (0x10624DD3 & 0xFFFF)
    /* 3FD2C 8004F52C 00190200 */  sll        $v1, $v0, 4
    /* 3FD30 8004F530 23186200 */  subu       $v1, $v1, $v0
    /* 3FD34 8004F534 40180300 */  sll        $v1, $v1, 1
    /* 3FD38 8004F538 18006400 */  mult       $v1, $a0
    /* 3FD3C 8004F53C C31F0300 */  sra        $v1, $v1, 31
    /* 3FD40 8004F540 10400000 */  mfhi       $t0
    /* 3FD44 8004F544 83110800 */  sra        $v0, $t0, 6
    /* 3FD48 8004F548 5D7C010C */  jal        func_8005F174
    /* 3FD4C 8004F54C 23804300 */   subu      $s0, $v0, $v1
    /* 3FD50 8004F550 02000324 */  addiu      $v1, $zero, 0x2
    /* 3FD54 8004F554 04004314 */  bne        $v0, $v1, .L8004F568
    /* 3FD58 8004F558 21200000 */   addu      $a0, $zero, $zero
    /* 3FD5C 8004F55C 607C010C */  jal        func_8005F180
    /* 3FD60 8004F560 01000424 */   addiu     $a0, $zero, 0x1
    /* 3FD64 8004F564 21200000 */  addu       $a0, $zero, $zero
  .L8004F568:
    /* 3FD68 8004F568 21288000 */  addu       $a1, $a0, $zero
    /* 3FD6C 8004F56C 21308000 */  addu       $a2, $a0, $zero
    /* 3FD70 8004F570 477E010C */  jal        func_8005F91C
    /* 3FD74 8004F574 21388000 */   addu      $a3, $a0, $zero
    /* 3FD78 8004F578 21380002 */  addu       $a3, $s0, $zero
    /* 3FD7C 8004F57C 0A00E228 */  slti       $v0, $a3, 0xA
    /* 3FD80 8004F580 02004010 */  beqz       $v0, .L8004F58C
    /* 3FD84 8004F584 01000424 */   addiu     $a0, $zero, 0x1
    /* 3FD88 8004F588 0A000724 */  addiu      $a3, $zero, 0xA
  .L8004F58C:
    /* 3FD8C 8004F58C FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 3FD90 8004F590 C667010C */  jal        func_80059F18
    /* 3FD94 8004F594 21300000 */   addu      $a2, $zero, $zero
    /* 3FD98 8004F598 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3FD9C 8004F59C 823F0108 */  j          .L8004FE08
    /* 3FDA0 8004F5A0 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004F5A4
    /* 3FDA4 8004F5A4 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 3FDA8 8004F5A8 402C5024 */  addiu      $s0, $v0, %lo(D_800F2C40)
    /* 3FDAC 8004F5AC 0F0E0392 */  lbu        $v1, 0xE0F($s0)
    /* 3FDB0 8004F5B0 06000224 */  addiu      $v0, $zero, 0x6
    /* 3FDB4 8004F5B4 14026210 */  beq        $v1, $v0, .L8004FE08
    /* 3FDB8 8004F5B8 14000224 */   addiu     $v0, $zero, 0x14
    /* 3FDBC 8004F5BC 1E6A010C */  jal        func_8005A878
    /* 3FDC0 8004F5C0 01000424 */   addiu     $a0, $zero, 0x1
    /* 3FDC4 8004F5C4 11024010 */  beqz       $v0, .L8004FE0C
    /* 3FDC8 8004F5C8 00000000 */   nop
    /* 3FDCC 8004F5CC C27E010C */  jal        func_8005FB08
    /* 3FDD0 8004F5D0 00000000 */   nop
    /* 3FDD4 8004F5D4 0D024010 */  beqz       $v0, .L8004FE0C
    /* 3FDD8 8004F5D8 FFFF043C */   lui       $a0, (0xFFFF0000 >> 16)
    /* 3FDDC 8004F5DC 0C0E028E */  lw         $v0, 0xE0C($s0)
    /* 3FDE0 8004F5E0 00000000 */  nop
    /* 3FDE4 8004F5E4 24184400 */  and        $v1, $v0, $a0
    /* 3FDE8 8004F5E8 0200023C */  lui        $v0, (0x20000 >> 16)
    /* 3FDEC 8004F5EC 07026214 */  bne        $v1, $v0, .L8004FE0C
    /* 3FDF0 8004F5F0 00000000 */   nop
    /* 3FDF4 8004F5F4 2C1C028E */  lw         $v0, 0x1C2C($s0)
    /* 3FDF8 8004F5F8 00000000 */  nop
    /* 3FDFC 8004F5FC 24104400 */  and        $v0, $v0, $a0
    /* 3FE00 8004F600 02024314 */  bne        $v0, $v1, .L8004FE0C
    /* 3FE04 8004F604 0A80043C */   lui       $a0, %hi(D_8009AFF4)
    /* 3FE08 8004F608 E1FB010C */  jal        func_8007EF84
    /* 3FE0C 8004F60C F4AF8424 */   addiu     $a0, $a0, %lo(D_8009AFF4)
    /* 3FE10 8004F610 833F0108 */  j          .L8004FE0C
    /* 3FE14 8004F614 00000000 */   nop
  jlabel .L8004F618
    /* 3FE18 8004F618 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 3FE1C 8004F61C 402C4524 */  addiu      $a1, $v0, %lo(D_800F2C40)
    /* 3FE20 8004F620 0F0EA290 */  lbu        $v0, 0xE0F($a1)
    /* 3FE24 8004F624 00000000 */  nop
    /* 3FE28 8004F628 06004238 */  xori       $v0, $v0, 0x6
    /* 3FE2C 8004F62C 2B800200 */  sltu       $s0, $zero, $v0
    /* 3FE30 8004F630 0100033A */  xori       $v1, $s0, 0x1
    /* 3FE34 8004F634 C0100300 */  sll        $v0, $v1, 3
    /* 3FE38 8004F638 23104300 */  subu       $v0, $v0, $v1
    /* 3FE3C 8004F63C 00110200 */  sll        $v0, $v0, 4
    /* 3FE40 8004F640 21104300 */  addu       $v0, $v0, $v1
    /* 3FE44 8004F644 40110200 */  sll        $v0, $v0, 5
    /* 3FE48 8004F648 21204500 */  addu       $a0, $v0, $a1
    /* 3FE4C 8004F64C 0E0E8390 */  lbu        $v1, 0xE0E($a0)
    /* 3FE50 8004F650 02000224 */  addiu      $v0, $zero, 0x2
    /* 3FE54 8004F654 ED016214 */  bne        $v1, $v0, .L8004FE0C
    /* 3FE58 8004F658 00000000 */   nop
    /* 3FE5C 8004F65C 0F0E8290 */  lbu        $v0, 0xE0F($a0)
    /* 3FE60 8004F660 00000000 */  nop
    /* 3FE64 8004F664 E9014014 */  bnez       $v0, .L8004FE0C
    /* 3FE68 8004F668 C0101000 */   sll       $v0, $s0, 3
    /* 3FE6C 8004F66C 23105000 */  subu       $v0, $v0, $s0
    /* 3FE70 8004F670 00110200 */  sll        $v0, $v0, 4
    /* 3FE74 8004F674 21105000 */  addu       $v0, $v0, $s0
    /* 3FE78 8004F678 40110200 */  sll        $v0, $v0, 5
    /* 3FE7C 8004F67C 21104500 */  addu       $v0, $v0, $a1
    /* 3FE80 8004F680 160E4390 */  lbu        $v1, 0xE16($v0)
    /* 3FE84 8004F684 23000224 */  addiu      $v0, $zero, 0x23
    /* 3FE88 8004F688 E0016214 */  bne        $v1, $v0, .L8004FE0C
    /* 3FE8C 8004F68C 00000000 */   nop
    /* 3FE90 8004F690 1F1CA290 */  lbu        $v0, 0x1C1F($a1)
    /* 3FE94 8004F694 00000000 */  nop
    /* 3FE98 8004F698 0F004014 */  bnez       $v0, .L8004F6D8
    /* 3FE9C 8004F69C 00000000 */   nop
    /* 3FEA0 8004F6A0 F80CA394 */  lhu        $v1, 0xCF8($a1)
    /* 3FEA4 8004F6A4 181BA294 */  lhu        $v0, 0x1B18($a1)
    /* 3FEA8 8004F6A8 00000000 */  nop
    /* 3FEAC 8004F6AC 0A006214 */  bne        $v1, $v0, .L8004F6D8
    /* 3FEB0 8004F6B0 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 3FEB4 8004F6B4 331CA390 */  lbu        $v1, 0x1C33($a1)
    /* 3FEB8 8004F6B8 00000000 */  nop
    /* 3FEBC 8004F6BC 02006214 */  bne        $v1, $v0, .L8004F6C8
    /* 3FEC0 8004F6C0 80000224 */   addiu     $v0, $zero, 0x80
    /* 3FEC4 8004F6C4 331CA2A0 */  sb         $v0, 0x1C33($a1)
  .L8004F6C8:
    /* 3FEC8 8004F6C8 01000424 */  addiu      $a0, $zero, 0x1
    /* 3FECC 8004F6CC 06000524 */  addiu      $a1, $zero, 0x6
    /* 3FED0 8004F6D0 BD5E010C */  jal        func_80057AF4
    /* 3FED4 8004F6D4 21308000 */   addu      $a2, $a0, $zero
  .L8004F6D8:
    /* 3FED8 8004F6D8 21200000 */  addu       $a0, $zero, $zero
    /* 3FEDC 8004F6DC 21288000 */  addu       $a1, $a0, $zero
    /* 3FEE0 8004F6E0 21308000 */  addu       $a2, $a0, $zero
    /* 3FEE4 8004F6E4 477E010C */  jal        func_8005F91C
    /* 3FEE8 8004F6E8 21388000 */   addu      $a3, $a0, $zero
    /* 3FEEC 8004F6EC 1E6A010C */  jal        func_8005A878
    /* 3FEF0 8004F6F0 01000424 */   addiu     $a0, $zero, 0x1
    /* 3FEF4 8004F6F4 15004010 */  beqz       $v0, .L8004F74C
    /* 3FEF8 8004F6F8 00000000 */   nop
    /* 3FEFC 8004F6FC B868010C */  jal        func_8005A2E0
    /* 3FF00 8004F700 21200002 */   addu      $a0, $s0, $zero
    /* 3FF04 8004F704 6210043C */  lui        $a0, (0x10624DD3 >> 16)
    /* 3FF08 8004F708 D34D8434 */  ori        $a0, $a0, (0x10624DD3 & 0xFFFF)
    /* 3FF0C 8004F70C 00190200 */  sll        $v1, $v0, 4
    /* 3FF10 8004F710 23186200 */  subu       $v1, $v1, $v0
    /* 3FF14 8004F714 40180300 */  sll        $v1, $v1, 1
    /* 3FF18 8004F718 18006400 */  mult       $v1, $a0
    /* 3FF1C 8004F71C C31F0300 */  sra        $v1, $v1, 31
    /* 3FF20 8004F720 10400000 */  mfhi       $t0
    /* 3FF24 8004F724 83110800 */  sra        $v0, $t0, 6
    /* 3FF28 8004F728 23384300 */  subu       $a3, $v0, $v1
    /* 3FF2C 8004F72C 0A00E228 */  slti       $v0, $a3, 0xA
    /* 3FF30 8004F730 02004010 */  beqz       $v0, .L8004F73C
    /* 3FF34 8004F734 01000424 */   addiu     $a0, $zero, 0x1
    /* 3FF38 8004F738 0A000724 */  addiu      $a3, $zero, 0xA
  .L8004F73C:
    /* 3FF3C 8004F73C FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 3FF40 8004F740 21300002 */  addu       $a2, $s0, $zero
    /* 3FF44 8004F744 C667010C */  jal        func_80059F18
    /* 3FF48 8004F748 23380700 */   negu      $a3, $a3
  .L8004F74C:
    /* 3FF4C 8004F74C 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3FF50 8004F750 823F0108 */  j          .L8004FE08
    /* 3FF54 8004F754 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004F758
    /* 3FF58 8004F758 0F80033C */  lui        $v1, %hi(D_800F2C40)
    /* 3FF5C 8004F75C 402C6324 */  addiu      $v1, $v1, %lo(D_800F2C40)
    /* 3FF60 8004F760 0F0E6290 */  lbu        $v0, 0xE0F($v1)
    /* 3FF64 8004F764 00000000 */  nop
    /* 3FF68 8004F768 06004238 */  xori       $v0, $v0, 0x6
    /* 3FF6C 8004F76C 2B800200 */  sltu       $s0, $zero, $v0
    /* 3FF70 8004F770 C0101000 */  sll        $v0, $s0, 3
    /* 3FF74 8004F774 23105000 */  subu       $v0, $v0, $s0
    /* 3FF78 8004F778 00110200 */  sll        $v0, $v0, 4
    /* 3FF7C 8004F77C 21105000 */  addu       $v0, $v0, $s0
    /* 3FF80 8004F780 40110200 */  sll        $v0, $v0, 5
    /* 3FF84 8004F784 21884300 */  addu       $s1, $v0, $v1
    /* 3FF88 8004F788 130E2292 */  lbu        $v0, 0xE13($s1)
    /* 3FF8C 8004F78C 00000000 */  nop
    /* 3FF90 8004F790 9E014014 */  bnez       $v0, .L8004FE0C
    /* 3FF94 8004F794 00000000 */   nop
    /* 3FF98 8004F798 1E6A010C */  jal        func_8005A878
    /* 3FF9C 8004F79C 01000424 */   addiu     $a0, $zero, 0x1
    /* 3FFA0 8004F7A0 9A014010 */  beqz       $v0, .L8004FE0C
    /* 3FFA4 8004F7A4 21200002 */   addu      $a0, $s0, $zero
    /* 3FFA8 8004F7A8 05000524 */  addiu      $a1, $zero, 0x5
    /* 3FFAC 8004F7AC 80000624 */  addiu      $a2, $zero, 0x80
    /* 3FFB0 8004F7B0 2138C000 */  addu       $a3, $a2, $zero
    /* 3FFB4 8004F7B4 2110C000 */  addu       $v0, $a2, $zero
    /* 3FFB8 8004F7B8 6465010C */  jal        func_80059590
    /* 3FFBC 8004F7BC 1000A2AF */   sw        $v0, 0x10($sp)
    /* 3FFC0 8004F7C0 EC0D248E */  lw         $a0, 0xDEC($s1)
    /* 3FFC4 8004F7C4 2400A28F */  lw         $v0, 0x24($sp)
    /* 3FFC8 8004F7C8 980090A3 */  sb         $s0, %gp_rel(D_8009AFA0)($gp)
    /* 3FFCC 8004F7CC 09F84000 */  jalr       $v0
    /* 3FFD0 8004F7D0 21280000 */   addu      $a1, $zero, $zero
    /* 3FFD4 8004F7D4 150E20A2 */  sb         $zero, 0xE15($s1)
    /* 3FFD8 8004F7D8 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 3FFDC 8004F7DC 823F0108 */  j          .L8004FE08
    /* 3FFE0 8004F7E0 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004F7E4
    /* 3FFE4 8004F7E4 0F80033C */  lui        $v1, %hi(D_800F2C40)
    /* 3FFE8 8004F7E8 402C6324 */  addiu      $v1, $v1, %lo(D_800F2C40)
    /* 3FFEC 8004F7EC 0F0E6290 */  lbu        $v0, 0xE0F($v1)
    /* 3FFF0 8004F7F0 00000000 */  nop
    /* 3FFF4 8004F7F4 06004238 */  xori       $v0, $v0, 0x6
    /* 3FFF8 8004F7F8 2B880200 */  sltu       $s1, $zero, $v0
    /* 3FFFC 8004F7FC C0101100 */  sll        $v0, $s1, 3
    /* 40000 8004F800 23105100 */  subu       $v0, $v0, $s1
    /* 40004 8004F804 00110200 */  sll        $v0, $v0, 4
    /* 40008 8004F808 21105100 */  addu       $v0, $v0, $s1
    /* 4000C 8004F80C 40110200 */  sll        $v0, $v0, 5
    /* 40010 8004F810 21804300 */  addu       $s0, $v0, $v1
    /* 40014 8004F814 150E0292 */  lbu        $v0, 0xE15($s0)
    /* 40018 8004F818 00000000 */  nop
    /* 4001C 8004F81C 0D004014 */  bnez       $v0, .L8004F854
    /* 40020 8004F820 00000000 */   nop
    /* 40024 8004F824 EC0D048E */  lw         $a0, 0xDEC($s0)
    /* 40028 8004F828 2400A28F */  lw         $v0, 0x24($sp)
    /* 4002C 8004F82C 980091A3 */  sb         $s1, %gp_rel(D_8009AFA0)($gp)
    /* 40030 8004F830 09F84000 */  jalr       $v0
    /* 40034 8004F834 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 40038 8004F838 02000324 */  addiu      $v1, $zero, 0x2
    /* 4003C 8004F83C 73014314 */  bne        $v0, $v1, .L8004FE0C
    /* 40040 8004F840 00000000 */   nop
    /* 40044 8004F844 150E0292 */  lbu        $v0, 0xE15($s0)
    /* 40048 8004F848 00000000 */  nop
    /* 4004C 8004F84C 01004224 */  addiu      $v0, $v0, 0x1
    /* 40050 8004F850 150E02A2 */  sb         $v0, 0xE15($s0)
  .L8004F854:
    /* 40054 8004F854 C00D0292 */  lbu        $v0, 0xDC0($s0)
    /* 40058 8004F858 00000000 */  nop
    /* 4005C 8004F85C 09004010 */  beqz       $v0, .L8004F884
    /* 40060 8004F860 FEFF4224 */   addiu     $v0, $v0, -0x2
    /* 40064 8004F864 C00D02A2 */  sb         $v0, 0xDC0($s0)
    /* 40068 8004F868 C10D0292 */  lbu        $v0, 0xDC1($s0)
    /* 4006C 8004F86C C20D0392 */  lbu        $v1, 0xDC2($s0)
    /* 40070 8004F870 FEFF4224 */  addiu      $v0, $v0, -0x2
    /* 40074 8004F874 FEFF6324 */  addiu      $v1, $v1, -0x2
  .L8004F878:
    /* 40078 8004F878 C10D02A2 */  sb         $v0, 0xDC1($s0)
    /* 4007C 8004F87C 833F0108 */  j          .L8004FE0C
    /* 40080 8004F880 C20D03A2 */   sb        $v1, 0xDC2($s0)
  .L8004F884:
    /* 40084 8004F884 72058487 */  lh         $a0, %gp_rel(D_8009B47A)($gp)
    /* 40088 8004F888 0500201A */  blez       $s1, .L8004F8A0
    /* 4008C 8004F88C 000C8324 */   addiu     $v1, $a0, 0xC00
    /* 40090 8004F890 07006104 */  bgez       $v1, .L8004F8B0
    /* 40094 8004F894 21106000 */   addu      $v0, $v1, $zero
    /* 40098 8004F898 2C3E0108 */  j          .L8004F8B0
    /* 4009C 8004F89C FF1B8224 */   addiu     $v0, $a0, 0x1BFF
  .L8004F8A0:
    /* 400A0 8004F8A0 00048324 */  addiu      $v1, $a0, 0x400
    /* 400A4 8004F8A4 02006104 */  bgez       $v1, .L8004F8B0
    /* 400A8 8004F8A8 21106000 */   addu      $v0, $v1, $zero
    /* 400AC 8004F8AC FF138224 */  addiu      $v0, $a0, 0x13FF
  .L8004F8B0:
    /* 400B0 8004F8B0 03130200 */  sra        $v0, $v0, 12
    /* 400B4 8004F8B4 00130200 */  sll        $v0, $v0, 12
    /* 400B8 8004F8B8 23106200 */  subu       $v0, $v1, $v0
    /* 400BC 8004F8BC FFFD4224 */  addiu      $v0, $v0, -0x201
    /* 400C0 8004F8C0 FF0B422C */  sltiu      $v0, $v0, 0xBFF
    /* 400C4 8004F8C4 51014010 */  beqz       $v0, .L8004FE0C
    /* 400C8 8004F8C8 0100303A */   xori      $s0, $s1, 0x1
    /* 400CC 8004F8CC B868010C */  jal        func_8005A2E0
    /* 400D0 8004F8D0 21200002 */   addu      $a0, $s0, $zero
    /* 400D4 8004F8D4 6210043C */  lui        $a0, (0x10624DD3 >> 16)
    /* 400D8 8004F8D8 D34D8434 */  ori        $a0, $a0, (0x10624DD3 & 0xFFFF)
    /* 400DC 8004F8DC 00190200 */  sll        $v1, $v0, 4
    /* 400E0 8004F8E0 23186200 */  subu       $v1, $v1, $v0
    /* 400E4 8004F8E4 40180300 */  sll        $v1, $v1, 1
    /* 400E8 8004F8E8 18006400 */  mult       $v1, $a0
    /* 400EC 8004F8EC C31F0300 */  sra        $v1, $v1, 31
    /* 400F0 8004F8F0 10400000 */  mfhi       $t0
    /* 400F4 8004F8F4 83110800 */  sra        $v0, $t0, 6
    /* 400F8 8004F8F8 23384300 */  subu       $a3, $v0, $v1
    /* 400FC 8004F8FC 1E00E228 */  slti       $v0, $a3, 0x1E
    /* 40100 8004F900 02004010 */  beqz       $v0, .L8004F90C
    /* 40104 8004F904 01000424 */   addiu     $a0, $zero, 0x1
    /* 40108 8004F908 1E000724 */  addiu      $a3, $zero, 0x1E
  .L8004F90C:
    /* 4010C 8004F90C FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 40110 8004F910 21300002 */  addu       $a2, $s0, $zero
    /* 40114 8004F914 C667010C */  jal        func_80059F18
    /* 40118 8004F918 23380700 */   negu      $a3, $a3
    /* 4011C 8004F91C 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 40120 8004F920 823F0108 */  j          .L8004FE08
    /* 40124 8004F924 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004F928
    /* 40128 8004F928 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 4012C 8004F92C 402C5224 */  addiu      $s2, $v0, %lo(D_800F2C40)
    /* 40130 8004F930 0F0E4292 */  lbu        $v0, 0xE0F($s2)
    /* 40134 8004F934 00000000 */  nop
    /* 40138 8004F938 06004238 */  xori       $v0, $v0, 0x6
    /* 4013C 8004F93C C27E010C */  jal        func_8005FB08
    /* 40140 8004F940 0100512C */   sltiu     $s1, $v0, 0x1
    /* 40144 8004F944 31014010 */  beqz       $v0, .L8004FE0C
    /* 40148 8004F948 21202002 */   addu      $a0, $s1, $zero
    /* 4014C 8004F94C 70059087 */  lh         $s0, %gp_rel(D_8009B478)($gp)
    /* 40150 8004F950 6E7C010C */  jal        func_8005F1B8
    /* 40154 8004F954 BC020524 */   addiu     $a1, $zero, 0x2BC
    /* 40158 8004F958 0A004224 */  addiu      $v0, $v0, 0xA
    /* 4015C 8004F95C 2A105000 */  slt        $v0, $v0, $s0
    /* 40160 8004F960 2A014014 */  bnez       $v0, .L8004FE0C
    /* 40164 8004F964 00000000 */   nop
    /* 40168 8004F968 1E6A010C */  jal        func_8005A878
    /* 4016C 8004F96C 01000424 */   addiu     $a0, $zero, 0x1
    /* 40170 8004F970 26014010 */  beqz       $v0, .L8004FE0C
    /* 40174 8004F974 00000000 */   nop
    /* 40178 8004F978 F80C4396 */  lhu        $v1, 0xCF8($s2)
    /* 4017C 8004F97C 181B4296 */  lhu        $v0, 0x1B18($s2)
    /* 40180 8004F980 00000000 */  nop
    /* 40184 8004F984 11006214 */  bne        $v1, $v0, .L8004F9CC
    /* 40188 8004F988 00000000 */   nop
    /* 4018C 8004F98C 1F1C4292 */  lbu        $v0, 0x1C1F($s2)
    /* 40190 8004F990 00000000 */  nop
    /* 40194 8004F994 0E004014 */  bnez       $v0, .L8004F9D0
    /* 40198 8004F998 FFFF0424 */   addiu     $a0, $zero, -0x1
    /* 4019C 8004F99C 0C1C448E */  lw         $a0, 0x1C0C($s2)
    /* 401A0 8004F9A0 2400A28F */  lw         $v0, 0x24($sp)
    /* 401A4 8004F9A4 01000324 */  addiu      $v1, $zero, 0x1
    /* 401A8 8004F9A8 980083A3 */  sb         $v1, %gp_rel(D_8009AFA0)($gp)
    /* 401AC 8004F9AC 09F84000 */  jalr       $v0
    /* 401B0 8004F9B0 21280000 */   addu      $a1, $zero, $zero
    /* 401B4 8004F9B4 19000224 */  addiu      $v0, $zero, 0x19
    /* 401B8 8004F9B8 351C40A2 */  sb         $zero, 0x1C35($s2)
    /* 401BC 8004F9BC 920082A3 */  sb         $v0, %gp_rel(D_8009AF9A)($gp)
    /* 401C0 8004F9C0 E10080A3 */  sb         $zero, %gp_rel(D_8009AFE9)($gp)
    /* 401C4 8004F9C4 833F0108 */  j          .L8004FE0C
    /* 401C8 8004F9C8 00000000 */   nop
  .L8004F9CC:
    /* 401CC 8004F9CC FFFF0424 */  addiu      $a0, $zero, -0x1
  .L8004F9D0:
    /* 401D0 8004F9D0 21282002 */  addu       $a1, $s1, $zero
    /* 401D4 8004F9D4 C57D010C */  jal        func_8005F714
    /* 401D8 8004F9D8 00400624 */   addiu     $a2, $zero, 0x4000
    /* 401DC 8004F9DC FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 401E0 8004F9E0 0468010C */  jal        func_8005A010
    /* 401E4 8004F9E4 21282002 */   addu      $a1, $s1, $zero
    /* 401E8 8004F9E8 21202002 */  addu       $a0, $s1, $zero
    /* 401EC 8004F9EC 07000524 */  addiu      $a1, $zero, 0x7
    /* 401F0 8004F9F0 BD5E010C */  jal        func_80057AF4
    /* 401F4 8004F9F4 01000624 */   addiu     $a2, $zero, 0x1
    /* 401F8 8004F9F8 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 401FC 8004F9FC 823F0108 */  j          .L8004FE08
    /* 40200 8004FA00 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004FA04
    /* 40204 8004FA04 0F80033C */  lui        $v1, %hi(D_800F2C40)
    /* 40208 8004FA08 402C6324 */  addiu      $v1, $v1, %lo(D_800F2C40)
    /* 4020C 8004FA0C 0F0E6290 */  lbu        $v0, 0xE0F($v1)
    /* 40210 8004FA10 00000000 */  nop
    /* 40214 8004FA14 06004238 */  xori       $v0, $v0, 0x6
    /* 40218 8004FA18 0100502C */  sltiu      $s0, $v0, 0x1
    /* 4021C 8004FA1C C0101000 */  sll        $v0, $s0, 3
    /* 40220 8004FA20 23105000 */  subu       $v0, $v0, $s0
    /* 40224 8004FA24 00110200 */  sll        $v0, $v0, 4
    /* 40228 8004FA28 21105000 */  addu       $v0, $v0, $s0
    /* 4022C 8004FA2C 40110200 */  sll        $v0, $v0, 5
    /* 40230 8004FA30 21104300 */  addu       $v0, $v0, $v1
    /* 40234 8004FA34 0F0E4390 */  lbu        $v1, 0xE0F($v0)
    /* 40238 8004FA38 07000224 */  addiu      $v0, $zero, 0x7
    /* 4023C 8004FA3C F3006210 */  beq        $v1, $v0, .L8004FE0C
    /* 40240 8004FA40 21200000 */   addu      $a0, $zero, $zero
    /* 40244 8004FA44 21288000 */  addu       $a1, $a0, $zero
    /* 40248 8004FA48 21308000 */  addu       $a2, $a0, $zero
    /* 4024C 8004FA4C 477E010C */  jal        func_8005F91C
    /* 40250 8004FA50 21388000 */   addu      $a3, $a0, $zero
    /* 40254 8004FA54 01000424 */  addiu      $a0, $zero, 0x1
    /* 40258 8004FA58 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 4025C 8004FA5C 21300002 */  addu       $a2, $s0, $zero
    /* 40260 8004FA60 C667010C */  jal        func_80059F18
    /* 40264 8004FA64 E2FF0724 */   addiu     $a3, $zero, -0x1E
    /* 40268 8004FA68 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 4026C 8004FA6C 3C000324 */  addiu      $v1, $zero, 0x3C
    /* 40270 8004FA70 E10083A3 */  sb         $v1, %gp_rel(D_8009AFE9)($gp)
    /* 40274 8004FA74 823F0108 */  j          .L8004FE08
    /* 40278 8004FA78 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004FA7C
    /* 4027C 8004FA7C 0F80033C */  lui        $v1, %hi(D_800F2C40)
    /* 40280 8004FA80 402C6324 */  addiu      $v1, $v1, %lo(D_800F2C40)
    /* 40284 8004FA84 0F0E6290 */  lbu        $v0, 0xE0F($v1)
    /* 40288 8004FA88 00000000 */  nop
    /* 4028C 8004FA8C 06004238 */  xori       $v0, $v0, 0x6
    /* 40290 8004FA90 0100502C */  sltiu      $s0, $v0, 0x1
    /* 40294 8004FA94 C0101000 */  sll        $v0, $s0, 3
    /* 40298 8004FA98 23105000 */  subu       $v0, $v0, $s0
    /* 4029C 8004FA9C 00110200 */  sll        $v0, $v0, 4
    /* 402A0 8004FAA0 21105000 */  addu       $v0, $v0, $s0
    /* 402A4 8004FAA4 40110200 */  sll        $v0, $v0, 5
    /* 402A8 8004FAA8 21104300 */  addu       $v0, $v0, $v1
    /* 402AC 8004FAAC 130E4290 */  lbu        $v0, 0xE13($v0)
    /* 402B0 8004FAB0 00000000 */  nop
    /* 402B4 8004FAB4 D5004014 */  bnez       $v0, .L8004FE0C
    /* 402B8 8004FAB8 00000000 */   nop
    /* 402BC 8004FABC 1E6A010C */  jal        func_8005A878
    /* 402C0 8004FAC0 01000424 */   addiu     $a0, $zero, 0x1
    /* 402C4 8004FAC4 D1004010 */  beqz       $v0, .L8004FE0C
    /* 402C8 8004FAC8 00000000 */   nop
    /* 402CC 8004FACC 8763010C */  jal        func_80058E1C
    /* 402D0 8004FAD0 00000000 */   nop
    /* 402D4 8004FAD4 E1008393 */  lbu        $v1, %gp_rel(D_8009AFE9)($gp)
    /* 402D8 8004FAD8 00000000 */  nop
    /* 402DC 8004FADC 21186200 */  addu       $v1, $v1, $v0
    /* 402E0 8004FAE0 E10083A3 */  sb         $v1, %gp_rel(D_8009AFE9)($gp)
    /* 402E4 8004FAE4 FF006330 */  andi       $v1, $v1, 0xFF
    /* 402E8 8004FAE8 3C00632C */  sltiu      $v1, $v1, 0x3C
    /* 402EC 8004FAEC C7006014 */  bnez       $v1, .L8004FE0C
    /* 402F0 8004FAF0 21200002 */   addu      $a0, $s0, $zero
    /* 402F4 8004FAF4 05000524 */  addiu      $a1, $zero, 0x5
    /* 402F8 8004FAF8 80000624 */  addiu      $a2, $zero, 0x80
    /* 402FC 8004FAFC 2138C000 */  addu       $a3, $a2, $zero
    /* 40300 8004FB00 2110C000 */  addu       $v0, $a2, $zero
    /* 40304 8004FB04 6465010C */  jal        func_80059590
    /* 40308 8004FB08 1000A2AF */   sw        $v0, 0x10($sp)
    /* 4030C 8004FB0C 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 40310 8004FB10 823F0108 */  j          .L8004FE08
    /* 40314 8004FB14 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004FB18
    /* 40318 8004FB18 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 4031C 8004FB1C 402C5024 */  addiu      $s0, $v0, %lo(D_800F2C40)
    /* 40320 8004FB20 0F0E0292 */  lbu        $v0, 0xE0F($s0)
    /* 40324 8004FB24 F80C0496 */  lhu        $a0, 0xCF8($s0)
    /* 40328 8004FB28 181B0396 */  lhu        $v1, 0x1B18($s0)
    /* 4032C 8004FB2C 06004238 */  xori       $v0, $v0, 0x6
    /* 40330 8004FB30 16008314 */  bne        $a0, $v1, .L8004FB8C
    /* 40334 8004FB34 0100512C */   sltiu     $s1, $v0, 0x1
    /* 40338 8004FB38 1F1C0292 */  lbu        $v0, 0x1C1F($s0)
    /* 4033C 8004FB3C 00000000 */  nop
    /* 40340 8004FB40 13004014 */  bnez       $v0, .L8004FB90
    /* 40344 8004FB44 0F80033C */   lui       $v1, %hi(D_800F2C40)
    /* 40348 8004FB48 351C0292 */  lbu        $v0, 0x1C35($s0)
    /* 4034C 8004FB4C 00000000 */  nop
    /* 40350 8004FB50 10004014 */  bnez       $v0, .L8004FB94
    /* 40354 8004FB54 402C6324 */   addiu     $v1, $v1, %lo(D_800F2C40)
    /* 40358 8004FB58 0C1C048E */  lw         $a0, 0x1C0C($s0)
    /* 4035C 8004FB5C 2400A28F */  lw         $v0, 0x24($sp)
    /* 40360 8004FB60 01000324 */  addiu      $v1, $zero, 0x1
    /* 40364 8004FB64 980083A3 */  sb         $v1, %gp_rel(D_8009AFA0)($gp)
    /* 40368 8004FB68 09F84000 */  jalr       $v0
    /* 4036C 8004FB6C FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 40370 8004FB70 02000324 */  addiu      $v1, $zero, 0x2
    /* 40374 8004FB74 A5004314 */  bne        $v0, $v1, .L8004FE0C
    /* 40378 8004FB78 00000000 */   nop
    /* 4037C 8004FB7C 351C0292 */  lbu        $v0, 0x1C35($s0)
    /* 40380 8004FB80 00000000 */  nop
    /* 40384 8004FB84 01004224 */  addiu      $v0, $v0, 0x1
    /* 40388 8004FB88 351C02A2 */  sb         $v0, 0x1C35($s0)
  .L8004FB8C:
    /* 4038C 8004FB8C 0F80033C */  lui        $v1, %hi(D_800F2C40)
  .L8004FB90:
    /* 40390 8004FB90 402C6324 */  addiu      $v1, $v1, %lo(D_800F2C40)
  .L8004FB94:
    /* 40394 8004FB94 C0101100 */  sll        $v0, $s1, 3
    /* 40398 8004FB98 23105100 */  subu       $v0, $v0, $s1
    /* 4039C 8004FB9C 00110200 */  sll        $v0, $v0, 4
    /* 403A0 8004FBA0 21105100 */  addu       $v0, $v0, $s1
    /* 403A4 8004FBA4 40110200 */  sll        $v0, $v0, 5
    /* 403A8 8004FBA8 21204300 */  addu       $a0, $v0, $v1
    /* 403AC 8004FBAC C00D8290 */  lbu        $v0, 0xDC0($a0)
    /* 403B0 8004FBB0 00000000 */  nop
    /* 403B4 8004FBB4 75004014 */  bnez       $v0, .L8004FD8C
    /* 403B8 8004FBB8 00000000 */   nop
    /* 403BC 8004FBBC 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 403C0 8004FBC0 823F0108 */  j          .L8004FE08
    /* 403C4 8004FBC4 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004FBC8
    /* 403C8 8004FBC8 1E6A010C */  jal        func_8005A878
    /* 403CC 8004FBCC 01000424 */   addiu     $a0, $zero, 0x1
    /* 403D0 8004FBD0 8E004010 */  beqz       $v0, .L8004FE0C
    /* 403D4 8004FBD4 28000224 */   addiu     $v0, $zero, 0x28
    /* 403D8 8004FBD8 823F0108 */  j          .L8004FE08
    /* 403DC 8004FBDC 00000000 */   nop
  jlabel .L8004FBE0
    /* 403E0 8004FBE0 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 403E4 8004FBE4 402C5024 */  addiu      $s0, $v0, %lo(D_800F2C40)
    /* 403E8 8004FBE8 351C0292 */  lbu        $v0, 0x1C35($s0)
    /* 403EC 8004FBEC 00000000 */  nop
    /* 403F0 8004FBF0 10004014 */  bnez       $v0, .L8004FC34
    /* 403F4 8004FBF4 80101200 */   sll       $v0, $s2, 2
    /* 403F8 8004FBF8 2110A203 */  addu       $v0, $sp, $v0
    /* 403FC 8004FBFC 0C1C048E */  lw         $a0, 0x1C0C($s0)
    /* 40400 8004FC00 1800428C */  lw         $v0, 0x18($v0)
    /* 40404 8004FC04 01000324 */  addiu      $v1, $zero, 0x1
    /* 40408 8004FC08 980083A3 */  sb         $v1, %gp_rel(D_8009AFA0)($gp)
    /* 4040C 8004FC0C 09F84000 */  jalr       $v0
    /* 40410 8004FC10 FEFF0524 */   addiu     $a1, $zero, -0x2
    /* 40414 8004FC14 02000324 */  addiu      $v1, $zero, 0x2
    /* 40418 8004FC18 7C004314 */  bne        $v0, $v1, .L8004FE0C
    /* 4041C 8004FC1C 00000000 */   nop
    /* 40420 8004FC20 351C0292 */  lbu        $v0, 0x1C35($s0)
    /* 40424 8004FC24 00000000 */  nop
    /* 40428 8004FC28 01004224 */  addiu      $v0, $v0, 0x1
    /* 4042C 8004FC2C 833F0108 */  j          .L8004FE0C
    /* 40430 8004FC30 351C02A2 */   sb        $v0, 0x1C35($s0)
  .L8004FC34:
    /* 40434 8004FC34 1E6A010C */  jal        func_8005A878
    /* 40438 8004FC38 01000424 */   addiu     $a0, $zero, 0x1
    /* 4043C 8004FC3C 73004010 */  beqz       $v0, .L8004FE0C
    /* 40440 8004FC40 01000424 */   addiu     $a0, $zero, 0x1
    /* 40444 8004FC44 05000524 */  addiu      $a1, $zero, 0x5
    /* 40448 8004FC48 80000624 */  addiu      $a2, $zero, 0x80
    /* 4044C 8004FC4C 2138C000 */  addu       $a3, $a2, $zero
    /* 40450 8004FC50 2110C000 */  addu       $v0, $a2, $zero
    /* 40454 8004FC54 6465010C */  jal        func_80059590
    /* 40458 8004FC58 1000A2AF */   sw        $v0, 0x10($sp)
    /* 4045C 8004FC5C 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 40460 8004FC60 823F0108 */  j          .L8004FE08
    /* 40464 8004FC64 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004FC68
    /* 40468 8004FC68 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 4046C 8004FC6C 402C4424 */  addiu      $a0, $v0, %lo(D_800F2C40)
    /* 40470 8004FC70 E01B8290 */  lbu        $v0, 0x1BE0($a0)
    /* 40474 8004FC74 00000000 */  nop
    /* 40478 8004FC78 09004010 */  beqz       $v0, .L8004FCA0
    /* 4047C 8004FC7C FEFF4224 */   addiu     $v0, $v0, -0x2
    /* 40480 8004FC80 E01B82A0 */  sb         $v0, 0x1BE0($a0)
    /* 40484 8004FC84 E11B8290 */  lbu        $v0, 0x1BE1($a0)
    /* 40488 8004FC88 E21B8390 */  lbu        $v1, 0x1BE2($a0)
    /* 4048C 8004FC8C FEFF4224 */  addiu      $v0, $v0, -0x2
    /* 40490 8004FC90 FEFF6324 */  addiu      $v1, $v1, -0x2
  .L8004FC94:
    /* 40494 8004FC94 E11B82A0 */  sb         $v0, 0x1BE1($a0)
    /* 40498 8004FC98 833F0108 */  j          .L8004FE0C
    /* 4049C 8004FC9C E21B83A0 */   sb        $v1, 0x1BE2($a0)
  .L8004FCA0:
    /* 404A0 8004FCA0 72058487 */  lh         $a0, %gp_rel(D_8009B47A)($gp)
    /* 404A4 8004FCA4 00000000 */  nop
    /* 404A8 8004FCA8 000C8324 */  addiu      $v1, $a0, 0xC00
    /* 404AC 8004FCAC 02006104 */  bgez       $v1, .L8004FCB8
    /* 404B0 8004FCB0 21106000 */   addu      $v0, $v1, $zero
    /* 404B4 8004FCB4 FF1B8224 */  addiu      $v0, $a0, 0x1BFF
  .L8004FCB8:
    /* 404B8 8004FCB8 03130200 */  sra        $v0, $v0, 12
    /* 404BC 8004FCBC 00130200 */  sll        $v0, $v0, 12
    /* 404C0 8004FCC0 23106200 */  subu       $v0, $v1, $v0
    /* 404C4 8004FCC4 FFFD4224 */  addiu      $v0, $v0, -0x201
    /* 404C8 8004FCC8 FF0B422C */  sltiu      $v0, $v0, 0xBFF
    /* 404CC 8004FCCC 4F004010 */  beqz       $v0, .L8004FE0C
    /* 404D0 8004FCD0 00000000 */   nop
    /* 404D4 8004FCD4 B868010C */  jal        func_8005A2E0
    /* 404D8 8004FCD8 21200000 */   addu      $a0, $zero, $zero
    /* 404DC 8004FCDC 6210043C */  lui        $a0, (0x10624DD3 >> 16)
    /* 404E0 8004FCE0 D34D8434 */  ori        $a0, $a0, (0x10624DD3 & 0xFFFF)
    /* 404E4 8004FCE4 00190200 */  sll        $v1, $v0, 4
    /* 404E8 8004FCE8 23186200 */  subu       $v1, $v1, $v0
    /* 404EC 8004FCEC 40180300 */  sll        $v1, $v1, 1
    /* 404F0 8004FCF0 18006400 */  mult       $v1, $a0
    /* 404F4 8004FCF4 C31F0300 */  sra        $v1, $v1, 31
    /* 404F8 8004FCF8 10400000 */  mfhi       $t0
    /* 404FC 8004FCFC 83110800 */  sra        $v0, $t0, 6
    /* 40500 8004FD00 23384300 */  subu       $a3, $v0, $v1
    /* 40504 8004FD04 1E00E228 */  slti       $v0, $a3, 0x1E
    /* 40508 8004FD08 02004010 */  beqz       $v0, .L8004FD14
    /* 4050C 8004FD0C 01000424 */   addiu     $a0, $zero, 0x1
    /* 40510 8004FD10 1E000724 */  addiu      $a3, $zero, 0x1E
  .L8004FD14:
    /* 40514 8004FD14 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 40518 8004FD18 21300000 */  addu       $a2, $zero, $zero
    /* 4051C 8004FD1C C667010C */  jal        func_80059F18
    /* 40520 8004FD20 23380700 */   negu      $a3, $a3
    /* 40524 8004FD24 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 40528 8004FD28 823F0108 */  j          .L8004FE08
    /* 4052C 8004FD2C 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004FD30
    /* 40530 8004FD30 C27E010C */  jal        func_8005FB08
    /* 40534 8004FD34 00000000 */   nop
    /* 40538 8004FD38 34004010 */  beqz       $v0, .L8004FE0C
    /* 4053C 8004FD3C 00000000 */   nop
    /* 40540 8004FD40 1E6A010C */  jal        func_8005A878
    /* 40544 8004FD44 01000424 */   addiu     $a0, $zero, 0x1
    /* 40548 8004FD48 30004010 */  beqz       $v0, .L8004FE0C
    /* 4054C 8004FD4C 21200000 */   addu      $a0, $zero, $zero
    /* 40550 8004FD50 05000524 */  addiu      $a1, $zero, 0x5
    /* 40554 8004FD54 80000624 */  addiu      $a2, $zero, 0x80
    /* 40558 8004FD58 2138C000 */  addu       $a3, $a2, $zero
    /* 4055C 8004FD5C 2110C000 */  addu       $v0, $a2, $zero
    /* 40560 8004FD60 6465010C */  jal        func_80059590
    /* 40564 8004FD64 1000A2AF */   sw        $v0, 0x10($sp)
    /* 40568 8004FD68 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 4056C 8004FD6C 823F0108 */  j          .L8004FE08
    /* 40570 8004FD70 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004FD74
    /* 40574 8004FD74 0F80023C */  lui        $v0, %hi(D_800F2C40)
    /* 40578 8004FD78 402C4424 */  addiu      $a0, $v0, %lo(D_800F2C40)
    /* 4057C 8004FD7C C00D8290 */  lbu        $v0, 0xDC0($a0)
    /* 40580 8004FD80 00000000 */  nop
    /* 40584 8004FD84 0A004010 */  beqz       $v0, .L8004FDB0
    /* 40588 8004FD88 00000000 */   nop
  .L8004FD8C:
    /* 4058C 8004FD8C FEFF4224 */  addiu      $v0, $v0, -0x2
    /* 40590 8004FD90 C00D82A0 */  sb         $v0, 0xDC0($a0)
    /* 40594 8004FD94 C10D8290 */  lbu        $v0, 0xDC1($a0)
    /* 40598 8004FD98 C20D8390 */  lbu        $v1, 0xDC2($a0)
    /* 4059C 8004FD9C FEFF4224 */  addiu      $v0, $v0, -0x2
    /* 405A0 8004FDA0 FEFF6324 */  addiu      $v1, $v1, -0x2
    /* 405A4 8004FDA4 C10D82A0 */  sb         $v0, 0xDC1($a0)
    /* 405A8 8004FDA8 833F0108 */  j          .L8004FE0C
    /* 405AC 8004FDAC C20D83A0 */   sb        $v1, 0xDC2($a0)
  .L8004FDB0:
    /* 405B0 8004FDB0 823F0108 */  j          .L8004FE08
    /* 405B4 8004FDB4 28000224 */   addiu     $v0, $zero, 0x28
  jlabel .L8004FDB8
    /* 405B8 8004FDB8 02000424 */  addiu      $a0, $zero, 0x2
    /* 405BC 8004FDBC A164010C */  jal        func_80059284
    /* 405C0 8004FDC0 03000524 */   addiu     $a1, $zero, 0x3
    /* 405C4 8004FDC4 4156000C */  jal        func_80015904
    /* 405C8 8004FDC8 00000000 */   nop
    /* 405CC 8004FDCC 92008293 */  lbu        $v0, %gp_rel(D_8009AF9A)($gp)
    /* 405D0 8004FDD0 823F0108 */  j          .L8004FE08
    /* 405D4 8004FDD4 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8004FDD8
    /* 405D8 8004FDD8 02000424 */  addiu      $a0, $zero, 0x2
    /* 405DC 8004FDDC A164010C */  jal        func_80059284
    /* 405E0 8004FDE0 03000524 */   addiu     $a1, $zero, 0x3
    /* 405E4 8004FDE4 0F80023C */  lui        $v0, %hi(D_800E9ECE)
    /* 405E8 8004FDE8 CE9E4290 */  lbu        $v0, %lo(D_800E9ECE)($v0)
    /* 405EC 8004FDEC 00000000 */  nop
    /* 405F0 8004FDF0 80004230 */  andi       $v0, $v0, 0x80
    /* 405F4 8004FDF4 05004014 */  bnez       $v0, .L8004FE0C
    /* 405F8 8004FDF8 00000000 */   nop
    /* 405FC 8004FDFC 8F1D010C */  jal        func_8004763C
    /* 40600 8004FE00 00000000 */   nop
    /* 40604 8004FE04 FEFF0224 */  addiu      $v0, $zero, -0x2
  .L8004FE08:
    /* 40608 8004FE08 920082A3 */  sb         $v0, %gp_rel(D_8009AF9A)($gp)
  jlabel .L8004FE0C
    /* 4060C 8004FE0C 6268010C */  jal        func_8005A188
    /* 40610 8004FE10 01000424 */   addiu     $a0, $zero, 0x1
    /* 40614 8004FE14 3C00BF8F */  lw         $ra, 0x3C($sp)
    /* 40618 8004FE18 3800B28F */  lw         $s2, 0x38($sp)
    /* 4061C 8004FE1C 3400B18F */  lw         $s1, 0x34($sp)
    /* 40620 8004FE20 3000B08F */  lw         $s0, 0x30($sp)
    /* 40624 8004FE24 0800E003 */  jr         $ra
    /* 40628 8004FE28 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8004EB00
