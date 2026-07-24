nonmatching func_8006AF74, 0xD30

glabel func_8006AF74
    /* 5B774 8006AF74 C8FEBD27 */  addiu      $sp, $sp, -0x138
    /* 5B778 8006AF78 1001B0AF */  sw         $s0, 0x110($sp)
    /* 5B77C 8006AF7C 21808000 */  addu       $s0, $a0, $zero
    /* 5B780 8006AF80 C000A927 */  addiu      $t1, $sp, 0xC0
    /* 5B784 8006AF84 21202001 */  addu       $a0, $t1, $zero
    /* 5B788 8006AF88 3C01A5AF */  sw         $a1, 0x13C($sp)
    /* 5B78C 8006AF8C 21280000 */  addu       $a1, $zero, $zero
    /* 5B790 8006AF90 08000624 */  addiu      $a2, $zero, 0x8
    /* 5B794 8006AF94 3401BFAF */  sw         $ra, 0x134($sp)
    /* 5B798 8006AF98 3001BEAF */  sw         $fp, 0x130($sp)
    /* 5B79C 8006AF9C 2C01B7AF */  sw         $s7, 0x12C($sp)
    /* 5B7A0 8006AFA0 2801B6AF */  sw         $s6, 0x128($sp)
    /* 5B7A4 8006AFA4 2401B5AF */  sw         $s5, 0x124($sp)
    /* 5B7A8 8006AFA8 2001B4AF */  sw         $s4, 0x120($sp)
    /* 5B7AC 8006AFAC 1C01B3AF */  sw         $s3, 0x11C($sp)
    /* 5B7B0 8006AFB0 1801B2AF */  sw         $s2, 0x118($sp)
    /* 5B7B4 8006AFB4 1401B1AF */  sw         $s1, 0x114($sp)
    /* 5B7B8 8006AFB8 F438020C */  jal        func_8008E3D0
    /* 5B7BC 8006AFBC F800A9AF */   sw        $t1, 0xF8($sp)
    /* 5B7C0 8006AFC0 C800AA27 */  addiu      $t2, $sp, 0xC8
    /* 5B7C4 8006AFC4 21204001 */  addu       $a0, $t2, $zero
    /* 5B7C8 8006AFC8 21280000 */  addu       $a1, $zero, $zero
    /* 5B7CC 8006AFCC 08000624 */  addiu      $a2, $zero, 0x8
    /* 5B7D0 8006AFD0 F438020C */  jal        func_8008E3D0
    /* 5B7D4 8006AFD4 FC00AAAF */   sw        $t2, 0xFC($sp)
    /* 5B7D8 8006AFD8 0180023C */  lui        $v0, %hi(D_8001185C)
    /* 5B7DC 8006AFDC 5C184A24 */  addiu      $t2, $v0, %lo(D_8001185C)
    /* 5B7E0 8006AFE0 00004B8D */  lw         $t3, 0x0($t2)
    /* 5B7E4 8006AFE4 04004C8D */  lw         $t4, 0x4($t2)
    /* 5B7E8 8006AFE8 0800498D */  lw         $t1, 0x8($t2)
    /* 5B7EC 8006AFEC D000ABAF */  sw         $t3, 0xD0($sp)
    /* 5B7F0 8006AFF0 D400ACAF */  sw         $t4, 0xD4($sp)
    /* 5B7F4 8006AFF4 D800A9AF */  sw         $t1, 0xD8($sp)
    /* 5B7F8 8006AFF8 0C004B8D */  lw         $t3, 0xC($t2)
    /* 5B7FC 8006AFFC 00000000 */  nop
    /* 5B800 8006B000 DC00ABAF */  sw         $t3, 0xDC($sp)
    /* 5B804 8006B004 7363010C */  jal        func_80058DCC
    /* 5B808 8006B008 21B80002 */   addu      $s7, $s0, $zero
    /* 5B80C 8006B00C 8763010C */  jal        func_80058E1C
    /* 5B810 8006B010 00000000 */   nop
    /* 5B814 8006B014 3C01AC8F */  lw         $t4, 0x13C($sp)
    /* 5B818 8006B018 D000AB27 */  addiu      $t3, $sp, 0xD0
    /* 5B81C 8006B01C 0001ABAF */  sw         $t3, 0x100($sp)
    /* 5B820 8006B020 C0008005 */  bltz       $t4, .L8006B324
    /* 5B824 8006B024 0401A2AF */   sw        $v0, 0x104($sp)
    /* 5B828 8006B028 0980023C */  lui        $v0, %hi(D_800915E8)
    /* 5B82C 8006B02C E8154224 */  addiu      $v0, $v0, %lo(D_800915E8)
    /* 5B830 8006B030 21F04000 */  addu       $fp, $v0, $zero
    /* 5B834 8006B034 7363010C */  jal        func_80058DCC
    /* 5B838 8006B038 0000FEAE */   sw        $fp, 0x0($s7)
    /* 5B83C 8006B03C 21204000 */  addu       $a0, $v0, $zero
    /* 5B840 8006B040 885F010C */  jal        func_80057E20
    /* 5B844 8006B044 E000A527 */   addiu     $a1, $sp, 0xE0
    /* 5B848 8006B048 E600A297 */  lhu        $v0, 0xE6($sp)
    /* 5B84C 8006B04C 00000000 */  nop
    /* 5B850 8006B050 00140200 */  sll        $v0, $v0, 16
    /* 5B854 8006B054 03340200 */  sra        $a2, $v0, 16
    /* 5B858 8006B058 2120C000 */  addu       $a0, $a2, $zero
    /* 5B85C 8006B05C C2170200 */  srl        $v0, $v0, 31
    /* 5B860 8006B060 21188200 */  addu       $v1, $a0, $v0
    /* 5B864 8006B064 43300300 */  sra        $a2, $v1, 1
    /* 5B868 8006B068 21106000 */  addu       $v0, $v1, $zero
    /* 5B86C 8006B06C 1400C387 */  lh         $v1, 0x14($fp)
    /* 5B870 8006B070 43200200 */  sra        $a0, $v0, 1
    /* 5B874 8006B074 2A10C300 */  slt        $v0, $a2, $v1
    /* 5B878 8006B078 04004014 */  bnez       $v0, .L8006B08C
    /* 5B87C 8006B07C BD02C228 */   slti      $v0, $a2, 0x2BD
    /* 5B880 8006B080 02004010 */  beqz       $v0, .L8006B08C
    /* 5B884 8006B084 BC020324 */   addiu     $v1, $zero, 0x2BC
    /* 5B888 8006B088 2118C000 */  addu       $v1, $a2, $zero
  .L8006B08C:
    /* 5B88C 8006B08C 1200C587 */  lh         $a1, 0x12($fp)
    /* 5B890 8006B090 00000000 */  nop
    /* 5B894 8006B094 2A108500 */  slt        $v0, $a0, $a1
    /* 5B898 8006B098 03004010 */  beqz       $v0, .L8006B0A8
    /* 5B89C 8006B09C 21306000 */   addu      $a2, $v1, $zero
    /* 5B8A0 8006B0A0 2EAC0108 */  j          .L8006B0B8
    /* 5B8A4 8006B0A4 2118A000 */   addu      $v1, $a1, $zero
  .L8006B0A8:
    /* 5B8A8 8006B0A8 BD028228 */  slti       $v0, $a0, 0x2BD
    /* 5B8AC 8006B0AC 02004010 */  beqz       $v0, .L8006B0B8
    /* 5B8B0 8006B0B0 BC020324 */   addiu     $v1, $zero, 0x2BC
    /* 5B8B4 8006B0B4 21188000 */  addu       $v1, $a0, $zero
  .L8006B0B8:
    /* 5B8B8 8006B0B8 21206000 */  addu       $a0, $v1, $zero
    /* 5B8BC 8006B0BC 0400F626 */  addiu      $s6, $s7, 0x4
    /* 5B8C0 8006B0C0 23100400 */  negu       $v0, $a0
    /* 5B8C4 8006B0C4 0400E0A6 */  sh         $zero, 0x4($s7)
    /* 5B8C8 8006B0C8 0200C2A6 */  sh         $v0, 0x2($s6)
    /* 5B8CC 8006B0CC 0400C0A6 */  sh         $zero, 0x4($s6)
    /* 5B8D0 8006B0D0 0C00F626 */  addiu      $s6, $s7, 0xC
    /* 5B8D4 8006B0D4 23100600 */  negu       $v0, $a2
    /* 5B8D8 8006B0D8 0C00E0A6 */  sh         $zero, 0xC($s7)
    /* 5B8DC 8006B0DC 0200C0A6 */  sh         $zero, 0x2($s6)
    /* 5B8E0 8006B0E0 0400C2A6 */  sh         $v0, 0x4($s6)
    /* 5B8E4 8006B0E4 1400F626 */  addiu      $s6, $s7, 0x14
    /* 5B8E8 8006B0E8 1400E2A6 */  sh         $v0, 0x14($s7)
    /* 5B8EC 8006B0EC 0200C0A6 */  sh         $zero, 0x2($s6)
    /* 5B8F0 8006B0F0 0400C0A6 */  sh         $zero, 0x4($s6)
    /* 5B8F4 8006B0F4 1C00F626 */  addiu      $s6, $s7, 0x1C
    /* 5B8F8 8006B0F8 1C00E0A6 */  sh         $zero, 0x1C($s7)
    /* 5B8FC 8006B0FC 0200C0A6 */  sh         $zero, 0x2($s6)
    /* 5B900 8006B100 0400C6A6 */  sh         $a2, 0x4($s6)
    /* 5B904 8006B104 2400F626 */  addiu      $s6, $s7, 0x24
    /* 5B908 8006B108 2400E6A6 */  sh         $a2, 0x24($s7)
    /* 5B90C 8006B10C 0200C0A6 */  sh         $zero, 0x2($s6)
    /* 5B910 8006B110 0400C0A6 */  sh         $zero, 0x4($s6)
    /* 5B914 8006B114 2C00F626 */  addiu      $s6, $s7, 0x2C
    /* 5B918 8006B118 940CF326 */  addiu      $s3, $s7, 0xC94
    /* 5B91C 8006B11C 21900000 */  addu       $s2, $zero, $zero
    /* 5B920 8006B120 2C00E0A6 */  sh         $zero, 0x2C($s7)
    /* 5B924 8006B124 0200C4A6 */  sh         $a0, 0x2($s6)
    /* 5B928 8006B128 0400C0A6 */  sh         $zero, 0x4($s6)
    /* 5B92C 8006B12C 21206002 */  addu       $a0, $s3, $zero
  .L8006B130:
    /* 5B930 8006B130 04007326 */  addiu      $s3, $s3, 0x4
    /* 5B934 8006B134 2110D203 */  addu       $v0, $fp, $s2
    /* 5B938 8006B138 00004590 */  lbu        $a1, 0x0($v0)
    /* 5B93C 8006B13C 06004690 */  lbu        $a2, 0x6($v0)
    /* 5B940 8006B140 0C004790 */  lbu        $a3, 0xC($v0)
    /* 5B944 8006B144 BFB0010C */  jal        func_8006C2FC
    /* 5B948 8006B148 01005226 */   addiu     $s2, $s2, 0x1
    /* 5B94C 8006B14C 0600422A */  slti       $v0, $s2, 0x6
    /* 5B950 8006B150 F7FF4014 */  bnez       $v0, .L8006B130
    /* 5B954 8006B154 21206002 */   addu      $a0, $s3, $zero
    /* 5B958 8006B158 0400F626 */  addiu      $s6, $s7, 0x4
    /* 5B95C 8006B15C 940CF326 */  addiu      $s3, $s7, 0xC94
    /* 5B960 8006B160 3400F126 */  addiu      $s1, $s7, 0x34
    /* 5B964 8006B164 AC0CF026 */  addiu      $s0, $s7, 0xCAC
    /* 5B968 8006B168 01001224 */  addiu      $s2, $zero, 0x1
    /* 5B96C 8006B16C 980CE526 */  addiu      $a1, $s7, 0xC98
    /* 5B970 8006B170 0C00E426 */  addiu      $a0, $s7, 0xC
  .L8006B174:
    /* 5B974 8006B174 000036AE */  sw         $s6, 0x0($s1)
    /* 5B978 8006B178 04003126 */  addiu      $s1, $s1, 0x4
    /* 5B97C 8006B17C 000013AE */  sw         $s3, 0x0($s0)
    /* 5B980 8006B180 04001026 */  addiu      $s0, $s0, 0x4
    /* 5B984 8006B184 000024AE */  sw         $a0, 0x0($s1)
    /* 5B988 8006B188 04003126 */  addiu      $s1, $s1, 0x4
    /* 5B98C 8006B18C 000005AE */  sw         $a1, 0x0($s0)
    /* 5B990 8006B190 04001026 */  addiu      $s0, $s0, 0x4
    /* 5B994 8006B194 02004106 */  bgez       $s2, .L8006B1A0
    /* 5B998 8006B198 21104002 */   addu      $v0, $s2, $zero
    /* 5B99C 8006B19C 03004226 */  addiu      $v0, $s2, 0x3
  .L8006B1A0:
    /* 5B9A0 8006B1A0 83100200 */  sra        $v0, $v0, 2
    /* 5B9A4 8006B1A4 80100200 */  sll        $v0, $v0, 2
    /* 5B9A8 8006B1A8 23104202 */  subu       $v0, $s2, $v0
    /* 5B9AC 8006B1AC C0180200 */  sll        $v1, $v0, 3
    /* 5B9B0 8006B1B0 04006324 */  addiu      $v1, $v1, 0x4
    /* 5B9B4 8006B1B4 2118E302 */  addu       $v1, $s7, $v1
    /* 5B9B8 8006B1B8 08006324 */  addiu      $v1, $v1, 0x8
    /* 5B9BC 8006B1BC 000023AE */  sw         $v1, 0x0($s1)
    /* 5B9C0 8006B1C0 04003126 */  addiu      $s1, $s1, 0x4
    /* 5B9C4 8006B1C4 80100200 */  sll        $v0, $v0, 2
    /* 5B9C8 8006B1C8 21105700 */  addu       $v0, $v0, $s7
    /* 5B9CC 8006B1CC 980C4224 */  addiu      $v0, $v0, 0xC98
    /* 5B9D0 8006B1D0 000002AE */  sw         $v0, 0x0($s0)
    /* 5B9D4 8006B1D4 04001026 */  addiu      $s0, $s0, 0x4
    /* 5B9D8 8006B1D8 0400A524 */  addiu      $a1, $a1, 0x4
    /* 5B9DC 8006B1DC 01005226 */  addiu      $s2, $s2, 0x1
    /* 5B9E0 8006B1E0 0500422A */  slti       $v0, $s2, 0x5
    /* 5B9E4 8006B1E4 E3FF4014 */  bnez       $v0, .L8006B174
    /* 5B9E8 8006B1E8 08008424 */   addiu     $a0, $a0, 0x8
    /* 5B9EC 8006B1EC 01001224 */  addiu      $s2, $zero, 0x1
    /* 5B9F0 8006B1F0 2800C626 */  addiu      $a2, $s6, 0x28
    /* 5B9F4 8006B1F4 14006526 */  addiu      $a1, $s3, 0x14
    /* 5B9F8 8006B1F8 04006726 */  addiu      $a3, $s3, 0x4
    /* 5B9FC 8006B1FC 0800C426 */  addiu      $a0, $s6, 0x8
  .L8006B200:
    /* 5BA00 8006B200 000026AE */  sw         $a2, 0x0($s1)
    /* 5BA04 8006B204 04003126 */  addiu      $s1, $s1, 0x4
    /* 5BA08 8006B208 000005AE */  sw         $a1, 0x0($s0)
    /* 5BA0C 8006B20C 04001026 */  addiu      $s0, $s0, 0x4
    /* 5BA10 8006B210 02004106 */  bgez       $s2, .L8006B21C
    /* 5BA14 8006B214 21104002 */   addu      $v0, $s2, $zero
    /* 5BA18 8006B218 03004226 */  addiu      $v0, $s2, 0x3
  .L8006B21C:
    /* 5BA1C 8006B21C 83100200 */  sra        $v0, $v0, 2
    /* 5BA20 8006B220 80100200 */  sll        $v0, $v0, 2
    /* 5BA24 8006B224 23104202 */  subu       $v0, $s2, $v0
    /* 5BA28 8006B228 C0180200 */  sll        $v1, $v0, 3
    /* 5BA2C 8006B22C 04006324 */  addiu      $v1, $v1, 0x4
    /* 5BA30 8006B230 2118E302 */  addu       $v1, $s7, $v1
    /* 5BA34 8006B234 08006324 */  addiu      $v1, $v1, 0x8
    /* 5BA38 8006B238 000023AE */  sw         $v1, 0x0($s1)
    /* 5BA3C 8006B23C 04003126 */  addiu      $s1, $s1, 0x4
    /* 5BA40 8006B240 80100200 */  sll        $v0, $v0, 2
    /* 5BA44 8006B244 21105700 */  addu       $v0, $v0, $s7
    /* 5BA48 8006B248 980C4224 */  addiu      $v0, $v0, 0xC98
    /* 5BA4C 8006B24C 000002AE */  sw         $v0, 0x0($s0)
    /* 5BA50 8006B250 04001026 */  addiu      $s0, $s0, 0x4
    /* 5BA54 8006B254 000024AE */  sw         $a0, 0x0($s1)
    /* 5BA58 8006B258 04003126 */  addiu      $s1, $s1, 0x4
    /* 5BA5C 8006B25C 000007AE */  sw         $a3, 0x0($s0)
    /* 5BA60 8006B260 04001026 */  addiu      $s0, $s0, 0x4
    /* 5BA64 8006B264 0400E724 */  addiu      $a3, $a3, 0x4
    /* 5BA68 8006B268 01005226 */  addiu      $s2, $s2, 0x1
    /* 5BA6C 8006B26C 0500422A */  slti       $v0, $s2, 0x5
    /* 5BA70 8006B270 E3FF4014 */  bnez       $v0, .L8006B200
    /* 5BA74 8006B274 08008424 */   addiu     $a0, $a0, 0x8
    /* 5BA78 8006B278 9400F626 */  addiu      $s6, $s7, 0x94
    /* 5BA7C 8006B27C 0C0DF326 */  addiu      $s3, $s7, 0xD0C
    /* 5BA80 8006B280 3400F126 */  addiu      $s1, $s7, 0x34
    /* 5BA84 8006B284 AC0CF026 */  addiu      $s0, $s7, 0xCAC
    /* 5BA88 8006B288 21900000 */  addu       $s2, $zero, $zero
    /* 5BA8C 8006B28C B40CF526 */  addiu      $s5, $s7, 0xCB4
    /* 5BA90 8006B290 3C00F426 */  addiu      $s4, $s7, 0x3C
    /* 5BA94 8006B294 2138C002 */  addu       $a3, $s6, $zero
  .L8006B298:
    /* 5BA98 8006B298 02000924 */  addiu      $t1, $zero, 0x2
    /* 5BA9C 8006B29C 1000A9AF */  sw         $t1, 0x10($sp)
    /* 5BAA0 8006B2A0 FCFF858E */  lw         $a1, -0x4($s4)
    /* 5BAA4 8006B2A4 0000868E */  lw         $a2, 0x0($s4)
    /* 5BAA8 8006B2A8 0C009426 */  addiu      $s4, $s4, 0xC
    /* 5BAAC 8006B2AC 0000248E */  lw         $a0, 0x0($s1)
    /* 5BAB0 8006B2B0 0C003126 */  addiu      $s1, $s1, 0xC
    /* 5BAB4 8006B2B4 8001D626 */  addiu      $s6, $s6, 0x180
    /* 5BAB8 8006B2B8 29AF010C */  jal        func_8006BCA4
    /* 5BABC 8006B2BC 01005226 */   addiu     $s2, $s2, 0x1
    /* 5BAC0 8006B2C0 21386002 */  addu       $a3, $s3, $zero
    /* 5BAC4 8006B2C4 02000A24 */  addiu      $t2, $zero, 0x2
    /* 5BAC8 8006B2C8 1000AAAF */  sw         $t2, 0x10($sp)
    /* 5BACC 8006B2CC FCFFA58E */  lw         $a1, -0x4($s5)
    /* 5BAD0 8006B2D0 0000A68E */  lw         $a2, 0x0($s5)
    /* 5BAD4 8006B2D4 0C00B526 */  addiu      $s5, $s5, 0xC
    /* 5BAD8 8006B2D8 0000048E */  lw         $a0, 0x0($s0)
    /* 5BADC 8006B2DC 0C001026 */  addiu      $s0, $s0, 0xC
    /* 5BAE0 8006B2E0 48B0010C */  jal        func_8006C120
    /* 5BAE4 8006B2E4 C0007326 */   addiu     $s3, $s3, 0xC0
    /* 5BAE8 8006B2E8 0800422A */  slti       $v0, $s2, 0x8
    /* 5BAEC 8006B2EC EAFF4014 */  bnez       $v0, .L8006B298
    /* 5BAF0 8006B2F0 2138C002 */   addu      $a3, $s6, $zero
    /* 5BAF4 8006B2F4 0180043C */  lui        $a0, %hi(D_8001186C)
    /* 5BAF8 8006B2F8 6C188424 */  addiu      $a0, $a0, %lo(D_8001186C)
    /* 5BAFC 8006B2FC 18130524 */  addiu      $a1, $zero, 0x1318
    /* 5BB00 8006B300 1013E0AE */  sw         $zero, 0x1310($s7)
    /* 5BB04 8006B304 1800C287 */  lh         $v0, 0x18($fp)
    /* 5BB08 8006B308 2130A000 */  addu       $a2, $a1, $zero
    /* 5BB0C 8006B30C 0C13E0A2 */  sb         $zero, 0x130C($s7)
    /* 5BB10 8006B310 0D13E0A2 */  sb         $zero, 0x130D($s7)
    /* 5BB14 8006B314 1C3A020C */  jal        func_8008E870
    /* 5BB18 8006B318 1413E2AE */   sw        $v0, 0x1314($s7)
    /* 5BB1C 8006B31C 1DAF0108 */  j          .L8006BC74
    /* 5BB20 8006B320 21100000 */   addu      $v0, $zero, $zero
  .L8006B324:
    /* 5BB24 8006B324 0000FE8E */  lw         $fp, 0x0($s7)
    /* 5BB28 8006B328 C463010C */  jal        func_80058F10
    /* 5BB2C 8006B32C 9400F626 */   addiu     $s6, $s7, 0x94
    /* 5BB30 8006B330 8864010C */  jal        func_80059220
    /* 5BB34 8006B334 F400A2AF */   sw        $v0, 0xF4($sp)
    /* 5BB38 8006B338 00004B8C */  lw         $t3, 0x0($v0)
    /* 5BB3C 8006B33C 04004C8C */  lw         $t4, 0x4($v0)
    /* 5BB40 8006B340 0800498C */  lw         $t1, 0x8($v0)
    /* 5BB44 8006B344 0C004A8C */  lw         $t2, 0xC($v0)
    /* 5BB48 8006B348 2800ABAF */  sw         $t3, 0x28($sp)
    /* 5BB4C 8006B34C 2C00ACAF */  sw         $t4, 0x2C($sp)
    /* 5BB50 8006B350 3000A9AF */  sw         $t1, 0x30($sp)
    /* 5BB54 8006B354 3400AAAF */  sw         $t2, 0x34($sp)
    /* 5BB58 8006B358 10004B8C */  lw         $t3, 0x10($v0)
    /* 5BB5C 8006B35C 14004C8C */  lw         $t4, 0x14($v0)
    /* 5BB60 8006B360 1800498C */  lw         $t1, 0x18($v0)
    /* 5BB64 8006B364 1C004A8C */  lw         $t2, 0x1C($v0)
    /* 5BB68 8006B368 3800ABAF */  sw         $t3, 0x38($sp)
    /* 5BB6C 8006B36C 3C00ACAF */  sw         $t4, 0x3C($sp)
    /* 5BB70 8006B370 4000A9AF */  sw         $t1, 0x40($sp)
    /* 5BB74 8006B374 4400AAAF */  sw         $t2, 0x44($sp)
    /* 5BB78 8006B378 741C020C */  jal        func_800871D0
    /* 5BB7C 8006B37C 0C0DF326 */   addiu     $s3, $s7, 0xD0C
    /* 5BB80 8006B380 380A020C */  jal        func_800828E0
    /* 5BB84 8006B384 6800A427 */   addiu     $a0, $sp, 0x68
    /* 5BB88 8006B388 580A020C */  jal        func_80082960
    /* 5BB8C 8006B38C 8800A427 */   addiu     $a0, $sp, 0x88
    /* 5BB90 8006B390 2800B127 */  addiu      $s1, $sp, 0x28
    /* 5BB94 8006B394 21202002 */  addu       $a0, $s1, $zero
    /* 5BB98 8006B398 0050023C */  lui        $v0, (0x50000000 >> 16)
    /* 5BB9C 8006B39C 0801A0AF */  sw         $zero, 0x108($sp)
    /* 5BBA0 8006B3A0 B000A2AF */  sw         $v0, 0xB0($sp)
    /* 5BBA4 8006B3A4 1013F58E */  lw         $s5, 0x1310($s7)
    /* 5BBA8 8006B3A8 1413F48E */  lw         $s4, 0x1314($s7)
    /* 5BBAC 8006B3AC 0E0DF226 */  addiu      $s2, $s7, 0xD0E
    /* 5BBB0 8006B3B0 C000A0A7 */  sh         $zero, 0xC0($sp)
    /* 5BBB4 8006B3B4 C400A0A7 */  sh         $zero, 0xC4($sp)
    /* 5BBB8 8006B3B8 40111500 */  sll        $v0, $s5, 5
    /* 5BBBC 8006B3BC 7415020C */  jal        func_800855D0
    /* 5BBC0 8006B3C0 C200A2A7 */   sh        $v0, 0xC2($sp)
    /* 5BBC4 8006B3C4 7363010C */  jal        func_80058DCC
    /* 5BBC8 8006B3C8 00000000 */   nop
    /* 5BBCC 8006B3CC FC00A58F */  lw         $a1, 0xFC($sp)
    /* 5BBD0 8006B3D0 EC63010C */  jal        func_80058FB0
    /* 5BBD4 8006B3D4 21204000 */   addu      $a0, $v0, $zero
    /* 5BBD8 8006B3D8 7415020C */  jal        func_800855D0
    /* 5BBDC 8006B3DC 21202002 */   addu      $a0, $s1, $zero
    /* 5BBE0 8006B3E0 5C00A527 */  addiu      $a1, $sp, 0x5C
    /* 5BBE4 8006B3E4 FC00A48F */  lw         $a0, 0xFC($sp)
    /* 5BBE8 8006B3E8 5C1E020C */  jal        func_80087970
    /* 5BBEC 8006B3EC E800A627 */   addiu     $a2, $sp, 0xE8
    /* 5BBF0 8006B3F0 4800B027 */  addiu      $s0, $sp, 0x48
    /* 5BBF4 8006B3F4 F800A48F */  lw         $a0, 0xF8($sp)
    /* 5BBF8 8006B3F8 4C1F020C */  jal        func_80087D30
    /* 5BBFC 8006B3FC 21280002 */   addu      $a1, $s0, $zero
    /* 5BC00 8006B400 21202002 */  addu       $a0, $s1, $zero
    /* 5BC04 8006B404 201D020C */  jal        func_80087480
    /* 5BC08 8006B408 21280002 */   addu      $a1, $s0, $zero
    /* 5BC0C 8006B40C 0001A58F */  lw         $a1, 0x100($sp)
    /* 5BC10 8006B410 9C1D020C */  jal        func_80087670
    /* 5BC14 8006B414 21200002 */   addu      $a0, $s0, $zero
    /* 5BC18 8006B418 7415020C */  jal        func_800855D0
    /* 5BC1C 8006B41C 21200002 */   addu      $a0, $s0, $zero
  .L8006B420:
    /* 5BC20 8006B420 2120C002 */  addu       $a0, $s6, $zero
    /* 5BC24 8006B424 0800C526 */  addiu      $a1, $s6, 0x8
    /* 5BC28 8006B428 1000C626 */  addiu      $a2, $s6, 0x10
    /* 5BC2C 8006B42C 7000A727 */  addiu      $a3, $sp, 0x70
    /* 5BC30 8006B430 7800A227 */  addiu      $v0, $sp, 0x78
    /* 5BC34 8006B434 1000A2AF */  sw         $v0, 0x10($sp)
    /* 5BC38 8006B438 8000A227 */  addiu      $v0, $sp, 0x80
    /* 5BC3C 8006B43C 1400A2AF */  sw         $v0, 0x14($sp)
    /* 5BC40 8006B440 EC00A227 */  addiu      $v0, $sp, 0xEC
    /* 5BC44 8006B444 1800A2AF */  sw         $v0, 0x18($sp)
    /* 5BC48 8006B448 F000A227 */  addiu      $v0, $sp, 0xF0
    /* 5BC4C 8006B44C 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 5BC50 8006B450 E800A227 */  addiu      $v0, $sp, 0xE8
    /* 5BC54 8006B454 CC1E020C */  jal        func_80087B30
    /* 5BC58 8006B458 2000A2AF */   sw        $v0, 0x20($sp)
    /* 5BC5C 8006B45C AF008006 */  bltz       $s4, .L8006B71C
    /* 5BC60 8006B460 21304000 */   addu      $a2, $v0, $zero
    /* 5BC64 8006B464 1800C387 */  lh         $v1, 0x18($fp)
    /* 5BC68 8006B468 00000000 */  nop
    /* 5BC6C 8006B46C 2A108302 */  slt        $v0, $s4, $v1
    /* 5BC70 8006B470 AA004010 */  beqz       $v0, .L8006B71C
    /* 5BC74 8006B474 00000000 */   nop
    /* 5BC78 8006B478 00006292 */  lbu        $v0, 0x0($s3)
    /* 5BC7C 8006B47C 00000000 */  nop
    /* 5BC80 8006B480 18005400 */  mult       $v0, $s4
    /* 5BC84 8006B484 12400000 */  mflo       $t0
    /* 5BC88 8006B488 00000000 */  nop
    /* 5BC8C 8006B48C 00000000 */  nop
    /* 5BC90 8006B490 1A000301 */  div        $zero, $t0, $v1
    /* 5BC94 8006B494 02006014 */  bnez       $v1, .L8006B4A0
    /* 5BC98 8006B498 00000000 */   nop
    /* 5BC9C 8006B49C 0D000700 */  break      7
  .L8006B4A0:
    /* 5BCA0 8006B4A0 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5BCA4 8006B4A4 04006114 */  bne        $v1, $at, .L8006B4B8
    /* 5BCA8 8006B4A8 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5BCAC 8006B4AC 02000115 */  bne        $t0, $at, .L8006B4B8
    /* 5BCB0 8006B4B0 00000000 */   nop
    /* 5BCB4 8006B4B4 0D000600 */  break      6
  .L8006B4B8:
    /* 5BCB8 8006B4B8 12280000 */  mflo       $a1
    /* 5BCBC 8006B4BC FFFF4292 */  lbu        $v0, -0x1($s2)
    /* 5BCC0 8006B4C0 00000000 */  nop
    /* 5BCC4 8006B4C4 18005400 */  mult       $v0, $s4
    /* 5BCC8 8006B4C8 12400000 */  mflo       $t0
    /* 5BCCC 8006B4CC 00000000 */  nop
    /* 5BCD0 8006B4D0 00000000 */  nop
    /* 5BCD4 8006B4D4 1A000301 */  div        $zero, $t0, $v1
    /* 5BCD8 8006B4D8 02006014 */  bnez       $v1, .L8006B4E4
    /* 5BCDC 8006B4DC 00000000 */   nop
    /* 5BCE0 8006B4E0 0D000700 */  break      7
  .L8006B4E4:
    /* 5BCE4 8006B4E4 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5BCE8 8006B4E8 04006114 */  bne        $v1, $at, .L8006B4FC
    /* 5BCEC 8006B4EC 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5BCF0 8006B4F0 02000115 */  bne        $t0, $at, .L8006B4FC
    /* 5BCF4 8006B4F4 00000000 */   nop
    /* 5BCF8 8006B4F8 0D000600 */  break      6
  .L8006B4FC:
    /* 5BCFC 8006B4FC 12200000 */  mflo       $a0
    /* 5BD00 8006B500 00004292 */  lbu        $v0, 0x0($s2)
    /* 5BD04 8006B504 00000000 */  nop
    /* 5BD08 8006B508 18005400 */  mult       $v0, $s4
    /* 5BD0C 8006B50C 12400000 */  mflo       $t0
    /* 5BD10 8006B510 00000000 */  nop
    /* 5BD14 8006B514 00000000 */  nop
    /* 5BD18 8006B518 1A000301 */  div        $zero, $t0, $v1
    /* 5BD1C 8006B51C 02006014 */  bnez       $v1, .L8006B528
    /* 5BD20 8006B520 00000000 */   nop
    /* 5BD24 8006B524 0D000700 */  break      7
  .L8006B528:
    /* 5BD28 8006B528 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5BD2C 8006B52C 04006114 */  bne        $v1, $at, .L8006B540
    /* 5BD30 8006B530 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5BD34 8006B534 02000115 */  bne        $t0, $at, .L8006B540
    /* 5BD38 8006B538 00000000 */   nop
    /* 5BD3C 8006B53C 0D000600 */  break      6
  .L8006B540:
    /* 5BD40 8006B540 12180000 */  mflo       $v1
    /* 5BD44 8006B544 04007326 */  addiu      $s3, $s3, 0x4
    /* 5BD48 8006B548 6C00A5A3 */  sb         $a1, 0x6C($sp)
    /* 5BD4C 8006B54C 6D00A4A3 */  sb         $a0, 0x6D($sp)
    /* 5BD50 8006B550 6E00A3A3 */  sb         $v1, 0x6E($sp)
    /* 5BD54 8006B554 00006292 */  lbu        $v0, 0x0($s3)
    /* 5BD58 8006B558 00000000 */  nop
    /* 5BD5C 8006B55C 18005400 */  mult       $v0, $s4
    /* 5BD60 8006B560 12400000 */  mflo       $t0
    /* 5BD64 8006B564 1800C387 */  lh         $v1, 0x18($fp)
    /* 5BD68 8006B568 00000000 */  nop
    /* 5BD6C 8006B56C 1A000301 */  div        $zero, $t0, $v1
    /* 5BD70 8006B570 02006014 */  bnez       $v1, .L8006B57C
    /* 5BD74 8006B574 00000000 */   nop
    /* 5BD78 8006B578 0D000700 */  break      7
  .L8006B57C:
    /* 5BD7C 8006B57C FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5BD80 8006B580 04006114 */  bne        $v1, $at, .L8006B594
    /* 5BD84 8006B584 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5BD88 8006B588 02000115 */  bne        $t0, $at, .L8006B594
    /* 5BD8C 8006B58C 00000000 */   nop
    /* 5BD90 8006B590 0D000600 */  break      6
  .L8006B594:
    /* 5BD94 8006B594 12280000 */  mflo       $a1
    /* 5BD98 8006B598 04005226 */  addiu      $s2, $s2, 0x4
    /* 5BD9C 8006B59C FFFF4292 */  lbu        $v0, -0x1($s2)
    /* 5BDA0 8006B5A0 00000000 */  nop
    /* 5BDA4 8006B5A4 18005400 */  mult       $v0, $s4
    /* 5BDA8 8006B5A8 12400000 */  mflo       $t0
    /* 5BDAC 8006B5AC 00000000 */  nop
    /* 5BDB0 8006B5B0 00000000 */  nop
    /* 5BDB4 8006B5B4 1A000301 */  div        $zero, $t0, $v1
    /* 5BDB8 8006B5B8 02006014 */  bnez       $v1, .L8006B5C4
    /* 5BDBC 8006B5BC 00000000 */   nop
    /* 5BDC0 8006B5C0 0D000700 */  break      7
  .L8006B5C4:
    /* 5BDC4 8006B5C4 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5BDC8 8006B5C8 04006114 */  bne        $v1, $at, .L8006B5DC
    /* 5BDCC 8006B5CC 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5BDD0 8006B5D0 02000115 */  bne        $t0, $at, .L8006B5DC
    /* 5BDD4 8006B5D4 00000000 */   nop
    /* 5BDD8 8006B5D8 0D000600 */  break      6
  .L8006B5DC:
    /* 5BDDC 8006B5DC 12200000 */  mflo       $a0
    /* 5BDE0 8006B5E0 00004292 */  lbu        $v0, 0x0($s2)
    /* 5BDE4 8006B5E4 00000000 */  nop
    /* 5BDE8 8006B5E8 18005400 */  mult       $v0, $s4
    /* 5BDEC 8006B5EC 12400000 */  mflo       $t0
    /* 5BDF0 8006B5F0 00000000 */  nop
    /* 5BDF4 8006B5F4 00000000 */  nop
    /* 5BDF8 8006B5F8 1A000301 */  div        $zero, $t0, $v1
    /* 5BDFC 8006B5FC 02006014 */  bnez       $v1, .L8006B608
    /* 5BE00 8006B600 00000000 */   nop
    /* 5BE04 8006B604 0D000700 */  break      7
  .L8006B608:
    /* 5BE08 8006B608 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5BE0C 8006B60C 04006114 */  bne        $v1, $at, .L8006B620
    /* 5BE10 8006B610 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5BE14 8006B614 02000115 */  bne        $t0, $at, .L8006B620
    /* 5BE18 8006B618 00000000 */   nop
    /* 5BE1C 8006B61C 0D000600 */  break      6
  .L8006B620:
    /* 5BE20 8006B620 12180000 */  mflo       $v1
    /* 5BE24 8006B624 04007326 */  addiu      $s3, $s3, 0x4
    /* 5BE28 8006B628 7400A5A3 */  sb         $a1, 0x74($sp)
    /* 5BE2C 8006B62C 7500A4A3 */  sb         $a0, 0x75($sp)
    /* 5BE30 8006B630 7600A3A3 */  sb         $v1, 0x76($sp)
    /* 5BE34 8006B634 00006292 */  lbu        $v0, 0x0($s3)
    /* 5BE38 8006B638 00000000 */  nop
    /* 5BE3C 8006B63C 18005400 */  mult       $v0, $s4
    /* 5BE40 8006B640 12400000 */  mflo       $t0
    /* 5BE44 8006B644 1800C387 */  lh         $v1, 0x18($fp)
    /* 5BE48 8006B648 00000000 */  nop
    /* 5BE4C 8006B64C 1A000301 */  div        $zero, $t0, $v1
    /* 5BE50 8006B650 02006014 */  bnez       $v1, .L8006B65C
    /* 5BE54 8006B654 00000000 */   nop
    /* 5BE58 8006B658 0D000700 */  break      7
  .L8006B65C:
    /* 5BE5C 8006B65C FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5BE60 8006B660 04006114 */  bne        $v1, $at, .L8006B674
    /* 5BE64 8006B664 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5BE68 8006B668 02000115 */  bne        $t0, $at, .L8006B674
    /* 5BE6C 8006B66C 00000000 */   nop
    /* 5BE70 8006B670 0D000600 */  break      6
  .L8006B674:
    /* 5BE74 8006B674 12280000 */  mflo       $a1
    /* 5BE78 8006B678 04005226 */  addiu      $s2, $s2, 0x4
    /* 5BE7C 8006B67C FFFF4292 */  lbu        $v0, -0x1($s2)
    /* 5BE80 8006B680 00000000 */  nop
    /* 5BE84 8006B684 18005400 */  mult       $v0, $s4
    /* 5BE88 8006B688 12400000 */  mflo       $t0
    /* 5BE8C 8006B68C 00000000 */  nop
    /* 5BE90 8006B690 00000000 */  nop
    /* 5BE94 8006B694 1A000301 */  div        $zero, $t0, $v1
    /* 5BE98 8006B698 02006014 */  bnez       $v1, .L8006B6A4
    /* 5BE9C 8006B69C 00000000 */   nop
    /* 5BEA0 8006B6A0 0D000700 */  break      7
  .L8006B6A4:
    /* 5BEA4 8006B6A4 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5BEA8 8006B6A8 04006114 */  bne        $v1, $at, .L8006B6BC
    /* 5BEAC 8006B6AC 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5BEB0 8006B6B0 02000115 */  bne        $t0, $at, .L8006B6BC
    /* 5BEB4 8006B6B4 00000000 */   nop
    /* 5BEB8 8006B6B8 0D000600 */  break      6
  .L8006B6BC:
    /* 5BEBC 8006B6BC 12200000 */  mflo       $a0
    /* 5BEC0 8006B6C0 00004292 */  lbu        $v0, 0x0($s2)
    /* 5BEC4 8006B6C4 00000000 */  nop
    /* 5BEC8 8006B6C8 18005400 */  mult       $v0, $s4
    /* 5BECC 8006B6CC 12400000 */  mflo       $t0
    /* 5BED0 8006B6D0 00000000 */  nop
    /* 5BED4 8006B6D4 00000000 */  nop
    /* 5BED8 8006B6D8 1A000301 */  div        $zero, $t0, $v1
    /* 5BEDC 8006B6DC 02006014 */  bnez       $v1, .L8006B6E8
    /* 5BEE0 8006B6E0 00000000 */   nop
    /* 5BEE4 8006B6E4 0D000700 */  break      7
  .L8006B6E8:
    /* 5BEE8 8006B6E8 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5BEEC 8006B6EC 04006114 */  bne        $v1, $at, .L8006B700
    /* 5BEF0 8006B6F0 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5BEF4 8006B6F4 02000115 */  bne        $t0, $at, .L8006B700
    /* 5BEF8 8006B6F8 00000000 */   nop
    /* 5BEFC 8006B6FC 0D000600 */  break      6
  .L8006B700:
    /* 5BF00 8006B700 12180000 */  mflo       $v1
    /* 5BF04 8006B704 04007326 */  addiu      $s3, $s3, 0x4
    /* 5BF08 8006B708 04005226 */  addiu      $s2, $s2, 0x4
    /* 5BF0C 8006B70C 7C00A5A3 */  sb         $a1, 0x7C($sp)
    /* 5BF10 8006B710 7D00A4A3 */  sb         $a0, 0x7D($sp)
    /* 5BF14 8006B714 5DAE0108 */  j          .L8006B974
    /* 5BF18 8006B718 7E00A3A3 */   sb        $v1, 0x7E($sp)
  .L8006B71C:
    /* 5BF1C 8006B71C 7A00A006 */  bltz       $s5, .L8006B908
    /* 5BF20 8006B720 00000000 */   nop
    /* 5BF24 8006B724 1600C387 */  lh         $v1, 0x16($fp)
    /* 5BF28 8006B728 00000000 */  nop
    /* 5BF2C 8006B72C 2A10A302 */  slt        $v0, $s5, $v1
    /* 5BF30 8006B730 75004010 */  beqz       $v0, .L8006B908
    /* 5BF34 8006B734 00000000 */   nop
    /* 5BF38 8006B738 00006292 */  lbu        $v0, 0x0($s3)
    /* 5BF3C 8006B73C 00000000 */  nop
    /* 5BF40 8006B740 18005500 */  mult       $v0, $s5
    /* 5BF44 8006B744 12400000 */  mflo       $t0
    /* 5BF48 8006B748 00000000 */  nop
    /* 5BF4C 8006B74C 00000000 */  nop
    /* 5BF50 8006B750 1A000301 */  div        $zero, $t0, $v1
    /* 5BF54 8006B754 02006014 */  bnez       $v1, .L8006B760
    /* 5BF58 8006B758 00000000 */   nop
    /* 5BF5C 8006B75C 0D000700 */  break      7
  .L8006B760:
    /* 5BF60 8006B760 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5BF64 8006B764 04006114 */  bne        $v1, $at, .L8006B778
    /* 5BF68 8006B768 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5BF6C 8006B76C 02000115 */  bne        $t0, $at, .L8006B778
    /* 5BF70 8006B770 00000000 */   nop
    /* 5BF74 8006B774 0D000600 */  break      6
  .L8006B778:
    /* 5BF78 8006B778 12280000 */  mflo       $a1
    /* 5BF7C 8006B77C FFFF4292 */  lbu        $v0, -0x1($s2)
    /* 5BF80 8006B780 00000000 */  nop
    /* 5BF84 8006B784 18005500 */  mult       $v0, $s5
    /* 5BF88 8006B788 12400000 */  mflo       $t0
    /* 5BF8C 8006B78C 00000000 */  nop
    /* 5BF90 8006B790 00000000 */  nop
    /* 5BF94 8006B794 1A000301 */  div        $zero, $t0, $v1
    /* 5BF98 8006B798 02006014 */  bnez       $v1, .L8006B7A4
    /* 5BF9C 8006B79C 00000000 */   nop
    /* 5BFA0 8006B7A0 0D000700 */  break      7
  .L8006B7A4:
    /* 5BFA4 8006B7A4 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5BFA8 8006B7A8 04006114 */  bne        $v1, $at, .L8006B7BC
    /* 5BFAC 8006B7AC 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5BFB0 8006B7B0 02000115 */  bne        $t0, $at, .L8006B7BC
    /* 5BFB4 8006B7B4 00000000 */   nop
    /* 5BFB8 8006B7B8 0D000600 */  break      6
  .L8006B7BC:
    /* 5BFBC 8006B7BC 12200000 */  mflo       $a0
    /* 5BFC0 8006B7C0 00004292 */  lbu        $v0, 0x0($s2)
    /* 5BFC4 8006B7C4 00000000 */  nop
    /* 5BFC8 8006B7C8 18005500 */  mult       $v0, $s5
    /* 5BFCC 8006B7CC 12400000 */  mflo       $t0
    /* 5BFD0 8006B7D0 00000000 */  nop
    /* 5BFD4 8006B7D4 00000000 */  nop
    /* 5BFD8 8006B7D8 1A000301 */  div        $zero, $t0, $v1
    /* 5BFDC 8006B7DC 02006014 */  bnez       $v1, .L8006B7E8
    /* 5BFE0 8006B7E0 00000000 */   nop
    /* 5BFE4 8006B7E4 0D000700 */  break      7
  .L8006B7E8:
    /* 5BFE8 8006B7E8 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5BFEC 8006B7EC 04006114 */  bne        $v1, $at, .L8006B800
    /* 5BFF0 8006B7F0 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5BFF4 8006B7F4 02000115 */  bne        $t0, $at, .L8006B800
    /* 5BFF8 8006B7F8 00000000 */   nop
    /* 5BFFC 8006B7FC 0D000600 */  break      6
  .L8006B800:
    /* 5C000 8006B800 12180000 */  mflo       $v1
    /* 5C004 8006B804 04007326 */  addiu      $s3, $s3, 0x4
    /* 5C008 8006B808 6C00A5A3 */  sb         $a1, 0x6C($sp)
    /* 5C00C 8006B80C 6D00A4A3 */  sb         $a0, 0x6D($sp)
    /* 5C010 8006B810 6E00A3A3 */  sb         $v1, 0x6E($sp)
    /* 5C014 8006B814 00006292 */  lbu        $v0, 0x0($s3)
    /* 5C018 8006B818 00000000 */  nop
    /* 5C01C 8006B81C 18005500 */  mult       $v0, $s5
    /* 5C020 8006B820 12400000 */  mflo       $t0
    /* 5C024 8006B824 1600C387 */  lh         $v1, 0x16($fp)
    /* 5C028 8006B828 00000000 */  nop
    /* 5C02C 8006B82C 1A000301 */  div        $zero, $t0, $v1
    /* 5C030 8006B830 02006014 */  bnez       $v1, .L8006B83C
    /* 5C034 8006B834 00000000 */   nop
    /* 5C038 8006B838 0D000700 */  break      7
  .L8006B83C:
    /* 5C03C 8006B83C FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5C040 8006B840 04006114 */  bne        $v1, $at, .L8006B854
    /* 5C044 8006B844 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5C048 8006B848 02000115 */  bne        $t0, $at, .L8006B854
    /* 5C04C 8006B84C 00000000 */   nop
    /* 5C050 8006B850 0D000600 */  break      6
  .L8006B854:
    /* 5C054 8006B854 12280000 */  mflo       $a1
    /* 5C058 8006B858 04005226 */  addiu      $s2, $s2, 0x4
    /* 5C05C 8006B85C FFFF4292 */  lbu        $v0, -0x1($s2)
    /* 5C060 8006B860 00000000 */  nop
    /* 5C064 8006B864 18005500 */  mult       $v0, $s5
    /* 5C068 8006B868 12400000 */  mflo       $t0
    /* 5C06C 8006B86C 00000000 */  nop
    /* 5C070 8006B870 00000000 */  nop
    /* 5C074 8006B874 1A000301 */  div        $zero, $t0, $v1
    /* 5C078 8006B878 02006014 */  bnez       $v1, .L8006B884
    /* 5C07C 8006B87C 00000000 */   nop
    /* 5C080 8006B880 0D000700 */  break      7
  .L8006B884:
    /* 5C084 8006B884 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5C088 8006B888 04006114 */  bne        $v1, $at, .L8006B89C
    /* 5C08C 8006B88C 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5C090 8006B890 02000115 */  bne        $t0, $at, .L8006B89C
    /* 5C094 8006B894 00000000 */   nop
    /* 5C098 8006B898 0D000600 */  break      6
  .L8006B89C:
    /* 5C09C 8006B89C 12200000 */  mflo       $a0
    /* 5C0A0 8006B8A0 00004292 */  lbu        $v0, 0x0($s2)
    /* 5C0A4 8006B8A4 00000000 */  nop
    /* 5C0A8 8006B8A8 18005500 */  mult       $v0, $s5
    /* 5C0AC 8006B8AC 12400000 */  mflo       $t0
    /* 5C0B0 8006B8B0 00000000 */  nop
    /* 5C0B4 8006B8B4 00000000 */  nop
    /* 5C0B8 8006B8B8 1A000301 */  div        $zero, $t0, $v1
    /* 5C0BC 8006B8BC 02006014 */  bnez       $v1, .L8006B8C8
    /* 5C0C0 8006B8C0 00000000 */   nop
    /* 5C0C4 8006B8C4 0D000700 */  break      7
  .L8006B8C8:
    /* 5C0C8 8006B8C8 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5C0CC 8006B8CC 04006114 */  bne        $v1, $at, .L8006B8E0
    /* 5C0D0 8006B8D0 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5C0D4 8006B8D4 02000115 */  bne        $t0, $at, .L8006B8E0
    /* 5C0D8 8006B8D8 00000000 */   nop
    /* 5C0DC 8006B8DC 0D000600 */  break      6
  .L8006B8E0:
    /* 5C0E0 8006B8E0 12180000 */  mflo       $v1
    /* 5C0E4 8006B8E4 08007326 */  addiu      $s3, $s3, 0x8
    /* 5C0E8 8006B8E8 08005226 */  addiu      $s2, $s2, 0x8
    /* 5C0EC 8006B8EC 7400A5A3 */  sb         $a1, 0x74($sp)
    /* 5C0F0 8006B8F0 7C00A5A3 */  sb         $a1, 0x7C($sp)
    /* 5C0F4 8006B8F4 7500A4A3 */  sb         $a0, 0x75($sp)
    /* 5C0F8 8006B8F8 7D00A4A3 */  sb         $a0, 0x7D($sp)
    /* 5C0FC 8006B8FC 7600A3A3 */  sb         $v1, 0x76($sp)
    /* 5C100 8006B900 5DAE0108 */  j          .L8006B974
    /* 5C104 8006B904 7E00A3A3 */   sb        $v1, 0x7E($sp)
  .L8006B908:
    /* 5C108 8006B908 00006292 */  lbu        $v0, 0x0($s3)
    /* 5C10C 8006B90C 00000000 */  nop
    /* 5C110 8006B910 6C00A2A3 */  sb         $v0, 0x6C($sp)
    /* 5C114 8006B914 FFFF4292 */  lbu        $v0, -0x1($s2)
    /* 5C118 8006B918 00000000 */  nop
    /* 5C11C 8006B91C 6D00A2A3 */  sb         $v0, 0x6D($sp)
    /* 5C120 8006B920 00004292 */  lbu        $v0, 0x0($s2)
    /* 5C124 8006B924 04007326 */  addiu      $s3, $s3, 0x4
    /* 5C128 8006B928 6E00A2A3 */  sb         $v0, 0x6E($sp)
    /* 5C12C 8006B92C 00006292 */  lbu        $v0, 0x0($s3)
    /* 5C130 8006B930 04005226 */  addiu      $s2, $s2, 0x4
    /* 5C134 8006B934 7400A2A3 */  sb         $v0, 0x74($sp)
    /* 5C138 8006B938 FFFF4292 */  lbu        $v0, -0x1($s2)
    /* 5C13C 8006B93C 00000000 */  nop
    /* 5C140 8006B940 7500A2A3 */  sb         $v0, 0x75($sp)
    /* 5C144 8006B944 00004292 */  lbu        $v0, 0x0($s2)
    /* 5C148 8006B948 04007326 */  addiu      $s3, $s3, 0x4
    /* 5C14C 8006B94C 7600A2A3 */  sb         $v0, 0x76($sp)
    /* 5C150 8006B950 00006292 */  lbu        $v0, 0x0($s3)
    /* 5C154 8006B954 04005226 */  addiu      $s2, $s2, 0x4
    /* 5C158 8006B958 7C00A2A3 */  sb         $v0, 0x7C($sp)
    /* 5C15C 8006B95C FFFF4292 */  lbu        $v0, -0x1($s2)
    /* 5C160 8006B960 04007326 */  addiu      $s3, $s3, 0x4
    /* 5C164 8006B964 7D00A2A3 */  sb         $v0, 0x7D($sp)
    /* 5C168 8006B968 00004292 */  lbu        $v0, 0x0($s2)
    /* 5C16C 8006B96C 04005226 */  addiu      $s2, $s2, 0x4
    /* 5C170 8006B970 7E00A2A3 */  sb         $v0, 0x7E($sp)
  .L8006B974:
    /* 5C174 8006B974 F000A28F */  lw         $v0, 0xF0($sp)
    /* 5C178 8006B978 00000000 */  nop
    /* 5C17C 8006B97C 0B004004 */  bltz       $v0, .L8006B9AC
    /* 5C180 8006B980 00000000 */   nop
    /* 5C184 8006B984 E800A28F */  lw         $v0, 0xE8($sp)
    /* 5C188 8006B988 00000000 */  nop
    /* 5C18C 8006B98C 07004004 */  bltz       $v0, .L8006B9AC
    /* 5C190 8006B990 00000000 */   nop
    /* 5C194 8006B994 0500C018 */  blez       $a2, .L8006B9AC
    /* 5C198 8006B998 6800A427 */   addiu     $a0, $sp, 0x68
    /* 5C19C 8006B99C F400A58F */  lw         $a1, 0xF4($sp)
    /* 5C1A0 8006B9A0 F000A697 */  lhu        $a2, 0xF0($sp)
    /* 5C1A4 8006B9A4 986C010C */  jal        func_8005B260
    /* 5C1A8 8006B9A8 01000724 */   addiu     $a3, $zero, 0x1
  .L8006B9AC:
    /* 5C1AC 8006B9AC 0801A98F */  lw         $t1, 0x108($sp)
    /* 5C1B0 8006B9B0 1800D626 */  addiu      $s6, $s6, 0x18
    /* 5C1B4 8006B9B4 01002925 */  addiu      $t1, $t1, 0x1
    /* 5C1B8 8006B9B8 80002229 */  slti       $v0, $t1, 0x80
    /* 5C1BC 8006B9BC 98FE4014 */  bnez       $v0, .L8006B420
    /* 5C1C0 8006B9C0 0801A9AF */   sw        $t1, 0x108($sp)
    /* 5C1C4 8006B9C4 25008006 */  bltz       $s4, .L8006BA5C
    /* 5C1C8 8006B9C8 00000000 */   nop
    /* 5C1CC 8006B9CC 1800C487 */  lh         $a0, 0x18($fp)
    /* 5C1D0 8006B9D0 00000000 */  nop
    /* 5C1D4 8006B9D4 2A108402 */  slt        $v0, $s4, $a0
    /* 5C1D8 8006B9D8 20004010 */  beqz       $v0, .L8006BA5C
    /* 5C1DC 8006B9DC 40191400 */   sll       $v1, $s4, 5
    /* 5C1E0 8006B9E0 1A006400 */  div        $zero, $v1, $a0
    /* 5C1E4 8006B9E4 02008014 */  bnez       $a0, .L8006B9F0
    /* 5C1E8 8006B9E8 00000000 */   nop
    /* 5C1EC 8006B9EC 0D000700 */  break      7
  .L8006B9F0:
    /* 5C1F0 8006B9F0 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5C1F4 8006B9F4 04008114 */  bne        $a0, $at, .L8006BA08
    /* 5C1F8 8006B9F8 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5C1FC 8006B9FC 02006114 */  bne        $v1, $at, .L8006BA08
    /* 5C200 8006BA00 00000000 */   nop
    /* 5C204 8006BA04 0D000600 */  break      6
  .L8006BA08:
    /* 5C208 8006BA08 12100000 */  mflo       $v0
    /* 5C20C 8006BA0C 00000000 */  nop
    /* 5C210 8006BA10 BC00A2A3 */  sb         $v0, 0xBC($sp)
    /* 5C214 8006BA14 1800C287 */  lh         $v0, 0x18($fp)
    /* 5C218 8006BA18 00000000 */  nop
    /* 5C21C 8006BA1C 1A006200 */  div        $zero, $v1, $v0
    /* 5C220 8006BA20 02004014 */  bnez       $v0, .L8006BA2C
    /* 5C224 8006BA24 00000000 */   nop
    /* 5C228 8006BA28 0D000700 */  break      7
  .L8006BA2C:
    /* 5C22C 8006BA2C FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5C230 8006BA30 04004114 */  bne        $v0, $at, .L8006BA44
    /* 5C234 8006BA34 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5C238 8006BA38 02006114 */  bne        $v1, $at, .L8006BA44
    /* 5C23C 8006BA3C 00000000 */   nop
    /* 5C240 8006BA40 0D000600 */  break      6
  .L8006BA44:
    /* 5C244 8006BA44 12100000 */  mflo       $v0
    /* 5C248 8006BA48 00000000 */  nop
    /* 5C24C 8006BA4C BD00A2A3 */  sb         $v0, 0xBD($sp)
    /* 5C250 8006BA50 1800C287 */  lh         $v0, 0x18($fp)
    /* 5C254 8006BA54 BBAE0108 */  j          .L8006BAEC
    /* 5C258 8006BA58 00000000 */   nop
  .L8006BA5C:
    /* 5C25C 8006BA5C 3200A006 */  bltz       $s5, .L8006BB28
    /* 5C260 8006BA60 20000224 */   addiu     $v0, $zero, 0x20
    /* 5C264 8006BA64 1600C487 */  lh         $a0, 0x16($fp)
    /* 5C268 8006BA68 00000000 */  nop
    /* 5C26C 8006BA6C 2A10A402 */  slt        $v0, $s5, $a0
    /* 5C270 8006BA70 2C004010 */  beqz       $v0, .L8006BB24
    /* 5C274 8006BA74 40191500 */   sll       $v1, $s5, 5
    /* 5C278 8006BA78 1A006400 */  div        $zero, $v1, $a0
    /* 5C27C 8006BA7C 02008014 */  bnez       $a0, .L8006BA88
    /* 5C280 8006BA80 00000000 */   nop
    /* 5C284 8006BA84 0D000700 */  break      7
  .L8006BA88:
    /* 5C288 8006BA88 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5C28C 8006BA8C 04008114 */  bne        $a0, $at, .L8006BAA0
    /* 5C290 8006BA90 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5C294 8006BA94 02006114 */  bne        $v1, $at, .L8006BAA0
    /* 5C298 8006BA98 00000000 */   nop
    /* 5C29C 8006BA9C 0D000600 */  break      6
  .L8006BAA0:
    /* 5C2A0 8006BAA0 12100000 */  mflo       $v0
    /* 5C2A4 8006BAA4 00000000 */  nop
    /* 5C2A8 8006BAA8 BC00A2A3 */  sb         $v0, 0xBC($sp)
    /* 5C2AC 8006BAAC 1600C287 */  lh         $v0, 0x16($fp)
    /* 5C2B0 8006BAB0 00000000 */  nop
    /* 5C2B4 8006BAB4 1A006200 */  div        $zero, $v1, $v0
    /* 5C2B8 8006BAB8 02004014 */  bnez       $v0, .L8006BAC4
    /* 5C2BC 8006BABC 00000000 */   nop
    /* 5C2C0 8006BAC0 0D000700 */  break      7
  .L8006BAC4:
    /* 5C2C4 8006BAC4 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5C2C8 8006BAC8 04004114 */  bne        $v0, $at, .L8006BADC
    /* 5C2CC 8006BACC 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5C2D0 8006BAD0 02006114 */  bne        $v1, $at, .L8006BADC
    /* 5C2D4 8006BAD4 00000000 */   nop
    /* 5C2D8 8006BAD8 0D000600 */  break      6
  .L8006BADC:
    /* 5C2DC 8006BADC 12100000 */  mflo       $v0
    /* 5C2E0 8006BAE0 00000000 */  nop
    /* 5C2E4 8006BAE4 BD00A2A3 */  sb         $v0, 0xBD($sp)
    /* 5C2E8 8006BAE8 1600C287 */  lh         $v0, 0x16($fp)
  .L8006BAEC:
    /* 5C2EC 8006BAEC 00000000 */  nop
    /* 5C2F0 8006BAF0 1A006200 */  div        $zero, $v1, $v0
    /* 5C2F4 8006BAF4 02004014 */  bnez       $v0, .L8006BB00
    /* 5C2F8 8006BAF8 00000000 */   nop
    /* 5C2FC 8006BAFC 0D000700 */  break      7
  .L8006BB00:
    /* 5C300 8006BB00 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 5C304 8006BB04 04004114 */  bne        $v0, $at, .L8006BB18
    /* 5C308 8006BB08 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 5C30C 8006BB0C 02006114 */  bne        $v1, $at, .L8006BB18
    /* 5C310 8006BB10 00000000 */   nop
    /* 5C314 8006BB14 0D000600 */  break      6
  .L8006BB18:
    /* 5C318 8006BB18 12180000 */  mflo       $v1
    /* 5C31C 8006BB1C CDAE0108 */  j          .L8006BB34
    /* 5C320 8006BB20 BE00A3A3 */   sb        $v1, 0xBE($sp)
  .L8006BB24:
    /* 5C324 8006BB24 20000224 */  addiu      $v0, $zero, 0x20
  .L8006BB28:
    /* 5C328 8006BB28 BC00A2A3 */  sb         $v0, 0xBC($sp)
    /* 5C32C 8006BB2C BD00A2A3 */  sb         $v0, 0xBD($sp)
    /* 5C330 8006BB30 BE00A2A3 */  sb         $v0, 0xBE($sp)
  .L8006BB34:
    /* 5C334 8006BB34 3400F126 */  addiu      $s1, $s7, 0x34
    /* 5C338 8006BB38 21900000 */  addu       $s2, $zero, $zero
    /* 5C33C 8006BB3C B000B327 */  addiu      $s3, $sp, 0xB0
    /* 5C340 8006BB40 3C00F026 */  addiu      $s0, $s7, 0x3C
  .L8006BB44:
    /* 5C344 8006BB44 7800A227 */  addiu      $v0, $sp, 0x78
    /* 5C348 8006BB48 1000A2AF */  sw         $v0, 0x10($sp)
    /* 5C34C 8006BB4C 8000A227 */  addiu      $v0, $sp, 0x80
    /* 5C350 8006BB50 1400A2AF */  sw         $v0, 0x14($sp)
    /* 5C354 8006BB54 EC00A227 */  addiu      $v0, $sp, 0xEC
    /* 5C358 8006BB58 1800A2AF */  sw         $v0, 0x18($sp)
    /* 5C35C 8006BB5C F000A227 */  addiu      $v0, $sp, 0xF0
    /* 5C360 8006BB60 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 5C364 8006BB64 E800A227 */  addiu      $v0, $sp, 0xE8
    /* 5C368 8006BB68 2000A2AF */  sw         $v0, 0x20($sp)
    /* 5C36C 8006BB6C 0000248E */  lw         $a0, 0x0($s1)
    /* 5C370 8006BB70 FCFF058E */  lw         $a1, -0x4($s0)
    /* 5C374 8006BB74 0000068E */  lw         $a2, 0x0($s0)
    /* 5C378 8006BB78 CC1E020C */  jal        func_80087B30
    /* 5C37C 8006BB7C 7000A727 */   addiu     $a3, $sp, 0x70
    /* 5C380 8006BB80 F000A38F */  lw         $v1, 0xF0($sp)
    /* 5C384 8006BB84 00000000 */  nop
    /* 5C388 8006BB88 22006004 */  bltz       $v1, .L8006BC14
    /* 5C38C 8006BB8C 21304000 */   addu      $a2, $v0, $zero
    /* 5C390 8006BB90 E800A28F */  lw         $v0, 0xE8($sp)
    /* 5C394 8006BB94 00000000 */  nop
    /* 5C398 8006BB98 1E004004 */  bltz       $v0, .L8006BC14
    /* 5C39C 8006BB9C 00000000 */   nop
    /* 5C3A0 8006BBA0 1C00C018 */  blez       $a2, .L8006BC14
    /* 5C3A4 8006BBA4 21206002 */   addu      $a0, $s3, $zero
    /* 5C3A8 8006BBA8 F000A697 */  lhu        $a2, 0xF0($sp)
    /* 5C3AC 8006BBAC 7000A297 */  lhu        $v0, 0x70($sp)
    /* 5C3B0 8006BBB0 7200A397 */  lhu        $v1, 0x72($sp)
    /* 5C3B4 8006BBB4 7800A797 */  lhu        $a3, 0x78($sp)
    /* 5C3B8 8006BBB8 7A00A897 */  lhu        $t0, 0x7A($sp)
    /* 5C3BC 8006BBBC F400A58F */  lw         $a1, 0xF4($sp)
    /* 5C3C0 8006BBC0 B400A2A7 */  sh         $v0, 0xB4($sp)
    /* 5C3C4 8006BBC4 B600A3A7 */  sh         $v1, 0xB6($sp)
    /* 5C3C8 8006BBC8 B800A7A7 */  sh         $a3, 0xB8($sp)
    /* 5C3CC 8006BBCC EC0F020C */  jal        func_80083FB0
    /* 5C3D0 8006BBD0 BA00A8A7 */   sh        $t0, 0xBA($sp)
    /* 5C3D4 8006BBD4 F000A697 */  lhu        $a2, 0xF0($sp)
    /* 5C3D8 8006BBD8 8000A297 */  lhu        $v0, 0x80($sp)
    /* 5C3DC 8006BBDC 8200A397 */  lhu        $v1, 0x82($sp)
    /* 5C3E0 8006BBE0 F400A58F */  lw         $a1, 0xF4($sp)
    /* 5C3E4 8006BBE4 21206002 */  addu       $a0, $s3, $zero
    /* 5C3E8 8006BBE8 B400A2A7 */  sh         $v0, 0xB4($sp)
    /* 5C3EC 8006BBEC EC0F020C */  jal        func_80083FB0
    /* 5C3F0 8006BBF0 B600A3A7 */   sh        $v1, 0xB6($sp)
    /* 5C3F4 8006BBF4 F000A697 */  lhu        $a2, 0xF0($sp)
    /* 5C3F8 8006BBF8 7000A297 */  lhu        $v0, 0x70($sp)
    /* 5C3FC 8006BBFC 7200A397 */  lhu        $v1, 0x72($sp)
    /* 5C400 8006BC00 F400A58F */  lw         $a1, 0xF4($sp)
    /* 5C404 8006BC04 21206002 */  addu       $a0, $s3, $zero
    /* 5C408 8006BC08 B800A2A7 */  sh         $v0, 0xB8($sp)
    /* 5C40C 8006BC0C EC0F020C */  jal        func_80083FB0
    /* 5C410 8006BC10 BA00A3A7 */   sh        $v1, 0xBA($sp)
  .L8006BC14:
    /* 5C414 8006BC14 0C001026 */  addiu      $s0, $s0, 0xC
    /* 5C418 8006BC18 01005226 */  addiu      $s2, $s2, 0x1
    /* 5C41C 8006BC1C 0800422A */  slti       $v0, $s2, 0x8
    /* 5C420 8006BC20 C8FF4014 */  bnez       $v0, .L8006BB44
    /* 5C424 8006BC24 0C003126 */   addiu     $s1, $s1, 0xC
    /* 5C428 8006BC28 9D1C020C */  jal        func_80087274
    /* 5C42C 8006BC2C 00000000 */   nop
    /* 5C430 8006BC30 1013E28E */  lw         $v0, 0x1310($s7)
    /* 5C434 8006BC34 0401A98F */  lw         $t1, 0x104($sp)
    /* 5C438 8006BC38 00000000 */  nop
    /* 5C43C 8006BC3C 21104900 */  addu       $v0, $v0, $t1
    /* 5C440 8006BC40 1013E2AE */  sw         $v0, 0x1310($s7)
    /* 5C444 8006BC44 3C01AA8F */  lw         $t2, 0x13C($sp)
    /* 5C448 8006BC48 FEFF0224 */  addiu      $v0, $zero, -0x2
    /* 5C44C 8006BC4C 05004215 */  bne        $t2, $v0, .L8006BC64
    /* 5C450 8006BC50 00000000 */   nop
    /* 5C454 8006BC54 1413E28E */  lw         $v0, 0x1314($s7)
    /* 5C458 8006BC58 00000000 */  nop
    /* 5C45C 8006BC5C 23104900 */  subu       $v0, $v0, $t1
    /* 5C460 8006BC60 1413E2AE */  sw         $v0, 0x1314($s7)
  .L8006BC64:
    /* 5C464 8006BC64 1413E28E */  lw         $v0, 0x1314($s7)
    /* 5C468 8006BC68 00000000 */  nop
    /* 5C46C 8006BC6C C3170200 */  sra        $v0, $v0, 31
    /* 5C470 8006BC70 02004230 */  andi       $v0, $v0, 0x2
  .L8006BC74:
    /* 5C474 8006BC74 3401BF8F */  lw         $ra, 0x134($sp)
    /* 5C478 8006BC78 3001BE8F */  lw         $fp, 0x130($sp)
    /* 5C47C 8006BC7C 2C01B78F */  lw         $s7, 0x12C($sp)
    /* 5C480 8006BC80 2801B68F */  lw         $s6, 0x128($sp)
    /* 5C484 8006BC84 2401B58F */  lw         $s5, 0x124($sp)
    /* 5C488 8006BC88 2001B48F */  lw         $s4, 0x120($sp)
    /* 5C48C 8006BC8C 1C01B38F */  lw         $s3, 0x11C($sp)
    /* 5C490 8006BC90 1801B28F */  lw         $s2, 0x118($sp)
    /* 5C494 8006BC94 1401B18F */  lw         $s1, 0x114($sp)
    /* 5C498 8006BC98 1001B08F */  lw         $s0, 0x110($sp)
    /* 5C49C 8006BC9C 0800E003 */  jr         $ra
    /* 5C4A0 8006BCA0 3801BD27 */   addiu     $sp, $sp, 0x138
endlabel func_8006AF74
