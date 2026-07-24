nonmatching func_8003EED0, 0x3E0

glabel func_8003EED0
    /* 2F6D0 8003EED0 B9048393 */  lbu        $v1, %gp_rel(D_8009B3C1)($gp)
    /* 2F6D4 8003EED4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2F6D8 8003EED8 2400BFAF */  sw         $ra, 0x24($sp)
    /* 2F6DC 8003EEDC 80006230 */  andi       $v0, $v1, 0x80
    /* 2F6E0 8003EEE0 07004014 */  bnez       $v0, .L8003EF00
    /* 2F6E4 8003EEE4 2000B0AF */   sw        $s0, 0x20($sp)
    /* 2F6E8 8003EEE8 C0000424 */  addiu      $a0, $zero, 0xC0
    /* 2F6EC 8003EEEC 80006234 */  ori        $v0, $v1, 0x80
    /* 2F6F0 8003EEF0 B90482A3 */  sb         $v0, %gp_rel(D_8009B3C1)($gp)
    /* 2F6F4 8003EEF4 1BF9000C */  jal        func_8003E46C
    /* 2F6F8 8003EEF8 21280000 */   addu      $a1, $zero, $zero
    /* 2F6FC 8003EEFC E30480A3 */  sb         $zero, %gp_rel(D_8009B3EB)($gp)
  .L8003EF00:
    /* 2F700 8003EF00 E3048393 */  lbu        $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2F704 8003EF04 01000224 */  addiu      $v0, $zero, 0x1
    /* 2F708 8003EF08 0F007030 */  andi       $s0, $v1, 0xF
    /* 2F70C 8003EF0C 39000212 */  beq        $s0, $v0, .L8003EFF4
    /* 2F710 8003EF10 0200022A */   slti      $v0, $s0, 0x2
    /* 2F714 8003EF14 05004010 */  beqz       $v0, .L8003EF2C
    /* 2F718 8003EF18 00000000 */   nop
    /* 2F71C 8003EF1C 0A000012 */  beqz       $s0, .L8003EF48
    /* 2F720 8003EF20 80006230 */   andi      $v0, $v1, 0x80
    /* 2F724 8003EF24 A8FC0008 */  j          .L8003F2A0
    /* 2F728 8003EF28 00000000 */   nop
  .L8003EF2C:
    /* 2F72C 8003EF2C 02000224 */  addiu      $v0, $zero, 0x2
    /* 2F730 8003EF30 4F000212 */  beq        $s0, $v0, .L8003F070
    /* 2F734 8003EF34 03000224 */   addiu     $v0, $zero, 0x3
    /* 2F738 8003EF38 95000212 */  beq        $s0, $v0, .L8003F190
    /* 2F73C 8003EF3C 00000000 */   nop
    /* 2F740 8003EF40 A8FC0008 */  j          .L8003F2A0
    /* 2F744 8003EF44 00000000 */   nop
  .L8003EF48:
    /* 2F748 8003EF48 0E004014 */  bnez       $v0, .L8003EF84
    /* 2F74C 8003EF4C 80006234 */   ori       $v0, $v1, 0x80
    /* 2F750 8003EF50 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F754 8003EF54 F1048293 */  lbu        $v0, %gp_rel(D_8009B3F9)($gp)
    /* 2F758 8003EF58 1D80033C */  lui        $v1, %hi(D_801D5648)
    /* 2F75C 8003EF5C 02110200 */  srl        $v0, $v0, 4
    /* 2F760 8003EF60 01004224 */  addiu      $v0, $v0, 0x1
    /* 2F764 8003EF64 485662AC */  sw         $v0, %lo(D_801D5648)($v1)
  .L8003EF68:
    /* 2F768 8003EF68 F1048493 */  lbu        $a0, %gp_rel(D_8009B3F9)($gp)
    /* 2F76C 8003EF6C 242F020C */  jal        func_8008BC90
    /* 2F770 8003EF70 00000000 */   nop
    /* 2F774 8003EF74 FCFF4010 */  beqz       $v0, .L8003EF68
    /* 2F778 8003EF78 00000000 */   nop
    /* 2F77C 8003EF7C 84FC0008 */  j          .L8003F210
    /* 2F780 8003EF80 00000000 */   nop
  .L8003EF84:
    /* 2F784 8003EF84 EC04838F */  lw         $v1, %gp_rel(D_8009B3F4)($gp)
    /* 2F788 8003EF88 00000000 */  nop
    /* 2F78C 8003EF8C 0500622C */  sltiu      $v0, $v1, 0x5
    /* 2F790 8003EF90 C3004010 */  beqz       $v0, .L8003F2A0
    /* 2F794 8003EF94 0180023C */   lui       $v0, %hi(jtbl_800104D8)
    /* 2F798 8003EF98 D8044224 */  addiu      $v0, $v0, %lo(jtbl_800104D8)
    /* 2F79C 8003EF9C 80180300 */  sll        $v1, $v1, 2
    /* 2F7A0 8003EFA0 21186200 */  addu       $v1, $v1, $v0
    /* 2F7A4 8003EFA4 0000628C */  lw         $v0, 0x0($v1)
    /* 2F7A8 8003EFA8 00000000 */  nop
    /* 2F7AC 8003EFAC 08004000 */  jr         $v0
    /* 2F7B0 8003EFB0 00000000 */   nop
  jlabel .L8003EFB4
    /* 2F7B4 8003EFB4 A6FC0008 */  j          .L8003F298
    /* 2F7B8 8003EFB8 C1000424 */   addiu     $a0, $zero, 0xC1
  jlabel .L8003EFBC
    /* 2F7BC 8003EFBC F1048293 */  lbu        $v0, %gp_rel(D_8009B3F9)($gp)
    /* 2F7C0 8003EFC0 01000324 */  addiu      $v1, $zero, 0x1
    /* 2F7C4 8003EFC4 E30483A3 */  sb         $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2F7C8 8003EFC8 10004238 */  xori       $v0, $v0, 0x10
    /* 2F7CC 8003EFCC F10482A3 */  sb         $v0, %gp_rel(D_8009B3F9)($gp)
    /* 2F7D0 8003EFD0 B3004010 */  beqz       $v0, .L8003F2A0
    /* 2F7D4 8003EFD4 00000000 */   nop
    /* 2F7D8 8003EFD8 E30480A3 */  sb         $zero, %gp_rel(D_8009B3EB)($gp)
    /* 2F7DC 8003EFDC A8FC0008 */  j          .L8003F2A0
    /* 2F7E0 8003EFE0 00000000 */   nop
  jlabel .L8003EFE4
    /* 2F7E4 8003EFE4 A6FC0008 */  j          .L8003F298
    /* 2F7E8 8003EFE8 DA000424 */   addiu     $a0, $zero, 0xDA
  jlabel .L8003EFEC
    /* 2F7EC 8003EFEC A6FC0008 */  j          .L8003F298
    /* 2F7F0 8003EFF0 C3000424 */   addiu     $a0, $zero, 0xC3
  .L8003EFF4:
    /* 2F7F4 8003EFF4 0F80053C */  lui        $a1, %hi(D_800EFE18)
    /* 2F7F8 8003EFF8 18FEA524 */  addiu      $a1, $a1, %lo(D_800EFE18)
    /* 2F7FC 8003EFFC 0F80063C */  lui        $a2, %hi(D_800EFBC0)
    /* 2F800 8003F000 C0FBC624 */  addiu      $a2, $a2, %lo(D_800EFBC0)
    /* 2F804 8003F004 1800A727 */  addiu      $a3, $sp, 0x18
    /* 2F808 8003F008 0F000224 */  addiu      $v0, $zero, 0xF
    /* 2F80C 8003F00C F1048493 */  lbu        $a0, %gp_rel(D_8009B3F9)($gp)
    /* 2F810 8003F010 1D80033C */  lui        $v1, %hi(D_801D5648)
    /* 2F814 8003F014 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2F818 8003F018 1400A2AF */  sw         $v0, 0x14($sp)
    /* 2F81C 8003F01C 21108000 */  addu       $v0, $a0, $zero
    /* 2F820 8003F020 02110200 */  srl        $v0, $v0, 4
    /* 2F824 8003F024 01004224 */  addiu      $v0, $v0, 0x1
    /* 2F828 8003F028 9E32020C */  jal        func_8008CA78
    /* 2F82C 8003F02C 485662AC */   sw        $v0, %lo(D_801D5648)($v1)
    /* 2F830 8003F030 99004014 */  bnez       $v0, .L8003F298
    /* 2F834 8003F034 DA000424 */   addiu     $a0, $zero, 0xDA
    /* 2F838 8003F038 1800A28F */  lw         $v0, 0x18($sp)
    /* 2F83C 8003F03C 00000000 */  nop
    /* 2F840 8003F040 95004010 */  beqz       $v0, .L8003F298
    /* 2F844 8003F044 C3000424 */   addiu     $a0, $zero, 0xC3
    /* 2F848 8003F048 F1048293 */  lbu        $v0, %gp_rel(D_8009B3F9)($gp)
    /* 2F84C 8003F04C 00000000 */  nop
    /* 2F850 8003F050 10004238 */  xori       $v0, $v0, 0x10
    /* 2F854 8003F054 F10482A3 */  sb         $v0, %gp_rel(D_8009B3F9)($gp)
    /* 2F858 8003F058 04004010 */  beqz       $v0, .L8003F06C
    /* 2F85C 8003F05C 02000224 */   addiu     $v0, $zero, 0x2
    /* 2F860 8003F060 E30490A3 */  sb         $s0, %gp_rel(D_8009B3EB)($gp)
    /* 2F864 8003F064 A8FC0008 */  j          .L8003F2A0
    /* 2F868 8003F068 00000000 */   nop
  .L8003F06C:
    /* 2F86C 8003F06C E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
  .L8003F070:
    /* 2F870 8003F070 E3048493 */  lbu        $a0, %gp_rel(D_8009B3EB)($gp)
    /* 2F874 8003F074 00000000 */  nop
    /* 2F878 8003F078 80008230 */  andi       $v0, $a0, 0x80
    /* 2F87C 8003F07C 14004014 */  bnez       $v0, .L8003F0D0
    /* 2F880 8003F080 40008230 */   andi      $v0, $a0, 0x40
    /* 2F884 8003F084 0F80053C */  lui        $a1, %hi(D_800EFE18)
    /* 2F888 8003F088 18FEA524 */  addiu      $a1, $a1, %lo(D_800EFE18)
    /* 2F88C 8003F08C 1E80063C */  lui        $a2, %hi(D_801DC000)
    /* 2F890 8003F090 00C0C624 */  addiu      $a2, $a2, %lo(D_801DC000)
    /* 2F894 8003F094 80008234 */  ori        $v0, $a0, 0x80
    /* 2F898 8003F098 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F89C 8003F09C 80040224 */  addiu      $v0, $zero, 0x480
    /* 2F8A0 8003F0A0 F1048493 */  lbu        $a0, %gp_rel(D_8009B3F9)($gp)
    /* 2F8A4 8003F0A4 BC048797 */  lhu        $a3, %gp_rel(D_8009B3C4)($gp)
    /* 2F8A8 8003F0A8 1D80033C */  lui        $v1, %hi(D_801D5648)
    /* 2F8AC 8003F0AC E40480A3 */  sb         $zero, %gp_rel(D_8009B3EC)($gp)
    /* 2F8B0 8003F0B0 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2F8B4 8003F0B4 21108000 */  addu       $v0, $a0, $zero
    /* 2F8B8 8003F0B8 02110200 */  srl        $v0, $v0, 4
    /* 2F8BC 8003F0BC 01004224 */  addiu      $v0, $v0, 0x1
    /* 2F8C0 8003F0C0 8E31020C */  jal        func_8008C638
    /* 2F8C4 8003F0C4 485662AC */   sw        $v0, %lo(D_801D5648)($v1)
    /* 2F8C8 8003F0C8 84FC0008 */  j          .L8003F210
    /* 2F8CC 8003F0CC 00000000 */   nop
  .L8003F0D0:
    /* 2F8D0 8003F0D0 05004014 */  bnez       $v0, .L8003F0E8
    /* 2F8D4 8003F0D4 40008234 */   ori       $v0, $a0, 0x40
    /* 2F8D8 8003F0D8 EC04838F */  lw         $v1, %gp_rel(D_8009B3F4)($gp)
    /* 2F8DC 8003F0DC E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F8E0 8003F0E0 6D006014 */  bnez       $v1, .L8003F298
    /* 2F8E4 8003F0E4 DA000424 */   addiu     $a0, $zero, 0xDA
  .L8003F0E8:
    /* 2F8E8 8003F0E8 F1048293 */  lbu        $v0, %gp_rel(D_8009B3F9)($gp)
    /* 2F8EC 8003F0EC C804848F */  lw         $a0, %gp_rel(D_8009B3D0)($gp)
    /* 2F8F0 8003F0F0 02004010 */  beqz       $v0, .L8003F0FC
    /* 2F8F4 8003F0F4 1E80023C */   lui       $v0, %hi(D_801DC000)
    /* 2F8F8 8003F0F8 D804848F */  lw         $a0, %gp_rel(D_8009B3E0)($gp)
  .L8003F0FC:
    /* 2F8FC 8003F0FC 00C05024 */  addiu      $s0, $v0, %lo(D_801DC000)
    /* 2F900 8003F100 A2F4000C */  jal        func_8003D288
    /* 2F904 8003F104 21280002 */   addu      $a1, $s0, $zero
    /* 2F908 8003F108 16004014 */  bnez       $v0, .L8003F164
    /* 2F90C 8003F10C 00000000 */   nop
    /* 2F910 8003F110 E4048293 */  lbu        $v0, %gp_rel(D_8009B3EC)($gp)
    /* 2F914 8003F114 00000000 */  nop
    /* 2F918 8003F118 5F004014 */  bnez       $v0, .L8003F298
    /* 2F91C 8003F11C C3000424 */   addiu     $a0, $zero, 0xC3
    /* 2F920 8003F120 0F80053C */  lui        $a1, %hi(D_800EFE18)
    /* 2F924 8003F124 18FEA524 */  addiu      $a1, $a1, %lo(D_800EFE18)
    /* 2F928 8003F128 21300002 */  addu       $a2, $s0, $zero
    /* 2F92C 8003F12C F1048493 */  lbu        $a0, %gp_rel(D_8009B3F9)($gp)
    /* 2F930 8003F130 BC048797 */  lhu        $a3, %gp_rel(D_8009B3C4)($gp)
    /* 2F934 8003F134 01004224 */  addiu      $v0, $v0, 0x1
    /* 2F938 8003F138 E40482A3 */  sb         $v0, %gp_rel(D_8009B3EC)($gp)
    /* 2F93C 8003F13C 80040224 */  addiu      $v0, $zero, 0x480
    /* 2F940 8003F140 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2F944 8003F144 E3048293 */  lbu        $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F948 8003F148 00000000 */  nop
    /* 2F94C 8003F14C BF004230 */  andi       $v0, $v0, 0xBF
    /* 2F950 8003F150 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F954 8003F154 8E31020C */  jal        func_8008C638
    /* 2F958 8003F158 8006E724 */   addiu     $a3, $a3, 0x680
    /* 2F95C 8003F15C 84FC0008 */  j          .L8003F210
    /* 2F960 8003F160 00000000 */   nop
  .L8003F164:
    /* 2F964 8003F164 F1048293 */  lbu        $v0, %gp_rel(D_8009B3F9)($gp)
    /* 2F968 8003F168 00000000 */  nop
    /* 2F96C 8003F16C 10004238 */  xori       $v0, $v0, 0x10
    /* 2F970 8003F170 F10482A3 */  sb         $v0, %gp_rel(D_8009B3F9)($gp)
    /* 2F974 8003F174 04004010 */  beqz       $v0, .L8003F188
    /* 2F978 8003F178 02000224 */   addiu     $v0, $zero, 0x2
    /* 2F97C 8003F17C E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F980 8003F180 A8FC0008 */  j          .L8003F2A0
    /* 2F984 8003F184 00000000 */   nop
  .L8003F188:
    /* 2F988 8003F188 03000224 */  addiu      $v0, $zero, 0x3
    /* 2F98C 8003F18C E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
  .L8003F190:
    /* 2F990 8003F190 E3048393 */  lbu        $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2F994 8003F194 00000000 */  nop
    /* 2F998 8003F198 80006230 */  andi       $v0, $v1, 0x80
    /* 2F99C 8003F19C 09004014 */  bnez       $v0, .L8003F1C4
    /* 2F9A0 8003F1A0 40006230 */   andi      $v0, $v1, 0x40
    /* 2F9A4 8003F1A4 C0006234 */  ori        $v0, $v1, 0xC0
    /* 2F9A8 8003F1A8 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F9AC 8003F1AC C4000424 */  addiu      $a0, $zero, 0xC4
    /* 2F9B0 8003F1B0 1BF9000C */  jal        func_8003E46C
    /* 2F9B4 8003F1B4 21280000 */   addu      $a1, $zero, $zero
    /* 2F9B8 8003F1B8 E3048393 */  lbu        $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2F9BC 8003F1BC 00000000 */  nop
    /* 2F9C0 8003F1C0 40006230 */  andi       $v0, $v1, 0x40
  .L8003F1C4:
    /* 2F9C4 8003F1C4 18004010 */  beqz       $v0, .L8003F228
    /* 2F9C8 8003F1C8 00000000 */   nop
  .L8003F1CC:
    /* 2F9CC 8003F1CC E3048293 */  lbu        $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F9D0 8003F1D0 F1048393 */  lbu        $v1, %gp_rel(D_8009B3F9)($gp)
    /* 2F9D4 8003F1D4 BF004230 */  andi       $v0, $v0, 0xBF
    /* 2F9D8 8003F1D8 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2F9DC 8003F1DC 05006010 */  beqz       $v1, .L8003F1F4
    /* 2F9E0 8003F1E0 0F80053C */   lui       $a1, %hi(D_800EFE18)
    /* 2F9E4 8003F1E4 18FEA524 */  addiu      $a1, $a1, %lo(D_800EFE18)
    /* 2F9E8 8003F1E8 D804868F */  lw         $a2, %gp_rel(D_8009B3E0)($gp)
    /* 2F9EC 8003F1EC 80FC0008 */  j          .L8003F200
    /* 2F9F0 8003F1F0 21206000 */   addu      $a0, $v1, $zero
  .L8003F1F4:
    /* 2F9F4 8003F1F4 18FEA524 */  addiu      $a1, $a1, %lo(D_800EFE18)
    /* 2F9F8 8003F1F8 F1048493 */  lbu        $a0, %gp_rel(D_8009B3F9)($gp)
    /* 2F9FC 8003F1FC C804868F */  lw         $a2, %gp_rel(D_8009B3D0)($gp)
  .L8003F200:
    /* 2FA00 8003F200 BC048797 */  lhu        $a3, %gp_rel(D_8009B3C4)($gp)
    /* 2FA04 8003F204 80000224 */  addiu      $v0, $zero, 0x80
    /* 2FA08 8003F208 1632020C */  jal        func_8008C858
    /* 2FA0C 8003F20C 1000A2AF */   sw        $v0, 0x10($sp)
  .L8003F210:
    /* 2FA10 8003F210 F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2FA14 8003F214 00000000 */  nop
    /* 2FA18 8003F218 00104234 */  ori        $v0, $v0, 0x1000
    /* 2FA1C 8003F21C F20482A7 */  sh         $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2FA20 8003F220 A8FC0008 */  j          .L8003F2A0
    /* 2FA24 8003F224 00000000 */   nop
  .L8003F228:
    /* 2FA28 8003F228 EC04828F */  lw         $v0, %gp_rel(D_8009B3F4)($gp)
    /* 2FA2C 8003F22C 00000000 */  nop
    /* 2FA30 8003F230 19004014 */  bnez       $v0, .L8003F298
    /* 2FA34 8003F234 C5000424 */   addiu     $a0, $zero, 0xC5
    /* 2FA38 8003F238 F1048293 */  lbu        $v0, %gp_rel(D_8009B3F9)($gp)
    /* 2FA3C 8003F23C 40006334 */  ori        $v1, $v1, 0x40
    /* 2FA40 8003F240 E30483A3 */  sb         $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2FA44 8003F244 10004238 */  xori       $v0, $v0, 0x10
    /* 2FA48 8003F248 F10482A3 */  sb         $v0, %gp_rel(D_8009B3F9)($gp)
    /* 2FA4C 8003F24C DFFF4014 */  bnez       $v0, .L8003F1CC
    /* 2FA50 8003F250 00000000 */   nop
    /* 2FA54 8003F254 C804828F */  lw         $v0, %gp_rel(D_8009B3D0)($gp)
    /* 2FA58 8003F258 D804838F */  lw         $v1, %gp_rel(D_8009B3E0)($gp)
    /* 2FA5C 8003F25C 80004224 */  addiu      $v0, $v0, 0x80
    /* 2FA60 8003F260 C80482AF */  sw         $v0, %gp_rel(D_8009B3D0)($gp)
    /* 2FA64 8003F264 BC048297 */  lhu        $v0, %gp_rel(D_8009B3C4)($gp)
    /* 2FA68 8003F268 80006324 */  addiu      $v1, $v1, 0x80
    /* 2FA6C 8003F26C D80483AF */  sw         $v1, %gp_rel(D_8009B3E0)($gp)
    /* 2FA70 8003F270 BA048397 */  lhu        $v1, %gp_rel(D_8009B3C2)($gp)
    /* 2FA74 8003F274 80004224 */  addiu      $v0, $v0, 0x80
    /* 2FA78 8003F278 80FF6324 */  addiu      $v1, $v1, -0x80
    /* 2FA7C 8003F27C BA0483A7 */  sh         $v1, %gp_rel(D_8009B3C2)($gp)
    /* 2FA80 8003F280 FFFF6330 */  andi       $v1, $v1, 0xFFFF
    /* 2FA84 8003F284 BC0482A7 */  sh         $v0, %gp_rel(D_8009B3C4)($gp)
    /* 2FA88 8003F288 D0FF6014 */  bnez       $v1, .L8003F1CC
    /* 2FA8C 8003F28C 01000224 */   addiu     $v0, $zero, 0x1
    /* 2FA90 8003F290 E70482A3 */  sb         $v0, %gp_rel(D_8009B3EF)($gp)
    /* 2FA94 8003F294 C6000424 */  addiu      $a0, $zero, 0xC6
  .L8003F298:
    /* 2FA98 8003F298 1BF9000C */  jal        func_8003E46C
    /* 2FA9C 8003F29C 18000524 */   addiu     $a1, $zero, 0x18
  .L8003F2A0:
    /* 2FAA0 8003F2A0 2400BF8F */  lw         $ra, 0x24($sp)
    /* 2FAA4 8003F2A4 2000B08F */  lw         $s0, 0x20($sp)
    /* 2FAA8 8003F2A8 0800E003 */  jr         $ra
    /* 2FAAC 8003F2AC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003EED0
