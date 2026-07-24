nonmatching func_8001D670, 0x1600

glabel func_8001D670
    /* DE70 8001D670 C0FFBD27 */  addiu      $sp, $sp, -0x40
    /* DE74 8001D674 0F80033C */  lui        $v1, %hi(D_800E9F48)
    /* DE78 8001D678 CD028493 */  lbu        $a0, %gp_rel(D_8009B1D5)($gp)
    /* DE7C 8001D67C 32038597 */  lhu        $a1, %gp_rel(D_8009B23A)($gp)
    /* DE80 8001D680 489F6324 */  addiu      $v1, $v1, %lo(D_800E9F48)
    /* DE84 8001D684 3800BFAF */  sw         $ra, 0x38($sp)
    /* DE88 8001D688 3400B7AF */  sw         $s7, 0x34($sp)
    /* DE8C 8001D68C 3000B6AF */  sw         $s6, 0x30($sp)
    /* DE90 8001D690 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* DE94 8001D694 2800B4AF */  sw         $s4, 0x28($sp)
    /* DE98 8001D698 2400B3AF */  sw         $s3, 0x24($sp)
    /* DE9C 8001D69C 2000B2AF */  sw         $s2, 0x20($sp)
    /* DEA0 8001D6A0 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* DEA4 8001D6A4 C0100400 */  sll        $v0, $a0, 3
    /* DEA8 8001D6A8 23104400 */  subu       $v0, $v0, $a0
    /* DEAC 8001D6AC 00110200 */  sll        $v0, $v0, 4
    /* DEB0 8001D6B0 21A84300 */  addu       $s5, $v0, $v1
    /* DEB4 8001D6B4 0080A230 */  andi       $v0, $a1, 0x8000
    /* DEB8 8001D6B8 28004014 */  bnez       $v0, .L8001D75C
    /* DEBC 8001D6BC 1800B0AF */   sw        $s0, 0x18($sp)
    /* DEC0 8001D6C0 0F80023C */  lui        $v0, %hi(D_800E9FF0)
    /* DEC4 8001D6C4 F09F4624 */  addiu      $a2, $v0, %lo(D_800E9FF0)
    /* DEC8 8001D6C8 1400C384 */  lh         $v1, 0x14($a2)
    /* DECC 8001D6CC 0080A234 */  ori        $v0, $a1, 0x8000
    /* DED0 8001D6D0 320382A7 */  sh         $v0, %gp_rel(D_8009B23A)($gp)
    /* DED4 8001D6D4 06006010 */  beqz       $v1, .L8001D6F0
    /* DED8 8001D6D8 40110400 */   sll       $v0, $a0, 5
    /* DEDC 8001D6DC 3400C284 */  lh         $v0, 0x34($a2)
    /* DEE0 8001D6E0 00000000 */  nop
    /* DEE4 8001D6E4 10004014 */  bnez       $v0, .L8001D728
    /* DEE8 8001D6E8 01000324 */   addiu     $v1, $zero, 0x1
    /* DEEC 8001D6EC 40110400 */  sll        $v0, $a0, 5
  .L8001D6F0:
    /* DEF0 8001D6F0 21104600 */  addu       $v0, $v0, $a2
    /* DEF4 8001D6F4 14004284 */  lh         $v0, 0x14($v0)
    /* DEF8 8001D6F8 5D0284A3 */  sb         $a0, %gp_rel(D_8009B165)($gp)
    /* DEFC 8001D6FC 03004014 */  bnez       $v0, .L8001D70C
    /* DF00 8001D700 00000000 */   nop
    /* DF04 8001D704 01008238 */  xori       $v0, $a0, 0x1
    /* DF08 8001D708 5D0282A3 */  sb         $v0, %gp_rel(D_8009B165)($gp)
  .L8001D70C:
    /* DF0C 8001D70C 5D028293 */  lbu        $v0, %gp_rel(D_8009B165)($gp)
    /* DF10 8001D710 02000324 */  addiu      $v1, $zero, 0x2
    /* DF14 8001D714 40110200 */  sll        $v0, $v0, 5
    /* DF18 8001D718 21104600 */  addu       $v0, $v0, $a2
    /* DF1C 8001D71C 000043A0 */  sb         $v1, 0x0($v0)
    /* DF20 8001D720 107B0008 */  j          .L8001EC40
    /* DF24 8001D724 0C000224 */   addiu     $v0, $zero, 0xC
  .L8001D728:
    /* DF28 8001D728 04000224 */  addiu      $v0, $zero, 0x4
    /* DF2C 8001D72C F00280AF */  sw         $zero, %gp_rel(D_8009B1F8)($gp)
    /* DF30 8001D730 120380A3 */  sb         $zero, %gp_rel(D_8009B21A)($gp)
    /* DF34 8001D734 AC0295AF */  sw         $s5, %gp_rel(D_8009B1B4)($gp)
    /* DF38 8001D738 1200A2A2 */  sb         $v0, 0x12($s5)
    /* DF3C 8001D73C AE000224 */  addiu      $v0, $zero, 0xAE
    /* DF40 8001D740 0C00A2A6 */  sh         $v0, 0xC($s5)
    /* DF44 8001D744 03000224 */  addiu      $v0, $zero, 0x3
    /* DF48 8001D748 1800A3A2 */  sb         $v1, 0x18($s5)
    /* DF4C 8001D74C 1300A0A2 */  sb         $zero, 0x13($s5)
    /* DF50 8001D750 1100A0A2 */  sb         $zero, 0x11($s5)
    /* DF54 8001D754 5A0282A7 */  sh         $v0, %gp_rel(D_8009B162)($gp)
    /* DF58 8001D758 6C0283A3 */  sb         $v1, %gp_rel(D_8009B174)($gp)
  .L8001D75C:
    /* DF5C 8001D75C 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* DF60 8001D760 00000000 */  nop
    /* DF64 8001D764 0F004230 */  andi       $v0, $v0, 0xF
    /* DF68 8001D768 FFFF4324 */  addiu      $v1, $v0, -0x1
    /* DF6C 8001D76C 0B00622C */  sltiu      $v0, $v1, 0xB
    /* DF70 8001D770 34054010 */  beqz       $v0, .L8001EC44
    /* DF74 8001D774 0180023C */   lui       $v0, %hi(jtbl_80010160)
    /* DF78 8001D778 60014224 */  addiu      $v0, $v0, %lo(jtbl_80010160)
    /* DF7C 8001D77C 80180300 */  sll        $v1, $v1, 2
    /* DF80 8001D780 21186200 */  addu       $v1, $v1, $v0
    /* DF84 8001D784 0000628C */  lw         $v0, 0x0($v1)
    /* DF88 8001D788 00000000 */  nop
    /* DF8C 8001D78C 08004000 */  jr         $v0
    /* DF90 8001D790 00000000 */   nop
  jlabel .L8001D794
    /* DF94 8001D794 5A028297 */  lhu        $v0, %gp_rel(D_8009B162)($gp)
    /* DF98 8001D798 00000000 */  nop
    /* DF9C 8001D79C 29054014 */  bnez       $v0, .L8001EC44
    /* DFA0 8001D7A0 03000224 */   addiu     $v0, $zero, 0x3
    /* DFA4 8001D7A4 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* DFA8 8001D7A8 117B0008 */  j          .L8001EC44
    /* DFAC 8001D7AC 00000000 */   nop
  jlabel .L8001D7B0
    /* DFB0 8001D7B0 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* DFB4 8001D7B4 00000000 */  nop
    /* DFB8 8001D7B8 80006230 */  andi       $v0, $v1, 0x80
    /* DFBC 8001D7BC 0B004014 */  bnez       $v0, .L8001D7EC
    /* DFC0 8001D7C0 01001024 */   addiu     $s0, $zero, 0x1
    /* DFC4 8001D7C4 80006234 */  ori        $v0, $v1, 0x80
    /* DFC8 8001D7C8 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* DFCC 8001D7CC 88A0000C */  jal        func_80028220
    /* DFD0 8001D7D0 00000000 */   nop
    /* DFD4 8001D7D4 1B80043C */  lui        $a0, %hi(D_801A9800)
    /* DFD8 8001D7D8 76C1010C */  jal        func_800705D8
    /* DFDC 8001D7DC 00988424 */   addiu     $a0, $a0, %lo(D_801A9800)
    /* DFE0 8001D7E0 040380A7 */  sh         $zero, %gp_rel(D_8009B20C)($gp)
    /* DFE4 8001D7E4 117B0008 */  j          .L8001EC44
    /* DFE8 8001D7E8 00000000 */   nop
  .L8001D7EC:
    /* DFEC 8001D7EC 04038697 */  lhu        $a2, %gp_rel(D_8009B20C)($gp)
    /* DFF0 8001D7F0 00000000 */  nop
    /* DFF4 8001D7F4 0F00D130 */  andi       $s1, $a2, 0xF
    /* DFF8 8001D7F8 18003012 */  beq        $s1, $s0, .L8001D85C
    /* DFFC 8001D7FC 0200222A */   slti      $v0, $s1, 0x2
    /* E000 8001D800 05004010 */  beqz       $v0, .L8001D818
    /* E004 8001D804 00000000 */   nop
    /* E008 8001D808 0A002012 */  beqz       $s1, .L8001D834
    /* E00C 8001D80C 00000000 */   nop
    /* E010 8001D810 117B0008 */  j          .L8001EC44
    /* E014 8001D814 00000000 */   nop
  .L8001D818:
    /* E018 8001D818 02000224 */  addiu      $v0, $zero, 0x2
    /* E01C 8001D81C 63002212 */  beq        $s1, $v0, .L8001D9AC
    /* E020 8001D820 03000224 */   addiu     $v0, $zero, 0x3
    /* E024 8001D824 91002212 */  beq        $s1, $v0, .L8001DA6C
    /* E028 8001D828 0080C230 */   andi      $v0, $a2, 0x8000
    /* E02C 8001D82C 117B0008 */  j          .L8001EC44
    /* E030 8001D830 00000000 */   nop
  .L8001D834:
    /* E034 8001D834 94C1010C */  jal        func_80070650
    /* E038 8001D838 00000000 */   nop
    /* E03C 8001D83C 21A04000 */  addu       $s4, $v0, $zero
    /* E040 8001D840 00058012 */  beqz       $s4, .L8001EC44
    /* E044 8001D844 03000224 */   addiu     $v0, $zero, 0x3
    /* E048 8001D848 E4048212 */  beq        $s4, $v0, .L8001EBDC
    /* E04C 8001D84C 00000000 */   nop
    /* E050 8001D850 040390A7 */  sh         $s0, %gp_rel(D_8009B20C)($gp)
    /* E054 8001D854 117B0008 */  j          .L8001EC44
    /* E058 8001D858 00000000 */   nop
  .L8001D85C:
    /* E05C 8001D85C 0080C230 */  andi       $v0, $a2, 0x8000
    /* E060 8001D860 18004014 */  bnez       $v0, .L8001D8C4
    /* E064 8001D864 6666033C */   lui       $v1, (0x66666667 >> 16)
    /* E068 8001D868 0F80023C */  lui        $v0, %hi(D_800EAE91)
    /* E06C 8001D86C 91AE5490 */  lbu        $s4, %lo(D_800EAE91)($v0)
    /* E070 8001D870 67666334 */  ori        $v1, $v1, (0x66666667 & 0xFFFF)
    /* E074 8001D874 FFFF8426 */  addiu      $a0, $s4, -0x1
    /* E078 8001D878 18008300 */  mult       $a0, $v1
    /* E07C 8001D87C 0080C234 */  ori        $v0, $a2, 0x8000
    /* E080 8001D880 040382A7 */  sh         $v0, %gp_rel(D_8009B20C)($gp)
    /* E084 8001D884 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* E088 8001D888 580282A3 */  sb         $v0, %gp_rel(D_8009B160)($gp)
    /* E08C 8001D88C 02000224 */  addiu      $v0, $zero, 0x2
    /* E090 8001D890 CF0282A3 */  sb         $v0, %gp_rel(D_8009B1D7)($gp)
    /* E094 8001D894 C3170400 */  sra        $v0, $a0, 31
    /* E098 8001D898 10500000 */  mfhi       $t2
    /* E09C 8001D89C 43180A00 */  sra        $v1, $t2, 1
    /* E0A0 8001D8A0 23186200 */  subu       $v1, $v1, $v0
    /* E0A4 8001D8A4 80100300 */  sll        $v0, $v1, 2
    /* E0A8 8001D8A8 21104300 */  addu       $v0, $v0, $v1
    /* E0AC 8001D8AC 23208200 */  subu       $a0, $a0, $v0
    /* E0B0 8001D8B0 0600822A */  slti       $v0, $s4, 0x6
    /* E0B4 8001D8B4 CE0284A3 */  sb         $a0, %gp_rel(D_8009B1D6)($gp)
    /* E0B8 8001D8B8 02004014 */  bnez       $v0, .L8001D8C4
    /* E0BC 8001D8BC 03000224 */   addiu     $v0, $zero, 0x3
    /* E0C0 8001D8C0 CF0282A3 */  sb         $v0, %gp_rel(D_8009B1D7)($gp)
  .L8001D8C4:
    /* E0C4 8001D8C4 6D75000C */  jal        func_8001D5B4
    /* E0C8 8001D8C8 2120A002 */   addu      $a0, $s5, $zero
    /* E0CC 8001D8CC DD044014 */  bnez       $v0, .L8001EC44
    /* E0D0 8001D8D0 0F80023C */   lui       $v0, %hi(D_800EAE88)
    /* E0D4 8001D8D4 88AE4324 */  addiu      $v1, $v0, %lo(D_800EAE88)
    /* E0D8 8001D8D8 0A006290 */  lbu        $v0, 0xA($v1)
    /* E0DC 8001D8DC 00000000 */  nop
    /* E0E0 8001D8E0 24004014 */  bnez       $v0, .L8001D974
    /* E0E4 8001D8E4 0F80023C */   lui       $v0, %hi(D_800EAE88)
    /* E0E8 8001D8E8 0B006290 */  lbu        $v0, 0xB($v1)
    /* E0EC 8001D8EC 00000000 */  nop
    /* E0F0 8001D8F0 20004014 */  bnez       $v0, .L8001D974
    /* E0F4 8001D8F4 0F80023C */   lui       $v0, %hi(D_800EAE88)
    /* E0F8 8001D8F8 0980053C */  lui        $a1, %hi(D_800907D8)
    /* E0FC 8001D8FC 1000A282 */  lb         $v0, 0x10($s5)
    /* E100 8001D900 D807A524 */  addiu      $a1, $a1, %lo(D_800907D8)
    /* E104 8001D904 80180200 */  sll        $v1, $v0, 2
    /* E108 8001D908 21186200 */  addu       $v1, $v1, $v0
    /* E10C 8001D90C 0F00A282 */  lb         $v0, 0xF($s5)
    /* E110 8001D910 CD028493 */  lbu        $a0, %gp_rel(D_8009B1D5)($gp)
    /* E114 8001D914 21186200 */  addu       $v1, $v1, $v0
    /* E118 8001D918 80100400 */  sll        $v0, $a0, 2
    /* E11C 8001D91C 21104400 */  addu       $v0, $v0, $a0
    /* E120 8001D920 80100200 */  sll        $v0, $v0, 2
    /* E124 8001D924 21186200 */  addu       $v1, $v1, $v0
    /* E128 8001D928 21186500 */  addu       $v1, $v1, $a1
    /* E12C 8001D92C 00006290 */  lbu        $v0, 0x0($v1)
    /* E130 8001D930 00000000 */  nop
    /* E134 8001D934 C0180200 */  sll        $v1, $v0, 3
    /* E138 8001D938 23186200 */  subu       $v1, $v1, $v0
    /* E13C 8001D93C 80180300 */  sll        $v1, $v1, 2
    /* E140 8001D940 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* E144 8001D944 D87A4224 */  addiu      $v0, $v0, %lo(D_801A7AD8)
    /* E148 8001D948 21806200 */  addu       $s0, $v1, $v0
    /* E14C 8001D94C 16000396 */  lhu        $v1, 0x16($s0)
    /* E150 8001D950 00000000 */  nop
    /* E154 8001D954 00806230 */  andi       $v0, $v1, 0x8000
    /* E158 8001D958 82004010 */  beqz       $v0, .L8001DB64
    /* E15C 8001D95C 00406234 */   ori       $v0, $v1, 0x4000
    /* E160 8001D960 0000048E */  lw         $a0, 0x0($s0)
    /* E164 8001D964 8F5F000C */  jal        func_80017E3C
    /* E168 8001D968 160002A6 */   sh        $v0, 0x16($s0)
    /* E16C 8001D96C DA760008 */  j          .L8001DB68
    /* E170 8001D970 02000224 */   addiu     $v0, $zero, 0x2
  .L8001D974:
    /* E174 8001D974 88AE4424 */  addiu      $a0, $v0, %lo(D_800EAE88)
    /* E178 8001D978 0B008390 */  lbu        $v1, 0xB($a0)
    /* E17C 8001D97C 03000224 */  addiu      $v0, $zero, 0x3
    /* E180 8001D980 040382A7 */  sh         $v0, %gp_rel(D_8009B20C)($gp)
    /* E184 8001D984 AF046010 */  beqz       $v1, .L8001EC44
    /* E188 8001D988 00000000 */   nop
    /* E18C 8001D98C 09008290 */  lbu        $v0, 0x9($a0)
    /* E190 8001D990 00000000 */  nop
    /* E194 8001D994 0600422C */  sltiu      $v0, $v0, 0x6
    /* E198 8001D998 AA044010 */  beqz       $v0, .L8001EC44
    /* E19C 8001D99C 02000224 */   addiu     $v0, $zero, 0x2
    /* E1A0 8001D9A0 040382A7 */  sh         $v0, %gp_rel(D_8009B20C)($gp)
    /* E1A4 8001D9A4 117B0008 */  j          .L8001EC44
    /* E1A8 8001D9A8 00000000 */   nop
  .L8001D9AC:
    /* E1AC 8001D9AC 0980053C */  lui        $a1, %hi(D_800907D8)
    /* E1B0 8001D9B0 1000A282 */  lb         $v0, 0x10($s5)
    /* E1B4 8001D9B4 D807A524 */  addiu      $a1, $a1, %lo(D_800907D8)
    /* E1B8 8001D9B8 80180200 */  sll        $v1, $v0, 2
    /* E1BC 8001D9BC 21186200 */  addu       $v1, $v1, $v0
    /* E1C0 8001D9C0 0F00A282 */  lb         $v0, 0xF($s5)
    /* E1C4 8001D9C4 CD028493 */  lbu        $a0, %gp_rel(D_8009B1D5)($gp)
    /* E1C8 8001D9C8 21186200 */  addu       $v1, $v1, $v0
    /* E1CC 8001D9CC 80100400 */  sll        $v0, $a0, 2
    /* E1D0 8001D9D0 21104400 */  addu       $v0, $v0, $a0
    /* E1D4 8001D9D4 80100200 */  sll        $v0, $v0, 2
    /* E1D8 8001D9D8 21186200 */  addu       $v1, $v1, $v0
    /* E1DC 8001D9DC 21186500 */  addu       $v1, $v1, $a1
    /* E1E0 8001D9E0 00006290 */  lbu        $v0, 0x0($v1)
    /* E1E4 8001D9E4 00000000 */  nop
    /* E1E8 8001D9E8 C0180200 */  sll        $v1, $v0, 3
    /* E1EC 8001D9EC 23186200 */  subu       $v1, $v1, $v0
    /* E1F0 8001D9F0 80180300 */  sll        $v1, $v1, 2
    /* E1F4 8001D9F4 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* E1F8 8001D9F8 D87A4224 */  addiu      $v0, $v0, %lo(D_801A7AD8)
    /* E1FC 8001D9FC 21806200 */  addu       $s0, $v1, $v0
    /* E200 8001DA00 0080C230 */  andi       $v0, $a2, 0x8000
    /* E204 8001DA04 0D004014 */  bnez       $v0, .L8001DA3C
    /* E208 8001DA08 0080C234 */   ori       $v0, $a2, 0x8000
    /* E20C 8001DA0C 16000396 */  lhu        $v1, 0x16($s0)
    /* E210 8001DA10 040382A7 */  sh         $v0, %gp_rel(D_8009B20C)($gp)
    /* E214 8001DA14 00806230 */  andi       $v0, $v1, 0x8000
    /* E218 8001DA18 52004010 */  beqz       $v0, .L8001DB64
    /* E21C 8001DA1C 00086230 */   andi      $v0, $v1, 0x800
    /* E220 8001DA20 31004010 */  beqz       $v0, .L8001DAE8
    /* E224 8001DA24 00406234 */   ori       $v0, $v1, 0x4000
    /* E228 8001DA28 0000048E */  lw         $a0, 0x0($s0)
    /* E22C 8001DA2C 8F5F000C */  jal        func_80017E3C
    /* E230 8001DA30 160002A6 */   sh        $v0, 0x16($s0)
    /* E234 8001DA34 DA760008 */  j          .L8001DB68
    /* E238 8001DA38 02000224 */   addiu     $v0, $zero, 0x2
  .L8001DA3C:
    /* E23C 8001DA3C D00A010C */  jal        func_80042B40
    /* E240 8001DA40 0F000424 */   addiu     $a0, $zero, 0xF
    /* E244 8001DA44 7F044014 */  bnez       $v0, .L8001EC44
    /* E248 8001DA48 00000000 */   nop
    /* E24C 8001DA4C 16000296 */  lhu        $v0, 0x16($s0)
    /* E250 8001DA50 0000048E */  lw         $a0, 0x0($s0)
    /* E254 8001DA54 00404234 */  ori        $v0, $v0, 0x4000
    /* E258 8001DA58 8F5F000C */  jal        func_80017E3C
    /* E25C 8001DA5C 160002A6 */   sh        $v0, 0x16($s0)
    /* E260 8001DA60 6C0291A3 */  sb         $s1, %gp_rel(D_8009B174)($gp)
    /* E264 8001DA64 117B0008 */  j          .L8001EC44
    /* E268 8001DA68 00000000 */   nop
  .L8001DA6C:
    /* E26C 8001DA6C 25004014 */  bnez       $v0, .L8001DB04
    /* E270 8001DA70 0040C230 */   andi      $v0, $a2, 0x4000
    /* E274 8001DA74 0080C234 */  ori        $v0, $a2, 0x8000
    /* E278 8001DA78 0980053C */  lui        $a1, %hi(D_800907D8)
    /* E27C 8001DA7C 040382A7 */  sh         $v0, %gp_rel(D_8009B20C)($gp)
    /* E280 8001DA80 1000A282 */  lb         $v0, 0x10($s5)
    /* E284 8001DA84 D807A524 */  addiu      $a1, $a1, %lo(D_800907D8)
    /* E288 8001DA88 80180200 */  sll        $v1, $v0, 2
    /* E28C 8001DA8C 21186200 */  addu       $v1, $v1, $v0
    /* E290 8001DA90 0F00A282 */  lb         $v0, 0xF($s5)
    /* E294 8001DA94 CD028493 */  lbu        $a0, %gp_rel(D_8009B1D5)($gp)
    /* E298 8001DA98 21186200 */  addu       $v1, $v1, $v0
    /* E29C 8001DA9C 80100400 */  sll        $v0, $a0, 2
    /* E2A0 8001DAA0 21104400 */  addu       $v0, $v0, $a0
    /* E2A4 8001DAA4 80100200 */  sll        $v0, $v0, 2
    /* E2A8 8001DAA8 21186200 */  addu       $v1, $v1, $v0
    /* E2AC 8001DAAC 21186500 */  addu       $v1, $v1, $a1
    /* E2B0 8001DAB0 00006290 */  lbu        $v0, 0x0($v1)
    /* E2B4 8001DAB4 00000000 */  nop
    /* E2B8 8001DAB8 C0180200 */  sll        $v1, $v0, 3
    /* E2BC 8001DABC 23186200 */  subu       $v1, $v1, $v0
    /* E2C0 8001DAC0 80180300 */  sll        $v1, $v1, 2
    /* E2C4 8001DAC4 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* E2C8 8001DAC8 D87A4224 */  addiu      $v0, $v0, %lo(D_801A7AD8)
    /* E2CC 8001DACC 21806200 */  addu       $s0, $v1, $v0
    /* E2D0 8001DAD0 16000296 */  lhu        $v0, 0x16($s0)
    /* E2D4 8001DAD4 00000000 */  nop
    /* E2D8 8001DAD8 00084230 */  andi       $v0, $v0, 0x800
    /* E2DC 8001DADC 59044010 */  beqz       $v0, .L8001EC44
    /* E2E0 8001DAE0 00C0C234 */   ori       $v0, $a2, 0xC000
    /* E2E4 8001DAE4 040382A7 */  sh         $v0, %gp_rel(D_8009B20C)($gp)
  .L8001DAE8:
    /* E2E8 8001DAE8 0280023C */  lui        $v0, %hi(func_8001D240)
    /* E2EC 8001DAEC 0000128E */  lw         $s2, 0x0($s0)
    /* E2F0 8001DAF0 40D24224 */  addiu      $v0, $v0, %lo(func_8001D240)
    /* E2F4 8001DAF4 240042AE */  sw         $v0, 0x24($s2)
    /* E2F8 8001DAF8 0F000224 */  addiu      $v0, $zero, 0xF
    /* E2FC 8001DAFC 117B0008 */  j          .L8001EC44
    /* E300 8001DB00 6C0042A2 */   sb        $v0, 0x6C($s2)
  .L8001DB04:
    /* E304 8001DB04 05004010 */  beqz       $v0, .L8001DB1C
    /* E308 8001DB08 00000000 */   nop
    /* E30C 8001DB0C D00A010C */  jal        func_80042B40
    /* E310 8001DB10 0F000424 */   addiu     $a0, $zero, 0xF
    /* E314 8001DB14 4B044014 */  bnez       $v0, .L8001EC44
    /* E318 8001DB18 00000000 */   nop
  .L8001DB1C:
    /* E31C 8001DB1C 120390A3 */  sb         $s0, %gp_rel(D_8009B21A)($gp)
    /* E320 8001DB20 80770008 */  j          .L8001DE00
    /* E324 8001DB24 00000000 */   nop
  jlabel .L8001DB28
    /* E328 8001DB28 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* E32C 8001DB2C 00000000 */  nop
    /* E330 8001DB30 80006230 */  andi       $v0, $v1, 0x80
    /* E334 8001DB34 10004014 */  bnez       $v0, .L8001DB78
    /* E338 8001DB38 C0006234 */   ori       $v0, $v1, 0xC0
    /* E33C 8001DB3C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* E340 8001DB40 CD028293 */  lbu        $v0, %gp_rel(D_8009B1D5)($gp)
    /* E344 8001DB44 0A80033C */  lui        $v1, %hi(D_8009B360)
    /* E348 8001DB48 60B36324 */  addiu      $v1, $v1, %lo(D_8009B360)
    /* E34C 8001DB4C 120380A3 */  sb         $zero, %gp_rel(D_8009B21A)($gp)
    /* E350 8001DB50 21104300 */  addu       $v0, $v0, $v1
    /* E354 8001DB54 00004280 */  lb         $v0, 0x0($v0)
    /* E358 8001DB58 00000000 */  nop
    /* E35C 8001DB5C 05004004 */  bltz       $v0, .L8001DB74
    /* E360 8001DB60 00000000 */   nop
  .L8001DB64:
    /* E364 8001DB64 02000224 */  addiu      $v0, $zero, 0x2
  .L8001DB68:
    /* E368 8001DB68 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* E36C 8001DB6C 117B0008 */  j          .L8001EC44
    /* E370 8001DB70 00000000 */   nop
  .L8001DB74:
    /* E374 8001DB74 1900A0A2 */  sb         $zero, 0x19($s5)
  .L8001DB78:
    /* E378 8001DB78 D00A010C */  jal        func_80042B40
    /* E37C 8001DB7C 0F000424 */   addiu     $a0, $zero, 0xF
    /* E380 8001DB80 30044014 */  bnez       $v0, .L8001EC44
    /* E384 8001DB84 00000000 */   nop
    /* E388 8001DB88 1890000C */  jal        func_80024060
    /* E38C 8001DB8C 2120A002 */   addu      $a0, $s5, $zero
    /* E390 8001DB90 04004010 */  beqz       $v0, .L8001DBA4
    /* E394 8001DB94 00000000 */   nop
    /* E398 8001DB98 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* E39C 8001DB9C C0780008 */  j          .L8001E300
    /* E3A0 8001DBA0 40004234 */   ori       $v0, $v0, 0x40
  .L8001DBA4:
    /* E3A4 8001DBA4 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* E3A8 8001DBA8 00000000 */  nop
    /* E3AC 8001DBAC 40006230 */  andi       $v0, $v1, 0x40
    /* E3B0 8001DBB0 23004010 */  beqz       $v0, .L8001DC40
    /* E3B4 8001DBB4 BF006230 */   andi      $v0, $v1, 0xBF
    /* E3B8 8001DBB8 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* E3BC 8001DBBC 1000A382 */  lb         $v1, 0x10($s5)
    /* E3C0 8001DBC0 02000224 */  addiu      $v0, $zero, 0x2
    /* E3C4 8001DBC4 1A006214 */  bne        $v1, $v0, .L8001DC30
    /* E3C8 8001DBC8 0980053C */   lui       $a1, %hi(D_800907D8)
    /* E3CC 8001DBCC D807A524 */  addiu      $a1, $a1, %lo(D_800907D8)
    /* E3D0 8001DBD0 0F00A382 */  lb         $v1, 0xF($s5)
    /* E3D4 8001DBD4 CD028493 */  lbu        $a0, %gp_rel(D_8009B1D5)($gp)
    /* E3D8 8001DBD8 0A006324 */  addiu      $v1, $v1, 0xA
    /* E3DC 8001DBDC 04104400 */  sllv       $v0, $a0, $v0
    /* E3E0 8001DBE0 21104400 */  addu       $v0, $v0, $a0
    /* E3E4 8001DBE4 80100200 */  sll        $v0, $v0, 2
    /* E3E8 8001DBE8 21186200 */  addu       $v1, $v1, $v0
    /* E3EC 8001DBEC 21186500 */  addu       $v1, $v1, $a1
    /* E3F0 8001DBF0 1A80043C */  lui        $a0, %hi(D_801A7AD8)
    /* E3F4 8001DBF4 00006390 */  lbu        $v1, 0x0($v1)
    /* E3F8 8001DBF8 D87A8424 */  addiu      $a0, $a0, %lo(D_801A7AD8)
    /* E3FC 8001DBFC C0100300 */  sll        $v0, $v1, 3
    /* E400 8001DC00 23104300 */  subu       $v0, $v0, $v1
    /* E404 8001DC04 80100200 */  sll        $v0, $v0, 2
    /* E408 8001DC08 035C000C */  jal        func_8001700C
    /* E40C 8001DC0C 21204400 */   addu      $a0, $v0, $a0
    /* E410 8001DC10 07004010 */  beqz       $v0, .L8001DC30
    /* E414 8001DC14 00000000 */   nop
    /* E418 8001DC18 0400A48E */  lw         $a0, 0x4($s5)
    /* E41C 8001DC1C 4675000C */  jal        func_8001D518
    /* E420 8001DC20 00000000 */   nop
    /* E424 8001DC24 F00282AF */  sw         $v0, %gp_rel(D_8009B1F8)($gp)
    /* E428 8001DC28 10770008 */  j          .L8001DC40
    /* E42C 8001DC2C 00000000 */   nop
  .L8001DC30:
    /* E430 8001DC30 F002848F */  lw         $a0, %gp_rel(D_8009B1F8)($gp)
    /* E434 8001DC34 DB00010C */  jal        func_8004036C
    /* E438 8001DC38 00000000 */   nop
    /* E43C 8001DC3C F00280AF */  sw         $zero, %gp_rel(D_8009B1F8)($gp)
  .L8001DC40:
    /* E440 8001DC40 CD028293 */  lbu        $v0, %gp_rel(D_8009B1D5)($gp)
    /* E444 8001DC44 0A80033C */  lui        $v1, %hi(D_8009B360)
    /* E448 8001DC48 60B36324 */  addiu      $v1, $v1, %lo(D_8009B360)
    /* E44C 8001DC4C 21104300 */  addu       $v0, $v0, $v1
    /* E450 8001DC50 00004280 */  lb         $v0, 0x0($v0)
    /* E454 8001DC54 00000000 */  nop
    /* E458 8001DC58 0A004104 */  bgez       $v0, .L8001DC84
    /* E45C 8001DC5C 00000000 */   nop
    /* E460 8001DC60 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* E464 8001DC64 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* E468 8001DC68 00000000 */  nop
    /* E46C 8001DC6C 00084230 */  andi       $v0, $v0, 0x800
    /* E470 8001DC70 04004010 */  beqz       $v0, .L8001DC84
    /* E474 8001DC74 0B000224 */   addiu     $v0, $zero, 0xB
    /* E478 8001DC78 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* E47C 8001DC7C 117B0008 */  j          .L8001EC44
    /* E480 8001DC80 00000000 */   nop
  .L8001DC84:
    /* E484 8001DC84 526F000C */  jal        func_8001BD48
    /* E488 8001DC88 00000000 */   nop
    /* E48C 8001DC8C ED034014 */  bnez       $v0, .L8001EC44
    /* E490 8001DC90 00000000 */   nop
    /* E494 8001DC94 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* E498 8001DC98 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* E49C 8001DC9C 00000000 */  nop
    /* E4A0 8001DCA0 0C004230 */  andi       $v0, $v0, 0xC
    /* E4A4 8001DCA4 25004010 */  beqz       $v0, .L8001DD3C
    /* E4A8 8001DCA8 0980053C */   lui       $a1, %hi(D_800907D8)
    /* E4AC 8001DCAC D807A524 */  addiu      $a1, $a1, %lo(D_800907D8)
    /* E4B0 8001DCB0 1000A682 */  lb         $a2, 0x10($s5)
    /* E4B4 8001DCB4 0F00A282 */  lb         $v0, 0xF($s5)
    /* E4B8 8001DCB8 CD028493 */  lbu        $a0, %gp_rel(D_8009B1D5)($gp)
    /* E4BC 8001DCBC 80180600 */  sll        $v1, $a2, 2
    /* E4C0 8001DCC0 21186600 */  addu       $v1, $v1, $a2
    /* E4C4 8001DCC4 21186200 */  addu       $v1, $v1, $v0
    /* E4C8 8001DCC8 80100400 */  sll        $v0, $a0, 2
    /* E4CC 8001DCCC 21104400 */  addu       $v0, $v0, $a0
    /* E4D0 8001DCD0 80100200 */  sll        $v0, $v0, 2
    /* E4D4 8001DCD4 21186200 */  addu       $v1, $v1, $v0
    /* E4D8 8001DCD8 21186500 */  addu       $v1, $v1, $a1
    /* E4DC 8001DCDC 00006290 */  lbu        $v0, 0x0($v1)
    /* E4E0 8001DCE0 00000000 */  nop
    /* E4E4 8001DCE4 C0180200 */  sll        $v1, $v0, 3
    /* E4E8 8001DCE8 23186200 */  subu       $v1, $v1, $v0
    /* E4EC 8001DCEC 80180300 */  sll        $v1, $v1, 2
    /* E4F0 8001DCF0 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* E4F4 8001DCF4 D87A4224 */  addiu      $v0, $v0, %lo(D_801A7AD8)
    /* E4F8 8001DCF8 21806200 */  addu       $s0, $v1, $v0
    /* E4FC 8001DCFC 02000224 */  addiu      $v0, $zero, 0x2
    /* E500 8001DD00 D003C214 */  bne        $a2, $v0, .L8001EC44
    /* E504 8001DD04 00000000 */   nop
    /* E508 8001DD08 035C000C */  jal        func_8001700C
    /* E50C 8001DD0C 21200002 */   addu      $a0, $s0, $zero
    /* E510 8001DD10 CC034010 */  beqz       $v0, .L8001EC44
    /* E514 8001DD14 0B000424 */   addiu     $a0, $zero, 0xB
    /* E518 8001DD18 0280023C */  lui        $v0, %hi(func_8001D240)
    /* E51C 8001DD1C 0000128E */  lw         $s2, 0x0($s0)
    /* E520 8001DD20 40D24224 */  addiu      $v0, $v0, %lo(func_8001D240)
    /* E524 8001DD24 240042AE */  sw         $v0, 0x24($s2)
    /* E528 8001DD28 0F000224 */  addiu      $v0, $zero, 0xF
    /* E52C 8001DD2C B8FF000C */  jal        func_8003FEE0
    /* E530 8001DD30 6C0042A2 */   sb        $v0, 0x6C($s2)
    /* E534 8001DD34 117B0008 */  j          .L8001EC44
    /* E538 8001DD38 00000000 */   nop
  .L8001DD3C:
    /* E53C 8001DD3C 1000A282 */  lb         $v0, 0x10($s5)
    /* E540 8001DD40 D807A524 */  addiu      $a1, $a1, %lo(D_800907D8)
    /* E544 8001DD44 80180200 */  sll        $v1, $v0, 2
    /* E548 8001DD48 21186200 */  addu       $v1, $v1, $v0
    /* E54C 8001DD4C 0F00A282 */  lb         $v0, 0xF($s5)
    /* E550 8001DD50 CD028493 */  lbu        $a0, %gp_rel(D_8009B1D5)($gp)
    /* E554 8001DD54 21186200 */  addu       $v1, $v1, $v0
    /* E558 8001DD58 80100400 */  sll        $v0, $a0, 2
    /* E55C 8001DD5C 21104400 */  addu       $v0, $v0, $a0
    /* E560 8001DD60 80100200 */  sll        $v0, $v0, 2
    /* E564 8001DD64 21186200 */  addu       $v1, $v1, $v0
    /* E568 8001DD68 21186500 */  addu       $v1, $v1, $a1
    /* E56C 8001DD6C 1A80043C */  lui        $a0, %hi(D_801A7AD8)
    /* E570 8001DD70 00006390 */  lbu        $v1, 0x0($v1)
    /* E574 8001DD74 D87A8424 */  addiu      $a0, $a0, %lo(D_801A7AD8)
    /* E578 8001DD78 C0100300 */  sll        $v0, $v1, 3
    /* E57C 8001DD7C 23104300 */  subu       $v0, $v0, $v1
    /* E580 8001DD80 80100200 */  sll        $v0, $v0, 2
    /* E584 8001DD84 0D5C000C */  jal        func_80017034
    /* E588 8001DD88 21204400 */   addu      $a0, $v0, $a0
    /* E58C 8001DD8C 21A04000 */  addu       $s4, $v0, $zero
    /* E590 8001DD90 76018016 */  bnez       $s4, .L8001E36C
    /* E594 8001DD94 14000224 */   addiu     $v0, $zero, 0x14
    /* E598 8001DD98 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* E59C 8001DD9C 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* E5A0 8001DDA0 00000000 */  nop
    /* E5A4 8001DDA4 C0004230 */  andi       $v0, $v0, 0xC0
    /* E5A8 8001DDA8 A6034010 */  beqz       $v0, .L8001EC44
    /* E5AC 8001DDAC 02000224 */   addiu     $v0, $zero, 0x2
    /* E5B0 8001DDB0 1000A382 */  lb         $v1, 0x10($s5)
    /* E5B4 8001DDB4 00000000 */  nop
    /* E5B8 8001DDB8 0C006214 */  bne        $v1, $v0, .L8001DDEC
    /* E5BC 8001DDBC 00000000 */   nop
    /* E5C0 8001DDC0 C002828F */  lw         $v0, %gp_rel(D_8009B1C8)($gp)
    /* E5C4 8001DDC4 00000000 */  nop
    /* E5C8 8001DDC8 19004280 */  lb         $v0, 0x19($v0)
    /* E5CC 8001DDCC 00000000 */  nop
    /* E5D0 8001DDD0 B8014014 */  bnez       $v0, .L8001E4B4
    /* E5D4 8001DDD4 00000000 */   nop
    /* E5D8 8001DDD8 64028297 */  lhu        $v0, %gp_rel(D_8009B16C)($gp)
    /* E5DC 8001DDDC 00000000 */  nop
    /* E5E0 8001DDE0 00104230 */  andi       $v0, $v0, 0x1000
    /* E5E4 8001DDE4 B3014014 */  bnez       $v0, .L8001E4B4
    /* E5E8 8001DDE8 00000000 */   nop
  .L8001DDEC:
    /* E5EC 8001DDEC 1000A282 */  lb         $v0, 0x10($s5)
    /* E5F0 8001DDF0 00000000 */  nop
    /* E5F4 8001DDF4 02004228 */  slti       $v0, $v0, 0x2
    /* E5F8 8001DDF8 AE014014 */  bnez       $v0, .L8001E4B4
    /* E5FC 8001DDFC 00000000 */   nop
  .L8001DE00:
    /* E600 8001DE00 1000A382 */  lb         $v1, 0x10($s5)
    /* E604 8001DE04 0F00A482 */  lb         $a0, 0xF($s5)
    /* E608 8001DE08 80100300 */  sll        $v0, $v1, 2
    /* E60C 8001DE0C 21104300 */  addu       $v0, $v0, $v1
    /* E610 8001DE10 21304400 */  addu       $a2, $v0, $a0
    /* E614 8001DE14 0980033C */  lui        $v1, %hi(D_800907D8)
    /* E618 8001DE18 CD028493 */  lbu        $a0, %gp_rel(D_8009B1D5)($gp)
    /* E61C 8001DE1C D8076324 */  addiu      $v1, $v1, %lo(D_800907D8)
    /* E620 8001DE20 80100400 */  sll        $v0, $a0, 2
    /* E624 8001DE24 21104400 */  addu       $v0, $v0, $a0
    /* E628 8001DE28 80100200 */  sll        $v0, $v0, 2
    /* E62C 8001DE2C 2110C200 */  addu       $v0, $a2, $v0
    /* E630 8001DE30 21104300 */  addu       $v0, $v0, $v1
    /* E634 8001DE34 00004290 */  lbu        $v0, 0x0($v0)
    /* E638 8001DE38 00000000 */  nop
    /* E63C 8001DE3C C0180200 */  sll        $v1, $v0, 3
    /* E640 8001DE40 23186200 */  subu       $v1, $v1, $v0
    /* E644 8001DE44 80180300 */  sll        $v1, $v1, 2
    /* E648 8001DE48 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* E64C 8001DE4C D87A4224 */  addiu      $v0, $v0, %lo(D_801A7AD8)
    /* E650 8001DE50 21806200 */  addu       $s0, $v1, $v0
    /* E654 8001DE54 1400028E */  lw         $v0, 0x14($s0)
    /* E658 8001DE58 00C8033C */  lui        $v1, (0xC8000000 >> 16)
    /* E65C 8001DE5C 24104300 */  and        $v0, $v0, $v1
    /* E660 8001DE60 0080033C */  lui        $v1, (0x80000000 >> 16)
    /* E664 8001DE64 93014314 */  bne        $v0, $v1, .L8001E4B4
    /* E668 8001DE68 00000000 */   nop
    /* E66C 8001DE6C B8FF000C */  jal        func_8003FEE0
    /* E670 8001DE70 07000424 */   addiu     $a0, $zero, 0x7
    /* E674 8001DE74 F002848F */  lw         $a0, %gp_rel(D_8009B1F8)($gp)
    /* E678 8001DE78 DB00010C */  jal        func_8004036C
    /* E67C 8001DE7C 00000000 */   nop
    /* E680 8001DE80 F00280AF */  sw         $zero, %gp_rel(D_8009B1F8)($gp)
    /* E684 8001DE84 1000B482 */  lb         $s4, 0x10($s5)
    /* E688 8001DE88 00000000 */  nop
    /* E68C 8001DE8C 0200822A */  slti       $v0, $s4, 0x2
    /* E690 8001DE90 6C034014 */  bnez       $v0, .L8001EC44
    /* E694 8001DE94 00000000 */   nop
    /* E698 8001DE98 CD028293 */  lbu        $v0, %gp_rel(D_8009B1D5)($gp)
    /* E69C 8001DE9C 00000000 */  nop
    /* E6A0 8001DEA0 C0180200 */  sll        $v1, $v0, 3
    /* E6A4 8001DEA4 23186200 */  subu       $v1, $v1, $v0
    /* E6A8 8001DEA8 00190300 */  sll        $v1, $v1, 4
    /* E6AC 8001DEAC 0F80023C */  lui        $v0, %hi(D_800E9F64)
    /* E6B0 8001DEB0 649F4224 */  addiu      $v0, $v0, %lo(D_800E9F64)
    /* E6B4 8001DEB4 21A86200 */  addu       $s5, $v1, $v0
    /* E6B8 8001DEB8 0300822A */  slti       $v0, $s4, 0x3
    /* E6BC 8001DEBC 17004014 */  bnez       $v0, .L8001DF1C
    /* E6C0 8001DEC0 04000224 */   addiu     $v0, $zero, 0x4
    /* E6C4 8001DEC4 1D80033C */  lui        $v1, %hi(D_801D4244)
    /* E6C8 8001DEC8 0C000286 */  lh         $v0, 0xC($s0)
    /* E6CC 8001DECC 44426324 */  addiu      $v1, $v1, %lo(D_801D4244)
    /* E6D0 8001DED0 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* E6D4 8001DED4 80100200 */  sll        $v0, $v0, 2
    /* E6D8 8001DED8 21104300 */  addu       $v0, $v0, $v1
    /* E6DC 8001DEDC 0000428C */  lw         $v0, 0x0($v0)
    /* E6E0 8001DEE0 07000324 */  addiu      $v1, $zero, 0x7
    /* E6E4 8001DEE4 6C0283A3 */  sb         $v1, %gp_rel(D_8009B174)($gp)
    /* E6E8 8001DEE8 17000324 */  addiu      $v1, $zero, 0x17
    /* E6EC 8001DEEC 83160200 */  sra        $v0, $v0, 26
    /* E6F0 8001DEF0 1F004230 */  andi       $v0, $v0, 0x1F
    /* E6F4 8001DEF4 53034314 */  bne        $v0, $v1, .L8001EC44
    /* E6F8 8001DEF8 02000224 */   addiu     $v0, $zero, 0x2
    /* E6FC 8001DEFC 03000324 */  addiu      $v1, $zero, 0x3
    /* E700 8001DF00 1100A2A2 */  sb         $v0, 0x11($s5)
    /* E704 8001DF04 1000A2A2 */  sb         $v0, 0x10($s5)
    /* E708 8001DF08 04000224 */  addiu      $v0, $zero, 0x4
    /* E70C 8001DF0C 1200A3A2 */  sb         $v1, 0x12($s5)
    /* E710 8001DF10 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* E714 8001DF14 117B0008 */  j          .L8001EC44
    /* E718 8001DF18 00000000 */   nop
  .L8001DF1C:
    /* E71C 8001DF1C 01000324 */  addiu      $v1, $zero, 0x1
    /* E720 8001DF20 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* E724 8001DF24 02000224 */  addiu      $v0, $zero, 0x2
    /* E728 8001DF28 1100A3A2 */  sb         $v1, 0x11($s5)
    /* E72C 8001DF2C 1200A2A2 */  sb         $v0, 0x12($s5)
    /* E730 8001DF30 117B0008 */  j          .L8001EC44
    /* E734 8001DF34 1000A3A2 */   sb        $v1, 0x10($s5)
  jlabel .L8001DF38
    /* E738 8001DF38 CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* E73C 8001DF3C 00000000 */  nop
    /* E740 8001DF40 C0100300 */  sll        $v0, $v1, 3
    /* E744 8001DF44 23104300 */  subu       $v0, $v0, $v1
    /* E748 8001DF48 00110200 */  sll        $v0, $v0, 4
    /* E74C 8001DF4C 0F80033C */  lui        $v1, %hi(D_800E9F64)
    /* E750 8001DF50 649F7024 */  addiu      $s0, $v1, %lo(D_800E9F64)
    /* E754 8001DF54 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* E758 8001DF58 21A85000 */  addu       $s5, $v0, $s0
    /* E75C 8001DF5C 80006230 */  andi       $v0, $v1, 0x80
    /* E760 8001DF60 45004014 */  bnez       $v0, .L8001E078
    /* E764 8001DF64 2120A002 */   addu      $a0, $s5, $zero
    /* E768 8001DF68 80006234 */  ori        $v0, $v1, 0x80
    /* E76C 8001DF6C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* E770 8001DF70 74000224 */  addiu      $v0, $zero, 0x74
    /* E774 8001DF74 AC0295AF */  sw         $s5, %gp_rel(D_8009B1B4)($gp)
    /* E778 8001DF78 1800A0A2 */  sb         $zero, 0x18($s5)
    /* E77C 8001DF7C 398D000C */  jal        func_800234E4
    /* E780 8001DF80 0C00A2A6 */   sh        $v0, 0xC($s5)
    /* E784 8001DF84 10000424 */  addiu      $a0, $zero, 0x10
    /* E788 8001DF88 4E010524 */  addiu      $a1, $zero, 0x14E
    /* E78C 8001DF8C 18008227 */  addiu      $v0, $gp, %gp_rel(D_8009AF20)
    /* E790 8001DF90 0980073C */  lui        $a3, %hi(D_800907AC)
    /* E794 8001DF94 AC07E724 */  addiu      $a3, $a3, %lo(D_800907AC)
    /* E798 8001DF98 CD028893 */  lbu        $t0, %gp_rel(D_8009B1D5)($gp)
    /* E79C 8001DF9C 1800A392 */  lbu        $v1, 0x18($s5)
    /* E7A0 8001DFA0 40480800 */  sll        $t1, $t0, 1
    /* E7A4 8001DFA4 21482201 */  addu       $t1, $t1, $v0
    /* E7A8 8001DFA8 C0180300 */  sll        $v1, $v1, 3
    /* E7AC 8001DFAC 1000A282 */  lb         $v0, 0x10($s5)
    /* E7B0 8001DFB0 00410800 */  sll        $t0, $t0, 4
    /* E7B4 8001DFB4 40100200 */  sll        $v0, $v0, 1
    /* E7B8 8001DFB8 21104300 */  addu       $v0, $v0, $v1
    /* E7BC 8001DFBC 21104800 */  addu       $v0, $v0, $t0
    /* E7C0 8001DFC0 21104700 */  addu       $v0, $v0, $a3
    /* E7C4 8001DFC4 00002795 */  lhu        $a3, 0x0($t1)
    /* E7C8 8001DFC8 00004284 */  lh         $v0, 0x0($v0)
    /* E7CC 8001DFCC FE030624 */  addiu      $a2, $zero, 0x3FE
    /* E7D0 8001DFD0 658B000C */  jal        func_80022D94
    /* E7D4 8001DFD4 1000A2AF */   sw        $v0, 0x10($sp)
    /* E7D8 8001DFD8 0400B28E */  lw         $s2, 0x4($s5)
    /* E7DC 8001DFDC CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* E7E0 8001DFE0 00000000 */  nop
    /* E7E4 8001DFE4 C0100300 */  sll        $v0, $v1, 3
    /* E7E8 8001DFE8 23104300 */  subu       $v0, $v0, $v1
    /* E7EC 8001DFEC 00110200 */  sll        $v0, $v0, 4
    /* E7F0 8001DFF0 21100202 */  addu       $v0, $s0, $v0
    /* E7F4 8001DFF4 E8FF508C */  lw         $s0, -0x18($v0)
    /* E7F8 8001DFF8 760A010C */  jal        func_800429D8
    /* E7FC 8001DFFC 21204002 */   addu      $a0, $s2, $zero
    /* E800 8001E000 2800438E */  lw         $v1, 0x28($s2)
    /* E804 8001E004 10000224 */  addiu      $v0, $zero, 0x10
    /* E808 8001E008 600042A6 */  sh         $v0, 0x60($s2)
    /* E80C 8001E00C 28004286 */  lh         $v0, 0x28($s2)
    /* E810 8001E010 6C0040A2 */  sb         $zero, 0x6C($s2)
    /* E814 8001E014 2C0043AE */  sw         $v1, 0x2C($s2)
    /* E818 8001E018 28000386 */  lh         $v1, 0x28($s0)
    /* E81C 8001E01C 00000000 */  nop
    /* E820 8001E020 23104300 */  subu       $v0, $v0, $v1
    /* E824 8001E024 00120200 */  sll        $v0, $v0, 8
    /* E828 8001E028 02004104 */  bgez       $v0, .L8001E034
    /* E82C 8001E02C 00000000 */   nop
    /* E830 8001E030 0F004224 */  addiu      $v0, $v0, 0xF
  .L8001E034:
    /* E834 8001E034 03110200 */  sra        $v0, $v0, 4
    /* E838 8001E038 360042A6 */  sh         $v0, 0x36($s2)
    /* E83C 8001E03C 2A004286 */  lh         $v0, 0x2A($s2)
    /* E840 8001E040 2A000386 */  lh         $v1, 0x2A($s0)
    /* E844 8001E044 00000000 */  nop
    /* E848 8001E048 23104300 */  subu       $v0, $v0, $v1
    /* E84C 8001E04C 00120200 */  sll        $v0, $v0, 8
    /* E850 8001E050 02004104 */  bgez       $v0, .L8001E05C
    /* E854 8001E054 00000000 */   nop
    /* E858 8001E058 0F004224 */  addiu      $v0, $v0, 0xF
  .L8001E05C:
    /* E85C 8001E05C 03110200 */  sra        $v0, $v0, 4
    /* E860 8001E060 3A0042A6 */  sh         $v0, 0x3A($s2)
    /* E864 8001E064 2800038E */  lw         $v1, 0x28($s0)
    /* E868 8001E068 52000224 */  addiu      $v0, $zero, 0x52
    /* E86C 8001E06C 5A0282A7 */  sh         $v0, %gp_rel(D_8009B162)($gp)
    /* E870 8001E070 117B0008 */  j          .L8001EC44
    /* E874 8001E074 280043AE */   sw        $v1, 0x28($s2)
  .L8001E078:
    /* E878 8001E078 5A028297 */  lhu        $v0, %gp_rel(D_8009B162)($gp)
    /* E87C 8001E07C 00000000 */  nop
    /* E880 8001E080 F0024014 */  bnez       $v0, .L8001EC44
    /* E884 8001E084 00000000 */   nop
    /* E888 8001E088 238D000C */  jal        func_8002348C
    /* E88C 8001E08C 2120A002 */   addu      $a0, $s5, $zero
    /* E890 8001E090 12038393 */  lbu        $v1, %gp_rel(D_8009B21A)($gp)
    /* E894 8001E094 06000224 */  addiu      $v0, $zero, 0x6
    /* E898 8001E098 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* E89C 8001E09C E9026010 */  beqz       $v1, .L8001EC44
    /* E8A0 8001E0A0 05000224 */   addiu     $v0, $zero, 0x5
    /* E8A4 8001E0A4 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* E8A8 8001E0A8 117B0008 */  j          .L8001EC44
    /* E8AC 8001E0AC 00000000 */   nop
  jlabel .L8001E0B0
    /* E8B0 8001E0B0 CD028293 */  lbu        $v0, %gp_rel(D_8009B1D5)($gp)
    /* E8B4 8001E0B4 6C028493 */  lbu        $a0, %gp_rel(D_8009B174)($gp)
    /* E8B8 8001E0B8 C0180200 */  sll        $v1, $v0, 3
    /* E8BC 8001E0BC 23186200 */  subu       $v1, $v1, $v0
    /* E8C0 8001E0C0 00190300 */  sll        $v1, $v1, 4
    /* E8C4 8001E0C4 0F80023C */  lui        $v0, %hi(D_800E9F64)
    /* E8C8 8001E0C8 649F4224 */  addiu      $v0, $v0, %lo(D_800E9F64)
    /* E8CC 8001E0CC 21A86200 */  addu       $s5, $v1, $v0
    /* E8D0 8001E0D0 80008230 */  andi       $v0, $a0, 0x80
    /* E8D4 8001E0D4 17004014 */  bnez       $v0, .L8001E134
    /* E8D8 8001E0D8 0F80023C */   lui       $v0, %hi(D_800EAE92)
    /* E8DC 8001E0DC 92AE5490 */  lbu        $s4, %lo(D_800EAE92)($v0)
    /* E8E0 8001E0E0 80008234 */  ori        $v0, $a0, 0x80
    /* E8E4 8001E0E4 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* E8E8 8001E0E8 210380A3 */  sb         $zero, %gp_rel(D_8009B229)($gp)
    /* E8EC 8001E0EC 3800822A */  slti       $v0, $s4, 0x38
    /* E8F0 8001E0F0 0B004010 */  beqz       $v0, .L8001E120
    /* E8F4 8001E0F4 0600822A */   slti      $v0, $s4, 0x6
    /* E8F8 8001E0F8 05004014 */  bnez       $v0, .L8001E110
    /* E8FC 8001E0FC 00000000 */   nop
    /* E900 8001E100 FAFF8226 */  addiu      $v0, $s4, -0x6
    /* E904 8001E104 CE0282A3 */  sb         $v0, %gp_rel(D_8009B1D6)($gp)
    /* E908 8001E108 4C780008 */  j          .L8001E130
    /* E90C 8001E10C 03000224 */   addiu     $v0, $zero, 0x3
  .L8001E110:
    /* E910 8001E110 FFFF8226 */  addiu      $v0, $s4, -0x1
    /* E914 8001E114 CE0282A3 */  sb         $v0, %gp_rel(D_8009B1D6)($gp)
    /* E918 8001E118 4C780008 */  j          .L8001E130
    /* E91C 8001E11C 02000224 */   addiu     $v0, $zero, 0x2
  .L8001E120:
    /* E920 8001E120 3C000224 */  addiu      $v0, $zero, 0x3C
    /* E924 8001E124 23105400 */  subu       $v0, $v0, $s4
    /* E928 8001E128 CE0282A3 */  sb         $v0, %gp_rel(D_8009B1D6)($gp)
    /* E92C 8001E12C 01000224 */  addiu      $v0, $zero, 0x1
  .L8001E130:
    /* E930 8001E130 CF0282A3 */  sb         $v0, %gp_rel(D_8009B1D7)($gp)
  .L8001E134:
    /* E934 8001E134 6D75000C */  jal        func_8001D5B4
    /* E938 8001E138 2120A002 */   addu      $a0, $s5, $zero
    /* E93C 8001E13C C1024014 */  bnez       $v0, .L8001EC44
    /* E940 8001E140 21A00000 */   addu      $s4, $zero, $zero
    /* E944 8001E144 F4780008 */  j          .L8001E3D0
    /* E948 8001E148 00000000 */   nop
  jlabel .L8001E14C
    /* E94C 8001E14C CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* E950 8001E150 00000000 */  nop
    /* E954 8001E154 C0100300 */  sll        $v0, $v1, 3
    /* E958 8001E158 23104300 */  subu       $v0, $v0, $v1
    /* E95C 8001E15C 00110200 */  sll        $v0, $v0, 4
    /* E960 8001E160 0F80033C */  lui        $v1, %hi(D_800E9F64)
    /* E964 8001E164 649F7024 */  addiu      $s0, $v1, %lo(D_800E9F64)
    /* E968 8001E168 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* E96C 8001E16C 21A85000 */  addu       $s5, $v0, $s0
    /* E970 8001E170 80006230 */  andi       $v0, $v1, 0x80
    /* E974 8001E174 03004010 */  beqz       $v0, .L8001E184
    /* E978 8001E178 80006234 */   ori       $v0, $v1, 0x80
    /* E97C 8001E17C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* E980 8001E180 AC0295AF */  sw         $s5, %gp_rel(D_8009B1B4)($gp)
  .L8001E184:
    /* E984 8001E184 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* E988 8001E188 00000000 */  nop
    /* E98C 8001E18C 40004230 */  andi       $v0, $v0, 0x40
    /* E990 8001E190 10004010 */  beqz       $v0, .L8001E1D4
    /* E994 8001E194 00000000 */   nop
    /* E998 8001E198 5A028297 */  lhu        $v0, %gp_rel(D_8009B162)($gp)
    /* E99C 8001E19C 00000000 */  nop
    /* E9A0 8001E1A0 A8024014 */  bnez       $v0, .L8001EC44
    /* E9A4 8001E1A4 00000000 */   nop
    /* E9A8 8001E1A8 0400A48E */  lw         $a0, 0x4($s5)
    /* E9AC 8001E1AC DB00010C */  jal        func_8004036C
    /* E9B0 8001E1B0 00000000 */   nop
    /* E9B4 8001E1B4 CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* E9B8 8001E1B8 03000224 */  addiu      $v0, $zero, 0x3
    /* E9BC 8001E1BC 0400A0AE */  sw         $zero, 0x4($s5)
    /* E9C0 8001E1C0 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* E9C4 8001E1C4 C0100300 */  sll        $v0, $v1, 3
    /* E9C8 8001E1C8 23104300 */  subu       $v0, $v0, $v1
    /* E9CC 8001E1CC E37A0008 */  j          .L8001EB8C
    /* E9D0 8001E1D0 00110200 */   sll       $v0, $v0, 4
  .L8001E1D4:
    /* E9D4 8001E1D4 1890000C */  jal        func_80024060
    /* E9D8 8001E1D8 2120A002 */   addu      $a0, $s5, $zero
    /* E9DC 8001E1DC 99024014 */  bnez       $v0, .L8001EC44
    /* E9E0 8001E1E0 00000000 */   nop
    /* E9E4 8001E1E4 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* E9E8 8001E1E8 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* E9EC 8001E1EC 00000000 */  nop
    /* E9F0 8001E1F0 20004230 */  andi       $v0, $v0, 0x20
    /* E9F4 8001E1F4 45004010 */  beqz       $v0, .L8001E30C
    /* E9F8 8001E1F8 4E010524 */   addiu     $a1, $zero, 0x14E
    /* E9FC 8001E1FC 10000424 */  addiu      $a0, $zero, 0x10
    /* EA00 8001E200 18008227 */  addiu      $v0, $gp, %gp_rel(D_8009AF20)
    /* EA04 8001E204 0980083C */  lui        $t0, %hi(D_800907AC)
    /* EA08 8001E208 AC070825 */  addiu      $t0, $t0, %lo(D_800907AC)
    /* EA0C 8001E20C CD028793 */  lbu        $a3, %gp_rel(D_8009B1D5)($gp)
    /* EA10 8001E210 ACFF1026 */  addiu      $s0, $s0, -0x54
    /* EA14 8001E214 40480700 */  sll        $t1, $a3, 1
    /* EA18 8001E218 21482201 */  addu       $t1, $t1, $v0
    /* EA1C 8001E21C C0100700 */  sll        $v0, $a3, 3
    /* EA20 8001E220 23104700 */  subu       $v0, $v0, $a3
    /* EA24 8001E224 00110200 */  sll        $v0, $v0, 4
    /* EA28 8001E228 21105000 */  addu       $v0, $v0, $s0
    /* EA2C 8001E22C 00390700 */  sll        $a3, $a3, 4
    /* EA30 8001E230 48004380 */  lb         $v1, 0x48($v0)
    /* EA34 8001E234 50004290 */  lbu        $v0, 0x50($v0)
    /* EA38 8001E238 40180300 */  sll        $v1, $v1, 1
    /* EA3C 8001E23C C0100200 */  sll        $v0, $v0, 3
    /* EA40 8001E240 21186200 */  addu       $v1, $v1, $v0
    /* EA44 8001E244 21186700 */  addu       $v1, $v1, $a3
    /* EA48 8001E248 21186800 */  addu       $v1, $v1, $t0
    /* EA4C 8001E24C 00002795 */  lhu        $a3, 0x0($t1)
    /* EA50 8001E250 00006284 */  lh         $v0, 0x0($v1)
    /* EA54 8001E254 FE030624 */  addiu      $a2, $zero, 0x3FE
    /* EA58 8001E258 658B000C */  jal        func_80022D94
    /* EA5C 8001E25C 1000A2AF */   sw        $v0, 0x10($sp)
    /* EA60 8001E260 0400B28E */  lw         $s2, 0x4($s5)
    /* EA64 8001E264 CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* EA68 8001E268 00000000 */  nop
    /* EA6C 8001E26C C0100300 */  sll        $v0, $v1, 3
    /* EA70 8001E270 23104300 */  subu       $v0, $v0, $v1
    /* EA74 8001E274 00110200 */  sll        $v0, $v0, 4
    /* EA78 8001E278 21105000 */  addu       $v0, $v0, $s0
    /* EA7C 8001E27C 3C00508C */  lw         $s0, 0x3C($v0)
    /* EA80 8001E280 760A010C */  jal        func_800429D8
    /* EA84 8001E284 21204002 */   addu      $a0, $s2, $zero
    /* EA88 8001E288 28004386 */  lh         $v1, 0x28($s2)
    /* EA8C 8001E28C 10000224 */  addiu      $v0, $zero, 0x10
    /* EA90 8001E290 600042A6 */  sh         $v0, 0x60($s2)
    /* EA94 8001E294 6C0040A2 */  sb         $zero, 0x6C($s2)
    /* EA98 8001E298 28000286 */  lh         $v0, 0x28($s0)
    /* EA9C 8001E29C 00000000 */  nop
    /* EAA0 8001E2A0 23104300 */  subu       $v0, $v0, $v1
    /* EAA4 8001E2A4 00120200 */  sll        $v0, $v0, 8
    /* EAA8 8001E2A8 02004104 */  bgez       $v0, .L8001E2B4
    /* EAAC 8001E2AC 00000000 */   nop
    /* EAB0 8001E2B0 0F004224 */  addiu      $v0, $v0, 0xF
  .L8001E2B4:
    /* EAB4 8001E2B4 03110200 */  sra        $v0, $v0, 4
    /* EAB8 8001E2B8 360042A6 */  sh         $v0, 0x36($s2)
    /* EABC 8001E2BC 2A000286 */  lh         $v0, 0x2A($s0)
    /* EAC0 8001E2C0 2A004386 */  lh         $v1, 0x2A($s2)
    /* EAC4 8001E2C4 00000000 */  nop
    /* EAC8 8001E2C8 23104300 */  subu       $v0, $v0, $v1
    /* EACC 8001E2CC 00120200 */  sll        $v0, $v0, 8
    /* EAD0 8001E2D0 02004104 */  bgez       $v0, .L8001E2DC
    /* EAD4 8001E2D4 00000000 */   nop
    /* EAD8 8001E2D8 0F004224 */  addiu      $v0, $v0, 0xF
  .L8001E2DC:
    /* EADC 8001E2DC 03110200 */  sra        $v0, $v0, 4
    /* EAE0 8001E2E0 3A0042A6 */  sh         $v0, 0x3A($s2)
    /* EAE4 8001E2E4 2800028E */  lw         $v0, 0x28($s0)
    /* EAE8 8001E2E8 00000000 */  nop
    /* EAEC 8001E2EC 2C0042AE */  sw         $v0, 0x2C($s2)
    /* EAF0 8001E2F0 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* EAF4 8001E2F4 58000324 */  addiu      $v1, $zero, 0x58
    /* EAF8 8001E2F8 5A0283A7 */  sh         $v1, %gp_rel(D_8009B162)($gp)
    /* EAFC 8001E2FC 40004234 */  ori        $v0, $v0, 0x40
  .L8001E300:
    /* EB00 8001E300 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* EB04 8001E304 117B0008 */  j          .L8001EC44
    /* EB08 8001E308 00000000 */   nop
  .L8001E30C:
    /* EB0C 8001E30C 0980053C */  lui        $a1, %hi(D_800907D8)
    /* EB10 8001E310 1000A282 */  lb         $v0, 0x10($s5)
    /* EB14 8001E314 D807A524 */  addiu      $a1, $a1, %lo(D_800907D8)
    /* EB18 8001E318 80180200 */  sll        $v1, $v0, 2
    /* EB1C 8001E31C 21186200 */  addu       $v1, $v1, $v0
    /* EB20 8001E320 0F00A282 */  lb         $v0, 0xF($s5)
    /* EB24 8001E324 CD028493 */  lbu        $a0, %gp_rel(D_8009B1D5)($gp)
    /* EB28 8001E328 21186200 */  addu       $v1, $v1, $v0
    /* EB2C 8001E32C 80100400 */  sll        $v0, $a0, 2
    /* EB30 8001E330 21104400 */  addu       $v0, $v0, $a0
    /* EB34 8001E334 80100200 */  sll        $v0, $v0, 2
    /* EB38 8001E338 21186200 */  addu       $v1, $v1, $v0
    /* EB3C 8001E33C 21186500 */  addu       $v1, $v1, $a1
    /* EB40 8001E340 1A80043C */  lui        $a0, %hi(D_801A7AD8)
    /* EB44 8001E344 00006390 */  lbu        $v1, 0x0($v1)
    /* EB48 8001E348 D87A8424 */  addiu      $a0, $a0, %lo(D_801A7AD8)
    /* EB4C 8001E34C C0100300 */  sll        $v0, $v1, 3
    /* EB50 8001E350 23104300 */  subu       $v0, $v0, $v1
    /* EB54 8001E354 80100200 */  sll        $v0, $v0, 2
    /* EB58 8001E358 0D5C000C */  jal        func_80017034
    /* EB5C 8001E35C 21204400 */   addu      $a0, $v0, $a0
    /* EB60 8001E360 21A04000 */  addu       $s4, $v0, $zero
    /* EB64 8001E364 0C008012 */  beqz       $s4, .L8001E398
    /* EB68 8001E368 14000224 */   addiu     $v0, $zero, 0x14
  .L8001E36C:
    /* EB6C 8001E36C 0A80013C */  lui        $at, %hi(D_8009B24B)
    /* EB70 8001E370 4BB222A0 */  sb         $v0, %lo(D_8009B24B)($at)
    /* EB74 8001E374 02000224 */  addiu      $v0, $zero, 0x2
    /* EB78 8001E378 0A80013C */  lui        $at, %hi(D_8009B246)
    /* EB7C 8001E37C 46B234A4 */  sh         $s4, %lo(D_8009B246)($at)
    /* EB80 8001E380 0A80013C */  lui        $at, %hi(D_8009B254)
    /* EB84 8001E384 54B222A0 */  sb         $v0, %lo(D_8009B254)($at)
    /* EB88 8001E388 117B0008 */  j          .L8001EC44
    /* EB8C 8001E38C 00000000 */   nop
  .L8001E390:
    /* EB90 8001E390 12790008 */  j          .L8001E448
    /* EB94 8001E394 21A00000 */   addu      $s4, $zero, $zero
  .L8001E398:
    /* EB98 8001E398 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* EB9C 8001E39C 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* EBA0 8001E3A0 00000000 */  nop
    /* EBA4 8001E3A4 C0004230 */  andi       $v0, $v0, 0xC0
    /* EBA8 8001E3A8 26024010 */  beqz       $v0, .L8001EC44
    /* EBAC 8001E3AC 00000000 */   nop
    /* EBB0 8001E3B0 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* EBB4 8001E3B4 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* EBB8 8001E3B8 210380A3 */  sb         $zero, %gp_rel(D_8009B229)($gp)
    /* EBBC 8001E3BC 80004230 */  andi       $v0, $v0, 0x80
    /* EBC0 8001E3C0 02004010 */  beqz       $v0, .L8001E3CC
    /* EBC4 8001E3C4 01000224 */   addiu     $v0, $zero, 0x1
    /* EBC8 8001E3C8 210382A3 */  sb         $v0, %gp_rel(D_8009B229)($gp)
  .L8001E3CC:
    /* EBCC 8001E3CC 21A00000 */  addu       $s4, $zero, $zero
  .L8001E3D0:
    /* EBD0 8001E3D0 1000A382 */  lb         $v1, 0x10($s5)
    /* EBD4 8001E3D4 01000224 */  addiu      $v0, $zero, 0x1
    /* EBD8 8001E3D8 1C006214 */  bne        $v1, $v0, .L8001E44C
    /* EBDC 8001E3DC 05000624 */   addiu     $a2, $zero, 0x5
    /* EBE0 8001E3E0 21A04000 */  addu       $s4, $v0, $zero
    /* EBE4 8001E3E4 21200000 */  addu       $a0, $zero, $zero
    /* EBE8 8001E3E8 0980023C */  lui        $v0, %hi(D_800907D8)
    /* EBEC 8001E3EC D8074824 */  addiu      $t0, $v0, %lo(D_800907D8)
    /* EBF0 8001E3F0 CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* EBF4 8001E3F4 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* EBF8 8001E3F8 D87A4724 */  addiu      $a3, $v0, %lo(D_801A7AD8)
    /* EBFC 8001E3FC 80100300 */  sll        $v0, $v1, 2
    /* EC00 8001E400 21104300 */  addu       $v0, $v0, $v1
    /* EC04 8001E404 80280200 */  sll        $a1, $v0, 2
  .L8001E408:
    /* EC08 8001E408 2110C500 */  addu       $v0, $a2, $a1
    /* EC0C 8001E40C 21104800 */  addu       $v0, $v0, $t0
    /* EC10 8001E410 00004390 */  lbu        $v1, 0x0($v0)
    /* EC14 8001E414 00000000 */  nop
    /* EC18 8001E418 C0100300 */  sll        $v0, $v1, 3
    /* EC1C 8001E41C 23104300 */  subu       $v0, $v0, $v1
    /* EC20 8001E420 80100200 */  sll        $v0, $v0, 2
    /* EC24 8001E424 21984700 */  addu       $s3, $v0, $a3
    /* EC28 8001E428 16006296 */  lhu        $v0, 0x16($s3)
    /* EC2C 8001E42C 00000000 */  nop
    /* EC30 8001E430 00804230 */  andi       $v0, $v0, 0x8000
    /* EC34 8001E434 D6FF4014 */  bnez       $v0, .L8001E390
    /* EC38 8001E438 01008424 */   addiu     $a0, $a0, 0x1
    /* EC3C 8001E43C 05008228 */  slti       $v0, $a0, 0x5
    /* EC40 8001E440 F1FF4014 */  bnez       $v0, .L8001E408
    /* EC44 8001E444 0100C624 */   addiu     $a2, $a2, 0x1
  .L8001E448:
    /* EC48 8001E448 1000A382 */  lb         $v1, 0x10($s5)
  .L8001E44C:
    /* EC4C 8001E44C 0F00A482 */  lb         $a0, 0xF($s5)
    /* EC50 8001E450 80100300 */  sll        $v0, $v1, 2
    /* EC54 8001E454 21104300 */  addu       $v0, $v0, $v1
    /* EC58 8001E458 21304400 */  addu       $a2, $v0, $a0
    /* EC5C 8001E45C 0980033C */  lui        $v1, %hi(D_800907D8)
    /* EC60 8001E460 CD028493 */  lbu        $a0, %gp_rel(D_8009B1D5)($gp)
    /* EC64 8001E464 D8076324 */  addiu      $v1, $v1, %lo(D_800907D8)
    /* EC68 8001E468 80100400 */  sll        $v0, $a0, 2
    /* EC6C 8001E46C 21104400 */  addu       $v0, $v0, $a0
    /* EC70 8001E470 80100200 */  sll        $v0, $v0, 2
    /* EC74 8001E474 2110C200 */  addu       $v0, $a2, $v0
    /* EC78 8001E478 21104300 */  addu       $v0, $v0, $v1
    /* EC7C 8001E47C 00004290 */  lbu        $v0, 0x0($v0)
    /* EC80 8001E480 00000000 */  nop
    /* EC84 8001E484 C0180200 */  sll        $v1, $v0, 3
    /* EC88 8001E488 23186200 */  subu       $v1, $v1, $v0
    /* EC8C 8001E48C 80180300 */  sll        $v1, $v1, 2
    /* EC90 8001E490 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* EC94 8001E494 D87A4224 */  addiu      $v0, $v0, %lo(D_801A7AD8)
    /* EC98 8001E498 0A008016 */  bnez       $s4, .L8001E4C4
    /* EC9C 8001E49C 21986200 */   addu      $s3, $v1, $v0
    /* ECA0 8001E4A0 16006296 */  lhu        $v0, 0x16($s3)
    /* ECA4 8001E4A4 00000000 */  nop
    /* ECA8 8001E4A8 00804230 */  andi       $v0, $v0, 0x8000
    /* ECAC 8001E4AC 05004014 */  bnez       $v0, .L8001E4C4
    /* ECB0 8001E4B0 00000000 */   nop
  .L8001E4B4:
    /* ECB4 8001E4B4 B8FF000C */  jal        func_8003FEE0
    /* ECB8 8001E4B8 09000424 */   addiu     $a0, $zero, 0x9
    /* ECBC 8001E4BC 117B0008 */  j          .L8001EC44
    /* ECC0 8001E4C0 00000000 */   nop
  .L8001E4C4:
    /* ECC4 8001E4C4 B8FF000C */  jal        func_8003FEE0
    /* ECC8 8001E4C8 07000424 */   addiu     $a0, $zero, 0x7
    /* ECCC 8001E4CC 06000424 */  addiu      $a0, $zero, 0x6
    /* ECD0 8001E4D0 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* ECD4 8001E4D4 F09E4224 */  addiu      $v0, $v0, %lo(D_800E9EF0)
    /* ECD8 8001E4D8 18004224 */  addiu      $v0, $v0, 0x18
  .L8001E4DC:
    /* ECDC 8001E4DC 000040AC */  sw         $zero, 0x0($v0)
    /* ECE0 8001E4E0 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* ECE4 8001E4E4 FDFF8104 */  bgez       $a0, .L8001E4DC
    /* ECE8 8001E4E8 FCFF4224 */   addiu     $v0, $v0, -0x4
    /* ECEC 8001E4EC 0F80033C */  lui        $v1, %hi(D_800E9F10)
    /* ECF0 8001E4F0 109F6324 */  addiu      $v1, $v1, %lo(D_800E9F10)
    /* ECF4 8001E4F4 0980113C */  lui        $s1, %hi(D_800907D8)
    /* ECF8 8001E4F8 D8073126 */  addiu      $s1, $s1, %lo(D_800907D8)
    /* ECFC 8001E4FC CD028593 */  lbu        $a1, %gp_rel(D_8009B1D5)($gp)
    /* ED00 8001E500 1A80103C */  lui        $s0, %hi(D_801A7AD8)
    /* ED04 8001E504 C0100500 */  sll        $v0, $a1, 3
    /* ED08 8001E508 23104500 */  subu       $v0, $v0, $a1
    /* ED0C 8001E50C 00110200 */  sll        $v0, $v0, 4
    /* ED10 8001E510 21104300 */  addu       $v0, $v0, $v1
    /* ED14 8001E514 48004480 */  lb         $a0, 0x48($v0)
    /* ED18 8001E518 47004280 */  lb         $v0, 0x47($v0)
    /* ED1C 8001E51C 80180400 */  sll        $v1, $a0, 2
    /* ED20 8001E520 21186400 */  addu       $v1, $v1, $a0
    /* ED24 8001E524 21306200 */  addu       $a2, $v1, $v0
    /* ED28 8001E528 80100500 */  sll        $v0, $a1, 2
    /* ED2C 8001E52C 21104500 */  addu       $v0, $v0, $a1
    /* ED30 8001E530 80100200 */  sll        $v0, $v0, 2
    /* ED34 8001E534 2110C200 */  addu       $v0, $a2, $v0
    /* ED38 8001E538 21105100 */  addu       $v0, $v0, $s1
    /* ED3C 8001E53C 00004390 */  lbu        $v1, 0x0($v0)
    /* ED40 8001E540 D87A1026 */  addiu      $s0, $s0, %lo(D_801A7AD8)
    /* ED44 8001E544 C0100300 */  sll        $v0, $v1, 3
    /* ED48 8001E548 23104300 */  subu       $v0, $v0, $v1
    /* ED4C 8001E54C 80100200 */  sll        $v0, $v0, 2
    /* ED50 8001E550 21985000 */  addu       $s3, $v0, $s0
    /* ED54 8001E554 16006296 */  lhu        $v0, 0x16($s3)
    /* ED58 8001E558 00000000 */  nop
    /* ED5C 8001E55C 700282A7 */  sh         $v0, %gp_rel(D_8009B178)($gp)
    /* ED60 8001E560 12006296 */  lhu        $v0, 0x12($s3)
    /* ED64 8001E564 00000000 */  nop
    /* ED68 8001E568 680282A7 */  sh         $v0, %gp_rel(D_8009B170)($gp)
    /* ED6C 8001E56C 08006586 */  lh         $a1, 0x8($s3)
    /* ED70 8001E570 0A006686 */  lh         $a2, 0xA($s3)
    /* ED74 8001E574 C15F000C */  jal        func_80017F04
    /* ED78 8001E578 21206002 */   addu      $a0, $s3, $zero
    /* ED7C 8001E57C 21904000 */  addu       $s2, $v0, $zero
    /* ED80 8001E580 21204002 */  addu       $a0, $s2, $zero
    /* ED84 8001E584 3B0A010C */  jal        func_800428EC
    /* ED88 8001E588 F6FF0524 */   addiu     $a1, $zero, -0xA
    /* ED8C 8001E58C 21206002 */  addu       $a0, $s3, $zero
    /* ED90 8001E590 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* ED94 8001E594 F09E52AC */  sw         $s2, %lo(D_800E9EF0)($v0)
    /* ED98 8001E598 0C009684 */  lh         $s6, 0xC($a0)
    /* ED9C 8001E59C 4592000C */  jal        func_80024914
    /* EDA0 8001E5A0 F09E5724 */   addiu     $s7, $v0, %lo(D_800E9EF0)
    /* EDA4 8001E5A4 1000A382 */  lb         $v1, 0x10($s5)
    /* EDA8 8001E5A8 00000000 */  nop
    /* EDAC 8001E5AC 80100300 */  sll        $v0, $v1, 2
    /* EDB0 8001E5B0 21104300 */  addu       $v0, $v0, $v1
    /* EDB4 8001E5B4 0F00A382 */  lb         $v1, 0xF($s5)
    /* EDB8 8001E5B8 CD028493 */  lbu        $a0, %gp_rel(D_8009B1D5)($gp)
    /* EDBC 8001E5BC 21304300 */  addu       $a2, $v0, $v1
    /* EDC0 8001E5C0 80100400 */  sll        $v0, $a0, 2
    /* EDC4 8001E5C4 21104400 */  addu       $v0, $v0, $a0
    /* EDC8 8001E5C8 80100200 */  sll        $v0, $v0, 2
    /* EDCC 8001E5CC 2110C200 */  addu       $v0, $a2, $v0
    /* EDD0 8001E5D0 21105100 */  addu       $v0, $v0, $s1
    /* EDD4 8001E5D4 00004390 */  lbu        $v1, 0x0($v0)
    /* EDD8 8001E5D8 00000000 */  nop
    /* EDDC 8001E5DC C0100300 */  sll        $v0, $v1, 3
    /* EDE0 8001E5E0 23104300 */  subu       $v0, $v0, $v1
    /* EDE4 8001E5E4 80100200 */  sll        $v0, $v0, 2
    /* EDE8 8001E5E8 21008016 */  bnez       $s4, .L8001E670
    /* EDEC 8001E5EC 21985000 */   addu      $s3, $v0, $s0
    /* EDF0 8001E5F0 16006296 */  lhu        $v0, 0x16($s3)
    /* EDF4 8001E5F4 00000000 */  nop
    /* EDF8 8001E5F8 720282A7 */  sh         $v0, %gp_rel(D_8009B17A)($gp)
    /* EDFC 8001E5FC 12006296 */  lhu        $v0, 0x12($s3)
    /* EE00 8001E600 00000000 */  nop
    /* EE04 8001E604 6A0282A7 */  sh         $v0, %gp_rel(D_8009B172)($gp)
    /* EE08 8001E608 08006586 */  lh         $a1, 0x8($s3)
    /* EE0C 8001E60C 0A006686 */  lh         $a2, 0xA($s3)
    /* EE10 8001E610 C15F000C */  jal        func_80017F04
    /* EE14 8001E614 21206002 */   addu      $a0, $s3, $zero
    /* EE18 8001E618 21904000 */  addu       $s2, $v0, $zero
    /* EE1C 8001E61C 0400F2AE */  sw         $s2, 0x4($s7)
    /* EE20 8001E620 6A004292 */  lbu        $v0, 0x6A($s2)
    /* EE24 8001E624 00000000 */  nop
    /* EE28 8001E628 940282A3 */  sb         $v0, %gp_rel(D_8009B19C)($gp)
    /* EE2C 8001E62C 4592000C */  jal        func_80024914
    /* EE30 8001E630 21206002 */   addu      $a0, $s3, $zero
    /* EE34 8001E634 1D80033C */  lui        $v1, %hi(D_801D4244)
    /* EE38 8001E638 44426324 */  addiu      $v1, $v1, %lo(D_801D4244)
    /* EE3C 8001E63C FFFFC226 */  addiu      $v0, $s6, -0x1
    /* EE40 8001E640 80100200 */  sll        $v0, $v0, 2
    /* EE44 8001E644 21104300 */  addu       $v0, $v0, $v1
    /* EE48 8001E648 0000428C */  lw         $v0, 0x0($v0)
    /* EE4C 8001E64C 17000324 */  addiu      $v1, $zero, 0x17
    /* EE50 8001E650 83160200 */  sra        $v0, $v0, 26
    /* EE54 8001E654 1F004230 */  andi       $v0, $v0, 0x1F
    /* EE58 8001E658 79014314 */  bne        $v0, $v1, .L8001EC40
    /* EE5C 8001E65C 09000224 */   addiu     $v0, $zero, 0x9
    /* EE60 8001E660 08000224 */  addiu      $v0, $zero, 0x8
    /* EE64 8001E664 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* EE68 8001E668 117B0008 */  j          .L8001EC44
    /* EE6C 8001E66C 00000000 */   nop
  .L8001E670:
    /* EE70 8001E670 107B0008 */  j          .L8001EC40
    /* EE74 8001E674 09000224 */   addiu     $v0, $zero, 0x9
  jlabel .L8001E678
    /* EE78 8001E678 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* EE7C 8001E67C 00000000 */  nop
    /* EE80 8001E680 80006230 */  andi       $v0, $v1, 0x80
    /* EE84 8001E684 61004014 */  bnez       $v0, .L8001E80C
    /* EE88 8001E688 80006234 */   ori       $v0, $v1, 0x80
    /* EE8C 8001E68C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* EE90 8001E690 1000A382 */  lb         $v1, 0x10($s5)
    /* EE94 8001E694 0F00A482 */  lb         $a0, 0xF($s5)
    /* EE98 8001E698 80100300 */  sll        $v0, $v1, 2
    /* EE9C 8001E69C 21104300 */  addu       $v0, $v0, $v1
    /* EEA0 8001E6A0 21304400 */  addu       $a2, $v0, $a0
    /* EEA4 8001E6A4 0980033C */  lui        $v1, %hi(D_800907D8)
    /* EEA8 8001E6A8 CD028493 */  lbu        $a0, %gp_rel(D_8009B1D5)($gp)
    /* EEAC 8001E6AC D8076324 */  addiu      $v1, $v1, %lo(D_800907D8)
    /* EEB0 8001E6B0 80100400 */  sll        $v0, $a0, 2
    /* EEB4 8001E6B4 21104400 */  addu       $v0, $v0, $a0
    /* EEB8 8001E6B8 80100200 */  sll        $v0, $v0, 2
    /* EEBC 8001E6BC 2110C200 */  addu       $v0, $a2, $v0
    /* EEC0 8001E6C0 21104300 */  addu       $v0, $v0, $v1
    /* EEC4 8001E6C4 00004390 */  lbu        $v1, 0x0($v0)
    /* EEC8 8001E6C8 00000000 */  nop
    /* EECC 8001E6CC C0100300 */  sll        $v0, $v1, 3
    /* EED0 8001E6D0 23104300 */  subu       $v0, $v0, $v1
    /* EED4 8001E6D4 80100200 */  sll        $v0, $v0, 2
    /* EED8 8001E6D8 1A80033C */  lui        $v1, %hi(D_801A7AD8)
    /* EEDC 8001E6DC D87A7124 */  addiu      $s1, $v1, %lo(D_801A7AD8)
    /* EEE0 8001E6E0 21805100 */  addu       $s0, $v0, $s1
    /* EEE4 8001E6E4 08000586 */  lh         $a1, 0x8($s0)
    /* EEE8 8001E6E8 0A000686 */  lh         $a2, 0xA($s0)
    /* EEEC 8001E6EC C15F000C */  jal        func_80017F04
    /* EEF0 8001E6F0 21200002 */   addu      $a0, $s0, $zero
    /* EEF4 8001E6F4 16000396 */  lhu        $v1, 0x16($s0)
    /* EEF8 8001E6F8 21904000 */  addu       $s2, $v0, $zero
    /* EEFC 8001E6FC FF7F6230 */  andi       $v0, $v1, 0x7FFF
    /* EF00 8001E700 00106330 */  andi       $v1, $v1, 0x1000
    /* EF04 8001E704 06006010 */  beqz       $v1, .L8001E720
    /* EF08 8001E708 160002A6 */   sh        $v0, 0x16($s0)
    /* EF0C 8001E70C 08004296 */  lhu        $v0, 0x8($s2)
    /* EF10 8001E710 80000324 */  addiu      $v1, $zero, 0x80
    /* EF14 8001E714 210043A2 */  sb         $v1, 0x21($s2)
    /* EF18 8001E718 04004234 */  ori        $v0, $v0, 0x4
    /* EF1C 8001E71C 080042A6 */  sh         $v0, 0x8($s2)
  .L8001E720:
    /* EF20 8001E720 0C000224 */  addiu      $v0, $zero, 0xC
    /* EF24 8001E724 600042A6 */  sh         $v0, 0x60($s2)
    /* EF28 8001E728 0280023C */  lui        $v0, %hi(func_8001D3C4)
    /* EF2C 8001E72C C4D34224 */  addiu      $v0, $v0, %lo(func_8001D3C4)
    /* EF30 8001E730 240042AE */  sw         $v0, 0x24($s2)
    /* EF34 8001E734 86000224 */  addiu      $v0, $zero, 0x86
    /* EF38 8001E738 280042A6 */  sh         $v0, 0x28($s2)
    /* EF3C 8001E73C 5A000224 */  addiu      $v0, $zero, 0x5A
    /* EF40 8001E740 2A0042A6 */  sh         $v0, 0x2A($s2)
    /* EF44 8001E744 01000224 */  addiu      $v0, $zero, 0x1
    /* EF48 8001E748 2C0040A6 */  sh         $zero, 0x2C($s2)
    /* EF4C 8001E74C 6C0042A2 */  sb         $v0, 0x6C($s2)
    /* EF50 8001E750 0400A48E */  lw         $a0, 0x4($s5)
    /* EF54 8001E754 12038393 */  lbu        $v1, %gp_rel(D_8009B21A)($gp)
    /* EF58 8001E758 08008294 */  lhu        $v0, 0x8($a0)
    /* EF5C 8001E75C C40292AF */  sw         $s2, %gp_rel(D_8009B1CC)($gp)
    /* EF60 8001E760 BFFF4230 */  andi       $v0, $v0, 0xFFBF
    /* EF64 8001E764 37016014 */  bnez       $v1, .L8001EC44
    /* EF68 8001E768 080082A4 */   sh        $v0, 0x8($a0)
    /* EF6C 8001E76C 2000023C */  lui        $v0, (0x202020 >> 16)
    /* EF70 8001E770 20204234 */  ori        $v0, $v0, (0x202020 & 0xFFFF)
    /* EF74 8001E774 B40282AF */  sw         $v0, %gp_rel(D_8009B1BC)($gp)
    /* EF78 8001E778 21802002 */  addu       $s0, $s1, $zero
    /* EF7C 8001E77C 21200000 */  addu       $a0, $zero, $zero
    /* EF80 8001E780 01000724 */  addiu      $a3, $zero, 0x1
    /* EF84 8001E784 08000624 */  addiu      $a2, $zero, 0x8
    /* EF88 8001E788 0280023C */  lui        $v0, %hi(func_8001D344)
    /* EF8C 8001E78C 44D34524 */  addiu      $a1, $v0, %lo(func_8001D344)
    /* EF90 8001E790 16000326 */  addiu      $v1, $s0, 0x16
  .L8001E794:
    /* EF94 8001E794 00006294 */  lhu        $v0, 0x0($v1)
    /* EF98 8001E798 00000000 */  nop
    /* EF9C 8001E79C 00804230 */  andi       $v0, $v0, 0x8000
    /* EFA0 8001E7A0 0F004010 */  beqz       $v0, .L8001E7E0
    /* EFA4 8001E7A4 00000000 */   nop
    /* EFA8 8001E7A8 0000128E */  lw         $s2, 0x0($s0)
    /* EFAC 8001E7AC 00000000 */  nop
    /* EFB0 8001E7B0 6C0047A2 */  sb         $a3, 0x6C($s2)
    /* EFB4 8001E7B4 600046A6 */  sh         $a2, 0x60($s2)
    /* EFB8 8001E7B8 240045AE */  sw         $a1, 0x24($s2)
    /* EFBC 8001E7BC 00006294 */  lhu        $v0, 0x0($v1)
    /* EFC0 8001E7C0 00000000 */  nop
    /* EFC4 8001E7C4 00404230 */  andi       $v0, $v0, 0x4000
    /* EFC8 8001E7C8 02004010 */  beqz       $v0, .L8001E7D4
    /* EFCC 8001E7CC 20001424 */   addiu     $s4, $zero, 0x20
    /* EFD0 8001E7D0 10001424 */  addiu      $s4, $zero, 0x10
  .L8001E7D4:
    /* EFD4 8001E7D4 2C0054A6 */  sh         $s4, 0x2C($s2)
    /* EFD8 8001E7D8 2A0054A6 */  sh         $s4, 0x2A($s2)
    /* EFDC 8001E7DC 280054A6 */  sh         $s4, 0x28($s2)
  .L8001E7E0:
    /* EFE0 8001E7E0 1C006324 */  addiu      $v1, $v1, 0x1C
    /* EFE4 8001E7E4 01008424 */  addiu      $a0, $a0, 0x1
    /* EFE8 8001E7E8 1E008228 */  slti       $v0, $a0, 0x1E
    /* EFEC 8001E7EC E9FF4014 */  bnez       $v0, .L8001E794
    /* EFF0 8001E7F0 1C001026 */   addiu     $s0, $s0, 0x1C
    /* EFF4 8001E7F4 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* EFF8 8001E7F8 4A0280A3 */  sb         $zero, %gp_rel(D_8009B152)($gp)
    /* EFFC 8001E7FC 20004234 */  ori        $v0, $v0, 0x20
    /* F000 8001E800 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* F004 8001E804 117B0008 */  j          .L8001EC44
    /* F008 8001E808 00000000 */   nop
  .L8001E80C:
    /* F00C 8001E80C 12038293 */  lbu        $v0, %gp_rel(D_8009B21A)($gp)
    /* F010 8001E810 00000000 */  nop
    /* F014 8001E814 07004010 */  beqz       $v0, .L8001E834
    /* F018 8001E818 20006230 */   andi      $v0, $v1, 0x20
    /* F01C 8001E81C D00A010C */  jal        func_80042B40
    /* F020 8001E820 01000424 */   addiu     $a0, $zero, 0x1
    /* F024 8001E824 40004010 */  beqz       $v0, .L8001E928
    /* F028 8001E828 00000000 */   nop
    /* F02C 8001E82C 117B0008 */  j          .L8001EC44
    /* F030 8001E830 00000000 */   nop
  .L8001E834:
    /* F034 8001E834 23004010 */  beqz       $v0, .L8001E8C4
    /* F038 8001E838 40006230 */   andi      $v0, $v1, 0x40
    /* F03C 8001E83C 0A80143C */  lui        $s4, %hi(D_8009B300)
    /* F040 8001E840 00B39492 */  lbu        $s4, %lo(D_8009B300)($s4)
    /* F044 8001E844 B4028693 */  lbu        $a2, %gp_rel(D_8009B1BC)($gp)
    /* F048 8001E848 00000000 */  nop
    /* F04C 8001E84C 2A108602 */  slt        $v0, $s4, $a2
    /* F050 8001E850 04004014 */  bnez       $v0, .L8001E864
    /* F054 8001E854 00000000 */   nop
    /* F058 8001E858 F8FF9426 */  addiu      $s4, $s4, -0x8
    /* F05C 8001E85C 1B7A0008 */  j          .L8001E86C
    /* F060 8001E860 2A108602 */   slt       $v0, $s4, $a2
  .L8001E864:
    /* F064 8001E864 08009426 */  addiu      $s4, $s4, 0x8
    /* F068 8001E868 2A10D400 */  slt        $v0, $a2, $s4
  .L8001E86C:
    /* F06C 8001E86C 03004010 */  beqz       $v0, .L8001E87C
    /* F070 8001E870 00141400 */   sll       $v0, $s4, 16
    /* F074 8001E874 21A0C000 */  addu       $s4, $a2, $zero
    /* F078 8001E878 00141400 */  sll        $v0, $s4, 16
  .L8001E87C:
    /* F07C 8001E87C 001A1400 */  sll        $v1, $s4, 8
    /* F080 8001E880 25104300 */  or         $v0, $v0, $v1
    /* F084 8001E884 B402838F */  lw         $v1, %gp_rel(D_8009B1BC)($gp)
    /* F088 8001E888 25105400 */  or         $v0, $v0, $s4
    /* F08C 8001E88C 0A80013C */  lui        $at, %hi(D_8009B300)
    /* F090 8001E890 00B322AC */  sw         $v0, %lo(D_8009B300)($at)
    /* F094 8001E894 EB004314 */  bne        $v0, $v1, .L8001EC44
    /* F098 8001E898 00000000 */   nop
    /* F09C 8001E89C D00A010C */  jal        func_80042B40
    /* F0A0 8001E8A0 01000424 */   addiu     $a0, $zero, 0x1
    /* F0A4 8001E8A4 E7004014 */  bnez       $v0, .L8001EC44
    /* F0A8 8001E8A8 00000000 */   nop
    /* F0AC 8001E8AC 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* F0B0 8001E8B0 00000000 */  nop
    /* F0B4 8001E8B4 DF004230 */  andi       $v0, $v0, 0xDF
    /* F0B8 8001E8B8 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* F0BC 8001E8BC 117B0008 */  j          .L8001EC44
    /* F0C0 8001E8C0 00000000 */   nop
  .L8001E8C4:
    /* F0C4 8001E8C4 27004010 */  beqz       $v0, .L8001E964
    /* F0C8 8001E8C8 10006230 */   andi      $v0, $v1, 0x10
    /* F0CC 8001E8CC 16004010 */  beqz       $v0, .L8001E928
    /* F0D0 8001E8D0 1A80033C */   lui       $v1, %hi(D_801A7AD8)
    /* F0D4 8001E8D4 C402848F */  lw         $a0, %gp_rel(D_8009B1CC)($gp)
    /* F0D8 8001E8D8 00000000 */  nop
    /* F0DC 8001E8DC 6A008590 */  lbu        $a1, 0x6A($a0)
    /* F0E0 8001E8E0 D87A6324 */  addiu      $v1, $v1, %lo(D_801A7AD8)
    /* F0E4 8001E8E4 C0100500 */  sll        $v0, $a1, 3
    /* F0E8 8001E8E8 23104500 */  subu       $v0, $v0, $a1
    /* F0EC 8001E8EC 80100200 */  sll        $v0, $v0, 2
    /* F0F0 8001E8F0 21104300 */  addu       $v0, $v0, $v1
    /* F0F4 8001E8F4 16004394 */  lhu        $v1, 0x16($v0)
    /* F0F8 8001E8F8 00000000 */  nop
    /* F0FC 8001E8FC 00806334 */  ori        $v1, $v1, 0x8000
    /* F100 8001E900 DB00010C */  jal        func_8004036C
    /* F104 8001E904 160043A4 */   sh        $v1, 0x16($v0)
    /* F108 8001E908 0400A48E */  lw         $a0, 0x4($s5)
    /* F10C 8001E90C 00000000 */  nop
    /* F110 8001E910 08008294 */  lhu        $v0, 0x8($a0)
    /* F114 8001E914 03000324 */  addiu      $v1, $zero, 0x3
    /* F118 8001E918 6C0283A3 */  sb         $v1, %gp_rel(D_8009B174)($gp)
    /* F11C 8001E91C 40004234 */  ori        $v0, $v0, 0x40
    /* F120 8001E920 117B0008 */  j          .L8001EC44
    /* F124 8001E924 080082A4 */   sh        $v0, 0x8($a0)
  .L8001E928:
    /* F128 8001E928 C402828F */  lw         $v0, %gp_rel(D_8009B1CC)($gp)
    /* F12C 8001E92C 1A80043C */  lui        $a0, %hi(D_801A7AD8)
    /* F130 8001E930 6A004390 */  lbu        $v1, 0x6A($v0)
    /* F134 8001E934 D87A8424 */  addiu      $a0, $a0, %lo(D_801A7AD8)
    /* F138 8001E938 C0100300 */  sll        $v0, $v1, 3
    /* F13C 8001E93C 23104300 */  subu       $v0, $v0, $v1
    /* F140 8001E940 80100200 */  sll        $v0, $v0, 2
    /* F144 8001E944 5592000C */  jal        func_80024954
    /* F148 8001E948 21204400 */   addu      $a0, $v0, $a0
    /* F14C 8001E94C C402838F */  lw         $v1, %gp_rel(D_8009B1CC)($gp)
    /* F150 8001E950 09000224 */  addiu      $v0, $zero, 0x9
    /* F154 8001E954 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* F158 8001E958 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* F15C 8001E95C 117B0008 */  j          .L8001EC44
    /* F160 8001E960 F09E43AC */   sw        $v1, %lo(D_800E9EF0)($v0)
  .L8001E964:
    /* F164 8001E964 6282000C */  jal        func_80020988
    /* F168 8001E968 00000000 */   nop
    /* F16C 8001E96C 21A04000 */  addu       $s4, $v0, $zero
    /* F170 8001E970 B4008012 */  beqz       $s4, .L8001EC44
    /* F174 8001E974 01001024 */   addiu     $s0, $zero, 0x1
    /* F178 8001E978 31009012 */  beq        $s4, $s0, .L8001EA40
    /* F17C 8001E97C 00000000 */   nop
    /* F180 8001E980 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* F184 8001E984 00000000 */  nop
    /* F188 8001E988 10004234 */  ori        $v0, $v0, 0x10
    /* F18C 8001E98C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* F190 8001E990 B8FF000C */  jal        func_8003FEE0
    /* F194 8001E994 08000424 */   addiu     $a0, $zero, 0x8
    /* F198 8001E998 0400053C */  lui        $a1, (0x48000 >> 16)
    /* F19C 8001E99C 0080A534 */  ori        $a1, $a1, (0x48000 & 0xFFFF)
    /* F1A0 8001E9A0 0C000224 */  addiu      $v0, $zero, 0xC
    /* F1A4 8001E9A4 1680043C */  lui        $a0, %hi(D_8015C424)
    /* F1A8 8001E9A8 C402928F */  lw         $s2, %gp_rel(D_8009B1CC)($gp)
    /* F1AC 8001E9AC 24C48424 */  addiu      $a0, $a0, %lo(D_8015C424)
    /* F1B0 8001E9B0 600042A6 */  sh         $v0, 0x60($s2)
    /* F1B4 8001E9B4 0280023C */  lui        $v0, %hi(func_8001D3C4)
    /* F1B8 8001E9B8 6A004392 */  lbu        $v1, 0x6A($s2)
    /* F1BC 8001E9BC C4D34224 */  addiu      $v0, $v0, %lo(func_8001D3C4)
    /* F1C0 8001E9C0 240042AE */  sw         $v0, 0x24($s2)
    /* F1C4 8001E9C4 C0100300 */  sll        $v0, $v1, 3
    /* F1C8 8001E9C8 23104300 */  subu       $v0, $v0, $v1
    /* F1CC 8001E9CC 80100200 */  sll        $v0, $v0, 2
    /* F1D0 8001E9D0 21104400 */  addu       $v0, $v0, $a0
    /* F1D4 8001E9D4 21104500 */  addu       $v0, $v0, $a1
    /* F1D8 8001E9D8 BC364294 */  lhu        $v0, 0x36BC($v0)
    /* F1DC 8001E9DC 00000000 */  nop
    /* F1E0 8001E9E0 280042A6 */  sh         $v0, 0x28($s2)
    /* F1E4 8001E9E4 C0100300 */  sll        $v0, $v1, 3
    /* F1E8 8001E9E8 23104300 */  subu       $v0, $v0, $v1
    /* F1EC 8001E9EC 80100200 */  sll        $v0, $v0, 2
    /* F1F0 8001E9F0 21104400 */  addu       $v0, $v0, $a0
    /* F1F4 8001E9F4 21104500 */  addu       $v0, $v0, $a1
    /* F1F8 8001E9F8 1A80033C */  lui        $v1, %hi(D_801A7AD8)
    /* F1FC 8001E9FC BE364294 */  lhu        $v0, 0x36BE($v0)
    /* F200 8001EA00 6A004492 */  lbu        $a0, 0x6A($s2)
    /* F204 8001EA04 D87A6324 */  addiu      $v1, $v1, %lo(D_801A7AD8)
    /* F208 8001EA08 2C0040A6 */  sh         $zero, 0x2C($s2)
    /* F20C 8001EA0C 2A0042A6 */  sh         $v0, 0x2A($s2)
    /* F210 8001EA10 C0100400 */  sll        $v0, $a0, 3
    /* F214 8001EA14 23104400 */  subu       $v0, $v0, $a0
    /* F218 8001EA18 80100200 */  sll        $v0, $v0, 2
    /* F21C 8001EA1C 21104300 */  addu       $v0, $v0, $v1
    /* F220 8001EA20 16004294 */  lhu        $v0, 0x16($v0)
    /* F224 8001EA24 00000000 */  nop
    /* F228 8001EA28 00104230 */  andi       $v0, $v0, 0x1000
    /* F22C 8001EA2C 02004010 */  beqz       $v0, .L8001EA38
    /* F230 8001EA30 80000224 */   addiu     $v0, $zero, 0x80
    /* F234 8001EA34 2C0042A6 */  sh         $v0, 0x2C($s2)
  .L8001EA38:
    /* F238 8001EA38 927A0008 */  j          .L8001EA48
    /* F23C 8001EA3C 6C0050A2 */   sb        $s0, 0x6C($s2)
  .L8001EA40:
    /* F240 8001EA40 B8FF000C */  jal        func_8003FEE0
    /* F244 8001EA44 07000424 */   addiu     $a0, $zero, 0x7
  .L8001EA48:
    /* F248 8001EA48 8000033C */  lui        $v1, (0x808080 >> 16)
    /* F24C 8001EA4C 80806334 */  ori        $v1, $v1, (0x808080 & 0xFFFF)
    /* F250 8001EA50 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* F254 8001EA54 D87A5024 */  addiu      $s0, $v0, %lo(D_801A7AD8)
    /* F258 8001EA58 21200000 */  addu       $a0, $zero, $zero
    /* F25C 8001EA5C 01000824 */  addiu      $t0, $zero, 0x1
    /* F260 8001EA60 08000724 */  addiu      $a3, $zero, 0x8
    /* F264 8001EA64 0280023C */  lui        $v0, %hi(func_8001D344)
    /* F268 8001EA68 44D34624 */  addiu      $a2, $v0, %lo(func_8001D344)
    /* F26C 8001EA6C 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* F270 8001EA70 16000526 */  addiu      $a1, $s0, 0x16
    /* F274 8001EA74 B40283AF */  sw         $v1, %gp_rel(D_8009B1BC)($gp)
    /* F278 8001EA78 60004234 */  ori        $v0, $v0, 0x60
    /* F27C 8001EA7C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
  .L8001EA80:
    /* F280 8001EA80 0000A294 */  lhu        $v0, 0x0($a1)
    /* F284 8001EA84 00000000 */  nop
    /* F288 8001EA88 00804230 */  andi       $v0, $v0, 0x8000
    /* F28C 8001EA8C 0F004010 */  beqz       $v0, .L8001EACC
    /* F290 8001EA90 00000000 */   nop
    /* F294 8001EA94 0000128E */  lw         $s2, 0x0($s0)
    /* F298 8001EA98 00000000 */  nop
    /* F29C 8001EA9C 6C0048A2 */  sb         $t0, 0x6C($s2)
    /* F2A0 8001EAA0 600047A6 */  sh         $a3, 0x60($s2)
    /* F2A4 8001EAA4 240046AE */  sw         $a2, 0x24($s2)
    /* F2A8 8001EAA8 0000A294 */  lhu        $v0, 0x0($a1)
    /* F2AC 8001EAAC 00000000 */  nop
    /* F2B0 8001EAB0 00404230 */  andi       $v0, $v0, 0x4000
    /* F2B4 8001EAB4 02004010 */  beqz       $v0, .L8001EAC0
    /* F2B8 8001EAB8 80001424 */   addiu     $s4, $zero, 0x80
    /* F2BC 8001EABC 40001424 */  addiu      $s4, $zero, 0x40
  .L8001EAC0:
    /* F2C0 8001EAC0 2C0054A6 */  sh         $s4, 0x2C($s2)
    /* F2C4 8001EAC4 2A0054A6 */  sh         $s4, 0x2A($s2)
    /* F2C8 8001EAC8 280054A6 */  sh         $s4, 0x28($s2)
  .L8001EACC:
    /* F2CC 8001EACC 1C00A524 */  addiu      $a1, $a1, 0x1C
    /* F2D0 8001EAD0 01008424 */  addiu      $a0, $a0, 0x1
    /* F2D4 8001EAD4 1E008228 */  slti       $v0, $a0, 0x1E
    /* F2D8 8001EAD8 E9FF4014 */  bnez       $v0, .L8001EA80
    /* F2DC 8001EADC 1C001026 */   addiu     $s0, $s0, 0x1C
    /* F2E0 8001EAE0 117B0008 */  j          .L8001EC44
    /* F2E4 8001EAE4 00000000 */   nop
  jlabel .L8001EAE8
    /* F2E8 8001EAE8 6C028593 */  lbu        $a1, %gp_rel(D_8009B174)($gp)
    /* F2EC 8001EAEC 00000000 */  nop
    /* F2F0 8001EAF0 8000A230 */  andi       $v0, $a1, 0x80
    /* F2F4 8001EAF4 13004014 */  bnez       $v0, .L8001EB44
    /* F2F8 8001EAF8 00000000 */   nop
    /* F2FC 8001EAFC CD028293 */  lbu        $v0, %gp_rel(D_8009B1D5)($gp)
    /* F300 8001EB00 00000000 */  nop
    /* F304 8001EB04 C0180200 */  sll        $v1, $v0, 3
    /* F308 8001EB08 23186200 */  subu       $v1, $v1, $v0
    /* F30C 8001EB0C 00190300 */  sll        $v1, $v1, 4
    /* F310 8001EB10 0F80023C */  lui        $v0, %hi(D_800E9F64)
    /* F314 8001EB14 649F4224 */  addiu      $v0, $v0, %lo(D_800E9F64)
    /* F318 8001EB18 21186200 */  addu       $v1, $v1, $v0
    /* F31C 8001EB1C 0400648C */  lw         $a0, 0x4($v1)
    /* F320 8001EB20 8000A234 */  ori        $v0, $a1, 0x80
    /* F324 8001EB24 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* F328 8001EB28 AC0283AF */  sw         $v1, %gp_rel(D_8009B1B4)($gp)
    /* F32C 8001EB2C DB00010C */  jal        func_8004036C
    /* F330 8001EB30 00000000 */   nop
    /* F334 8001EB34 AC02838F */  lw         $v1, %gp_rel(D_8009B1B4)($gp)
    /* F338 8001EB38 08000224 */  addiu      $v0, $zero, 0x8
    /* F33C 8001EB3C 5A0282A7 */  sh         $v0, %gp_rel(D_8009B162)($gp)
    /* F340 8001EB40 040060AC */  sw         $zero, 0x4($v1)
  .L8001EB44:
    /* F344 8001EB44 5A028297 */  lhu        $v0, %gp_rel(D_8009B162)($gp)
    /* F348 8001EB48 00000000 */  nop
    /* F34C 8001EB4C 3D004014 */  bnez       $v0, .L8001EC44
    /* F350 8001EB50 00000000 */   nop
    /* F354 8001EB54 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* F358 8001EB58 00000000 */  nop
    /* F35C 8001EB5C 40006230 */  andi       $v0, $v1, 0x40
    /* F360 8001EB60 37004014 */  bnez       $v0, .L8001EC40
    /* F364 8001EB64 07000224 */   addiu     $v0, $zero, 0x7
    /* F368 8001EB68 40006234 */  ori        $v0, $v1, 0x40
    /* F36C 8001EB6C CD028393 */  lbu        $v1, %gp_rel(D_8009B1D5)($gp)
    /* F370 8001EB70 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* F374 8001EB74 0C000224 */  addiu      $v0, $zero, 0xC
    /* F378 8001EB78 5A0282A7 */  sh         $v0, %gp_rel(D_8009B162)($gp)
    /* F37C 8001EB7C C0100300 */  sll        $v0, $v1, 3
    /* F380 8001EB80 23104300 */  subu       $v0, $v0, $v1
    /* F384 8001EB84 00110200 */  sll        $v0, $v0, 4
    /* F388 8001EB88 0F80033C */  lui        $v1, (0x800F0000 >> 16)
  .L8001EB8C:
    /* F38C 8001EB8C 0F80033C */  lui        $v1, %hi(D_800E9F48)
    /* F390 8001EB90 489F6324 */  addiu      $v1, $v1, %lo(D_800E9F48)
    /* F394 8001EB94 21104300 */  addu       $v0, $v0, $v1
    /* F398 8001EB98 AC0282AF */  sw         $v0, %gp_rel(D_8009B1B4)($gp)
    /* F39C 8001EB9C 117B0008 */  j          .L8001EC44
    /* F3A0 8001EBA0 00000000 */   nop
  jlabel .L8001EBA4
    /* F3A4 8001EBA4 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* F3A8 8001EBA8 00000000 */  nop
    /* F3AC 8001EBAC 80006230 */  andi       $v0, $v1, 0x80
    /* F3B0 8001EBB0 04004014 */  bnez       $v0, .L8001EBC4
    /* F3B4 8001EBB4 80006234 */   ori       $v0, $v1, 0x80
    /* F3B8 8001EBB8 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* F3BC 8001EBBC 0C000224 */  addiu      $v0, $zero, 0xC
    /* F3C0 8001EBC0 5A0282A7 */  sh         $v0, %gp_rel(D_8009B162)($gp)
  .L8001EBC4:
    /* F3C4 8001EBC4 5A028297 */  lhu        $v0, %gp_rel(D_8009B162)($gp)
    /* F3C8 8001EBC8 00000000 */  nop
    /* F3CC 8001EBCC 1D004014 */  bnez       $v0, .L8001EC44
    /* F3D0 8001EBD0 06000224 */   addiu     $v0, $zero, 0x6
    /* F3D4 8001EBD4 107B0008 */  j          .L8001EC40
    /* F3D8 8001EBD8 00000000 */   nop
  jlabel .L8001EBDC
    /* F3DC 8001EBDC 64028297 */  lhu        $v0, %gp_rel(D_8009B16C)($gp)
    /* F3E0 8001EBE0 F002848F */  lw         $a0, %gp_rel(D_8009B1F8)($gp)
    /* F3E4 8001EBE4 FFEF4230 */  andi       $v0, $v0, 0xEFFF
    /* F3E8 8001EBE8 640282A7 */  sh         $v0, %gp_rel(D_8009B16C)($gp)
    /* F3EC 8001EBEC DB00010C */  jal        func_8004036C
    /* F3F0 8001EBF0 00000000 */   nop
    /* F3F4 8001EBF4 0A000224 */  addiu      $v0, $zero, 0xA
    /* F3F8 8001EBF8 F00280AF */  sw         $zero, %gp_rel(D_8009B1F8)($gp)
    /* F3FC 8001EBFC 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* F400 8001EC00 B8FF000C */  jal        func_8003FEE0
    /* F404 8001EC04 30000424 */   addiu     $a0, $zero, 0x30
    /* F408 8001EC08 117B0008 */  j          .L8001EC44
    /* F40C 8001EC0C 00000000 */   nop
  jlabel .L8001EC10
    /* F410 8001EC10 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* F414 8001EC14 00000000 */  nop
    /* F418 8001EC18 80006230 */  andi       $v0, $v1, 0x80
    /* F41C 8001EC1C 04004014 */  bnez       $v0, .L8001EC30
    /* F420 8001EC20 80006234 */   ori       $v0, $v1, 0x80
    /* F424 8001EC24 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* F428 8001EC28 0C000224 */  addiu      $v0, $zero, 0xC
    /* F42C 8001EC2C 5A0282A7 */  sh         $v0, %gp_rel(D_8009B162)($gp)
  .L8001EC30:
    /* F430 8001EC30 5A028297 */  lhu        $v0, %gp_rel(D_8009B162)($gp)
    /* F434 8001EC34 00000000 */  nop
    /* F438 8001EC38 02004014 */  bnez       $v0, .L8001EC44
    /* F43C 8001EC3C 0A000224 */   addiu     $v0, $zero, 0xA
  .L8001EC40:
    /* F440 8001EC40 320382A7 */  sh         $v0, %gp_rel(D_8009B23A)($gp)
  .L8001EC44:
    /* F444 8001EC44 3800BF8F */  lw         $ra, 0x38($sp)
    /* F448 8001EC48 3400B78F */  lw         $s7, 0x34($sp)
    /* F44C 8001EC4C 3000B68F */  lw         $s6, 0x30($sp)
    /* F450 8001EC50 2C00B58F */  lw         $s5, 0x2C($sp)
    /* F454 8001EC54 2800B48F */  lw         $s4, 0x28($sp)
    /* F458 8001EC58 2400B38F */  lw         $s3, 0x24($sp)
    /* F45C 8001EC5C 2000B28F */  lw         $s2, 0x20($sp)
    /* F460 8001EC60 1C00B18F */  lw         $s1, 0x1C($sp)
    /* F464 8001EC64 1800B08F */  lw         $s0, 0x18($sp)
    /* F468 8001EC68 0800E003 */  jr         $ra
    /* F46C 8001EC6C 4000BD27 */   addiu     $sp, $sp, 0x40
endlabel func_8001D670
