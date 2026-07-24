nonmatching func_8002F630, 0x300

glabel func_8002F630
    /* 1FE30 8002F630 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 1FE34 8002F634 4000BFAF */  sw         $ra, 0x40($sp)
    /* 1FE38 8002F638 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 1FE3C 8002F63C 3800B4AF */  sw         $s4, 0x38($sp)
    /* 1FE40 8002F640 3400B3AF */  sw         $s3, 0x34($sp)
    /* 1FE44 8002F644 3000B2AF */  sw         $s2, 0x30($sp)
    /* 1FE48 8002F648 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 1FE4C 8002F64C EDB8000C */  jal        func_8002E3B4
    /* 1FE50 8002F650 2800B0AF */   sw        $s0, 0x28($sp)
    /* 1FE54 8002F654 15004014 */  bnez       $v0, .L8002F6AC
    /* 1FE58 8002F658 21200000 */   addu      $a0, $zero, $zero
    /* 1FE5C 8002F65C 21288000 */  addu       $a1, $a0, $zero
    /* 1FE60 8002F660 A71F0624 */  addiu      $a2, $zero, 0x1FA7
    /* 1FE64 8002F664 8803838F */  lw         $v1, %gp_rel(D_8009B290)($gp)
    /* 1FE68 8002F668 00000000 */  nop
    /* 1FE6C 8002F66C 02006224 */  addiu      $v0, $v1, 0x2
    /* 1FE70 8002F670 880382AF */  sw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1FE74 8002F674 0380023C */  lui        $v0, %hi(func_8002F4C0)
    /* 1FE78 8002F678 00006890 */  lbu        $t0, 0x0($v1)
    /* 1FE7C 8002F67C 01006390 */  lbu        $v1, 0x1($v1)
    /* 1FE80 8002F680 C0F44224 */  addiu      $v0, $v0, %lo(func_8002F4C0)
    /* 1FE84 8002F684 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1FE88 8002F688 1400A0AF */  sw         $zero, 0x14($sp)
    /* 1FE8C 8002F68C 1800A0AF */  sw         $zero, 0x18($sp)
    /* 1FE90 8002F690 001A0300 */  sll        $v1, $v1, 8
    /* 1FE94 8002F694 25400301 */  or         $t0, $t0, $v1
    /* 1FE98 8002F698 940388A7 */  sh         $t0, %gp_rel(D_8009B29C)($gp)
    /* 1FE9C 8002F69C 8753000C */  jal        func_80014E1C
    /* 1FEA0 8002F6A0 32000724 */   addiu     $a3, $zero, 0x32
    /* 1FEA4 8002F6A4 F94D000C */  jal        func_800137E4
    /* 1FEA8 8002F6A8 00000000 */   nop
  .L8002F6AC:
    /* 1FEAC 8002F6AC 74038597 */  lhu        $a1, %gp_rel(D_8009B27C)($gp)
    /* 1FEB0 8002F6B0 00000000 */  nop
    /* 1FEB4 8002F6B4 0040A230 */  andi       $v0, $a1, 0x4000
    /* 1FEB8 8002F6B8 7E004014 */  bnez       $v0, .L8002F8B4
    /* 1FEBC 8002F6BC 0002023C */   lui       $v0, (0x2000030 >> 16)
    /* 1FEC0 8002F6C0 30004234 */  ori        $v0, $v0, (0x2000030 & 0xFFFF)
    /* 1FEC4 8002F6C4 0A80033C */  lui        $v1, %hi(D_8009B0F4)
    /* 1FEC8 8002F6C8 F4B0638C */  lw         $v1, %lo(D_8009B0F4)($v1)
    /* 1FECC 8002F6CC 0A80043C */  lui        $a0, %hi(D_8009B134)
    /* 1FED0 8002F6D0 34B1848C */  lw         $a0, %lo(D_8009B134)($a0)
    /* 1FED4 8002F6D4 24186200 */  and        $v1, $v1, $v0
    /* 1FED8 8002F6D8 25186400 */  or         $v1, $v1, $a0
    /* 1FEDC 8002F6DC 8B006014 */  bnez       $v1, .L8002F90C
    /* 1FEE0 8002F6E0 0040A234 */   ori       $v0, $a1, 0x4000
    /* 1FEE4 8002F6E4 9803838F */  lw         $v1, %gp_rel(D_8009B2A0)($gp)
    /* 1FEE8 8002F6E8 740382A7 */  sh         $v0, %gp_rel(D_8009B27C)($gp)
    /* 1FEEC 8002F6EC 05006010 */  beqz       $v1, .L8002F704
    /* 1FEF0 8002F6F0 0F80103C */   lui       $s0, %hi(D_800EAE98)
    /* 1FEF4 8002F6F4 08006294 */  lhu        $v0, 0x8($v1)
    /* 1FEF8 8002F6F8 00000000 */  nop
    /* 1FEFC 8002F6FC BFFF4230 */  andi       $v0, $v0, 0xFFBF
    /* 1FF00 8002F700 080062A4 */  sh         $v0, 0x8($v1)
  .L8002F704:
    /* 1FF04 8002F704 98AE1326 */  addiu      $s3, $s0, %lo(D_800EAE98)
    /* 1FF08 8002F708 03B8000C */  jal        func_8002E00C
    /* 1FF0C 8002F70C 21206002 */   addu      $a0, $s3, $zero
    /* 1FF10 8002F710 0B00010C */  jal        func_8004002C
    /* 1FF14 8002F714 04001424 */   addiu     $s4, $zero, 0x4
    /* 1FF18 8002F718 21204000 */  addu       $a0, $v0, $zero
    /* 1FF1C 8002F71C 2B00010C */  jal        func_800400AC
    /* 1FF20 8002F720 02000524 */   addiu     $a1, $zero, 0x2
    /* 1FF24 8002F724 21A84000 */  addu       $s5, $v0, $zero
    /* 1FF28 8002F728 2120A002 */  addu       $a0, $s5, $zero
    /* 1FF2C 8002F72C 21280000 */  addu       $a1, $zero, $zero
    /* 1FF30 8002F730 2130A000 */  addu       $a2, $a1, $zero
    /* 1FF34 8002F734 2138A000 */  addu       $a3, $a1, $zero
    /* 1FF38 8002F738 17000224 */  addiu      $v0, $zero, 0x17
    /* 1FF3C 8002F73C 1800A2AF */  sw         $v0, 0x18($sp)
    /* 1FF40 8002F740 1B80023C */  lui        $v0, %hi(D_801AF000)
    /* 1FF44 8002F744 00F04224 */  addiu      $v0, $v0, %lo(D_801AF000)
    /* 1FF48 8002F748 1000A0AF */  sw         $zero, 0x10($sp)
    /* 1FF4C 8002F74C 1400A0AF */  sw         $zero, 0x14($sp)
    /* 1FF50 8002F750 1C00B4AF */  sw         $s4, 0x1C($sp)
    /* 1FF54 8002F754 2A0A010C */  jal        func_800428A8
    /* 1FF58 8002F758 2000A2AF */   sw        $v0, 0x20($sp)
    /* 1FF5C 8002F75C 2120A002 */  addu       $a0, $s5, $zero
    /* 1FF60 8002F760 3B0A010C */  jal        func_800428EC
    /* 1FF64 8002F764 01000524 */   addiu     $a1, $zero, 0x1
    /* 1FF68 8002F768 0800A296 */  lhu        $v0, 0x8($s5)
    /* 1FF6C 8002F76C 00000000 */  nop
    /* 1FF70 8002F770 28004234 */  ori        $v0, $v0, 0x28
    /* 1FF74 8002F774 0800A2A6 */  sh         $v0, 0x8($s5)
    /* 1FF78 8002F778 0400A28E */  lw         $v0, 0x4($s5)
    /* 1FF7C 8002F77C 0001033C */  lui        $v1, (0x1000000 >> 16)
    /* 1FF80 8002F780 25104300 */  or         $v0, $v0, $v1
    /* 1FF84 8002F784 0400A2AE */  sw         $v0, 0x4($s5)
    /* 1FF88 8002F788 0B00010C */  jal        func_8004002C
    /* 1FF8C 8002F78C 98AE15AE */   sw        $s5, %lo(D_800EAE98)($s0)
    /* 1FF90 8002F790 21204000 */  addu       $a0, $v0, $zero
    /* 1FF94 8002F794 2B00010C */  jal        func_800400AC
    /* 1FF98 8002F798 01000524 */   addiu     $a1, $zero, 0x1
    /* 1FF9C 8002F79C 21A84000 */  addu       $s5, $v0, $zero
    /* 1FFA0 8002F7A0 2120A002 */  addu       $a0, $s5, $zero
    /* 1FFA4 8002F7A4 21280000 */  addu       $a1, $zero, $zero
    /* 1FFA8 8002F7A8 2130A000 */  addu       $a2, $a1, $zero
    /* 1FFAC 8002F7AC 40010724 */  addiu      $a3, $zero, 0x140
    /* 1FFB0 8002F7B0 F0001224 */  addiu      $s2, $zero, 0xF0
    /* 1FFB4 8002F7B4 19001124 */  addiu      $s1, $zero, 0x19
    /* 1FFB8 8002F7B8 F5001024 */  addiu      $s0, $zero, 0xF5
    /* 1FFBC 8002F7BC 1000B2AF */  sw         $s2, 0x10($sp)
    /* 1FFC0 8002F7C0 1400A0AF */  sw         $zero, 0x14($sp)
    /* 1FFC4 8002F7C4 1800A0AF */  sw         $zero, 0x18($sp)
    /* 1FFC8 8002F7C8 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1FFCC 8002F7CC 2000A0AF */  sw         $zero, 0x20($sp)
    /* 1FFD0 8002F7D0 4401010C */  jal        func_80040510
    /* 1FFD4 8002F7D4 2400B0AF */   sw        $s0, 0x24($sp)
    /* 1FFD8 8002F7D8 2120A002 */  addu       $a0, $s5, $zero
    /* 1FFDC 8002F7DC 3B0A010C */  jal        func_800428EC
    /* 1FFE0 8002F7E0 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 1FFE4 8002F7E4 0B00010C */  jal        func_8004002C
    /* 1FFE8 8002F7E8 140075AE */   sw        $s5, 0x14($s3)
    /* 1FFEC 8002F7EC 21204000 */  addu       $a0, $v0, $zero
    /* 1FFF0 8002F7F0 2B00010C */  jal        func_800400AC
    /* 1FFF4 8002F7F4 01000524 */   addiu     $a1, $zero, 0x1
    /* 1FFF8 8002F7F8 21A84000 */  addu       $s5, $v0, $zero
    /* 1FFFC 8002F7FC 2120A002 */  addu       $a0, $s5, $zero
    /* 20000 8002F800 00010524 */  addiu      $a1, $zero, 0x100
    /* 20004 8002F804 21300000 */  addu       $a2, $zero, $zero
    /* 20008 8002F808 40000724 */  addiu      $a3, $zero, 0x40
    /* 2000C 8002F80C 1000B2AF */  sw         $s2, 0x10($sp)
    /* 20010 8002F810 1400A0AF */  sw         $zero, 0x14($sp)
    /* 20014 8002F814 1800A0AF */  sw         $zero, 0x18($sp)
    /* 20018 8002F818 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 2001C 8002F81C 2000A0AF */  sw         $zero, 0x20($sp)
    /* 20020 8002F820 4401010C */  jal        func_80040510
    /* 20024 8002F824 2400B0AF */   sw        $s0, 0x24($sp)
    /* 20028 8002F828 2120A002 */  addu       $a0, $s5, $zero
    /* 2002C 8002F82C 3B0A010C */  jal        func_800428EC
    /* 20030 8002F830 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 20034 8002F834 0B00010C */  jal        func_8004002C
    /* 20038 8002F838 280075AE */   sw        $s5, 0x28($s3)
    /* 2003C 8002F83C 21204000 */  addu       $a0, $v0, $zero
    /* 20040 8002F840 2B00010C */  jal        func_800400AC
    /* 20044 8002F844 21288002 */   addu      $a1, $s4, $zero
    /* 20048 8002F848 21804000 */  addu       $s0, $v0, $zero
    /* 2004C 8002F84C 21200002 */  addu       $a0, $s0, $zero
    /* 20050 8002F850 F709010C */  jal        func_800427DC
    /* 20054 8002F854 21280000 */   addu      $a1, $zero, $zero
    /* 20058 8002F858 F000043C */  lui        $a0, (0xF00140 >> 16)
    /* 2005C 8002F85C 40018434 */  ori        $a0, $a0, (0xF00140 & 0xFFFF)
    /* 20060 8002F860 FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 20064 8002F864 40010224 */  addiu      $v0, $zero, 0x140
    /* 20068 8002F868 300002AE */  sw         $v0, 0x30($s0)
    /* 2006C 8002F86C F000023C */  lui        $v0, (0xF00000 >> 16)
    /* 20070 8002F870 380002AE */  sw         $v0, 0x38($s0)
    /* 20074 8002F874 0400028E */  lw         $v0, 0x4($s0)
    /* 20078 8002F878 FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 2007C 8002F87C 3C0003AE */  sw         $v1, 0x3C($s0)
    /* 20080 8002F880 440003AE */  sw         $v1, 0x44($s0)
    /* 20084 8002F884 0060033C */  lui        $v1, (0x60000000 >> 16)
    /* 20088 8002F888 280000AE */  sw         $zero, 0x28($s0)
    /* 2008C 8002F88C 400004AE */  sw         $a0, 0x40($s0)
    /* 20090 8002F890 780390AF */  sw         $s0, %gp_rel(D_8009B280)($gp)
    /* 20094 8002F894 25104300 */  or         $v0, $v0, $v1
    /* 20098 8002F898 F755000C */  jal        func_800157DC
    /* 2009C 8002F89C 040002AE */   sw        $v0, 0x4($s0)
    /* 200A0 8002F8A0 0F80023C */  lui        $v0, %hi(D_800E9ECF)
    /* 200A4 8002F8A4 6656000C */  jal        func_80015998
    /* 200A8 8002F8A8 CF9E54A0 */   sb        $s4, %lo(D_800E9ECF)($v0)
    /* 200AC 8002F8AC 43BE0008 */  j          .L8002F90C
    /* 200B0 8002F8B0 00000000 */   nop
  .L8002F8B4:
    /* 200B4 8002F8B4 0F1C010C */  jal        func_8004703C
    /* 200B8 8002F8B8 00000000 */   nop
    /* 200BC 8002F8BC 80004230 */  andi       $v0, $v0, 0x80
    /* 200C0 8002F8C0 12004014 */  bnez       $v0, .L8002F90C
    /* 200C4 8002F8C4 00000000 */   nop
    /* 200C8 8002F8C8 C056000C */  jal        func_80015B00
    /* 200CC 8002F8CC 00000000 */   nop
    /* 200D0 8002F8D0 9803838F */  lw         $v1, %gp_rel(D_8009B2A0)($gp)
    /* 200D4 8002F8D4 00000000 */  nop
    /* 200D8 8002F8D8 05006010 */  beqz       $v1, .L8002F8F0
    /* 200DC 8002F8DC 00000000 */   nop
    /* 200E0 8002F8E0 08006294 */  lhu        $v0, 0x8($v1)
    /* 200E4 8002F8E4 00000000 */  nop
    /* 200E8 8002F8E8 40004234 */  ori        $v0, $v0, 0x40
    /* 200EC 8002F8EC 080062A4 */  sh         $v0, 0x8($v1)
  .L8002F8F0:
    /* 200F0 8002F8F0 7803848F */  lw         $a0, %gp_rel(D_8009B280)($gp)
    /* 200F4 8002F8F4 DB00010C */  jal        func_8004036C
    /* 200F8 8002F8F8 00000000 */   nop
    /* 200FC 8002F8FC 0F80043C */  lui        $a0, %hi(D_800EAE98)
    /* 20100 8002F900 03B8000C */  jal        func_8002E00C
    /* 20104 8002F904 98AE8424 */   addiu     $a0, $a0, %lo(D_800EAE98)
    /* 20108 8002F908 740380A7 */  sh         $zero, %gp_rel(D_8009B27C)($gp)
  .L8002F90C:
    /* 2010C 8002F90C 4000BF8F */  lw         $ra, 0x40($sp)
    /* 20110 8002F910 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 20114 8002F914 3800B48F */  lw         $s4, 0x38($sp)
    /* 20118 8002F918 3400B38F */  lw         $s3, 0x34($sp)
    /* 2011C 8002F91C 3000B28F */  lw         $s2, 0x30($sp)
    /* 20120 8002F920 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 20124 8002F924 2800B08F */  lw         $s0, 0x28($sp)
    /* 20128 8002F928 0800E003 */  jr         $ra
    /* 2012C 8002F92C 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_8002F630
