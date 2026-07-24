nonmatching func_8003E854, 0x63C

glabel func_8003E854
    /* 2F054 8003E854 E3048293 */  lbu        $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F058 8003E858 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2F05C 8003E85C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 2F060 8003E860 0F004330 */  andi       $v1, $v0, 0xF
    /* 2F064 8003E864 0F00622C */  sltiu      $v0, $v1, 0xF
    /* 2F068 8003E868 85014010 */  beqz       $v0, .L8003EE80
    /* 2F06C 8003E86C 2000B0AF */   sw        $s0, 0x20($sp)
    /* 2F070 8003E870 0180023C */  lui        $v0, %hi(jtbl_80010468)
    /* 2F074 8003E874 68044224 */  addiu      $v0, $v0, %lo(jtbl_80010468)
    /* 2F078 8003E878 80180300 */  sll        $v1, $v1, 2
    /* 2F07C 8003E87C 21186200 */  addu       $v1, $v1, $v0
    /* 2F080 8003E880 0000628C */  lw         $v0, 0x0($v1)
    /* 2F084 8003E884 00000000 */  nop
    /* 2F088 8003E888 08004000 */  jr         $v0
    /* 2F08C 8003E88C 00000000 */   nop
  jlabel .L8003E890
    /* 2F090 8003E890 E3048393 */  lbu        $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2F094 8003E894 00000000 */  nop
    /* 2F098 8003E898 80006230 */  andi       $v0, $v1, 0x80
    /* 2F09C 8003E89C 0B004014 */  bnez       $v0, .L8003E8CC
    /* 2F0A0 8003E8A0 01000224 */   addiu     $v0, $zero, 0x1
    /* 2F0A4 8003E8A4 C9000424 */  addiu      $a0, $zero, 0xC9
    /* 2F0A8 8003E8A8 20000524 */  addiu      $a1, $zero, 0x20
    /* 2F0AC 8003E8AC 80006234 */  ori        $v0, $v1, 0x80
    /* 2F0B0 8003E8B0 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F0B4 8003E8B4 F1048293 */  lbu        $v0, %gp_rel(D_8009B3F9)($gp)
    /* 2F0B8 8003E8B8 1D80033C */  lui        $v1, %hi(D_801D5648)
    /* 2F0BC 8003E8BC 02110200 */  srl        $v0, $v0, 4
    /* 2F0C0 8003E8C0 01004224 */  addiu      $v0, $v0, 0x1
    /* 2F0C4 8003E8C4 9EFB0008 */  j          .L8003EE78
    /* 2F0C8 8003E8C8 485662AC */   sw        $v0, %lo(D_801D5648)($v1)
  .L8003E8CC:
    /* 2F0CC 8003E8CC 0A80033C */  lui        $v1, %hi(D_8009B34D)
    /* 2F0D0 8003E8D0 4DB36380 */  lb         $v1, %lo(D_8009B34D)($v1)
    /* 2F0D4 8003E8D4 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F0D8 8003E8D8 20016014 */  bnez       $v1, .L8003ED5C
    /* 2F0DC 8003E8DC 0C000224 */   addiu     $v0, $zero, 0xC
  jlabel .L8003E8E0
    /* 2F0E0 8003E8E0 E3048393 */  lbu        $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2F0E4 8003E8E4 00000000 */  nop
    /* 2F0E8 8003E8E8 80006230 */  andi       $v0, $v1, 0x80
    /* 2F0EC 8003E8EC 0B004014 */  bnez       $v0, .L8003E91C
    /* 2F0F0 8003E8F0 80006234 */   ori       $v0, $v1, 0x80
    /* 2F0F4 8003E8F4 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F0F8 8003E8F8 D4000424 */  addiu      $a0, $zero, 0xD4
    /* 2F0FC 8003E8FC 1BF9000C */  jal        func_8003E46C
    /* 2F100 8003E900 21280000 */   addu      $a1, $zero, $zero
  .L8003E904:
    /* 2F104 8003E904 242F020C */  jal        func_8008BC90
    /* 2F108 8003E908 21200000 */   addu      $a0, $zero, $zero
    /* 2F10C 8003E90C FDFF4010 */  beqz       $v0, .L8003E904
    /* 2F110 8003E910 00000000 */   nop
    /* 2F114 8003E914 6CFB0008 */  j          .L8003EDB0
    /* 2F118 8003E918 00000000 */   nop
  .L8003E91C:
    /* 2F11C 8003E91C EC04838F */  lw         $v1, %gp_rel(D_8009B3F4)($gp)
    /* 2F120 8003E920 00000000 */  nop
    /* 2F124 8003E924 0500622C */  sltiu      $v0, $v1, 0x5
    /* 2F128 8003E928 55014010 */  beqz       $v0, .L8003EE80
    /* 2F12C 8003E92C 0180023C */   lui       $v0, %hi(jtbl_800104A8)
    /* 2F130 8003E930 A8044224 */  addiu      $v0, $v0, %lo(jtbl_800104A8)
    /* 2F134 8003E934 80180300 */  sll        $v1, $v1, 2
    /* 2F138 8003E938 21186200 */  addu       $v1, $v1, $v0
    /* 2F13C 8003E93C 0000628C */  lw         $v0, 0x0($v1)
    /* 2F140 8003E940 00000000 */  nop
    /* 2F144 8003E944 08004000 */  jr         $v0
    /* 2F148 8003E948 00000000 */   nop
  jlabel .L8003E94C
    /* 2F14C 8003E94C 03000224 */  addiu      $v0, $zero, 0x3
    /* 2F150 8003E950 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F154 8003E954 A0FB0008 */  j          .L8003EE80
    /* 2F158 8003E958 00000000 */   nop
  jlabel .L8003E95C
    /* 2F15C 8003E95C F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2F160 8003E960 04000324 */  addiu      $v1, $zero, 0x4
    /* 2F164 8003E964 E30483A3 */  sb         $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2F168 8003E968 00014230 */  andi       $v0, $v0, 0x100
    /* 2F16C 8003E96C 44014014 */  bnez       $v0, .L8003EE80
    /* 2F170 8003E970 00000000 */   nop
    /* 2F174 8003E974 CC048293 */  lbu        $v0, %gp_rel(D_8009B3D4)($gp)
    /* 2F178 8003E978 00000000 */  nop
    /* 2F17C 8003E97C 40014014 */  bnez       $v0, .L8003EE80
    /* 2F180 8003E980 0E000224 */   addiu     $v0, $zero, 0xE
    /* 2F184 8003E984 4CFB0008 */  j          .L8003ED30
    /* 2F188 8003E988 00000000 */   nop
  jlabel .L8003E98C
    /* 2F18C 8003E98C E3048393 */  lbu        $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2F190 8003E990 00000000 */  nop
    /* 2F194 8003E994 80006230 */  andi       $v0, $v1, 0x80
    /* 2F198 8003E998 07004014 */  bnez       $v0, .L8003E9B8
    /* 2F19C 8003E99C 40006230 */   andi      $v0, $v1, 0x40
    /* 2F1A0 8003E9A0 80006234 */  ori        $v0, $v1, 0x80
    /* 2F1A4 8003E9A4 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F1A8 8003E9A8 03000224 */  addiu      $v0, $zero, 0x3
    /* 2F1AC 8003E9AC E40482A3 */  sb         $v0, %gp_rel(D_8009B3EC)($gp)
    /* 2F1B0 8003E9B0 A0FB0008 */  j          .L8003EE80
    /* 2F1B4 8003E9B4 00000000 */   nop
  .L8003E9B8:
    /* 2F1B8 8003E9B8 31014010 */  beqz       $v0, .L8003EE80
    /* 2F1BC 8003E9BC B8000424 */   addiu     $a0, $zero, 0xB8
    /* 2F1C0 8003E9C0 9EFB0008 */  j          .L8003EE78
    /* 2F1C4 8003E9C4 18000524 */   addiu     $a1, $zero, 0x18
  jlabel .L8003E9C8
    /* 2F1C8 8003E9C8 21200000 */  addu       $a0, $zero, $zero
    /* 2F1CC 8003E9CC 0A80053C */  lui        $a1, %hi(D_8009AF70)
    /* 2F1D0 8003E9D0 70AFA524 */  addiu      $a1, $a1, %lo(D_8009AF70)
    /* 2F1D4 8003E9D4 0F80023C */  lui        $v0, %hi(D_800EFBC0)
    /* 2F1D8 8003E9D8 C0FB5024 */  addiu      $s0, $v0, %lo(D_800EFBC0)
    /* 2F1DC 8003E9DC 21300002 */  addu       $a2, $s0, $zero
    /* 2F1E0 8003E9E0 1800A727 */  addiu      $a3, $sp, 0x18
    /* 2F1E4 8003E9E4 0F000224 */  addiu      $v0, $zero, 0xF
    /* 2F1E8 8003E9E8 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2F1EC 8003E9EC 9E32020C */  jal        func_8008CA78
    /* 2F1F0 8003E9F0 1400A2AF */   sw        $v0, 0x14($sp)
    /* 2F1F4 8003E9F4 63004014 */  bnez       $v0, .L8003EB84
    /* 2F1F8 8003E9F8 0D000224 */   addiu     $v0, $zero, 0xD
    /* 2F1FC 8003E9FC 0F80043C */  lui        $a0, %hi(D_800EFE18)
    /* 2F200 8003EA00 18FE8424 */  addiu      $a0, $a0, %lo(D_800EFE18)
    /* 2F204 8003EA04 1800A68F */  lw         $a2, 0x18($sp)
    /* 2F208 8003EA08 6611010C */  jal        func_80044598
    /* 2F20C 8003EA0C 21280002 */   addu      $a1, $s0, $zero
    /* 2F210 8003EA10 04004004 */  bltz       $v0, .L8003EA24
    /* 2F214 8003EA14 07000224 */   addiu     $v0, $zero, 0x7
    /* 2F218 8003EA18 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F21C 8003EA1C A0FB0008 */  j          .L8003EE80
    /* 2F220 8003EA20 00000000 */   nop
  .L8003EA24:
    /* 2F224 8003EA24 F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2F228 8003EA28 00000000 */  nop
    /* 2F22C 8003EA2C 00014230 */  andi       $v0, $v0, 0x100
    /* 2F230 8003EA30 05004014 */  bnez       $v0, .L8003EA48
    /* 2F234 8003EA34 0F80043C */   lui       $a0, %hi(D_800EFBC0)
    /* 2F238 8003EA38 CC048293 */  lbu        $v0, %gp_rel(D_8009B3D4)($gp)
    /* 2F23C 8003EA3C 00000000 */  nop
    /* 2F240 8003EA40 BB004010 */  beqz       $v0, .L8003ED30
    /* 2F244 8003EA44 0E000224 */   addiu     $v0, $zero, 0xE
  .L8003EA48:
    /* 2F248 8003EA48 1800A58F */  lw         $a1, 0x18($sp)
    /* 2F24C 8003EA4C 5111010C */  jal        func_80044544
    /* 2F250 8003EA50 C0FB8424 */   addiu     $a0, $a0, %lo(D_800EFBC0)
    /* 2F254 8003EA54 D4048793 */  lbu        $a3, %gp_rel(D_8009B3DC)($gp)
    /* 2F258 8003EA58 21304000 */  addu       $a2, $v0, $zero
    /* 2F25C 8003EA5C 2A10C700 */  slt        $v0, $a2, $a3
    /* 2F260 8003EA60 05004014 */  bnez       $v0, .L8003EA78
    /* 2F264 8003EA64 DB000424 */   addiu     $a0, $zero, 0xDB
    /* 2F268 8003EA68 06000224 */  addiu      $v0, $zero, 0x6
    /* 2F26C 8003EA6C E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F270 8003EA70 F6FA0008 */  j          .L8003EBD8
    /* 2F274 8003EA74 21200000 */   addu      $a0, $zero, $zero
  .L8003EA78:
    /* 2F278 8003EA78 18000524 */  addiu      $a1, $zero, 0x18
    /* 2F27C 8003EA7C 1D80033C */  lui        $v1, %hi(D_801D5608)
    /* 2F280 8003EA80 0F000224 */  addiu      $v0, $zero, 0xF
    /* 2F284 8003EA84 23104600 */  subu       $v0, $v0, $a2
    /* 2F288 8003EA88 085662AC */  sw         $v0, %lo(D_801D5608)($v1)
    /* 2F28C 8003EA8C 08566324 */  addiu      $v1, $v1, %lo(D_801D5608)
    /* 2F290 8003EA90 9EFB0008 */  j          .L8003EE78
    /* 2F294 8003EA94 040067AC */   sw        $a3, 0x4($v1)
  jlabel .L8003EA98
    /* 2F298 8003EA98 E3048393 */  lbu        $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2F29C 8003EA9C 00000000 */  nop
    /* 2F2A0 8003EAA0 80006230 */  andi       $v0, $v1, 0x80
    /* 2F2A4 8003EAA4 06004014 */  bnez       $v0, .L8003EAC0
    /* 2F2A8 8003EAA8 40006230 */   andi      $v0, $v1, 0x40
    /* 2F2AC 8003EAAC 80006234 */  ori        $v0, $v1, 0x80
    /* 2F2B0 8003EAB0 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F2B4 8003EAB4 DE000424 */  addiu      $a0, $zero, 0xDE
    /* 2F2B8 8003EAB8 9EFB0008 */  j          .L8003EE78
    /* 2F2BC 8003EABC 10000524 */   addiu     $a1, $zero, 0x10
  .L8003EAC0:
    /* 2F2C0 8003EAC0 05004014 */  bnez       $v0, .L8003EAD8
    /* 2F2C4 8003EAC4 40006234 */   ori       $v0, $v1, 0x40
    /* 2F2C8 8003EAC8 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F2CC 8003EACC DF000424 */  addiu      $a0, $zero, 0xDF
    /* 2F2D0 8003EAD0 9EFB0008 */  j          .L8003EE78
    /* 2F2D4 8003EAD4 20000524 */   addiu     $a1, $zero, 0x20
  .L8003EAD8:
    /* 2F2D8 8003EAD8 0A80023C */  lui        $v0, %hi(D_8009B34D)
    /* 2F2DC 8003EADC 4DB34280 */  lb         $v0, %lo(D_8009B34D)($v0)
    /* 2F2E0 8003EAE0 00000000 */  nop
    /* 2F2E4 8003EAE4 9C004010 */  beqz       $v0, .L8003ED58
    /* 2F2E8 8003EAE8 05000224 */   addiu     $v0, $zero, 0x5
    /* 2F2EC 8003EAEC E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F2F0 8003EAF0 BE000424 */  addiu      $a0, $zero, 0xBE
    /* 2F2F4 8003EAF4 9EFB0008 */  j          .L8003EE78
    /* 2F2F8 8003EAF8 21280000 */   addu      $a1, $zero, $zero
  jlabel .L8003EAFC
    /* 2F2FC 8003EAFC E3048393 */  lbu        $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2F300 8003EB00 00000000 */  nop
    /* 2F304 8003EB04 80006230 */  andi       $v0, $v1, 0x80
    /* 2F308 8003EB08 09004014 */  bnez       $v0, .L8003EB30
    /* 2F30C 8003EB0C 02000224 */   addiu     $v0, $zero, 0x2
    /* 2F310 8003EB10 80006234 */  ori        $v0, $v1, 0x80
    /* 2F314 8003EB14 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
  .L8003EB18:
    /* 2F318 8003EB18 242F020C */  jal        func_8008BC90
    /* 2F31C 8003EB1C 21200000 */   addu      $a0, $zero, $zero
    /* 2F320 8003EB20 FDFF4010 */  beqz       $v0, .L8003EB18
    /* 2F324 8003EB24 00000000 */   nop
    /* 2F328 8003EB28 6CFB0008 */  j          .L8003EDB0
    /* 2F32C 8003EB2C 00000000 */   nop
  .L8003EB30:
    /* 2F330 8003EB30 E804838F */  lw         $v1, %gp_rel(D_8009B3F0)($gp)
    /* 2F334 8003EB34 00000000 */  nop
    /* 2F338 8003EB38 D1006214 */  bne        $v1, $v0, .L8003EE80
    /* 2F33C 8003EB3C 00000000 */   nop
    /* 2F340 8003EB40 EC04838F */  lw         $v1, %gp_rel(D_8009B3F4)($gp)
    /* 2F344 8003EB44 00000000 */  nop
    /* 2F348 8003EB48 0500622C */  sltiu      $v0, $v1, 0x5
    /* 2F34C 8003EB4C CC004010 */  beqz       $v0, .L8003EE80
    /* 2F350 8003EB50 0180023C */   lui       $v0, %hi(jtbl_800104C0)
    /* 2F354 8003EB54 C0044224 */  addiu      $v0, $v0, %lo(jtbl_800104C0)
    /* 2F358 8003EB58 80180300 */  sll        $v1, $v1, 2
    /* 2F35C 8003EB5C 21186200 */  addu       $v1, $v1, $v0
    /* 2F360 8003EB60 0000628C */  lw         $v0, 0x0($v1)
    /* 2F364 8003EB64 00000000 */  nop
    /* 2F368 8003EB68 08004000 */  jr         $v0
    /* 2F36C 8003EB6C 00000000 */   nop
  jlabel .L8003EB70
    /* 2F370 8003EB70 9DFB0008 */  j          .L8003EE74
    /* 2F374 8003EB74 C3000424 */   addiu     $a0, $zero, 0xC3
  jlabel .L8003EB78
    /* 2F378 8003EB78 9DFB0008 */  j          .L8003EE74
    /* 2F37C 8003EB7C C3000424 */   addiu     $a0, $zero, 0xC3
  jlabel .L8003EB80
    /* 2F380 8003EB80 0D000224 */  addiu      $v0, $zero, 0xD
  .L8003EB84:
    /* 2F384 8003EB84 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F388 8003EB88 A0FB0008 */  j          .L8003EE80
    /* 2F38C 8003EB8C 00000000 */   nop
  jlabel .L8003EB90
    /* 2F390 8003EB90 E3048393 */  lbu        $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2F394 8003EB94 00000000 */  nop
    /* 2F398 8003EB98 40006230 */  andi       $v0, $v1, 0x40
    /* 2F39C 8003EB9C 0A004014 */  bnez       $v0, .L8003EBC8
    /* 2F3A0 8003EBA0 01000224 */   addiu     $v0, $zero, 0x1
    /* 2F3A4 8003EBA4 40006234 */  ori        $v0, $v1, 0x40
    /* 2F3A8 8003EBA8 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F3AC 8003EBAC C033020C */  jal        func_8008CF00
    /* 2F3B0 8003EBB0 21200000 */   addu      $a0, $zero, $zero
    /* 2F3B4 8003EBB4 AF004014 */  bnez       $v0, .L8003EE74
    /* 2F3B8 8003EBB8 DD000424 */   addiu     $a0, $zero, 0xDD
    /* 2F3BC 8003EBBC BF000424 */  addiu      $a0, $zero, 0xBF
    /* 2F3C0 8003EBC0 9EFB0008 */  j          .L8003EE78
    /* 2F3C4 8003EBC4 10000524 */   addiu     $a1, $zero, 0x10
  .L8003EBC8:
    /* 2F3C8 8003EBC8 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F3CC 8003EBCC A0FB0008 */  j          .L8003EE80
    /* 2F3D0 8003EBD0 00000000 */   nop
  jlabel .L8003EBD4
    /* 2F3D4 8003EBD4 21200000 */  addu       $a0, $zero, $zero
  .L8003EBD8:
    /* 2F3D8 8003EBD8 D4048693 */  lbu        $a2, %gp_rel(D_8009B3DC)($gp)
    /* 2F3DC 8003EBDC 0F80053C */  lui        $a1, %hi(D_800EFE18)
    /* 2F3E0 8003EBE0 8133020C */  jal        func_8008CE04
    /* 2F3E4 8003EBE4 18FEA524 */   addiu     $a1, $a1, %lo(D_800EFE18)
    /* 2F3E8 8003EBE8 04004010 */  beqz       $v0, .L8003EBFC
    /* 2F3EC 8003EBEC 0B000224 */   addiu     $v0, $zero, 0xB
    /* 2F3F0 8003EBF0 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F3F4 8003EBF4 A0FB0008 */  j          .L8003EE80
    /* 2F3F8 8003EBF8 00000000 */   nop
  .L8003EBFC:
    /* 2F3FC 8003EBFC F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2F400 8003EC00 00000000 */  nop
    /* 2F404 8003EC04 00014230 */  andi       $v0, $v0, 0x100
    /* 2F408 8003EC08 57004014 */  bnez       $v0, .L8003ED68
    /* 2F40C 8003EC0C 08000224 */   addiu     $v0, $zero, 0x8
    /* 2F410 8003EC10 C804828F */  lw         $v0, %gp_rel(D_8009B3D0)($gp)
    /* 2F414 8003EC14 BA048397 */  lhu        $v1, %gp_rel(D_8009B3C2)($gp)
    /* 2F418 8003EC18 BC0480A7 */  sh         $zero, %gp_rel(D_8009B3C4)($gp)
    /* 2F41C 8003EC1C 00FE4224 */  addiu      $v0, $v0, -0x200
    /* 2F420 8003EC20 00026324 */  addiu      $v1, $v1, 0x200
    /* 2F424 8003EC24 C80482AF */  sw         $v0, %gp_rel(D_8009B3D0)($gp)
    /* 2F428 8003EC28 BA0483A7 */  sh         $v1, %gp_rel(D_8009B3C2)($gp)
    /* 2F42C 8003EC2C 5AFB0008 */  j          .L8003ED68
    /* 2F430 8003EC30 08000224 */   addiu     $v0, $zero, 0x8
  jlabel .L8003EC34
    /* 2F434 8003EC34 E3048393 */  lbu        $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2F438 8003EC38 00000000 */  nop
    /* 2F43C 8003EC3C 80006230 */  andi       $v0, $v1, 0x80
    /* 2F440 8003EC40 0F004014 */  bnez       $v0, .L8003EC80
    /* 2F444 8003EC44 40006230 */   andi      $v0, $v1, 0x40
    /* 2F448 8003EC48 21200000 */  addu       $a0, $zero, $zero
    /* 2F44C 8003EC4C 0F80053C */  lui        $a1, %hi(D_800EFE18)
    /* 2F450 8003EC50 18FEA524 */  addiu      $a1, $a1, %lo(D_800EFE18)
    /* 2F454 8003EC54 1E80063C */  lui        $a2, %hi(D_801DC000)
    /* 2F458 8003EC58 00C0C624 */  addiu      $a2, $a2, %lo(D_801DC000)
    /* 2F45C 8003EC5C BC048797 */  lhu        $a3, %gp_rel(D_8009B3C4)($gp)
    /* 2F460 8003EC60 80006234 */  ori        $v0, $v1, 0x80
    /* 2F464 8003EC64 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F468 8003EC68 80040224 */  addiu      $v0, $zero, 0x480
    /* 2F46C 8003EC6C E40480A3 */  sb         $zero, %gp_rel(D_8009B3EC)($gp)
    /* 2F470 8003EC70 8E31020C */  jal        func_8008C638
    /* 2F474 8003EC74 1000A2AF */   sw        $v0, 0x10($sp)
    /* 2F478 8003EC78 6CFB0008 */  j          .L8003EDB0
    /* 2F47C 8003EC7C 00000000 */   nop
  .L8003EC80:
    /* 2F480 8003EC80 30004014 */  bnez       $v0, .L8003ED44
    /* 2F484 8003EC84 40006234 */   ori       $v0, $v1, 0x40
    /* 2F488 8003EC88 EC04848F */  lw         $a0, %gp_rel(D_8009B3F4)($gp)
    /* 2F48C 8003EC8C E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F490 8003EC90 07008010 */  beqz       $a0, .L8003ECB0
    /* 2F494 8003EC94 0D000224 */   addiu     $v0, $zero, 0xD
    /* 2F498 8003EC98 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F49C 8003EC9C 01000224 */  addiu      $v0, $zero, 0x1
    /* 2F4A0 8003ECA0 77008214 */  bne        $a0, $v0, .L8003EE80
    /* 2F4A4 8003ECA4 09000224 */   addiu     $v0, $zero, 0x9
    /* 2F4A8 8003ECA8 7BFB0008 */  j          .L8003EDEC
    /* 2F4AC 8003ECAC 00000000 */   nop
  .L8003ECB0:
    /* 2F4B0 8003ECB0 CC048293 */  lbu        $v0, %gp_rel(D_8009B3D4)($gp)
    /* 2F4B4 8003ECB4 00000000 */  nop
    /* 2F4B8 8003ECB8 20004014 */  bnez       $v0, .L8003ED3C
    /* 2F4BC 8003ECBC CF000424 */   addiu     $a0, $zero, 0xCF
    /* 2F4C0 8003ECC0 C804848F */  lw         $a0, %gp_rel(D_8009B3D0)($gp)
    /* 2F4C4 8003ECC4 1E80023C */  lui        $v0, %hi(D_801DC000)
    /* 2F4C8 8003ECC8 00C05024 */  addiu      $s0, $v0, %lo(D_801DC000)
    /* 2F4CC 8003ECCC AEF4000C */  jal        func_8003D2B8
    /* 2F4D0 8003ECD0 21280002 */   addu      $a1, $s0, $zero
    /* 2F4D4 8003ECD4 19004014 */  bnez       $v0, .L8003ED3C
    /* 2F4D8 8003ECD8 CF000424 */   addiu     $a0, $zero, 0xCF
    /* 2F4DC 8003ECDC E4048293 */  lbu        $v0, %gp_rel(D_8009B3EC)($gp)
    /* 2F4E0 8003ECE0 00000000 */  nop
    /* 2F4E4 8003ECE4 11004014 */  bnez       $v0, .L8003ED2C
    /* 2F4E8 8003ECE8 21200000 */   addu      $a0, $zero, $zero
    /* 2F4EC 8003ECEC 0F80053C */  lui        $a1, %hi(D_800EFE18)
    /* 2F4F0 8003ECF0 18FEA524 */  addiu      $a1, $a1, %lo(D_800EFE18)
    /* 2F4F4 8003ECF4 21300002 */  addu       $a2, $s0, $zero
    /* 2F4F8 8003ECF8 BC048797 */  lhu        $a3, %gp_rel(D_8009B3C4)($gp)
    /* 2F4FC 8003ECFC 01004224 */  addiu      $v0, $v0, 0x1
    /* 2F500 8003ED00 E40482A3 */  sb         $v0, %gp_rel(D_8009B3EC)($gp)
    /* 2F504 8003ED04 80040224 */  addiu      $v0, $zero, 0x480
    /* 2F508 8003ED08 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2F50C 8003ED0C E3048293 */  lbu        $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F510 8003ED10 00000000 */  nop
    /* 2F514 8003ED14 BF004230 */  andi       $v0, $v0, 0xBF
    /* 2F518 8003ED18 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F51C 8003ED1C 8E31020C */  jal        func_8008C638
    /* 2F520 8003ED20 8006E724 */   addiu     $a3, $a3, 0x680
    /* 2F524 8003ED24 6CFB0008 */  j          .L8003EDB0
    /* 2F528 8003ED28 00000000 */   nop
  .L8003ED2C:
    /* 2F52C 8003ED2C 0E000224 */  addiu      $v0, $zero, 0xE
  .L8003ED30:
    /* 2F530 8003ED30 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F534 8003ED34 A0FB0008 */  j          .L8003EE80
    /* 2F538 8003ED38 00000000 */   nop
  .L8003ED3C:
    /* 2F53C 8003ED3C 9EFB0008 */  j          .L8003EE78
    /* 2F540 8003ED40 20000524 */   addiu     $a1, $zero, 0x20
  .L8003ED44:
    /* 2F544 8003ED44 0A80023C */  lui        $v0, %hi(D_8009B34D)
    /* 2F548 8003ED48 4DB34280 */  lb         $v0, %lo(D_8009B34D)($v0)
    /* 2F54C 8003ED4C 00000000 */  nop
    /* 2F550 8003ED50 05004010 */  beqz       $v0, .L8003ED68
    /* 2F554 8003ED54 08000224 */   addiu     $v0, $zero, 0x8
  .L8003ED58:
    /* 2F558 8003ED58 0C000224 */  addiu      $v0, $zero, 0xC
  .L8003ED5C:
    /* 2F55C 8003ED5C E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F560 8003ED60 A0FB0008 */  j          .L8003EE80
    /* 2F564 8003ED64 00000000 */   nop
  .L8003ED68:
    /* 2F568 8003ED68 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
  jlabel .L8003ED6C
    /* 2F56C 8003ED6C E3048393 */  lbu        $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2F570 8003ED70 00000000 */  nop
    /* 2F574 8003ED74 80006230 */  andi       $v0, $v1, 0x80
    /* 2F578 8003ED78 13004014 */  bnez       $v0, .L8003EDC8
    /* 2F57C 8003ED7C D6000424 */   addiu     $a0, $zero, 0xD6
    /* 2F580 8003ED80 80006234 */  ori        $v0, $v1, 0x80
    /* 2F584 8003ED84 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F588 8003ED88 1BF9000C */  jal        func_8003E46C
    /* 2F58C 8003ED8C 21280000 */   addu      $a1, $zero, $zero
    /* 2F590 8003ED90 21200000 */  addu       $a0, $zero, $zero
    /* 2F594 8003ED94 0F80053C */  lui        $a1, %hi(D_800EFE18)
    /* 2F598 8003ED98 C804868F */  lw         $a2, %gp_rel(D_8009B3D0)($gp)
    /* 2F59C 8003ED9C BC048797 */  lhu        $a3, %gp_rel(D_8009B3C4)($gp)
    /* 2F5A0 8003EDA0 BA048297 */  lhu        $v0, %gp_rel(D_8009B3C2)($gp)
    /* 2F5A4 8003EDA4 18FEA524 */  addiu      $a1, $a1, %lo(D_800EFE18)
    /* 2F5A8 8003EDA8 1632020C */  jal        func_8008C858
    /* 2F5AC 8003EDAC 1000A2AF */   sw        $v0, 0x10($sp)
  .L8003EDB0:
    /* 2F5B0 8003EDB0 F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2F5B4 8003EDB4 00000000 */  nop
    /* 2F5B8 8003EDB8 00104234 */  ori        $v0, $v0, 0x1000
    /* 2F5BC 8003EDBC F20482A7 */  sh         $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2F5C0 8003EDC0 A0FB0008 */  j          .L8003EE80
    /* 2F5C4 8003EDC4 00000000 */   nop
  .L8003EDC8:
    /* 2F5C8 8003EDC8 EC04838F */  lw         $v1, %gp_rel(D_8009B3F4)($gp)
    /* 2F5CC 8003EDCC 00000000 */  nop
    /* 2F5D0 8003EDD0 09006010 */  beqz       $v1, .L8003EDF8
    /* 2F5D4 8003EDD4 0B000224 */   addiu     $v0, $zero, 0xB
    /* 2F5D8 8003EDD8 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F5DC 8003EDDC 01000224 */  addiu      $v0, $zero, 0x1
    /* 2F5E0 8003EDE0 27006214 */  bne        $v1, $v0, .L8003EE80
    /* 2F5E4 8003EDE4 00000000 */   nop
  jlabel .L8003EDE8
    /* 2F5E8 8003EDE8 09000224 */  addiu      $v0, $zero, 0x9
  .L8003EDEC:
    /* 2F5EC 8003EDEC E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F5F0 8003EDF0 A0FB0008 */  j          .L8003EE80
    /* 2F5F4 8003EDF4 00000000 */   nop
  .L8003EDF8:
    /* 2F5F8 8003EDF8 0A000224 */  addiu      $v0, $zero, 0xA
    /* 2F5FC 8003EDFC E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F600 8003EE00 A0FB0008 */  j          .L8003EE80
    /* 2F604 8003EE04 00000000 */   nop
  jlabel .L8003EE08
    /* 2F608 8003EE08 9DFB0008 */  j          .L8003EE74
    /* 2F60C 8003EE0C D2000424 */   addiu     $a0, $zero, 0xD2
  jlabel .L8003EE10
    /* 2F610 8003EE10 F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2F614 8003EE14 01000324 */  addiu      $v1, $zero, 0x1
    /* 2F618 8003EE18 E70483A3 */  sb         $v1, %gp_rel(D_8009B3EF)($gp)
    /* 2F61C 8003EE1C 00014230 */  andi       $v0, $v0, 0x100
    /* 2F620 8003EE20 06004014 */  bnez       $v0, .L8003EE3C
    /* 2F624 8003EE24 CC000624 */   addiu     $a2, $zero, 0xCC
    /* 2F628 8003EE28 B004828F */  lw         $v0, %gp_rel(D_8009B3B8)($gp)
    /* 2F62C 8003EE2C D1000624 */  addiu      $a2, $zero, 0xD1
    /* 2F630 8003EE30 CC0480A3 */  sb         $zero, %gp_rel(D_8009B3D4)($gp)
    /* 2F634 8003EE34 01004224 */  addiu      $v0, $v0, 0x1
    /* 2F638 8003EE38 B00482AF */  sw         $v0, %gp_rel(D_8009B3B8)($gp)
  .L8003EE3C:
    /* 2F63C 8003EE3C 9DFB0008 */  j          .L8003EE74
    /* 2F640 8003EE40 2120C000 */   addu      $a0, $a2, $zero
  jlabel .L8003EE44
    /* 2F644 8003EE44 9DFB0008 */  j          .L8003EE74
    /* 2F648 8003EE48 D9000424 */   addiu     $a0, $zero, 0xD9
  jlabel .L8003EE4C
    /* 2F64C 8003EE4C CD000424 */  addiu      $a0, $zero, 0xCD
    /* 2F650 8003EE50 1BF9000C */  jal        func_8003E46C
    /* 2F654 8003EE54 18000524 */   addiu     $a1, $zero, 0x18
    /* 2F658 8003EE58 03000224 */  addiu      $v0, $zero, 0x3
    /* 2F65C 8003EE5C E70482A3 */  sb         $v0, %gp_rel(D_8009B3EF)($gp)
    /* 2F660 8003EE60 A0FB0008 */  j          .L8003EE80
    /* 2F664 8003EE64 00000000 */   nop
  jlabel .L8003EE68
    /* 2F668 8003EE68 9DFB0008 */  j          .L8003EE74
    /* 2F66C 8003EE6C DA000424 */   addiu     $a0, $zero, 0xDA
  jlabel .L8003EE70
    /* 2F670 8003EE70 CE000424 */  addiu      $a0, $zero, 0xCE
  .L8003EE74:
    /* 2F674 8003EE74 18000524 */  addiu      $a1, $zero, 0x18
  .L8003EE78:
    /* 2F678 8003EE78 1BF9000C */  jal        func_8003E46C
    /* 2F67C 8003EE7C 00000000 */   nop
  .L8003EE80:
    /* 2F680 8003EE80 2400BF8F */  lw         $ra, 0x24($sp)
    /* 2F684 8003EE84 2000B08F */  lw         $s0, 0x20($sp)
    /* 2F688 8003EE88 0800E003 */  jr         $ra
    /* 2F68C 8003EE8C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003E854
