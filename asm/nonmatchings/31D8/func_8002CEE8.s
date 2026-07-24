nonmatching func_8002CEE8, 0x1F8

glabel func_8002CEE8
    /* 1D6E8 8002CEE8 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1D6EC 8002CEEC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1D6F0 8002CEF0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 1D6F4 8002CEF4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1D6F8 8002CEF8 40006230 */  andi       $v0, $v1, 0x40
    /* 1D6FC 8002CEFC 13004014 */  bnez       $v0, .L8002CF4C
    /* 1D700 8002CF00 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1D704 8002CF04 40006234 */  ori        $v0, $v1, 0x40
    /* 1D708 8002CF08 0A80033C */  lui        $v1, %hi(D_8009B369)
    /* 1D70C 8002CF0C 69B36390 */  lbu        $v1, %lo(D_8009B369)($v1)
    /* 1D710 8002CF10 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1D714 8002CF14 01000224 */  addiu      $v0, $zero, 0x1
    /* 1D718 8002CF18 660382A3 */  sb         $v0, %gp_rel(D_8009B26E)($gp)
    /* 1D71C 8002CF1C 07006014 */  bnez       $v1, .L8002CF3C
    /* 1D720 8002CF20 0A000224 */   addiu     $v0, $zero, 0xA
    /* 1D724 8002CF24 0A80023C */  lui        $v0, %hi(D_8009B361)
    /* 1D728 8002CF28 61B34280 */  lb         $v0, %lo(D_8009B361)($v0)
    /* 1D72C 8002CF2C 00000000 */  nop
    /* 1D730 8002CF30 02004004 */  bltz       $v0, .L8002CF3C
    /* 1D734 8002CF34 0A000224 */   addiu     $v0, $zero, 0xA
    /* 1D738 8002CF38 660380A3 */  sb         $zero, %gp_rel(D_8009B26E)($gp)
  .L8002CF3C:
    /* 1D73C 8002CF3C 0A80013C */  lui        $at, %hi(D_8009B0A3)
    /* 1D740 8002CF40 A3B022A0 */  sb         $v0, %lo(D_8009B0A3)($at)
    /* 1D744 8002CF44 33B40008 */  j          .L8002D0CC
    /* 1D748 8002CF48 00000000 */   nop
  .L8002CF4C:
    /* 1D74C 8002CF4C 66038393 */  lbu        $v1, %gp_rel(D_8009B26E)($gp)
    /* 1D750 8002CF50 01001124 */  addiu      $s1, $zero, 0x1
    /* 1D754 8002CF54 0F007030 */  andi       $s0, $v1, 0xF
    /* 1D758 8002CF58 2A001112 */  beq        $s0, $s1, .L8002D004
    /* 1D75C 8002CF5C 0200022A */   slti      $v0, $s0, 0x2
    /* 1D760 8002CF60 05004010 */  beqz       $v0, .L8002CF78
    /* 1D764 8002CF64 00000000 */   nop
    /* 1D768 8002CF68 08000012 */  beqz       $s0, .L8002CF8C
    /* 1D76C 8002CF6C 80006230 */   andi      $v0, $v1, 0x80
    /* 1D770 8002CF70 33B40008 */  j          .L8002D0CC
    /* 1D774 8002CF74 00000000 */   nop
  .L8002CF78:
    /* 1D778 8002CF78 02000224 */  addiu      $v0, $zero, 0x2
    /* 1D77C 8002CF7C 34000212 */  beq        $s0, $v0, .L8002D050
    /* 1D780 8002CF80 00000000 */   nop
    /* 1D784 8002CF84 33B40008 */  j          .L8002D0CC
    /* 1D788 8002CF88 00000000 */   nop
  .L8002CF8C:
    /* 1D78C 8002CF8C 10004014 */  bnez       $v0, .L8002CFD0
    /* 1D790 8002CF90 80006234 */   ori       $v0, $v1, 0x80
    /* 1D794 8002CF94 660382A3 */  sb         $v0, %gp_rel(D_8009B26E)($gp)
    /* 1D798 8002CF98 80000224 */  addiu      $v0, $zero, 0x80
    /* 1D79C 8002CF9C 1D80053C */  lui        $a1, %hi(D_801D0200)
    /* 1D7A0 8002CFA0 0002A524 */  addiu      $a1, $a1, %lo(D_801D0200)
    /* 1D7A4 8002CFA4 21300000 */  addu       $a2, $zero, $zero
    /* 1D7A8 8002CFA8 0180043C */  lui        $a0, %hi(D_80010000)
    /* 1D7AC 8002CFAC 0000848C */  lw         $a0, %lo(D_80010000)($a0)
    /* 1D7B0 8002CFB0 0A80013C */  lui        $at, %hi(D_8009B2F8)
    /* 1D7B4 8002CFB4 F8B222A0 */  sb         $v0, %lo(D_8009B2F8)($at)
    /* 1D7B8 8002CFB8 FEC8000C */  jal        func_800323F8
    /* 1D7BC 8002CFBC 80000724 */   addiu     $a3, $zero, 0x80
    /* 1D7C0 8002CFC0 8056000C */  jal        func_80015A00
    /* 1D7C4 8002CFC4 00000000 */   nop
    /* 1D7C8 8002CFC8 33B40008 */  j          .L8002D0CC
    /* 1D7CC 8002CFCC 00000000 */   nop
  .L8002CFD0:
    /* 1D7D0 8002CFD0 FACE000C */  jal        func_80033BE8
    /* 1D7D4 8002CFD4 00000000 */   nop
    /* 1D7D8 8002CFD8 3C004014 */  bnez       $v0, .L8002D0CC
    /* 1D7DC 8002CFDC 00000000 */   nop
    /* 1D7E0 8002CFE0 CDFF000C */  jal        func_8003FF34
    /* 1D7E4 8002CFE4 00000000 */   nop
    /* 1D7E8 8002CFE8 C056000C */  jal        func_80015B00
    /* 1D7EC 8002CFEC 00000000 */   nop
    /* 1D7F0 8002CFF0 63B3000C */  jal        func_8002CD8C
    /* 1D7F4 8002CFF4 00000000 */   nop
    /* 1D7F8 8002CFF8 660391A3 */  sb         $s1, %gp_rel(D_8009B26E)($gp)
    /* 1D7FC 8002CFFC 33B40008 */  j          .L8002D0CC
    /* 1D800 8002D000 00000000 */   nop
  .L8002D004:
    /* 1D804 8002D004 80006230 */  andi       $v0, $v1, 0x80
    /* 1D808 8002D008 06004014 */  bnez       $v0, .L8002D024
    /* 1D80C 8002D00C 80006234 */   ori       $v0, $v1, 0x80
    /* 1D810 8002D010 660382A3 */  sb         $v0, %gp_rel(D_8009B26E)($gp)
    /* 1D814 8002D014 7D5E000C */  jal        func_800179F4
    /* 1D818 8002D018 00000000 */   nop
    /* 1D81C 8002D01C 33B40008 */  j          .L8002D0CC
    /* 1D820 8002D020 00000000 */   nop
  .L8002D024:
    /* 1D824 8002D024 E290000C */  jal        func_80024388
    /* 1D828 8002D028 00000000 */   nop
    /* 1D82C 8002D02C 0A80023C */  lui        $v0, %hi(D_8009B16C)
    /* 1D830 8002D030 6CB14294 */  lhu        $v0, %lo(D_8009B16C)($v0)
    /* 1D834 8002D034 00000000 */  nop
    /* 1D838 8002D038 00204230 */  andi       $v0, $v0, 0x2000
    /* 1D83C 8002D03C 23004010 */  beqz       $v0, .L8002D0CC
    /* 1D840 8002D040 02000224 */   addiu     $v0, $zero, 0x2
    /* 1D844 8002D044 660382A3 */  sb         $v0, %gp_rel(D_8009B26E)($gp)
    /* 1D848 8002D048 33B40008 */  j          .L8002D0CC
    /* 1D84C 8002D04C 00000000 */   nop
  .L8002D050:
    /* 1D850 8002D050 C056000C */  jal        func_80015B00
    /* 1D854 8002D054 00000000 */   nop
    /* 1D858 8002D058 CDFF000C */  jal        func_8003FF34
    /* 1D85C 8002D05C 00000000 */   nop
    /* 1D860 8002D060 B41E010C */  jal        func_80047AD0
    /* 1D864 8002D064 02000424 */   addiu     $a0, $zero, 0x2
    /* 1D868 8002D068 2D4D000C */  jal        func_800134B4
    /* 1D86C 8002D06C 00000000 */   nop
    /* 1D870 8002D070 06000224 */  addiu      $v0, $zero, 0x6
    /* 1D874 8002D074 0A80013C */  lui        $at, %hi(D_8009B0A3)
    /* 1D878 8002D078 A3B022A0 */  sb         $v0, %lo(D_8009B0A3)($at)
    /* 1D87C 8002D07C 614B000C */  jal        func_80012D84
    /* 1D880 8002D080 04000424 */   addiu     $a0, $zero, 0x4
    /* 1D884 8002D084 F94D000C */  jal        func_800137E4
    /* 1D888 8002D088 00000000 */   nop
    /* 1D88C 8002D08C 0A80023C */  lui        $v0, %hi(D_8009B368)
    /* 1D890 8002D090 68B34290 */  lbu        $v0, %lo(D_8009B368)($v0)
    /* 1D894 8002D094 00000000 */  nop
    /* 1D898 8002D098 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1D89C 8002D09C FF004230 */  andi       $v0, $v0, 0xFF
    /* 1D8A0 8002D0A0 0A005014 */  bne        $v0, $s0, .L8002D0CC
    /* 1D8A4 8002D0A4 00000000 */   nop
    /* 1D8A8 8002D0A8 0A80023C */  lui        $v0, %hi(D_8009B362)
    /* 1D8AC 8002D0AC 62B34290 */  lbu        $v0, %lo(D_8009B362)($v0)
    /* 1D8B0 8002D0B0 0A80033C */  lui        $v1, %hi(D_8009B370)
    /* 1D8B4 8002D0B4 70B36324 */  addiu      $v1, $v1, %lo(D_8009B370)
    /* 1D8B8 8002D0B8 40100200 */  sll        $v0, $v0, 1
    /* 1D8BC 8002D0BC 21104300 */  addu       $v0, $v0, $v1
    /* 1D8C0 8002D0C0 00004290 */  lbu        $v0, 0x0($v0)
    /* 1D8C4 8002D0C4 0A80013C */  lui        $at, %hi(D_8009B27A)
    /* 1D8C8 8002D0C8 7AB222A0 */  sb         $v0, %lo(D_8009B27A)($at)
  .L8002D0CC:
    /* 1D8CC 8002D0CC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 1D8D0 8002D0D0 1400B18F */  lw         $s1, 0x14($sp)
    /* 1D8D4 8002D0D4 1000B08F */  lw         $s0, 0x10($sp)
    /* 1D8D8 8002D0D8 0800E003 */  jr         $ra
    /* 1D8DC 8002D0DC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8002CEE8
