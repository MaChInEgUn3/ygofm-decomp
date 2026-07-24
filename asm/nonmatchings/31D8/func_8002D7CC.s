nonmatching func_8002D7CC, 0x250

glabel func_8002D7CC
    /* 1DFCC 8002D7CC 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1DFD0 8002D7D0 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 1DFD4 8002D7D4 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 1DFD8 8002D7D8 2800B2AF */  sw         $s2, 0x28($sp)
    /* 1DFDC 8002D7DC 2400B1AF */  sw         $s1, 0x24($sp)
    /* 1DFE0 8002D7E0 40006230 */  andi       $v0, $v1, 0x40
    /* 1DFE4 8002D7E4 3D004014 */  bnez       $v0, .L8002D8DC
    /* 1DFE8 8002D7E8 2000B0AF */   sw        $s0, 0x20($sp)
    /* 1DFEC 8002D7EC 40006234 */  ori        $v0, $v1, 0x40
    /* 1DFF0 8002D7F0 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1DFF4 8002D7F4 CAC8000C */  jal        func_80032328
    /* 1DFF8 8002D7F8 00000000 */   nop
    /* 1DFFC 8002D7FC C2FF000C */  jal        func_8003FF08
    /* 1E000 8002D800 D0720424 */   addiu     $a0, $zero, 0x72D0
    /* 1E004 8002D804 DA07060C */  jal        func_80181F68
    /* 1E008 8002D808 00000000 */   nop
    /* 1E00C 8002D80C 21200000 */  addu       $a0, $zero, $zero
    /* 1E010 8002D810 0B000524 */  addiu      $a1, $zero, 0xB
    /* 1E014 8002D814 18000624 */  addiu      $a2, $zero, 0x18
    /* 1E018 8002D818 20000724 */  addiu      $a3, $zero, 0x20
    /* 1E01C 8002D81C 01000224 */  addiu      $v0, $zero, 0x1
    /* 1E020 8002D820 660382A3 */  sb         $v0, %gp_rel(D_8009B26E)($gp)
    /* 1E024 8002D824 10010224 */  addiu      $v0, $zero, 0x110
    /* 1E028 8002D828 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1E02C 8002D82C A0000224 */  addiu      $v0, $zero, 0xA0
    /* 1E030 8002D830 1400A2AF */  sw         $v0, 0x14($sp)
    /* 1E034 8002D834 2110E000 */  addu       $v0, $a3, $zero
    /* 1E038 8002D838 0ED7000C */  jal        func_80035C38
    /* 1E03C 8002D83C 1800A2AF */   sw        $v0, 0x18($sp)
    /* 1E040 8002D840 21884000 */  addu       $s1, $v0, $zero
    /* 1E044 8002D844 21202002 */  addu       $a0, $s1, $zero
    /* 1E048 8002D848 10000224 */  addiu      $v0, $zero, 0x10
    /* 1E04C 8002D84C 85E6000C */  jal        func_80039A14
    /* 1E050 8002D850 590082A0 */   sb        $v0, 0x59($a0)
    /* 1E054 8002D854 0B00010C */  jal        func_8004002C
    /* 1E058 8002D858 00000000 */   nop
    /* 1E05C 8002D85C 21204000 */  addu       $a0, $v0, $zero
    /* 1E060 8002D860 2B00010C */  jal        func_800400AC
    /* 1E064 8002D864 02000524 */   addiu     $a1, $zero, 0x2
    /* 1E068 8002D868 21804000 */  addu       $s0, $v0, $zero
    /* 1E06C 8002D86C 21200002 */  addu       $a0, $s0, $zero
    /* 1E070 8002D870 21280000 */  addu       $a1, $zero, $zero
    /* 1E074 8002D874 2130A000 */  addu       $a2, $a1, $zero
    /* 1E078 8002D878 2138A000 */  addu       $a3, $a1, $zero
    /* 1E07C 8002D87C 04000224 */  addiu      $v0, $zero, 0x4
    /* 1E080 8002D880 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1E084 8002D884 0B000224 */  addiu      $v0, $zero, 0xB
    /* 1E088 8002D888 1400A2AF */  sw         $v0, 0x14($sp)
    /* 1E08C 8002D88C 0C000224 */  addiu      $v0, $zero, 0xC
    /* 1E090 8002D890 1800A2AF */  sw         $v0, 0x18($sp)
    /* 1E094 8002D894 08020224 */  addiu      $v0, $zero, 0x208
    /* 1E098 8002D898 3301010C */  jal        func_800404CC
    /* 1E09C 8002D89C 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* 1E0A0 8002D8A0 08000296 */  lhu        $v0, 0x8($s0)
    /* 1E0A4 8002D8A4 21200002 */  addu       $a0, $s0, $zero
    /* 1E0A8 8002D8A8 20004234 */  ori        $v0, $v0, 0x20
    /* 1E0AC 8002D8AC 080002A6 */  sh         $v0, 0x8($s0)
    /* 1E0B0 8002D8B0 0400028E */  lw         $v0, 0x4($s0)
    /* 1E0B4 8002D8B4 0040033C */  lui        $v1, (0x40000000 >> 16)
    /* 1E0B8 8002D8B8 25104300 */  or         $v0, $v0, $v1
    /* 1E0BC 8002D8BC 460A010C */  jal        func_80042918
    /* 1E0C0 8002D8C0 040002AE */   sw        $v0, 0x4($s0)
    /* 1E0C4 8002D8C4 21200002 */  addu       $a0, $s0, $zero
    /* 1E0C8 8002D8C8 3B0A010C */  jal        func_800428EC
    /* 1E0CC 8002D8CC 0F000524 */   addiu     $a1, $zero, 0xF
    /* 1E0D0 8002D8D0 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* 1E0D4 8002D8D4 8056000C */  jal        func_80015A00
    /* 1E0D8 8002D8D8 F09E50AC */   sw        $s0, %lo(D_800E9EF0)($v0)
  .L8002D8DC:
    /* 1E0DC 8002D8DC 0F80023C */  lui        $v0, %hi(D_800EB0F8)
    /* 1E0E0 8002D8E0 F8B05124 */  addiu      $s1, $v0, %lo(D_800EB0F8)
    /* 1E0E4 8002D8E4 0F80123C */  lui        $s2, %hi(D_800E9EF0)
    /* 1E0E8 8002D8E8 01000224 */  addiu      $v0, $zero, 0x1
    /* 1E0EC 8002D8EC 66038393 */  lbu        $v1, %gp_rel(D_8009B26E)($gp)
    /* 1E0F0 8002D8F0 F09E508E */  lw         $s0, %lo(D_800E9EF0)($s2)
    /* 1E0F4 8002D8F4 05006210 */  beq        $v1, $v0, .L8002D90C
    /* 1E0F8 8002D8F8 02000224 */   addiu     $v0, $zero, 0x2
    /* 1E0FC 8002D8FC 16006210 */  beq        $v1, $v0, .L8002D958
    /* 1E100 8002D900 21200002 */   addu      $a0, $s0, $zero
    /* 1E104 8002D904 70B60008 */  j          .L8002D9C0
    /* 1E108 8002D908 00000000 */   nop
  .L8002D90C:
    /* 1E10C 8002D90C 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* 1E110 8002D910 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* 1E114 8002D914 0A80033C */  lui        $v1, %hi(D_8009B39A)
    /* 1E118 8002D918 9AB36394 */  lhu        $v1, %lo(D_8009B39A)($v1)
    /* 1E11C 8002D91C 00000000 */  nop
    /* 1E120 8002D920 25104300 */  or         $v0, $v0, $v1
    /* 1E124 8002D924 E0004230 */  andi       $v0, $v0, 0xE0
    /* 1E128 8002D928 36004010 */  beqz       $v0, .L8002DA04
    /* 1E12C 8002D92C 00000000 */   nop
    /* 1E130 8002D930 B8FF000C */  jal        func_8003FEE0
    /* 1E134 8002D934 1E000424 */   addiu     $a0, $zero, 0x1E
    /* 1E138 8002D938 5E0C010C */  jal        func_80043178
    /* 1E13C 8002D93C 21200002 */   addu      $a0, $s0, $zero
    /* 1E140 8002D940 00040224 */  addiu      $v0, $zero, 0x400
    /* 1E144 8002D944 600002A6 */  sh         $v0, 0x60($s0)
    /* 1E148 8002D948 02000224 */  addiu      $v0, $zero, 0x2
    /* 1E14C 8002D94C 660382A3 */  sb         $v0, %gp_rel(D_8009B26E)($gp)
    /* 1E150 8002D950 81B60008 */  j          .L8002DA04
    /* 1E154 8002D954 00000000 */   nop
  .L8002D958:
    /* 1E158 8002D958 21280000 */  addu       $a1, $zero, $zero
    /* 1E15C 8002D95C 60000296 */  lhu        $v0, 0x60($s0)
    /* 1E160 8002D960 F0000624 */  addiu      $a2, $zero, 0xF0
    /* 1E164 8002D964 E0FF4224 */  addiu      $v0, $v0, -0x20
    /* 1E168 8002D968 003C0200 */  sll        $a3, $v0, 16
    /* 1E16C 8002D96C 033C0700 */  sra        $a3, $a3, 16
    /* 1E170 8002D970 8C0C010C */  jal        func_80043230
    /* 1E174 8002D974 600002A6 */   sh        $v0, 0x60($s0)
    /* 1E178 8002D978 21202002 */  addu       $a0, $s1, $zero
    /* 1E17C 8002D97C 30000586 */  lh         $a1, 0x30($s0)
    /* 1E180 8002D980 32000686 */  lh         $a2, 0x32($s0)
    /* 1E184 8002D984 1800A524 */  addiu      $a1, $a1, 0x18
    /* 1E188 8002D988 4DE6000C */  jal        func_80039934
    /* 1E18C 8002D98C 2000C624 */   addiu     $a2, $a2, 0x20
    /* 1E190 8002D990 60000286 */  lh         $v0, 0x60($s0)
    /* 1E194 8002D994 00000000 */  nop
    /* 1E198 8002D998 1A00401C */  bgtz       $v0, .L8002DA04
    /* 1E19C 8002D99C 00000000 */   nop
    /* 1E1A0 8002D9A0 660380A3 */  sb         $zero, %gp_rel(D_8009B26E)($gp)
    /* 1E1A4 8002D9A4 DFD6000C */  jal        func_80035B7C
    /* 1E1A8 8002D9A8 21202002 */   addu      $a0, $s1, $zero
    /* 1E1AC 8002D9AC F09E448E */  lw         $a0, %lo(D_800E9EF0)($s2)
    /* 1E1B0 8002D9B0 DB00010C */  jal        func_8004036C
    /* 1E1B4 8002D9B4 00000000 */   nop
    /* 1E1B8 8002D9B8 81B60008 */  j          .L8002DA04
    /* 1E1BC 8002D9BC F09E40AE */   sw        $zero, %lo(D_800E9EF0)($s2)
  .L8002D9C0:
    /* 1E1C0 8002D9C0 4BA2000C */  jal        func_8002892C
    /* 1E1C4 8002D9C4 00000000 */   nop
    /* 1E1C8 8002D9C8 0E004014 */  bnez       $v0, .L8002DA04
    /* 1E1CC 8002D9CC 00000000 */   nop
    /* 1E1D0 8002D9D0 7708060C */  jal        func_801821DC
    /* 1E1D4 8002D9D4 00000000 */   nop
    /* 1E1D8 8002D9D8 0A004010 */  beqz       $v0, .L8002DA04
    /* 1E1DC 8002D9DC 00000000 */   nop
    /* 1E1E0 8002D9E0 CDFF000C */  jal        func_8003FF34
    /* 1E1E4 8002D9E4 00000000 */   nop
    /* 1E1E8 8002D9E8 C056000C */  jal        func_80015B00
    /* 1E1EC 8002D9EC 00000000 */   nop
    /* 1E1F0 8002D9F0 F90F060C */  jal        func_80183FE4
    /* 1E1F4 8002D9F4 00000000 */   nop
    /* 1E1F8 8002D9F8 61038293 */  lbu        $v0, %gp_rel(D_8009B269)($gp)
    /* 1E1FC 8002D9FC 00000000 */  nop
    /* 1E200 8002DA00 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
  .L8002DA04:
    /* 1E204 8002DA04 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 1E208 8002DA08 2800B28F */  lw         $s2, 0x28($sp)
    /* 1E20C 8002DA0C 2400B18F */  lw         $s1, 0x24($sp)
    /* 1E210 8002DA10 2000B08F */  lw         $s0, 0x20($sp)
    /* 1E214 8002DA14 0800E003 */  jr         $ra
    /* 1E218 8002DA18 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8002D7CC
