nonmatching func_8008E8B0, 0x694

glabel func_8008E8B0
    /* 7F0B0 8008E8B0 88FFBD27 */  addiu      $sp, $sp, -0x78
    /* 7F0B4 8008E8B4 5400B1AF */  sw         $s1, 0x54($sp)
    /* 7F0B8 8008E8B8 2188C000 */  addu       $s1, $a2, $zero
    /* 7F0BC 8008E8BC 7400BFAF */  sw         $ra, 0x74($sp)
    /* 7F0C0 8008E8C0 7000BEAF */  sw         $fp, 0x70($sp)
    /* 7F0C4 8008E8C4 6C00B7AF */  sw         $s7, 0x6C($sp)
    /* 7F0C8 8008E8C8 6800B6AF */  sw         $s6, 0x68($sp)
    /* 7F0CC 8008E8CC 6400B5AF */  sw         $s5, 0x64($sp)
    /* 7F0D0 8008E8D0 6000B4AF */  sw         $s4, 0x60($sp)
    /* 7F0D4 8008E8D4 5C00B3AF */  sw         $s3, 0x5C($sp)
    /* 7F0D8 8008E8D8 5800B2AF */  sw         $s2, 0x58($sp)
    /* 7F0DC 8008E8DC 0300A014 */  bnez       $a1, .L8008E8EC
    /* 7F0E0 8008E8E0 5000B0AF */   sw        $s0, 0x50($sp)
    /* 7F0E4 8008E8E4 C53B0208 */  j          .L8008EF14
    /* 7F0E8 8008E8E8 21100000 */   addu      $v0, $zero, $zero
  .L8008E8EC:
    /* 7F0EC 8008E8EC 21B8A000 */  addu       $s7, $a1, $zero
    /* 7F0F0 8008E8F0 0180073C */  lui        $a3, %hi(D_80012678)
    /* 7F0F4 8008E8F4 7826E724 */  addiu      $a3, $a3, %lo(D_80012678)
    /* 7F0F8 8008E8F8 4800A7AF */  sw         $a3, 0x48($sp)
    /* 7F0FC 8008E8FC 3800A0AF */  sw         $zero, 0x38($sp)
  .L8008E900:
    /* 7F100 8008E900 0000E492 */  lbu        $a0, 0x0($s7)
    /* 7F104 8008E904 00000000 */  nop
    /* 7F108 8008E908 75018010 */  beqz       $a0, .L8008EEE0
    /* 7F10C 8008E90C 25000224 */   addiu     $v0, $zero, 0x25
    /* 7F110 8008E910 7C018214 */  bne        $a0, $v0, .L8008EF04
    /* 7F114 8008E914 21980000 */   addu      $s3, $zero, $zero
    /* 7F118 8008E918 FFFF1424 */  addiu      $s4, $zero, -0x1
    /* 7F11C 8008E91C 21F00000 */  addu       $fp, $zero, $zero
    /* 7F120 8008E920 3C00A0AF */  sw         $zero, 0x3C($sp)
    /* 7F124 8008E924 4000A0AF */  sw         $zero, 0x40($sp)
    /* 7F128 8008E928 4400A0AF */  sw         $zero, 0x44($sp)
  .L8008E92C:
    /* 7F12C 8008E92C 0100F726 */  addiu      $s7, $s7, 0x1
    /* 7F130 8008E930 0000E392 */  lbu        $v1, 0x0($s7)
    /* 7F134 8008E934 00000000 */  nop
    /* 7F138 8008E938 7900622C */  sltiu      $v0, $v1, 0x79
    /* 7F13C 8008E93C 6D014010 */  beqz       $v0, .L8008EEF4
    /* 7F140 8008E940 80100300 */   sll       $v0, $v1, 2
    /* 7F144 8008E944 0180013C */  lui        $at, %hi(jtbl_800126A8)
    /* 7F148 8008E948 21082200 */  addu       $at, $at, $v0
    /* 7F14C 8008E94C A826228C */  lw         $v0, %lo(jtbl_800126A8)($at)
    /* 7F150 8008E950 00000000 */  nop
    /* 7F154 8008E954 08004000 */  jr         $v0
    /* 7F158 8008E958 00000000 */   nop
  jlabel .L8008E95C
    /* 7F15C 8008E95C F3FFC017 */  bnez       $fp, .L8008E92C
    /* 7F160 8008E960 00000000 */   nop
    /* 7F164 8008E964 4B3A0208 */  j          .L8008E92C
    /* 7F168 8008E968 20001E24 */   addiu     $fp, $zero, 0x20
  jlabel .L8008E96C
    /* 7F16C 8008E96C 4B3A0208 */  j          .L8008E92C
    /* 7F170 8008E970 08007336 */   ori       $s3, $s3, 0x8
  jlabel .L8008E974
    /* 7F174 8008E974 04003126 */  addiu      $s1, $s1, 0x4
    /* 7F178 8008E978 FCFF278E */  lw         $a3, -0x4($s1)
    /* 7F17C 8008E97C 00000000 */  nop
    /* 7F180 8008E980 EAFFE104 */  bgez       $a3, .L8008E92C
    /* 7F184 8008E984 4400A7AF */   sw        $a3, 0x44($sp)
    /* 7F188 8008E988 23380700 */  negu       $a3, $a3
    /* 7F18C 8008E98C 4400A7AF */  sw         $a3, 0x44($sp)
  jlabel .L8008E990
    /* 7F190 8008E990 4B3A0208 */  j          .L8008E92C
    /* 7F194 8008E994 10007336 */   ori       $s3, $s3, 0x10
  jlabel .L8008E998
    /* 7F198 8008E998 4B3A0208 */  j          .L8008E92C
    /* 7F19C 8008E99C 2B001E24 */   addiu     $fp, $zero, 0x2B
  jlabel .L8008E9A0
    /* 7F1A0 8008E9A0 0100F726 */  addiu      $s7, $s7, 0x1
    /* 7F1A4 8008E9A4 0000E392 */  lbu        $v1, 0x0($s7)
    /* 7F1A8 8008E9A8 2A000224 */  addiu      $v0, $zero, 0x2A
    /* 7F1AC 8008E9AC 05006214 */  bne        $v1, $v0, .L8008E9C4
    /* 7F1B0 8008E9B0 8000622C */   sltiu     $v0, $v1, 0x80
    /* 7F1B4 8008E9B4 04003126 */  addiu      $s1, $s1, 0x4
    /* 7F1B8 8008E9B8 FCFF308E */  lw         $s0, -0x4($s1)
    /* 7F1BC 8008E9BC 863A0208 */  j          .L8008EA18
    /* 7F1C0 8008E9C0 21A00002 */   addu      $s4, $s0, $zero
  .L8008E9C4:
    /* 7F1C4 8008E9C4 12004010 */  beqz       $v0, .L8008EA10
    /* 7F1C8 8008E9C8 21800000 */   addu      $s0, $zero, $zero
  .L8008E9CC:
    /* 7F1CC 8008E9CC 0000E492 */  lbu        $a0, 0x0($s7)
    /* 7F1D0 8008E9D0 0A80023C */  lui        $v0, %hi(D_80099EE9)
    /* 7F1D4 8008E9D4 21104400 */  addu       $v0, $v0, $a0
    /* 7F1D8 8008E9D8 E99E4290 */  lbu        $v0, %lo(D_80099EE9)($v0)
    /* 7F1DC 8008E9DC 00000000 */  nop
    /* 7F1E0 8008E9E0 04004230 */  andi       $v0, $v0, 0x4
    /* 7F1E4 8008E9E4 0A004010 */  beqz       $v0, .L8008EA10
    /* 7F1E8 8008E9E8 80101000 */   sll       $v0, $s0, 2
    /* 7F1EC 8008E9EC 0100F726 */  addiu      $s7, $s7, 0x1
    /* 7F1F0 8008E9F0 21105000 */  addu       $v0, $v0, $s0
    /* 7F1F4 8008E9F4 40100200 */  sll        $v0, $v0, 1
    /* 7F1F8 8008E9F8 D0FF4224 */  addiu      $v0, $v0, -0x30
    /* 7F1FC 8008E9FC 0000E392 */  lbu        $v1, 0x0($s7)
    /* 7F200 8008EA00 00000000 */  nop
    /* 7F204 8008EA04 8000632C */  sltiu      $v1, $v1, 0x80
    /* 7F208 8008EA08 F0FF6014 */  bnez       $v1, .L8008E9CC
    /* 7F20C 8008EA0C 21804400 */   addu      $s0, $v0, $a0
  .L8008EA10:
    /* 7F210 8008EA10 FFFFF726 */  addiu      $s7, $s7, -0x1
    /* 7F214 8008EA14 21A00002 */  addu       $s4, $s0, $zero
  .L8008EA18:
    /* 7F218 8008EA18 C4FF0106 */  bgez       $s0, .L8008E92C
    /* 7F21C 8008EA1C 00000000 */   nop
    /* 7F220 8008EA20 4B3A0208 */  j          .L8008E92C
    /* 7F224 8008EA24 FFFF1424 */   addiu     $s4, $zero, -0x1
  jlabel .L8008EA28
    /* 7F228 8008EA28 4B3A0208 */  j          .L8008E92C
    /* 7F22C 8008EA2C 20007336 */   ori       $s3, $s3, 0x20
  jlabel .L8008EA30
    /* 7F230 8008EA30 21800000 */  addu       $s0, $zero, $zero
  .L8008EA34:
    /* 7F234 8008EA34 0000E292 */  lbu        $v0, 0x0($s7)
    /* 7F238 8008EA38 0100F726 */  addiu      $s7, $s7, 0x1
    /* 7F23C 8008EA3C 80181000 */  sll        $v1, $s0, 2
    /* 7F240 8008EA40 21187000 */  addu       $v1, $v1, $s0
    /* 7F244 8008EA44 40180300 */  sll        $v1, $v1, 1
    /* 7F248 8008EA48 D0FF6324 */  addiu      $v1, $v1, -0x30
    /* 7F24C 8008EA4C 0000E492 */  lbu        $a0, 0x0($s7)
    /* 7F250 8008EA50 00000000 */  nop
    /* 7F254 8008EA54 8000842C */  sltiu      $a0, $a0, 0x80
    /* 7F258 8008EA58 09008010 */  beqz       $a0, .L8008EA80
    /* 7F25C 8008EA5C 21806200 */   addu      $s0, $v1, $v0
    /* 7F260 8008EA60 0000E292 */  lbu        $v0, 0x0($s7)
    /* 7F264 8008EA64 0A80013C */  lui        $at, %hi(D_80099EE9)
    /* 7F268 8008EA68 21082200 */  addu       $at, $at, $v0
    /* 7F26C 8008EA6C E99E2290 */  lbu        $v0, %lo(D_80099EE9)($at)
    /* 7F270 8008EA70 00000000 */  nop
    /* 7F274 8008EA74 04004230 */  andi       $v0, $v0, 0x4
    /* 7F278 8008EA78 EEFF4014 */  bnez       $v0, .L8008EA34
    /* 7F27C 8008EA7C 00000000 */   nop
  .L8008EA80:
    /* 7F280 8008EA80 4400B0AF */  sw         $s0, 0x44($sp)
    /* 7F284 8008EA84 4B3A0208 */  j          .L8008E92C
    /* 7F288 8008EA88 FFFFF726 */   addiu     $s7, $s7, -0x1
  jlabel .L8008EA8C
    /* 7F28C 8008EA8C 4B3A0208 */  j          .L8008E92C
    /* 7F290 8008EA90 02007336 */   ori       $s3, $s3, 0x2
  jlabel .L8008EA94
    /* 7F294 8008EA94 4B3A0208 */  j          .L8008E92C
    /* 7F298 8008EA98 04007336 */   ori       $s3, $s3, 0x4
  jlabel .L8008EA9C
    /* 7F29C 8008EA9C 4B3A0208 */  j          .L8008E92C
    /* 7F2A0 8008EAA0 01007336 */   ori       $s3, $s3, 0x1
  jlabel .L8008EAA4
    /* 7F2A4 8008EAA4 1000B227 */  addiu      $s2, $sp, 0x10
    /* 7F2A8 8008EAA8 04003126 */  addiu      $s1, $s1, 0x4
    /* 7F2AC 8008EAAC 01001624 */  addiu      $s6, $zero, 0x1
    /* 7F2B0 8008EAB0 FCFF2292 */  lbu        $v0, -0x4($s1)
    /* 7F2B4 8008EAB4 21F00000 */  addu       $fp, $zero, $zero
    /* 7F2B8 8008EAB8 473B0208 */  j          .L8008ED1C
    /* 7F2BC 8008EABC 1000A2A3 */   sb        $v0, 0x10($sp)
  jlabel .L8008EAC0
    /* 7F2C0 8008EAC0 01007336 */  ori        $s3, $s3, 0x1
  jlabel .L8008EAC4
    /* 7F2C4 8008EAC4 01006232 */  andi       $v0, $s3, 0x1
    /* 7F2C8 8008EAC8 07004014 */  bnez       $v0, .L8008EAE8
    /* 7F2CC 8008EACC 04006232 */   andi      $v0, $s3, 0x4
    /* 7F2D0 8008EAD0 05004010 */  beqz       $v0, .L8008EAE8
    /* 7F2D4 8008EAD4 00000000 */   nop
    /* 7F2D8 8008EAD8 04003126 */  addiu      $s1, $s1, 0x4
    /* 7F2DC 8008EADC FCFF2386 */  lh         $v1, -0x4($s1)
    /* 7F2E0 8008EAE0 BD3A0208 */  j          .L8008EAF4
    /* 7F2E4 8008EAE4 00000000 */   nop
  .L8008EAE8:
    /* 7F2E8 8008EAE8 04003126 */  addiu      $s1, $s1, 0x4
    /* 7F2EC 8008EAEC FCFF238E */  lw         $v1, -0x4($s1)
    /* 7F2F0 8008EAF0 00000000 */  nop
  .L8008EAF4:
    /* 7F2F4 8008EAF4 61006104 */  bgez       $v1, .L8008EC7C
    /* 7F2F8 8008EAF8 0A000524 */   addiu     $a1, $zero, 0xA
    /* 7F2FC 8008EAFC 23180300 */  negu       $v1, $v1
    /* 7F300 8008EB00 1F3B0208 */  j          .L8008EC7C
    /* 7F304 8008EB04 2D001E24 */   addiu     $fp, $zero, 0x2D
  jlabel .L8008EB08
    /* 7F308 8008EB08 01006232 */  andi       $v0, $s3, 0x1
    /* 7F30C 8008EB0C 08004014 */  bnez       $v0, .L8008EB30
    /* 7F310 8008EB10 04006232 */   andi      $v0, $s3, 0x4
    /* 7F314 8008EB14 06004010 */  beqz       $v0, .L8008EB30
    /* 7F318 8008EB18 00000000 */   nop
    /* 7F31C 8008EB1C 04003126 */  addiu      $s1, $s1, 0x4
    /* 7F320 8008EB20 FCFF228E */  lw         $v0, -0x4($s1)
    /* 7F324 8008EB24 3800A797 */  lhu        $a3, 0x38($sp)
    /* 7F328 8008EB28 C33B0208 */  j          .L8008EF0C
    /* 7F32C 8008EB2C 000047A4 */   sh        $a3, 0x0($v0)
  .L8008EB30:
    /* 7F330 8008EB30 04003126 */  addiu      $s1, $s1, 0x4
    /* 7F334 8008EB34 FCFF228E */  lw         $v0, -0x4($s1)
    /* 7F338 8008EB38 3800A78F */  lw         $a3, 0x38($sp)
    /* 7F33C 8008EB3C C33B0208 */  j          .L8008EF0C
    /* 7F340 8008EB40 000047AC */   sw        $a3, 0x0($v0)
  jlabel .L8008EB44
    /* 7F344 8008EB44 01007336 */  ori        $s3, $s3, 0x1
  jlabel .L8008EB48
    /* 7F348 8008EB48 01006232 */  andi       $v0, $s3, 0x1
    /* 7F34C 8008EB4C 07004014 */  bnez       $v0, .L8008EB6C
    /* 7F350 8008EB50 04006232 */   andi      $v0, $s3, 0x4
    /* 7F354 8008EB54 05004010 */  beqz       $v0, .L8008EB6C
    /* 7F358 8008EB58 08000524 */   addiu     $a1, $zero, 0x8
    /* 7F35C 8008EB5C 04003126 */  addiu      $s1, $s1, 0x4
    /* 7F360 8008EB60 FCFF2386 */  lh         $v1, -0x4($s1)
    /* 7F364 8008EB64 1F3B0208 */  j          .L8008EC7C
    /* 7F368 8008EB68 21F00000 */   addu      $fp, $zero, $zero
  .L8008EB6C:
    /* 7F36C 8008EB6C 04003126 */  addiu      $s1, $s1, 0x4
    /* 7F370 8008EB70 FCFF238E */  lw         $v1, -0x4($s1)
    /* 7F374 8008EB74 1E3B0208 */  j          .L8008EC78
    /* 7F378 8008EB78 08000524 */   addiu     $a1, $zero, 0x8
  jlabel .L8008EB7C
    /* 7F37C 8008EB7C 04003126 */  addiu      $s1, $s1, 0x4
    /* 7F380 8008EB80 FCFF238E */  lw         $v1, -0x4($s1)
    /* 7F384 8008EB84 1E3B0208 */  j          .L8008EC78
    /* 7F388 8008EB88 10000524 */   addiu     $a1, $zero, 0x10
  jlabel .L8008EB8C
    /* 7F38C 8008EB8C 04003126 */  addiu      $s1, $s1, 0x4
    /* 7F390 8008EB90 FCFF328E */  lw         $s2, -0x4($s1)
    /* 7F394 8008EB94 00000000 */  nop
    /* 7F398 8008EB98 03004016 */  bnez       $s2, .L8008EBA8
    /* 7F39C 8008EB9C 00000000 */   nop
    /* 7F3A0 8008EBA0 0180123C */  lui        $s2, %hi(D_8001268C)
    /* 7F3A4 8008EBA4 8C265226 */  addiu      $s2, $s2, %lo(D_8001268C)
  .L8008EBA8:
    /* 7F3A8 8008EBA8 0B008006 */  bltz       $s4, .L8008EBD8
    /* 7F3AC 8008EBAC 21204002 */   addu      $a0, $s2, $zero
    /* 7F3B0 8008EBB0 21280000 */  addu       $a1, $zero, $zero
    /* 7F3B4 8008EBB4 D43B020C */  jal        func_8008EF50
    /* 7F3B8 8008EBB8 21308002 */   addu      $a2, $s4, $zero
    /* 7F3BC 8008EBBC 04004010 */  beqz       $v0, .L8008EBD0
    /* 7F3C0 8008EBC0 23B05200 */   subu      $s6, $v0, $s2
    /* 7F3C4 8008EBC4 2A109602 */  slt        $v0, $s4, $s6
    /* 7F3C8 8008EBC8 54004010 */  beqz       $v0, .L8008ED1C
    /* 7F3CC 8008EBCC 21F00000 */   addu      $fp, $zero, $zero
  .L8008EBD0:
    /* 7F3D0 8008EBD0 F93A0208 */  j          .L8008EBE4
    /* 7F3D4 8008EBD4 21B08002 */   addu      $s6, $s4, $zero
  .L8008EBD8:
    /* 7F3D8 8008EBD8 D039020C */  jal        func_8008E740
    /* 7F3DC 8008EBDC 21204002 */   addu      $a0, $s2, $zero
    /* 7F3E0 8008EBE0 21B04000 */  addu       $s6, $v0, $zero
  .L8008EBE4:
    /* 7F3E4 8008EBE4 473B0208 */  j          .L8008ED1C
    /* 7F3E8 8008EBE8 21F00000 */   addu      $fp, $zero, $zero
  jlabel .L8008EBEC
    /* 7F3EC 8008EBEC 01007336 */  ori        $s3, $s3, 0x1
  jlabel .L8008EBF0
    /* 7F3F0 8008EBF0 01006232 */  andi       $v0, $s3, 0x1
    /* 7F3F4 8008EBF4 07004014 */  bnez       $v0, .L8008EC14
    /* 7F3F8 8008EBF8 04006232 */   andi      $v0, $s3, 0x4
    /* 7F3FC 8008EBFC 05004010 */  beqz       $v0, .L8008EC14
    /* 7F400 8008EC00 0A000524 */   addiu     $a1, $zero, 0xA
    /* 7F404 8008EC04 04003126 */  addiu      $s1, $s1, 0x4
    /* 7F408 8008EC08 FCFF2386 */  lh         $v1, -0x4($s1)
    /* 7F40C 8008EC0C 1F3B0208 */  j          .L8008EC7C
    /* 7F410 8008EC10 21F00000 */   addu      $fp, $zero, $zero
  .L8008EC14:
    /* 7F414 8008EC14 04003126 */  addiu      $s1, $s1, 0x4
    /* 7F418 8008EC18 FCFF238E */  lw         $v1, -0x4($s1)
    /* 7F41C 8008EC1C 1E3B0208 */  j          .L8008EC78
    /* 7F420 8008EC20 0A000524 */   addiu     $a1, $zero, 0xA
  jlabel .L8008EC24
    /* 7F424 8008EC24 0180073C */  lui        $a3, %hi(D_80012694)
    /* 7F428 8008EC28 9426E724 */  addiu      $a3, $a3, %lo(D_80012694)
    /* 7F42C 8008EC2C 4800A7AF */  sw         $a3, 0x48($sp)
  jlabel .L8008EC30
    /* 7F430 8008EC30 01006232 */  andi       $v0, $s3, 0x1
    /* 7F434 8008EC34 07004014 */  bnez       $v0, .L8008EC54
    /* 7F438 8008EC38 04006232 */   andi      $v0, $s3, 0x4
    /* 7F43C 8008EC3C 05004010 */  beqz       $v0, .L8008EC54
    /* 7F440 8008EC40 10000524 */   addiu     $a1, $zero, 0x10
    /* 7F444 8008EC44 04003126 */  addiu      $s1, $s1, 0x4
    /* 7F448 8008EC48 FCFF2386 */  lh         $v1, -0x4($s1)
    /* 7F44C 8008EC4C 193B0208 */  j          .L8008EC64
    /* 7F450 8008EC50 08006232 */   andi      $v0, $s3, 0x8
  .L8008EC54:
    /* 7F454 8008EC54 04003126 */  addiu      $s1, $s1, 0x4
    /* 7F458 8008EC58 FCFF238E */  lw         $v1, -0x4($s1)
    /* 7F45C 8008EC5C 10000524 */  addiu      $a1, $zero, 0x10
    /* 7F460 8008EC60 08006232 */  andi       $v0, $s3, 0x8
  .L8008EC64:
    /* 7F464 8008EC64 05004010 */  beqz       $v0, .L8008EC7C
    /* 7F468 8008EC68 21F00000 */   addu      $fp, $zero, $zero
    /* 7F46C 8008EC6C 03006010 */  beqz       $v1, .L8008EC7C
    /* 7F470 8008EC70 00000000 */   nop
    /* 7F474 8008EC74 40007336 */  ori        $s3, $s3, 0x40
  .L8008EC78:
    /* 7F478 8008EC78 21F00000 */  addu       $fp, $zero, $zero
  .L8008EC7C:
    /* 7F47C 8008EC7C 03008006 */  bltz       $s4, .L8008EC8C
    /* 7F480 8008EC80 3C00B4AF */   sw        $s4, 0x3C($sp)
    /* 7F484 8008EC84 DFFF0224 */  addiu      $v0, $zero, -0x21
    /* 7F488 8008EC88 24986202 */  and        $s3, $s3, $v0
  .L8008EC8C:
    /* 7F48C 8008EC8C 05006014 */  bnez       $v1, .L8008ECA4
    /* 7F490 8008EC90 3800B227 */   addiu     $s2, $sp, 0x38
    /* 7F494 8008EC94 3C00A78F */  lw         $a3, 0x3C($sp)
    /* 7F498 8008EC98 00000000 */  nop
    /* 7F49C 8008EC9C 1E00E010 */  beqz       $a3, .L8008ED18
    /* 7F4A0 8008ECA0 2310B203 */   subu      $v0, $sp, $s2
  .L8008ECA4:
    /* 7F4A4 8008ECA4 1B006500 */  divu       $zero, $v1, $a1
    /* 7F4A8 8008ECA8 0200A014 */  bnez       $a1, .L8008ECB4
    /* 7F4AC 8008ECAC 00000000 */   nop
    /* 7F4B0 8008ECB0 0D000700 */  break      7
  .L8008ECB4:
    /* 7F4B4 8008ECB4 12180000 */  mflo       $v1
    /* 7F4B8 8008ECB8 10100000 */  mfhi       $v0
    /* 7F4BC 8008ECBC 4800A78F */  lw         $a3, 0x48($sp)
    /* 7F4C0 8008ECC0 00000000 */  nop
    /* 7F4C4 8008ECC4 2110E200 */  addu       $v0, $a3, $v0
    /* 7F4C8 8008ECC8 00004490 */  lbu        $a0, 0x0($v0)
    /* 7F4CC 8008ECCC FFFF5226 */  addiu      $s2, $s2, -0x1
    /* 7F4D0 8008ECD0 F4FF6014 */  bnez       $v1, .L8008ECA4
    /* 7F4D4 8008ECD4 000044A2 */   sb        $a0, 0x0($s2)
    /* 7F4D8 8008ECD8 0180073C */  lui        $a3, %hi(D_80012678)
    /* 7F4DC 8008ECDC 7826E724 */  addiu      $a3, $a3, %lo(D_80012678)
    /* 7F4E0 8008ECE0 08006232 */  andi       $v0, $s3, 0x8
    /* 7F4E4 8008ECE4 0B004010 */  beqz       $v0, .L8008ED14
    /* 7F4E8 8008ECE8 4800A7AF */   sw        $a3, 0x48($sp)
    /* 7F4EC 8008ECEC 08000224 */  addiu      $v0, $zero, 0x8
    /* 7F4F0 8008ECF0 0900A214 */  bne        $a1, $v0, .L8008ED18
    /* 7F4F4 8008ECF4 2310B203 */   subu      $v0, $sp, $s2
    /* 7F4F8 8008ECF8 00160400 */  sll        $v0, $a0, 24
    /* 7F4FC 8008ECFC 03160200 */  sra        $v0, $v0, 24
    /* 7F500 8008ED00 30000324 */  addiu      $v1, $zero, 0x30
    /* 7F504 8008ED04 04004310 */  beq        $v0, $v1, .L8008ED18
    /* 7F508 8008ED08 2310B203 */   subu      $v0, $sp, $s2
    /* 7F50C 8008ED0C FFFF5226 */  addiu      $s2, $s2, -0x1
    /* 7F510 8008ED10 000043A2 */  sb         $v1, 0x0($s2)
  .L8008ED14:
    /* 7F514 8008ED14 2310B203 */  subu       $v0, $sp, $s2
  .L8008ED18:
    /* 7F518 8008ED18 38005624 */  addiu      $s6, $v0, 0x38
  .L8008ED1C:
    /* 7F51C 8008ED1C 4000A78F */  lw         $a3, 0x40($sp)
    /* 7F520 8008ED20 0200C013 */  beqz       $fp, .L8008ED2C
    /* 7F524 8008ED24 21A0C702 */   addu      $s4, $s6, $a3
    /* 7F528 8008ED28 01009426 */  addiu      $s4, $s4, 0x1
  .L8008ED2C:
    /* 7F52C 8008ED2C 40006232 */  andi       $v0, $s3, 0x40
    /* 7F530 8008ED30 02004010 */  beqz       $v0, .L8008ED3C
    /* 7F534 8008ED34 00000000 */   nop
    /* 7F538 8008ED38 02009426 */  addiu      $s4, $s4, 0x2
  .L8008ED3C:
    /* 7F53C 8008ED3C 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 7F540 8008ED40 00000000 */  nop
    /* 7F544 8008ED44 2A10B402 */  slt        $v0, $s5, $s4
    /* 7F548 8008ED48 02004010 */  beqz       $v0, .L8008ED54
    /* 7F54C 8008ED4C 30006232 */   andi      $v0, $s3, 0x30
    /* 7F550 8008ED50 21A88002 */  addu       $s5, $s4, $zero
  .L8008ED54:
    /* 7F554 8008ED54 0E004014 */  bnez       $v0, .L8008ED90
    /* 7F558 8008ED58 2120C003 */   addu      $a0, $fp, $zero
    /* 7F55C 8008ED5C 4400A78F */  lw         $a3, 0x44($sp)
    /* 7F560 8008ED60 00000000 */  nop
    /* 7F564 8008ED64 0A00E010 */  beqz       $a3, .L8008ED90
    /* 7F568 8008ED68 2A10A702 */   slt       $v0, $s5, $a3
    /* 7F56C 8008ED6C 08004010 */  beqz       $v0, .L8008ED90
    /* 7F570 8008ED70 2180A002 */   addu      $s0, $s5, $zero
  .L8008ED74:
    /* 7F574 8008ED74 E83B020C */  jal        func_8008EFA0
    /* 7F578 8008ED78 20000424 */   addiu     $a0, $zero, 0x20
    /* 7F57C 8008ED7C 4400A78F */  lw         $a3, 0x44($sp)
    /* 7F580 8008ED80 01001026 */  addiu      $s0, $s0, 0x1
    /* 7F584 8008ED84 2A100702 */  slt        $v0, $s0, $a3
    /* 7F588 8008ED88 FAFF4014 */  bnez       $v0, .L8008ED74
    /* 7F58C 8008ED8C 2120C003 */   addu      $a0, $fp, $zero
  .L8008ED90:
    /* 7F590 8008ED90 04008010 */  beqz       $a0, .L8008EDA4
    /* 7F594 8008ED94 40006232 */   andi      $v0, $s3, 0x40
    /* 7F598 8008ED98 E83B020C */  jal        func_8008EFA0
    /* 7F59C 8008ED9C 00000000 */   nop
    /* 7F5A0 8008EDA0 40006232 */  andi       $v0, $s3, 0x40
  .L8008EDA4:
    /* 7F5A4 8008EDA4 07004010 */  beqz       $v0, .L8008EDC4
    /* 7F5A8 8008EDA8 30006332 */   andi      $v1, $s3, 0x30
    /* 7F5AC 8008EDAC E83B020C */  jal        func_8008EFA0
    /* 7F5B0 8008EDB0 30000424 */   addiu     $a0, $zero, 0x30
    /* 7F5B4 8008EDB4 0000E482 */  lb         $a0, 0x0($s7)
    /* 7F5B8 8008EDB8 E83B020C */  jal        func_8008EFA0
    /* 7F5BC 8008EDBC 00000000 */   nop
    /* 7F5C0 8008EDC0 30006332 */  andi       $v1, $s3, 0x30
  .L8008EDC4:
    /* 7F5C4 8008EDC4 20000224 */  addiu      $v0, $zero, 0x20
    /* 7F5C8 8008EDC8 0D006214 */  bne        $v1, $v0, .L8008EE00
    /* 7F5CC 8008EDCC 00000000 */   nop
    /* 7F5D0 8008EDD0 4400A78F */  lw         $a3, 0x44($sp)
    /* 7F5D4 8008EDD4 00000000 */  nop
    /* 7F5D8 8008EDD8 2A10A702 */  slt        $v0, $s5, $a3
    /* 7F5DC 8008EDDC 08004010 */  beqz       $v0, .L8008EE00
    /* 7F5E0 8008EDE0 2180A002 */   addu      $s0, $s5, $zero
  .L8008EDE4:
    /* 7F5E4 8008EDE4 E83B020C */  jal        func_8008EFA0
    /* 7F5E8 8008EDE8 30000424 */   addiu     $a0, $zero, 0x30
    /* 7F5EC 8008EDEC 4400A78F */  lw         $a3, 0x44($sp)
    /* 7F5F0 8008EDF0 01001026 */  addiu      $s0, $s0, 0x1
    /* 7F5F4 8008EDF4 2A100702 */  slt        $v0, $s0, $a3
    /* 7F5F8 8008EDF8 FAFF4014 */  bnez       $v0, .L8008EDE4
    /* 7F5FC 8008EDFC 00000000 */   nop
  .L8008EE00:
    /* 7F600 8008EE00 3C00A78F */  lw         $a3, 0x3C($sp)
    /* 7F604 8008EE04 21808002 */  addu       $s0, $s4, $zero
    /* 7F608 8008EE08 2A100702 */  slt        $v0, $s0, $a3
    /* 7F60C 8008EE0C 08004010 */  beqz       $v0, .L8008EE30
    /* 7F610 8008EE10 00000000 */   nop
  .L8008EE14:
    /* 7F614 8008EE14 E83B020C */  jal        func_8008EFA0
    /* 7F618 8008EE18 30000424 */   addiu     $a0, $zero, 0x30
    /* 7F61C 8008EE1C 3C00A78F */  lw         $a3, 0x3C($sp)
    /* 7F620 8008EE20 01001026 */  addiu      $s0, $s0, 0x1
    /* 7F624 8008EE24 2A100702 */  slt        $v0, $s0, $a3
    /* 7F628 8008EE28 FAFF4014 */  bnez       $v0, .L8008EE14
    /* 7F62C 8008EE2C 00000000 */   nop
  .L8008EE30:
    /* 7F630 8008EE30 FFFFD026 */  addiu      $s0, $s6, -0x1
    /* 7F634 8008EE34 0B000006 */  bltz       $s0, .L8008EE64
    /* 7F638 8008EE38 00000000 */   nop
  .L8008EE3C:
    /* 7F63C 8008EE3C 00004482 */  lb         $a0, 0x0($s2)
    /* 7F640 8008EE40 01005226 */  addiu      $s2, $s2, 0x1
    /* 7F644 8008EE44 E83B020C */  jal        func_8008EFA0
    /* 7F648 8008EE48 FFFF1026 */   addiu     $s0, $s0, -0x1
    /* 7F64C 8008EE4C 05000006 */  bltz       $s0, .L8008EE64
    /* 7F650 8008EE50 00000000 */   nop
    /* 7F654 8008EE54 8F3B0208 */  j          .L8008EE3C
    /* 7F658 8008EE58 00000000 */   nop
  .L8008EE5C:
    /* 7F65C 8008EE5C E83B020C */  jal        func_8008EFA0
    /* 7F660 8008EE60 30000424 */   addiu     $a0, $zero, 0x30
  .L8008EE64:
    /* 7F664 8008EE64 4000A78F */  lw         $a3, 0x40($sp)
    /* 7F668 8008EE68 00000000 */  nop
    /* 7F66C 8008EE6C FFFFE724 */  addiu      $a3, $a3, -0x1
    /* 7F670 8008EE70 FAFFE104 */  bgez       $a3, .L8008EE5C
    /* 7F674 8008EE74 4000A7AF */   sw        $a3, 0x40($sp)
    /* 7F678 8008EE78 10006232 */  andi       $v0, $s3, 0x10
    /* 7F67C 8008EE7C 0D004010 */  beqz       $v0, .L8008EEB4
    /* 7F680 8008EE80 00000000 */   nop
    /* 7F684 8008EE84 4400A78F */  lw         $a3, 0x44($sp)
    /* 7F688 8008EE88 00000000 */  nop
    /* 7F68C 8008EE8C 2A10A702 */  slt        $v0, $s5, $a3
    /* 7F690 8008EE90 08004010 */  beqz       $v0, .L8008EEB4
    /* 7F694 8008EE94 2180A002 */   addu      $s0, $s5, $zero
  .L8008EE98:
    /* 7F698 8008EE98 E83B020C */  jal        func_8008EFA0
    /* 7F69C 8008EE9C 20000424 */   addiu     $a0, $zero, 0x20
    /* 7F6A0 8008EEA0 4400A78F */  lw         $a3, 0x44($sp)
    /* 7F6A4 8008EEA4 01001026 */  addiu      $s0, $s0, 0x1
    /* 7F6A8 8008EEA8 2A100702 */  slt        $v0, $s0, $a3
    /* 7F6AC 8008EEAC FAFF4014 */  bnez       $v0, .L8008EE98
    /* 7F6B0 8008EEB0 00000000 */   nop
  .L8008EEB4:
    /* 7F6B4 8008EEB4 4400A38F */  lw         $v1, 0x44($sp)
    /* 7F6B8 8008EEB8 00000000 */  nop
    /* 7F6BC 8008EEBC 2A107500 */  slt        $v0, $v1, $s5
    /* 7F6C0 8008EEC0 02004010 */  beqz       $v0, .L8008EECC
    /* 7F6C4 8008EEC4 00000000 */   nop
    /* 7F6C8 8008EEC8 2118A002 */  addu       $v1, $s5, $zero
  .L8008EECC:
    /* 7F6CC 8008EECC 3800A78F */  lw         $a3, 0x38($sp)
    /* 7F6D0 8008EED0 00000000 */  nop
    /* 7F6D4 8008EED4 2138E300 */  addu       $a3, $a3, $v1
    /* 7F6D8 8008EED8 C33B0208 */  j          .L8008EF0C
    /* 7F6DC 8008EEDC 3800A7AF */   sw        $a3, 0x38($sp)
  jlabel .L8008EEE0
    /* 7F6E0 8008EEE0 273C020C */  jal        func_8008F09C
    /* 7F6E4 8008EEE4 00000000 */   nop
    /* 7F6E8 8008EEE8 3800A28F */  lw         $v0, 0x38($sp)
    /* 7F6EC 8008EEEC C53B0208 */  j          .L8008EF14
    /* 7F6F0 8008EEF0 00000000 */   nop
  jlabel .L8008EEF4
    /* 7F6F4 8008EEF4 3800A78F */  lw         $a3, 0x38($sp)
    /* 7F6F8 8008EEF8 0000E482 */  lb         $a0, 0x0($s7)
    /* 7F6FC 8008EEFC 0100E724 */  addiu      $a3, $a3, 0x1
    /* 7F700 8008EF00 3800A7AF */  sw         $a3, 0x38($sp)
  .L8008EF04:
    /* 7F704 8008EF04 E83B020C */  jal        func_8008EFA0
    /* 7F708 8008EF08 00000000 */   nop
  .L8008EF0C:
    /* 7F70C 8008EF0C 403A0208 */  j          .L8008E900
    /* 7F710 8008EF10 0100F726 */   addiu     $s7, $s7, 0x1
  .L8008EF14:
    /* 7F714 8008EF14 7400BF8F */  lw         $ra, 0x74($sp)
    /* 7F718 8008EF18 7000BE8F */  lw         $fp, 0x70($sp)
    /* 7F71C 8008EF1C 6C00B78F */  lw         $s7, 0x6C($sp)
    /* 7F720 8008EF20 6800B68F */  lw         $s6, 0x68($sp)
    /* 7F724 8008EF24 6400B58F */  lw         $s5, 0x64($sp)
    /* 7F728 8008EF28 6000B48F */  lw         $s4, 0x60($sp)
    /* 7F72C 8008EF2C 5C00B38F */  lw         $s3, 0x5C($sp)
    /* 7F730 8008EF30 5800B28F */  lw         $s2, 0x58($sp)
    /* 7F734 8008EF34 5400B18F */  lw         $s1, 0x54($sp)
    /* 7F738 8008EF38 5000B08F */  lw         $s0, 0x50($sp)
    /* 7F73C 8008EF3C 0800E003 */  jr         $ra
    /* 7F740 8008EF40 7800BD27 */   addiu     $sp, $sp, 0x78
endlabel func_8008E8B0
    /* 7F744 8008EF44 00000000 */  nop
    /* 7F748 8008EF48 00000000 */  nop
    /* 7F74C 8008EF4C 00000000 */  nop
