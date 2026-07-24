nonmatching func_80019D18, 0x13B4

glabel func_80019D18
    /* A518 80019D18 CD028293 */  lbu        $v0, %gp_rel(D_8009B1D5)($gp)
    /* A51C 80019D1C 32038497 */  lhu        $a0, %gp_rel(D_8009B23A)($gp)
    /* A520 80019D20 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* A524 80019D24 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* A528 80019D28 2800B6AF */  sw         $s6, 0x28($sp)
    /* A52C 80019D2C 2400B5AF */  sw         $s5, 0x24($sp)
    /* A530 80019D30 2000B4AF */  sw         $s4, 0x20($sp)
    /* A534 80019D34 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* A538 80019D38 1800B2AF */  sw         $s2, 0x18($sp)
    /* A53C 80019D3C 1400B1AF */  sw         $s1, 0x14($sp)
    /* A540 80019D40 C0180200 */  sll        $v1, $v0, 3
    /* A544 80019D44 23186200 */  subu       $v1, $v1, $v0
    /* A548 80019D48 00190300 */  sll        $v1, $v1, 4
    /* A54C 80019D4C 0F80023C */  lui        $v0, %hi(D_800E9F10)
    /* A550 80019D50 109F4224 */  addiu      $v0, $v0, %lo(D_800E9F10)
    /* A554 80019D54 21A86200 */  addu       $s5, $v1, $v0
    /* A558 80019D58 00808230 */  andi       $v0, $a0, 0x8000
    /* A55C 80019D5C 75004014 */  bnez       $v0, .L80019F34
    /* A560 80019D60 1000B0AF */   sw        $s0, 0x10($sp)
    /* A564 80019D64 04011324 */  addiu      $s3, $zero, 0x104
    /* A568 80019D68 04001024 */  addiu      $s0, $zero, 0x4
    /* A56C 80019D6C 05001224 */  addiu      $s2, $zero, 0x5
    /* A570 80019D70 52001624 */  addiu      $s6, $zero, 0x52
    /* A574 80019D74 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* A578 80019D78 F09E4224 */  addiu      $v0, $v0, %lo(D_800E9EF0)
    /* A57C 80019D7C 14005424 */  addiu      $s4, $v0, 0x14
    /* A580 80019D80 00808234 */  ori        $v0, $a0, 0x8000
    /* A584 80019D84 320382A7 */  sh         $v0, %gp_rel(D_8009B23A)($gp)
    /* A588 80019D88 AC0295AF */  sw         $s5, %gp_rel(D_8009B1B4)($gp)
    /* A58C 80019D8C 100380A3 */  sb         $zero, %gp_rel(D_8009B218)($gp)
    /* A590 80019D90 B10280A3 */  sb         $zero, %gp_rel(D_8009B1B9)($gp)
    /* A594 80019D94 4C0280A7 */  sh         $zero, %gp_rel(D_8009B154)($gp)
  .L80019D98:
    /* A598 80019D98 0000918E */  lw         $s1, 0x0($s4)
    /* A59C 80019D9C 00000000 */  nop
    /* A5A0 80019DA0 08002012 */  beqz       $s1, .L80019DC4
    /* A5A4 80019DA4 21202002 */   addu      $a0, $s1, $zero
    /* A5A8 80019DA8 002E1000 */  sll        $a1, $s0, 24
    /* A5AC 80019DAC 032E0500 */  sra        $a1, $a1, 24
    /* A5B0 80019DB0 280093A4 */  sh         $s3, 0x28($a0)
    /* A5B4 80019DB4 3B0A010C */  jal        func_800428EC
    /* A5B8 80019DB8 2A0096A4 */   sh        $s6, 0x2A($a0)
    /* A5BC 80019DBC F0FF7326 */  addiu      $s3, $s3, -0x10
    /* A5C0 80019DC0 01001026 */  addiu      $s0, $s0, 0x1
  .L80019DC4:
    /* A5C4 80019DC4 FFFF5226 */  addiu      $s2, $s2, -0x1
    /* A5C8 80019DC8 F3FF401E */  bgtz       $s2, .L80019D98
    /* A5CC 80019DCC FCFF9426 */   addiu     $s4, $s4, -0x4
    /* A5D0 80019DD0 0F80123C */  lui        $s2, %hi(D_800E9EF0)
    /* A5D4 80019DD4 002E1000 */  sll        $a1, $s0, 24
    /* A5D8 80019DD8 032E0500 */  sra        $a1, $a1, 24
    /* A5DC 80019DDC F09E518E */  lw         $s1, %lo(D_800E9EF0)($s2)
    /* A5E0 80019DE0 40000224 */  addiu      $v0, $zero, 0x40
    /* A5E4 80019DE4 21202002 */  addu       $a0, $s1, $zero
    /* A5E8 80019DE8 280022A6 */  sh         $v0, 0x28($s1)
    /* A5EC 80019DEC 52000224 */  addiu      $v0, $zero, 0x52
    /* A5F0 80019DF0 3B0A010C */  jal        func_800428EC
    /* A5F4 80019DF4 2A0022A6 */   sh        $v0, 0x2A($s1)
    /* A5F8 80019DF8 6A002392 */  lbu        $v1, 0x6A($s1)
    /* A5FC 80019DFC 8888023C */  lui        $v0, (0x88888889 >> 16)
    /* A600 80019E00 89884234 */  ori        $v0, $v0, (0x88888889 & 0xFFFF)
    /* A604 80019E04 19006200 */  multu      $v1, $v0
    /* A608 80019E08 10480000 */  mfhi       $t1
    /* A60C 80019E0C C2200900 */  srl        $a0, $t1, 3
    /* A610 80019E10 00110400 */  sll        $v0, $a0, 4
    /* A614 80019E14 23104400 */  subu       $v0, $v0, $a0
    /* A618 80019E18 23186200 */  subu       $v1, $v1, $v0
    /* A61C 80019E1C FF006330 */  andi       $v1, $v1, 0xFF
    /* A620 80019E20 0500632C */  sltiu      $v1, $v1, 0x5
    /* A624 80019E24 03006010 */  beqz       $v1, .L80019E34
    /* A628 80019E28 F09E5026 */   addiu     $s0, $s2, %lo(D_800E9EF0)
    /* A62C 80019E2C 01000224 */  addiu      $v0, $zero, 0x1
    /* A630 80019E30 100382A3 */  sb         $v0, %gp_rel(D_8009B218)($gp)
  .L80019E34:
    /* A634 80019E34 0400028E */  lw         $v0, 0x4($s0)
    /* A638 80019E38 00000000 */  nop
    /* A63C 80019E3C 1E004014 */  bnez       $v0, .L80019EB8
    /* A640 80019E40 00000000 */   nop
    /* A644 80019E44 F09E428E */  lw         $v0, %lo(D_800E9EF0)($s2)
    /* A648 80019E48 00000000 */  nop
    /* A64C 80019E4C 68004290 */  lbu        $v0, 0x68($v0)
    /* A650 80019E50 00000000 */  nop
    /* A654 80019E54 1400422C */  sltiu      $v0, $v0, 0x14
    /* A658 80019E58 02004010 */  beqz       $v0, .L80019E64
    /* A65C 80019E5C 01000224 */   addiu     $v0, $zero, 0x1
    /* A660 80019E60 100382A3 */  sb         $v0, %gp_rel(D_8009B218)($gp)
  .L80019E64:
    /* A664 80019E64 0400053C */  lui        $a1, (0x48000 >> 16)
    /* A668 80019E68 0080A534 */  ori        $a1, $a1, (0x48000 & 0xFFFF)
    /* A66C 80019E6C 1680033C */  lui        $v1, %hi(D_8015C424)
    /* A670 80019E70 6A002492 */  lbu        $a0, 0x6A($s1)
    /* A674 80019E74 24C46324 */  addiu      $v1, $v1, %lo(D_8015C424)
    /* A678 80019E78 C0100400 */  sll        $v0, $a0, 3
    /* A67C 80019E7C 23104400 */  subu       $v0, $v0, $a0
    /* A680 80019E80 80100200 */  sll        $v0, $v0, 2
    /* A684 80019E84 21104300 */  addu       $v0, $v0, $v1
    /* A688 80019E88 21104500 */  addu       $v0, $v0, $a1
    /* A68C 80019E8C C0364494 */  lhu        $a0, 0x36C0($v0)
    /* A690 80019E90 86000224 */  addiu      $v0, $zero, 0x86
    /* A694 80019E94 280022A6 */  sh         $v0, 0x28($s1)
    /* A698 80019E98 32038297 */  lhu        $v0, %gp_rel(D_8009B23A)($gp)
    /* A69C 80019E9C 2A000324 */  addiu      $v1, $zero, 0x2A
    /* A6A0 80019EA0 2A0023A6 */  sh         $v1, 0x2A($s1)
    /* A6A4 80019EA4 00404234 */  ori        $v0, $v0, 0x4000
    /* A6A8 80019EA8 320382A7 */  sh         $v0, %gp_rel(D_8009B23A)($gp)
    /* A6AC 80019EAC 480284A7 */  sh         $a0, %gp_rel(D_8009B150)($gp)
    /* A6B0 80019EB0 B5670008 */  j          .L80019ED4
    /* A6B4 80019EB4 21900000 */   addu      $s2, $zero, $zero
  .L80019EB8:
    /* A6B8 80019EB8 C002838F */  lw         $v1, %gp_rel(D_8009B1C8)($gp)
    /* A6BC 80019EBC 00000000 */  nop
    /* A6C0 80019EC0 07006290 */  lbu        $v0, 0x7($v1)
    /* A6C4 80019EC4 00000000 */  nop
    /* A6C8 80019EC8 01004224 */  addiu      $v0, $v0, 0x1
    /* A6CC 80019ECC 070062A0 */  sb         $v0, 0x7($v1)
    /* A6D0 80019ED0 21900000 */  addu       $s2, $zero, $zero
  .L80019ED4:
    /* A6D4 80019ED4 0F80023C */  lui        $v0, %hi(D_800EA030)
    /* A6D8 80019ED8 30A05024 */  addiu      $s0, $v0, %lo(D_800EA030)
  .L80019EDC:
    /* A6DC 80019EDC 09000292 */  lbu        $v0, 0x9($s0)
    /* A6E0 80019EE0 00000000 */  nop
    /* A6E4 80019EE4 05004010 */  beqz       $v0, .L80019EFC
    /* A6E8 80019EE8 00000000 */   nop
    /* A6EC 80019EEC 0400048E */  lw         $a0, 0x4($s0)
    /* A6F0 80019EF0 DB00010C */  jal        func_8004036C
    /* A6F4 80019EF4 000000AE */   sw        $zero, 0x0($s0)
    /* A6F8 80019EF8 040000AE */  sw         $zero, 0x4($s0)
  .L80019EFC:
    /* A6FC 80019EFC 01005226 */  addiu      $s2, $s2, 0x1
    /* A700 80019F00 0500422A */  slti       $v0, $s2, 0x5
    /* A704 80019F04 F5FF4014 */  bnez       $v0, .L80019EDC
    /* A708 80019F08 0C001026 */   addiu     $s0, $s0, 0xC
    /* A70C 80019F0C 0400A48E */  lw         $a0, 0x4($s5)
    /* A710 80019F10 DB00010C */  jal        func_8004036C
    /* A714 80019F14 00000000 */   nop
    /* A718 80019F18 08000224 */  addiu      $v0, $zero, 0x8
    /* A71C 80019F1C 5A0282A7 */  sh         $v0, %gp_rel(D_8009B162)($gp)
    /* A720 80019F20 01000224 */  addiu      $v0, $zero, 0x1
    /* A724 80019F24 0400A0AE */  sw         $zero, 0x4($s5)
    /* A728 80019F28 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* A72C 80019F2C 296C0008 */  j          .L8001B0A4
    /* A730 80019F30 00000000 */   nop
  .L80019F34:
    /* A734 80019F34 6C028293 */  lbu        $v0, %gp_rel(D_8009B174)($gp)
    /* A738 80019F38 00000000 */  nop
    /* A73C 80019F3C 0F004230 */  andi       $v0, $v0, 0xF
    /* A740 80019F40 FFFF4324 */  addiu      $v1, $v0, -0x1
    /* A744 80019F44 0800622C */  sltiu      $v0, $v1, 0x8
    /* A748 80019F48 56044010 */  beqz       $v0, .L8001B0A4
    /* A74C 80019F4C 0180023C */   lui       $v0, %hi(jtbl_800100F8)
    /* A750 80019F50 F8004224 */  addiu      $v0, $v0, %lo(jtbl_800100F8)
    /* A754 80019F54 80180300 */  sll        $v1, $v1, 2
    /* A758 80019F58 21186200 */  addu       $v1, $v1, $v0
    /* A75C 80019F5C 0000628C */  lw         $v0, 0x0($v1)
    /* A760 80019F60 00000000 */  nop
    /* A764 80019F64 08004000 */  jr         $v0
    /* A768 80019F68 00000000 */   nop
  jlabel .L80019F6C
    /* A76C 80019F6C 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* A770 80019F70 00000000 */  nop
    /* A774 80019F74 80006230 */  andi       $v0, $v1, 0x80
    /* A778 80019F78 24004014 */  bnez       $v0, .L8001A00C
    /* A77C 80019F7C 80006334 */   ori       $v1, $v1, 0x80
    /* A780 80019F80 32038297 */  lhu        $v0, %gp_rel(D_8009B23A)($gp)
    /* A784 80019F84 6C0283A3 */  sb         $v1, %gp_rel(D_8009B174)($gp)
    /* A788 80019F88 00404230 */  andi       $v0, $v0, 0x4000
    /* A78C 80019F8C 45044014 */  bnez       $v0, .L8001B0A4
    /* A790 80019F90 05001224 */   addiu     $s2, $zero, 0x5
    /* A794 80019F94 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* A798 80019F98 D87A4724 */  addiu      $a3, $v0, %lo(D_801A7AD8)
    /* A79C 80019F9C 01000624 */  addiu      $a2, $zero, 0x1
    /* A7A0 80019FA0 0280023C */  lui        $v0, %hi(func_80019BD0)
    /* A7A4 80019FA4 D09B4524 */  addiu      $a1, $v0, %lo(func_80019BD0)
    /* A7A8 80019FA8 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* A7AC 80019FAC F09E4224 */  addiu      $v0, $v0, %lo(D_800E9EF0)
    /* A7B0 80019FB0 14004424 */  addiu      $a0, $v0, 0x14
  .L80019FB4:
    /* A7B4 80019FB4 0000918C */  lw         $s1, 0x0($a0)
    /* A7B8 80019FB8 00000000 */  nop
    /* A7BC 80019FBC 0E002012 */  beqz       $s1, .L80019FF8
    /* A7C0 80019FC0 00000000 */   nop
    /* A7C4 80019FC4 6A002292 */  lbu        $v0, 0x6A($s1)
    /* A7C8 80019FC8 00000000 */  nop
    /* A7CC 80019FCC C0180200 */  sll        $v1, $v0, 3
    /* A7D0 80019FD0 23186200 */  subu       $v1, $v1, $v0
    /* A7D4 80019FD4 80180300 */  sll        $v1, $v1, 2
    /* A7D8 80019FD8 21186700 */  addu       $v1, $v1, $a3
    /* A7DC 80019FDC 16006294 */  lhu        $v0, 0x16($v1)
    /* A7E0 80019FE0 00000000 */  nop
    /* A7E4 80019FE4 00204230 */  andi       $v0, $v0, 0x2000
    /* A7E8 80019FE8 03004010 */  beqz       $v0, .L80019FF8
    /* A7EC 80019FEC 00000000 */   nop
    /* A7F0 80019FF0 6C0026A2 */  sb         $a2, 0x6C($s1)
    /* A7F4 80019FF4 240025AE */  sw         $a1, 0x24($s1)
  .L80019FF8:
    /* A7F8 80019FF8 FFFF5226 */  addiu      $s2, $s2, -0x1
    /* A7FC 80019FFC EDFF4106 */  bgez       $s2, .L80019FB4
    /* A800 8001A000 FCFF8424 */   addiu     $a0, $a0, -0x4
    /* A804 8001A004 296C0008 */  j          .L8001B0A4
    /* A808 8001A008 00000000 */   nop
  .L8001A00C:
    /* A80C 8001A00C D00A010C */  jal        func_80042B40
    /* A810 8001A010 01000424 */   addiu     $a0, $zero, 0x1
    /* A814 8001A014 23044014 */  bnez       $v0, .L8001B0A4
    /* A818 8001A018 02000224 */   addiu     $v0, $zero, 0x2
    /* A81C 8001A01C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
  jlabel .L8001A020
    /* A820 8001A020 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* A824 8001A024 00000000 */  nop
    /* A828 8001A028 80006230 */  andi       $v0, $v1, 0x80
    /* A82C 8001A02C 13004014 */  bnez       $v0, .L8001A07C
    /* A830 8001A030 21800000 */   addu      $s0, $zero, $zero
    /* A834 8001A034 80006234 */  ori        $v0, $v1, 0x80
    /* A838 8001A038 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* A83C 8001A03C 05001224 */  addiu      $s2, $zero, 0x5
    /* A840 8001A040 01001324 */  addiu      $s3, $zero, 0x1
    /* A844 8001A044 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* A848 8001A048 F09E4224 */  addiu      $v0, $v0, %lo(D_800E9EF0)
    /* A84C 8001A04C 14005024 */  addiu      $s0, $v0, 0x14
  .L8001A050:
    /* A850 8001A050 0000118E */  lw         $s1, 0x0($s0)
    /* A854 8001A054 00000000 */  nop
    /* A858 8001A058 04002012 */  beqz       $s1, .L8001A06C
    /* A85C 8001A05C 21202002 */   addu      $a0, $s1, $zero
    /* A860 8001A060 5E0C010C */  jal        func_80043178
    /* A864 8001A064 6C0033A2 */   sb        $s3, 0x6C($s1)
    /* A868 8001A068 600020A6 */  sh         $zero, 0x60($s1)
  .L8001A06C:
    /* A86C 8001A06C FFFF5226 */  addiu      $s2, $s2, -0x1
    /* A870 8001A070 F7FF4106 */  bgez       $s2, .L8001A050
    /* A874 8001A074 FCFF1026 */   addiu     $s0, $s0, -0x4
    /* A878 8001A078 21800000 */  addu       $s0, $zero, $zero
  .L8001A07C:
    /* A87C 8001A07C 05001224 */  addiu      $s2, $zero, 0x5
    /* A880 8001A080 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* A884 8001A084 F09E4224 */  addiu      $v0, $v0, %lo(D_800E9EF0)
    /* A888 8001A088 14005324 */  addiu      $s3, $v0, 0x14
  .L8001A08C:
    /* A88C 8001A08C 0000718E */  lw         $s1, 0x0($s3)
    /* A890 8001A090 00000000 */  nop
    /* A894 8001A094 36002012 */  beqz       $s1, .L8001A170
    /* A898 8001A098 00000000 */   nop
    /* A89C 8001A09C 6C002292 */  lbu        $v0, 0x6C($s1)
    /* A8A0 8001A0A0 00000000 */  nop
    /* A8A4 8001A0A4 32004010 */  beqz       $v0, .L8001A170
    /* A8A8 8001A0A8 00000000 */   nop
    /* A8AC 8001A0AC 32038297 */  lhu        $v0, %gp_rel(D_8009B23A)($gp)
    /* A8B0 8001A0B0 00000000 */  nop
    /* A8B4 8001A0B4 00404230 */  andi       $v0, $v0, 0x4000
    /* A8B8 8001A0B8 06004014 */  bnez       $v0, .L8001A0D4
    /* A8BC 8001A0BC 01001024 */   addiu     $s0, $zero, 0x1
    /* A8C0 8001A0C0 21002292 */  lbu        $v0, 0x21($s1)
    /* A8C4 8001A0C4 00000000 */  nop
    /* A8C8 8001A0C8 02004010 */  beqz       $v0, .L8001A0D4
    /* A8CC 8001A0CC 08004224 */   addiu     $v0, $v0, 0x8
    /* A8D0 8001A0D0 210022A2 */  sb         $v0, 0x21($s1)
  .L8001A0D4:
    /* A8D4 8001A0D4 22002292 */  lbu        $v0, 0x22($s1)
    /* A8D8 8001A0D8 00000000 */  nop
    /* A8DC 8001A0DC 02004010 */  beqz       $v0, .L8001A0E8
    /* A8E0 8001A0E0 08004224 */   addiu     $v0, $v0, 0x8
    /* A8E4 8001A0E4 220022A2 */  sb         $v0, 0x22($s1)
  .L8001A0E8:
    /* A8E8 8001A0E8 28002586 */  lh         $a1, 0x28($s1)
    /* A8EC 8001A0EC 2A002686 */  lh         $a2, 0x2A($s1)
    /* A8F0 8001A0F0 60002786 */  lh         $a3, 0x60($s1)
    /* A8F4 8001A0F4 630C010C */  jal        func_8004318C
    /* A8F8 8001A0F8 21202002 */   addu      $a0, $s1, $zero
    /* A8FC 8001A0FC 60002296 */  lhu        $v0, 0x60($s1)
    /* A900 8001A100 00000000 */  nop
    /* A904 8001A104 80004224 */  addiu      $v0, $v0, 0x80
    /* A908 8001A108 600022A6 */  sh         $v0, 0x60($s1)
    /* A90C 8001A10C 00140200 */  sll        $v0, $v0, 16
    /* A910 8001A110 03140200 */  sra        $v0, $v0, 16
    /* A914 8001A114 00084228 */  slti       $v0, $v0, 0x800
    /* A918 8001A118 15004014 */  bnez       $v0, .L8001A170
    /* A91C 8001A11C 00000000 */   nop
    /* A920 8001A120 6C0020A2 */  sb         $zero, 0x6C($s1)
    /* A924 8001A124 220020A2 */  sb         $zero, 0x22($s1)
    /* A928 8001A128 32038297 */  lhu        $v0, %gp_rel(D_8009B23A)($gp)
    /* A92C 8001A12C 00000000 */  nop
    /* A930 8001A130 00404230 */  andi       $v0, $v0, 0x4000
    /* A934 8001A134 02004014 */  bnez       $v0, .L8001A140
    /* A938 8001A138 00000000 */   nop
    /* A93C 8001A13C 210020A2 */  sb         $zero, 0x21($s1)
  .L8001A140:
    /* A940 8001A140 21002292 */  lbu        $v0, 0x21($s1)
    /* A944 8001A144 00000000 */  nop
    /* A948 8001A148 05004014 */  bnez       $v0, .L8001A160
    /* A94C 8001A14C 00000000 */   nop
    /* A950 8001A150 08002296 */  lhu        $v0, 0x8($s1)
    /* A954 8001A154 00000000 */  nop
    /* A958 8001A158 FBFF4230 */  andi       $v0, $v0, 0xFFFB
    /* A95C 8001A15C 080022A6 */  sh         $v0, 0x8($s1)
  .L8001A160:
    /* A960 8001A160 28002296 */  lhu        $v0, 0x28($s1)
    /* A964 8001A164 2A002396 */  lhu        $v1, 0x2A($s1)
    /* A968 8001A168 300022A6 */  sh         $v0, 0x30($s1)
    /* A96C 8001A16C 320023A6 */  sh         $v1, 0x32($s1)
  .L8001A170:
    /* A970 8001A170 FFFF5226 */  addiu      $s2, $s2, -0x1
    /* A974 8001A174 C5FF4106 */  bgez       $s2, .L8001A08C
    /* A978 8001A178 FCFF7326 */   addiu     $s3, $s3, -0x4
    /* A97C 8001A17C 5A028297 */  lhu        $v0, %gp_rel(D_8009B162)($gp)
    /* A980 8001A180 00000000 */  nop
    /* A984 8001A184 25105000 */  or         $v0, $v0, $s0
    /* A988 8001A188 C6034014 */  bnez       $v0, .L8001B0A4
    /* A98C 8001A18C 00000000 */   nop
    /* A990 8001A190 32038297 */  lhu        $v0, %gp_rel(D_8009B23A)($gp)
    /* A994 8001A194 03000324 */  addiu      $v1, $zero, 0x3
    /* A998 8001A198 6C0283A3 */  sb         $v1, %gp_rel(D_8009B174)($gp)
    /* A99C 8001A19C 00404230 */  andi       $v0, $v0, 0x4000
    /* A9A0 8001A1A0 C0034010 */  beqz       $v0, .L8001B0A4
    /* A9A4 8001A1A4 08000224 */   addiu     $v0, $zero, 0x8
    /* A9A8 8001A1A8 286C0008 */  j          .L8001B0A0
    /* A9AC 8001A1AC 00000000 */   nop
  jlabel .L8001A1B0
    /* A9B0 8001A1B0 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* A9B4 8001A1B4 00000000 */  nop
    /* A9B8 8001A1B8 80006230 */  andi       $v0, $v1, 0x80
    /* A9BC 8001A1BC 84004014 */  bnez       $v0, .L8001A3D0
    /* A9C0 8001A1C0 0F80103C */   lui       $s0, %hi(D_800E9EF0)
    /* A9C4 8001A1C4 B1028293 */  lbu        $v0, %gp_rel(D_8009B1B9)($gp)
    /* A9C8 8001A1C8 80006334 */  ori        $v1, $v1, 0x80
    /* A9CC 8001A1CC 6C0283A3 */  sb         $v1, %gp_rel(D_8009B174)($gp)
    /* A9D0 8001A1D0 01004224 */  addiu      $v0, $v0, 0x1
    /* A9D4 8001A1D4 B10282A3 */  sb         $v0, %gp_rel(D_8009B1B9)($gp)
    /* A9D8 8001A1D8 00160200 */  sll        $v0, $v0, 24
    /* A9DC 8001A1DC 031E0200 */  sra        $v1, $v0, 24
    /* A9E0 8001A1E0 06006228 */  slti       $v0, $v1, 0x6
    /* A9E4 8001A1E4 08004010 */  beqz       $v0, .L8001A208
    /* A9E8 8001A1E8 0F80133C */   lui       $s3, %hi(D_800E9EF0)
    /* A9EC 8001A1EC F09E6526 */  addiu      $a1, $s3, %lo(D_800E9EF0)
    /* A9F0 8001A1F0 80100300 */  sll        $v0, $v1, 2
    /* A9F4 8001A1F4 21104500 */  addu       $v0, $v0, $a1
    /* A9F8 8001A1F8 0000428C */  lw         $v0, 0x0($v0)
    /* A9FC 8001A1FC 00000000 */  nop
    /* AA00 8001A200 05004014 */  bnez       $v0, .L8001A218
    /* AA04 8001A204 21884000 */   addu      $s1, $v0, $zero
  .L8001A208:
    /* AA08 8001A208 08000224 */  addiu      $v0, $zero, 0x8
    /* AA0C 8001A20C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* AA10 8001A210 296C0008 */  j          .L8001B0A4
    /* AA14 8001A214 00000000 */   nop
  .L8001A218:
    /* AA18 8001A218 21202002 */  addu       $a0, $s1, $zero
    /* AA1C 8001A21C 760A010C */  jal        func_800429D8
    /* AA20 8001A220 0400B1AC */   sw        $s1, 0x4($a1)
    /* AA24 8001A224 30002386 */  lh         $v1, 0x30($s1)
    /* AA28 8001A228 08000224 */  addiu      $v0, $zero, 0x8
    /* AA2C 8001A22C 600022A6 */  sh         $v0, 0x60($s1)
    /* AA30 8001A230 40000224 */  addiu      $v0, $zero, 0x40
    /* AA34 8001A234 23104300 */  subu       $v0, $v0, $v1
    /* AA38 8001A238 00120200 */  sll        $v0, $v0, 8
    /* AA3C 8001A23C 02004104 */  bgez       $v0, .L8001A248
    /* AA40 8001A240 00000000 */   nop
    /* AA44 8001A244 07004224 */  addiu      $v0, $v0, 0x7
  .L8001A248:
    /* AA48 8001A248 32002386 */  lh         $v1, 0x32($s1)
    /* AA4C 8001A24C C3100200 */  sra        $v0, $v0, 3
    /* AA50 8001A250 360022A6 */  sh         $v0, 0x36($s1)
    /* AA54 8001A254 52000224 */  addiu      $v0, $zero, 0x52
    /* AA58 8001A258 23104300 */  subu       $v0, $v0, $v1
    /* AA5C 8001A25C 00120200 */  sll        $v0, $v0, 8
    /* AA60 8001A260 02004104 */  bgez       $v0, .L8001A26C
    /* AA64 8001A264 00000000 */   nop
    /* AA68 8001A268 07004224 */  addiu      $v0, $v0, 0x7
  .L8001A26C:
    /* AA6C 8001A26C 16002592 */  lbu        $a1, 0x16($s1)
    /* AA70 8001A270 C3100200 */  sra        $v0, $v0, 3
    /* AA74 8001A274 380022A6 */  sh         $v0, 0x38($s1)
    /* AA78 8001A278 F09E648E */  lw         $a0, %lo(D_800E9EF0)($s3)
    /* AA7C 8001A27C FFFFA524 */  addiu      $a1, $a1, -0x1
    /* AA80 8001A280 002E0500 */  sll        $a1, $a1, 24
    /* AA84 8001A284 3B0A010C */  jal        func_800428EC
    /* AA88 8001A288 032E0500 */   sra       $a1, $a1, 24
    /* AA8C 8001A28C B8FF000C */  jal        func_8003FEE0
    /* AA90 8001A290 0A000424 */   addiu     $a0, $zero, 0xA
    /* AA94 8001A294 F09E638E */  lw         $v1, %lo(D_800E9EF0)($s3)
    /* AA98 8001A298 480280A7 */  sh         $zero, %gp_rel(D_8009B150)($gp)
    /* AA9C 8001A29C 81036010 */  beqz       $v1, .L8001B0A4
    /* AAA0 8001A2A0 0400103C */   lui       $s0, (0x48000 >> 16)
    /* AAA4 8001A2A4 00801036 */  ori        $s0, $s0, (0x48000 & 0xFFFF)
    /* AAA8 8001A2A8 1680023C */  lui        $v0, %hi(D_8015C424)
    /* AAAC 8001A2AC 6A006390 */  lbu        $v1, 0x6A($v1)
    /* AAB0 8001A2B0 24C45224 */  addiu      $s2, $v0, %lo(D_8015C424)
    /* AAB4 8001A2B4 C0100300 */  sll        $v0, $v1, 3
    /* AAB8 8001A2B8 23104300 */  subu       $v0, $v0, $v1
    /* AABC 8001A2BC 80100200 */  sll        $v0, $v0, 2
    /* AAC0 8001A2C0 21105200 */  addu       $v0, $v0, $s2
    /* AAC4 8001A2C4 21105000 */  addu       $v0, $v0, $s0
    /* AAC8 8001A2C8 6A002392 */  lbu        $v1, 0x6A($s1)
    /* AACC 8001A2CC C0364484 */  lh         $a0, 0x36C0($v0)
    /* AAD0 8001A2D0 C0100300 */  sll        $v0, $v1, 3
    /* AAD4 8001A2D4 23104300 */  subu       $v0, $v0, $v1
    /* AAD8 8001A2D8 80100200 */  sll        $v0, $v0, 2
    /* AADC 8001A2DC 21105200 */  addu       $v0, $v0, $s2
    /* AAE0 8001A2E0 21105000 */  addu       $v0, $v0, $s0
    /* AAE4 8001A2E4 C0364584 */  lh         $a1, 0x36C0($v0)
    /* AAE8 8001A2E8 9866000C */  jal        func_80019A60
    /* AAEC 8001A2EC 00000000 */   nop
    /* AAF0 8001A2F0 21184000 */  addu       $v1, $v0, $zero
    /* AAF4 8001A2F4 00140300 */  sll        $v0, $v1, 16
    /* AAF8 8001A2F8 480283A7 */  sh         $v1, %gp_rel(D_8009B150)($gp)
    /* AAFC 8001A2FC 29004014 */  bnez       $v0, .L8001A3A4
    /* AB00 8001A300 00806234 */   ori       $v0, $v1, 0x8000
    /* AB04 8001A304 6A002392 */  lbu        $v1, 0x6A($s1)
    /* AB08 8001A308 00000000 */  nop
    /* AB0C 8001A30C C0100300 */  sll        $v0, $v1, 3
    /* AB10 8001A310 23104300 */  subu       $v0, $v0, $v1
    /* AB14 8001A314 80100200 */  sll        $v0, $v0, 2
    /* AB18 8001A318 21105200 */  addu       $v0, $v0, $s2
    /* AB1C 8001A31C F09E638E */  lw         $v1, %lo(D_800E9EF0)($s3)
    /* AB20 8001A320 21105000 */  addu       $v0, $v0, $s0
    /* AB24 8001A324 6A006390 */  lbu        $v1, 0x6A($v1)
    /* AB28 8001A328 C0364484 */  lh         $a0, 0x36C0($v0)
    /* AB2C 8001A32C C0100300 */  sll        $v0, $v1, 3
    /* AB30 8001A330 23104300 */  subu       $v0, $v0, $v1
    /* AB34 8001A334 80100200 */  sll        $v0, $v0, 2
    /* AB38 8001A338 21105200 */  addu       $v0, $v0, $s2
    /* AB3C 8001A33C 21105000 */  addu       $v0, $v0, $s0
    /* AB40 8001A340 C0364584 */  lh         $a1, 0x36C0($v0)
    /* AB44 8001A344 8266000C */  jal        func_80019A08
    /* AB48 8001A348 00000000 */   nop
    /* AB4C 8001A34C 480282A7 */  sh         $v0, %gp_rel(D_8009B150)($gp)
    /* AB50 8001A350 00140200 */  sll        $v0, $v0, 16
    /* AB54 8001A354 18004014 */  bnez       $v0, .L8001A3B8
    /* AB58 8001A358 00000000 */   nop
    /* AB5C 8001A35C 6A002392 */  lbu        $v1, 0x6A($s1)
    /* AB60 8001A360 00000000 */  nop
    /* AB64 8001A364 C0100300 */  sll        $v0, $v1, 3
    /* AB68 8001A368 23104300 */  subu       $v0, $v0, $v1
    /* AB6C 8001A36C 80100200 */  sll        $v0, $v0, 2
    /* AB70 8001A370 21105200 */  addu       $v0, $v0, $s2
    /* AB74 8001A374 F09E638E */  lw         $v1, %lo(D_800E9EF0)($s3)
    /* AB78 8001A378 21105000 */  addu       $v0, $v0, $s0
    /* AB7C 8001A37C 6A006390 */  lbu        $v1, 0x6A($v1)
    /* AB80 8001A380 C0364584 */  lh         $a1, 0x36C0($v0)
    /* AB84 8001A384 C0100300 */  sll        $v0, $v1, 3
    /* AB88 8001A388 23104300 */  subu       $v0, $v0, $v1
    /* AB8C 8001A38C 80100200 */  sll        $v0, $v0, 2
    /* AB90 8001A390 21105200 */  addu       $v0, $v0, $s2
    /* AB94 8001A394 21105000 */  addu       $v0, $v0, $s0
    /* AB98 8001A398 C0364484 */  lh         $a0, 0x36C0($v0)
    /* AB9C 8001A39C 8266000C */  jal        func_80019A08
    /* ABA0 8001A3A0 00000000 */   nop
  .L8001A3A4:
    /* ABA4 8001A3A4 480282A7 */  sh         $v0, %gp_rel(D_8009B150)($gp)
    /* ABA8 8001A3A8 48028287 */  lh         $v0, %gp_rel(D_8009B150)($gp)
    /* ABAC 8001A3AC 00000000 */  nop
    /* ABB0 8001A3B0 3C034010 */  beqz       $v0, .L8001B0A4
    /* ABB4 8001A3B4 00000000 */   nop
  .L8001A3B8:
    /* ABB8 8001A3B8 48028597 */  lhu        $a1, %gp_rel(D_8009B150)($gp)
    /* ABBC 8001A3BC 21200000 */  addu       $a0, $zero, $zero
    /* ABC0 8001A3C0 59A4000C */  jal        func_80029164
    /* ABC4 8001A3C4 FF0FA530 */   andi      $a1, $a1, 0xFFF
    /* ABC8 8001A3C8 296C0008 */  j          .L8001B0A4
    /* ABCC 8001A3CC 00000000 */   nop
  .L8001A3D0:
    /* ABD0 8001A3D0 F09E0226 */  addiu      $v0, $s0, %lo(D_800E9EF0)
    /* ABD4 8001A3D4 0400518C */  lw         $s1, 0x4($v0)
    /* ABD8 8001A3D8 800A010C */  jal        func_80042A00
    /* ABDC 8001A3DC 21202002 */   addu      $a0, $s1, $zero
    /* ABE0 8001A3E0 60002296 */  lhu        $v0, 0x60($s1)
    /* ABE4 8001A3E4 00000000 */  nop
    /* ABE8 8001A3E8 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* ABEC 8001A3EC 600022A6 */  sh         $v0, 0x60($s1)
    /* ABF0 8001A3F0 00140200 */  sll        $v0, $v0, 16
    /* ABF4 8001A3F4 2B034014 */  bnez       $v0, .L8001B0A4
    /* ABF8 8001A3F8 00000000 */   nop
    /* ABFC 8001A3FC F09E028E */  lw         $v0, %lo(D_800E9EF0)($s0)
    /* AC00 8001A400 080380A7 */  sh         $zero, %gp_rel(D_8009B210)($gp)
    /* AC04 8001A404 06004014 */  bnez       $v0, .L8001A420
    /* AC08 8001A408 00000000 */   nop
    /* AC0C 8001A40C 03000224 */  addiu      $v0, $zero, 0x3
    /* AC10 8001A410 F09E11AE */  sw         $s1, %lo(D_800E9EF0)($s0)
    /* AC14 8001A414 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* AC18 8001A418 296C0008 */  j          .L8001B0A4
    /* AC1C 8001A41C 00000000 */   nop
  .L8001A420:
    /* AC20 8001A420 3000428C */  lw         $v0, 0x30($v0)
    /* AC24 8001A424 00000000 */  nop
    /* AC28 8001A428 300022AE */  sw         $v0, 0x30($s1)
    /* AC2C 8001A42C 48028287 */  lh         $v0, %gp_rel(D_8009B150)($gp)
    /* AC30 8001A430 00000000 */  nop
    /* AC34 8001A434 07004014 */  bnez       $v0, .L8001A454
    /* AC38 8001A438 00804230 */   andi      $v0, $v0, 0x8000
    /* AC3C 8001A43C 07000224 */  addiu      $v0, $zero, 0x7
    /* AC40 8001A440 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* AC44 8001A444 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* AC48 8001A448 100382A3 */  sb         $v0, %gp_rel(D_8009B218)($gp)
    /* AC4C 8001A44C 296C0008 */  j          .L8001B0A4
    /* AC50 8001A450 00000000 */   nop
  .L8001A454:
    /* AC54 8001A454 0B004010 */  beqz       $v0, .L8001A484
    /* AC58 8001A458 01000224 */   addiu     $v0, $zero, 0x1
    /* AC5C 8001A45C C002838F */  lw         $v1, %gp_rel(D_8009B1C8)($gp)
    /* AC60 8001A460 100382A3 */  sb         $v0, %gp_rel(D_8009B218)($gp)
    /* AC64 8001A464 06000224 */  addiu      $v0, $zero, 0x6
    /* AC68 8001A468 4C0280A7 */  sh         $zero, %gp_rel(D_8009B154)($gp)
    /* AC6C 8001A46C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* AC70 8001A470 08006290 */  lbu        $v0, 0x8($v1)
    /* AC74 8001A474 00000000 */  nop
    /* AC78 8001A478 01004224 */  addiu      $v0, $v0, 0x1
    /* AC7C 8001A47C 296C0008 */  j          .L8001B0A4
    /* AC80 8001A480 080062A0 */   sb        $v0, 0x8($v1)
  .L8001A484:
    /* AC84 8001A484 05000224 */  addiu      $v0, $zero, 0x5
    /* AC88 8001A488 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* AC8C 8001A48C 4C028297 */  lhu        $v0, %gp_rel(D_8009B154)($gp)
    /* AC90 8001A490 C002838F */  lw         $v1, %gp_rel(D_8009B1C8)($gp)
    /* AC94 8001A494 F4014224 */  addiu      $v0, $v0, 0x1F4
    /* AC98 8001A498 4C0282A7 */  sh         $v0, %gp_rel(D_8009B154)($gp)
    /* AC9C 8001A49C 09006290 */  lbu        $v0, 0x9($v1)
    /* ACA0 8001A4A0 00000000 */  nop
    /* ACA4 8001A4A4 01004224 */  addiu      $v0, $v0, 0x1
    /* ACA8 8001A4A8 296C0008 */  j          .L8001B0A4
    /* ACAC 8001A4AC 090062A0 */   sb        $v0, 0x9($v1)
  jlabel .L8001A4B0
    /* ACB0 8001A4B0 0002023C */  lui        $v0, (0x2000030 >> 16)
    /* ACB4 8001A4B4 30004234 */  ori        $v0, $v0, (0x2000030 & 0xFFFF)
    /* ACB8 8001A4B8 0A80033C */  lui        $v1, %hi(D_8009B0F4)
    /* ACBC 8001A4BC F4B0638C */  lw         $v1, %lo(D_8009B0F4)($v1)
    /* ACC0 8001A4C0 0A80043C */  lui        $a0, %hi(D_8009B134)
    /* ACC4 8001A4C4 34B1848C */  lw         $a0, %lo(D_8009B134)($a0)
    /* ACC8 8001A4C8 24186200 */  and        $v1, $v1, $v0
    /* ACCC 8001A4CC 25186400 */  or         $v1, $v1, $a0
    /* ACD0 8001A4D0 F4026014 */  bnez       $v1, .L8001B0A4
    /* ACD4 8001A4D4 00000000 */   nop
    /* ACD8 8001A4D8 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* ACDC 8001A4DC 00000000 */  nop
    /* ACE0 8001A4E0 80006230 */  andi       $v0, $v1, 0x80
    /* ACE4 8001A4E4 05004014 */  bnez       $v0, .L8001A4FC
    /* ACE8 8001A4E8 80006234 */   ori       $v0, $v1, 0x80
    /* ACEC 8001A4EC 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* ACF0 8001A4F0 080380A7 */  sh         $zero, %gp_rel(D_8009B210)($gp)
    /* ACF4 8001A4F4 296C0008 */  j          .L8001B0A4
    /* ACF8 8001A4F8 00000000 */   nop
  .L8001A4FC:
    /* ACFC 8001A4FC 08038297 */  lhu        $v0, %gp_rel(D_8009B210)($gp)
    /* AD00 8001A500 00000000 */  nop
    /* AD04 8001A504 0F004330 */  andi       $v1, $v0, 0xF
    /* AD08 8001A508 0500622C */  sltiu      $v0, $v1, 0x5
    /* AD0C 8001A50C E5024010 */  beqz       $v0, .L8001B0A4
    /* AD10 8001A510 0180023C */   lui       $v0, %hi(jtbl_80010118)
    /* AD14 8001A514 18014224 */  addiu      $v0, $v0, %lo(jtbl_80010118)
    /* AD18 8001A518 80180300 */  sll        $v1, $v1, 2
    /* AD1C 8001A51C 21186200 */  addu       $v1, $v1, $v0
    /* AD20 8001A520 0000628C */  lw         $v0, 0x0($v1)
    /* AD24 8001A524 00000000 */  nop
    /* AD28 8001A528 08004000 */  jr         $v0
    /* AD2C 8001A52C 00000000 */   nop
  jlabel .L8001A530
    /* AD30 8001A530 0F80133C */  lui        $s3, %hi(D_800E9EF0)
    /* AD34 8001A534 F09E628E */  lw         $v0, %lo(D_800E9EF0)($s3)
    /* AD38 8001A538 08038697 */  lhu        $a2, %gp_rel(D_8009B210)($gp)
    /* AD3C 8001A53C 6A004490 */  lbu        $a0, 0x6A($v0)
    /* AD40 8001A540 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* AD44 8001A544 D87A4224 */  addiu      $v0, $v0, %lo(D_801A7AD8)
    /* AD48 8001A548 C0180400 */  sll        $v1, $a0, 3
    /* AD4C 8001A54C 23186400 */  subu       $v1, $v1, $a0
    /* AD50 8001A550 80180300 */  sll        $v1, $v1, 2
    /* AD54 8001A554 21906200 */  addu       $s2, $v1, $v0
    /* AD58 8001A558 0F80023C */  lui        $v0, %hi(D_800EA0E8)
    /* AD5C 8001A55C E8A04724 */  addiu      $a3, $v0, %lo(D_800EA0E8)
    /* AD60 8001A560 8000C230 */  andi       $v0, $a2, 0x80
    /* AD64 8001A564 24004014 */  bnez       $v0, .L8001A5F8
    /* AD68 8001A568 F09E7426 */   addiu     $s4, $s3, %lo(D_800E9EF0)
    /* AD6C 8001A56C 48028387 */  lh         $v1, %gp_rel(D_8009B150)($gp)
    /* AD70 8001A570 48028597 */  lhu        $a1, %gp_rel(D_8009B150)($gp)
    /* AD74 8001A574 8000C234 */  ori        $v0, $a2, 0x80
    /* AD78 8001A578 080382A7 */  sh         $v0, %gp_rel(D_8009B210)($gp)
    /* AD7C 8001A57C 00806330 */  andi       $v1, $v1, 0x8000
    /* AD80 8001A580 C8026010 */  beqz       $v1, .L8001B0A4
    /* AD84 8001A584 0800E424 */   addiu     $a0, $a3, 0x8
    /* AD88 8001A588 0400428E */  lw         $v0, 0x4($s2)
    /* AD8C 8001A58C FF0FA330 */  andi       $v1, $a1, 0xFFF
    /* AD90 8001A590 000043A4 */  sh         $v1, 0x0($v0)
    /* AD94 8001A594 0400458E */  lw         $a1, 0x4($s2)
    /* AD98 8001A598 C000C234 */  ori        $v0, $a2, 0xC0
    /* AD9C 8001A59C 080382A7 */  sh         $v0, %gp_rel(D_8009B210)($gp)
    /* ADA0 8001A5A0 0C0043A6 */  sh         $v1, 0xC($s2)
    /* ADA4 8001A5A4 2800E294 */  lhu        $v0, 0x28($a3)
    /* ADA8 8001A5A8 2A00E394 */  lhu        $v1, 0x2A($a3)
    /* ADAC 8001A5AC 0300B090 */  lbu        $s0, 0x3($a1)
    /* ADB0 8001A5B0 38004224 */  addiu      $v0, $v0, 0x38
    /* ADB4 8001A5B4 0800E2A4 */  sh         $v0, 0x8($a3)
    /* ADB8 8001A5B8 08000224 */  addiu      $v0, $zero, 0x8
    /* ADBC 8001A5BC 0C00E2A4 */  sh         $v0, 0xC($a3)
    /* ADC0 8001A5C0 58000224 */  addiu      $v0, $zero, 0x58
    /* ADC4 8001A5C4 0E00E2A4 */  sh         $v0, 0xE($a3)
    /* ADC8 8001A5C8 1980023C */  lui        $v0, %hi(D_8018C2D8)
    /* ADCC 8001A5CC D8C24224 */  addiu      $v0, $v0, %lo(D_8018C2D8)
    /* ADD0 8001A5D0 0A00E3A4 */  sh         $v1, 0xA($a3)
    /* ADD4 8001A5D4 40281000 */  sll        $a1, $s0, 1
    /* ADD8 8001A5D8 2128B000 */  addu       $a1, $a1, $s0
    /* ADDC 8001A5DC 80280500 */  sll        $a1, $a1, 2
    /* ADE0 8001A5E0 2328B000 */  subu       $a1, $a1, $s0
    /* ADE4 8001A5E4 C0290500 */  sll        $a1, $a1, 7
    /* ADE8 8001A5E8 B507020C */  jal        func_80081ED4
    /* ADEC 8001A5EC 2128A200 */   addu      $a1, $a1, $v0
    /* ADF0 8001A5F0 296C0008 */  j          .L8001B0A4
    /* ADF4 8001A5F4 00000000 */   nop
  .L8001A5F8:
    /* ADF8 8001A5F8 4000C230 */  andi       $v0, $a2, 0x40
    /* ADFC 8001A5FC 08004010 */  beqz       $v0, .L8001A620
    /* AE00 8001A600 00000000 */   nop
    /* AE04 8001A604 0400428E */  lw         $v0, 0x4($s2)
    /* AE08 8001A608 00000000 */  nop
    /* AE0C 8001A60C 02004580 */  lb         $a1, 0x2($v0)
    /* AE10 8001A610 7892000C */  jal        func_800249E0
    /* AE14 8001A614 00000000 */   nop
    /* AE18 8001A618 5592000C */  jal        func_80024954
    /* AE1C 8001A61C 21204002 */   addu      $a0, $s2, $zero
  .L8001A620:
    /* AE20 8001A620 325C000C */  jal        func_800170C8
    /* AE24 8001A624 21204002 */   addu      $a0, $s2, $zero
    /* AE28 8001A628 21804000 */  addu       $s0, $v0, $zero
    /* AE2C 8001A62C 21200000 */  addu       $a0, $zero, $zero
    /* AE30 8001A630 FFFF0532 */  andi       $a1, $s0, 0xFFFF
    /* AE34 8001A634 78A4000C */  jal        func_800291E0
    /* AE38 8001A638 03341000 */   sra       $a2, $s0, 16
    /* AE3C 8001A63C 21884000 */  addu       $s1, $v0, $zero
    /* AE40 8001A640 21280000 */  addu       $a1, $zero, $zero
    /* AE44 8001A644 40000624 */  addiu      $a2, $zero, 0x40
    /* AE48 8001A648 10000224 */  addiu      $v0, $zero, 0x10
    /* AE4C 8001A64C 320022A6 */  sh         $v0, 0x32($s1)
    /* AE50 8001A650 F09E638E */  lw         $v1, %lo(D_800E9EF0)($s3)
    /* AE54 8001A654 08002296 */  lhu        $v0, 0x8($s1)
    /* AE58 8001A658 30006394 */  lhu        $v1, 0x30($v1)
    /* AE5C 8001A65C BFFF4230 */  andi       $v0, $v0, 0xFFBF
    /* AE60 8001A660 080022A6 */  sh         $v0, 0x8($s1)
    /* AE64 8001A664 D4FF6324 */  addiu      $v1, $v1, -0x2C
    /* AE68 8001A668 300023A6 */  sh         $v1, 0x30($s1)
    /* AE6C 8001A66C F09E648E */  lw         $a0, %lo(D_800E9EF0)($s3)
    /* AE70 8001A670 B80291AF */  sw         $s1, %gp_rel(D_8009B1C0)($gp)
    /* AE74 8001A674 E866000C */  jal        func_80019BA0
    /* AE78 8001A678 08000724 */   addiu     $a3, $zero, 0x8
    /* AE7C 8001A67C 0400838E */  lw         $v1, 0x4($s4)
    /* AE80 8001A680 00000000 */  nop
    /* AE84 8001A684 10006010 */  beqz       $v1, .L8001A6C8
    /* AE88 8001A688 21280000 */   addu      $a1, $zero, $zero
    /* AE8C 8001A68C 40000624 */  addiu      $a2, $zero, 0x40
    /* AE90 8001A690 F09E628E */  lw         $v0, %lo(D_800E9EF0)($s3)
    /* AE94 8001A694 30006384 */  lh         $v1, 0x30($v1)
    /* AE98 8001A698 30004284 */  lh         $v0, 0x30($v0)
    /* AE9C 8001A69C 34006324 */  addiu      $v1, $v1, 0x34
    /* AEA0 8001A6A0 21104300 */  addu       $v0, $v0, $v1
    /* AEA4 8001A6A4 C21F0200 */  srl        $v1, $v0, 31
    /* AEA8 8001A6A8 21104300 */  addu       $v0, $v0, $v1
    /* AEAC 8001A6AC 43100200 */  sra        $v0, $v0, 1
    /* AEB0 8001A6B0 B802838F */  lw         $v1, %gp_rel(D_8009B1C0)($gp)
    /* AEB4 8001A6B4 BAFF4224 */  addiu      $v0, $v0, -0x46
    /* AEB8 8001A6B8 300062A4 */  sh         $v0, 0x30($v1)
    /* AEBC 8001A6BC 0400848E */  lw         $a0, 0x4($s4)
    /* AEC0 8001A6C0 E866000C */  jal        func_80019BA0
    /* AEC4 8001A6C4 08000724 */   addiu     $a3, $zero, 0x8
  .L8001A6C8:
    /* AEC8 8001A6C8 01000224 */  addiu      $v0, $zero, 0x1
    /* AECC 8001A6CC 080382A7 */  sh         $v0, %gp_rel(D_8009B210)($gp)
    /* AED0 8001A6D0 296C0008 */  j          .L8001B0A4
    /* AED4 8001A6D4 00000000 */   nop
  jlabel .L8001A6D8
    /* AED8 8001A6D8 D00A010C */  jal        func_80042B40
    /* AEDC 8001A6DC 01000424 */   addiu     $a0, $zero, 0x1
    /* AEE0 8001A6E0 70024014 */  bnez       $v0, .L8001B0A4
    /* AEE4 8001A6E4 00000000 */   nop
    /* AEE8 8001A6E8 08038597 */  lhu        $a1, %gp_rel(D_8009B210)($gp)
    /* AEEC 8001A6EC 00000000 */  nop
    /* AEF0 8001A6F0 8000A230 */  andi       $v0, $a1, 0x80
    /* AEF4 8001A6F4 1A004014 */  bnez       $v0, .L8001A760
    /* AEF8 8001A6F8 0F80033C */   lui       $v1, %hi(D_800E9EF0)
    /* AEFC 8001A6FC F09E648C */  lw         $a0, %lo(D_800E9EF0)($v1)
    /* AF00 8001A700 00000000 */  nop
    /* AF04 8001A704 08008294 */  lhu        $v0, 0x8($a0)
    /* AF08 8001A708 F09E6324 */  addiu      $v1, $v1, %lo(D_800E9EF0)
    /* AF0C 8001A70C BFFF4230 */  andi       $v0, $v0, 0xFFBF
    /* AF10 8001A710 080082A4 */  sh         $v0, 0x8($a0)
    /* AF14 8001A714 0400638C */  lw         $v1, 0x4($v1)
    /* AF18 8001A718 8000A234 */  ori        $v0, $a1, 0x80
    /* AF1C 8001A71C 080382A7 */  sh         $v0, %gp_rel(D_8009B210)($gp)
    /* AF20 8001A720 05006010 */  beqz       $v1, .L8001A738
    /* AF24 8001A724 00000000 */   nop
    /* AF28 8001A728 08006294 */  lhu        $v0, 0x8($v1)
    /* AF2C 8001A72C 00000000 */  nop
    /* AF30 8001A730 BFFF4230 */  andi       $v0, $v0, 0xFFBF
    /* AF34 8001A734 080062A4 */  sh         $v0, 0x8($v1)
  .L8001A738:
    /* AF38 8001A738 B802838F */  lw         $v1, %gp_rel(D_8009B1C0)($gp)
    /* AF3C 8001A73C C0000224 */  addiu      $v0, $zero, 0xC0
    /* AF40 8001A740 210062A0 */  sb         $v0, 0x21($v1)
    /* AF44 8001A744 B802838F */  lw         $v1, %gp_rel(D_8009B1C0)($gp)
    /* AF48 8001A748 00000000 */  nop
    /* AF4C 8001A74C 08006294 */  lhu        $v0, 0x8($v1)
    /* AF50 8001A750 00000000 */  nop
    /* AF54 8001A754 44004234 */  ori        $v0, $v0, 0x44
    /* AF58 8001A758 296C0008 */  j          .L8001B0A4
    /* AF5C 8001A75C 080062A4 */   sh        $v0, 0x8($v1)
  .L8001A760:
    /* AF60 8001A760 B802838F */  lw         $v1, %gp_rel(D_8009B1C0)($gp)
    /* AF64 8001A764 00000000 */  nop
    /* AF68 8001A768 21006290 */  lbu        $v0, 0x21($v1)
    /* AF6C 8001A76C 00000000 */  nop
    /* AF70 8001A770 08004224 */  addiu      $v0, $v0, 0x8
    /* AF74 8001A774 210062A0 */  sb         $v0, 0x21($v1)
    /* AF78 8001A778 00160200 */  sll        $v0, $v0, 24
    /* AF7C 8001A77C 49024004 */  bltz       $v0, .L8001B0A4
    /* AF80 8001A780 02000424 */   addiu     $a0, $zero, 0x2
    /* AF84 8001A784 B802828F */  lw         $v0, %gp_rel(D_8009B1C0)($gp)
    /* AF88 8001A788 00000000 */  nop
    /* AF8C 8001A78C 08004394 */  lhu        $v1, 0x8($v0)
    /* AF90 8001A790 210040A0 */  sb         $zero, 0x21($v0)
    /* AF94 8001A794 080384A7 */  sh         $a0, %gp_rel(D_8009B210)($gp)
    /* AF98 8001A798 FBFF6330 */  andi       $v1, $v1, 0xFFFB
    /* AF9C 8001A79C 296C0008 */  j          .L8001B0A4
    /* AFA0 8001A7A0 080043A4 */   sh        $v1, 0x8($v0)
  jlabel .L8001A7A4
    /* AFA4 8001A7A4 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* AFA8 8001A7A8 F09E428C */  lw         $v0, %lo(D_800E9EF0)($v0)
    /* AFAC 8001A7AC B802918F */  lw         $s1, %gp_rel(D_8009B1C0)($gp)
    /* AFB0 8001A7B0 6A004290 */  lbu        $v0, 0x6A($v0)
    /* AFB4 8001A7B4 08038497 */  lhu        $a0, %gp_rel(D_8009B210)($gp)
    /* AFB8 8001A7B8 C0180200 */  sll        $v1, $v0, 3
    /* AFBC 8001A7BC 23186200 */  subu       $v1, $v1, $v0
    /* AFC0 8001A7C0 80180300 */  sll        $v1, $v1, 2
    /* AFC4 8001A7C4 1A80023C */  lui        $v0, %hi(D_801A7AD8)
    /* AFC8 8001A7C8 D87A4224 */  addiu      $v0, $v0, %lo(D_801A7AD8)
    /* AFCC 8001A7CC 21906200 */  addu       $s2, $v1, $v0
    /* AFD0 8001A7D0 80008230 */  andi       $v0, $a0, 0x80
    /* AFD4 8001A7D4 1A004014 */  bnez       $v0, .L8001A840
    /* AFD8 8001A7D8 40008230 */   andi      $v0, $a0, 0x40
    /* AFDC 8001A7DC 80008234 */  ori        $v0, $a0, 0x80
    /* AFE0 8001A7E0 080382A7 */  sh         $v0, %gp_rel(D_8009B210)($gp)
    /* AFE4 8001A7E4 48028287 */  lh         $v0, %gp_rel(D_8009B150)($gp)
    /* AFE8 8001A7E8 1E000324 */  addiu      $v1, $zero, 0x1E
    /* AFEC 8001A7EC 00804230 */  andi       $v0, $v0, 0x8000
    /* AFF0 8001A7F0 10004014 */  bnez       $v0, .L8001A834
    /* AFF4 8001A7F4 600023A6 */   sh        $v1, 0x60($s1)
    /* AFF8 8001A7F8 F4010224 */  addiu      $v0, $zero, 0x1F4
    /* AFFC 8001A7FC 280020A6 */  sh         $zero, 0x28($s1)
    /* B000 8001A800 2A0022A6 */  sh         $v0, 0x2A($s1)
    /* B004 8001A804 12004396 */  lhu        $v1, 0x12($s2)
    /* B008 8001A808 C0008234 */  ori        $v0, $a0, 0xC0
    /* B00C 8001A80C 080382A7 */  sh         $v0, %gp_rel(D_8009B210)($gp)
    /* B010 8001A810 2C0023A6 */  sh         $v1, 0x2C($s1)
    /* B014 8001A814 FE028387 */  lh         $v1, %gp_rel(D_8009B206)($gp)
    /* B018 8001A818 91020224 */  addiu      $v0, $zero, 0x291
    /* B01C 8001A81C 05006214 */  bne        $v1, $v0, .L8001A834
    /* B020 8001A820 E8030324 */   addiu     $v1, $zero, 0x3E8
    /* B024 8001A824 4C028297 */  lhu        $v0, %gp_rel(D_8009B154)($gp)
    /* B028 8001A828 2A0023A6 */  sh         $v1, 0x2A($s1)
    /* B02C 8001A82C F4014224 */  addiu      $v0, $v0, 0x1F4
    /* B030 8001A830 4C0282A7 */  sh         $v0, %gp_rel(D_8009B154)($gp)
  .L8001A834:
    /* B034 8001A834 08038497 */  lhu        $a0, %gp_rel(D_8009B210)($gp)
    /* B038 8001A838 00000000 */  nop
    /* B03C 8001A83C 40008230 */  andi       $v0, $a0, 0x40
  .L8001A840:
    /* B040 8001A840 1C004010 */  beqz       $v0, .L8001A8B4
    /* B044 8001A844 00000000 */   nop
    /* B048 8001A848 28002296 */  lhu        $v0, 0x28($s1)
    /* B04C 8001A84C 2A002386 */  lh         $v1, 0x2A($s1)
    /* B050 8001A850 1F004224 */  addiu      $v0, $v0, 0x1F
    /* B054 8001A854 280022A6 */  sh         $v0, 0x28($s1)
    /* B058 8001A858 00140200 */  sll        $v0, $v0, 16
    /* B05C 8001A85C 03140200 */  sra        $v0, $v0, 16
    /* B060 8001A860 2A104300 */  slt        $v0, $v0, $v1
    /* B064 8001A864 2A002396 */  lhu        $v1, 0x2A($s1)
    /* B068 8001A868 05004014 */  bnez       $v0, .L8001A880
    /* B06C 8001A86C BFFF8230 */   andi      $v0, $a0, 0xFFBF
    /* B070 8001A870 080382A7 */  sh         $v0, %gp_rel(D_8009B210)($gp)
    /* B074 8001A874 10000224 */  addiu      $v0, $zero, 0x10
    /* B078 8001A878 280023A6 */  sh         $v1, 0x28($s1)
    /* B07C 8001A87C 600022A6 */  sh         $v0, 0x60($s1)
  .L8001A880:
    /* B080 8001A880 2C002296 */  lhu        $v0, 0x2C($s1)
    /* B084 8001A884 28002396 */  lhu        $v1, 0x28($s1)
    /* B088 8001A888 21204002 */  addu       $a0, $s2, $zero
    /* B08C 8001A88C 21104300 */  addu       $v0, $v0, $v1
    /* B090 8001A890 325C000C */  jal        func_800170C8
    /* B094 8001A894 120082A4 */   sh        $v0, 0x12($a0)
    /* B098 8001A898 21804000 */  addu       $s0, $v0, $zero
    /* B09C 8001A89C 0F80023C */  lui        $v0, %hi(D_800EA0E8)
    /* B0A0 8001A8A0 E8A04224 */  addiu      $v0, $v0, %lo(D_800EA0E8)
    /* B0A4 8001A8A4 031C1000 */  sra        $v1, $s0, 16
    /* B0A8 8001A8A8 320050A4 */  sh         $s0, 0x32($v0)
    /* B0AC 8001A8AC 296C0008 */  j          .L8001B0A4
    /* B0B0 8001A8B0 340043A4 */   sh        $v1, 0x34($v0)
  .L8001A8B4:
    /* B0B4 8001A8B4 60002296 */  lhu        $v0, 0x60($s1)
    /* B0B8 8001A8B8 00000000 */  nop
    /* B0BC 8001A8BC FFFF4224 */  addiu      $v0, $v0, -0x1
    /* B0C0 8001A8C0 600022A6 */  sh         $v0, 0x60($s1)
    /* B0C4 8001A8C4 00140200 */  sll        $v0, $v0, 16
    /* B0C8 8001A8C8 F601401C */  bgtz       $v0, .L8001B0A4
    /* B0CC 8001A8CC 0F80103C */   lui       $s0, %hi(D_800E9EF0)
    /* B0D0 8001A8D0 B802838F */  lw         $v1, %gp_rel(D_8009B1C0)($gp)
    /* B0D4 8001A8D4 00000000 */  nop
    /* B0D8 8001A8D8 08006294 */  lhu        $v0, 0x8($v1)
    /* B0DC 8001A8DC 00000000 */  nop
    /* B0E0 8001A8E0 04004234 */  ori        $v0, $v0, 0x4
    /* B0E4 8001A8E4 080062A4 */  sh         $v0, 0x8($v1)
    /* B0E8 8001A8E8 F09E048E */  lw         $a0, %lo(D_800E9EF0)($s0)
    /* B0EC 8001A8EC DB00010C */  jal        func_8004036C
    /* B0F0 8001A8F0 F09E1126 */   addiu     $s1, $s0, %lo(D_800E9EF0)
    /* B0F4 8001A8F4 0400248E */  lw         $a0, 0x4($s1)
    /* B0F8 8001A8F8 DB00010C */  jal        func_8004036C
    /* B0FC 8001A8FC 00000000 */   nop
    /* B100 8001A900 21204002 */  addu       $a0, $s2, $zero
    /* B104 8001A904 40000524 */  addiu      $a1, $zero, 0x40
    /* B108 8001A908 52000624 */  addiu      $a2, $zero, 0x52
    /* B10C 8001A90C 040020AE */  sw         $zero, 0x4($s1)
    /* B110 8001A910 C15F000C */  jal        func_80017F04
    /* B114 8001A914 F09E00AE */   sw        $zero, %lo(D_800E9EF0)($s0)
    /* B118 8001A918 21884000 */  addu       $s1, $v0, $zero
    /* B11C 8001A91C F09E11AE */  sw         $s1, %lo(D_800E9EF0)($s0)
    /* B120 8001A920 08002296 */  lhu        $v0, 0x8($s1)
    /* B124 8001A924 03000324 */  addiu      $v1, $zero, 0x3
    /* B128 8001A928 200020AE */  sw         $zero, 0x20($s1)
    /* B12C 8001A92C 080383A7 */  sh         $v1, %gp_rel(D_8009B210)($gp)
    /* B130 8001A930 BBFF4230 */  andi       $v0, $v0, 0xFFBB
    /* B134 8001A934 296C0008 */  j          .L8001B0A4
    /* B138 8001A938 080022A6 */   sh        $v0, 0x8($s1)
  jlabel .L8001A93C
    /* B13C 8001A93C 0F80033C */  lui        $v1, %hi(D_800E9EF0)
    /* B140 8001A940 08038297 */  lhu        $v0, %gp_rel(D_8009B210)($gp)
    /* B144 8001A944 F09E718C */  lw         $s1, %lo(D_800E9EF0)($v1)
    /* B148 8001A948 80004230 */  andi       $v0, $v0, 0x80
    /* B14C 8001A94C 1D004014 */  bnez       $v0, .L8001A9C4
    /* B150 8001A950 00000000 */   nop
    /* B154 8001A954 B802838F */  lw         $v1, %gp_rel(D_8009B1C0)($gp)
    /* B158 8001A958 00000000 */  nop
    /* B15C 8001A95C 21006290 */  lbu        $v0, 0x21($v1)
    /* B160 8001A960 00000000 */  nop
    /* B164 8001A964 08004224 */  addiu      $v0, $v0, 0x8
    /* B168 8001A968 210062A0 */  sb         $v0, 0x21($v1)
    /* B16C 8001A96C FF004230 */  andi       $v0, $v0, 0xFF
    /* B170 8001A970 4000422C */  sltiu      $v0, $v0, 0x40
    /* B174 8001A974 CB014014 */  bnez       $v0, .L8001B0A4
    /* B178 8001A978 21202002 */   addu      $a0, $s1, $zero
    /* B17C 8001A97C C0000524 */  addiu      $a1, $zero, 0xC0
    /* B180 8001A980 21300000 */  addu       $a2, $zero, $zero
    /* B184 8001A984 08000724 */  addiu      $a3, $zero, 0x8
    /* B188 8001A988 B802838F */  lw         $v1, %gp_rel(D_8009B1C0)($gp)
    /* B18C 8001A98C 08038297 */  lhu        $v0, %gp_rel(D_8009B210)($gp)
    /* B190 8001A990 30006394 */  lhu        $v1, 0x30($v1)
    /* B194 8001A994 80004234 */  ori        $v0, $v0, 0x80
    /* B198 8001A998 080382A7 */  sh         $v0, %gp_rel(D_8009B210)($gp)
    /* B19C 8001A99C 2C006324 */  addiu      $v1, $v1, 0x2C
    /* B1A0 8001A9A0 E866000C */  jal        func_80019BA0
    /* B1A4 8001A9A4 300023A6 */   sh        $v1, 0x30($s1)
    /* B1A8 8001A9A8 08002296 */  lhu        $v0, 0x8($s1)
    /* B1AC 8001A9AC 21200000 */  addu       $a0, $zero, $zero
    /* B1B0 8001A9B0 40004234 */  ori        $v0, $v0, 0x40
    /* B1B4 8001A9B4 4AA5000C */  jal        func_80029528
    /* B1B8 8001A9B8 080022A6 */   sh        $v0, 0x8($s1)
    /* B1BC 8001A9BC 296C0008 */  j          .L8001B0A4
    /* B1C0 8001A9C0 00000000 */   nop
  .L8001A9C4:
    /* B1C4 8001A9C4 D00A010C */  jal        func_80042B40
    /* B1C8 8001A9C8 01000424 */   addiu     $a0, $zero, 0x1
    /* B1CC 8001A9CC B5014014 */  bnez       $v0, .L8001B0A4
    /* B1D0 8001A9D0 04000224 */   addiu     $v0, $zero, 0x4
    /* B1D4 8001A9D4 080382A7 */  sh         $v0, %gp_rel(D_8009B210)($gp)
    /* B1D8 8001A9D8 296C0008 */  j          .L8001B0A4
    /* B1DC 8001A9DC 00000000 */   nop
  jlabel .L8001A9E0
    /* B1E0 8001A9E0 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* B1E4 8001A9E4 08038397 */  lhu        $v1, %gp_rel(D_8009B210)($gp)
    /* B1E8 8001A9E8 F09E518C */  lw         $s1, %lo(D_800E9EF0)($v0)
    /* B1EC 8001A9EC 80006230 */  andi       $v0, $v1, 0x80
    /* B1F0 8001A9F0 07004014 */  bnez       $v0, .L8001AA10
    /* B1F4 8001A9F4 21202002 */   addu      $a0, $s1, $zero
    /* B1F8 8001A9F8 80006234 */  ori        $v0, $v1, 0x80
    /* B1FC 8001A9FC 080382A7 */  sh         $v0, %gp_rel(D_8009B210)($gp)
    /* B200 8001AA00 5E0C010C */  jal        func_80043178
    /* B204 8001AA04 21202002 */   addu      $a0, $s1, $zero
    /* B208 8001AA08 600020A6 */  sh         $zero, 0x60($s1)
    /* B20C 8001AA0C 21202002 */  addu       $a0, $s1, $zero
  .L8001AA10:
    /* B210 8001AA10 40000524 */  addiu      $a1, $zero, 0x40
    /* B214 8001AA14 60002786 */  lh         $a3, 0x60($s1)
    /* B218 8001AA18 630C010C */  jal        func_8004318C
    /* B21C 8001AA1C 52000624 */   addiu     $a2, $zero, 0x52
    /* B220 8001AA20 60002296 */  lhu        $v0, 0x60($s1)
    /* B224 8001AA24 00000000 */  nop
    /* B228 8001AA28 80004224 */  addiu      $v0, $v0, 0x80
    /* B22C 8001AA2C 600022A6 */  sh         $v0, 0x60($s1)
    /* B230 8001AA30 00140200 */  sll        $v0, $v0, 16
    /* B234 8001AA34 03140200 */  sra        $v0, $v0, 16
    /* B238 8001AA38 00084228 */  slti       $v0, $v0, 0x800
    /* B23C 8001AA3C 99014014 */  bnez       $v0, .L8001B0A4
    /* B240 8001AA40 03000224 */   addiu     $v0, $zero, 0x3
    /* B244 8001AA44 0E6C0008 */  j          .L8001B038
    /* B248 8001AA48 00000000 */   nop
  jlabel .L8001AA4C
    /* B24C 8001AA4C 6C028893 */  lbu        $t0, %gp_rel(D_8009B174)($gp)
    /* B250 8001AA50 00000000 */  nop
    /* B254 8001AA54 80000231 */  andi       $v0, $t0, 0x80
    /* B258 8001AA58 24004014 */  bnez       $v0, .L8001AAEC
    /* B25C 8001AA5C 40000231 */   andi      $v0, $t0, 0x40
    /* B260 8001AA60 21280000 */  addu       $a1, $zero, $zero
    /* B264 8001AA64 0F80103C */  lui        $s0, %hi(D_800E9EF0)
    /* B268 8001AA68 40000624 */  addiu      $a2, $zero, 0x40
    /* B26C 8001AA6C F09E038E */  lw         $v1, %lo(D_800E9EF0)($s0)
    /* B270 8001AA70 00000000 */  nop
    /* B274 8001AA74 08006294 */  lhu        $v0, 0x8($v1)
    /* B278 8001AA78 F09E1226 */  addiu      $s2, $s0, %lo(D_800E9EF0)
    /* B27C 8001AA7C BFFF4230 */  andi       $v0, $v0, 0xFFBF
    /* B280 8001AA80 080062A4 */  sh         $v0, 0x8($v1)
    /* B284 8001AA84 0400448E */  lw         $a0, 0x4($s2)
    /* B288 8001AA88 C0000235 */  ori        $v0, $t0, 0xC0
    /* B28C 8001AA8C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* B290 8001AA90 E866000C */  jal        func_80019BA0
    /* B294 8001AA94 08000724 */   addiu     $a3, $zero, 0x8
    /* B298 8001AA98 F09E118E */  lw         $s1, %lo(D_800E9EF0)($s0)
    /* B29C 8001AA9C 00000000 */  nop
    /* B2A0 8001AAA0 68002392 */  lbu        $v1, 0x68($s1)
    /* B2A4 8001AAA4 17000224 */  addiu      $v0, $zero, 0x17
    /* B2A8 8001AAA8 02006210 */  beq        $v1, $v0, .L8001AAB4
    /* B2AC 8001AAAC 0400053C */   lui       $a1, (0x48000 >> 16)
    /* B2B0 8001AAB0 0400518E */  lw         $s1, 0x4($s2)
  .L8001AAB4:
    /* B2B4 8001AAB4 0080A534 */  ori        $a1, $a1, (0x48000 & 0xFFFF)
    /* B2B8 8001AAB8 1680033C */  lui        $v1, %hi(D_8015C424)
    /* B2BC 8001AABC 6A002492 */  lbu        $a0, 0x6A($s1)
    /* B2C0 8001AAC0 24C46324 */  addiu      $v1, $v1, %lo(D_8015C424)
    /* B2C4 8001AAC4 C0100400 */  sll        $v0, $a0, 3
    /* B2C8 8001AAC8 23104400 */  subu       $v0, $v0, $a0
    /* B2CC 8001AACC 80100200 */  sll        $v0, $v0, 2
    /* B2D0 8001AAD0 21104300 */  addu       $v0, $v0, $v1
    /* B2D4 8001AAD4 21104500 */  addu       $v0, $v0, $a1
    /* B2D8 8001AAD8 C0364294 */  lhu        $v0, 0x36C0($v0)
    /* B2DC 8001AADC 00000000 */  nop
    /* B2E0 8001AAE0 FE0282A7 */  sh         $v0, %gp_rel(D_8009B206)($gp)
    /* B2E4 8001AAE4 296C0008 */  j          .L8001B0A4
    /* B2E8 8001AAE8 00000000 */   nop
  .L8001AAEC:
    /* B2EC 8001AAEC 28004010 */  beqz       $v0, .L8001AB90
    /* B2F0 8001AAF0 20000231 */   andi      $v0, $t0, 0x20
    /* B2F4 8001AAF4 D00A010C */  jal        func_80042B40
    /* B2F8 8001AAF8 01000424 */   addiu     $a0, $zero, 0x1
    /* B2FC 8001AAFC 69014014 */  bnez       $v0, .L8001B0A4
    /* B300 8001AB00 00000000 */   nop
    /* B304 8001AB04 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* B308 8001AB08 00000000 */  nop
    /* B30C 8001AB0C 20006230 */  andi       $v0, $v1, 0x20
    /* B310 8001AB10 82004014 */  bnez       $v0, .L8001AD1C
    /* B314 8001AB14 9F006230 */   andi      $v0, $v1, 0x9F
    /* B318 8001AB18 0F80103C */  lui        $s0, %hi(D_800E9EF0)
    /* B31C 8001AB1C F09E1126 */  addiu      $s1, $s0, %lo(D_800E9EF0)
    /* B320 8001AB20 0400248E */  lw         $a0, 0x4($s1)
    /* B324 8001AB24 20006234 */  ori        $v0, $v1, 0x20
    /* B328 8001AB28 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* B32C 8001AB2C 68008290 */  lbu        $v0, 0x68($a0)
    /* B330 8001AB30 00000000 */  nop
    /* B334 8001AB34 1400422C */  sltiu      $v0, $v0, 0x14
    /* B338 8001AB38 07004010 */  beqz       $v0, .L8001AB58
    /* B33C 8001AB3C 00000000 */   nop
    /* B340 8001AB40 F09E048E */  lw         $a0, %lo(D_800E9EF0)($s0)
    /* B344 8001AB44 DB00010C */  jal        func_8004036C
    /* B348 8001AB48 00000000 */   nop
    /* B34C 8001AB4C 0400228E */  lw         $v0, 0x4($s1)
    /* B350 8001AB50 D86A0008 */  j          .L8001AB60
    /* B354 8001AB54 F09E02AE */   sw        $v0, %lo(D_800E9EF0)($s0)
  .L8001AB58:
    /* B358 8001AB58 DB00010C */  jal        func_8004036C
    /* B35C 8001AB5C 00000000 */   nop
  .L8001AB60:
    /* B360 8001AB60 C0000524 */  addiu      $a1, $zero, 0xC0
    /* B364 8001AB64 0F80033C */  lui        $v1, %hi(D_800E9EF0)
    /* B368 8001AB68 F09E648C */  lw         $a0, %lo(D_800E9EF0)($v1)
    /* B36C 8001AB6C F09E6224 */  addiu      $v0, $v1, %lo(D_800E9EF0)
    /* B370 8001AB70 040040AC */  sw         $zero, 0x4($v0)
    /* B374 8001AB74 08008294 */  lhu        $v0, 0x8($a0)
    /* B378 8001AB78 00000000 */  nop
    /* B37C 8001AB7C 40004234 */  ori        $v0, $v0, 0x40
    /* B380 8001AB80 080082A4 */  sh         $v0, 0x8($a0)
    /* B384 8001AB84 F09E648C */  lw         $a0, %lo(D_800E9EF0)($v1)
    /* B388 8001AB88 436B0008 */  j          .L8001AD0C
    /* B38C 8001AB8C 21300000 */   addu      $a2, $zero, $zero
  .L8001AB90:
    /* B390 8001AB90 21004014 */  bnez       $v0, .L8001AC18
    /* B394 8001AB94 20000235 */   ori       $v0, $t0, 0x20
    /* B398 8001AB98 FE028497 */  lhu        $a0, %gp_rel(D_8009B206)($gp)
    /* B39C 8001AB9C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* B3A0 8001ABA0 D3FE8424 */  addiu      $a0, $a0, -0x12D
    /* B3A4 8001ABA4 0200842C */  sltiu      $a0, $a0, 0x2
    /* B3A8 8001ABA8 81B1000C */  jal        func_8002C604
    /* B3AC 8001ABAC 80200400 */   sll       $a0, $a0, 2
    /* B3B0 8001ABB0 0F80043C */  lui        $a0, %hi(D_800E9EF0)
    /* B3B4 8001ABB4 F09E838C */  lw         $v1, %lo(D_800E9EF0)($a0)
    /* B3B8 8001ABB8 00000000 */  nop
    /* B3BC 8001ABBC 30006394 */  lhu        $v1, 0x30($v1)
    /* B3C0 8001ABC0 21284000 */  addu       $a1, $v0, $zero
    /* B3C4 8001ABC4 1A006324 */  addiu      $v1, $v1, 0x1A
    /* B3C8 8001ABC8 0000A3A4 */  sh         $v1, 0x0($a1)
    /* B3CC 8001ABCC F09E828C */  lw         $v0, %lo(D_800E9EF0)($a0)
    /* B3D0 8001ABD0 740285AF */  sw         $a1, %gp_rel(D_8009B17C)($gp)
    /* B3D4 8001ABD4 32004294 */  lhu        $v0, 0x32($v0)
    /* B3D8 8001ABD8 FE028387 */  lh         $v1, %gp_rel(D_8009B206)($gp)
    /* B3DC 8001ABDC 1E004224 */  addiu      $v0, $v0, 0x1E
    /* B3E0 8001ABE0 0200A2A4 */  sh         $v0, 0x2($a1)
    /* B3E4 8001ABE4 2E010224 */  addiu      $v0, $zero, 0x12E
    /* B3E8 8001ABE8 02006214 */  bne        $v1, $v0, .L8001ABF4
    /* B3EC 8001ABEC 01000224 */   addiu     $v0, $zero, 0x1
    /* B3F0 8001ABF0 1A00A2A4 */  sh         $v0, 0x1A($a1)
  .L8001ABF4:
    /* B3F4 8001ABF4 FE028387 */  lh         $v1, %gp_rel(D_8009B206)($gp)
    /* B3F8 8001ABF8 91020224 */  addiu      $v0, $zero, 0x291
    /* B3FC 8001ABFC 02006214 */  bne        $v1, $v0, .L8001AC08
    /* B400 8001AC00 0A000224 */   addiu     $v0, $zero, 0xA
    /* B404 8001AC04 1A00A2A4 */  sh         $v0, 0x1A($a1)
  .L8001AC08:
    /* B408 8001AC08 B8FF000C */  jal        func_8003FEE0
    /* B40C 8001AC0C 16000424 */   addiu     $a0, $zero, 0x16
    /* B410 8001AC10 296C0008 */  j          .L8001B0A4
    /* B414 8001AC14 00000000 */   nop
  .L8001AC18:
    /* B418 8001AC18 7402828F */  lw         $v0, %gp_rel(D_8009B17C)($gp)
    /* B41C 8001AC1C 00000000 */  nop
    /* B420 8001AC20 1D004290 */  lbu        $v0, 0x1D($v0)
    /* B424 8001AC24 00000000 */  nop
    /* B428 8001AC28 1E014010 */  beqz       $v0, .L8001B0A4
    /* B42C 8001AC2C 04000224 */   addiu     $v0, $zero, 0x4
    /* B430 8001AC30 8A6B0008 */  j          .L8001AE28
    /* B434 8001AC34 00000000 */   nop
  jlabel .L8001AC38
    /* B438 8001AC38 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* B43C 8001AC3C 00000000 */  nop
    /* B440 8001AC40 80006230 */  andi       $v0, $v1, 0x80
    /* B444 8001AC44 10004014 */  bnez       $v0, .L8001AC88
    /* B448 8001AC48 C0006234 */   ori       $v0, $v1, 0xC0
    /* B44C 8001AC4C 48028497 */  lhu        $a0, %gp_rel(D_8009B150)($gp)
    /* B450 8001AC50 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* B454 8001AC54 3267000C */  jal        func_80019CC8
    /* B458 8001AC58 FF0F8430 */   andi      $a0, $a0, 0xFFF
    /* B45C 8001AC5C 0F80033C */  lui        $v1, %hi(D_800E9EF0)
    /* B460 8001AC60 21280000 */  addu       $a1, $zero, $zero
    /* B464 8001AC64 F09E648C */  lw         $a0, %lo(D_800E9EF0)($v1)
    /* B468 8001AC68 40000624 */  addiu      $a2, $zero, 0x40
    /* B46C 8001AC6C 08008294 */  lhu        $v0, 0x8($a0)
    /* B470 8001AC70 F09E6324 */  addiu      $v1, $v1, %lo(D_800E9EF0)
    /* B474 8001AC74 BFFF4230 */  andi       $v0, $v0, 0xFFBF
    /* B478 8001AC78 080082A4 */  sh         $v0, 0x8($a0)
    /* B47C 8001AC7C 0400648C */  lw         $a0, 0x4($v1)
    /* B480 8001AC80 E866000C */  jal        func_80019BA0
    /* B484 8001AC84 08000724 */   addiu     $a3, $zero, 0x8
  .L8001AC88:
    /* B488 8001AC88 6C028593 */  lbu        $a1, %gp_rel(D_8009B174)($gp)
    /* B48C 8001AC8C 00000000 */  nop
    /* B490 8001AC90 4000A230 */  andi       $v0, $a1, 0x40
    /* B494 8001AC94 24004010 */  beqz       $v0, .L8001AD28
    /* B498 8001AC98 2000A230 */   andi      $v0, $a1, 0x20
    /* B49C 8001AC9C D00A010C */  jal        func_80042B40
    /* B4A0 8001ACA0 01000424 */   addiu     $a0, $zero, 0x1
    /* B4A4 8001ACA4 FF004014 */  bnez       $v0, .L8001B0A4
    /* B4A8 8001ACA8 00000000 */   nop
    /* B4AC 8001ACAC 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* B4B0 8001ACB0 00000000 */  nop
    /* B4B4 8001ACB4 20006230 */  andi       $v0, $v1, 0x20
    /* B4B8 8001ACB8 18004014 */  bnez       $v0, .L8001AD1C
    /* B4BC 8001ACBC 9F006230 */   andi      $v0, $v1, 0x9F
    /* B4C0 8001ACC0 C0000524 */  addiu      $a1, $zero, 0xC0
    /* B4C4 8001ACC4 21300000 */  addu       $a2, $zero, $zero
    /* B4C8 8001ACC8 0F80113C */  lui        $s1, %hi(D_800E9EF0)
    /* B4CC 8001ACCC F09E3026 */  addiu      $s0, $s1, %lo(D_800E9EF0)
    /* B4D0 8001ACD0 0400048E */  lw         $a0, 0x4($s0)
    /* B4D4 8001ACD4 20006234 */  ori        $v0, $v1, 0x20
    /* B4D8 8001ACD8 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* B4DC 8001ACDC E866000C */  jal        func_80019BA0
    /* B4E0 8001ACE0 08000724 */   addiu     $a3, $zero, 0x8
    /* B4E4 8001ACE4 0400038E */  lw         $v1, 0x4($s0)
    /* B4E8 8001ACE8 8C000224 */  addiu      $v0, $zero, 0x8C
    /* B4EC 8001ACEC 300062A4 */  sh         $v0, 0x30($v1)
    /* B4F0 8001ACF0 F09E238E */  lw         $v1, %lo(D_800E9EF0)($s1)
    /* B4F4 8001ACF4 C0000524 */  addiu      $a1, $zero, 0xC0
    /* B4F8 8001ACF8 08006294 */  lhu        $v0, 0x8($v1)
    /* B4FC 8001ACFC 21300000 */  addu       $a2, $zero, $zero
    /* B500 8001AD00 40004234 */  ori        $v0, $v0, 0x40
    /* B504 8001AD04 080062A4 */  sh         $v0, 0x8($v1)
    /* B508 8001AD08 F09E248E */  lw         $a0, %lo(D_800E9EF0)($s1)
  .L8001AD0C:
    /* B50C 8001AD0C E866000C */  jal        func_80019BA0
    /* B510 8001AD10 08000724 */   addiu     $a3, $zero, 0x8
    /* B514 8001AD14 296C0008 */  j          .L8001B0A4
    /* B518 8001AD18 00000000 */   nop
  .L8001AD1C:
    /* B51C 8001AD1C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* B520 8001AD20 296C0008 */  j          .L8001B0A4
    /* B524 8001AD24 00000000 */   nop
  .L8001AD28:
    /* B528 8001AD28 2B004014 */  bnez       $v0, .L8001ADD8
    /* B52C 8001AD2C 0F80103C */   lui       $s0, %hi(D_800E9EF0)
    /* B530 8001AD30 F09E028E */  lw         $v0, %lo(D_800E9EF0)($s0)
    /* B534 8001AD34 01000424 */  addiu      $a0, $zero, 0x1
    /* B538 8001AD38 600040A4 */  sh         $zero, 0x60($v0)
    /* B53C 8001AD3C F09E028E */  lw         $v0, %lo(D_800E9EF0)($s0)
    /* B540 8001AD40 21888000 */  addu       $s1, $a0, $zero
    /* B544 8001AD44 280051A4 */  sh         $s1, 0x28($v0)
    /* B548 8001AD48 F09E038E */  lw         $v1, %lo(D_800E9EF0)($s0)
    /* B54C 8001AD4C 80260224 */  addiu      $v0, $zero, 0x2680
    /* B550 8001AD50 2A0062A4 */  sh         $v0, 0x2A($v1)
    /* B554 8001AD54 F09E038E */  lw         $v1, %lo(D_800E9EF0)($s0)
    /* B558 8001AD58 2000A234 */  ori        $v0, $a1, 0x20
    /* B55C 8001AD5C 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* B560 8001AD60 81B1000C */  jal        func_8002C604
    /* B564 8001AD64 2E0071A4 */   sh        $s1, 0x2E($v1)
    /* B568 8001AD68 21184000 */  addu       $v1, $v0, $zero
    /* B56C 8001AD6C 80000224 */  addiu      $v0, $zero, 0x80
    /* B570 8001AD70 000062A4 */  sh         $v0, 0x0($v1)
    /* B574 8001AD74 F09E028E */  lw         $v0, %lo(D_800E9EF0)($s0)
    /* B578 8001AD78 00000000 */  nop
    /* B57C 8001AD7C 32004294 */  lhu        $v0, 0x32($v0)
    /* B580 8001AD80 00000000 */  nop
    /* B584 8001AD84 1E004224 */  addiu      $v0, $v0, 0x1E
    /* B588 8001AD88 020062A4 */  sh         $v0, 0x2($v1)
    /* B58C 8001AD8C F09E028E */  lw         $v0, %lo(D_800E9EF0)($s0)
    /* B590 8001AD90 740283AF */  sw         $v1, %gp_rel(D_8009B17C)($gp)
    /* B594 8001AD94 68004290 */  lbu        $v0, 0x68($v0)
    /* B598 8001AD98 00000000 */  nop
    /* B59C 8001AD9C 1400422C */  sltiu      $v0, $v0, 0x14
    /* B5A0 8001ADA0 08004010 */  beqz       $v0, .L8001ADC4
    /* B5A4 8001ADA4 F09E1026 */   addiu     $s0, $s0, %lo(D_800E9EF0)
    /* B5A8 8001ADA8 0400028E */  lw         $v0, 0x4($s0)
    /* B5AC 8001ADAC 00000000 */  nop
    /* B5B0 8001ADB0 68004290 */  lbu        $v0, 0x68($v0)
    /* B5B4 8001ADB4 00000000 */  nop
    /* B5B8 8001ADB8 1400422C */  sltiu      $v0, $v0, 0x14
    /* B5BC 8001ADBC 02004014 */  bnez       $v0, .L8001ADC8
    /* B5C0 8001ADC0 00000000 */   nop
  .L8001ADC4:
    /* B5C4 8001ADC4 1A0071A4 */  sh         $s1, 0x1A($v1)
  .L8001ADC8:
    /* B5C8 8001ADC8 B8FF000C */  jal        func_8003FEE0
    /* B5CC 8001ADCC 18000424 */   addiu     $a0, $zero, 0x18
    /* B5D0 8001ADD0 296C0008 */  j          .L8001B0A4
    /* B5D4 8001ADD4 00000000 */   nop
  .L8001ADD8:
    /* B5D8 8001ADD8 7402828F */  lw         $v0, %gp_rel(D_8009B17C)($gp)
    /* B5DC 8001ADDC 00000000 */  nop
    /* B5E0 8001ADE0 1D004290 */  lbu        $v0, 0x1D($v0)
    /* B5E4 8001ADE4 00000000 */  nop
    /* B5E8 8001ADE8 12004010 */  beqz       $v0, .L8001AE34
    /* B5EC 8001ADEC 0F80033C */   lui       $v1, %hi(D_800E9EF0)
    /* B5F0 8001ADF0 F09E648C */  lw         $a0, %lo(D_800E9EF0)($v1)
    /* B5F4 8001ADF4 00000000 */  nop
    /* B5F8 8001ADF8 08008294 */  lhu        $v0, 0x8($a0)
    /* B5FC 8001ADFC F09E6324 */  addiu      $v1, $v1, %lo(D_800E9EF0)
    /* B600 8001AE00 BFFF4230 */  andi       $v0, $v0, 0xFFBF
    /* B604 8001AE04 080082A4 */  sh         $v0, 0x8($a0)
    /* B608 8001AE08 0400638C */  lw         $v1, 0x4($v1)
    /* B60C 8001AE0C 00000000 */  nop
    /* B610 8001AE10 08006294 */  lhu        $v0, 0x8($v1)
    /* B614 8001AE14 19000424 */  addiu      $a0, $zero, 0x19
    /* B618 8001AE18 BFFF4230 */  andi       $v0, $v0, 0xFFBF
    /* B61C 8001AE1C B8FF000C */  jal        func_8003FEE0
    /* B620 8001AE20 080062A4 */   sh        $v0, 0x8($v1)
    /* B624 8001AE24 04000224 */  addiu      $v0, $zero, 0x4
  .L8001AE28:
    /* B628 8001AE28 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* B62C 8001AE2C 296C0008 */  j          .L8001B0A4
    /* B630 8001AE30 00000000 */   nop
  .L8001AE34:
    /* B634 8001AE34 0F80063C */  lui        $a2, %hi(D_800E9EF0)
    /* B638 8001AE38 F09ED18C */  lw         $s1, %lo(D_800E9EF0)($a2)
    /* B63C 8001AE3C 00000000 */  nop
    /* B640 8001AE40 2E002296 */  lhu        $v0, 0x2E($s1)
    /* B644 8001AE44 AA2A043C */  lui        $a0, (0x2AAAAAAB >> 16)
    /* B648 8001AE48 08004224 */  addiu      $v0, $v0, 0x8
    /* B64C 8001AE4C 2E0022A6 */  sh         $v0, 0x2E($s1)
    /* B650 8001AE50 F09EC28C */  lw         $v0, %lo(D_800E9EF0)($a2)
    /* B654 8001AE54 60002396 */  lhu        $v1, 0x60($s1)
    /* B658 8001AE58 2E004294 */  lhu        $v0, 0x2E($v0)
    /* B65C 8001AE5C ABAA8434 */  ori        $a0, $a0, (0x2AAAAAAB & 0xFFFF)
    /* B660 8001AE60 21186200 */  addu       $v1, $v1, $v0
    /* B664 8001AE64 002C0300 */  sll        $a1, $v1, 16
    /* B668 8001AE68 03140500 */  sra        $v0, $a1, 16
    /* B66C 8001AE6C 18004400 */  mult       $v0, $a0
    /* B670 8001AE70 F09ED424 */  addiu      $s4, $a2, %lo(D_800E9EF0)
    /* B674 8001AE74 C32F0500 */  sra        $a1, $a1, 31
    /* B678 8001AE78 600023A6 */  sh         $v1, 0x60($s1)
    /* B67C 8001AE7C 60002486 */  lh         $a0, 0x60($s1)
    /* B680 8001AE80 2A002396 */  lhu        $v1, 0x2A($s1)
    /* B684 8001AE84 10400000 */  mfhi       $t0
    /* B688 8001AE88 43100800 */  sra        $v0, $t0, 1
    /* B68C 8001AE8C 23104500 */  subu       $v0, $v0, $a1
    /* B690 8001AE90 23186200 */  subu       $v1, $v1, $v0
    /* B694 8001AE94 00140300 */  sll        $v0, $v1, 16
    /* B698 8001AE98 03960200 */  sra        $s2, $v0, 24
    /* B69C 8001AE9C DC19020C */  jal        func_80086770
    /* B6A0 8001AEA0 2A0023A6 */   sh        $v1, 0x2A($s1)
    /* B6A4 8001AEA4 18005200 */  mult       $v0, $s2
    /* B6A8 8001AEA8 12100000 */  mflo       $v0
    /* B6AC 8001AEAC 02004104 */  bgez       $v0, .L8001AEB8
    /* B6B0 8001AEB0 00000000 */   nop
    /* B6B4 8001AEB4 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8001AEB8:
    /* B6B8 8001AEB8 60002486 */  lh         $a0, 0x60($s1)
    /* B6BC 8001AEBC A819020C */  jal        func_800866A0
    /* B6C0 8001AEC0 039B0200 */   sra       $s3, $v0, 12
    /* B6C4 8001AEC4 18005200 */  mult       $v0, $s2
    /* B6C8 8001AEC8 12100000 */  mflo       $v0
    /* B6CC 8001AECC 03004104 */  bgez       $v0, .L8001AEDC
    /* B6D0 8001AED0 03830200 */   sra       $s0, $v0, 12
    /* B6D4 8001AED4 FF0F4224 */  addiu      $v0, $v0, 0xFFF
    /* B6D8 8001AED8 03830200 */  sra        $s0, $v0, 12
  .L8001AEDC:
    /* B6DC 8001AEDC 66000224 */  addiu      $v0, $zero, 0x66
    /* B6E0 8001AEE0 23105300 */  subu       $v0, $v0, $s3
    /* B6E4 8001AEE4 300022A6 */  sh         $v0, 0x30($s1)
    /* B6E8 8001AEE8 52000224 */  addiu      $v0, $zero, 0x52
    /* B6EC 8001AEEC 23105000 */  subu       $v0, $v0, $s0
    /* B6F0 8001AEF0 320022A6 */  sh         $v0, 0x32($s1)
    /* B6F4 8001AEF4 0400838E */  lw         $v1, 0x4($s4)
    /* B6F8 8001AEF8 66006226 */  addiu      $v0, $s3, 0x66
    /* B6FC 8001AEFC 300062A4 */  sh         $v0, 0x30($v1)
    /* B700 8001AF00 0400838E */  lw         $v1, 0x4($s4)
    /* B704 8001AF04 52000226 */  addiu      $v0, $s0, 0x52
    /* B708 8001AF08 296C0008 */  j          .L8001B0A4
    /* B70C 8001AF0C 320062A4 */   sh        $v0, 0x32($v1)
  jlabel .L8001AF10
    /* B710 8001AF10 0F80103C */  lui        $s0, %hi(D_800E9EF0)
    /* B714 8001AF14 6C028393 */  lbu        $v1, %gp_rel(D_8009B174)($gp)
    /* B718 8001AF18 F09E118E */  lw         $s1, %lo(D_800E9EF0)($s0)
    /* B71C 8001AF1C 80006230 */  andi       $v0, $v1, 0x80
    /* B720 8001AF20 26004014 */  bnez       $v0, .L8001AFBC
    /* B724 8001AF24 F09E1226 */   addiu     $s2, $s0, %lo(D_800E9EF0)
    /* B728 8001AF28 FFF7053C */  lui        $a1, (0xF7FFFFFF >> 16)
    /* B72C 8001AF2C FFFFA534 */  ori        $a1, $a1, (0xF7FFFFFF & 0xFFFF)
    /* B730 8001AF30 1A000424 */  addiu      $a0, $zero, 0x1A
    /* B734 8001AF34 80006234 */  ori        $v0, $v1, 0x80
    /* B738 8001AF38 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* B73C 8001AF3C 08002296 */  lhu        $v0, 0x8($s1)
    /* B740 8001AF40 0400238E */  lw         $v1, 0x4($s1)
    /* B744 8001AF44 04004234 */  ori        $v0, $v0, 0x4
    /* B748 8001AF48 24186500 */  and        $v1, $v1, $a1
    /* B74C 8001AF4C 080022A6 */  sh         $v0, 0x8($s1)
    /* B750 8001AF50 B8FF000C */  jal        func_8003FEE0
    /* B754 8001AF54 040023AE */   sw        $v1, 0x4($s1)
    /* B758 8001AF58 0400438E */  lw         $v1, 0x4($s2)
    /* B75C 8001AF5C 00000000 */  nop
    /* B760 8001AF60 68006290 */  lbu        $v0, 0x68($v1)
    /* B764 8001AF64 00000000 */  nop
    /* B768 8001AF68 1400422C */  sltiu      $v0, $v0, 0x14
    /* B76C 8001AF6C 09004014 */  bnez       $v0, .L8001AF94
    /* B770 8001AF70 00000000 */   nop
    /* B774 8001AF74 68002292 */  lbu        $v0, 0x68($s1)
    /* B778 8001AF78 00000000 */  nop
    /* B77C 8001AF7C 1400422C */  sltiu      $v0, $v0, 0x14
    /* B780 8001AF80 04004010 */  beqz       $v0, .L8001AF94
    /* B784 8001AF84 00000000 */   nop
    /* B788 8001AF88 040051AE */  sw         $s1, 0x4($s2)
    /* B78C 8001AF8C 21886000 */  addu       $s1, $v1, $zero
    /* B790 8001AF90 F09E03AE */  sw         $v1, %lo(D_800E9EF0)($s0)
  .L8001AF94:
    /* B794 8001AF94 760A010C */  jal        func_800429D8
    /* B798 8001AF98 21202002 */   addu      $a0, $s1, $zero
    /* B79C 8001AF9C 6439020C */  jal        func_8008E590
    /* B7A0 8001AFA0 00000000 */   nop
    /* B7A4 8001AFA4 FF004230 */  andi       $v0, $v0, 0xFF
    /* B7A8 8001AFA8 00034224 */  addiu      $v0, $v0, 0x300
    /* B7AC 8001AFAC 23100200 */  negu       $v0, $v0
    /* B7B0 8001AFB0 360022A6 */  sh         $v0, 0x36($s1)
    /* B7B4 8001AFB4 80FD0224 */  addiu      $v0, $zero, -0x280
    /* B7B8 8001AFB8 380022A6 */  sh         $v0, 0x38($s1)
  .L8001AFBC:
    /* B7BC 8001AFBC 36002486 */  lh         $a0, 0x36($s1)
    /* B7C0 8001AFC0 C20A010C */  jal        func_80042B08
    /* B7C4 8001AFC4 08000524 */   addiu     $a1, $zero, 0x8
    /* B7C8 8001AFC8 00080524 */  addiu      $a1, $zero, 0x800
    /* B7CC 8001AFCC 38002486 */  lh         $a0, 0x38($s1)
    /* B7D0 8001AFD0 60000624 */  addiu      $a2, $zero, 0x60
    /* B7D4 8001AFD4 B60A010C */  jal        func_80042AD8
    /* B7D8 8001AFD8 360022A6 */   sh        $v0, 0x36($s1)
    /* B7DC 8001AFDC 21202002 */  addu       $a0, $s1, $zero
    /* B7E0 8001AFE0 9E0A010C */  jal        func_80042A78
    /* B7E4 8001AFE4 380022A6 */   sh        $v0, 0x38($s1)
    /* B7E8 8001AFE8 30002286 */  lh         $v0, 0x30($s1)
    /* B7EC 8001AFEC 00000000 */  nop
    /* B7F0 8001AFF0 CCFF4228 */  slti       $v0, $v0, -0x34
    /* B7F4 8001AFF4 06004014 */  bnez       $v0, .L8001B010
    /* B7F8 8001AFF8 00000000 */   nop
    /* B7FC 8001AFFC 32002286 */  lh         $v0, 0x32($s1)
    /* B800 8001B000 00000000 */  nop
    /* B804 8001B004 F0004228 */  slti       $v0, $v0, 0xF0
    /* B808 8001B008 26004014 */  bnez       $v0, .L8001B0A4
    /* B80C 8001B00C 00000000 */   nop
  .L8001B010:
    /* B810 8001B010 DB00010C */  jal        func_8004036C
    /* B814 8001B014 21202002 */   addu      $a0, $s1, $zero
    /* B818 8001B018 0F80033C */  lui        $v1, %hi(D_800E9EF0)
    /* B81C 8001B01C F09E6224 */  addiu      $v0, $v1, %lo(D_800E9EF0)
    /* B820 8001B020 0F80043C */  lui        $a0, %hi(D_800EB0F8)
    /* B824 8001B024 0400428C */  lw         $v0, 0x4($v0)
    /* B828 8001B028 F8B08424 */  addiu      $a0, $a0, %lo(D_800EB0F8)
    /* B82C 8001B02C DFD6000C */  jal        func_80035B7C
    /* B830 8001B030 F09E62AC */   sw        $v0, %lo(D_800E9EF0)($v1)
    /* B834 8001B034 03000224 */  addiu      $v0, $zero, 0x3
  .L8001B038:
    /* B838 8001B038 6C0282A3 */  sb         $v0, %gp_rel(D_8009B174)($gp)
    /* B83C 8001B03C 296C0008 */  j          .L8001B0A4
    /* B840 8001B040 00000000 */   nop
  jlabel .L8001B044
    /* B844 8001B044 0F80023C */  lui        $v0, %hi(D_800E9EF0)
    /* B848 8001B048 F09E438C */  lw         $v1, %lo(D_800E9EF0)($v0)
    /* B84C 8001B04C 06000224 */  addiu      $v0, $zero, 0x6
    /* B850 8001B050 320382A7 */  sh         $v0, %gp_rel(D_8009B23A)($gp)
    /* B854 8001B054 68006290 */  lbu        $v0, 0x68($v1)
    /* B858 8001B058 00000000 */  nop
    /* B85C 8001B05C 1400422C */  sltiu      $v0, $v0, 0x14
    /* B860 8001B060 10004010 */  beqz       $v0, .L8001B0A4
    /* B864 8001B064 08400224 */   addiu     $v0, $zero, 0x4008
    /* B868 8001B068 6A006490 */  lbu        $a0, 0x6A($v1)
    /* B86C 8001B06C 1A80033C */  lui        $v1, %hi(D_801A7AD8)
    /* B870 8001B070 D87A6324 */  addiu      $v1, $v1, %lo(D_801A7AD8)
    /* B874 8001B074 320382A7 */  sh         $v0, %gp_rel(D_8009B23A)($gp)
    /* B878 8001B078 C0100400 */  sll        $v0, $a0, 3
    /* B87C 8001B07C 23104400 */  subu       $v0, $v0, $a0
    /* B880 8001B080 80100200 */  sll        $v0, $v0, 2
    /* B884 8001B084 21104300 */  addu       $v0, $v0, $v1
    /* B888 8001B088 16004394 */  lhu        $v1, 0x16($v0)
    /* B88C 8001B08C 10038483 */  lb         $a0, %gp_rel(D_8009B218)($gp)
    /* B890 8001B090 FFEF6330 */  andi       $v1, $v1, 0xEFFF
    /* B894 8001B094 03008010 */  beqz       $a0, .L8001B0A4
    /* B898 8001B098 160043A4 */   sh        $v1, 0x16($v0)
    /* B89C 8001B09C 08000224 */  addiu      $v0, $zero, 0x8
  .L8001B0A0:
    /* B8A0 8001B0A0 320382A7 */  sh         $v0, %gp_rel(D_8009B23A)($gp)
  .L8001B0A4:
    /* B8A4 8001B0A4 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* B8A8 8001B0A8 2800B68F */  lw         $s6, 0x28($sp)
    /* B8AC 8001B0AC 2400B58F */  lw         $s5, 0x24($sp)
    /* B8B0 8001B0B0 2000B48F */  lw         $s4, 0x20($sp)
    /* B8B4 8001B0B4 1C00B38F */  lw         $s3, 0x1C($sp)
    /* B8B8 8001B0B8 1800B28F */  lw         $s2, 0x18($sp)
    /* B8BC 8001B0BC 1400B18F */  lw         $s1, 0x14($sp)
    /* B8C0 8001B0C0 1000B08F */  lw         $s0, 0x10($sp)
    /* B8C4 8001B0C4 0800E003 */  jr         $ra
    /* B8C8 8001B0C8 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_80019D18
