nonmatching func_8003E490, 0x344

glabel func_8003E490
    /* 2EC90 8003E490 E3048293 */  lbu        $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2EC94 8003E494 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2EC98 8003E498 0F004330 */  andi       $v1, $v0, 0xF
    /* 2EC9C 8003E49C 0A00622C */  sltiu      $v0, $v1, 0xA
    /* 2ECA0 8003E4A0 C8004010 */  beqz       $v0, .L8003E7C4
    /* 2ECA4 8003E4A4 2000BFAF */   sw        $ra, 0x20($sp)
    /* 2ECA8 8003E4A8 0180023C */  lui        $v0, %hi(jtbl_80010410)
    /* 2ECAC 8003E4AC 10044224 */  addiu      $v0, $v0, %lo(jtbl_80010410)
    /* 2ECB0 8003E4B0 80180300 */  sll        $v1, $v1, 2
    /* 2ECB4 8003E4B4 21186200 */  addu       $v1, $v1, $v0
    /* 2ECB8 8003E4B8 0000628C */  lw         $v0, 0x0($v1)
    /* 2ECBC 8003E4BC 00000000 */  nop
    /* 2ECC0 8003E4C0 08004000 */  jr         $v0
    /* 2ECC4 8003E4C4 00000000 */   nop
  jlabel .L8003E4C8
    /* 2ECC8 8003E4C8 E3048393 */  lbu        $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2ECCC 8003E4CC 00000000 */  nop
    /* 2ECD0 8003E4D0 80006230 */  andi       $v0, $v1, 0x80
    /* 2ECD4 8003E4D4 06004014 */  bnez       $v0, .L8003E4F0
    /* 2ECD8 8003E4D8 01000224 */   addiu     $v0, $zero, 0x1
    /* 2ECDC 8003E4DC 80006234 */  ori        $v0, $v1, 0x80
    /* 2ECE0 8003E4E0 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2ECE4 8003E4E4 C8000424 */  addiu      $a0, $zero, 0xC8
    /* 2ECE8 8003E4E8 EFF90008 */  j          .L8003E7BC
    /* 2ECEC 8003E4EC 20000524 */   addiu     $a1, $zero, 0x20
  .L8003E4F0:
    /* 2ECF0 8003E4F0 0A80033C */  lui        $v1, %hi(D_8009B34D)
    /* 2ECF4 8003E4F4 4DB36380 */  lb         $v1, %lo(D_8009B34D)($v1)
    /* 2ECF8 8003E4F8 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2ECFC 8003E4FC 04006010 */  beqz       $v1, .L8003E510
    /* 2ED00 8003E500 09000224 */   addiu     $v0, $zero, 0x9
    /* 2ED04 8003E504 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2ED08 8003E508 F1F90008 */  j          .L8003E7C4
    /* 2ED0C 8003E50C 00000000 */   nop
  jlabel .L8003E510
    /* 2ED10 8003E510 E3048393 */  lbu        $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2ED14 8003E514 00000000 */  nop
    /* 2ED18 8003E518 80006230 */  andi       $v0, $v1, 0x80
    /* 2ED1C 8003E51C 16004014 */  bnez       $v0, .L8003E578
    /* 2ED20 8003E520 D4000524 */   addiu     $a1, $zero, 0xD4
    /* 2ED24 8003E524 80006234 */  ori        $v0, $v1, 0x80
    /* 2ED28 8003E528 1D80043C */  lui        $a0, %hi(D_801D5648)
    /* 2ED2C 8003E52C E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2ED30 8003E530 F1048293 */  lbu        $v0, %gp_rel(D_8009B3F9)($gp)
    /* 2ED34 8003E534 F2048397 */  lhu        $v1, %gp_rel(D_8009B3FA)($gp)
    /* 2ED38 8003E538 02110200 */  srl        $v0, $v0, 4
    /* 2ED3C 8003E53C 01004224 */  addiu      $v0, $v0, 0x1
    /* 2ED40 8003E540 00026330 */  andi       $v1, $v1, 0x200
    /* 2ED44 8003E544 02006010 */  beqz       $v1, .L8003E550
    /* 2ED48 8003E548 485682AC */   sw        $v0, %lo(D_801D5648)($a0)
    /* 2ED4C 8003E54C C0000524 */  addiu      $a1, $zero, 0xC0
  .L8003E550:
    /* 2ED50 8003E550 2120A000 */  addu       $a0, $a1, $zero
    /* 2ED54 8003E554 1BF9000C */  jal        func_8003E46C
    /* 2ED58 8003E558 21280000 */   addu      $a1, $zero, $zero
  .L8003E55C:
    /* 2ED5C 8003E55C F1048493 */  lbu        $a0, %gp_rel(D_8009B3F9)($gp)
    /* 2ED60 8003E560 242F020C */  jal        func_8008BC90
    /* 2ED64 8003E564 00000000 */   nop
    /* 2ED68 8003E568 FCFF4010 */  beqz       $v0, .L8003E55C
    /* 2ED6C 8003E56C 00000000 */   nop
    /* 2ED70 8003E570 90F90008 */  j          .L8003E640
    /* 2ED74 8003E574 00000000 */   nop
  .L8003E578:
    /* 2ED78 8003E578 EC04838F */  lw         $v1, %gp_rel(D_8009B3F4)($gp)
    /* 2ED7C 8003E57C 00000000 */  nop
    /* 2ED80 8003E580 0500622C */  sltiu      $v0, $v1, 0x5
    /* 2ED84 8003E584 8F004010 */  beqz       $v0, .L8003E7C4
    /* 2ED88 8003E588 0180023C */   lui       $v0, %hi(jtbl_80010438)
    /* 2ED8C 8003E58C 38044224 */  addiu      $v0, $v0, %lo(jtbl_80010438)
    /* 2ED90 8003E590 80180300 */  sll        $v1, $v1, 2
    /* 2ED94 8003E594 21186200 */  addu       $v1, $v1, $v0
    /* 2ED98 8003E598 0000628C */  lw         $v0, 0x0($v1)
    /* 2ED9C 8003E59C 00000000 */  nop
    /* 2EDA0 8003E5A0 08004000 */  jr         $v0
    /* 2EDA4 8003E5A4 00000000 */   nop
  jlabel .L8003E5A8
    /* 2EDA8 8003E5A8 02000224 */  addiu      $v0, $zero, 0x2
    /* 2EDAC 8003E5AC E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2EDB0 8003E5B0 F1F90008 */  j          .L8003E7C4
    /* 2EDB4 8003E5B4 00000000 */   nop
  jlabel .L8003E5B8
    /* 2EDB8 8003E5B8 0F80053C */  lui        $a1, %hi(D_800EFE18)
    /* 2EDBC 8003E5BC 18FEA524 */  addiu      $a1, $a1, %lo(D_800EFE18)
    /* 2EDC0 8003E5C0 0F80063C */  lui        $a2, %hi(D_800EFBC0)
    /* 2EDC4 8003E5C4 C0FBC624 */  addiu      $a2, $a2, %lo(D_800EFBC0)
    /* 2EDC8 8003E5C8 1800A727 */  addiu      $a3, $sp, 0x18
    /* 2EDCC 8003E5CC F1048493 */  lbu        $a0, %gp_rel(D_8009B3F9)($gp)
    /* 2EDD0 8003E5D0 0F000224 */  addiu      $v0, $zero, 0xF
    /* 2EDD4 8003E5D4 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2EDD8 8003E5D8 9E32020C */  jal        func_8008CA78
    /* 2EDDC 8003E5DC 1400A2AF */   sw        $v0, 0x14($sp)
    /* 2EDE0 8003E5E0 42004014 */  bnez       $v0, .L8003E6EC
    /* 2EDE4 8003E5E4 06000224 */   addiu     $v0, $zero, 0x6
    /* 2EDE8 8003E5E8 1800A28F */  lw         $v0, 0x18($sp)
    /* 2EDEC 8003E5EC 00000000 */  nop
    /* 2EDF0 8003E5F0 3D004010 */  beqz       $v0, .L8003E6E8
    /* 2EDF4 8003E5F4 03000224 */   addiu     $v0, $zero, 0x3
    /* 2EDF8 8003E5F8 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
  jlabel .L8003E5FC
    /* 2EDFC 8003E5FC E3048393 */  lbu        $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2EE00 8003E600 00000000 */  nop
    /* 2EE04 8003E604 80006230 */  andi       $v0, $v1, 0x80
    /* 2EE08 8003E608 13004014 */  bnez       $v0, .L8003E658
    /* 2EE0C 8003E60C D5000424 */   addiu     $a0, $zero, 0xD5
    /* 2EE10 8003E610 80006234 */  ori        $v0, $v1, 0x80
    /* 2EE14 8003E614 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2EE18 8003E618 1BF9000C */  jal        func_8003E46C
    /* 2EE1C 8003E61C 21280000 */   addu      $a1, $zero, $zero
    /* 2EE20 8003E620 0F80053C */  lui        $a1, %hi(D_800EFE18)
    /* 2EE24 8003E624 F1048493 */  lbu        $a0, %gp_rel(D_8009B3F9)($gp)
    /* 2EE28 8003E628 C804868F */  lw         $a2, %gp_rel(D_8009B3D0)($gp)
    /* 2EE2C 8003E62C BC048797 */  lhu        $a3, %gp_rel(D_8009B3C4)($gp)
    /* 2EE30 8003E630 BA048297 */  lhu        $v0, %gp_rel(D_8009B3C2)($gp)
    /* 2EE34 8003E634 18FEA524 */  addiu      $a1, $a1, %lo(D_800EFE18)
    /* 2EE38 8003E638 8E31020C */  jal        func_8008C638
    /* 2EE3C 8003E63C 1000A2AF */   sw        $v0, 0x10($sp)
  .L8003E640:
    /* 2EE40 8003E640 F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2EE44 8003E644 00000000 */  nop
    /* 2EE48 8003E648 00104234 */  ori        $v0, $v0, 0x1000
    /* 2EE4C 8003E64C F20482A7 */  sh         $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2EE50 8003E650 F1F90008 */  j          .L8003E7C4
    /* 2EE54 8003E654 00000000 */   nop
  .L8003E658:
    /* 2EE58 8003E658 EC04838F */  lw         $v1, %gp_rel(D_8009B3F4)($gp)
    /* 2EE5C 8003E65C 00000000 */  nop
    /* 2EE60 8003E660 0600622C */  sltiu      $v0, $v1, 0x6
    /* 2EE64 8003E664 57004010 */  beqz       $v0, .L8003E7C4
    /* 2EE68 8003E668 0180023C */   lui       $v0, %hi(jtbl_80010450)
    /* 2EE6C 8003E66C 50044224 */  addiu      $v0, $v0, %lo(jtbl_80010450)
    /* 2EE70 8003E670 80180300 */  sll        $v1, $v1, 2
    /* 2EE74 8003E674 21186200 */  addu       $v1, $v1, $v0
    /* 2EE78 8003E678 0000628C */  lw         $v0, 0x0($v1)
    /* 2EE7C 8003E67C 00000000 */  nop
    /* 2EE80 8003E680 08004000 */  jr         $v0
    /* 2EE84 8003E684 00000000 */   nop
  jlabel .L8003E688
    /* 2EE88 8003E688 C804848F */  lw         $a0, %gp_rel(D_8009B3D0)($gp)
    /* 2EE8C 8003E68C 07000224 */  addiu      $v0, $zero, 0x7
    /* 2EE90 8003E690 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2EE94 8003E694 5DF4000C */  jal        func_8003D174
    /* 2EE98 8003E698 00000000 */   nop
    /* 2EE9C 8003E69C 49004014 */  bnez       $v0, .L8003E7C4
    /* 2EEA0 8003E6A0 04000224 */   addiu     $v0, $zero, 0x4
    /* 2EEA4 8003E6A4 F2048397 */  lhu        $v1, %gp_rel(D_8009B3FA)($gp)
    /* 2EEA8 8003E6A8 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2EEAC 8003E6AC 00046230 */  andi       $v0, $v1, 0x400
    /* 2EEB0 8003E6B0 41004014 */  bnez       $v0, .L8003E7B8
    /* 2EEB4 8003E6B4 BD000424 */   addiu     $a0, $zero, 0xBD
    /* 2EEB8 8003E6B8 00046234 */  ori        $v0, $v1, 0x400
    /* 2EEBC 8003E6BC F20482A7 */  sh         $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2EEC0 8003E6C0 F1F90008 */  j          .L8003E7C4
    /* 2EEC4 8003E6C4 00000000 */   nop
  jlabel .L8003E6C8
    /* 2EEC8 8003E6C8 05000224 */  addiu      $v0, $zero, 0x5
    /* 2EECC 8003E6CC E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2EED0 8003E6D0 F1F90008 */  j          .L8003E7C4
    /* 2EED4 8003E6D4 00000000 */   nop
  jlabel .L8003E6D8
    /* 2EED8 8003E6D8 08000224 */  addiu      $v0, $zero, 0x8
    /* 2EEDC 8003E6DC E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2EEE0 8003E6E0 F1F90008 */  j          .L8003E7C4
    /* 2EEE4 8003E6E4 00000000 */   nop
  jlabel .L8003E6E8
    /* 2EEE8 8003E6E8 06000224 */  addiu      $v0, $zero, 0x6
  .L8003E6EC:
    /* 2EEEC 8003E6EC E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2EEF0 8003E6F0 F1F90008 */  j          .L8003E7C4
    /* 2EEF4 8003E6F4 00000000 */   nop
  jlabel .L8003E6F8
    /* 2EEF8 8003E6F8 E3048393 */  lbu        $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2EEFC 8003E6FC 00000000 */  nop
    /* 2EF00 8003E700 80006230 */  andi       $v0, $v1, 0x80
    /* 2EF04 8003E704 06004014 */  bnez       $v0, .L8003E720
    /* 2EF08 8003E708 40006230 */   andi      $v0, $v1, 0x40
    /* 2EF0C 8003E70C 80006234 */  ori        $v0, $v1, 0x80
    /* 2EF10 8003E710 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2EF14 8003E714 BD000424 */  addiu      $a0, $zero, 0xBD
    /* 2EF18 8003E718 EFF90008 */  j          .L8003E7BC
    /* 2EF1C 8003E71C 10000524 */   addiu     $a1, $zero, 0x10
  .L8003E720:
    /* 2EF20 8003E720 06004014 */  bnez       $v0, .L8003E73C
    /* 2EF24 8003E724 09000224 */   addiu     $v0, $zero, 0x9
    /* 2EF28 8003E728 40006234 */  ori        $v0, $v1, 0x40
    /* 2EF2C 8003E72C E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2EF30 8003E730 BC000424 */  addiu      $a0, $zero, 0xBC
    /* 2EF34 8003E734 EFF90008 */  j          .L8003E7BC
    /* 2EF38 8003E738 20000524 */   addiu     $a1, $zero, 0x20
  .L8003E73C:
    /* 2EF3C 8003E73C 0A80033C */  lui        $v1, %hi(D_8009B34D)
    /* 2EF40 8003E740 4DB36380 */  lb         $v1, %lo(D_8009B34D)($v1)
    /* 2EF44 8003E744 E30482A3 */  sb         $v0, %gp_rel(D_8009B3EB)($gp)
    /* 2EF48 8003E748 1E006014 */  bnez       $v1, .L8003E7C4
    /* 2EF4C 8003E74C 03000324 */   addiu     $v1, $zero, 0x3
    /* 2EF50 8003E750 BC048297 */  lhu        $v0, %gp_rel(D_8009B3C4)($gp)
    /* 2EF54 8003E754 E30483A3 */  sb         $v1, %gp_rel(D_8009B3EB)($gp)
    /* 2EF58 8003E758 80064224 */  addiu      $v0, $v0, 0x680
    /* 2EF5C 8003E75C BC0482A7 */  sh         $v0, %gp_rel(D_8009B3C4)($gp)
    /* 2EF60 8003E760 F1F90008 */  j          .L8003E7C4
    /* 2EF64 8003E764 00000000 */   nop
  jlabel .L8003E768
    /* 2EF68 8003E768 EEF90008 */  j          .L8003E7B8
    /* 2EF6C 8003E76C C1000424 */   addiu     $a0, $zero, 0xC1
  jlabel .L8003E770
    /* 2EF70 8003E770 EEF90008 */  j          .L8003E7B8
    /* 2EF74 8003E774 D3000424 */   addiu     $a0, $zero, 0xD3
  jlabel .L8003E778
    /* 2EF78 8003E778 F2048297 */  lhu        $v0, %gp_rel(D_8009B3FA)($gp)
    /* 2EF7C 8003E77C 01000324 */  addiu      $v1, $zero, 0x1
    /* 2EF80 8003E780 E70483A3 */  sb         $v1, %gp_rel(D_8009B3EF)($gp)
    /* 2EF84 8003E784 00024230 */  andi       $v0, $v0, 0x200
    /* 2EF88 8003E788 03004010 */  beqz       $v0, .L8003E798
    /* 2EF8C 8003E78C D0000424 */   addiu     $a0, $zero, 0xD0
    /* 2EF90 8003E790 EFF90008 */  j          .L8003E7BC
    /* 2EF94 8003E794 08000524 */   addiu     $a1, $zero, 0x8
  .L8003E798:
    /* 2EF98 8003E798 CC0480A3 */  sb         $zero, %gp_rel(D_8009B3D4)($gp)
    /* 2EF9C 8003E79C EFF90008 */  j          .L8003E7BC
    /* 2EFA0 8003E7A0 18000524 */   addiu     $a1, $zero, 0x18
  jlabel .L8003E7A4
    /* 2EFA4 8003E7A4 EEF90008 */  j          .L8003E7B8
    /* 2EFA8 8003E7A8 D3000424 */   addiu     $a0, $zero, 0xD3
  jlabel .L8003E7AC
    /* 2EFAC 8003E7AC 03000224 */  addiu      $v0, $zero, 0x3
    /* 2EFB0 8003E7B0 E70482A3 */  sb         $v0, %gp_rel(D_8009B3EF)($gp)
    /* 2EFB4 8003E7B4 C7000424 */  addiu      $a0, $zero, 0xC7
  .L8003E7B8:
    /* 2EFB8 8003E7B8 18000524 */  addiu      $a1, $zero, 0x18
  .L8003E7BC:
    /* 2EFBC 8003E7BC 1BF9000C */  jal        func_8003E46C
    /* 2EFC0 8003E7C0 00000000 */   nop
  jlabel .L8003E7C4
    /* 2EFC4 8003E7C4 2000BF8F */  lw         $ra, 0x20($sp)
    /* 2EFC8 8003E7C8 00000000 */  nop
    /* 2EFCC 8003E7CC 0800E003 */  jr         $ra
    /* 2EFD0 8003E7D0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003E490
