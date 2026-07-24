nonmatching func_8005EBF4, 0x47C

glabel func_8005EBF4
    /* 4F3F4 8005EBF4 88FFBD27 */  addiu      $sp, $sp, -0x78
    /* 4F3F8 8005EBF8 6C00B3AF */  sw         $s3, 0x6C($sp)
    /* 4F3FC 8005EBFC 21988000 */  addu       $s3, $a0, $zero
    /* 4F400 8005EC00 6800B2AF */  sw         $s2, 0x68($sp)
    /* 4F404 8005EC04 2190E000 */  addu       $s2, $a3, $zero
    /* 4F408 8005EC08 0F80073C */  lui        $a3, %hi(D_800F5788)
    /* 4F40C 8005EC0C 8857E724 */  addiu      $a3, $a3, %lo(D_800F5788)
    /* 4F410 8005EC10 23186702 */  subu       $v1, $s3, $a3
    /* 4F414 8005EC14 40100300 */  sll        $v0, $v1, 1
    /* 4F418 8005EC18 21104300 */  addu       $v0, $v0, $v1
    /* 4F41C 8005EC1C 00190200 */  sll        $v1, $v0, 4
    /* 4F420 8005EC20 21104300 */  addu       $v0, $v0, $v1
    /* 4F424 8005EC24 001A0200 */  sll        $v1, $v0, 8
    /* 4F428 8005EC28 21104300 */  addu       $v0, $v0, $v1
    /* 4F42C 8005EC2C 001C0200 */  sll        $v1, $v0, 16
    /* 4F430 8005EC30 21104300 */  addu       $v0, $v0, $v1
    /* 4F434 8005EC34 23100200 */  negu       $v0, $v0
    /* 4F438 8005EC38 70018493 */  lbu        $a0, %gp_rel(D_8009B078)($gp)
    /* 4F43C 8005EC3C C3100200 */  sra        $v0, $v0, 3
    /* 4F440 8005EC40 1A004400 */  div        $zero, $v0, $a0
    /* 4F444 8005EC44 02008014 */  bnez       $a0, .L8005EC50
    /* 4F448 8005EC48 00000000 */   nop
    /* 4F44C 8005EC4C 0D000700 */  break      7
  .L8005EC50:
    /* 4F450 8005EC50 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 4F454 8005EC54 04008114 */  bne        $a0, $at, .L8005EC68
    /* 4F458 8005EC58 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 4F45C 8005EC5C 02004114 */  bne        $v0, $at, .L8005EC68
    /* 4F460 8005EC60 00000000 */   nop
    /* 4F464 8005EC64 0D000600 */  break      6
  .L8005EC68:
    /* 4F468 8005EC68 10400000 */  mfhi       $t0
    /* 4F46C 8005EC6C 01004324 */  addiu      $v1, $v0, 0x1
    /* 4F470 8005EC70 00000000 */  nop
    /* 4F474 8005EC74 1A006400 */  div        $zero, $v1, $a0
    /* 4F478 8005EC78 02008014 */  bnez       $a0, .L8005EC84
    /* 4F47C 8005EC7C 00000000 */   nop
    /* 4F480 8005EC80 0D000700 */  break      7
  .L8005EC84:
    /* 4F484 8005EC84 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 4F488 8005EC88 04008114 */  bne        $a0, $at, .L8005EC9C
    /* 4F48C 8005EC8C 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 4F490 8005EC90 02006114 */  bne        $v1, $at, .L8005EC9C
    /* 4F494 8005EC94 00000000 */   nop
    /* 4F498 8005EC98 0D000600 */  break      6
  .L8005EC9C:
    /* 4F49C 8005EC9C 10480000 */  mfhi       $t1
    /* 4F4A0 8005ECA0 02004224 */  addiu      $v0, $v0, 0x2
    /* 4F4A4 8005ECA4 00000000 */  nop
    /* 4F4A8 8005ECA8 1A004400 */  div        $zero, $v0, $a0
    /* 4F4AC 8005ECAC 02008014 */  bnez       $a0, .L8005ECB8
    /* 4F4B0 8005ECB0 00000000 */   nop
    /* 4F4B4 8005ECB4 0D000700 */  break      7
  .L8005ECB8:
    /* 4F4B8 8005ECB8 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 4F4BC 8005ECBC 04008114 */  bne        $a0, $at, .L8005ECD0
    /* 4F4C0 8005ECC0 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 4F4C4 8005ECC4 02004114 */  bne        $v0, $at, .L8005ECD0
    /* 4F4C8 8005ECC8 00000000 */   nop
    /* 4F4CC 8005ECCC 0D000600 */  break      6
  .L8005ECD0:
    /* 4F4D0 8005ECD0 10180000 */  mfhi       $v1
    /* 4F4D4 8005ECD4 6400B1AF */  sw         $s1, 0x64($sp)
    /* 4F4D8 8005ECD8 2188A000 */  addu       $s1, $a1, $zero
    /* 4F4DC 8005ECDC 7000B4AF */  sw         $s4, 0x70($sp)
    /* 4F4E0 8005ECE0 21A0C000 */  addu       $s4, $a2, $zero
    /* 4F4E4 8005ECE4 7400BFAF */  sw         $ra, 0x74($sp)
    /* 4F4E8 8005ECE8 6000B0AF */  sw         $s0, 0x60($sp)
    /* 4F4EC 8005ECEC 21280000 */  addu       $a1, $zero, $zero
    /* 4F4F0 8005ECF0 10000624 */  addiu      $a2, $zero, 0x10
    /* 4F4F4 8005ECF4 01001024 */  addiu      $s0, $zero, 0x1
    /* 4F4F8 8005ECF8 80100800 */  sll        $v0, $t0, 2
    /* 4F4FC 8005ECFC 21104800 */  addu       $v0, $v0, $t0
    /* 4F500 8005ED00 C0100200 */  sll        $v0, $v0, 3
    /* 4F504 8005ED04 21104700 */  addu       $v0, $v0, $a3
    /* 4F508 8005ED08 2800A2AF */  sw         $v0, 0x28($sp)
    /* 4F50C 8005ED0C 80100900 */  sll        $v0, $t1, 2
    /* 4F510 8005ED10 21104900 */  addu       $v0, $v0, $t1
    /* 4F514 8005ED14 C0100200 */  sll        $v0, $v0, 3
    /* 4F518 8005ED18 21104700 */  addu       $v0, $v0, $a3
    /* 4F51C 8005ED1C 2C00A2AF */  sw         $v0, 0x2C($sp)
    /* 4F520 8005ED20 80100300 */  sll        $v0, $v1, 2
    /* 4F524 8005ED24 21104300 */  addu       $v0, $v0, $v1
    /* 4F528 8005ED28 C0100200 */  sll        $v0, $v0, 3
    /* 4F52C 8005ED2C 21104700 */  addu       $v0, $v0, $a3
    /* 4F530 8005ED30 3000A2AF */  sw         $v0, 0x30($sp)
    /* 4F534 8005ED34 2800AA8F */  lw         $t2, 0x28($sp)
    /* 4F538 8005ED38 2C00AB8F */  lw         $t3, 0x2C($sp)
    /* 4F53C 8005ED3C 3000AC8F */  lw         $t4, 0x30($sp)
    /* 4F540 8005ED40 1800AAAF */  sw         $t2, 0x18($sp)
    /* 4F544 8005ED44 1C00ABAF */  sw         $t3, 0x1C($sp)
    /* 4F548 8005ED48 2000ACAF */  sw         $t4, 0x20($sp)
    /* 4F54C 8005ED4C F438020C */  jal        func_8008E3D0
    /* 4F550 8005ED50 3800A427 */   addiu     $a0, $sp, 0x38
    /* 4F554 8005ED54 C0101100 */  sll        $v0, $s1, 3
    /* 4F558 8005ED58 21204000 */  addu       $a0, $v0, $zero
    /* 4F55C 8005ED5C 21280002 */  addu       $a1, $s0, $zero
    /* 4F560 8005ED60 1C00A327 */  addiu      $v1, $sp, 0x1C
    /* 4F564 8005ED64 0F80023C */  lui        $v0, %hi(D_800F5768)
    /* 4F568 8005ED68 68574224 */  addiu      $v0, $v0, %lo(D_800F5768)
    /* 4F56C 8005ED6C 21108200 */  addu       $v0, $a0, $v0
    /* 4F570 8005ED70 3800A2AF */  sw         $v0, 0x38($sp)
  .L8005ED74:
    /* 4F574 8005ED74 0000628C */  lw         $v0, 0x0($v1)
    /* 4F578 8005ED78 00000000 */  nop
    /* 4F57C 8005ED7C 21104400 */  addu       $v0, $v0, $a0
    /* 4F580 8005ED80 06004284 */  lh         $v0, 0x6($v0)
    /* 4F584 8005ED84 00000000 */  nop
    /* 4F588 8005ED88 06004514 */  bne        $v0, $a1, .L8005EDA4
    /* 4F58C 8005ED8C 0300022A */   slti      $v0, $s0, 0x3
    /* 4F590 8005ED90 01001026 */  addiu      $s0, $s0, 0x1
    /* 4F594 8005ED94 0300022A */  slti       $v0, $s0, 0x3
    /* 4F598 8005ED98 F6FF4014 */  bnez       $v0, .L8005ED74
    /* 4F59C 8005ED9C 04006324 */   addiu     $v1, $v1, 0x4
    /* 4F5A0 8005EDA0 0300022A */  slti       $v0, $s0, 0x3
  .L8005EDA4:
    /* 4F5A4 8005EDA4 0C004010 */  beqz       $v0, .L8005EDD8
    /* 4F5A8 8005EDA8 FFFF0326 */   addiu     $v1, $s0, -0x1
    /* 4F5AC 8005EDAC 1800A227 */  addiu      $v0, $sp, 0x18
    /* 4F5B0 8005EDB0 80180300 */  sll        $v1, $v1, 2
    /* 4F5B4 8005EDB4 21204300 */  addu       $a0, $v0, $v1
    /* 4F5B8 8005EDB8 80181000 */  sll        $v1, $s0, 2
    /* 4F5BC 8005EDBC 21186200 */  addu       $v1, $v1, $v0
  .L8005EDC0:
    /* 4F5C0 8005EDC0 0000828C */  lw         $v0, 0x0($a0)
    /* 4F5C4 8005EDC4 01001026 */  addiu      $s0, $s0, 0x1
    /* 4F5C8 8005EDC8 000062AC */  sw         $v0, 0x0($v1)
    /* 4F5CC 8005EDCC 0300022A */  slti       $v0, $s0, 0x3
    /* 4F5D0 8005EDD0 FBFF4014 */  bnez       $v0, .L8005EDC0
    /* 4F5D4 8005EDD4 04006324 */   addiu     $v1, $v1, 0x4
  .L8005EDD8:
    /* 4F5D8 8005EDD8 21800000 */  addu       $s0, $zero, $zero
    /* 4F5DC 8005EDDC 3800A627 */  addiu      $a2, $sp, 0x38
    /* 4F5E0 8005EDE0 1800A527 */  addiu      $a1, $sp, 0x18
    /* 4F5E4 8005EDE4 C0201100 */  sll        $a0, $s1, 3
    /* 4F5E8 8005EDE8 01000326 */  addiu      $v1, $s0, 0x1
  .L8005EDEC:
    /* 4F5EC 8005EDEC 80101000 */  sll        $v0, $s0, 2
    /* 4F5F0 8005EDF0 21806000 */  addu       $s0, $v1, $zero
    /* 4F5F4 8005EDF4 80181000 */  sll        $v1, $s0, 2
    /* 4F5F8 8005EDF8 2110A200 */  addu       $v0, $a1, $v0
    /* 4F5FC 8005EDFC 0000428C */  lw         $v0, 0x0($v0)
    /* 4F600 8005EE00 2118C300 */  addu       $v1, $a2, $v1
    /* 4F604 8005EE04 21104400 */  addu       $v0, $v0, $a0
    /* 4F608 8005EE08 000062AC */  sw         $v0, 0x0($v1)
    /* 4F60C 8005EE0C 0300022A */  slti       $v0, $s0, 0x3
    /* 4F610 8005EE10 F6FF4014 */  bnez       $v0, .L8005EDEC
    /* 4F614 8005EE14 01000326 */   addiu     $v1, $s0, 0x1
    /* 4F618 8005EE18 28004012 */  beqz       $s2, .L8005EEBC
    /* 4F61C 8005EE1C 0F80043C */   lui       $a0, %hi(D_800F5788)
    /* 4F620 8005EE20 88578424 */  addiu      $a0, $a0, %lo(D_800F5788)
    /* 4F624 8005EE24 23186402 */  subu       $v1, $s3, $a0
    /* 4F628 8005EE28 40100300 */  sll        $v0, $v1, 1
    /* 4F62C 8005EE2C 21104300 */  addu       $v0, $v0, $v1
    /* 4F630 8005EE30 00190200 */  sll        $v1, $v0, 4
    /* 4F634 8005EE34 21104300 */  addu       $v0, $v0, $v1
    /* 4F638 8005EE38 001A0200 */  sll        $v1, $v0, 8
    /* 4F63C 8005EE3C 21104300 */  addu       $v0, $v0, $v1
    /* 4F640 8005EE40 001C0200 */  sll        $v1, $v0, 16
    /* 4F644 8005EE44 21104300 */  addu       $v0, $v0, $v1
    /* 4F648 8005EE48 23100200 */  negu       $v0, $v0
    /* 4F64C 8005EE4C 70018393 */  lbu        $v1, %gp_rel(D_8009B078)($gp)
    /* 4F650 8005EE50 C3100200 */  sra        $v0, $v0, 3
    /* 4F654 8005EE54 21104300 */  addu       $v0, $v0, $v1
    /* 4F658 8005EE58 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 4F65C 8005EE5C 1A004300 */  div        $zero, $v0, $v1
    /* 4F660 8005EE60 02006014 */  bnez       $v1, .L8005EE6C
    /* 4F664 8005EE64 00000000 */   nop
    /* 4F668 8005EE68 0D000700 */  break      7
  .L8005EE6C:
    /* 4F66C 8005EE6C FFFF0124 */  addiu      $at, $zero, -0x1
    /* 4F670 8005EE70 04006114 */  bne        $v1, $at, .L8005EE84
    /* 4F674 8005EE74 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 4F678 8005EE78 02004114 */  bne        $v0, $at, .L8005EE84
    /* 4F67C 8005EE7C 00000000 */   nop
    /* 4F680 8005EE80 0D000600 */  break      6
  .L8005EE84:
    /* 4F684 8005EE84 10180000 */  mfhi       $v1
    /* 4F688 8005EE88 00000000 */  nop
    /* 4F68C 8005EE8C 80100300 */  sll        $v0, $v1, 2
    /* 4F690 8005EE90 21104300 */  addu       $v0, $v0, $v1
    /* 4F694 8005EE94 C0100200 */  sll        $v0, $v0, 3
    /* 4F698 8005EE98 21104400 */  addu       $v0, $v0, $a0
    /* 4F69C 8005EE9C C0181100 */  sll        $v1, $s1, 3
    /* 4F6A0 8005EEA0 21204300 */  addu       $a0, $v0, $v1
    /* 4F6A4 8005EEA4 06008384 */  lh         $v1, 0x6($a0)
    /* 4F6A8 8005EEA8 01000224 */  addiu      $v0, $zero, 0x1
    /* 4F6AC 8005EEAC 18006214 */  bne        $v1, $v0, .L8005EF10
    /* 4F6B0 8005EEB0 21800000 */   addu      $s0, $zero, $zero
    /* 4F6B4 8005EEB4 C47B0108 */  j          .L8005EF10
    /* 4F6B8 8005EEB8 3800A4AF */   sw        $a0, 0x38($sp)
  .L8005EEBC:
    /* 4F6BC 8005EEBC 01001024 */  addiu      $s0, $zero, 0x1
    /* 4F6C0 8005EEC0 1800A627 */  addiu      $a2, $sp, 0x18
    /* 4F6C4 8005EEC4 1C00A527 */  addiu      $a1, $sp, 0x1C
    /* 4F6C8 8005EEC8 1800A28F */  lw         $v0, 0x18($sp)
    /* 4F6CC 8005EECC 21200000 */  addu       $a0, $zero, $zero
    /* 4F6D0 8005EED0 22005294 */  lhu        $s2, 0x22($v0)
  .L8005EED4:
    /* 4F6D4 8005EED4 2110C400 */  addu       $v0, $a2, $a0
    /* 4F6D8 8005EED8 0000428C */  lw         $v0, 0x0($v0)
    /* 4F6DC 8005EEDC 0000A38C */  lw         $v1, 0x0($a1)
    /* 4F6E0 8005EEE0 00000000 */  nop
    /* 4F6E4 8005EEE4 04004310 */  beq        $v0, $v1, .L8005EEF8
    /* 4F6E8 8005EEE8 00000000 */   nop
    /* 4F6EC 8005EEEC 22006294 */  lhu        $v0, 0x22($v1)
    /* 4F6F0 8005EEF0 00000000 */  nop
    /* 4F6F4 8005EEF4 21904202 */  addu       $s2, $s2, $v0
  .L8005EEF8:
    /* 4F6F8 8005EEF8 0400A524 */  addiu      $a1, $a1, 0x4
    /* 4F6FC 8005EEFC 01001026 */  addiu      $s0, $s0, 0x1
    /* 4F700 8005EF00 0300022A */  slti       $v0, $s0, 0x3
    /* 4F704 8005EF04 F3FF4014 */  bnez       $v0, .L8005EED4
    /* 4F708 8005EF08 04008424 */   addiu     $a0, $a0, 0x4
    /* 4F70C 8005EF0C 21800000 */  addu       $s0, $zero, $zero
  .L8005EF10:
    /* 4F710 8005EF10 8800B38F */  lw         $s3, 0x88($sp)
    /* 4F714 8005EF14 4800B127 */  addiu      $s1, $sp, 0x48
  .L8005EF18:
    /* 4F718 8005EF18 40381000 */  sll        $a3, $s0, 1
    /* 4F71C 8005EF1C 3800A48F */  lw         $a0, 0x38($sp)
    /* 4F720 8005EF20 3C00A58F */  lw         $a1, 0x3C($sp)
    /* 4F724 8005EF24 4000A28F */  lw         $v0, 0x40($sp)
    /* 4F728 8005EF28 4400A38F */  lw         $v1, 0x44($sp)
    /* 4F72C 8005EF2C 2120E400 */  addu       $a0, $a3, $a0
    /* 4F730 8005EF30 2128E500 */  addu       $a1, $a3, $a1
    /* 4F734 8005EF34 2110E200 */  addu       $v0, $a3, $v0
    /* 4F738 8005EF38 2138E300 */  addu       $a3, $a3, $v1
    /* 4F73C 8005EF3C 00008484 */  lh         $a0, 0x0($a0)
    /* 4F740 8005EF40 0000A584 */  lh         $a1, 0x0($a1)
    /* 4F744 8005EF44 00004684 */  lh         $a2, 0x0($v0)
    /* 4F748 8005EF48 0000E784 */  lh         $a3, 0x0($a3)
    /* 4F74C 8005EF4C 02000224 */  addiu      $v0, $zero, 0x2
    /* 4F750 8005EF50 1000B1AF */  sw         $s1, 0x10($sp)
    /* 4F754 8005EF54 F17E010C */  jal        func_8005FBC4
    /* 4F758 8005EF58 1400A2AF */   sw        $v0, 0x14($sp)
    /* 4F75C 8005EF5C 00002286 */  lh         $v0, 0x0($s1)
    /* 4F760 8005EF60 00000000 */  nop
    /* 4F764 8005EF64 18005400 */  mult       $v0, $s4
    /* 4F768 8005EF68 12180000 */  mflo       $v1
    /* 4F76C 8005EF6C 00000000 */  nop
    /* 4F770 8005EF70 00000000 */  nop
    /* 4F774 8005EF74 1A007200 */  div        $zero, $v1, $s2
    /* 4F778 8005EF78 02004016 */  bnez       $s2, .L8005EF84
    /* 4F77C 8005EF7C 00000000 */   nop
    /* 4F780 8005EF80 0D000700 */  break      7
  .L8005EF84:
    /* 4F784 8005EF84 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 4F788 8005EF88 04004116 */  bne        $s2, $at, .L8005EF9C
    /* 4F78C 8005EF8C 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 4F790 8005EF90 02006114 */  bne        $v1, $at, .L8005EF9C
    /* 4F794 8005EF94 00000000 */   nop
    /* 4F798 8005EF98 0D000600 */  break      6
  .L8005EF9C:
    /* 4F79C 8005EF9C 12100000 */  mflo       $v0
    /* 4F7A0 8005EFA0 02002386 */  lh         $v1, 0x2($s1)
    /* 4F7A4 8005EFA4 00000000 */  nop
    /* 4F7A8 8005EFA8 21104300 */  addu       $v0, $v0, $v1
    /* 4F7AC 8005EFAC 18005400 */  mult       $v0, $s4
    /* 4F7B0 8005EFB0 12180000 */  mflo       $v1
    /* 4F7B4 8005EFB4 00000000 */  nop
    /* 4F7B8 8005EFB8 00000000 */  nop
    /* 4F7BC 8005EFBC 1A007200 */  div        $zero, $v1, $s2
    /* 4F7C0 8005EFC0 02004016 */  bnez       $s2, .L8005EFCC
    /* 4F7C4 8005EFC4 00000000 */   nop
    /* 4F7C8 8005EFC8 0D000700 */  break      7
  .L8005EFCC:
    /* 4F7CC 8005EFCC FFFF0124 */  addiu      $at, $zero, -0x1
    /* 4F7D0 8005EFD0 04004116 */  bne        $s2, $at, .L8005EFE4
    /* 4F7D4 8005EFD4 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 4F7D8 8005EFD8 02006114 */  bne        $v1, $at, .L8005EFE4
    /* 4F7DC 8005EFDC 00000000 */   nop
    /* 4F7E0 8005EFE0 0D000600 */  break      6
  .L8005EFE4:
    /* 4F7E4 8005EFE4 12100000 */  mflo       $v0
    /* 4F7E8 8005EFE8 04002386 */  lh         $v1, 0x4($s1)
    /* 4F7EC 8005EFEC 00000000 */  nop
    /* 4F7F0 8005EFF0 21104300 */  addu       $v0, $v0, $v1
    /* 4F7F4 8005EFF4 18005400 */  mult       $v0, $s4
    /* 4F7F8 8005EFF8 12180000 */  mflo       $v1
    /* 4F7FC 8005EFFC 00000000 */  nop
    /* 4F800 8005F000 00000000 */  nop
    /* 4F804 8005F004 1A007200 */  div        $zero, $v1, $s2
    /* 4F808 8005F008 02004016 */  bnez       $s2, .L8005F014
    /* 4F80C 8005F00C 00000000 */   nop
    /* 4F810 8005F010 0D000700 */  break      7
  .L8005F014:
    /* 4F814 8005F014 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 4F818 8005F018 04004116 */  bne        $s2, $at, .L8005F02C
    /* 4F81C 8005F01C 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 4F820 8005F020 02006114 */  bne        $v1, $at, .L8005F02C
    /* 4F824 8005F024 00000000 */   nop
    /* 4F828 8005F028 0D000600 */  break      6
  .L8005F02C:
    /* 4F82C 8005F02C 12180000 */  mflo       $v1
    /* 4F830 8005F030 01001026 */  addiu      $s0, $s0, 0x1
    /* 4F834 8005F034 06002296 */  lhu        $v0, 0x6($s1)
    /* 4F838 8005F038 08003126 */  addiu      $s1, $s1, 0x8
    /* 4F83C 8005F03C 21104300 */  addu       $v0, $v0, $v1
    /* 4F840 8005F040 000062A6 */  sh         $v0, 0x0($s3)
    /* 4F844 8005F044 0300022A */  slti       $v0, $s0, 0x3
    /* 4F848 8005F048 B3FF4014 */  bnez       $v0, .L8005EF18
    /* 4F84C 8005F04C 02007326 */   addiu     $s3, $s3, 0x2
    /* 4F850 8005F050 7400BF8F */  lw         $ra, 0x74($sp)
    /* 4F854 8005F054 7000B48F */  lw         $s4, 0x70($sp)
    /* 4F858 8005F058 6C00B38F */  lw         $s3, 0x6C($sp)
    /* 4F85C 8005F05C 6800B28F */  lw         $s2, 0x68($sp)
    /* 4F860 8005F060 6400B18F */  lw         $s1, 0x64($sp)
    /* 4F864 8005F064 6000B08F */  lw         $s0, 0x60($sp)
    /* 4F868 8005F068 0800E003 */  jr         $ra
    /* 4F86C 8005F06C 7800BD27 */   addiu     $sp, $sp, 0x78
endlabel func_8005EBF4
