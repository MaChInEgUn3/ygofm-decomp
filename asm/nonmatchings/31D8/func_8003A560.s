nonmatching func_8003A560, 0x3C0

glabel func_8003A560
    /* 2AD60 8003A560 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 2AD64 8003A564 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 2AD68 8003A568 21988000 */  addu       $s3, $a0, $zero
    /* 2AD6C 8003A56C 3400BFAF */  sw         $ra, 0x34($sp)
    /* 2AD70 8003A570 3000B4AF */  sw         $s4, 0x30($sp)
    /* 2AD74 8003A574 2800B2AF */  sw         $s2, 0x28($sp)
    /* 2AD78 8003A578 2400B1AF */  sw         $s1, 0x24($sp)
    /* 2AD7C 8003A57C C7E7000C */  jal        func_80039F1C
    /* 2AD80 8003A580 2000B0AF */   sw        $s0, 0x20($sp)
    /* 2AD84 8003A584 80004014 */  bnez       $v0, .L8003A788
    /* 2AD88 8003A588 0600023C */   lui       $v0, (0x63040 >> 16)
    /* 2AD8C 8003A58C 40304234 */  ori        $v0, $v0, (0x63040 & 0xFFFF)
    /* 2AD90 8003A590 04000424 */  addiu      $a0, $zero, 0x4
    /* 2AD94 8003A594 1680033C */  lui        $v1, %hi(D_8015C410)
    /* 2AD98 8003A598 10C46524 */  addiu      $a1, $v1, %lo(D_8015C410)
    /* 2AD9C 8003A59C 00011424 */  addiu      $s4, $zero, 0x100
    /* 2ADA0 8003A5A0 0100113C */  lui        $s1, (0x18400 >> 16)
    /* 2ADA4 8003A5A4 0180033C */  lui        $v1, %hi(D_80010000)
    /* 2ADA8 8003A5A8 0000638C */  lw         $v1, %lo(D_80010000)($v1)
    /* 2ADAC 8003A5AC 00843136 */  ori        $s1, $s1, (0x18400 & 0xFFFF)
    /* 2ADB0 8003A5B0 1E0480A3 */  sb         $zero, %gp_rel(D_8009B326)($gp)
    /* 2ADB4 8003A5B4 21906200 */  addu       $s2, $v1, $v0
  .L8003A5B8:
    /* 2ADB8 8003A5B8 21188500 */  addu       $v1, $a0, $a1
    /* 2ADBC 8003A5BC 00006280 */  lb         $v0, 0x0($v1)
    /* 2ADC0 8003A5C0 00000000 */  nop
    /* 2ADC4 8003A5C4 03004104 */  bgez       $v0, .L8003A5D4
    /* 2ADC8 8003A5C8 00000000 */   nop
    /* 2ADCC 8003A5CC 1E0484A3 */  sb         $a0, %gp_rel(D_8009B326)($gp)
    /* 2ADD0 8003A5D0 00006280 */  lb         $v0, 0x0($v1)
  .L8003A5D4:
    /* 2ADD4 8003A5D4 30006782 */  lb         $a3, 0x30($s3)
    /* 2ADD8 8003A5D8 00000000 */  nop
    /* 2ADDC 8003A5DC 35004714 */  bne        $v0, $a3, .L8003A6B4
    /* 2ADE0 8003A5E0 FEFF023C */   lui       $v0, (0xFFFE73F0 >> 16)
  .L8003A5E4:
    /* 2ADE4 8003A5E4 C908020C */  jal        func_80082324
    /* 2ADE8 8003A5E8 0A000424 */   addiu     $a0, $zero, 0xA
    /* 2ADEC 8003A5EC FDFF4014 */  bnez       $v0, .L8003A5E4
    /* 2ADF0 8003A5F0 0100103C */   lui       $s0, (0x18000 >> 16)
    /* 2ADF4 8003A5F4 00801036 */  ori        $s0, $s0, (0x18000 & 0xFFFF)
    /* 2ADF8 8003A5F8 0100043C */  lui        $a0, (0x18C00 >> 16)
    /* 2ADFC 8003A5FC 008C8434 */  ori        $a0, $a0, (0x18C00 & 0xFFFF)
    /* 2AE00 8003A600 21204402 */  addu       $a0, $s2, $a0
    /* 2AE04 8003A604 21284002 */  addu       $a1, $s2, $zero
    /* 2AE08 8003A608 21805002 */  addu       $s0, $s2, $s0
    /* 2AE0C 8003A60C 3C006692 */  lbu        $a2, 0x3C($s3)
    /* 2AE10 8003A610 C0000224 */  addiu      $v0, $zero, 0xC0
    /* 2AE14 8003A614 040C02A6 */  sh         $v0, 0xC04($s0)
    /* 2AE18 8003A618 40030224 */  addiu      $v0, $zero, 0x340
    /* 2AE1C 8003A61C 020C14A6 */  sh         $s4, 0xC02($s0)
    /* 2AE20 8003A620 060C14A6 */  sh         $s4, 0xC06($s0)
    /* 2AE24 8003A624 40180600 */  sll        $v1, $a2, 1
    /* 2AE28 8003A628 21186600 */  addu       $v1, $v1, $a2
    /* 2AE2C 8003A62C 80190300 */  sll        $v1, $v1, 6
    /* 2AE30 8003A630 23104300 */  subu       $v0, $v0, $v1
    /* 2AE34 8003A634 5EFE010C */  jal        func_8007F978
    /* 2AE38 8003A638 000C02A6 */   sh        $v0, 0xC00($s0)
    /* 2AE3C 8003A63C 0100043C */  lui        $a0, (0x18C08 >> 16)
    /* 2AE40 8003A640 088C8434 */  ori        $a0, $a0, (0x18C08 & 0xFFFF)
    /* 2AE44 8003A644 21204402 */  addu       $a0, $s2, $a0
    /* 2AE48 8003A648 00020224 */  addiu      $v0, $zero, 0x200
    /* 2AE4C 8003A64C 21280002 */  addu       $a1, $s0, $zero
    /* 2AE50 8003A650 080C02A6 */  sh         $v0, 0xC08($s0)
    /* 2AE54 8003A654 3C006392 */  lbu        $v1, 0x3C($s3)
    /* 2AE58 8003A658 02000224 */  addiu      $v0, $zero, 0x2
    /* 2AE5C 8003A65C 0C0CB4A4 */  sh         $s4, 0xC0C($a1)
    /* 2AE60 8003A660 0E0CA2A4 */  sh         $v0, 0xC0E($a1)
    /* 2AE64 8003A664 40180300 */  sll        $v1, $v1, 1
    /* 2AE68 8003A668 F0006324 */  addiu      $v1, $v1, 0xF0
    /* 2AE6C 8003A66C 5EFE010C */  jal        func_8007F978
    /* 2AE70 8003A670 0A0CA3A4 */   sh        $v1, 0xC0A($a1)
    /* 2AE74 8003A674 3C006292 */  lbu        $v0, 0x3C($s3)
    /* 2AE78 8003A678 00000000 */  nop
    /* 2AE7C 8003A67C 03004010 */  beqz       $v0, .L8003A68C
    /* 2AE80 8003A680 1B80043C */   lui       $a0, %hi(D_801AF800)
    /* 2AE84 8003A684 A5E90008 */  j          .L8003A694
    /* 2AE88 8003A688 00F88424 */   addiu     $a0, $a0, %lo(D_801AF800)
  .L8003A68C:
    /* 2AE8C 8003A68C 1B80043C */  lui        $a0, %hi(D_801AF000)
    /* 2AE90 8003A690 00F08424 */  addiu      $a0, $a0, %lo(D_801AF000)
  .L8003A694:
    /* 2AE94 8003A694 21285102 */  addu       $a1, $s2, $s1
    /* 2AE98 8003A698 A8D5000C */  jal        func_800356A0
    /* 2AE9C 8003A69C 00080624 */   addiu     $a2, $zero, 0x800
    /* 2AEA0 8003A6A0 33006292 */  lbu        $v0, 0x33($s3)
    /* 2AEA4 8003A6A4 00000000 */  nop
    /* 2AEA8 8003A6A8 40004234 */  ori        $v0, $v0, 0x40
    /* 2AEAC 8003A6AC 40EA0008 */  j          .L8003A900
    /* 2AEB0 8003A6B0 330062A2 */   sb        $v0, 0x33($s3)
  .L8003A6B4:
    /* 2AEB4 8003A6B4 F0734234 */  ori        $v0, $v0, (0xFFFE73F0 & 0xFFFF)
    /* 2AEB8 8003A6B8 FFFF8424 */  addiu      $a0, $a0, -0x1
    /* 2AEBC 8003A6BC BEFF8104 */  bgez       $a0, .L8003A5B8
    /* 2AEC0 8003A6C0 21904202 */   addu      $s2, $s2, $v0
    /* 2AEC4 8003A6C4 0002023C */  lui        $v0, (0x2000030 >> 16)
    /* 2AEC8 8003A6C8 30004234 */  ori        $v0, $v0, (0x2000030 & 0xFFFF)
    /* 2AECC 8003A6CC 0A80033C */  lui        $v1, %hi(D_8009B0F4)
    /* 2AED0 8003A6D0 F4B0638C */  lw         $v1, %lo(D_8009B0F4)($v1)
    /* 2AED4 8003A6D4 0A80043C */  lui        $a0, %hi(D_8009B134)
    /* 2AED8 8003A6D8 34B1848C */  lw         $a0, %lo(D_8009B134)($a0)
    /* 2AEDC 8003A6DC 24186200 */  and        $v1, $v1, $v0
    /* 2AEE0 8003A6E0 25186400 */  or         $v1, $v1, $a0
    /* 2AEE4 8003A6E4 06006010 */  beqz       $v1, .L8003A700
    /* 2AEE8 8003A6E8 21200000 */   addu      $a0, $zero, $zero
    /* 2AEEC 8003A6EC 33006292 */  lbu        $v0, 0x33($s3)
    /* 2AEF0 8003A6F0 00000000 */  nop
    /* 2AEF4 8003A6F4 7F004230 */  andi       $v0, $v0, 0x7F
    /* 2AEF8 8003A6F8 40EA0008 */  j          .L8003A900
    /* 2AEFC 8003A6FC 330062A2 */   sb        $v0, 0x33($s3)
  .L8003A700:
    /* 2AF00 8003A700 21288000 */  addu       $a1, $a0, $zero
    /* 2AF04 8003A704 40300700 */  sll        $a2, $a3, 1
    /* 2AF08 8003A708 2130C700 */  addu       $a2, $a2, $a3
    /* 2AF0C 8003A70C C0300600 */  sll        $a2, $a2, 3
    /* 2AF10 8003A710 2130C700 */  addu       $a2, $a2, $a3
    /* 2AF14 8003A714 40300600 */  sll        $a2, $a2, 1
    /* 2AF18 8003A718 4E3BC624 */  addiu      $a2, $a2, 0x3B4E
    /* 2AF1C 8003A71C 0480023C */  lui        $v0, %hi(func_8003A01C)
    /* 2AF20 8003A720 1CA04224 */  addiu      $v0, $v0, %lo(func_8003A01C)
    /* 2AF24 8003A724 32000724 */  addiu      $a3, $zero, 0x32
    /* 2AF28 8003A728 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2AF2C 8003A72C 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2AF30 8003A730 BB53000C */  jal        func_80014EEC
    /* 2AF34 8003A734 1800A0AF */   sw        $zero, 0x18($sp)
    /* 2AF38 8003A738 21184000 */  addu       $v1, $v0, $zero
    /* 2AF3C 8003A73C 1B80023C */  lui        $v0, %hi(D_801AF000)
    /* 2AF40 8003A740 00F04224 */  addiu      $v0, $v0, %lo(D_801AF000)
    /* 2AF44 8003A744 380062AC */  sw         $v0, 0x38($v1)
    /* 2AF48 8003A748 3C006292 */  lbu        $v0, 0x3C($s3)
    /* 2AF4C 8003A74C 00000000 */  nop
    /* 2AF50 8003A750 3C0062AC */  sw         $v0, 0x3C($v1)
    /* 2AF54 8003A754 3C006292 */  lbu        $v0, 0x3C($s3)
    /* 2AF58 8003A758 00000000 */  nop
    /* 2AF5C 8003A75C 03004010 */  beqz       $v0, .L8003A76C
    /* 2AF60 8003A760 1B80023C */   lui       $v0, %hi(D_801AF800)
    /* 2AF64 8003A764 00F84224 */  addiu      $v0, $v0, %lo(D_801AF800)
    /* 2AF68 8003A768 380062AC */  sw         $v0, 0x38($v1)
  .L8003A76C:
    /* 2AF6C 8003A76C 2C00628C */  lw         $v0, 0x2C($v1)
    /* 2AF70 8003A770 00000000 */  nop
    /* 2AF74 8003A774 10004234 */  ori        $v0, $v0, 0x10
    /* 2AF78 8003A778 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2AF7C 8003A77C F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2AF80 8003A780 40EA0008 */  j          .L8003A900
    /* 2AF84 8003A784 00000000 */   nop
  .L8003A788:
    /* 2AF88 8003A788 33006592 */  lbu        $a1, 0x33($s3)
    /* 2AF8C 8003A78C 00000000 */  nop
    /* 2AF90 8003A790 4000A230 */  andi       $v0, $a1, 0x40
    /* 2AF94 8003A794 53004014 */  bnez       $v0, .L8003A8E4
    /* 2AF98 8003A798 21206002 */   addu      $a0, $s3, $zero
    /* 2AF9C 8003A79C 0002023C */  lui        $v0, (0x2000030 >> 16)
    /* 2AFA0 8003A7A0 30004234 */  ori        $v0, $v0, (0x2000030 & 0xFFFF)
    /* 2AFA4 8003A7A4 0A80033C */  lui        $v1, %hi(D_8009B0F4)
    /* 2AFA8 8003A7A8 F4B0638C */  lw         $v1, %lo(D_8009B0F4)($v1)
    /* 2AFAC 8003A7AC 0A80043C */  lui        $a0, %hi(D_8009B134)
    /* 2AFB0 8003A7B0 34B1848C */  lw         $a0, %lo(D_8009B134)($a0)
    /* 2AFB4 8003A7B4 24186200 */  and        $v1, $v1, $v0
    /* 2AFB8 8003A7B8 25186400 */  or         $v1, $v1, $a0
    /* 2AFBC 8003A7BC 50006014 */  bnez       $v1, .L8003A900
    /* 2AFC0 8003A7C0 4000A234 */   ori       $v0, $a1, 0x40
    /* 2AFC4 8003A7C4 1680033C */  lui        $v1, %hi(D_8015C410)
    /* 2AFC8 8003A7C8 10C46324 */  addiu      $v1, $v1, %lo(D_8015C410)
    /* 2AFCC 8003A7CC 330062A2 */  sb         $v0, 0x33($s3)
    /* 2AFD0 8003A7D0 1E048283 */  lb         $v0, %gp_rel(D_8009B326)($gp)
    /* 2AFD4 8003A7D4 30006492 */  lbu        $a0, 0x30($s3)
    /* 2AFD8 8003A7D8 21104300 */  addu       $v0, $v0, $v1
    /* 2AFDC 8003A7DC 000044A0 */  sb         $a0, 0x0($v0)
  .L8003A7E0:
    /* 2AFE0 8003A7E0 C908020C */  jal        func_80082324
    /* 2AFE4 8003A7E4 0A000424 */   addiu     $a0, $zero, 0xA
    /* 2AFE8 8003A7E8 FDFF4014 */  bnez       $v0, .L8003A7E0
    /* 2AFEC 8003A7EC 0100103C */   lui       $s0, (0x18000 >> 16)
    /* 2AFF0 8003A7F0 00801036 */  ori        $s0, $s0, (0x18000 & 0xFFFF)
    /* 2AFF4 8003A7F4 0100043C */  lui        $a0, (0x18C00 >> 16)
    /* 2AFF8 8003A7F8 008C8434 */  ori        $a0, $a0, (0x18C00 & 0xFFFF)
    /* 2AFFC 8003A7FC 1E048583 */  lb         $a1, %gp_rel(D_8009B326)($gp)
    /* 2B000 8003A800 00011124 */  addiu      $s1, $zero, 0x100
    /* 2B004 8003A804 40100500 */  sll        $v0, $a1, 1
    /* 2B008 8003A808 21104500 */  addu       $v0, $v0, $a1
    /* 2B00C 8003A80C 40190200 */  sll        $v1, $v0, 5
    /* 2B010 8003A810 21104300 */  addu       $v0, $v0, $v1
    /* 2B014 8003A814 80110200 */  sll        $v0, $v0, 6
    /* 2B018 8003A818 21104500 */  addu       $v0, $v0, $a1
    /* 2B01C 8003A81C 0180033C */  lui        $v1, %hi(D_80010000)
    /* 2B020 8003A820 0000638C */  lw         $v1, %lo(D_80010000)($v1)
    /* 2B024 8003A824 00110200 */  sll        $v0, $v0, 4
    /* 2B028 8003A828 21906200 */  addu       $s2, $v1, $v0
    /* 2B02C 8003A82C 21204402 */  addu       $a0, $s2, $a0
    /* 2B030 8003A830 21284002 */  addu       $a1, $s2, $zero
    /* 2B034 8003A834 3C006292 */  lbu        $v0, 0x3C($s3)
    /* 2B038 8003A838 21805002 */  addu       $s0, $s2, $s0
    /* 2B03C 8003A83C 020C11A6 */  sh         $s1, 0xC02($s0)
    /* 2B040 8003A840 060C11A6 */  sh         $s1, 0xC06($s0)
    /* 2B044 8003A844 40180200 */  sll        $v1, $v0, 1
    /* 2B048 8003A848 21186200 */  addu       $v1, $v1, $v0
    /* 2B04C 8003A84C 80190300 */  sll        $v1, $v1, 6
    /* 2B050 8003A850 40030224 */  addiu      $v0, $zero, 0x340
    /* 2B054 8003A854 23104300 */  subu       $v0, $v0, $v1
    /* 2B058 8003A858 000C02A6 */  sh         $v0, 0xC00($s0)
    /* 2B05C 8003A85C C0000224 */  addiu      $v0, $zero, 0xC0
    /* 2B060 8003A860 76FE010C */  jal        func_8007F9D8
    /* 2B064 8003A864 040C02A6 */   sh        $v0, 0xC04($s0)
    /* 2B068 8003A868 0100043C */  lui        $a0, (0x18C08 >> 16)
    /* 2B06C 8003A86C 088C8434 */  ori        $a0, $a0, (0x18C08 & 0xFFFF)
    /* 2B070 8003A870 21204402 */  addu       $a0, $s2, $a0
    /* 2B074 8003A874 00020224 */  addiu      $v0, $zero, 0x200
    /* 2B078 8003A878 21280002 */  addu       $a1, $s0, $zero
    /* 2B07C 8003A87C 080C02A6 */  sh         $v0, 0xC08($s0)
    /* 2B080 8003A880 3C006392 */  lbu        $v1, 0x3C($s3)
    /* 2B084 8003A884 02000224 */  addiu      $v0, $zero, 0x2
    /* 2B088 8003A888 0C0CB1A4 */  sh         $s1, 0xC0C($a1)
    /* 2B08C 8003A88C 0E0CA2A4 */  sh         $v0, 0xC0E($a1)
    /* 2B090 8003A890 40180300 */  sll        $v1, $v1, 1
    /* 2B094 8003A894 F0006324 */  addiu      $v1, $v1, 0xF0
    /* 2B098 8003A898 76FE010C */  jal        func_8007F9D8
    /* 2B09C 8003A89C 0A0CA3A4 */   sh        $v1, 0xC0A($a1)
    /* 2B0A0 8003A8A0 3C006292 */  lbu        $v0, 0x3C($s3)
    /* 2B0A4 8003A8A4 00000000 */  nop
    /* 2B0A8 8003A8A8 06004010 */  beqz       $v0, .L8003A8C4
    /* 2B0AC 8003A8AC 0100043C */   lui       $a0, (0x18400 >> 16)
    /* 2B0B0 8003A8B0 00848434 */  ori        $a0, $a0, (0x18400 & 0xFFFF)
    /* 2B0B4 8003A8B4 21204402 */  addu       $a0, $s2, $a0
    /* 2B0B8 8003A8B8 1B80053C */  lui        $a1, %hi(D_801AF800)
    /* 2B0BC 8003A8BC 35EA0008 */  j          .L8003A8D4
    /* 2B0C0 8003A8C0 00F8A524 */   addiu     $a1, $a1, %lo(D_801AF800)
  .L8003A8C4:
    /* 2B0C4 8003A8C4 00848434 */  ori        $a0, $a0, (0x18400 & 0xFFFF)
    /* 2B0C8 8003A8C8 21204402 */  addu       $a0, $s2, $a0
    /* 2B0CC 8003A8CC 1B80053C */  lui        $a1, %hi(D_801AF000)
    /* 2B0D0 8003A8D0 00F0A524 */  addiu      $a1, $a1, %lo(D_801AF000)
  .L8003A8D4:
    /* 2B0D4 8003A8D4 A8D5000C */  jal        func_800356A0
    /* 2B0D8 8003A8D8 00080624 */   addiu     $a2, $zero, 0x800
    /* 2B0DC 8003A8DC 40EA0008 */  j          .L8003A900
    /* 2B0E0 8003A8E0 00000000 */   nop
  .L8003A8E4:
    /* 2B0E4 8003A8E4 31006692 */  lbu        $a2, 0x31($s3)
    /* 2B0E8 8003A8E8 7BE8000C */  jal        func_8003A1EC
    /* 2B0EC 8003A8EC 21286002 */   addu      $a1, $s3, $zero
    /* 2B0F0 8003A8F0 32006292 */  lbu        $v0, 0x32($s3)
    /* 2B0F4 8003A8F4 330060A2 */  sb         $zero, 0x33($s3)
    /* 2B0F8 8003A8F8 40004234 */  ori        $v0, $v0, 0x40
    /* 2B0FC 8003A8FC 320062A2 */  sb         $v0, 0x32($s3)
  .L8003A900:
    /* 2B100 8003A900 3400BF8F */  lw         $ra, 0x34($sp)
    /* 2B104 8003A904 3000B48F */  lw         $s4, 0x30($sp)
    /* 2B108 8003A908 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 2B10C 8003A90C 2800B28F */  lw         $s2, 0x28($sp)
    /* 2B110 8003A910 2400B18F */  lw         $s1, 0x24($sp)
    /* 2B114 8003A914 2000B08F */  lw         $s0, 0x20($sp)
    /* 2B118 8003A918 0800E003 */  jr         $ra
    /* 2B11C 8003A91C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8003A560
