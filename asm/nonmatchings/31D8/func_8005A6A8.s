nonmatching func_8005A6A8, 0x1D0

glabel func_8005A6A8
    /* 4AEA8 8005A6A8 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 4AEAC 8005A6AC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4AEB0 8005A6B0 0F80113C */  lui        $s1, %hi(D_800F56F0)
    /* 4AEB4 8005A6B4 F056228E */  lw         $v0, %lo(D_800F56F0)($s1)
    /* 4AEB8 8005A6B8 2400B5AF */  sw         $s5, 0x24($sp)
    /* 4AEBC 8005A6BC 21A88000 */  addu       $s5, $a0, $zero
    /* 4AEC0 8005A6C0 23105500 */  subu       $v0, $v0, $s5
    /* 4AEC4 8005A6C4 18004200 */  mult       $v0, $v0
    /* 4AEC8 8005A6C8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 4AECC 8005A6CC F0563026 */  addiu      $s0, $s1, %lo(D_800F56F0)
    /* 4AED0 8005A6D0 3000BFAF */  sw         $ra, 0x30($sp)
    /* 4AED4 8005A6D4 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 4AED8 8005A6D8 2800B6AF */  sw         $s6, 0x28($sp)
    /* 4AEDC 8005A6DC 2000B4AF */  sw         $s4, 0x20($sp)
    /* 4AEE0 8005A6E0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 4AEE4 8005A6E4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4AEE8 8005A6E8 0800028E */  lw         $v0, 0x8($s0)
    /* 4AEEC 8005A6EC 12180000 */  mflo       $v1
    /* 4AEF0 8005A6F0 21B0A000 */  addu       $s6, $a1, $zero
    /* 4AEF4 8005A6F4 23105600 */  subu       $v0, $v0, $s6
    /* 4AEF8 8005A6F8 18004200 */  mult       $v0, $v0
    /* 4AEFC 8005A6FC 21A0C000 */  addu       $s4, $a2, $zero
    /* 4AF00 8005A700 21B8E000 */  addu       $s7, $a3, $zero
    /* 4AF04 8005A704 12480000 */  mflo       $t1
    /* 4AF08 8005A708 941B020C */  jal        func_80086E50
    /* 4AF0C 8005A70C 21206900 */   addu      $a0, $v1, $t1
    /* 4AF10 8005A710 0800038E */  lw         $v1, 0x8($s0)
    /* 4AF14 8005A714 0C00048E */  lw         $a0, 0xC($s0)
    /* 4AF18 8005A718 00000000 */  nop
    /* 4AF1C 8005A71C 18008300 */  mult       $a0, $v1
    /* 4AF20 8005A720 1400058E */  lw         $a1, 0x14($s0)
    /* 4AF24 8005A724 12380000 */  mflo       $a3
    /* 4AF28 8005A728 2390A300 */  subu       $s2, $a1, $v1
    /* 4AF2C 8005A72C 00000000 */  nop
    /* 4AF30 8005A730 18005202 */  mult       $s2, $s2
    /* 4AF34 8005A734 F056238E */  lw         $v1, %lo(D_800F56F0)($s1)
    /* 4AF38 8005A738 12300000 */  mflo       $a2
    /* 4AF3C 8005A73C 23886400 */  subu       $s1, $v1, $a0
    /* 4AF40 8005A740 00000000 */  nop
    /* 4AF44 8005A744 18003102 */  mult       $s1, $s1
    /* 4AF48 8005A748 12200000 */  mflo       $a0
    /* 4AF4C 8005A74C 00000000 */  nop
    /* 4AF50 8005A750 00000000 */  nop
    /* 4AF54 8005A754 18006500 */  mult       $v1, $a1
    /* 4AF58 8005A758 21804000 */  addu       $s0, $v0, $zero
    /* 4AF5C 8005A75C 44FD1026 */  addiu      $s0, $s0, -0x2BC
    /* 4AF60 8005A760 2120C400 */  addu       $a0, $a2, $a0
    /* 4AF64 8005A764 12180000 */  mflo       $v1
    /* 4AF68 8005A768 941B020C */  jal        func_80086E50
    /* 4AF6C 8005A76C 2398E300 */   subu      $s3, $a3, $v1
    /* 4AF70 8005A770 FF000324 */  addiu      $v1, $zero, 0xFF
    /* 4AF74 8005A774 21204000 */  addu       $a0, $v0, $zero
    /* 4AF78 8005A778 000083A2 */  sb         $v1, 0x0($s4)
    /* 4AF7C 8005A77C 0F00001A */  blez       $s0, .L8005A7BC
    /* 4AF80 8005A780 0000E0A2 */   sb        $zero, 0x0($s7)
    /* 4AF84 8005A784 AA2A023C */  lui        $v0, (0x2AAAAAAB >> 16)
    /* 4AF88 8005A788 ABAA4234 */  ori        $v0, $v0, (0x2AAAAAAB & 0xFFFF)
    /* 4AF8C 8005A78C 18000202 */  mult       $s0, $v0
    /* 4AF90 8005A790 C31F1000 */  sra        $v1, $s0, 31
    /* 4AF94 8005A794 10400000 */  mfhi       $t0
    /* 4AF98 8005A798 43100800 */  sra        $v0, $t0, 1
    /* 4AF9C 8005A79C 23104300 */  subu       $v0, $v0, $v1
    /* 4AFA0 8005A7A0 FF000324 */  addiu      $v1, $zero, 0xFF
    /* 4AFA4 8005A7A4 23186200 */  subu       $v1, $v1, $v0
    /* 4AFA8 8005A7A8 10006228 */  slti       $v0, $v1, 0x10
    /* 4AFAC 8005A7AC 02004010 */  beqz       $v0, .L8005A7B8
    /* 4AFB0 8005A7B0 00000000 */   nop
    /* 4AFB4 8005A7B4 10000324 */  addiu      $v1, $zero, 0x10
  .L8005A7B8:
    /* 4AFB8 8005A7B8 000083A2 */  sb         $v1, 0x0($s4)
  .L8005A7BC:
    /* 4AFBC 8005A7BC 23008010 */  beqz       $a0, .L8005A84C
    /* 4AFC0 8005A7C0 1800B202 */   mult      $s5, $s2
    /* 4AFC4 8005A7C4 12100000 */  mflo       $v0
    /* 4AFC8 8005A7C8 00000000 */  nop
    /* 4AFCC 8005A7CC 00000000 */  nop
    /* 4AFD0 8005A7D0 1800D102 */  mult       $s6, $s1
    /* 4AFD4 8005A7D4 12180000 */  mflo       $v1
    /* 4AFD8 8005A7D8 21104300 */  addu       $v0, $v0, $v1
    /* 4AFDC 8005A7DC 21105300 */  addu       $v0, $v0, $s3
    /* 4AFE0 8005A7E0 1A004400 */  div        $zero, $v0, $a0
    /* 4AFE4 8005A7E4 02008014 */  bnez       $a0, .L8005A7F0
    /* 4AFE8 8005A7E8 00000000 */   nop
    /* 4AFEC 8005A7EC 0D000700 */  break      7
  .L8005A7F0:
    /* 4AFF0 8005A7F0 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 4AFF4 8005A7F4 04008114 */  bne        $a0, $at, .L8005A808
    /* 4AFF8 8005A7F8 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 4AFFC 8005A7FC 02004114 */  bne        $v0, $at, .L8005A808
    /* 4B000 8005A800 00000000 */   nop
    /* 4B004 8005A804 0D000600 */  break      6
  .L8005A808:
    /* 4B008 8005A808 12800000 */  mflo       $s0
    /* 4B00C 8005A80C 00000000 */  nop
    /* 4B010 8005A810 02000106 */  bgez       $s0, .L8005A81C
    /* 4B014 8005A814 21100002 */   addu      $v0, $s0, $zero
    /* 4B018 8005A818 0F000226 */  addiu      $v0, $s0, 0xF
  .L8005A81C:
    /* 4B01C 8005A81C 03110200 */  sra        $v0, $v0, 4
    /* 4B020 8005A820 02004104 */  bgez       $v0, .L8005A82C
    /* 4B024 8005A824 21184000 */   addu      $v1, $v0, $zero
    /* 4B028 8005A828 23180300 */  negu       $v1, $v1
  .L8005A82C:
    /* 4B02C 8005A82C 80006228 */  slti       $v0, $v1, 0x80
    /* 4B030 8005A830 02004014 */  bnez       $v0, .L8005A83C
    /* 4B034 8005A834 00000000 */   nop
    /* 4B038 8005A838 7F000324 */  addiu      $v1, $zero, 0x7F
  .L8005A83C:
    /* 4B03C 8005A83C 0200001E */  bgtz       $s0, .L8005A848
    /* 4B040 8005A840 21106000 */   addu      $v0, $v1, $zero
    /* 4B044 8005A844 23100200 */  negu       $v0, $v0
  .L8005A848:
    /* 4B048 8005A848 0000E2A2 */  sb         $v0, 0x0($s7)
  .L8005A84C:
    /* 4B04C 8005A84C 3000BF8F */  lw         $ra, 0x30($sp)
    /* 4B050 8005A850 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 4B054 8005A854 2800B68F */  lw         $s6, 0x28($sp)
    /* 4B058 8005A858 2400B58F */  lw         $s5, 0x24($sp)
    /* 4B05C 8005A85C 2000B48F */  lw         $s4, 0x20($sp)
    /* 4B060 8005A860 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 4B064 8005A864 1800B28F */  lw         $s2, 0x18($sp)
    /* 4B068 8005A868 1400B18F */  lw         $s1, 0x14($sp)
    /* 4B06C 8005A86C 1000B08F */  lw         $s0, 0x10($sp)
    /* 4B070 8005A870 0800E003 */  jr         $ra
    /* 4B074 8005A874 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8005A6A8
