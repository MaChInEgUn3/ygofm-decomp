nonmatching func_80029EC4, 0x430

glabel func_80029EC4
    /* 1A6C4 80029EC4 17B8033C */  lui        $v1, (0xB81702E1 >> 16)
    /* 1A6C8 80029EC8 0A80023C */  lui        $v0, %hi(D_8009B148)
    /* 1A6CC 80029ECC 48B14284 */  lh         $v0, %lo(D_8009B148)($v0)
    /* 1A6D0 80029ED0 E1026334 */  ori        $v1, $v1, (0xB81702E1 & 0xFFFF)
    /* 1A6D4 80029ED4 F8FF4224 */  addiu      $v0, $v0, -0x8
    /* 1A6D8 80029ED8 18004300 */  mult       $v0, $v1
    /* 1A6DC 80029EDC B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 1A6E0 80029EE0 2800B0AF */  sw         $s0, 0x28($sp)
    /* 1A6E4 80029EE4 801F103C */  lui        $s0, (0x1F800320 >> 16)
    /* 1A6E8 80029EE8 4800BEAF */  sw         $fp, 0x48($sp)
    /* 1A6EC 80029EEC 10480000 */  mfhi       $t1
    /* 1A6F0 80029EF0 21182201 */  addu       $v1, $t1, $v0
    /* 1A6F4 80029EF4 C3190300 */  sra        $v1, $v1, 7
    /* 1A6F8 80029EF8 C3170200 */  sra        $v0, $v0, 31
    /* 1A6FC 80029EFC 23F06200 */  subu       $fp, $v1, $v0
    /* 1A700 80029F00 0F80023C */  lui        $v0, %hi(D_800E9D9C)
    /* 1A704 80029F04 9C9D428C */  lw         $v0, %lo(D_800E9D9C)($v0)
    /* 1A708 80029F08 20031036 */  ori        $s0, $s0, (0x1F800320 & 0xFFFF)
    /* 1A70C 80029F0C 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 1A710 80029F10 4400B7AF */  sw         $s7, 0x44($sp)
    /* 1A714 80029F14 4000B6AF */  sw         $s6, 0x40($sp)
    /* 1A718 80029F18 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 1A71C 80029F1C 3800B4AF */  sw         $s4, 0x38($sp)
    /* 1A720 80029F20 3400B3AF */  sw         $s3, 0x34($sp)
    /* 1A724 80029F24 3000B2AF */  sw         $s2, 0x30($sp)
    /* 1A728 80029F28 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 1A72C 80029F2C E500C007 */  bltz       $fp, .L8002A2C4
    /* 1A730 80029F30 1000A2AF */   sw        $v0, 0x10($sp)
    /* 1A734 80029F34 0E00053C */  lui        $a1, (0xE000C >> 16)
    /* 1A738 80029F38 0C00A534 */  ori        $a1, $a1, (0xE000C & 0xFFFF)
    /* 1A73C 80029F3C F700043C */  lui        $a0, (0xF70130 >> 16)
    /* 1A740 80029F40 8000093C */  lui        $t1, (0x808080 >> 16)
    /* 1A744 80029F44 80802935 */  ori        $t1, $t1, (0x808080 & 0xFFFF)
    /* 1A748 80029F48 1400A9AF */  sw         $t1, 0x14($sp)
    /* 1A74C 80029F4C 4000093C */  lui        $t1, (0x404040 >> 16)
    /* 1A750 80029F50 40402935 */  ori        $t1, $t1, (0x404040 & 0xFFFF)
    /* 1A754 80029F54 40181E00 */  sll        $v1, $fp, 1
    /* 1A758 80029F58 21187E00 */  addu       $v1, $v1, $fp
    /* 1A75C 80029F5C 80100300 */  sll        $v0, $v1, 2
    /* 1A760 80029F60 23105E00 */  subu       $v0, $v0, $fp
    /* 1A764 80029F64 C0100200 */  sll        $v0, $v0, 3
    /* 1A768 80029F68 21105E00 */  addu       $v0, $v0, $fp
    /* 1A76C 80029F6C 40100200 */  sll        $v0, $v0, 1
    /* 1A770 80029F70 08004224 */  addiu      $v0, $v0, 0x8
    /* 1A774 80029F74 C0180300 */  sll        $v1, $v1, 3
    /* 1A778 80029F78 21187E00 */  addu       $v1, $v1, $fp
    /* 1A77C 80029F7C 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 1A780 80029F80 08000224 */  addiu      $v0, $zero, 0x8
    /* 1A784 80029F84 1800A9AF */  sw         $t1, 0x18($sp)
    /* 1A788 80029F88 2000A3AF */  sw         $v1, 0x20($sp)
    /* 1A78C 80029F8C 040002A6 */  sh         $v0, 0x4($s0)
    /* 1A790 80029F90 2000A98F */  lw         $t1, 0x20($sp)
    /* 1A794 80029F94 30018434 */  ori        $a0, $a0, (0xF70130 & 0xFFFF)
    /* 1A798 80029F98 080005AE */  sw         $a1, 0x8($s0)
    /* 1A79C 80029F9C 100004AE */  sw         $a0, 0x10($s0)
    /* 1A7A0 80029FA0 C0180900 */  sll        $v1, $t1, 3
    /* 1A7A4 80029FA4 00110900 */  sll        $v0, $t1, 4
    /* 1A7A8 80029FA8 21104300 */  addu       $v0, $v0, $v1
    /* 1A7AC 80029FAC 80100200 */  sll        $v0, $v0, 2
    /* 1A7B0 80029FB0 23104300 */  subu       $v0, $v0, $v1
    /* 1A7B4 80029FB4 C0100200 */  sll        $v0, $v0, 3
    /* 1A7B8 80029FB8 21104300 */  addu       $v0, $v0, $v1
    /* 1A7BC 80029FBC 40100200 */  sll        $v0, $v0, 1
    /* 1A7C0 80029FC0 08004224 */  addiu      $v0, $v0, 0x8
    /* 1A7C4 80029FC4 0008033C */  lui        $v1, (0x8000000 >> 16)
    /* 1A7C8 80029FC8 060002A6 */  sh         $v0, 0x6($s0)
    /* 1A7CC 80029FCC F7000224 */  addiu      $v0, $zero, 0xF7
    /* 1A7D0 80029FD0 120002A6 */  sh         $v0, 0x12($s0)
    /* 1A7D4 80029FD4 60F00234 */  ori        $v0, $zero, 0xF060
    /* 1A7D8 80029FD8 0E0002A6 */  sh         $v0, 0xE($s0)
    /* 1A7DC 80029FDC 1B000224 */  addiu      $v0, $zero, 0x1B
    /* 1A7E0 80029FE0 000003AE */  sw         $v1, 0x0($s0)
    /* 1A7E4 80029FE4 0C0002A6 */  sh         $v0, 0xC($s0)
  .L80029FE8:
    /* 1A7E8 80029FE8 2000A98F */  lw         $t1, 0x20($sp)
    /* 1A7EC 80029FEC 0A80023C */  lui        $v0, %hi(D_8009B148)
    /* 1A7F0 80029FF0 48B14294 */  lhu        $v0, %lo(D_8009B148)($v0)
    /* 1A7F4 80029FF4 C0B00900 */  sll        $s6, $t1, 3
    /* 1A7F8 80029FF8 1C00A997 */  lhu        $t1, 0x1C($sp)
    /* 1A7FC 80029FFC 00000000 */  nop
    /* 1A800 8002A000 060009A6 */  sh         $t1, 0x6($s0)
    /* 1A804 8002A004 1C00A98F */  lw         $t1, 0x1C($sp)
    /* 1A808 8002A008 21B80000 */  addu       $s7, $zero, $zero
    /* 1A80C 8002A00C 23102201 */  subu       $v0, $t1, $v0
    /* 1A810 8002A010 060002A6 */  sh         $v0, 0x6($s0)
  .L8002A014:
    /* 1A814 8002A014 06000396 */  lhu        $v1, 0x6($s0)
    /* 1A818 8002A018 08000296 */  lhu        $v0, 0x8($s0)
    /* 1A81C 8002A01C 001C0300 */  sll        $v1, $v1, 16
    /* 1A820 8002A020 031C0300 */  sra        $v1, $v1, 16
    /* 1A824 8002A024 21106200 */  addu       $v0, $v1, $v0
    /* 1A828 8002A028 43004018 */  blez       $v0, .L8002A138
    /* 1A82C 8002A02C 0100D326 */   addiu     $s3, $s6, 0x1
    /* 1A830 8002A030 F0006228 */  slti       $v0, $v1, 0xF0
    /* 1A834 8002A034 50004010 */  beqz       $v0, .L8002A178
    /* 1A838 8002A038 0F80093C */   lui       $t1, %hi(D_800EA1E8)
    /* 1A83C 8002A03C 6500D226 */  addiu      $s2, $s6, 0x65
    /* 1A840 8002A040 21880000 */  addu       $s1, $zero, $zero
    /* 1A844 8002A044 80101200 */  sll        $v0, $s2, 2
    /* 1A848 8002A048 E8A12925 */  addiu      $t1, $t1, %lo(D_800EA1E8)
    /* 1A84C 8002A04C 21A84900 */  addu       $s5, $v0, $t1
    /* 1A850 8002A050 80101300 */  sll        $v0, $s3, 2
    /* 1A854 8002A054 0F80093C */  lui        $t1, %hi(D_800EA1E8)
    /* 1A858 8002A058 E8A12925 */  addiu      $t1, $t1, %lo(D_800EA1E8)
    /* 1A85C 8002A05C 21A04900 */  addu       $s4, $v0, $t1
  .L8002A060:
    /* 1A860 8002A060 0F80043C */  lui        $a0, %hi(D_800EA1E8)
    /* 1A864 8002A064 E8A18424 */  addiu      $a0, $a0, %lo(D_800EA1E8)
    /* 1A868 8002A068 ACA7000C */  jal        func_80029EB0
    /* 1A86C 8002A06C 21286002 */   addu      $a1, $s3, $zero
    /* 1A870 8002A070 21184000 */  addu       $v1, $v0, $zero
    /* 1A874 8002A074 80006230 */  andi       $v0, $v1, 0x80
    /* 1A878 8002A078 0F004010 */  beqz       $v0, .L8002A0B8
    /* 1A87C 8002A07C 01006230 */   andi      $v0, $v1, 0x1
    /* 1A880 8002A080 1400A98F */  lw         $t1, 0x14($sp)
    /* 1A884 8002A084 04004010 */  beqz       $v0, .L8002A098
    /* 1A888 8002A088 140009AE */   sw        $t1, 0x14($s0)
    /* 1A88C 8002A08C 1800A98F */  lw         $t1, 0x18($sp)
    /* 1A890 8002A090 00000000 */  nop
    /* 1A894 8002A094 140009AE */  sw         $t1, 0x14($s0)
  .L8002A098:
    /* 1A898 8002A098 21200002 */  addu       $a0, $s0, $zero
    /* 1A89C 8002A09C 1000A58F */  lw         $a1, 0x10($sp)
    /* 1A8A0 8002A0A0 08002226 */  addiu      $v0, $s1, 0x8
    /* 1A8A4 8002A0A4 040002A6 */  sh         $v0, 0x4($s0)
    /* 1A8A8 8002A0A8 54008296 */  lhu        $v0, 0x54($s4)
    /* 1A8AC 8002A0AC 02000624 */  addiu      $a2, $zero, 0x2
    /* 1A8B0 8002A0B0 7C12020C */  jal        func_800849F0
    /* 1A8B4 8002A0B4 100002A6 */   sh        $v0, 0x10($s0)
  .L8002A0B8:
    /* 1A8B8 8002A0B8 D302422A */  slti       $v0, $s2, 0x2D3
    /* 1A8BC 8002A0BC 17004010 */  beqz       $v0, .L8002A11C
    /* 1A8C0 8002A0C0 00000000 */   nop
    /* 1A8C4 8002A0C4 0F80043C */  lui        $a0, %hi(D_800EA1E8)
    /* 1A8C8 8002A0C8 E8A18424 */  addiu      $a0, $a0, %lo(D_800EA1E8)
    /* 1A8CC 8002A0CC ACA7000C */  jal        func_80029EB0
    /* 1A8D0 8002A0D0 21284002 */   addu      $a1, $s2, $zero
    /* 1A8D4 8002A0D4 21184000 */  addu       $v1, $v0, $zero
    /* 1A8D8 8002A0D8 80006230 */  andi       $v0, $v1, 0x80
    /* 1A8DC 8002A0DC 0F004010 */  beqz       $v0, .L8002A11C
    /* 1A8E0 8002A0E0 01006230 */   andi      $v0, $v1, 0x1
    /* 1A8E4 8002A0E4 1400A98F */  lw         $t1, 0x14($sp)
    /* 1A8E8 8002A0E8 04004010 */  beqz       $v0, .L8002A0FC
    /* 1A8EC 8002A0EC 140009AE */   sw        $t1, 0x14($s0)
    /* 1A8F0 8002A0F0 1800A98F */  lw         $t1, 0x18($sp)
    /* 1A8F4 8002A0F4 00000000 */  nop
    /* 1A8F8 8002A0F8 140009AE */  sw         $t1, 0x14($s0)
  .L8002A0FC:
    /* 1A8FC 8002A0FC 21200002 */  addu       $a0, $s0, $zero
    /* 1A900 8002A100 1000A58F */  lw         $a1, 0x10($sp)
    /* 1A904 8002A104 A8002226 */  addiu      $v0, $s1, 0xA8
    /* 1A908 8002A108 040002A6 */  sh         $v0, 0x4($s0)
    /* 1A90C 8002A10C 5400A296 */  lhu        $v0, 0x54($s5)
    /* 1A910 8002A110 02000624 */  addiu      $a2, $zero, 0x2
    /* 1A914 8002A114 7C12020C */  jal        func_800849F0
    /* 1A918 8002A118 100002A6 */   sh        $v0, 0x10($s0)
  .L8002A11C:
    /* 1A91C 8002A11C 04009426 */  addiu      $s4, $s4, 0x4
    /* 1A920 8002A120 01007326 */  addiu      $s3, $s3, 0x1
    /* 1A924 8002A124 0400B526 */  addiu      $s5, $s5, 0x4
    /* 1A928 8002A128 0E003126 */  addiu      $s1, $s1, 0xE
    /* 1A92C 8002A12C 8A00222A */  slti       $v0, $s1, 0x8A
    /* 1A930 8002A130 CBFF4014 */  bnez       $v0, .L8002A060
    /* 1A934 8002A134 01005226 */   addiu     $s2, $s2, 0x1
  .L8002A138:
    /* 1A938 8002A138 06000296 */  lhu        $v0, 0x6($s0)
    /* 1A93C 8002A13C 0100F726 */  addiu      $s7, $s7, 0x1
    /* 1A940 8002A140 10004224 */  addiu      $v0, $v0, 0x10
    /* 1A944 8002A144 060002A6 */  sh         $v0, 0x6($s0)
    /* 1A948 8002A148 0A00E22A */  slti       $v0, $s7, 0xA
    /* 1A94C 8002A14C B1FF4014 */  bnez       $v0, .L8002A014
    /* 1A950 8002A150 0A00D626 */   addiu     $s6, $s6, 0xA
    /* 1A954 8002A154 1C00A98F */  lw         $t1, 0x1C($sp)
    /* 1A958 8002A158 0100DE27 */  addiu      $fp, $fp, 0x1
    /* 1A95C 8002A15C B2002925 */  addiu      $t1, $t1, 0xB2
    /* 1A960 8002A160 1C00A9AF */  sw         $t1, 0x1C($sp)
    /* 1A964 8002A164 2000A98F */  lw         $t1, 0x20($sp)
    /* 1A968 8002A168 0400C22B */  slti       $v0, $fp, 0x4
    /* 1A96C 8002A16C 19002925 */  addiu      $t1, $t1, 0x19
    /* 1A970 8002A170 9DFF4014 */  bnez       $v0, .L80029FE8
    /* 1A974 8002A174 2000A9AF */   sw        $t1, 0x20($sp)
  .L8002A178:
    /* 1A978 8002A178 801F103C */  lui        $s0, (0x1F80000F >> 16)
    /* 1A97C 8002A17C 0A80023C */  lui        $v0, %hi(D_8009B09C)
    /* 1A980 8002A180 9CB0428C */  lw         $v0, %lo(D_8009B09C)($v0)
    /* 1A984 8002A184 0050033C */  lui        $v1, (0x50000000 >> 16)
    /* 1A988 8002A188 000003AE */  sw         $v1, (0x1F800000 & 0xFFFF)($s0)
    /* 1A98C 8002A18C 0E0000A2 */  sb         $zero, (0x1F80000E & 0xFFFF)($s0)
    /* 1A990 8002A190 0D0000A2 */  sb         $zero, (0x1F80000D & 0xFFFF)($s0)
    /* 1A994 8002A194 0C0000A2 */  sb         $zero, (0x1F80000C & 0xFFFF)($s0)
    /* 1A998 8002A198 110000A2 */  sb         $zero, (0x1F800011 & 0xFFFF)($s0)
    /* 1A99C 8002A19C 100000A2 */  sb         $zero, (0x1F800010 & 0xFFFF)($s0)
    /* 1A9A0 8002A1A0 0F0000A2 */  sb         $zero, (0x1F80000F & 0xFFFF)($s0)
    /* 1A9A4 8002A1A4 7F004430 */  andi       $a0, $v0, 0x7F
    /* 1A9A8 8002A1A8 21188000 */  addu       $v1, $a0, $zero
    /* 1A9AC 8002A1AC 0F80023C */  lui        $v0, %hi(D_800EA1E8)
    /* 1A9B0 8002A1B0 02008104 */  bgez       $a0, .L8002A1BC
    /* 1A9B4 8002A1B4 E8A14824 */   addiu     $t0, $v0, %lo(D_800EA1E8)
    /* 1A9B8 8002A1B8 1F008324 */  addiu      $v1, $a0, 0x1F
  .L8002A1BC:
    /* 1A9BC 8002A1BC 43190300 */  sra        $v1, $v1, 5
    /* 1A9C0 8002A1C0 01000224 */  addiu      $v0, $zero, 0x1
    /* 1A9C4 8002A1C4 11006210 */  beq        $v1, $v0, .L8002A20C
    /* 1A9C8 8002A1C8 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 1A9CC 8002A1CC 02006228 */  slti       $v0, $v1, 0x2
    /* 1A9D0 8002A1D0 05004010 */  beqz       $v0, .L8002A1E8
    /* 1A9D4 8002A1D4 02000224 */   addiu     $v0, $zero, 0x2
    /* 1A9D8 8002A1D8 0A006010 */  beqz       $v1, .L8002A204
    /* 1A9DC 8002A1DC C0100400 */   sll       $v0, $a0, 3
    /* 1A9E0 8002A1E0 8FA80008 */  j          .L8002A23C
    /* 1A9E4 8002A1E4 21200002 */   addu      $a0, $s0, $zero
  .L8002A1E8:
    /* 1A9E8 8002A1E8 0B006210 */  beq        $v1, $v0, .L8002A218
    /* 1A9EC 8002A1EC 5F000224 */   addiu     $v0, $zero, 0x5F
    /* 1A9F0 8002A1F0 03000224 */  addiu      $v0, $zero, 0x3
    /* 1A9F4 8002A1F4 0D006210 */  beq        $v1, $v0, .L8002A22C
    /* 1A9F8 8002A1F8 7F000224 */   addiu     $v0, $zero, 0x7F
    /* 1A9FC 8002A1FC 8FA80008 */  j          .L8002A23C
    /* 1AA00 8002A200 21200002 */   addu      $a0, $s0, $zero
  .L8002A204:
    /* 1AA04 8002A204 8EA80008 */  j          .L8002A238
    /* 1AA08 8002A208 0D0002A2 */   sb        $v0, (0x1F80000D & 0xFFFF)($s0)
  .L8002A20C:
    /* 1AA0C 8002A20C 0D0002A2 */  sb         $v0, (0x1F80000D & 0xFFFF)($s0)
    /* 1AA10 8002A210 8CA80008 */  j          .L8002A230
    /* 1AA14 8002A214 E0FF8224 */   addiu     $v0, $a0, -0x20
  .L8002A218:
    /* 1AA18 8002A218 23104400 */  subu       $v0, $v0, $a0
    /* 1AA1C 8002A21C C0100200 */  sll        $v0, $v0, 3
    /* 1AA20 8002A220 0D0002A2 */  sb         $v0, (0x1F80000D & 0xFFFF)($s0)
    /* 1AA24 8002A224 8DA80008 */  j          .L8002A234
    /* 1AA28 8002A228 FF000224 */   addiu     $v0, $zero, 0xFF
  .L8002A22C:
    /* 1AA2C 8002A22C 23104400 */  subu       $v0, $v0, $a0
  .L8002A230:
    /* 1AA30 8002A230 C0100200 */  sll        $v0, $v0, 3
  .L8002A234:
    /* 1AA34 8002A234 100002A2 */  sb         $v0, (0x1F800010 & 0xFFFF)($s0)
  .L8002A238:
    /* 1AA38 8002A238 21200002 */  addu       $a0, $s0, $zero
  .L8002A23C:
    /* 1AA3C 8002A23C 1000A58F */  lw         $a1, 0x10($sp)
    /* 1AA40 8002A240 01000624 */  addiu      $a2, $zero, 0x1
    /* 1AA44 8002A244 080000A6 */  sh         $zero, (0x1F800008 & 0xFFFF)($s0)
    /* 1AA48 8002A248 08000395 */  lhu        $v1, 0x8($t0)
    /* 1AA4C 8002A24C 0A80073C */  lui        $a3, %hi(D_8009B146)
    /* 1AA50 8002A250 46B1E794 */  lhu        $a3, %lo(D_8009B146)($a3)
    /* 1AA54 8002A254 0A000295 */  lhu        $v0, 0xA($t0)
    /* 1AA58 8002A258 0A80083C */  lui        $t0, %hi(D_8009B148)
    /* 1AA5C 8002A25C 48B10895 */  lhu        $t0, %lo(D_8009B148)($t0)
    /* 1AA60 8002A260 23186700 */  subu       $v1, $v1, $a3
    /* 1AA64 8002A264 23104800 */  subu       $v0, $v0, $t0
    /* 1AA68 8002A268 040003A6 */  sh         $v1, (0x1F800004 & 0xFFFF)($s0)
    /* 1AA6C 8002A26C 0A0002A6 */  sh         $v0, (0x1F80000A & 0xFFFF)($s0)
    /* 1AA70 8002A270 4C10020C */  jal        func_80084130
    /* 1AA74 8002A274 060002A6 */   sh        $v0, (0x1F800006 & 0xFFFF)($s0)
    /* 1AA78 8002A278 21200002 */  addu       $a0, $s0, $zero
    /* 1AA7C 8002A27C 01000624 */  addiu      $a2, $zero, 0x1
    /* 1AA80 8002A280 1000A58F */  lw         $a1, 0x10($sp)
    /* 1AA84 8002A284 40010224 */  addiu      $v0, $zero, 0x140
    /* 1AA88 8002A288 4C10020C */  jal        func_80084130
    /* 1AA8C 8002A28C 080002A6 */   sh        $v0, (0x1F800008 & 0xFFFF)($s0)
    /* 1AA90 8002A290 21200002 */  addu       $a0, $s0, $zero
    /* 1AA94 8002A294 1000A58F */  lw         $a1, 0x10($sp)
    /* 1AA98 8002A298 04000296 */  lhu        $v0, (0x1F800004 & 0xFFFF)($s0)
    /* 1AA9C 8002A29C 01000624 */  addiu      $a2, $zero, 0x1
    /* 1AAA0 8002A2A0 0A0000A6 */  sh         $zero, (0x1F80000A & 0xFFFF)($s0)
    /* 1AAA4 8002A2A4 4C10020C */  jal        func_80084130
    /* 1AAA8 8002A2A8 080002A6 */   sh        $v0, (0x1F800008 & 0xFFFF)($s0)
    /* 1AAAC 8002A2AC 21200002 */  addu       $a0, $s0, $zero
    /* 1AAB0 8002A2B0 01000624 */  addiu      $a2, $zero, 0x1
    /* 1AAB4 8002A2B4 1000A58F */  lw         $a1, 0x10($sp)
    /* 1AAB8 8002A2B8 F0000224 */  addiu      $v0, $zero, 0xF0
    /* 1AABC 8002A2BC 4C10020C */  jal        func_80084130
    /* 1AAC0 8002A2C0 0A0082A4 */   sh        $v0, (0x1F80000A & 0xFFFF)($a0)
  .L8002A2C4:
    /* 1AAC4 8002A2C4 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 1AAC8 8002A2C8 4800BE8F */  lw         $fp, 0x48($sp)
    /* 1AACC 8002A2CC 4400B78F */  lw         $s7, 0x44($sp)
    /* 1AAD0 8002A2D0 4000B68F */  lw         $s6, 0x40($sp)
    /* 1AAD4 8002A2D4 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 1AAD8 8002A2D8 3800B48F */  lw         $s4, 0x38($sp)
    /* 1AADC 8002A2DC 3400B38F */  lw         $s3, 0x34($sp)
    /* 1AAE0 8002A2E0 3000B28F */  lw         $s2, 0x30($sp)
    /* 1AAE4 8002A2E4 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 1AAE8 8002A2E8 2800B08F */  lw         $s0, 0x28($sp)
    /* 1AAEC 8002A2EC 0800E003 */  jr         $ra
    /* 1AAF0 8002A2F0 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_80029EC4
