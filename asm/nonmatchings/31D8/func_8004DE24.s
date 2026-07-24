nonmatching func_8004DE24, 0x98C

glabel func_8004DE24
    /* 3E624 8004DE24 A8FEBD27 */  addiu      $sp, $sp, -0x158
    /* 3E628 8004DE28 0180023C */  lui        $v0, %hi(D_800114C4)
    /* 3E62C 8004DE2C 5001BFAF */  sw         $ra, 0x150($sp)
    /* 3E630 8004DE30 4C01B5AF */  sw         $s5, 0x14C($sp)
    /* 3E634 8004DE34 4801B4AF */  sw         $s4, 0x148($sp)
    /* 3E638 8004DE38 4401B3AF */  sw         $s3, 0x144($sp)
    /* 3E63C 8004DE3C 4001B2AF */  sw         $s2, 0x140($sp)
    /* 3E640 8004DE40 3C01B1AF */  sw         $s1, 0x13C($sp)
    /* 3E644 8004DE44 3801B0AF */  sw         $s0, 0x138($sp)
    /* 3E648 8004DE48 C4144E24 */  addiu      $t6, $v0, %lo(D_800114C4)
    /* 3E64C 8004DE4C 0300CB89 */  lwl        $t3, 0x3($t6)
    /* 3E650 8004DE50 0000CB99 */  lwr        $t3, 0x0($t6)
    /* 3E654 8004DE54 0700CC89 */  lwl        $t4, 0x7($t6)
    /* 3E658 8004DE58 0400CC99 */  lwr        $t4, 0x4($t6)
    /* 3E65C 8004DE5C 0B00CD89 */  lwl        $t5, 0xB($t6)
    /* 3E660 8004DE60 0800CD99 */  lwr        $t5, 0x8($t6)
    /* 3E664 8004DE64 2B00ABAB */  swl        $t3, 0x2B($sp)
    /* 3E668 8004DE68 2800ABBB */  swr        $t3, 0x28($sp)
    /* 3E66C 8004DE6C 2F00ACAB */  swl        $t4, 0x2F($sp)
    /* 3E670 8004DE70 2C00ACBB */  swr        $t4, 0x2C($sp)
    /* 3E674 8004DE74 3300ADAB */  swl        $t5, 0x33($sp)
    /* 3E678 8004DE78 3000ADBB */  swr        $t5, 0x30($sp)
    /* 3E67C 8004DE7C 0F00CB89 */  lwl        $t3, 0xF($t6)
    /* 3E680 8004DE80 0C00CB99 */  lwr        $t3, 0xC($t6)
    /* 3E684 8004DE84 1300CC89 */  lwl        $t4, 0x13($t6)
    /* 3E688 8004DE88 1000CC99 */  lwr        $t4, 0x10($t6)
    /* 3E68C 8004DE8C 3700ABAB */  swl        $t3, 0x37($sp)
    /* 3E690 8004DE90 3400ABBB */  swr        $t3, 0x34($sp)
    /* 3E694 8004DE94 3B00ACAB */  swl        $t4, 0x3B($sp)
    /* 3E698 8004DE98 3800ACBB */  swr        $t4, 0x38($sp)
    /* 3E69C 8004DE9C 0180023C */  lui        $v0, %hi(D_800114D8)
    /* 3E6A0 8004DEA0 D8144E24 */  addiu      $t6, $v0, %lo(D_800114D8)
    /* 3E6A4 8004DEA4 0300CB89 */  lwl        $t3, 0x3($t6)
    /* 3E6A8 8004DEA8 0000CB99 */  lwr        $t3, 0x0($t6)
    /* 3E6AC 8004DEAC 0700CC89 */  lwl        $t4, 0x7($t6)
    /* 3E6B0 8004DEB0 0400CC99 */  lwr        $t4, 0x4($t6)
    /* 3E6B4 8004DEB4 0B00CD89 */  lwl        $t5, 0xB($t6)
    /* 3E6B8 8004DEB8 0800CD99 */  lwr        $t5, 0x8($t6)
    /* 3E6BC 8004DEBC 4300ABAB */  swl        $t3, 0x43($sp)
    /* 3E6C0 8004DEC0 4000ABBB */  swr        $t3, 0x40($sp)
    /* 3E6C4 8004DEC4 4700ACAB */  swl        $t4, 0x47($sp)
    /* 3E6C8 8004DEC8 4400ACBB */  swr        $t4, 0x44($sp)
    /* 3E6CC 8004DECC 4B00ADAB */  swl        $t5, 0x4B($sp)
    /* 3E6D0 8004DED0 4800ADBB */  swr        $t5, 0x48($sp)
    /* 3E6D4 8004DED4 0F00CB89 */  lwl        $t3, 0xF($t6)
    /* 3E6D8 8004DED8 0C00CB99 */  lwr        $t3, 0xC($t6)
    /* 3E6DC 8004DEDC 00000000 */  nop
    /* 3E6E0 8004DEE0 4F00ABAB */  swl        $t3, 0x4F($sp)
    /* 3E6E4 8004DEE4 4C00ABBB */  swr        $t3, 0x4C($sp)
    /* 3E6E8 8004DEE8 0F80023C */  lui        $v0, %hi(D_800F4880)
    /* 3E6EC 8004DEEC 80485024 */  addiu      $s0, $v0, %lo(D_800F4880)
    /* 3E6F0 8004DEF0 02000324 */  addiu      $v1, $zero, 0x2
    /* 3E6F4 8004DEF4 8000868F */  lw         $a2, %gp_rel(D_8009AF88)($gp)
    /* 3E6F8 8004DEF8 180D048E */  lw         $a0, 0xD18($s0)
    /* 3E6FC 8004DEFC AA00C594 */  lhu        $a1, 0xAA($a2)
    /* 3E700 8004DF00 A800C294 */  lhu        $v0, 0xA8($a2)
    /* 3E704 8004DF04 AC00D390 */  lbu        $s3, 0xAC($a2)
    /* 3E708 8004DF08 42130200 */  srl        $v0, $v0, 13
    /* 3E70C 8004DF0C 03004230 */  andi       $v0, $v0, 0x3
    /* 3E710 8004DF10 23186200 */  subu       $v1, $v1, $v0
    /* 3E714 8004DF14 1C00828C */  lw         $v0, 0x1C($a0)
    /* 3E718 8004DF18 3F00A530 */  andi       $a1, $a1, 0x3F
    /* 3E71C 8004DF1C 2C015224 */  addiu      $s2, $v0, 0x12C
    /* 3E720 8004DF20 1F0E0292 */  lbu        $v0, 0xE1F($s0)
    /* 3E724 8004DF24 00000000 */  nop
    /* 3E728 8004DF28 18024010 */  beqz       $v0, .L8004E78C
    /* 3E72C 8004DF2C 04886500 */   sllv      $s1, $a1, $v1
    /* 3E730 8004DF30 A00D048E */  lw         $a0, 0xDA0($s0)
    /* 3E734 8004DF34 00F00224 */  addiu      $v0, $zero, -0x1000
    /* 3E738 8004DF38 09008214 */  bne        $a0, $v0, .L8004DF60
    /* 3E73C 8004DF3C 00000000 */   nop
    /* 3E740 8004DF40 A40D038E */  lw         $v1, 0xDA4($s0)
    /* 3E744 8004DF44 00000000 */  nop
    /* 3E748 8004DF48 05006414 */  bne        $v1, $a0, .L8004DF60
    /* 3E74C 8004DF4C 00000000 */   nop
    /* 3E750 8004DF50 A80D028E */  lw         $v0, 0xDA8($s0)
    /* 3E754 8004DF54 00000000 */  nop
    /* 3E758 8004DF58 0C024310 */  beq        $v0, $v1, .L8004E78C
    /* 3E75C 8004DF5C 00000000 */   nop
  .L8004DF60:
    /* 3E760 8004DF60 EC39010C */  jal        func_8004E7B0
    /* 3E764 8004DF64 21200000 */   addu      $a0, $zero, $zero
    /* 3E768 8004DF68 8000828F */  lw         $v0, %gp_rel(D_8009AF88)($gp)
    /* 3E76C 8004DF6C 9000A0AF */  sw         $zero, 0x90($sp)
    /* 3E770 8004DF70 A8004294 */  lhu        $v0, 0xA8($v0)
    /* 3E774 8004DF74 00000000 */  nop
    /* 3E778 8004DF78 00E04230 */  andi       $v0, $v0, 0xE000
    /* 3E77C 8004DF7C 02004010 */  beqz       $v0, .L8004DF88
    /* 3E780 8004DF80 0001023C */   lui       $v0, (0x1000000 >> 16)
    /* 3E784 8004DF84 9000A2AF */  sw         $v0, 0x90($sp)
  .L8004DF88:
    /* 3E788 8004DF88 21200000 */  addu       $a0, $zero, $zero
    /* 3E78C 8004DF8C F815020C */  jal        func_800857E0
    /* 3E790 8004DF90 700D0526 */   addiu     $a1, $s0, 0xD70
    /* 3E794 8004DF94 01000424 */  addiu      $a0, $zero, 0x1
    /* 3E798 8004DF98 F815020C */  jal        func_800857E0
    /* 3E79C 8004DF9C 800D0526 */   addiu     $a1, $s0, 0xD80
    /* 3E7A0 8004DFA0 02000424 */  addiu      $a0, $zero, 0x2
    /* 3E7A4 8004DFA4 F815020C */  jal        func_800857E0
    /* 3E7A8 8004DFA8 900D0526 */   addiu     $a1, $s0, 0xD90
    /* 3E7AC 8004DFAC A00D048E */  lw         $a0, 0xDA0($s0)
    /* 3E7B0 8004DFB0 A40D058E */  lw         $a1, 0xDA4($s0)
    /* 3E7B4 8004DFB4 A80D068E */  lw         $a2, 0xDA8($s0)
    /* 3E7B8 8004DFB8 5417020C */  jal        func_80085D50
    /* 3E7BC 8004DFBC 00000000 */   nop
    /* 3E7C0 8004DFC0 0F80043C */  lui        $a0, %hi(D_800F56A4)
    /* 3E7C4 8004DFC4 8015020C */  jal        func_80085600
    /* 3E7C8 8004DFC8 A4568424 */   addiu     $a0, $a0, %lo(D_800F56A4)
    /* 3E7CC 8004DFCC 4000A427 */  addiu      $a0, $sp, 0x40
    /* 3E7D0 8004DFD0 2800A527 */  addiu      $a1, $sp, 0x28
    /* 3E7D4 8004DFD4 0827020C */  jal        func_80089C20
    /* 3E7D8 8004DFD8 A400A627 */   addiu     $a2, $sp, 0xA4
    /* 3E7DC 8004DFDC 8000868F */  lw         $a2, %gp_rel(D_8009AF88)($gp)
    /* 3E7E0 8004DFE0 00000000 */  nop
    /* 3E7E4 8004DFE4 A800C494 */  lhu        $a0, 0xA8($a2)
    /* 3E7E8 8004DFE8 AC00C594 */  lhu        $a1, 0xAC($a2)
    /* 3E7EC 8004DFEC AA00C294 */  lhu        $v0, 0xAA($a2)
    /* 3E7F0 8004DFF0 82210400 */  srl        $a0, $a0, 6
    /* 3E7F4 8004DFF4 80018430 */  andi       $a0, $a0, 0x180
    /* 3E7F8 8004DFF8 0001A330 */  andi       $v1, $a1, 0x100
    /* 3E7FC 8004DFFC 02190300 */  srl        $v1, $v1, 4
    /* 3E800 8004E000 25208300 */  or         $a0, $a0, $v1
    /* 3E804 8004E004 FF034230 */  andi       $v0, $v0, 0x3FF
    /* 3E808 8004E008 82110200 */  srl        $v0, $v0, 6
    /* 3E80C 8004E00C 25208200 */  or         $a0, $a0, $v0
    /* 3E810 8004E010 0002A530 */  andi       $a1, $a1, 0x200
    /* 3E814 8004E014 80280500 */  sll        $a1, $a1, 2
    /* 3E818 8004E018 25208500 */  or         $a0, $a0, $a1
    /* 3E81C 8004E01C 9C00A4A7 */  sh         $a0, 0x9C($sp)
    /* 3E820 8004E020 AE00C294 */  lhu        $v0, 0xAE($a2)
    /* 3E824 8004E024 88008397 */  lhu        $v1, %gp_rel(D_8009AF90)($gp)
    /* 3E828 8004E028 A000A2A7 */  sh         $v0, 0xA0($sp)
    /* 3E82C 8004E02C B000C494 */  lhu        $a0, 0xB0($a2)
    /* 3E830 8004E030 40000224 */  addiu      $v0, $zero, 0x40
    /* 3E834 8004E034 9800A2A7 */  sh         $v0, 0x98($sp)
    /* 3E838 8004E038 00010224 */  addiu      $v0, $zero, 0x100
    /* 3E83C 8004E03C D0FF6524 */  addiu      $a1, $v1, -0x30
    /* 3E840 8004E040 001C0300 */  sll        $v1, $v1, 16
    /* 3E844 8004E044 9E00B1A3 */  sb         $s1, 0x9E($sp)
    /* 3E848 8004E048 9F00B3A3 */  sb         $s3, 0x9F($sp)
    /* 3E84C 8004E04C 9A00A2A7 */  sh         $v0, 0x9A($sp)
    /* 3E850 8004E050 9600A5A7 */  sh         $a1, 0x96($sp)
    /* 3E854 8004E054 A200A4A7 */  sh         $a0, 0xA2($sp)
    /* 3E858 8004E058 A800C294 */  lhu        $v0, 0xA8($a2)
    /* 3E85C 8004E05C 033C0300 */  sra        $a3, $v1, 16
    /* 3E860 8004E060 FF1F4230 */  andi       $v0, $v0, 0x1FFF
    /* 3E864 8004E064 23200200 */  negu       $a0, $v0
    /* 3E868 8004E068 2A10E400 */  slt        $v0, $a3, $a0
    /* 3E86C 8004E06C 99004014 */  bnez       $v0, .L8004E2D4
    /* 3E870 8004E070 00140500 */   sll       $v0, $a1, 16
    /* 3E874 8004E074 031C0200 */  sra        $v1, $v0, 16
    /* 3E878 8004E078 2A106400 */  slt        $v0, $v1, $a0
    /* 3E87C 8004E07C 95004014 */  bnez       $v0, .L8004E2D4
    /* 3E880 8004E080 00000000 */   nop
    /* 3E884 8004E084 02006018 */  blez       $v1, .L8004E090
    /* 3E888 8004E088 00000000 */   nop
    /* 3E88C 8004E08C 9600A0A7 */  sh         $zero, 0x96($sp)
  .L8004E090:
    /* 3E890 8004E090 9600A287 */  lh         $v0, 0x96($sp)
    /* 3E894 8004E094 00000000 */  nop
    /* 3E898 8004E098 07004104 */  bgez       $v0, .L8004E0B8
    /* 3E89C 8004E09C 00000000 */   nop
    /* 3E8A0 8004E0A0 02004104 */  bgez       $v0, .L8004E0AC
    /* 3E8A4 8004E0A4 00000000 */   nop
    /* 3E8A8 8004E0A8 23100200 */  negu       $v0, $v0
  .L8004E0AC:
    /* 3E8AC 8004E0AC 9F00A2A3 */  sb         $v0, 0x9F($sp)
    /* 3E8B0 8004E0B0 9600A0A7 */  sh         $zero, 0x96($sp)
    /* 3E8B4 8004E0B4 9600A287 */  lh         $v0, 0x96($sp)
  .L8004E0B8:
    /* 3E8B8 8004E0B8 A800C394 */  lhu        $v1, 0xA8($a2)
    /* 3E8BC 8004E0BC 00014424 */  addiu      $a0, $v0, 0x100
    /* 3E8C0 8004E0C0 FF1F6330 */  andi       $v1, $v1, 0x1FFF
    /* 3E8C4 8004E0C4 21186700 */  addu       $v1, $v1, $a3
    /* 3E8C8 8004E0C8 F1006228 */  slti       $v0, $v1, 0xF1
    /* 3E8CC 8004E0CC 05004010 */  beqz       $v0, .L8004E0E4
    /* 3E8D0 8004E0D0 2A106400 */   slt       $v0, $v1, $a0
    /* 3E8D4 8004E0D4 15004010 */  beqz       $v0, .L8004E12C
    /* 3E8D8 8004E0D8 00000000 */   nop
    /* 3E8DC 8004E0DC 3C380108 */  j          .L8004E0F0
    /* 3E8E0 8004E0E0 00000000 */   nop
  .L8004E0E4:
    /* 3E8E4 8004E0E4 F1008228 */  slti       $v0, $a0, 0xF1
    /* 3E8E8 8004E0E8 10004014 */  bnez       $v0, .L8004E12C
    /* 3E8EC 8004E0EC 00000000 */   nop
  .L8004E0F0:
    /* 3E8F0 8004E0F0 9A00A597 */  lhu        $a1, 0x9A($sp)
    /* 3E8F4 8004E0F4 9600A387 */  lh         $v1, 0x96($sp)
    /* 3E8F8 8004E0F8 8000828F */  lw         $v0, %gp_rel(D_8009AF88)($gp)
    /* 3E8FC 8004E0FC 88008487 */  lh         $a0, %gp_rel(D_8009AF90)($gp)
    /* 3E900 8004E100 A8004294 */  lhu        $v0, 0xA8($v0)
    /* 3E904 8004E104 21186500 */  addu       $v1, $v1, $a1
    /* 3E908 8004E108 FF1F4230 */  andi       $v0, $v0, 0x1FFF
    /* 3E90C 8004E10C 21104400 */  addu       $v0, $v0, $a0
    /* 3E910 8004E110 23186200 */  subu       $v1, $v1, $v0
    /* 3E914 8004E114 2A106500 */  slt        $v0, $v1, $a1
    /* 3E918 8004E118 02004010 */  beqz       $v0, .L8004E124
    /* 3E91C 8004E11C 2130A000 */   addu      $a2, $a1, $zero
    /* 3E920 8004E120 21306000 */  addu       $a2, $v1, $zero
  .L8004E124:
    /* 3E924 8004E124 2310A600 */  subu       $v0, $a1, $a2
    /* 3E928 8004E128 9A00A2A7 */  sh         $v0, 0x9A($sp)
  .L8004E12C:
    /* 3E92C 8004E12C 9F00A493 */  lbu        $a0, 0x9F($sp)
    /* 3E930 8004E130 8000828F */  lw         $v0, %gp_rel(D_8009AF88)($gp)
    /* 3E934 8004E134 9A00A397 */  lhu        $v1, 0x9A($sp)
    /* 3E938 8004E138 A8004294 */  lhu        $v0, 0xA8($v0)
    /* 3E93C 8004E13C 21208300 */  addu       $a0, $a0, $v1
    /* 3E940 8004E140 FF1F4330 */  andi       $v1, $v0, 0x1FFF
    /* 3E944 8004E144 F100622C */  sltiu      $v0, $v1, 0xF1
    /* 3E948 8004E148 05004010 */  beqz       $v0, .L8004E160
    /* 3E94C 8004E14C 2A106400 */   slt       $v0, $v1, $a0
    /* 3E950 8004E150 06004014 */  bnez       $v0, .L8004E16C
    /* 3E954 8004E154 6666043C */   lui       $a0, (0x66666667 >> 16)
    /* 3E958 8004E158 69380108 */  j          .L8004E1A4
    /* 3E95C 8004E15C 00000000 */   nop
  .L8004E160:
    /* 3E960 8004E160 F1008228 */  slti       $v0, $a0, 0xF1
    /* 3E964 8004E164 0F004014 */  bnez       $v0, .L8004E1A4
    /* 3E968 8004E168 6666043C */   lui       $a0, (0x66666667 >> 16)
  .L8004E16C:
    /* 3E96C 8004E16C 9A00A497 */  lhu        $a0, 0x9A($sp)
    /* 3E970 8004E170 8000828F */  lw         $v0, %gp_rel(D_8009AF88)($gp)
    /* 3E974 8004E174 9F00A393 */  lbu        $v1, 0x9F($sp)
    /* 3E978 8004E178 A8004294 */  lhu        $v0, 0xA8($v0)
    /* 3E97C 8004E17C 21186400 */  addu       $v1, $v1, $a0
    /* 3E980 8004E180 FF1F4230 */  andi       $v0, $v0, 0x1FFF
    /* 3E984 8004E184 23186200 */  subu       $v1, $v1, $v0
    /* 3E988 8004E188 2A106400 */  slt        $v0, $v1, $a0
    /* 3E98C 8004E18C 02004010 */  beqz       $v0, .L8004E198
    /* 3E990 8004E190 21288000 */   addu      $a1, $a0, $zero
    /* 3E994 8004E194 21286000 */  addu       $a1, $v1, $zero
  .L8004E198:
    /* 3E998 8004E198 23108500 */  subu       $v0, $a0, $a1
    /* 3E99C 8004E19C 9A00A2A7 */  sh         $v0, 0x9A($sp)
    /* 3E9A0 8004E1A0 6666043C */  lui        $a0, (0x66666667 >> 16)
  .L8004E1A4:
    /* 3E9A4 8004E1A4 86008397 */  lhu        $v1, %gp_rel(D_8009AF8E)($gp)
    /* 3E9A8 8004E1A8 67668434 */  ori        $a0, $a0, (0x66666667 & 0xFFFF)
    /* 3E9AC 8004E1AC 001C0300 */  sll        $v1, $v1, 16
    /* 3E9B0 8004E1B0 03140300 */  sra        $v0, $v1, 16
    /* 3E9B4 8004E1B4 18004400 */  mult       $v0, $a0
    /* 3E9B8 8004E1B8 8000828F */  lw         $v0, %gp_rel(D_8009AF88)($gp)
    /* 3E9BC 8004E1BC 10280000 */  mfhi       $a1
    /* 3E9C0 8004E1C0 A6004494 */  lhu        $a0, 0xA6($v0)
    /* 3E9C4 8004E1C4 CCCC023C */  lui        $v0, (0xCCCCCCCD >> 16)
    /* 3E9C8 8004E1C8 CDCC4234 */  ori        $v0, $v0, (0xCCCCCCCD & 0xFFFF)
    /* 3E9CC 8004E1CC 19008200 */  multu      $a0, $v0
    /* 3E9D0 8004E1D0 C31F0300 */  sra        $v1, $v1, 31
    /* 3E9D4 8004E1D4 83200500 */  sra        $a0, $a1, 2
    /* 3E9D8 8004E1D8 23208300 */  subu       $a0, $a0, $v1
    /* 3E9DC 8004E1DC 10400000 */  mfhi       $t0
    /* 3E9E0 8004E1E0 821A0800 */  srl        $v1, $t0, 10
    /* 3E9E4 8004E1E4 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 3E9E8 8004E1E8 80100300 */  sll        $v0, $v1, 2
    /* 3E9EC 8004E1EC 21104300 */  addu       $v0, $v0, $v1
    /* 3E9F0 8004E1F0 40110200 */  sll        $v0, $v0, 5
    /* 3E9F4 8004E1F4 23208200 */  subu       $a0, $a0, $v0
    /* 3E9F8 8004E1F8 9400A4A7 */  sh         $a0, 0x94($sp)
    /* 3E9FC 8004E1FC 00240400 */  sll        $a0, $a0, 16
    /* 3EA00 8004E200 03240400 */  sra        $a0, $a0, 16
    /* 3EA04 8004E204 40018428 */  slti       $a0, $a0, 0x140
    /* 3EA08 8004E208 32008010 */  beqz       $a0, .L8004E2D4
    /* 3EA0C 8004E20C 0F80023C */   lui       $v0, %hi(D_800E9D90)
    /* 3EA10 8004E210 909D5024 */  addiu      $s0, $v0, %lo(D_800E9D90)
  .L8004E214:
    /* 3EA14 8004E214 9400A287 */  lh         $v0, 0x94($sp)
    /* 3EA18 8004E218 9800A397 */  lhu        $v1, 0x98($sp)
    /* 3EA1C 8004E21C 00000000 */  nop
    /* 3EA20 8004E220 21104300 */  addu       $v0, $v0, $v1
    /* 3EA24 8004E224 09004018 */  blez       $v0, .L8004E24C
    /* 3EA28 8004E228 9000A427 */   addiu     $a0, $sp, 0x90
    /* 3EA2C 8004E22C 0C00058E */  lw         $a1, 0xC($s0)
    /* 3EA30 8004E230 00000000 */  nop
    /* 3EA34 8004E234 0000A28C */  lw         $v0, 0x0($a1)
    /* 3EA38 8004E238 01000624 */  addiu      $a2, $zero, 0x1
    /* 3EA3C 8004E23C 04304600 */  sllv       $a2, $a2, $v0
    /* 3EA40 8004E240 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 3EA44 8004E244 7C12020C */  jal        func_800849F0
    /* 3EA48 8004E248 FFFFC630 */   andi      $a2, $a2, 0xFFFF
  .L8004E24C:
    /* 3EA4C 8004E24C 8000828F */  lw         $v0, %gp_rel(D_8009AF88)($gp)
    /* 3EA50 8004E250 00000000 */  nop
    /* 3EA54 8004E254 A6004394 */  lhu        $v1, 0xA6($v0)
    /* 3EA58 8004E258 CCCC023C */  lui        $v0, (0xCCCCCCCD >> 16)
    /* 3EA5C 8004E25C CDCC4234 */  ori        $v0, $v0, (0xCCCCCCCD & 0xFFFF)
    /* 3EA60 8004E260 19006200 */  multu      $v1, $v0
    /* 3EA64 8004E264 9800A597 */  lhu        $a1, 0x98($sp)
    /* 3EA68 8004E268 9E00A393 */  lbu        $v1, 0x9E($sp)
    /* 3EA6C 8004E26C 00000000 */  nop
    /* 3EA70 8004E270 21186500 */  addu       $v1, $v1, $a1
    /* 3EA74 8004E274 10400000 */  mfhi       $t0
    /* 3EA78 8004E278 C2100800 */  srl        $v0, $t0, 3
    /* 3EA7C 8004E27C FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 3EA80 8004E280 1A006200 */  div        $zero, $v1, $v0
    /* 3EA84 8004E284 02004014 */  bnez       $v0, .L8004E290
    /* 3EA88 8004E288 00000000 */   nop
    /* 3EA8C 8004E28C 0D000700 */  break      7
  .L8004E290:
    /* 3EA90 8004E290 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 3EA94 8004E294 04004114 */  bne        $v0, $at, .L8004E2A8
    /* 3EA98 8004E298 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 3EA9C 8004E29C 02006114 */  bne        $v1, $at, .L8004E2A8
    /* 3EAA0 8004E2A0 00000000 */   nop
    /* 3EAA4 8004E2A4 0D000600 */  break      6
  .L8004E2A8:
    /* 3EAA8 8004E2A8 10200000 */  mfhi       $a0
    /* 3EAAC 8004E2AC 9400A297 */  lhu        $v0, 0x94($sp)
    /* 3EAB0 8004E2B0 00000000 */  nop
    /* 3EAB4 8004E2B4 21104500 */  addu       $v0, $v0, $a1
    /* 3EAB8 8004E2B8 9400A2A7 */  sh         $v0, 0x94($sp)
    /* 3EABC 8004E2BC 00140200 */  sll        $v0, $v0, 16
    /* 3EAC0 8004E2C0 03140200 */  sra        $v0, $v0, 16
    /* 3EAC4 8004E2C4 40014228 */  slti       $v0, $v0, 0x140
    /* 3EAC8 8004E2C8 21209100 */  addu       $a0, $a0, $s1
    /* 3EACC 8004E2CC D1FF4014 */  bnez       $v0, .L8004E214
    /* 3EAD0 8004E2D0 9E00A4A3 */   sb        $a0, 0x9E($sp)
  .L8004E2D4:
    /* 3EAD4 8004E2D4 8000828F */  lw         $v0, %gp_rel(D_8009AF88)($gp)
    /* 3EAD8 8004E2D8 00000000 */  nop
    /* 3EADC 8004E2DC A1004290 */  lbu        $v0, 0xA1($v0)
    /* 3EAE0 8004E2E0 00000000 */  nop
    /* 3EAE4 8004E2E4 01004230 */  andi       $v0, $v0, 0x1
    /* 3EAE8 8004E2E8 28014010 */  beqz       $v0, .L8004E78C
    /* 3EAEC 8004E2EC 4800B027 */   addiu     $s0, $sp, 0x48
    /* 3EAF0 8004E2F0 21200002 */  addu       $a0, $s0, $zero
    /* 3EAF4 8004E2F4 2C00B127 */  addiu      $s1, $sp, 0x2C
    /* 3EAF8 8004E2F8 21282002 */  addu       $a1, $s1, $zero
    /* 3EAFC 8004E2FC 0827020C */  jal        func_80089C20
    /* 3EB00 8004E300 BC00A627 */   addiu     $a2, $sp, 0xBC
    /* 3EB04 8004E304 21200002 */  addu       $a0, $s0, $zero
    /* 3EB08 8004E308 21282002 */  addu       $a1, $s1, $zero
    /* 3EB0C 8004E30C 0827020C */  jal        func_80089C20
    /* 3EB10 8004E310 C400A627 */   addiu     $a2, $sp, 0xC4
    /* 3EB14 8004E314 21200002 */  addu       $a0, $s0, $zero
    /* 3EB18 8004E318 3000B127 */  addiu      $s1, $sp, 0x30
    /* 3EB1C 8004E31C 21282002 */  addu       $a1, $s1, $zero
    /* 3EB20 8004E320 0827020C */  jal        func_80089C20
    /* 3EB24 8004E324 CC00A627 */   addiu     $a2, $sp, 0xCC
    /* 3EB28 8004E328 21200002 */  addu       $a0, $s0, $zero
    /* 3EB2C 8004E32C 21282002 */  addu       $a1, $s1, $zero
    /* 3EB30 8004E330 0827020C */  jal        func_80089C20
    /* 3EB34 8004E334 D400A627 */   addiu     $a2, $sp, 0xD4
    /* 3EB38 8004E338 21200002 */  addu       $a0, $s0, $zero
    /* 3EB3C 8004E33C 21282002 */  addu       $a1, $s1, $zero
    /* 3EB40 8004E340 0827020C */  jal        func_80089C20
    /* 3EB44 8004E344 E000A627 */   addiu     $a2, $sp, 0xE0
    /* 3EB48 8004E348 21200002 */  addu       $a0, $s0, $zero
    /* 3EB4C 8004E34C 21282002 */  addu       $a1, $s1, $zero
    /* 3EB50 8004E350 0827020C */  jal        func_80089C20
    /* 3EB54 8004E354 E800A627 */   addiu     $a2, $sp, 0xE8
    /* 3EB58 8004E358 21200002 */  addu       $a0, $s0, $zero
    /* 3EB5C 8004E35C 3400B127 */  addiu      $s1, $sp, 0x34
    /* 3EB60 8004E360 21282002 */  addu       $a1, $s1, $zero
    /* 3EB64 8004E364 0827020C */  jal        func_80089C20
    /* 3EB68 8004E368 F000A627 */   addiu     $a2, $sp, 0xF0
    /* 3EB6C 8004E36C 21200002 */  addu       $a0, $s0, $zero
    /* 3EB70 8004E370 21282002 */  addu       $a1, $s1, $zero
    /* 3EB74 8004E374 0827020C */  jal        func_80089C20
    /* 3EB78 8004E378 F800A627 */   addiu     $a2, $sp, 0xF8
    /* 3EB7C 8004E37C 21200002 */  addu       $a0, $s0, $zero
    /* 3EB80 8004E380 21282002 */  addu       $a1, $s1, $zero
    /* 3EB84 8004E384 0827020C */  jal        func_80089C20
    /* 3EB88 8004E388 0401A627 */   addiu     $a2, $sp, 0x104
    /* 3EB8C 8004E38C 21200002 */  addu       $a0, $s0, $zero
    /* 3EB90 8004E390 21282002 */  addu       $a1, $s1, $zero
    /* 3EB94 8004E394 0827020C */  jal        func_80089C20
    /* 3EB98 8004E398 0C01A627 */   addiu     $a2, $sp, 0x10C
    /* 3EB9C 8004E39C 21200002 */  addu       $a0, $s0, $zero
    /* 3EBA0 8004E3A0 3800B127 */  addiu      $s1, $sp, 0x38
    /* 3EBA4 8004E3A4 21282002 */  addu       $a1, $s1, $zero
    /* 3EBA8 8004E3A8 0827020C */  jal        func_80089C20
    /* 3EBAC 8004E3AC 1401A627 */   addiu     $a2, $sp, 0x114
    /* 3EBB0 8004E3B0 21200002 */  addu       $a0, $s0, $zero
    /* 3EBB4 8004E3B4 21282002 */  addu       $a1, $s1, $zero
    /* 3EBB8 8004E3B8 0827020C */  jal        func_80089C20
    /* 3EBBC 8004E3BC 1C01A627 */   addiu     $a2, $sp, 0x11C
    /* 3EBC0 8004E3C0 08000324 */  addiu      $v1, $zero, 0x8
    /* 3EBC4 8004E3C4 38000224 */  addiu      $v0, $zero, 0x38
    /* 3EBC8 8004E3C8 BF00A2A3 */  sb         $v0, 0xBF($sp)
    /* 3EBCC 8004E3CC E300A2A3 */  sb         $v0, 0xE3($sp)
    /* 3EBD0 8004E3D0 0701A2A3 */  sb         $v0, 0x107($sp)
    /* 3EBD4 8004E3D4 E8030224 */  addiu      $v0, $zero, 0x3E8
    /* 3EBD8 8004E3D8 5000A2A7 */  sh         $v0, 0x50($sp)
    /* 3EBDC 8004E3DC 40060224 */  addiu      $v0, $zero, 0x640
    /* 3EBE0 8004E3E0 6000A2A7 */  sh         $v0, 0x60($sp)
    /* 3EBE4 8004E3E4 98080224 */  addiu      $v0, $zero, 0x898
    /* 3EBE8 8004E3E8 7000A2A7 */  sh         $v0, 0x70($sp)
    /* 3EBEC 8004E3EC F00A0224 */  addiu      $v0, $zero, 0xAF0
    /* 3EBF0 8004E3F0 BB00A3A3 */  sb         $v1, 0xBB($sp)
    /* 3EBF4 8004E3F4 DF00A3A3 */  sb         $v1, 0xDF($sp)
    /* 3EBF8 8004E3F8 0301A3A3 */  sb         $v1, 0x103($sp)
    /* 3EBFC 8004E3FC 5200B2A7 */  sh         $s2, 0x52($sp)
    /* 3EC00 8004E400 5400A0A7 */  sh         $zero, 0x54($sp)
    /* 3EC04 8004E404 6200B2A7 */  sh         $s2, 0x62($sp)
    /* 3EC08 8004E408 6400A0A7 */  sh         $zero, 0x64($sp)
    /* 3EC0C 8004E40C 7200B2A7 */  sh         $s2, 0x72($sp)
    /* 3EC10 8004E410 7400A0A7 */  sh         $zero, 0x74($sp)
    /* 3EC14 8004E414 8000A2A7 */  sh         $v0, 0x80($sp)
    /* 3EC18 8004E418 8200B2A7 */  sh         $s2, 0x82($sp)
    /* 3EC1C 8004E41C 8400A0A7 */  sh         $zero, 0x84($sp)
    /* 3EC20 8004E420 5A00B2A7 */  sh         $s2, 0x5A($sp)
    /* 3EC24 8004E424 6A00B2A7 */  sh         $s2, 0x6A($sp)
    /* 3EC28 8004E428 7A00B2A7 */  sh         $s2, 0x7A($sp)
    /* 3EC2C 8004E42C 8864010C */  jal        func_80059220
    /* 3EC30 8004E430 8A00B2A7 */   sh        $s2, 0x8A($sp)
    /* 3EC34 8004E434 7415020C */  jal        func_800855D0
    /* 3EC38 8004E438 21204000 */   addu      $a0, $v0, $zero
    /* 3EC3C 8004E43C 00011224 */  addiu      $s2, $zero, 0x100
    /* 3EC40 8004E440 B800B527 */  addiu      $s5, $sp, 0xB8
    /* 3EC44 8004E444 0F80023C */  lui        $v0, %hi(D_800E9D90)
    /* 3EC48 8004E448 909D5424 */  addiu      $s4, $v0, %lo(D_800E9D90)
    /* 3EC4C 8004E44C 01001324 */  addiu      $s3, $zero, 0x1
  .L8004E450:
    /* 3EC50 8004E450 DC19020C */  jal        func_80086770
    /* 3EC54 8004E454 21204002 */   addu      $a0, $s2, $zero
    /* 3EC58 8004E458 21204002 */  addu       $a0, $s2, $zero
    /* 3EC5C 8004E45C A819020C */  jal        func_800866A0
    /* 3EC60 8004E460 21804000 */   addu      $s0, $v0, $zero
    /* 3EC64 8004E464 40191000 */  sll        $v1, $s0, 5
    /* 3EC68 8004E468 23187000 */  subu       $v1, $v1, $s0
    /* 3EC6C 8004E46C 80180300 */  sll        $v1, $v1, 2
    /* 3EC70 8004E470 21187000 */  addu       $v1, $v1, $s0
    /* 3EC74 8004E474 C0180300 */  sll        $v1, $v1, 3
    /* 3EC78 8004E478 02006104 */  bgez       $v1, .L8004E484
    /* 3EC7C 8004E47C 21204000 */   addu      $a0, $v0, $zero
    /* 3EC80 8004E480 FF0F6324 */  addiu      $v1, $v1, 0xFFF
  .L8004E484:
    /* 3EC84 8004E484 03130300 */  sra        $v0, $v1, 12
    /* 3EC88 8004E488 5800A2A7 */  sh         $v0, 0x58($sp)
    /* 3EC8C 8004E48C 40110400 */  sll        $v0, $a0, 5
    /* 3EC90 8004E490 23104400 */  subu       $v0, $v0, $a0
    /* 3EC94 8004E494 80100200 */  sll        $v0, $v0, 2
    /* 3EC98 8004E498 21104400 */  addu       $v0, $v0, $a0
    /* 3EC9C 8004E49C C0100200 */  sll        $v0, $v0, 3
    /* 3ECA0 8004E4A0 02004104 */  bgez       $v0, .L8004E4AC
    /* 3ECA4 8004E4A4 00000000 */   nop
    /* 3ECA8 8004E4A8 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8004E4AC:
    /* 3ECAC 8004E4AC 03130200 */  sra        $v0, $v0, 12
    /* 3ECB0 8004E4B0 5C00A2A7 */  sh         $v0, 0x5C($sp)
    /* 3ECB4 8004E4B4 40101000 */  sll        $v0, $s0, 1
    /* 3ECB8 8004E4B8 21185000 */  addu       $v1, $v0, $s0
    /* 3ECBC 8004E4BC C0100300 */  sll        $v0, $v1, 3
    /* 3ECC0 8004E4C0 21105000 */  addu       $v0, $v0, $s0
    /* 3ECC4 8004E4C4 80110200 */  sll        $v0, $v0, 6
    /* 3ECC8 8004E4C8 02004104 */  bgez       $v0, .L8004E4D4
    /* 3ECCC 8004E4CC 00000000 */   nop
    /* 3ECD0 8004E4D0 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8004E4D4:
    /* 3ECD4 8004E4D4 03130200 */  sra        $v0, $v0, 12
    /* 3ECD8 8004E4D8 6800A2A7 */  sh         $v0, 0x68($sp)
    /* 3ECDC 8004E4DC 40100400 */  sll        $v0, $a0, 1
    /* 3ECE0 8004E4E0 21284400 */  addu       $a1, $v0, $a0
    /* 3ECE4 8004E4E4 C0100500 */  sll        $v0, $a1, 3
    /* 3ECE8 8004E4E8 21104400 */  addu       $v0, $v0, $a0
    /* 3ECEC 8004E4EC 80110200 */  sll        $v0, $v0, 6
    /* 3ECF0 8004E4F0 02004104 */  bgez       $v0, .L8004E4FC
    /* 3ECF4 8004E4F4 00000000 */   nop
    /* 3ECF8 8004E4F8 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8004E4FC:
    /* 3ECFC 8004E4FC 03130200 */  sra        $v0, $v0, 12
    /* 3ED00 8004E500 6C00A2A7 */  sh         $v0, 0x6C($sp)
    /* 3ED04 8004E504 00111000 */  sll        $v0, $s0, 4
    /* 3ED08 8004E508 21105000 */  addu       $v0, $v0, $s0
    /* 3ED0C 8004E50C 80100200 */  sll        $v0, $v0, 2
    /* 3ED10 8004E510 21105000 */  addu       $v0, $v0, $s0
    /* 3ED14 8004E514 80100200 */  sll        $v0, $v0, 2
    /* 3ED18 8004E518 23105000 */  subu       $v0, $v0, $s0
    /* 3ED1C 8004E51C C0100200 */  sll        $v0, $v0, 3
    /* 3ED20 8004E520 02004104 */  bgez       $v0, .L8004E52C
    /* 3ED24 8004E524 00000000 */   nop
    /* 3ED28 8004E528 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8004E52C:
    /* 3ED2C 8004E52C 03130200 */  sra        $v0, $v0, 12
    /* 3ED30 8004E530 7800A2A7 */  sh         $v0, 0x78($sp)
    /* 3ED34 8004E534 00110400 */  sll        $v0, $a0, 4
    /* 3ED38 8004E538 21104400 */  addu       $v0, $v0, $a0
    /* 3ED3C 8004E53C 80100200 */  sll        $v0, $v0, 2
    /* 3ED40 8004E540 21104400 */  addu       $v0, $v0, $a0
    /* 3ED44 8004E544 80100200 */  sll        $v0, $v0, 2
    /* 3ED48 8004E548 23104400 */  subu       $v0, $v0, $a0
    /* 3ED4C 8004E54C C0100200 */  sll        $v0, $v0, 3
    /* 3ED50 8004E550 02004104 */  bgez       $v0, .L8004E55C
    /* 3ED54 8004E554 00000000 */   nop
    /* 3ED58 8004E558 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8004E55C:
    /* 3ED5C 8004E55C 03130200 */  sra        $v0, $v0, 12
    /* 3ED60 8004E560 7C00A2A7 */  sh         $v0, 0x7C($sp)
    /* 3ED64 8004E564 80100300 */  sll        $v0, $v1, 2
    /* 3ED68 8004E568 23105000 */  subu       $v0, $v0, $s0
    /* 3ED6C 8004E56C 00110200 */  sll        $v0, $v0, 4
    /* 3ED70 8004E570 23105000 */  subu       $v0, $v0, $s0
    /* 3ED74 8004E574 00110200 */  sll        $v0, $v0, 4
    /* 3ED78 8004E578 02004104 */  bgez       $v0, .L8004E584
    /* 3ED7C 8004E57C 00000000 */   nop
    /* 3ED80 8004E580 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8004E584:
    /* 3ED84 8004E584 03130200 */  sra        $v0, $v0, 12
    /* 3ED88 8004E588 8800A2A7 */  sh         $v0, 0x88($sp)
    /* 3ED8C 8004E58C 80100500 */  sll        $v0, $a1, 2
    /* 3ED90 8004E590 23104400 */  subu       $v0, $v0, $a0
    /* 3ED94 8004E594 00110200 */  sll        $v0, $v0, 4
    /* 3ED98 8004E598 23104400 */  subu       $v0, $v0, $a0
    /* 3ED9C 8004E59C 00110200 */  sll        $v0, $v0, 4
    /* 3EDA0 8004E5A0 02004104 */  bgez       $v0, .L8004E5AC
    /* 3EDA4 8004E5A4 5000A427 */   addiu     $a0, $sp, 0x50
    /* 3EDA8 8004E5A8 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8004E5AC:
    /* 3EDAC 8004E5AC 5800A527 */  addiu      $a1, $sp, 0x58
    /* 3EDB0 8004E5B0 6000A627 */  addiu      $a2, $sp, 0x60
    /* 3EDB4 8004E5B4 6800A727 */  addiu      $a3, $sp, 0x68
    /* 3EDB8 8004E5B8 03130200 */  sra        $v0, $v0, 12
    /* 3EDBC 8004E5BC 8C00A2A7 */  sh         $v0, 0x8C($sp)
    /* 3EDC0 8004E5C0 C000A227 */  addiu      $v0, $sp, 0xC0
    /* 3EDC4 8004E5C4 1000A2AF */  sw         $v0, 0x10($sp)
    /* 3EDC8 8004E5C8 C800A227 */  addiu      $v0, $sp, 0xC8
    /* 3EDCC 8004E5CC 1400A2AF */  sw         $v0, 0x14($sp)
    /* 3EDD0 8004E5D0 D000A227 */  addiu      $v0, $sp, 0xD0
    /* 3EDD4 8004E5D4 1800A2AF */  sw         $v0, 0x18($sp)
    /* 3EDD8 8004E5D8 D800A227 */  addiu      $v0, $sp, 0xD8
    /* 3EDDC 8004E5DC 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 3EDE0 8004E5E0 2801A227 */  addiu      $v0, $sp, 0x128
    /* 3EDE4 8004E5E4 2000A2AF */  sw         $v0, 0x20($sp)
    /* 3EDE8 8004E5E8 2C01A227 */  addiu      $v0, $sp, 0x12C
    /* 3EDEC 8004E5EC AC1E020C */  jal        func_80087AB0
    /* 3EDF0 8004E5F0 2400A2AF */   sw        $v0, 0x24($sp)
    /* 3EDF4 8004E5F4 7000A427 */  addiu      $a0, $sp, 0x70
    /* 3EDF8 8004E5F8 7800A527 */  addiu      $a1, $sp, 0x78
    /* 3EDFC 8004E5FC 8000A627 */  addiu      $a2, $sp, 0x80
    /* 3EE00 8004E600 8800A727 */  addiu      $a3, $sp, 0x88
    /* 3EE04 8004E604 0801A327 */  addiu      $v1, $sp, 0x108
    /* 3EE08 8004E608 1000A3AF */  sw         $v1, 0x10($sp)
    /* 3EE0C 8004E60C 1001A327 */  addiu      $v1, $sp, 0x110
    /* 3EE10 8004E610 1400A3AF */  sw         $v1, 0x14($sp)
    /* 3EE14 8004E614 1801A327 */  addiu      $v1, $sp, 0x118
    /* 3EE18 8004E618 1800A3AF */  sw         $v1, 0x18($sp)
    /* 3EE1C 8004E61C 2001A327 */  addiu      $v1, $sp, 0x120
    /* 3EE20 8004E620 1C00A3AF */  sw         $v1, 0x1C($sp)
    /* 3EE24 8004E624 3001A327 */  addiu      $v1, $sp, 0x130
    /* 3EE28 8004E628 2000A3AF */  sw         $v1, 0x20($sp)
    /* 3EE2C 8004E62C 3401A327 */  addiu      $v1, $sp, 0x134
    /* 3EE30 8004E630 21804000 */  addu       $s0, $v0, $zero
    /* 3EE34 8004E634 AC1E020C */  jal        func_80087AB0
    /* 3EE38 8004E638 2400A3AF */   sw        $v1, 0x24($sp)
    /* 3EE3C 8004E63C D000A397 */  lhu        $v1, 0xD0($sp)
    /* 3EE40 8004E640 D200A497 */  lhu        $a0, 0xD2($sp)
    /* 3EE44 8004E644 D800A597 */  lhu        $a1, 0xD8($sp)
    /* 3EE48 8004E648 DA00A697 */  lhu        $a2, 0xDA($sp)
    /* 3EE4C 8004E64C 0801A797 */  lhu        $a3, 0x108($sp)
    /* 3EE50 8004E650 0A01A897 */  lhu        $t0, 0x10A($sp)
    /* 3EE54 8004E654 1001A997 */  lhu        $t1, 0x110($sp)
    /* 3EE58 8004E658 1201AA97 */  lhu        $t2, 0x112($sp)
    /* 3EE5C 8004E65C 21884000 */  addu       $s1, $v0, $zero
    /* 3EE60 8004E660 E400A3A7 */  sh         $v1, 0xE4($sp)
    /* 3EE64 8004E664 E600A4A7 */  sh         $a0, 0xE6($sp)
    /* 3EE68 8004E668 EC00A5A7 */  sh         $a1, 0xEC($sp)
    /* 3EE6C 8004E66C EE00A6A7 */  sh         $a2, 0xEE($sp)
    /* 3EE70 8004E670 F400A7A7 */  sh         $a3, 0xF4($sp)
    /* 3EE74 8004E674 F600A8A7 */  sh         $t0, 0xF6($sp)
    /* 3EE78 8004E678 FC00A9A7 */  sh         $t1, 0xFC($sp)
    /* 3EE7C 8004E67C 0B000006 */  bltz       $s0, .L8004E6AC
    /* 3EE80 8004E680 FE00AAA7 */   sh        $t2, 0xFE($sp)
    /* 3EE84 8004E684 0C00858E */  lw         $a1, 0xC($s4)
    /* 3EE88 8004E688 00000000 */  nop
    /* 3EE8C 8004E68C 0000A68C */  lw         $a2, 0x0($a1)
    /* 3EE90 8004E690 2120A002 */  addu       $a0, $s5, $zero
    /* 3EE94 8004E694 0430D300 */  sllv       $a2, $s3, $a2
    /* 3EE98 8004E698 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 3EE9C 8004E69C C810020C */  jal        func_80084320
    /* 3EEA0 8004E6A0 FFFFC630 */   andi      $a2, $a2, 0xFFFF
    /* 3EEA4 8004E6A4 AD390108 */  j          .L8004E6B4
    /* 3EEA8 8004E6A8 00000000 */   nop
  .L8004E6AC:
    /* 3EEAC 8004E6AC 13002006 */  bltz       $s1, .L8004E6FC
    /* 3EEB0 8004E6B0 00000000 */   nop
  .L8004E6B4:
    /* 3EEB4 8004E6B4 0C00858E */  lw         $a1, 0xC($s4)
    /* 3EEB8 8004E6B8 00000000 */  nop
    /* 3EEBC 8004E6BC 0000A68C */  lw         $a2, 0x0($a1)
    /* 3EEC0 8004E6C0 DC00A427 */  addiu      $a0, $sp, 0xDC
    /* 3EEC4 8004E6C4 0430D300 */  sllv       $a2, $s3, $a2
    /* 3EEC8 8004E6C8 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 3EECC 8004E6CC C810020C */  jal        func_80084320
    /* 3EED0 8004E6D0 FFFFC630 */   andi      $a2, $a2, 0xFFFF
    /* 3EED4 8004E6D4 09002006 */  bltz       $s1, .L8004E6FC
    /* 3EED8 8004E6D8 0001A427 */   addiu     $a0, $sp, 0x100
    /* 3EEDC 8004E6DC 0C00858E */  lw         $a1, 0xC($s4)
    /* 3EEE0 8004E6E0 00000000 */  nop
    /* 3EEE4 8004E6E4 0000A68C */  lw         $a2, 0x0($a1)
    /* 3EEE8 8004E6E8 00000000 */  nop
    /* 3EEEC 8004E6EC 0430D300 */  sllv       $a2, $s3, $a2
    /* 3EEF0 8004E6F0 FFFFC624 */  addiu      $a2, $a2, -0x1
    /* 3EEF4 8004E6F4 C810020C */  jal        func_80084320
    /* 3EEF8 8004E6F8 FFFFC630 */   andi      $a2, $a2, 0xFFFF
  .L8004E6FC:
    /* 3EEFC 8004E6FC 00015226 */  addiu      $s2, $s2, 0x100
    /* 3EF00 8004E700 0110422A */  slti       $v0, $s2, 0x1001
    /* 3EF04 8004E704 5B00AB8B */  lwl        $t3, 0x5B($sp)
    /* 3EF08 8004E708 5800AB9B */  lwr        $t3, 0x58($sp)
    /* 3EF0C 8004E70C 5F00AC8B */  lwl        $t4, 0x5F($sp)
    /* 3EF10 8004E710 5C00AC9B */  lwr        $t4, 0x5C($sp)
    /* 3EF14 8004E714 5300ABAB */  swl        $t3, 0x53($sp)
    /* 3EF18 8004E718 5000ABBB */  swr        $t3, 0x50($sp)
    /* 3EF1C 8004E71C 5700ACAB */  swl        $t4, 0x57($sp)
    /* 3EF20 8004E720 5400ACBB */  swr        $t4, 0x54($sp)
    /* 3EF24 8004E724 6B00AB8B */  lwl        $t3, 0x6B($sp)
    /* 3EF28 8004E728 6800AB9B */  lwr        $t3, 0x68($sp)
    /* 3EF2C 8004E72C 6F00AC8B */  lwl        $t4, 0x6F($sp)
    /* 3EF30 8004E730 6C00AC9B */  lwr        $t4, 0x6C($sp)
    /* 3EF34 8004E734 6300ABAB */  swl        $t3, 0x63($sp)
    /* 3EF38 8004E738 6000ABBB */  swr        $t3, 0x60($sp)
    /* 3EF3C 8004E73C 6700ACAB */  swl        $t4, 0x67($sp)
    /* 3EF40 8004E740 6400ACBB */  swr        $t4, 0x64($sp)
    /* 3EF44 8004E744 7B00AB8B */  lwl        $t3, 0x7B($sp)
    /* 3EF48 8004E748 7800AB9B */  lwr        $t3, 0x78($sp)
    /* 3EF4C 8004E74C 7F00AC8B */  lwl        $t4, 0x7F($sp)
    /* 3EF50 8004E750 7C00AC9B */  lwr        $t4, 0x7C($sp)
    /* 3EF54 8004E754 7300ABAB */  swl        $t3, 0x73($sp)
    /* 3EF58 8004E758 7000ABBB */  swr        $t3, 0x70($sp)
    /* 3EF5C 8004E75C 7700ACAB */  swl        $t4, 0x77($sp)
    /* 3EF60 8004E760 7400ACBB */  swr        $t4, 0x74($sp)
    /* 3EF64 8004E764 8B00AB8B */  lwl        $t3, 0x8B($sp)
    /* 3EF68 8004E768 8800AB9B */  lwr        $t3, 0x88($sp)
    /* 3EF6C 8004E76C 8F00AC8B */  lwl        $t4, 0x8F($sp)
    /* 3EF70 8004E770 8C00AC9B */  lwr        $t4, 0x8C($sp)
    /* 3EF74 8004E774 8300ABAB */  swl        $t3, 0x83($sp)
    /* 3EF78 8004E778 8000ABBB */  swr        $t3, 0x80($sp)
    /* 3EF7C 8004E77C 8700ACAB */  swl        $t4, 0x87($sp)
    /* 3EF80 8004E780 8400ACBB */  swr        $t4, 0x84($sp)
    /* 3EF84 8004E784 32FF4014 */  bnez       $v0, .L8004E450
    /* 3EF88 8004E788 00000000 */   nop
  .L8004E78C:
    /* 3EF8C 8004E78C 5001BF8F */  lw         $ra, 0x150($sp)
    /* 3EF90 8004E790 4C01B58F */  lw         $s5, 0x14C($sp)
    /* 3EF94 8004E794 4801B48F */  lw         $s4, 0x148($sp)
    /* 3EF98 8004E798 4401B38F */  lw         $s3, 0x144($sp)
    /* 3EF9C 8004E79C 4001B28F */  lw         $s2, 0x140($sp)
    /* 3EFA0 8004E7A0 3C01B18F */  lw         $s1, 0x13C($sp)
    /* 3EFA4 8004E7A4 3801B08F */  lw         $s0, 0x138($sp)
    /* 3EFA8 8004E7A8 0800E003 */  jr         $ra
    /* 3EFAC 8004E7AC 5801BD27 */   addiu     $sp, $sp, 0x158
endlabel func_8004DE24
