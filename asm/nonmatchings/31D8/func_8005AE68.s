nonmatching func_8005AE68, 0x1EC

glabel func_8005AE68
    /* 4B668 8005AE68 B0FFBD27 */  addiu      $sp, $sp, -0x50
    /* 4B66C 8005AE6C 3000B0AF */  sw         $s0, 0x30($sp)
    /* 4B670 8005AE70 2180A000 */  addu       $s0, $a1, $zero
    /* 4B674 8005AE74 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* 4B678 8005AE78 21988000 */  addu       $s3, $a0, $zero
    /* 4B67C 8005AE7C 4800B6AF */  sw         $s6, 0x48($sp)
    /* 4B680 8005AE80 21B0C000 */  addu       $s6, $a2, $zero
    /* 4B684 8005AE84 FFFF6732 */  andi       $a3, $s3, 0xFFFF
    /* 4B688 8005AE88 4C00BFAF */  sw         $ra, 0x4C($sp)
    /* 4B68C 8005AE8C 4400B5AF */  sw         $s5, 0x44($sp)
    /* 4B690 8005AE90 4000B4AF */  sw         $s4, 0x40($sp)
    /* 4B694 8005AE94 3800B2AF */  sw         $s2, 0x38($sp)
    /* 4B698 8005AE98 3400B1AF */  sw         $s1, 0x34($sp)
    /* 4B69C 8005AE9C 6300E010 */  beqz       $a3, .L8005B02C
    /* 4B6A0 8005AEA0 21100000 */   addu      $v0, $zero, $zero
    /* 4B6A4 8005AEA4 1F000224 */  addiu      $v0, $zero, 0x1F
    /* 4B6A8 8005AEA8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 4B6AC 8005AEAC 2000A427 */  addiu      $a0, $sp, 0x20
    /* 4B6B0 8005AEB0 24286202 */  and        $a1, $s3, $v0
    /* 4B6B4 8005AEB4 42310700 */  srl        $a2, $a3, 5
    /* 4B6B8 8005AEB8 2430C200 */  and        $a2, $a2, $v0
    /* 4B6BC 8005AEBC 823A0700 */  srl        $a3, $a3, 10
    /* 4B6C0 8005AEC0 2438E200 */  and        $a3, $a3, $v0
    /* 4B6C4 8005AEC4 08001532 */  andi       $s5, $s0, 0x8
    /* 4B6C8 8005AEC8 07001132 */  andi       $s1, $s0, 0x7
    /* 4B6CC 8005AECC FF003032 */  andi       $s0, $s1, 0xFF
    /* 4B6D0 8005AED0 0600023A */  xori       $v0, $s0, 0x6
    /* 4B6D4 8005AED4 636A010C */  jal        func_8005A98C
    /* 4B6D8 8005AED8 0100522C */   sltiu     $s2, $v0, 0x1
    /* 4B6DC 8005AEDC 0700102E */  sltiu      $s0, $s0, 0x7
    /* 4B6E0 8005AEE0 11000012 */  beqz       $s0, .L8005AF28
    /* 4B6E4 8005AEE4 1F001424 */   addiu     $s4, $zero, 0x1F
    /* 4B6E8 8005AEE8 0C00A012 */  beqz       $s5, .L8005AF1C
    /* 4B6EC 8005AEEC 21202002 */   addu      $a0, $s1, $zero
    /* 4B6F0 8005AEF0 AA2A023C */  lui        $v0, (0x2AAAAAAB >> 16)
    /* 4B6F4 8005AEF4 ABAA4234 */  ori        $v0, $v0, (0x2AAAAAAB & 0xFFFF)
    /* 4B6F8 8005AEF8 03008424 */  addiu      $a0, $a0, 0x3
    /* 4B6FC 8005AEFC 18008200 */  mult       $a0, $v0
    /* 4B700 8005AF00 C31F0400 */  sra        $v1, $a0, 31
    /* 4B704 8005AF04 10400000 */  mfhi       $t0
    /* 4B708 8005AF08 23180301 */  subu       $v1, $t0, $v1
    /* 4B70C 8005AF0C 40100300 */  sll        $v0, $v1, 1
    /* 4B710 8005AF10 21104300 */  addu       $v0, $v0, $v1
    /* 4B714 8005AF14 40100200 */  sll        $v0, $v0, 1
    /* 4B718 8005AF18 23208200 */  subu       $a0, $a0, $v0
  .L8005AF1C:
    /* 4B71C 8005AF1C FF008230 */  andi       $v0, $a0, 0xFF
    /* 4B720 8005AF20 00130200 */  sll        $v0, $v0, 12
    /* 4B724 8005AF24 2000A2AF */  sw         $v0, 0x20($sp)
  .L8005AF28:
    /* 4B728 8005AF28 03004012 */  beqz       $s2, .L8005AF38
    /* 4B72C 8005AF2C FFFFC232 */   andi      $v0, $s6, 0xFFFF
    /* 4B730 8005AF30 D76B0108 */  j          .L8005AF5C
    /* 4B734 8005AF34 2600A0A7 */   sh        $zero, 0x26($sp)
  .L8005AF38:
    /* 4B738 8005AF38 2600A397 */  lhu        $v1, 0x26($sp)
    /* 4B73C 8005AF3C 00000000 */  nop
    /* 4B740 8005AF40 18006200 */  mult       $v1, $v0
    /* 4B744 8005AF44 12100000 */  mflo       $v0
    /* 4B748 8005AF48 02004104 */  bgez       $v0, .L8005AF54
    /* 4B74C 8005AF4C 00000000 */   nop
    /* 4B750 8005AF50 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8005AF54:
    /* 4B754 8005AF54 03130200 */  sra        $v0, $v0, 12
    /* 4B758 8005AF58 2600A2A7 */  sh         $v0, 0x26($sp)
  .L8005AF5C:
    /* 4B75C 8005AF5C 2400A697 */  lhu        $a2, 0x24($sp)
    /* 4B760 8005AF60 2600A797 */  lhu        $a3, 0x26($sp)
    /* 4B764 8005AF64 1F000224 */  addiu      $v0, $zero, 0x1F
    /* 4B768 8005AF68 1000A2AF */  sw         $v0, 0x10($sp)
    /* 4B76C 8005AF6C 2000A58F */  lw         $a1, 0x20($sp)
    /* 4B770 8005AF70 E86A010C */  jal        func_8005ABA0
    /* 4B774 8005AF74 2800A427 */   addiu     $a0, $sp, 0x28
    /* 4B778 8005AF78 0A00A012 */  beqz       $s5, .L8005AFA4
    /* 4B77C 8005AF7C 00000000 */   nop
    /* 4B780 8005AF80 2800A293 */  lbu        $v0, 0x28($sp)
    /* 4B784 8005AF84 2A00A393 */  lbu        $v1, 0x2A($sp)
    /* 4B788 8005AF88 23108202 */  subu       $v0, $s4, $v0
    /* 4B78C 8005AF8C 2800A2A3 */  sb         $v0, 0x28($sp)
    /* 4B790 8005AF90 2900A293 */  lbu        $v0, 0x29($sp)
    /* 4B794 8005AF94 23188302 */  subu       $v1, $s4, $v1
    /* 4B798 8005AF98 2A00A3A3 */  sb         $v1, 0x2A($sp)
    /* 4B79C 8005AF9C 23108202 */  subu       $v0, $s4, $v0
    /* 4B7A0 8005AFA0 2900A2A3 */  sb         $v0, 0x29($sp)
  .L8005AFA4:
    /* 4B7A4 8005AFA4 2800A293 */  lbu        $v0, 0x28($sp)
    /* 4B7A8 8005AFA8 00000000 */  nop
    /* 4B7AC 8005AFAC 02004014 */  bnez       $v0, .L8005AFB8
    /* 4B7B0 8005AFB0 00000000 */   nop
    /* 4B7B4 8005AFB4 01000224 */  addiu      $v0, $zero, 0x1
  .L8005AFB8:
    /* 4B7B8 8005AFB8 2900A393 */  lbu        $v1, 0x29($sp)
    /* 4B7BC 8005AFBC 00000000 */  nop
    /* 4B7C0 8005AFC0 02006014 */  bnez       $v1, .L8005AFCC
    /* 4B7C4 8005AFC4 2800A2A3 */   sb        $v0, 0x28($sp)
    /* 4B7C8 8005AFC8 01000324 */  addiu      $v1, $zero, 0x1
  .L8005AFCC:
    /* 4B7CC 8005AFCC 2A00A293 */  lbu        $v0, 0x2A($sp)
    /* 4B7D0 8005AFD0 00000000 */  nop
    /* 4B7D4 8005AFD4 02004014 */  bnez       $v0, .L8005AFE0
    /* 4B7D8 8005AFD8 2900A3A3 */   sb        $v1, 0x29($sp)
    /* 4B7DC 8005AFDC 01000224 */  addiu      $v0, $zero, 0x1
  .L8005AFE0:
    /* 4B7E0 8005AFE0 2A00A2A3 */  sb         $v0, 0x2A($sp)
    /* 4B7E4 8005AFE4 2800A883 */  lb         $t0, 0x28($sp)
    /* 4B7E8 8005AFE8 2900A983 */  lb         $t1, 0x29($sp)
    /* 4B7EC 8005AFEC 2A00AA83 */  lb         $t2, 0x2A($sp)
    /* 4B7F0 8005AFF0 1800A8A3 */  sb         $t0, 0x18($sp)
    /* 4B7F4 8005AFF4 1900A9A3 */  sb         $t1, 0x19($sp)
    /* 4B7F8 8005AFF8 1A00AAA3 */  sb         $t2, 0x1A($sp)
    /* 4B7FC 8005AFFC 1800A293 */  lbu        $v0, 0x18($sp)
    /* 4B800 8005B000 1900A493 */  lbu        $a0, 0x19($sp)
    /* 4B804 8005B004 1A00A393 */  lbu        $v1, 0x1A($sp)
    /* 4B808 8005B008 1F004230 */  andi       $v0, $v0, 0x1F
    /* 4B80C 8005B00C 1F008430 */  andi       $a0, $a0, 0x1F
    /* 4B810 8005B010 40210400 */  sll        $a0, $a0, 5
    /* 4B814 8005B014 25104400 */  or         $v0, $v0, $a0
    /* 4B818 8005B018 1F006330 */  andi       $v1, $v1, 0x1F
    /* 4B81C 8005B01C 801A0300 */  sll        $v1, $v1, 10
    /* 4B820 8005B020 25104300 */  or         $v0, $v0, $v1
    /* 4B824 8005B024 00806332 */  andi       $v1, $s3, 0x8000
    /* 4B828 8005B028 25104300 */  or         $v0, $v0, $v1
  .L8005B02C:
    /* 4B82C 8005B02C 4C00BF8F */  lw         $ra, 0x4C($sp)
    /* 4B830 8005B030 4800B68F */  lw         $s6, 0x48($sp)
    /* 4B834 8005B034 4400B58F */  lw         $s5, 0x44($sp)
    /* 4B838 8005B038 4000B48F */  lw         $s4, 0x40($sp)
    /* 4B83C 8005B03C 3C00B38F */  lw         $s3, 0x3C($sp)
    /* 4B840 8005B040 3800B28F */  lw         $s2, 0x38($sp)
    /* 4B844 8005B044 3400B18F */  lw         $s1, 0x34($sp)
    /* 4B848 8005B048 3000B08F */  lw         $s0, 0x30($sp)
    /* 4B84C 8005B04C 0800E003 */  jr         $ra
    /* 4B850 8005B050 5000BD27 */   addiu     $sp, $sp, 0x50
endlabel func_8005AE68
