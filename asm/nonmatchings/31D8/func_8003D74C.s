nonmatching func_8003D74C, 0x2F4

glabel func_8003D74C
    /* 2DF4C 8003D74C B9048393 */  lbu        $v1, %gp_rel(D_8009B3C1)($gp)
    /* 2DF50 8003D750 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 2DF54 8003D754 2800B2AF */  sw         $s2, 0x28($sp)
    /* 2DF58 8003D758 21908000 */  addu       $s2, $a0, $zero
    /* 2DF5C 8003D75C 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 2DF60 8003D760 2400B1AF */  sw         $s1, 0x24($sp)
    /* 2DF64 8003D764 80006230 */  andi       $v0, $v1, 0x80
    /* 2DF68 8003D768 54004014 */  bnez       $v0, .L8003D8BC
    /* 2DF6C 8003D76C 2000B0AF */   sw        $s0, 0x20($sp)
    /* 2DF70 8003D770 80006234 */  ori        $v0, $v1, 0x80
    /* 2DF74 8003D774 B90482A3 */  sb         $v0, %gp_rel(D_8009B3C1)($gp)
    /* 2DF78 8003D778 0B00010C */  jal        func_8004002C
    /* 2DF7C 8003D77C 00000000 */   nop
    /* 2DF80 8003D780 21204000 */  addu       $a0, $v0, $zero
    /* 2DF84 8003D784 2B00010C */  jal        func_800400AC
    /* 2DF88 8003D788 06000524 */   addiu     $a1, $zero, 0x6
    /* 2DF8C 8003D78C 21804000 */  addu       $s0, $v0, $zero
    /* 2DF90 8003D790 21200002 */  addu       $a0, $s0, $zero
    /* 2DF94 8003D794 A0000224 */  addiu      $v0, $zero, 0xA0
    /* 2DF98 8003D798 300002A6 */  sh         $v0, 0x30($s0)
    /* 2DF9C 8003D79C 78000224 */  addiu      $v0, $zero, 0x78
    /* 2DFA0 8003D7A0 320002A6 */  sh         $v0, 0x32($s0)
    /* 2DFA4 8003D7A4 80000224 */  addiu      $v0, $zero, 0x80
    /* 2DFA8 8003D7A8 480002A6 */  sh         $v0, 0x48($s0)
    /* 2DFAC 8003D7AC E0000224 */  addiu      $v0, $zero, 0xE0
    /* 2DFB0 8003D7B0 460A010C */  jal        func_80042918
    /* 2DFB4 8003D7B4 4A0002A6 */   sh        $v0, 0x4A($s0)
    /* 2DFB8 8003D7B8 0A80053C */  lui        $a1, %hi(D_8009AF76)
    /* 2DFBC 8003D7BC 76AFA590 */  lbu        $a1, %lo(D_8009AF76)($a1)
    /* 2DFC0 8003D7C0 21200002 */  addu       $a0, $s0, $zero
    /* 2DFC4 8003D7C4 FDFFA524 */  addiu      $a1, $a1, -0x3
    /* 2DFC8 8003D7C8 002E0500 */  sll        $a1, $a1, 24
    /* 2DFCC 8003D7CC 3B0A010C */  jal        func_800428EC
    /* 2DFD0 8003D7D0 032E0500 */   sra       $a1, $a1, 24
    /* 2DFD4 8003D7D4 0480023C */  lui        $v0, %hi(func_80042C08)
    /* 2DFD8 8003D7D8 082C4224 */  addiu      $v0, $v0, %lo(func_80042C08)
    /* 2DFDC 8003D7DC 4C0002AE */  sw         $v0, 0x4C($s0)
    /* 2DFE0 8003D7E0 0B00010C */  jal        func_8004002C
    /* 2DFE4 8003D7E4 040050AE */   sw        $s0, 0x4($s2)
    /* 2DFE8 8003D7E8 21204000 */  addu       $a0, $v0, $zero
    /* 2DFEC 8003D7EC 2B00010C */  jal        func_800400AC
    /* 2DFF0 8003D7F0 02000524 */   addiu     $a1, $zero, 0x2
    /* 2DFF4 8003D7F4 21804000 */  addu       $s0, $v0, $zero
    /* 2DFF8 8003D7F8 21200002 */  addu       $a0, $s0, $zero
    /* 2DFFC 8003D7FC 20000524 */  addiu      $a1, $zero, 0x20
    /* 2E000 8003D800 C0FF0624 */  addiu      $a2, $zero, -0x40
    /* 2E004 8003D804 03000724 */  addiu      $a3, $zero, 0x3
    /* 2E008 8003D808 02000224 */  addiu      $v0, $zero, 0x2
    /* 2E00C 8003D80C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2E010 8003D810 0B000224 */  addiu      $v0, $zero, 0xB
    /* 2E014 8003D814 1800A2AF */  sw         $v0, 0x18($sp)
    /* 2E018 8003D818 0C020224 */  addiu      $v0, $zero, 0x20C
    /* 2E01C 8003D81C 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2E020 8003D820 3301010C */  jal        func_800404CC
    /* 2E024 8003D824 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* 2E028 8003D828 08000296 */  lhu        $v0, 0x8($s0)
    /* 2E02C 8003D82C 21200002 */  addu       $a0, $s0, $zero
    /* 2E030 8003D830 28004234 */  ori        $v0, $v0, 0x28
    /* 2E034 8003D834 460A010C */  jal        func_80042918
    /* 2E038 8003D838 080002A6 */   sh        $v0, 0x8($s0)
    /* 2E03C 8003D83C 0A80053C */  lui        $a1, %hi(D_8009AF76)
    /* 2E040 8003D840 76AFA590 */  lbu        $a1, %lo(D_8009AF76)($a1)
    /* 2E044 8003D844 21200002 */  addu       $a0, $s0, $zero
    /* 2E048 8003D848 FEFFA524 */  addiu      $a1, $a1, -0x2
    /* 2E04C 8003D84C 002E0500 */  sll        $a1, $a1, 24
    /* 2E050 8003D850 3B0A010C */  jal        func_800428EC
    /* 2E054 8003D854 032E0500 */   sra       $a1, $a1, 24
    /* 2E058 8003D858 21200002 */  addu       $a0, $s0, $zero
    /* 2E05C 8003D85C 5E0C010C */  jal        func_80043178
    /* 2E060 8003D860 000050AE */   sw        $s0, 0x0($s2)
    /* 2E064 8003D864 21280000 */  addu       $a1, $zero, $zero
    /* 2E068 8003D868 BF048493 */  lbu        $a0, %gp_rel(D_8009B3C7)($gp)
    /* 2E06C 8003D86C 00FC0224 */  addiu      $v0, $zero, -0x400
    /* 2E070 8003D870 600002A6 */  sh         $v0, 0x60($s0)
    /* 2E074 8003D874 01008430 */  andi       $a0, $a0, 0x1
    /* 2E078 8003D878 1BF5000C */  jal        func_8003D46C
    /* 2E07C 8003D87C D0008434 */   ori       $a0, $a0, 0xD0
    /* 2E080 8003D880 21884000 */  addu       $s1, $v0, $zero
    /* 2E084 8003D884 34002296 */  lhu        $v0, 0x34($s1)
    /* 2E088 8003D888 00000000 */  nop
    /* 2E08C 8003D88C 04004234 */  ori        $v0, $v0, 0x4
    /* 2E090 8003D890 340022A6 */  sh         $v0, 0x34($s1)
  .L8003D894:
    /* 2E094 8003D894 E5E5000C */  jal        func_80039794
    /* 2E098 8003D898 00000000 */   nop
    /* 2E09C 8003D89C 3000228E */  lw         $v0, 0x30($s1)
    /* 2E0A0 8003D8A0 00000000 */  nop
    /* 2E0A4 8003D8A4 FBFF4010 */  beqz       $v0, .L8003D894
    /* 2E0A8 8003D8A8 00000000 */   nop
    /* 2E0AC 8003D8AC 30000586 */  lh         $a1, 0x30($s0)
    /* 2E0B0 8003D8B0 32000686 */  lh         $a2, 0x32($s0)
    /* 2E0B4 8003D8B4 4DE6000C */  jal        func_80039934
    /* 2E0B8 8003D8B8 21202002 */   addu      $a0, $s1, $zero
  .L8003D8BC:
    /* 2E0BC 8003D8BC B9048493 */  lbu        $a0, %gp_rel(D_8009B3C1)($gp)
    /* 2E0C0 8003D8C0 00000000 */  nop
    /* 2E0C4 8003D8C4 20008230 */  andi       $v0, $a0, 0x20
    /* 2E0C8 8003D8C8 04004010 */  beqz       $v0, .L8003D8DC
    /* 2E0CC 8003D8CC 00000000 */   nop
    /* 2E0D0 8003D8D0 B90480A3 */  sb         $zero, %gp_rel(D_8009B3C1)($gp)
    /* 2E0D4 8003D8D4 8AF60008 */  j          .L8003DA28
    /* 2E0D8 8003D8D8 00000000 */   nop
  .L8003D8DC:
    /* 2E0DC 8003D8DC 1A004392 */  lbu        $v1, 0x1A($s2)
    /* 2E0E0 8003D8E0 00000000 */  nop
    /* 2E0E4 8003D8E4 40100300 */  sll        $v0, $v1, 1
    /* 2E0E8 8003D8E8 21104300 */  addu       $v0, $v0, $v1
    /* 2E0EC 8003D8EC C0100200 */  sll        $v0, $v0, 3
    /* 2E0F0 8003D8F0 21104300 */  addu       $v0, $v0, $v1
    /* 2E0F4 8003D8F4 80100200 */  sll        $v0, $v0, 2
    /* 2E0F8 8003D8F8 0F80033C */  lui        $v1, %hi(D_800EB0F8)
    /* 2E0FC 8003D8FC F8B06324 */  addiu      $v1, $v1, %lo(D_800EB0F8)
    /* 2E100 8003D900 21884300 */  addu       $s1, $v0, $v1
    /* 2E104 8003D904 40008230 */  andi       $v0, $a0, 0x40
    /* 2E108 8003D908 16004010 */  beqz       $v0, .L8003D964
    /* 2E10C 8003D90C 00000000 */   nop
    /* 2E110 8003D910 E5E5000C */  jal        func_80039794
    /* 2E114 8003D914 00000000 */   nop
    /* 2E118 8003D918 34002296 */  lhu        $v0, 0x34($s1)
    /* 2E11C 8003D91C 00000000 */  nop
    /* 2E120 8003D920 00204230 */  andi       $v0, $v0, 0x2000
    /* 2E124 8003D924 40004010 */  beqz       $v0, .L8003DA28
    /* 2E128 8003D928 00000000 */   nop
    /* 2E12C 8003D92C B9048293 */  lbu        $v0, %gp_rel(D_8009B3C1)($gp)
    /* 2E130 8003D930 0A80033C */  lui        $v1, %hi(D_8009B34D)
    /* 2E134 8003D934 4DB36380 */  lb         $v1, %lo(D_8009B34D)($v1)
    /* 2E138 8003D938 20004234 */  ori        $v0, $v0, 0x20
    /* 2E13C 8003D93C B90482A3 */  sb         $v0, %gp_rel(D_8009B3C1)($gp)
    /* 2E140 8003D940 39006014 */  bnez       $v1, .L8003DA28
    /* 2E144 8003D944 00000000 */   nop
    /* 2E148 8003D948 D4800434 */  ori        $a0, $zero, 0x80D4
    /* 2E14C 8003D94C 1BF5000C */  jal        func_8003D46C
    /* 2E150 8003D950 21280000 */   addu      $a1, $zero, $zero
    /* 2E154 8003D954 0A80013C */  lui        $at, %hi(D_8009B34D)
    /* 2E158 8003D958 4DB320A0 */  sb         $zero, %lo(D_8009B34D)($at)
    /* 2E15C 8003D95C 8AF60008 */  j          .L8003DA28
    /* 2E160 8003D960 00000000 */   nop
  .L8003D964:
    /* 2E164 8003D964 0000508E */  lw         $s0, 0x0($s2)
    /* 2E168 8003D968 00000000 */  nop
    /* 2E16C 8003D96C 60000286 */  lh         $v0, 0x60($s0)
    /* 2E170 8003D970 60000396 */  lhu        $v1, 0x60($s0)
    /* 2E174 8003D974 13004104 */  bgez       $v0, .L8003D9C4
    /* 2E178 8003D978 40006224 */   addiu     $v0, $v1, 0x40
    /* 2E17C 8003D97C 600002A6 */  sh         $v0, 0x60($s0)
    /* 2E180 8003D980 00140200 */  sll        $v0, $v0, 16
    /* 2E184 8003D984 033C0200 */  sra        $a3, $v0, 16
    /* 2E188 8003D988 0600E004 */  bltz       $a3, .L8003D9A4
    /* 2E18C 8003D98C 20000224 */   addiu     $v0, $zero, 0x20
    /* 2E190 8003D990 300002A6 */  sh         $v0, 0x30($s0)
    /* 2E194 8003D994 50000224 */  addiu      $v0, $zero, 0x50
    /* 2E198 8003D998 600000A6 */  sh         $zero, 0x60($s0)
    /* 2E19C 8003D99C 6DF60008 */  j          .L8003D9B4
    /* 2E1A0 8003D9A0 320002A6 */   sh        $v0, 0x32($s0)
  .L8003D9A4:
    /* 2E1A4 8003D9A4 21200002 */  addu       $a0, $s0, $zero
    /* 2E1A8 8003D9A8 20000524 */  addiu      $a1, $zero, 0x20
    /* 2E1AC 8003D9AC 8C0C010C */  jal        func_80043230
    /* 2E1B0 8003D9B0 50000624 */   addiu     $a2, $zero, 0x50
  .L8003D9B4:
    /* 2E1B4 8003D9B4 30000586 */  lh         $a1, 0x30($s0)
    /* 2E1B8 8003D9B8 32000686 */  lh         $a2, 0x32($s0)
    /* 2E1BC 8003D9BC 4DE6000C */  jal        func_80039934
    /* 2E1C0 8003D9C0 21202002 */   addu      $a0, $s1, $zero
  .L8003D9C4:
    /* 2E1C4 8003D9C4 0400508E */  lw         $s0, 0x4($s2)
    /* 2E1C8 8003D9C8 00000000 */  nop
    /* 2E1CC 8003D9CC 4A000296 */  lhu        $v0, 0x4A($s0)
    /* 2E1D0 8003D9D0 48000396 */  lhu        $v1, 0x48($s0)
    /* 2E1D4 8003D9D4 F8FF4224 */  addiu      $v0, $v0, -0x8
    /* 2E1D8 8003D9D8 F8FF6324 */  addiu      $v1, $v1, -0x8
    /* 2E1DC 8003D9DC 480003A6 */  sh         $v1, 0x48($s0)
    /* 2E1E0 8003D9E0 001C0300 */  sll        $v1, $v1, 16
    /* 2E1E4 8003D9E4 1000601C */  bgtz       $v1, .L8003DA28
    /* 2E1E8 8003D9E8 4A0002A6 */   sh        $v0, 0x4A($s0)
    /* 2E1EC 8003D9EC 40000224 */  addiu      $v0, $zero, 0x40
    /* 2E1F0 8003D9F0 480000A6 */  sh         $zero, 0x48($s0)
    /* 2E1F4 8003D9F4 4A0002A6 */  sh         $v0, 0x4A($s0)
    /* 2E1F8 8003D9F8 0000428E */  lw         $v0, 0x0($s2)
    /* 2E1FC 8003D9FC 00000000 */  nop
    /* 2E200 8003DA00 60004284 */  lh         $v0, 0x60($v0)
    /* 2E204 8003DA04 00000000 */  nop
    /* 2E208 8003DA08 07004014 */  bnez       $v0, .L8003DA28
    /* 2E20C 8003DA0C 00000000 */   nop
    /* 2E210 8003DA10 34002296 */  lhu        $v0, 0x34($s1)
    /* 2E214 8003DA14 B9048393 */  lbu        $v1, %gp_rel(D_8009B3C1)($gp)
    /* 2E218 8003DA18 FBFF4230 */  andi       $v0, $v0, 0xFFFB
    /* 2E21C 8003DA1C 40006334 */  ori        $v1, $v1, 0x40
    /* 2E220 8003DA20 340022A6 */  sh         $v0, 0x34($s1)
    /* 2E224 8003DA24 B90483A3 */  sb         $v1, %gp_rel(D_8009B3C1)($gp)
  .L8003DA28:
    /* 2E228 8003DA28 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 2E22C 8003DA2C 2800B28F */  lw         $s2, 0x28($sp)
    /* 2E230 8003DA30 2400B18F */  lw         $s1, 0x24($sp)
    /* 2E234 8003DA34 2000B08F */  lw         $s0, 0x20($sp)
    /* 2E238 8003DA38 0800E003 */  jr         $ra
    /* 2E23C 8003DA3C 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8003D74C
