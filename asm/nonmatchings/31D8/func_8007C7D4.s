nonmatching func_8007C7D4, 0x288

glabel func_8007C7D4
    /* 6CFD4 8007C7D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6CFD8 8007C7D8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6CFDC 8007C7DC 2180A000 */  addu       $s0, $a1, $zero
    /* 6CFE0 8007C7E0 0980053C */  lui        $a1, %hi(D_800938A4)
    /* 6CFE4 8007C7E4 A438A524 */  addiu      $a1, $a1, %lo(D_800938A4)
    /* 6CFE8 8007C7E8 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6CFEC 8007C7EC 0000A28C */  lw         $v0, 0x0($a1)
    /* 6CFF0 8007C7F0 0C000324 */  addiu      $v1, $zero, 0xC
    /* 6CFF4 8007C7F4 04004314 */  bne        $v0, $v1, .L8007C808
    /* 6CFF8 8007C7F8 FF008230 */   andi      $v0, $a0, 0xFF
    /* 6CFFC 8007C7FC 0D000224 */  addiu      $v0, $zero, 0xD
    /* 6D000 8007C800 0000A2AC */  sw         $v0, 0x0($a1)
    /* 6D004 8007C804 FF008230 */  andi       $v0, $a0, 0xFF
  .L8007C808:
    /* 6D008 8007C808 02000624 */  addiu      $a2, $zero, 0x2
    /* 6D00C 8007C80C 7E004614 */  bne        $v0, $a2, .L8007CA08
    /* 6D010 8007C810 0D000224 */   addiu     $v0, $zero, 0xD
    /* 6D014 8007C814 0000A48C */  lw         $a0, 0x0($a1)
    /* 6D018 8007C818 00000000 */  nop
    /* 6D01C 8007C81C 0E008214 */  bne        $a0, $v0, .L8007C858
    /* 6D020 8007C820 0E000224 */   addiu     $v0, $zero, 0xE
    /* 6D024 8007C824 F4FFA290 */  lbu        $v0, -0xC($a1)
    /* 6D028 8007C828 00000000 */  nop
    /* 6D02C 8007C82C 10004230 */  andi       $v0, $v0, 0x10
    /* 6D030 8007C830 86004014 */  bnez       $v0, .L8007CA4C
    /* 6D034 8007C834 0E000224 */   addiu     $v0, $zero, 0xE
    /* 6D038 8007C838 0000A2AC */  sw         $v0, 0x0($a1)
    /* 6D03C 8007C83C 1800A28C */  lw         $v0, 0x18($a1)
    /* 6D040 8007C840 15000324 */  addiu      $v1, $zero, 0x15
    /* 6D044 8007C844 FCFFA6AC */  sw         $a2, -0x4($a1)
    /* 6D048 8007C848 0400A3AC */  sw         $v1, 0x4($a1)
    /* 6D04C 8007C84C 01004224 */  addiu      $v0, $v0, 0x1
    /* 6D050 8007C850 93F20108 */  j          .L8007CA4C
    /* 6D054 8007C854 1800A2AC */   sw        $v0, 0x18($a1)
  .L8007C858:
    /* 6D058 8007C858 3E008214 */  bne        $a0, $v0, .L8007C954
    /* 6D05C 8007C85C F0FF8224 */   addiu     $v0, $a0, -0x10
    /* 6D060 8007C860 0400A38C */  lw         $v1, 0x4($a1)
    /* 6D064 8007C864 15000224 */  addiu      $v0, $zero, 0x15
    /* 6D068 8007C868 0B006214 */  bne        $v1, $v0, .L8007C898
    /* 6D06C 8007C86C 16000224 */   addiu     $v0, $zero, 0x16
    /* 6D070 8007C870 F4FFA290 */  lbu        $v0, -0xC($a1)
    /* 6D074 8007C874 00000000 */  nop
    /* 6D078 8007C878 10004230 */  andi       $v0, $v0, 0x10
    /* 6D07C 8007C87C 73004014 */  bnez       $v0, .L8007CA4C
    /* 6D080 8007C880 16000224 */   addiu     $v0, $zero, 0x16
    /* 6D084 8007C884 FCFFA6AC */  sw         $a2, -0x4($a1)
    /* 6D088 8007C888 0000A4AC */  sw         $a0, 0x0($a1)
    /* 6D08C 8007C88C 0400A2AC */  sw         $v0, 0x4($a1)
    /* 6D090 8007C890 93F20108 */  j          .L8007CA4C
    /* 6D094 8007C894 1400A0AC */   sw        $zero, 0x14($a1)
  .L8007C898:
    /* 6D098 8007C898 15006214 */  bne        $v1, $v0, .L8007C8F0
    /* 6D09C 8007C89C 17000224 */   addiu     $v0, $zero, 0x17
    /* 6D0A0 8007C8A0 F4FFA290 */  lbu        $v0, -0xC($a1)
    /* 6D0A4 8007C8A4 00000000 */  nop
    /* 6D0A8 8007C8A8 02004230 */  andi       $v0, $v0, 0x2
    /* 6D0AC 8007C8AC 12004014 */  bnez       $v0, .L8007C8F8
    /* 6D0B0 8007C8B0 17000224 */   addiu     $v0, $zero, 0x17
    /* 6D0B4 8007C8B4 1400A28C */  lw         $v0, 0x14($a1)
    /* 6D0B8 8007C8B8 00000000 */  nop
    /* 6D0BC 8007C8BC 2D014228 */  slti       $v0, $v0, 0x12D
    /* 6D0C0 8007C8C0 62004014 */  bnez       $v0, .L8007CA4C
    /* 6D0C4 8007C8C4 00000000 */   nop
    /* 6D0C8 8007C8C8 0F80033C */  lui        $v1, %hi(D_800F5F8C)
    /* 6D0CC 8007C8CC 8C5F638C */  lw         $v1, %lo(D_800F5F8C)($v1)
    /* 6D0D0 8007C8D0 03000224 */  addiu      $v0, $zero, 0x3
    /* 6D0D4 8007C8D4 5D006010 */  beqz       $v1, .L8007CA4C
    /* 6D0D8 8007C8D8 FCFFA2AC */   sw        $v0, -0x4($a1)
    /* 6D0DC 8007C8DC 05000424 */  addiu      $a0, $zero, 0x5
    /* 6D0E0 8007C8E0 0F80023C */  lui        $v0, %hi(D_800F5F8C)
    /* 6D0E4 8007C8E4 8C5F428C */  lw         $v0, %lo(D_800F5F8C)($v0)
    /* 6D0E8 8007C8E8 7EF20108 */  j          .L8007C9F8
    /* 6D0EC 8007C8EC 00000000 */   nop
  .L8007C8F0:
    /* 6D0F0 8007C8F0 05006214 */  bne        $v1, $v0, .L8007C908
    /* 6D0F4 8007C8F4 18000224 */   addiu     $v0, $zero, 0x18
  .L8007C8F8:
    /* 6D0F8 8007C8F8 FCFFA6AC */  sw         $a2, -0x4($a1)
    /* 6D0FC 8007C8FC 0000A4AC */  sw         $a0, 0x0($a1)
    /* 6D100 8007C900 93F20108 */  j          .L8007CA4C
    /* 6D104 8007C904 0400A2AC */   sw        $v0, 0x4($a1)
  .L8007C908:
    /* 6D108 8007C908 50006214 */  bne        $v1, $v0, .L8007CA4C
    /* 6D10C 8007C90C 00000000 */   nop
    /* 6D110 8007C910 F4FFA290 */  lbu        $v0, -0xC($a1)
    /* 6D114 8007C914 00000000 */  nop
    /* 6D118 8007C918 4C004614 */  bne        $v0, $a2, .L8007CA4C
    /* 6D11C 8007C91C 00000000 */   nop
    /* 6D120 8007C920 0F80033C */  lui        $v1, %hi(D_800F5F8C)
    /* 6D124 8007C924 8C5F638C */  lw         $v1, %lo(D_800F5F8C)($v1)
    /* 6D128 8007C928 01000224 */  addiu      $v0, $zero, 0x1
    /* 6D12C 8007C92C FCFFA2AC */  sw         $v0, -0x4($a1)
    /* 6D130 8007C930 0B000224 */  addiu      $v0, $zero, 0xB
    /* 6D134 8007C934 0000A2AC */  sw         $v0, 0x0($a1)
    /* 6D138 8007C938 44006010 */  beqz       $v1, .L8007CA4C
    /* 6D13C 8007C93C 0400A0AC */   sw        $zero, 0x4($a1)
    /* 6D140 8007C940 02000424 */  addiu      $a0, $zero, 0x2
    /* 6D144 8007C944 0F80023C */  lui        $v0, %hi(D_800F5F8C)
    /* 6D148 8007C948 8C5F428C */  lw         $v0, %lo(D_800F5F8C)($v0)
    /* 6D14C 8007C94C 7EF20108 */  j          .L8007C9F8
    /* 6D150 8007C950 00000000 */   nop
  .L8007C954:
    /* 6D154 8007C954 0200422C */  sltiu      $v0, $v0, 0x2
    /* 6D158 8007C958 3C004010 */  beqz       $v0, .L8007CA4C
    /* 6D15C 8007C95C 00000000 */   nop
    /* 6D160 8007C960 2800A28C */  lw         $v0, 0x28($a1)
    /* 6D164 8007C964 00000000 */  nop
    /* 6D168 8007C968 38004014 */  bnez       $v0, .L8007CA4C
    /* 6D16C 8007C96C 00000000 */   nop
    /* 6D170 8007C970 F4FFA290 */  lbu        $v0, -0xC($a1)
    /* 6D174 8007C974 00000000 */  nop
    /* 6D178 8007C978 02004230 */  andi       $v0, $v0, 0x2
    /* 6D17C 8007C97C 33004014 */  bnez       $v0, .L8007CA4C
    /* 6D180 8007C980 00000000 */   nop
    /* 6D184 8007C984 0F80033C */  lui        $v1, %hi(D_800F5F88)
    /* 6D188 8007C988 885F638C */  lw         $v1, %lo(D_800F5F88)($v1)
    /* 6D18C 8007C98C 01000224 */  addiu      $v0, $zero, 0x1
    /* 6D190 8007C990 FCFFA2AC */  sw         $v0, -0x4($a1)
    /* 6D194 8007C994 0B000224 */  addiu      $v0, $zero, 0xB
    /* 6D198 8007C998 0A006010 */  beqz       $v1, .L8007C9C4
    /* 6D19C 8007C99C 0000A2AC */   sw        $v0, 0x0($a1)
    /* 6D1A0 8007C9A0 DCFFA28C */  lw         $v0, -0x24($a1)
    /* 6D1A4 8007C9A4 00000000 */  nop
    /* 6D1A8 8007C9A8 06004010 */  beqz       $v0, .L8007C9C4
    /* 6D1AC 8007C9AC 05000424 */   addiu     $a0, $zero, 0x5
    /* 6D1B0 8007C9B0 0F80023C */  lui        $v0, %hi(D_800F5F88)
    /* 6D1B4 8007C9B4 885F428C */  lw         $v0, %lo(D_800F5F88)($v0)
    /* 6D1B8 8007C9B8 00000000 */  nop
    /* 6D1BC 8007C9BC 09F84000 */  jalr       $v0
    /* 6D1C0 8007C9C0 21280002 */   addu      $a1, $s0, $zero
  .L8007C9C4:
    /* 6D1C4 8007C9C4 0F80023C */  lui        $v0, %hi(D_800F5F84)
    /* 6D1C8 8007C9C8 845F428C */  lw         $v0, %lo(D_800F5F84)($v0)
    /* 6D1CC 8007C9CC 00000000 */  nop
    /* 6D1D0 8007C9D0 1E004010 */  beqz       $v0, .L8007CA4C
    /* 6D1D4 8007C9D4 00000000 */   nop
    /* 6D1D8 8007C9D8 0980023C */  lui        $v0, %hi(D_80093880)
    /* 6D1DC 8007C9DC 8038428C */  lw         $v0, %lo(D_80093880)($v0)
    /* 6D1E0 8007C9E0 00000000 */  nop
    /* 6D1E4 8007C9E4 19004010 */  beqz       $v0, .L8007CA4C
    /* 6D1E8 8007C9E8 05000424 */   addiu     $a0, $zero, 0x5
    /* 6D1EC 8007C9EC 0F80023C */  lui        $v0, %hi(D_800F5F84)
    /* 6D1F0 8007C9F0 845F428C */  lw         $v0, %lo(D_800F5F84)($v0)
    /* 6D1F4 8007C9F4 00000000 */  nop
  .L8007C9F8:
    /* 6D1F8 8007C9F8 09F84000 */  jalr       $v0
    /* 6D1FC 8007C9FC 21280002 */   addu      $a1, $s0, $zero
    /* 6D200 8007CA00 93F20108 */  j          .L8007CA4C
    /* 6D204 8007CA04 00000000 */   nop
  .L8007CA08:
    /* 6D208 8007CA08 F4FFA290 */  lbu        $v0, -0xC($a1)
    /* 6D20C 8007CA0C 00000000 */  nop
    /* 6D210 8007CA10 10004230 */  andi       $v0, $v0, 0x10
    /* 6D214 8007CA14 04004010 */  beqz       $v0, .L8007CA28
    /* 6D218 8007CA18 00000000 */   nop
    /* 6D21C 8007CA1C FCFFA6AC */  sw         $a2, -0x4($a1)
    /* 6D220 8007CA20 93F20108 */  j          .L8007CA4C
    /* 6D224 8007CA24 0000A3AC */   sw        $v1, 0x0($a1)
  .L8007CA28:
    /* 6D228 8007CA28 0000A28C */  lw         $v0, 0x0($a1)
    /* 6D22C 8007CA2C 00000000 */  nop
    /* 6D230 8007CA30 F0FF4224 */  addiu      $v0, $v0, -0x10
    /* 6D234 8007CA34 0200422C */  sltiu      $v0, $v0, 0x2
    /* 6D238 8007CA38 04004010 */  beqz       $v0, .L8007CA4C
    /* 6D23C 8007CA3C 01000224 */   addiu     $v0, $zero, 0x1
    /* 6D240 8007CA40 FCFFA2AC */  sw         $v0, -0x4($a1)
    /* 6D244 8007CA44 0B000224 */  addiu      $v0, $zero, 0xB
    /* 6D248 8007CA48 0000A2AC */  sw         $v0, 0x0($a1)
  .L8007CA4C:
    /* 6D24C 8007CA4C 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6D250 8007CA50 1000B08F */  lw         $s0, 0x10($sp)
    /* 6D254 8007CA54 0800E003 */  jr         $ra
    /* 6D258 8007CA58 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007C7D4
