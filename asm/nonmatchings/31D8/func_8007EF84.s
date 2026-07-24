nonmatching func_8007EF84, 0x3C0

glabel func_8007EF84
    /* 6F784 8007EF84 0000A4AF */  sw         $a0, 0x0($sp)
    /* 6F788 8007EF88 0400A5AF */  sw         $a1, 0x4($sp)
    /* 6F78C 8007EF8C 0800A6AF */  sw         $a2, 0x8($sp)
    /* 6F790 8007EF90 0C00A7AF */  sw         $a3, 0xC($sp)
    /* 6F794 8007EF94 C8FDBD27 */  addiu      $sp, $sp, -0x238
    /* 6F798 8007EF98 3C02A227 */  addiu      $v0, $sp, 0x23C
    /* 6F79C 8007EF9C 3002BFAF */  sw         $ra, 0x230($sp)
    /* 6F7A0 8007EFA0 2C02B5AF */  sw         $s5, 0x22C($sp)
    /* 6F7A4 8007EFA4 2802B4AF */  sw         $s4, 0x228($sp)
    /* 6F7A8 8007EFA8 2402B3AF */  sw         $s3, 0x224($sp)
    /* 6F7AC 8007EFAC 2002B2AF */  sw         $s2, 0x220($sp)
    /* 6F7B0 8007EFB0 1C02B1AF */  sw         $s1, 0x21C($sp)
    /* 6F7B4 8007EFB4 1802B0AF */  sw         $s0, 0x218($sp)
    /* 6F7B8 8007EFB8 3802A4AF */  sw         $a0, 0x238($sp)
    /* 6F7BC 8007EFBC 07008004 */  bltz       $a0, .L8007EFDC
    /* 6F7C0 8007EFC0 1002A2AF */   sw        $v0, 0x210($sp)
    /* 6F7C4 8007EFC4 0980023C */  lui        $v0, %hi(D_80093C08)
    /* 6F7C8 8007EFC8 083C428C */  lw         $v0, %lo(D_80093C08)($v0)
    /* 6F7CC 8007EFCC 00000000 */  nop
    /* 6F7D0 8007EFD0 2A108200 */  slt        $v0, $a0, $v0
    /* 6F7D4 8007EFD4 0F004014 */  bnez       $v0, .L8007F014
    /* 6F7D8 8007EFD8 4002A227 */   addiu     $v0, $sp, 0x240
  .L8007EFDC:
    /* 6F7DC 8007EFDC 0980023C */  lui        $v0, %hi(D_80093C0C)
    /* 6F7E0 8007EFE0 0C3C428C */  lw         $v0, %lo(D_80093C0C)($v0)
    /* 6F7E4 8007EFE4 00000000 */  nop
    /* 6F7E8 8007EFE8 40180200 */  sll        $v1, $v0, 1
    /* 6F7EC 8007EFEC 21186200 */  addu       $v1, $v1, $v0
    /* 6F7F0 8007EFF0 00190300 */  sll        $v1, $v1, 4
    /* 6F7F4 8007EFF4 0980013C */  lui        $at, %hi(D_80093AAC)
    /* 6F7F8 8007EFF8 21082300 */  addu       $at, $at, $v1
    /* 6F7FC 8007EFFC AC3A238C */  lw         $v1, %lo(D_80093AAC)($at)
    /* 6F800 8007F000 21988000 */  addu       $s3, $a0, $zero
    /* 6F804 8007F004 05006014 */  bnez       $v1, .L8007F01C
    /* 6F808 8007F008 3802A2AF */   sw        $v0, 0x238($sp)
  .L8007F00C:
    /* 6F80C 8007F00C C8FC0108 */  j          .L8007F320
    /* 6F810 8007F010 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8007F014:
    /* 6F814 8007F014 3C02B38F */  lw         $s3, 0x23C($sp)
    /* 6F818 8007F018 1002A2AF */  sw         $v0, 0x210($sp)
  .L8007F01C:
    /* 6F81C 8007F01C 3802A38F */  lw         $v1, 0x238($sp)
    /* 6F820 8007F020 00000000 */  nop
    /* 6F824 8007F024 40100300 */  sll        $v0, $v1, 1
    /* 6F828 8007F028 21104300 */  addu       $v0, $v0, $v1
    /* 6F82C 8007F02C 00110200 */  sll        $v0, $v0, 4
    /* 6F830 8007F030 0980033C */  lui        $v1, %hi(D_80093A88)
    /* 6F834 8007F034 883A6324 */  addiu      $v1, $v1, %lo(D_80093A88)
    /* 6F838 8007F038 21884300 */  addu       $s1, $v0, $v1
    /* 6F83C 8007F03C 2800238E */  lw         $v1, 0x28($s1)
    /* 6F840 8007F040 1C00228E */  lw         $v0, 0x1C($s1)
    /* 6F844 8007F044 00000000 */  nop
    /* 6F848 8007F048 2A104300 */  slt        $v0, $v0, $v1
    /* 6F84C 8007F04C EFFF4014 */  bnez       $v0, .L8007F00C
    /* 6F850 8007F050 00000000 */   nop
    /* 6F854 8007F054 00006482 */  lb         $a0, 0x0($s3)
    /* 6F858 8007F058 00000000 */  nop
    /* 6F85C 8007F05C AA008010 */  beqz       $a0, .L8007F308
    /* 6F860 8007F060 00000000 */   nop
    /* 6F864 8007F064 25001424 */  addiu      $s4, $zero, 0x25
    /* 6F868 8007F068 CCCC153C */  lui        $s5, (0xCCCCCCCD >> 16)
    /* 6F86C 8007F06C CDCCB536 */  ori        $s5, $s5, (0xCCCCCCCD & 0xFFFF)
  .L8007F070:
    /* 6F870 8007F070 06009414 */  bne        $a0, $s4, .L8007F08C
    /* 6F874 8007F074 00000000 */   nop
    /* 6F878 8007F078 01007326 */  addiu      $s3, $s3, 0x1
    /* 6F87C 8007F07C 00006482 */  lb         $a0, 0x0($s3)
    /* 6F880 8007F080 00000000 */  nop
    /* 6F884 8007F084 0D009414 */  bne        $a0, $s4, .L8007F0BC
    /* 6F888 8007F088 21900000 */   addu      $s2, $zero, $zero
  .L8007F08C:
    /* 6F88C 8007F08C 2800228E */  lw         $v0, 0x28($s1)
    /* 6F890 8007F090 2400238E */  lw         $v1, 0x24($s1)
    /* 6F894 8007F094 00000000 */  nop
    /* 6F898 8007F098 21186200 */  addu       $v1, $v1, $v0
    /* 6F89C 8007F09C 000064A0 */  sb         $a0, 0x0($v1)
    /* 6F8A0 8007F0A0 1C00238E */  lw         $v1, 0x1C($s1)
    /* 6F8A4 8007F0A4 01004224 */  addiu      $v0, $v0, 0x1
    /* 6F8A8 8007F0A8 2A186200 */  slt        $v1, $v1, $v0
    /* 6F8AC 8007F0AC 91006010 */  beqz       $v1, .L8007F2F4
    /* 6F8B0 8007F0B0 280022AE */   sw        $v0, 0x28($s1)
    /* 6F8B4 8007F0B4 C8FC0108 */  j          .L8007F320
    /* 6F8B8 8007F0B8 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8007F0BC:
    /* 6F8BC 8007F0BC 30008238 */  xori       $v0, $a0, 0x30
    /* 6F8C0 8007F0C0 0100422C */  sltiu      $v0, $v0, 0x1
    /* 6F8C4 8007F0C4 3AFC0108 */  j          .L8007F0E8
    /* 6F8C8 8007F0C8 21304000 */   addu      $a2, $v0, $zero
  .L8007F0CC:
    /* 6F8CC 8007F0CC 21105200 */  addu       $v0, $v0, $s2
    /* 6F8D0 8007F0D0 40100200 */  sll        $v0, $v0, 1
    /* 6F8D4 8007F0D4 D0FF4224 */  addiu      $v0, $v0, -0x30
    /* 6F8D8 8007F0D8 21904400 */  addu       $s2, $v0, $a0
    /* 6F8DC 8007F0DC 01007326 */  addiu      $s3, $s3, 0x1
    /* 6F8E0 8007F0E0 00006482 */  lb         $a0, 0x0($s3)
    /* 6F8E4 8007F0E4 00000000 */  nop
  .L8007F0E8:
    /* 6F8E8 8007F0E8 D0FF8224 */  addiu      $v0, $a0, -0x30
    /* 6F8EC 8007F0EC 0A00422C */  sltiu      $v0, $v0, 0xA
    /* 6F8F0 8007F0F0 F6FF4014 */  bnez       $v0, .L8007F0CC
    /* 6F8F4 8007F0F4 80101200 */   sll       $v0, $s2, 2
    /* 6F8F8 8007F0F8 0200401E */  bgtz       $s2, .L8007F104
    /* 6F8FC 8007F0FC A8FF8324 */   addiu     $v1, $a0, -0x58
    /* 6F900 8007F100 01001224 */  addiu      $s2, $zero, 0x1
  .L8007F104:
    /* 6F904 8007F104 2100622C */  sltiu      $v0, $v1, 0x21
    /* 6F908 8007F108 56004010 */  beqz       $v0, .L8007F264
    /* 6F90C 8007F10C 1002B027 */   addiu     $s0, $sp, 0x210
    /* 6F910 8007F110 80100300 */  sll        $v0, $v1, 2
    /* 6F914 8007F114 0180013C */  lui        $at, %hi(jtbl_800120C0)
    /* 6F918 8007F118 21082200 */  addu       $at, $at, $v0
    /* 6F91C 8007F11C C020228C */  lw         $v0, %lo(jtbl_800120C0)($at)
    /* 6F920 8007F120 00000000 */  nop
    /* 6F924 8007F124 08004000 */  jr         $v0
    /* 6F928 8007F128 00000000 */   nop
  jlabel .L8007F12C
    /* 6F92C 8007F12C 1002A28F */  lw         $v0, 0x210($sp)
    /* 6F930 8007F130 00000000 */  nop
    /* 6F934 8007F134 0000448C */  lw         $a0, 0x0($v0)
    /* 6F938 8007F138 04004224 */  addiu      $v0, $v0, 0x4
    /* 6F93C 8007F13C 04008104 */  bgez       $a0, .L8007F150
    /* 6F940 8007F140 1002A2AF */   sw        $v0, 0x210($sp)
    /* 6F944 8007F144 23200400 */  negu       $a0, $a0
    /* 6F948 8007F148 55FC0108 */  j          .L8007F154
    /* 6F94C 8007F14C 2D000624 */   addiu     $a2, $zero, 0x2D
  .L8007F150:
    /* 6F950 8007F150 21300000 */  addu       $a2, $zero, $zero
  .L8007F154:
    /* 6F954 8007F154 21280000 */  addu       $a1, $zero, $zero
  .L8007F158:
    /* 6F958 8007F158 19009500 */  multu      $a0, $s5
    /* 6F95C 8007F15C FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 6F960 8007F160 0100A524 */  addiu      $a1, $a1, 0x1
    /* 6F964 8007F164 10380000 */  mfhi       $a3
    /* 6F968 8007F168 C2180700 */  srl        $v1, $a3, 3
    /* 6F96C 8007F16C 80100300 */  sll        $v0, $v1, 2
    /* 6F970 8007F170 21104300 */  addu       $v0, $v0, $v1
    /* 6F974 8007F174 40100200 */  sll        $v0, $v0, 1
    /* 6F978 8007F178 23108200 */  subu       $v0, $a0, $v0
    /* 6F97C 8007F17C 30004224 */  addiu      $v0, $v0, 0x30
    /* 6F980 8007F180 000002A2 */  sb         $v0, 0x0($s0)
    /* 6F984 8007F184 F4FFA010 */  beqz       $a1, .L8007F158
    /* 6F988 8007F188 21206000 */   addu      $a0, $v1, $zero
    /* 6F98C 8007F18C F2FF8014 */  bnez       $a0, .L8007F158
    /* 6F990 8007F190 00000000 */   nop
    /* 6F994 8007F194 3400C010 */  beqz       $a2, .L8007F268
    /* 6F998 8007F198 2A10B200 */   slt       $v0, $a1, $s2
    /* 6F99C 8007F19C FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 6F9A0 8007F1A0 000006A2 */  sb         $a2, 0x0($s0)
    /* 6F9A4 8007F1A4 99FC0108 */  j          .L8007F264
    /* 6F9A8 8007F1A8 0100A524 */   addiu     $a1, $a1, 0x1
  jlabel .L8007F1AC
    /* 6F9AC 8007F1AC 1002A28F */  lw         $v0, 0x210($sp)
    /* 6F9B0 8007F1B0 21280000 */  addu       $a1, $zero, $zero
    /* 6F9B4 8007F1B4 0000448C */  lw         $a0, 0x0($v0)
    /* 6F9B8 8007F1B8 04004224 */  addiu      $v0, $v0, 0x4
    /* 6F9BC 8007F1BC 1002A2AF */  sw         $v0, 0x210($sp)
  .L8007F1C0:
    /* 6F9C0 8007F1C0 FFFF1026 */  addiu      $s0, $s0, -0x1
  .L8007F1C4:
    /* 6F9C4 8007F1C4 0F008230 */  andi       $v0, $a0, 0xF
    /* 6F9C8 8007F1C8 0980033C */  lui        $v1, %hi(D_80094614)
    /* 6F9CC 8007F1CC 1446638C */  lw         $v1, %lo(D_80094614)($v1)
    /* 6F9D0 8007F1D0 02210400 */  srl        $a0, $a0, 4
    /* 6F9D4 8007F1D4 21186200 */  addu       $v1, $v1, $v0
    /* 6F9D8 8007F1D8 00006290 */  lbu        $v0, 0x0($v1)
    /* 6F9DC 8007F1DC 0100A524 */  addiu      $a1, $a1, 0x1
    /* 6F9E0 8007F1E0 F7FFA010 */  beqz       $a1, .L8007F1C0
    /* 6F9E4 8007F1E4 000002A2 */   sb        $v0, 0x0($s0)
    /* 6F9E8 8007F1E8 F6FF8014 */  bnez       $a0, .L8007F1C4
    /* 6F9EC 8007F1EC FFFF1026 */   addiu     $s0, $s0, -0x1
    /* 6F9F0 8007F1F0 01001026 */  addiu      $s0, $s0, 0x1
    /* 6F9F4 8007F1F4 2110C000 */  addu       $v0, $a2, $zero
    /* 6F9F8 8007F1F8 1A004010 */  beqz       $v0, .L8007F264
    /* 6F9FC 8007F1FC 2A10B200 */   slt       $v0, $a1, $s2
    /* 6FA00 8007F200 29004010 */  beqz       $v0, .L8007F2A8
    /* 6FA04 8007F204 30000324 */   addiu     $v1, $zero, 0x30
  .L8007F208:
    /* 6FA08 8007F208 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 6FA0C 8007F20C 0100A524 */  addiu      $a1, $a1, 0x1
    /* 6FA10 8007F210 2A10B200 */  slt        $v0, $a1, $s2
    /* 6FA14 8007F214 FCFF4014 */  bnez       $v0, .L8007F208
    /* 6FA18 8007F218 000003A2 */   sb        $v1, 0x0($s0)
    /* 6FA1C 8007F21C 9AFC0108 */  j          .L8007F268
    /* 6FA20 8007F220 00000000 */   nop
  jlabel .L8007F224
    /* 6FA24 8007F224 FFFF1026 */  addiu      $s0, $s0, -0x1
    /* 6FA28 8007F228 1002A28F */  lw         $v0, 0x210($sp)
    /* 6FA2C 8007F22C 01000524 */  addiu      $a1, $zero, 0x1
    /* 6FA30 8007F230 00004390 */  lbu        $v1, 0x0($v0)
    /* 6FA34 8007F234 04004224 */  addiu      $v0, $v0, 0x4
    /* 6FA38 8007F238 000003A2 */  sb         $v1, 0x0($s0)
    /* 6FA3C 8007F23C 99FC0108 */  j          .L8007F264
    /* 6FA40 8007F240 1002A2AF */   sw        $v0, 0x210($sp)
  jlabel .L8007F244
    /* 6FA44 8007F244 1002A28F */  lw         $v0, 0x210($sp)
    /* 6FA48 8007F248 00000000 */  nop
    /* 6FA4C 8007F24C 0000508C */  lw         $s0, 0x0($v0)
    /* 6FA50 8007F250 04004224 */  addiu      $v0, $v0, 0x4
    /* 6FA54 8007F254 1002A2AF */  sw         $v0, 0x210($sp)
    /* 6FA58 8007F258 D039020C */  jal        func_8008E740
    /* 6FA5C 8007F25C 21200002 */   addu      $a0, $s0, $zero
    /* 6FA60 8007F260 21284000 */  addu       $a1, $v0, $zero
  jlabel .L8007F264
    /* 6FA64 8007F264 2A10B200 */  slt        $v0, $a1, $s2
  .L8007F268:
    /* 6FA68 8007F268 0F004010 */  beqz       $v0, .L8007F2A8
    /* 6FA6C 8007F26C 20000424 */   addiu     $a0, $zero, 0x20
  .L8007F270:
    /* 6FA70 8007F270 2800228E */  lw         $v0, 0x28($s1)
    /* 6FA74 8007F274 2400238E */  lw         $v1, 0x24($s1)
    /* 6FA78 8007F278 00000000 */  nop
    /* 6FA7C 8007F27C 21186200 */  addu       $v1, $v1, $v0
    /* 6FA80 8007F280 000064A0 */  sb         $a0, 0x0($v1)
    /* 6FA84 8007F284 1C00238E */  lw         $v1, 0x1C($s1)
    /* 6FA88 8007F288 01004224 */  addiu      $v0, $v0, 0x1
    /* 6FA8C 8007F28C 2A186200 */  slt        $v1, $v1, $v0
    /* 6FA90 8007F290 5EFF6014 */  bnez       $v1, .L8007F00C
    /* 6FA94 8007F294 280022AE */   sw        $v0, 0x28($s1)
    /* 6FA98 8007F298 FFFF5226 */  addiu      $s2, $s2, -0x1
    /* 6FA9C 8007F29C 2A10B200 */  slt        $v0, $a1, $s2
    /* 6FAA0 8007F2A0 F3FF4014 */  bnez       $v0, .L8007F270
    /* 6FAA4 8007F2A4 00000000 */   nop
  .L8007F2A8:
    /* 6FAA8 8007F2A8 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 6FAAC 8007F2AC FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 6FAB0 8007F2B0 1000A210 */  beq        $a1, $v0, .L8007F2F4
    /* 6FAB4 8007F2B4 00000000 */   nop
    /* 6FAB8 8007F2B8 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L8007F2BC:
    /* 6FABC 8007F2BC 2800238E */  lw         $v1, 0x28($s1)
    /* 6FAC0 8007F2C0 2400228E */  lw         $v0, 0x24($s1)
    /* 6FAC4 8007F2C4 00000492 */  lbu        $a0, 0x0($s0)
    /* 6FAC8 8007F2C8 01001026 */  addiu      $s0, $s0, 0x1
    /* 6FACC 8007F2CC 21104300 */  addu       $v0, $v0, $v1
    /* 6FAD0 8007F2D0 000044A0 */  sb         $a0, 0x0($v0)
    /* 6FAD4 8007F2D4 1C00228E */  lw         $v0, 0x1C($s1)
    /* 6FAD8 8007F2D8 01006324 */  addiu      $v1, $v1, 0x1
    /* 6FADC 8007F2DC 2A104300 */  slt        $v0, $v0, $v1
    /* 6FAE0 8007F2E0 4AFF4014 */  bnez       $v0, .L8007F00C
    /* 6FAE4 8007F2E4 280023AE */   sw        $v1, 0x28($s1)
    /* 6FAE8 8007F2E8 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 6FAEC 8007F2EC F3FFA614 */  bne        $a1, $a2, .L8007F2BC
    /* 6FAF0 8007F2F0 00000000 */   nop
  .L8007F2F4:
    /* 6FAF4 8007F2F4 01007326 */  addiu      $s3, $s3, 0x1
    /* 6FAF8 8007F2F8 00006482 */  lb         $a0, 0x0($s3)
    /* 6FAFC 8007F2FC 00000000 */  nop
    /* 6FB00 8007F300 5BFF8014 */  bnez       $a0, .L8007F070
    /* 6FB04 8007F304 00000000 */   nop
  .L8007F308:
    /* 6FB08 8007F308 2400228E */  lw         $v0, 0x24($s1)
    /* 6FB0C 8007F30C 2800238E */  lw         $v1, 0x28($s1)
    /* 6FB10 8007F310 00000000 */  nop
    /* 6FB14 8007F314 21104300 */  addu       $v0, $v0, $v1
    /* 6FB18 8007F318 000040A0 */  sb         $zero, 0x0($v0)
    /* 6FB1C 8007F31C 2800228E */  lw         $v0, 0x28($s1)
  .L8007F320:
    /* 6FB20 8007F320 3002BF8F */  lw         $ra, 0x230($sp)
    /* 6FB24 8007F324 2C02B58F */  lw         $s5, 0x22C($sp)
    /* 6FB28 8007F328 2802B48F */  lw         $s4, 0x228($sp)
    /* 6FB2C 8007F32C 2402B38F */  lw         $s3, 0x224($sp)
    /* 6FB30 8007F330 2002B28F */  lw         $s2, 0x220($sp)
    /* 6FB34 8007F334 1C02B18F */  lw         $s1, 0x21C($sp)
    /* 6FB38 8007F338 1802B08F */  lw         $s0, 0x218($sp)
    /* 6FB3C 8007F33C 0800E003 */  jr         $ra
    /* 6FB40 8007F340 3802BD27 */   addiu     $sp, $sp, 0x238
endlabel func_8007EF84
    /* 6FB44 8007F344 00000000 */  nop
    /* 6FB48 8007F348 00000000 */  nop
    /* 6FB4C 8007F34C 00000000 */  nop
