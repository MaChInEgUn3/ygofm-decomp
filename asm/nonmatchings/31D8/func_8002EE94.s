nonmatching func_8002EE94, 0x59C

glabel func_8002EE94
    /* 1F694 8002EE94 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1F698 8002EE98 2800BFAF */  sw         $ra, 0x28($sp)
    /* 1F69C 8002EE9C 2400B1AF */  sw         $s1, 0x24($sp)
    /* 1F6A0 8002EEA0 EDB8000C */  jal        func_8002E3B4
    /* 1F6A4 8002EEA4 2000B0AF */   sw        $s0, 0x20($sp)
    /* 1F6A8 8002EEA8 1F004014 */  bnez       $v0, .L8002EF28
    /* 1F6AC 8002EEAC 21200000 */   addu      $a0, $zero, $zero
    /* 1F6B0 8002EEB0 02000524 */  addiu      $a1, $zero, 0x2
    /* 1F6B4 8002EEB4 8803838F */  lw         $v1, %gp_rel(D_8009B290)($gp)
    /* 1F6B8 8002EEB8 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 1F6BC 8002EEBC 0A80013C */  lui        $at, %hi(D_8009B34D)
    /* 1F6C0 8002EEC0 4DB322A0 */  sb         $v0, %lo(D_8009B34D)($at)
    /* 1F6C4 8002EEC4 21386500 */  addu       $a3, $v1, $a1
    /* 1F6C8 8002EEC8 880387AF */  sw         $a3, %gp_rel(D_8009B290)($gp)
    /* 1F6CC 8002EECC 00006890 */  lbu        $t0, 0x0($v1)
    /* 1F6D0 8002EED0 01006690 */  lbu        $a2, 0x1($v1)
    /* 1F6D4 8002EED4 04006224 */  addiu      $v0, $v1, 0x4
    /* 1F6D8 8002EED8 880382AF */  sw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1F6DC 8002EEDC 0100E290 */  lbu        $v0, 0x1($a3)
    /* 1F6E0 8002EEE0 02006390 */  lbu        $v1, 0x2($v1)
    /* 1F6E4 8002EEE4 00120200 */  sll        $v0, $v0, 8
    /* 1F6E8 8002EEE8 25186200 */  or         $v1, $v1, $v0
    /* 1F6EC 8002EEEC 00320600 */  sll        $a2, $a2, 8
    /* 1F6F0 8002EEF0 9E0383A7 */  sh         $v1, %gp_rel(D_8009B2A4 + 0x2)($gp)
    /* 1F6F4 8002EEF4 ABED000C */  jal        func_8003B6AC
    /* 1F6F8 8002EEF8 25800601 */   or        $s0, $t0, $a2
    /* 1F6FC 8002EEFC 21200000 */  addu       $a0, $zero, $zero
    /* 1F700 8002EF00 21280002 */  addu       $a1, $s0, $zero
    /* 1F704 8002EF04 10000624 */  addiu      $a2, $zero, 0x10
    /* 1F708 8002EF08 B0000724 */  addiu      $a3, $zero, 0xB0
    /* 1F70C 8002EF0C 20010224 */  addiu      $v0, $zero, 0x120
    /* 1F710 8002EF10 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1F714 8002EF14 30000224 */  addiu      $v0, $zero, 0x30
    /* 1F718 8002EF18 F9D6000C */  jal        func_80035BE4
    /* 1F71C 8002EF1C 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1F720 8002EF20 79BC0008 */  j          .L8002F1E4
    /* 1F724 8002EF24 00000000 */   nop
  .L8002EF28:
    /* 1F728 8002EF28 74038297 */  lhu        $v0, %gp_rel(D_8009B27C)($gp)
    /* 1F72C 8002EF2C 00000000 */  nop
    /* 1F730 8002EF30 80004230 */  andi       $v0, $v0, 0x80
    /* 1F734 8002EF34 10004010 */  beqz       $v0, .L8002EF78
    /* 1F738 8002EF38 00000000 */   nop
    /* 1F73C 8002EF3C C3FD000C */  jal        func_8003F70C
    /* 1F740 8002EF40 00000000 */   nop
    /* 1F744 8002EF44 35014010 */  beqz       $v0, .L8002F41C
    /* 1F748 8002EF48 04000224 */   addiu     $v0, $zero, 0x4
    /* 1F74C 8002EF4C 74038397 */  lhu        $v1, %gp_rel(D_8009B27C)($gp)
    /* 1F750 8002EF50 0A80013C */  lui        $at, %hi(D_8009B345)
    /* 1F754 8002EF54 45B322A0 */  sb         $v0, %lo(D_8009B345)($at)
    /* 1F758 8002EF58 0A80013C */  lui        $at, %hi(D_8009B34D)
    /* 1F75C 8002EF5C 4DB320A0 */  sb         $zero, %lo(D_8009B34D)($at)
    /* 1F760 8002EF60 0A80013C */  lui        $at, %hi(D_8009B34C)
    /* 1F764 8002EF64 4CB320A0 */  sb         $zero, %lo(D_8009B34C)($at)
    /* 1F768 8002EF68 7FFF6330 */  andi       $v1, $v1, 0xFF7F
    /* 1F76C 8002EF6C 740383A7 */  sh         $v1, %gp_rel(D_8009B27C)($gp)
    /* 1F770 8002EF70 07BD0008 */  j          .L8002F41C
    /* 1F774 8002EF74 00000000 */   nop
  .L8002EF78:
    /* 1F778 8002EF78 E5E5000C */  jal        func_80039794
    /* 1F77C 8002EF7C 00000000 */   nop
    /* 1F780 8002EF80 74038397 */  lhu        $v1, %gp_rel(D_8009B27C)($gp)
    /* 1F784 8002EF84 00000000 */  nop
    /* 1F788 8002EF88 00406230 */  andi       $v0, $v1, 0x4000
    /* 1F78C 8002EF8C 3F004014 */  bnez       $v0, .L8002F08C
    /* 1F790 8002EF90 0F80023C */   lui       $v0, %hi(D_800EB224)
    /* 1F794 8002EF94 0F80023C */  lui        $v0, %hi(D_800EB0F8)
    /* 1F798 8002EF98 F8B04424 */  addiu      $a0, $v0, %lo(D_800EB0F8)
    /* 1F79C 8002EF9C 34008294 */  lhu        $v0, 0x34($a0)
    /* 1F7A0 8002EFA0 00000000 */  nop
    /* 1F7A4 8002EFA4 00204230 */  andi       $v0, $v0, 0x2000
    /* 1F7A8 8002EFA8 1C014010 */  beqz       $v0, .L8002F41C
    /* 1F7AC 8002EFAC 00000000 */   nop
    /* 1F7B0 8002EFB0 D7DC000C */  jal        func_8003735C
    /* 1F7B4 8002EFB4 00000000 */   nop
    /* 1F7B8 8002EFB8 18014014 */  bnez       $v0, .L8002F41C
    /* 1F7BC 8002EFBC 00000000 */   nop
    /* 1F7C0 8002EFC0 74038297 */  lhu        $v0, %gp_rel(D_8009B27C)($gp)
    /* 1F7C4 8002EFC4 00000000 */  nop
    /* 1F7C8 8002EFC8 00404234 */  ori        $v0, $v0, 0x4000
    /* 1F7CC 8002EFCC 740382A7 */  sh         $v0, %gp_rel(D_8009B27C)($gp)
    /* 1F7D0 8002EFD0 97BB000C */  jal        func_8002EE5C
    /* 1F7D4 8002EFD4 00000000 */   nop
    /* 1F7D8 8002EFD8 09004014 */  bnez       $v0, .L8002F000
    /* 1F7DC 8002EFDC 21200000 */   addu      $a0, $zero, $zero
    /* 1F7E0 8002EFE0 74038297 */  lhu        $v0, %gp_rel(D_8009B27C)($gp)
    /* 1F7E4 8002EFE4 00000000 */  nop
    /* 1F7E8 8002EFE8 00024234 */  ori        $v0, $v0, 0x200
    /* 1F7EC 8002EFEC 740382A7 */  sh         $v0, %gp_rel(D_8009B27C)($gp)
    /* 1F7F0 8002EFF0 B8FF000C */  jal        func_8003FEE0
    /* 1F7F4 8002EFF4 2A000424 */   addiu     $a0, $zero, 0x2A
    /* 1F7F8 8002EFF8 07BD0008 */  j          .L8002F41C
    /* 1F7FC 8002EFFC 00000000 */   nop
  .L8002F000:
    /* 1F800 8002F000 ABED000C */  jal        func_8003B6AC
    /* 1F804 8002F004 02000524 */   addiu     $a1, $zero, 0x2
    /* 1F808 8002F008 03000424 */  addiu      $a0, $zero, 0x3
    /* 1F80C 8002F00C 11000524 */  addiu      $a1, $zero, 0x11
    /* 1F810 8002F010 70FF0624 */  addiu      $a2, $zero, -0x90
    /* 1F814 8002F014 38000724 */  addiu      $a3, $zero, 0x38
    /* 1F818 8002F018 78000224 */  addiu      $v0, $zero, 0x78
    /* 1F81C 8002F01C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1F820 8002F020 30000224 */  addiu      $v0, $zero, 0x30
    /* 1F824 8002F024 F9D6000C */  jal        func_80035BE4
    /* 1F828 8002F028 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1F82C 8002F02C 21804000 */  addu       $s0, $v0, $zero
    /* 1F830 8002F030 DCB8000C */  jal        func_8002E370
    /* 1F834 8002F034 21200002 */   addu      $a0, $s0, $zero
    /* 1F838 8002F038 34000296 */  lhu        $v0, 0x34($s0)
    /* 1F83C 8002F03C 00000000 */  nop
    /* 1F840 8002F040 24004234 */  ori        $v0, $v0, 0x24
    /* 1F844 8002F044 340002A6 */  sh         $v0, 0x34($s0)
  .L8002F048:
    /* 1F848 8002F048 E5E5000C */  jal        func_80039794
    /* 1F84C 8002F04C 00000000 */   nop
    /* 1F850 8002F050 3000028E */  lw         $v0, 0x30($s0)
    /* 1F854 8002F054 00000000 */  nop
    /* 1F858 8002F058 FBFF4010 */  beqz       $v0, .L8002F048
    /* 1F85C 8002F05C 00000000 */   nop
    /* 1F860 8002F060 2800048E */  lw         $a0, 0x28($s0)
    /* 1F864 8002F064 5E0C010C */  jal        func_80043178
    /* 1F868 8002F068 00000000 */   nop
    /* 1F86C 8002F06C 00FC0424 */  addiu      $a0, $zero, -0x400
    /* 1F870 8002F070 74038397 */  lhu        $v1, %gp_rel(D_8009B27C)($gp)
    /* 1F874 8002F074 2800028E */  lw         $v0, 0x28($s0)
    /* 1F878 8002F078 00606334 */  ori        $v1, $v1, 0x6000
    /* 1F87C 8002F07C 600044A4 */  sh         $a0, 0x60($v0)
    /* 1F880 8002F080 740383A7 */  sh         $v1, %gp_rel(D_8009B27C)($gp)
    /* 1F884 8002F084 07BD0008 */  j          .L8002F41C
    /* 1F888 8002F088 00000000 */   nop
  .L8002F08C:
    /* 1F88C 8002F08C 24B25024 */  addiu      $s0, $v0, %lo(D_800EB224)
    /* 1F890 8002F090 2800118E */  lw         $s1, 0x28($s0)
    /* 1F894 8002F094 00046230 */  andi       $v0, $v1, 0x400
    /* 1F898 8002F098 3E004010 */  beqz       $v0, .L8002F194
    /* 1F89C 8002F09C 00086230 */   andi      $v0, $v1, 0x800
    /* 1F8A0 8002F0A0 1B004014 */  bnez       $v0, .L8002F110
    /* 1F8A4 8002F0A4 0F80023C */   lui       $v0, %hi(D_800EB1C0)
    /* 1F8A8 8002F0A8 21200000 */  addu       $a0, $zero, $zero
    /* 1F8AC 8002F0AC 00086234 */  ori        $v0, $v1, 0x800
    /* 1F8B0 8002F0B0 740382A7 */  sh         $v0, %gp_rel(D_8009B27C)($gp)
    /* 1F8B4 8002F0B4 ABED000C */  jal        func_8003B6AC
    /* 1F8B8 8002F0B8 02000524 */   addiu     $a1, $zero, 0x2
    /* 1F8BC 8002F0BC 02000424 */  addiu      $a0, $zero, 0x2
    /* 1F8C0 8002F0C0 12000524 */  addiu      $a1, $zero, 0x12
    /* 1F8C4 8002F0C4 90000624 */  addiu      $a2, $zero, 0x90
    /* 1F8C8 8002F0C8 70000724 */  addiu      $a3, $zero, 0x70
    /* 1F8CC 8002F0CC 18000224 */  addiu      $v0, $zero, 0x18
    /* 1F8D0 8002F0D0 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1F8D4 8002F0D4 F9D6000C */  jal        func_80035BE4
    /* 1F8D8 8002F0D8 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1F8DC 8002F0DC 21804000 */  addu       $s0, $v0, $zero
    /* 1F8E0 8002F0E0 DCB8000C */  jal        func_8002E370
    /* 1F8E4 8002F0E4 21200002 */   addu      $a0, $s0, $zero
    /* 1F8E8 8002F0E8 34000296 */  lhu        $v0, 0x34($s0)
    /* 1F8EC 8002F0EC 00000000 */  nop
    /* 1F8F0 8002F0F0 20004234 */  ori        $v0, $v0, 0x20
    /* 1F8F4 8002F0F4 340002A6 */  sh         $v0, 0x34($s0)
  .L8002F0F8:
    /* 1F8F8 8002F0F8 E5E5000C */  jal        func_80039794
    /* 1F8FC 8002F0FC 00000000 */   nop
    /* 1F900 8002F100 3000028E */  lw         $v0, 0x30($s0)
    /* 1F904 8002F104 00000000 */  nop
    /* 1F908 8002F108 FBFF4010 */  beqz       $v0, .L8002F0F8
    /* 1F90C 8002F10C 0F80023C */   lui       $v0, %hi(D_800EB1C0)
  .L8002F110:
    /* 1F910 8002F110 C0B14424 */  addiu      $a0, $v0, %lo(D_800EB1C0)
    /* 1F914 8002F114 34008294 */  lhu        $v0, 0x34($a0)
    /* 1F918 8002F118 00000000 */  nop
    /* 1F91C 8002F11C 00204230 */  andi       $v0, $v0, 0x2000
    /* 1F920 8002F120 BE004010 */  beqz       $v0, .L8002F41C
    /* 1F924 8002F124 00000000 */   nop
    /* 1F928 8002F128 74038297 */  lhu        $v0, %gp_rel(D_8009B27C)($gp)
    /* 1F92C 8002F12C 00000000 */  nop
    /* 1F930 8002F130 FFF34230 */  andi       $v0, $v0, 0xF3FF
    /* 1F934 8002F134 740382A7 */  sh         $v0, %gp_rel(D_8009B27C)($gp)
    /* 1F938 8002F138 DFD6000C */  jal        func_80035B7C
    /* 1F93C 8002F13C 00000000 */   nop
    /* 1F940 8002F140 0A80023C */  lui        $v0, %hi(D_8009B34D)
    /* 1F944 8002F144 4DB34280 */  lb         $v0, %lo(D_8009B34D)($v0)
    /* 1F948 8002F148 00000000 */  nop
    /* 1F94C 8002F14C 09004010 */  beqz       $v0, .L8002F174
    /* 1F950 8002F150 01000224 */   addiu     $v0, $zero, 0x1
    /* 1F954 8002F154 0A80013C */  lui        $at, %hi(D_8009B268)
    /* 1F958 8002F158 68B222A0 */  sb         $v0, %lo(D_8009B268)($at)
    /* 1F95C 8002F15C 05000224 */  addiu      $v0, $zero, 0x5
    /* 1F960 8002F160 0A80013C */  lui        $at, %hi(D_8009B26D)
    /* 1F964 8002F164 6DB222A0 */  sb         $v0, %lo(D_8009B26D)($at)
    /* 1F968 8002F168 08000224 */  addiu      $v0, $zero, 0x8
    /* 1F96C 8002F16C 0A80013C */  lui        $at, %hi(D_8009B26C)
    /* 1F970 8002F170 6CB222A0 */  sb         $v0, %lo(D_8009B26C)($at)
  .L8002F174:
    /* 1F974 8002F174 04000224 */  addiu      $v0, $zero, 0x4
    /* 1F978 8002F178 0A80013C */  lui        $at, %hi(D_8009B345)
    /* 1F97C 8002F17C 45B322A0 */  sb         $v0, %lo(D_8009B345)($at)
    /* 1F980 8002F180 02000224 */  addiu      $v0, $zero, 0x2
    /* 1F984 8002F184 0A80013C */  lui        $at, %hi(D_8009B34D)
    /* 1F988 8002F188 4DB322A0 */  sb         $v0, %lo(D_8009B34D)($at)
    /* 1F98C 8002F18C 07BD0008 */  j          .L8002F41C
    /* 1F990 8002F190 00000000 */   nop
  .L8002F194:
    /* 1F994 8002F194 00026230 */  andi       $v0, $v1, 0x200
    /* 1F998 8002F198 28004010 */  beqz       $v0, .L8002F23C
    /* 1F99C 8002F19C 00086230 */   andi      $v0, $v1, 0x800
    /* 1F9A0 8002F1A0 14004014 */  bnez       $v0, .L8002F1F4
    /* 1F9A4 8002F1A4 21200000 */   addu      $a0, $zero, $zero
    /* 1F9A8 8002F1A8 00086234 */  ori        $v0, $v1, 0x800
    /* 1F9AC 8002F1AC 740382A7 */  sh         $v0, %gp_rel(D_8009B27C)($gp)
    /* 1F9B0 8002F1B0 ABED000C */  jal        func_8003B6AC
    /* 1F9B4 8002F1B4 02000524 */   addiu     $a1, $zero, 0x2
    /* 1F9B8 8002F1B8 21200000 */  addu       $a0, $zero, $zero
    /* 1F9BC 8002F1BC 1C000524 */  addiu      $a1, $zero, 0x1C
    /* 1F9C0 8002F1C0 10000624 */  addiu      $a2, $zero, 0x10
    /* 1F9C4 8002F1C4 B0000724 */  addiu      $a3, $zero, 0xB0
    /* 1F9C8 8002F1C8 20010224 */  addiu      $v0, $zero, 0x120
    /* 1F9CC 8002F1CC 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1F9D0 8002F1D0 24000224 */  addiu      $v0, $zero, 0x24
    /* 1F9D4 8002F1D4 1400A2AF */  sw         $v0, 0x14($sp)
    /* 1F9D8 8002F1D8 08100224 */  addiu      $v0, $zero, 0x1008
    /* 1F9DC 8002F1DC 0ED7000C */  jal        func_80035C38
    /* 1F9E0 8002F1E0 1800A2AF */   sw        $v0, 0x18($sp)
  .L8002F1E4:
    /* 1F9E4 8002F1E4 DCB8000C */  jal        func_8002E370
    /* 1F9E8 8002F1E8 21204000 */   addu      $a0, $v0, $zero
    /* 1F9EC 8002F1EC 07BD0008 */  j          .L8002F41C
    /* 1F9F0 8002F1F0 00000000 */   nop
  .L8002F1F4:
    /* 1F9F4 8002F1F4 08FF0296 */  lhu        $v0, -0xF8($s0)
    /* 1F9F8 8002F1F8 00000000 */  nop
    /* 1F9FC 8002F1FC 08004230 */  andi       $v0, $v0, 0x8
    /* 1FA00 8002F200 86004014 */  bnez       $v0, .L8002F41C
    /* 1FA04 8002F204 00000000 */   nop
    /* 1FA08 8002F208 B8FF000C */  jal        func_8003FEE0
    /* 1FA0C 8002F20C 08000424 */   addiu     $a0, $zero, 0x8
    /* 1FA10 8002F210 01000224 */  addiu      $v0, $zero, 0x1
    /* 1FA14 8002F214 0A80013C */  lui        $at, %hi(D_8009B268)
    /* 1FA18 8002F218 68B222A0 */  sb         $v0, %lo(D_8009B268)($at)
    /* 1FA1C 8002F21C 05000224 */  addiu      $v0, $zero, 0x5
    /* 1FA20 8002F220 0A80013C */  lui        $at, %hi(D_8009B26D)
    /* 1FA24 8002F224 6DB222A0 */  sb         $v0, %lo(D_8009B26D)($at)
    /* 1FA28 8002F228 08000224 */  addiu      $v0, $zero, 0x8
    /* 1FA2C 8002F22C 0A80013C */  lui        $at, %hi(D_8009B26C)
    /* 1FA30 8002F230 6CB222A0 */  sb         $v0, %lo(D_8009B26C)($at)
    /* 1FA34 8002F234 07BD0008 */  j          .L8002F41C
    /* 1FA38 8002F238 00000000 */   nop
  .L8002F23C:
    /* 1FA3C 8002F23C 00106230 */  andi       $v0, $v1, 0x1000
    /* 1FA40 8002F240 18004010 */  beqz       $v0, .L8002F2A4
    /* 1FA44 8002F244 00086230 */   andi      $v0, $v1, 0x800
    /* 1FA48 8002F248 07004014 */  bnez       $v0, .L8002F268
    /* 1FA4C 8002F24C 00086234 */   ori       $v0, $v1, 0x800
    /* 1FA50 8002F250 740382A7 */  sh         $v0, %gp_rel(D_8009B27C)($gp)
    /* 1FA54 8002F254 5E0C010C */  jal        func_80043178
    /* 1FA58 8002F258 21202002 */   addu      $a0, $s1, $zero
    /* 1FA5C 8002F25C 2800038E */  lw         $v1, 0x28($s0)
    /* 1FA60 8002F260 00040224 */  addiu      $v0, $zero, 0x400
    /* 1FA64 8002F264 600062A4 */  sh         $v0, 0x60($v1)
  .L8002F268:
    /* 1FA68 8002F268 60002296 */  lhu        $v0, 0x60($s1)
    /* 1FA6C 8002F26C 00000000 */  nop
    /* 1FA70 8002F270 C0FF4224 */  addiu      $v0, $v0, -0x40
    /* 1FA74 8002F274 600022A6 */  sh         $v0, 0x60($s1)
    /* 1FA78 8002F278 00140200 */  sll        $v0, $v0, 16
    /* 1FA7C 8002F27C 033C0200 */  sra        $a3, $v0, 16
    /* 1FA80 8002F280 0600E01C */  bgtz       $a3, .L8002F29C
    /* 1FA84 8002F284 21202002 */   addu      $a0, $s1, $zero
    /* 1FA88 8002F288 DFD6000C */  jal        func_80035B7C
    /* 1FA8C 8002F28C 21200002 */   addu      $a0, $s0, $zero
    /* 1FA90 8002F290 740380A7 */  sh         $zero, %gp_rel(D_8009B27C)($gp)
    /* 1FA94 8002F294 07BD0008 */  j          .L8002F41C
    /* 1FA98 8002F298 00000000 */   nop
  .L8002F29C:
    /* 1FA9C 8002F29C C1BC0008 */  j          .L8002F304
    /* 1FAA0 8002F2A0 70FF0524 */   addiu     $a1, $zero, -0x90
  .L8002F2A4:
    /* 1FAA4 8002F2A4 00206230 */  andi       $v0, $v1, 0x2000
    /* 1FAA8 8002F2A8 1E004010 */  beqz       $v0, .L8002F324
    /* 1FAAC 8002F2AC 00000000 */   nop
    /* 1FAB0 8002F2B0 60002296 */  lhu        $v0, 0x60($s1)
    /* 1FAB4 8002F2B4 00000000 */  nop
    /* 1FAB8 8002F2B8 40004224 */  addiu      $v0, $v0, 0x40
    /* 1FABC 8002F2BC 600022A6 */  sh         $v0, 0x60($s1)
    /* 1FAC0 8002F2C0 00140200 */  sll        $v0, $v0, 16
    /* 1FAC4 8002F2C4 033C0200 */  sra        $a3, $v0, 16
    /* 1FAC8 8002F2C8 0C00E004 */  bltz       $a3, .L8002F2FC
    /* 1FACC 8002F2CC 10000224 */   addiu     $v0, $zero, 0x10
    /* 1FAD0 8002F2D0 300022A6 */  sh         $v0, 0x30($s1)
    /* 1FAD4 8002F2D4 30002586 */  lh         $a1, 0x30($s1)
    /* 1FAD8 8002F2D8 38000224 */  addiu      $v0, $zero, 0x38
    /* 1FADC 8002F2DC 320022A6 */  sh         $v0, 0x32($s1)
    /* 1FAE0 8002F2E0 32002686 */  lh         $a2, 0x32($s1)
    /* 1FAE4 8002F2E4 FFDF6230 */  andi       $v0, $v1, 0xDFFF
    /* 1FAE8 8002F2E8 740382A7 */  sh         $v0, %gp_rel(D_8009B27C)($gp)
    /* 1FAEC 8002F2EC 4DE6000C */  jal        func_80039934
    /* 1FAF0 8002F2F0 21200002 */   addu      $a0, $s0, $zero
    /* 1FAF4 8002F2F4 07BD0008 */  j          .L8002F41C
    /* 1FAF8 8002F2F8 00000000 */   nop
  .L8002F2FC:
    /* 1FAFC 8002F2FC 21202002 */  addu       $a0, $s1, $zero
    /* 1FB00 8002F300 10000524 */  addiu      $a1, $zero, 0x10
  .L8002F304:
    /* 1FB04 8002F304 8C0C010C */  jal        func_80043230
    /* 1FB08 8002F308 38000624 */   addiu     $a2, $zero, 0x38
    /* 1FB0C 8002F30C 30002586 */  lh         $a1, 0x30($s1)
    /* 1FB10 8002F310 32002686 */  lh         $a2, 0x32($s1)
    /* 1FB14 8002F314 4DE6000C */  jal        func_80039934
    /* 1FB18 8002F318 21200002 */   addu      $a0, $s0, $zero
    /* 1FB1C 8002F31C 07BD0008 */  j          .L8002F41C
    /* 1FB20 8002F320 00000000 */   nop
  .L8002F324:
    /* 1FB24 8002F324 03DC000C */  jal        func_8003700C
    /* 1FB28 8002F328 21200002 */   addu      $a0, $s0, $zero
    /* 1FB2C 8002F32C 3B004014 */  bnez       $v0, .L8002F41C
    /* 1FB30 8002F330 00000000 */   nop
    /* 1FB34 8002F334 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* 1FB38 8002F338 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* 1FB3C 8002F33C 00000000 */  nop
    /* 1FB40 8002F340 C0004230 */  andi       $v0, $v0, 0xC0
    /* 1FB44 8002F344 35004010 */  beqz       $v0, .L8002F41C
    /* 1FB48 8002F348 1D80023C */   lui       $v0, %hi(D_801D0000)
    /* 1FB4C 8002F34C 9E038397 */  lhu        $v1, %gp_rel(D_8009B2A4 + 0x2)($gp)
    /* 1FB50 8002F350 00005024 */  addiu      $s0, $v0, %lo(D_801D0000)
    /* 1FB54 8002F354 DC0703A6 */  sh         $v1, 0x7DC($s0)
    /* 1FB58 8002F358 0A80033C */  lui        $v1, %hi(D_8009B34D)
    /* 1FB5C 8002F35C 4DB36380 */  lb         $v1, %lo(D_8009B34D)($v1)
    /* 1FB60 8002F360 01000224 */  addiu      $v0, $zero, 0x1
    /* 1FB64 8002F364 17006210 */  beq        $v1, $v0, .L8002F3C4
    /* 1FB68 8002F368 02006228 */   slti      $v0, $v1, 0x2
    /* 1FB6C 8002F36C 05004010 */  beqz       $v0, .L8002F384
    /* 1FB70 8002F370 00000000 */   nop
    /* 1FB74 8002F374 0B006010 */  beqz       $v1, .L8002F3A4
    /* 1FB78 8002F378 00000000 */   nop
    /* 1FB7C 8002F37C 07BD0008 */  j          .L8002F41C
    /* 1FB80 8002F380 00000000 */   nop
  .L8002F384:
    /* 1FB84 8002F384 02000224 */  addiu      $v0, $zero, 0x2
    /* 1FB88 8002F388 19006210 */  beq        $v1, $v0, .L8002F3F0
    /* 1FB8C 8002F38C 00000000 */   nop
    /* 1FB90 8002F390 03000224 */  addiu      $v0, $zero, 0x3
    /* 1FB94 8002F394 1B006210 */  beq        $v1, $v0, .L8002F404
    /* 1FB98 8002F398 00000000 */   nop
    /* 1FB9C 8002F39C 07BD0008 */  j          .L8002F41C
    /* 1FBA0 8002F3A0 00000000 */   nop
  .L8002F3A4:
    /* 1FBA4 8002F3A4 B8FF000C */  jal        func_8003FEE0
    /* 1FBA8 8002F3A8 07000424 */   addiu     $a0, $zero, 0x7
    /* 1FBAC 8002F3AC 9E038297 */  lhu        $v0, %gp_rel(D_8009B2A4 + 0x2)($gp)
    /* 1FBB0 8002F3B0 1FFE000C */  jal        func_8003F87C
    /* 1FBB4 8002F3B4 DC0702A6 */   sh        $v0, 0x7DC($s0)
    /* 1FBB8 8002F3B8 74038297 */  lhu        $v0, %gp_rel(D_8009B27C)($gp)
    /* 1FBBC 8002F3BC 06BD0008 */  j          .L8002F418
    /* 1FBC0 8002F3C0 80004234 */   ori       $v0, $v0, 0x80
  .L8002F3C4:
    /* 1FBC4 8002F3C4 B8FF000C */  jal        func_8003FEE0
    /* 1FBC8 8002F3C8 07000424 */   addiu     $a0, $zero, 0x7
    /* 1FBCC 8002F3CC 24CF000C */  jal        func_80033C90
    /* 1FBD0 8002F3D0 00000000 */   nop
    /* 1FBD4 8002F3D4 9E038393 */  lbu        $v1, %gp_rel(D_8009B2A4 + 0x2)($gp)
    /* 1FBD8 8002F3D8 02000224 */  addiu      $v0, $zero, 0x2
    /* 1FBDC 8002F3DC 0A80013C */  lui        $at, %hi(D_8009B269)
    /* 1FBE0 8002F3E0 69B222A0 */  sb         $v0, %lo(D_8009B269)($at)
    /* 1FBE4 8002F3E4 720383A3 */  sb         $v1, %gp_rel(D_8009B27A)($gp)
    /* 1FBE8 8002F3E8 07BD0008 */  j          .L8002F41C
    /* 1FBEC 8002F3EC 00000000 */   nop
  .L8002F3F0:
    /* 1FBF0 8002F3F0 B8FF000C */  jal        func_8003FEE0
    /* 1FBF4 8002F3F4 07000424 */   addiu     $a0, $zero, 0x7
    /* 1FBF8 8002F3F8 74038297 */  lhu        $v0, %gp_rel(D_8009B27C)($gp)
    /* 1FBFC 8002F3FC 06BD0008 */  j          .L8002F418
    /* 1FC00 8002F400 00044234 */   ori       $v0, $v0, 0x400
  .L8002F404:
    /* 1FC04 8002F404 B8FF000C */  jal        func_8003FEE0
    /* 1FC08 8002F408 08000424 */   addiu     $a0, $zero, 0x8
    /* 1FC0C 8002F40C 74038297 */  lhu        $v0, %gp_rel(D_8009B27C)($gp)
    /* 1FC10 8002F410 00000000 */  nop
    /* 1FC14 8002F414 00104234 */  ori        $v0, $v0, 0x1000
  .L8002F418:
    /* 1FC18 8002F418 740382A7 */  sh         $v0, %gp_rel(D_8009B27C)($gp)
  .L8002F41C:
    /* 1FC1C 8002F41C 2800BF8F */  lw         $ra, 0x28($sp)
    /* 1FC20 8002F420 2400B18F */  lw         $s1, 0x24($sp)
    /* 1FC24 8002F424 2000B08F */  lw         $s0, 0x20($sp)
    /* 1FC28 8002F428 0800E003 */  jr         $ra
    /* 1FC2C 8002F42C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8002EE94
