nonmatching func_8002E730, 0x1E8

glabel func_8002E730
    /* 1EF30 8002E730 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 1EF34 8002E734 3000BFAF */  sw         $ra, 0x30($sp)
    /* 1EF38 8002E738 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 1EF3C 8002E73C EDB8000C */  jal        func_8002E3B4
    /* 1EF40 8002E740 2800B0AF */   sw        $s0, 0x28($sp)
    /* 1EF44 8002E744 12004014 */  bnez       $v0, .L8002E790
    /* 1EF48 8002E748 0002023C */   lui       $v0, (0x2000030 >> 16)
    /* 1EF4C 8002E74C 0F80053C */  lui        $a1, %hi(D_800E9D70)
    /* 1EF50 8002E750 709DA424 */  addiu      $a0, $a1, %lo(D_800E9D70)
    /* 1EF54 8002E754 40010624 */  addiu      $a2, $zero, 0x140
    /* 1EF58 8002E758 0A80033C */  lui        $v1, %hi(D_8009B0AC)
    /* 1EF5C 8002E75C ACB06390 */  lbu        $v1, %lo(D_8009B0AC)($v1)
    /* 1EF60 8002E760 A0000224 */  addiu      $v0, $zero, 0xA0
    /* 1EF64 8002E764 709DA0A4 */  sh         $zero, %lo(D_800E9D70)($a1)
    /* 1EF68 8002E768 020080A4 */  sh         $zero, 0x2($a0)
    /* 1EF6C 8002E76C 040086A4 */  sh         $a2, 0x4($a0)
    /* 1EF70 8002E770 02006014 */  bnez       $v1, .L8002E77C
    /* 1EF74 8002E774 060082A4 */   sh        $v0, 0x6($a0)
    /* 1EF78 8002E778 709DA6A4 */  sh         $a2, %lo(D_800E9D70)($a1)
  .L8002E77C:
    /* 1EF7C 8002E77C C0010524 */  addiu      $a1, $zero, 0x1C0
    /* 1EF80 8002E780 8EFE010C */  jal        func_8007FA38
    /* 1EF84 8002E784 00010624 */   addiu     $a2, $zero, 0x100
    /* 1EF88 8002E788 41BA0008 */  j          .L8002E904
    /* 1EF8C 8002E78C 00000000 */   nop
  .L8002E790:
    /* 1EF90 8002E790 30004234 */  ori        $v0, $v0, (0x2000030 & 0xFFFF)
    /* 1EF94 8002E794 0A80033C */  lui        $v1, %hi(D_8009B0F4)
    /* 1EF98 8002E798 F4B0638C */  lw         $v1, %lo(D_8009B0F4)($v1)
    /* 1EF9C 8002E79C 0A80043C */  lui        $a0, %hi(D_8009B134)
    /* 1EFA0 8002E7A0 34B1848C */  lw         $a0, %lo(D_8009B134)($a0)
    /* 1EFA4 8002E7A4 24186200 */  and        $v1, $v1, $v0
    /* 1EFA8 8002E7A8 25186400 */  or         $v1, $v1, $a0
    /* 1EFAC 8002E7AC 55006014 */  bnez       $v1, .L8002E904
    /* 1EFB0 8002E7B0 0F80023C */   lui       $v0, %hi(D_800E9ECE)
    /* 1EFB4 8002E7B4 CE9E4290 */  lbu        $v0, %lo(D_800E9ECE)($v0)
    /* 1EFB8 8002E7B8 00000000 */  nop
    /* 1EFBC 8002E7BC 80004230 */  andi       $v0, $v0, 0x80
    /* 1EFC0 8002E7C0 50004014 */  bnez       $v0, .L8002E904
    /* 1EFC4 8002E7C4 00000000 */   nop
    /* 1EFC8 8002E7C8 74038397 */  lhu        $v1, %gp_rel(D_8009B27C)($gp)
    /* 1EFCC 8002E7CC 00000000 */  nop
    /* 1EFD0 8002E7D0 00406230 */  andi       $v0, $v1, 0x4000
    /* 1EFD4 8002E7D4 32004014 */  bnez       $v0, .L8002E8A0
    /* 1EFD8 8002E7D8 00206230 */   andi      $v0, $v1, 0x2000
    /* 1EFDC 8002E7DC 00406234 */  ori        $v0, $v1, 0x4000
    /* 1EFE0 8002E7E0 740382A7 */  sh         $v0, %gp_rel(D_8009B27C)($gp)
    /* 1EFE4 8002E7E4 1B00010C */  jal        func_8004006C
    /* 1EFE8 8002E7E8 00000000 */   nop
    /* 1EFEC 8002E7EC 21204000 */  addu       $a0, $v0, $zero
    /* 1EFF0 8002E7F0 2B00010C */  jal        func_800400AC
    /* 1EFF4 8002E7F4 03000524 */   addiu     $a1, $zero, 0x3
    /* 1EFF8 8002E7F8 21804000 */  addu       $s0, $v0, $zero
    /* 1EFFC 8002E7FC 21200002 */  addu       $a0, $s0, $zero
    /* 1F000 8002E800 21280000 */  addu       $a1, $zero, $zero
    /* 1F004 8002E804 2130A000 */  addu       $a2, $a1, $zero
    /* 1F008 8002E808 A0000224 */  addiu      $v0, $zero, 0xA0
    /* 1F00C 8002E80C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1F010 8002E810 17000224 */  addiu      $v0, $zero, 0x17
    /* 1F014 8002E814 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 1F018 8002E818 F4000224 */  addiu      $v0, $zero, 0xF4
    /* 1F01C 8002E81C 40010724 */  addiu      $a3, $zero, 0x140
    /* 1F020 8002E820 1400A0AF */  sw         $zero, 0x14($sp)
    /* 1F024 8002E824 1800A0AF */  sw         $zero, 0x18($sp)
    /* 1F028 8002E828 2000A0AF */  sw         $zero, 0x20($sp)
    /* 1F02C 8002E82C 4401010C */  jal        func_80040510
    /* 1F030 8002E830 2400A2AF */   sw        $v0, 0x24($sp)
    /* 1F034 8002E834 0F80023C */  lui        $v0, %hi(D_800EAE98)
    /* 1F038 8002E838 98AE5124 */  addiu      $s1, $v0, %lo(D_800EAE98)
    /* 1F03C 8002E83C 21202002 */  addu       $a0, $s1, $zero
    /* 1F040 8002E840 0400028E */  lw         $v0, 0x4($s0)
    /* 1F044 8002E844 0002033C */  lui        $v1, (0x2000000 >> 16)
    /* 1F048 8002E848 780390AF */  sw         $s0, %gp_rel(D_8009B280)($gp)
    /* 1F04C 8002E84C 25104300 */  or         $v0, $v0, $v1
    /* 1F050 8002E850 03B8000C */  jal        func_8002E00C
    /* 1F054 8002E854 040002AE */   sw        $v0, 0x4($s0)
    /* 1F058 8002E858 A0038297 */  lhu        $v0, %gp_rel(D_8009B2A8)($gp)
    /* 1F05C 8002E85C A2038397 */  lhu        $v1, %gp_rel(D_8009B2AA)($gp)
    /* 1F060 8002E860 0A80043C */  lui        $a0, %hi(D_8009B145)
    /* 1F064 8002E864 45B18490 */  lbu        $a0, %lo(D_8009B145)($a0)
    /* 1F068 8002E868 0A80013C */  lui        $at, %hi(D_8009B146)
    /* 1F06C 8002E86C 46B122A4 */  sh         $v0, %lo(D_8009B146)($at)
    /* 1F070 8002E870 0A80013C */  lui        $at, %hi(D_8009B148)
    /* 1F074 8002E874 48B123A4 */  sh         $v1, %lo(D_8009B148)($at)
    /* 1F078 8002E878 03008014 */  bnez       $a0, .L8002E888
    /* 1F07C 8002E87C 00000000 */   nop
    /* 1F080 8002E880 2157000C */  jal        func_80015C84
    /* 1F084 8002E884 00000000 */   nop
  .L8002E888:
    /* 1F088 8002E888 68038597 */  lhu        $a1, %gp_rel(D_8009B270)($gp)
    /* 1F08C 8002E88C 21202002 */  addu       $a0, $s1, $zero
    /* 1F090 8002E890 CBB7000C */  jal        func_8002DF2C
    /* 1F094 8002E894 FF0FA530 */   andi      $a1, $a1, 0xFFF
    /* 1F098 8002E898 41BA0008 */  j          .L8002E904
    /* 1F09C 8002E89C 00000000 */   nop
  .L8002E8A0:
    /* 1F0A0 8002E8A0 17004014 */  bnez       $v0, .L8002E900
    /* 1F0A4 8002E8A4 00206234 */   ori       $v0, $v1, 0x2000
    /* 1F0A8 8002E8A8 7803848F */  lw         $a0, %gp_rel(D_8009B280)($gp)
    /* 1F0AC 8002E8AC 740382A7 */  sh         $v0, %gp_rel(D_8009B27C)($gp)
    /* 1F0B0 8002E8B0 DB00010C */  jal        func_8004036C
    /* 1F0B4 8002E8B4 00000000 */   nop
    /* 1F0B8 8002E8B8 0F80043C */  lui        $a0, %hi(D_800EAE98)
    /* 1F0BC 8002E8BC 98AE8424 */  addiu      $a0, $a0, %lo(D_800EAE98)
    /* 1F0C0 8002E8C0 4AB8000C */  jal        func_8002E128
    /* 1F0C4 8002E8C4 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 1F0C8 8002E8C8 0A80023C */  lui        $v0, %hi(D_8009B145)
    /* 1F0CC 8002E8CC 45B14290 */  lbu        $v0, %lo(D_8009B145)($v0)
    /* 1F0D0 8002E8D0 00000000 */  nop
    /* 1F0D4 8002E8D4 0B004014 */  bnez       $v0, .L8002E904
    /* 1F0D8 8002E8D8 00000000 */   nop
    /* 1F0DC 8002E8DC 68038297 */  lhu        $v0, %gp_rel(D_8009B270)($gp)
    /* 1F0E0 8002E8E0 00000000 */  nop
    /* 1F0E4 8002E8E4 00404230 */  andi       $v0, $v0, 0x4000
    /* 1F0E8 8002E8E8 06004014 */  bnez       $v0, .L8002E904
    /* 1F0EC 8002E8EC 00000000 */   nop
    /* 1F0F0 8002E8F0 0357000C */  jal        func_80015C0C
    /* 1F0F4 8002E8F4 00000000 */   nop
    /* 1F0F8 8002E8F8 41BA0008 */  j          .L8002E904
    /* 1F0FC 8002E8FC 00000000 */   nop
  .L8002E900:
    /* 1F100 8002E900 740380A7 */  sh         $zero, %gp_rel(D_8009B27C)($gp)
  .L8002E904:
    /* 1F104 8002E904 3000BF8F */  lw         $ra, 0x30($sp)
    /* 1F108 8002E908 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 1F10C 8002E90C 2800B08F */  lw         $s0, 0x28($sp)
    /* 1F110 8002E910 0800E003 */  jr         $ra
    /* 1F114 8002E914 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8002E730
