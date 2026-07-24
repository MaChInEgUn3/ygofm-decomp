nonmatching func_8002ACA4, 0xDFC

glabel func_8002ACA4
    /* 1B4A4 8002ACA4 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 1B4A8 8002ACA8 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 1B4AC 8002ACAC 21988000 */  addu       $s3, $a0, $zero
    /* 1B4B0 8002ACB0 0F80023C */  lui        $v0, %hi(D_800EA0E8)
    /* 1B4B4 8002ACB4 4000BFAF */  sw         $ra, 0x40($sp)
    /* 1B4B8 8002ACB8 3C00B7AF */  sw         $s7, 0x3C($sp)
    /* 1B4BC 8002ACBC 3800B6AF */  sw         $s6, 0x38($sp)
    /* 1B4C0 8002ACC0 3400B5AF */  sw         $s5, 0x34($sp)
    /* 1B4C4 8002ACC4 3000B4AF */  sw         $s4, 0x30($sp)
    /* 1B4C8 8002ACC8 2800B2AF */  sw         $s2, 0x28($sp)
    /* 1B4CC 8002ACCC 2400B1AF */  sw         $s1, 0x24($sp)
    /* 1B4D0 8002ACD0 2000B0AF */  sw         $s0, 0x20($sp)
    /* 1B4D4 8002ACD4 00006392 */  lbu        $v1, 0x0($s3)
    /* 1B4D8 8002ACD8 E8A05624 */  addiu      $s6, $v0, %lo(D_800EA0E8)
    /* 1B4DC 8002ACDC 80006230 */  andi       $v0, $v1, 0x80
    /* 1B4E0 8002ACE0 29004014 */  bnez       $v0, .L8002AD88
    /* 1B4E4 8002ACE4 80006234 */   ori       $v0, $v1, 0x80
    /* 1B4E8 8002ACE8 000062A2 */  sb         $v0, 0x0($s3)
    /* 1B4EC 8002ACEC 01000224 */  addiu      $v0, $zero, 0x1
    /* 1B4F0 8002ACF0 010060A2 */  sb         $zero, 0x1($s3)
    /* 1B4F4 8002ACF4 030060A2 */  sb         $zero, 0x3($s3)
    /* 1B4F8 8002ACF8 314C010C */  jal        func_800530C4
    /* 1B4FC 8002ACFC 040062A2 */   sb        $v0, 0x4($s3)
    /* 1B500 8002AD00 F64C010C */  jal        func_800533D8
    /* 1B504 8002AD04 0F80103C */   lui       $s0, %hi(D_800F2848)
    /* 1B508 8002AD08 2C010424 */  addiu      $a0, $zero, 0x12C
    /* 1B50C 8002AD0C 34030224 */  addiu      $v0, $zero, 0x334
    /* 1B510 8002AD10 482802A6 */  sh         $v0, %lo(D_800F2848)($s0)
    /* 1B514 8002AD14 48281026 */  addiu      $s0, $s0, %lo(D_800F2848)
    /* 1B518 8002AD18 00040224 */  addiu      $v0, $zero, 0x400
    /* 1B51C 8002AD1C 020002A6 */  sh         $v0, 0x2($s0)
    /* 1B520 8002AD20 C4000224 */  addiu      $v0, $zero, 0xC4
    /* 1B524 8002AD24 040002A6 */  sh         $v0, 0x4($s0)
    /* 1B528 8002AD28 21108000 */  addu       $v0, $a0, $zero
    /* 1B52C 8002AD2C 0C0000A6 */  sh         $zero, 0xC($s0)
    /* 1B530 8002AD30 280000AE */  sw         $zero, 0x28($s0)
    /* 1B534 8002AD34 2C0000AE */  sw         $zero, 0x2C($s0)
    /* 1B538 8002AD38 F015020C */  jal        func_800857C0
    /* 1B53C 8002AD3C 0E0002A6 */   sh        $v0, 0xE($s0)
    /* 1B540 8002AD40 10000226 */  addiu      $v0, $s0, 0x10
    /* 1B544 8002AD44 0C0040AC */  sw         $zero, 0xC($v0)
    /* 1B548 8002AD48 060000A6 */  sh         $zero, 0x6($s0)
    /* 1B54C 8002AD4C 100040AC */  sw         $zero, 0x10($v0)
    /* 1B550 8002AD50 080000A6 */  sh         $zero, 0x8($s0)
    /* 1B554 8002AD54 140040AC */  sw         $zero, 0x14($v0)
    /* 1B558 8002AD58 4B4D000C */  jal        func_8001352C
    /* 1B55C 8002AD5C 0A0000A6 */   sh        $zero, 0xA($s0)
    /* 1B560 8002AD60 06006596 */  lhu        $a1, 0x6($s3)
    /* 1B564 8002AD64 59A4000C */  jal        func_80029164
    /* 1B568 8002AD68 21200000 */   addu      $a0, $zero, $zero
    /* 1B56C 8002AD6C 2157000C */  jal        func_80015C84
    /* 1B570 8002AD70 00000000 */   nop
    /* 1B574 8002AD74 0F80033C */  lui        $v1, %hi(D_800E9ECF)
    /* 1B578 8002AD78 06000224 */  addiu      $v0, $zero, 0x6
    /* 1B57C 8002AD7C CF9E62A0 */  sb         $v0, %lo(D_800E9ECF)($v1)
    /* 1B580 8002AD80 9DAE0008 */  j          .L8002BA74
    /* 1B584 8002AD84 500060AE */   sw        $zero, 0x50($s3)
  .L8002AD88:
    /* 1B588 8002AD88 E5E5000C */  jal        func_80039794
    /* 1B58C 8002AD8C 00000000 */   nop
    /* 1B590 8002AD90 04006592 */  lbu        $a1, 0x4($s3)
    /* 1B594 8002AD94 00000000 */  nop
    /* 1B598 8002AD98 0F00A230 */  andi       $v0, $a1, 0xF
    /* 1B59C 8002AD9C 46004010 */  beqz       $v0, .L8002AEB8
    /* 1B5A0 8002ADA0 0002023C */   lui       $v0, (0x2000030 >> 16)
    /* 1B5A4 8002ADA4 30004234 */  ori        $v0, $v0, (0x2000030 & 0xFFFF)
    /* 1B5A8 8002ADA8 0A80033C */  lui        $v1, %hi(D_8009B0F4)
    /* 1B5AC 8002ADAC F4B0638C */  lw         $v1, %lo(D_8009B0F4)($v1)
    /* 1B5B0 8002ADB0 0A80043C */  lui        $a0, %hi(D_8009B134)
    /* 1B5B4 8002ADB4 34B1848C */  lw         $a0, %lo(D_8009B134)($a0)
    /* 1B5B8 8002ADB8 24186200 */  and        $v1, $v1, $v0
    /* 1B5BC 8002ADBC 25186400 */  or         $v1, $v1, $a0
    /* 1B5C0 8002ADC0 3D006014 */  bnez       $v1, .L8002AEB8
    /* 1B5C4 8002ADC4 01001024 */   addiu     $s0, $zero, 0x1
    /* 1B5C8 8002ADC8 1A00B014 */  bne        $a1, $s0, .L8002AE34
    /* 1B5CC 8002ADCC 1D80033C */   lui       $v1, %hi(D_801D4244)
    /* 1B5D0 8002ADD0 06006296 */  lhu        $v0, 0x6($s3)
    /* 1B5D4 8002ADD4 44426324 */  addiu      $v1, $v1, %lo(D_801D4244)
    /* 1B5D8 8002ADD8 040060A2 */  sb         $zero, 0x4($s3)
    /* 1B5DC 8002ADDC FFFF4524 */  addiu      $a1, $v0, -0x1
    /* 1B5E0 8002ADE0 80100500 */  sll        $v0, $a1, 2
    /* 1B5E4 8002ADE4 21104300 */  addu       $v0, $v0, $v1
    /* 1B5E8 8002ADE8 0000428C */  lw         $v0, 0x0($v0)
    /* 1B5EC 8002ADEC 00000000 */  nop
    /* 1B5F0 8002ADF0 83160200 */  sra        $v0, $v0, 26
    /* 1B5F4 8002ADF4 1F004230 */  andi       $v0, $v0, 0x1F
    /* 1B5F8 8002ADF8 14004228 */  slti       $v0, $v0, 0x14
    /* 1B5FC 8002ADFC 2E004010 */  beqz       $v0, .L8002AEB8
    /* 1B600 8002AE00 21200000 */   addu      $a0, $zero, $zero
    /* 1B604 8002AE04 21308000 */  addu       $a2, $a0, $zero
    /* 1B608 8002AE08 21388000 */  addu       $a3, $a0, $zero
    /* 1B60C 8002AE0C 04000224 */  addiu      $v0, $zero, 0x4
    /* 1B610 8002AE10 1000A0AF */  sw         $zero, 0x10($sp)
    /* 1B614 8002AE14 1400A0AF */  sw         $zero, 0x14($sp)
    /* 1B618 8002AE18 4159010C */  jal        func_80056504
    /* 1B61C 8002AE1C 1800A2AF */   sw        $v0, 0x18($sp)
    /* 1B620 8002AE20 2C010224 */  addiu      $v0, $zero, 0x12C
    /* 1B624 8002AE24 200062AE */  sw         $v0, 0x20($s3)
    /* 1B628 8002AE28 02000224 */  addiu      $v0, $zero, 0x2
    /* 1B62C 8002AE2C AEAB0008 */  j          .L8002AEB8
    /* 1B630 8002AE30 040062A2 */   sb        $v0, 0x4($s3)
  .L8002AE34:
    /* 1B634 8002AE34 0A5A010C */  jal        func_80056828
    /* 1B638 8002AE38 21200000 */   addu      $a0, $zero, $zero
    /* 1B63C 8002AE3C 7663010C */  jal        func_80058DD8
    /* 1B640 8002AE40 21200000 */   addu      $a0, $zero, $zero
    /* 1B644 8002AE44 1C005014 */  bne        $v0, $s0, .L8002AEB8
    /* 1B648 8002AE48 00000000 */   nop
    /* 1B64C 8002AE4C 0B00010C */  jal        func_8004002C
    /* 1B650 8002AE50 040060A2 */   sb        $zero, 0x4($s3)
    /* 1B654 8002AE54 21204000 */  addu       $a0, $v0, $zero
    /* 1B658 8002AE58 2B00010C */  jal        func_800400AC
    /* 1B65C 8002AE5C 02000524 */   addiu     $a1, $zero, 0x2
    /* 1B660 8002AE60 21804000 */  addu       $s0, $v0, $zero
    /* 1B664 8002AE64 21200002 */  addu       $a0, $s0, $zero
    /* 1B668 8002AE68 30010524 */  addiu      $a1, $zero, 0x130
    /* 1B66C 8002AE6C CD000624 */  addiu      $a2, $zero, 0xCD
    /* 1B670 8002AE70 03000724 */  addiu      $a3, $zero, 0x3
    /* 1B674 8002AE74 02000224 */  addiu      $v0, $zero, 0x2
    /* 1B678 8002AE78 1400A2AF */  sw         $v0, 0x14($sp)
    /* 1B67C 8002AE7C 0B000224 */  addiu      $v0, $zero, 0xB
    /* 1B680 8002AE80 1800A2AF */  sw         $v0, 0x18($sp)
    /* 1B684 8002AE84 0C020224 */  addiu      $v0, $zero, 0x20C
    /* 1B688 8002AE88 1000A0AF */  sw         $zero, 0x10($sp)
    /* 1B68C 8002AE8C 3301010C */  jal        func_800404CC
    /* 1B690 8002AE90 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* 1B694 8002AE94 08000296 */  lhu        $v0, 0x8($s0)
    /* 1B698 8002AE98 21200002 */  addu       $a0, $s0, $zero
    /* 1B69C 8002AE9C 28004234 */  ori        $v0, $v0, 0x28
    /* 1B6A0 8002AEA0 460A010C */  jal        func_80042918
    /* 1B6A4 8002AEA4 080002A6 */   sh        $v0, 0x8($s0)
    /* 1B6A8 8002AEA8 21200002 */  addu       $a0, $s0, $zero
    /* 1B6AC 8002AEAC 3B0A010C */  jal        func_800428EC
    /* 1B6B0 8002AEB0 0A000524 */   addiu     $a1, $zero, 0xA
    /* 1B6B4 8002AEB4 500070AE */  sw         $s0, 0x50($s3)
  .L8002AEB8:
    /* 1B6B8 8002AEB8 03006392 */  lbu        $v1, 0x3($s3)
    /* 1B6BC 8002AEBC 01000224 */  addiu      $v0, $zero, 0x1
    /* 1B6C0 8002AEC0 0F006430 */  andi       $a0, $v1, 0xF
    /* 1B6C4 8002AEC4 05008210 */  beq        $a0, $v0, .L8002AEDC
    /* 1B6C8 8002AEC8 02000224 */   addiu     $v0, $zero, 0x2
    /* 1B6CC 8002AECC 1B008210 */  beq        $a0, $v0, .L8002AF3C
    /* 1B6D0 8002AED0 80006230 */   andi      $v0, $v1, 0x80
    /* 1B6D4 8002AED4 EDAB0008 */  j          .L8002AFB4
    /* 1B6D8 8002AED8 00000000 */   nop
  .L8002AEDC:
    /* 1B6DC 8002AEDC 4C00708E */  lw         $s0, 0x4C($s3)
    /* 1B6E0 8002AEE0 80006230 */  andi       $v0, $v1, 0x80
    /* 1B6E4 8002AEE4 0A004014 */  bnez       $v0, .L8002AF10
    /* 1B6E8 8002AEE8 21200002 */   addu      $a0, $s0, $zero
    /* 1B6EC 8002AEEC 80006234 */  ori        $v0, $v1, 0x80
    /* 1B6F0 8002AEF0 030062A2 */  sb         $v0, 0x3($s3)
    /* 1B6F4 8002AEF4 48010224 */  addiu      $v0, $zero, 0x148
    /* 1B6F8 8002AEF8 300002A6 */  sh         $v0, 0x30($s0)
    /* 1B6FC 8002AEFC 0E000224 */  addiu      $v0, $zero, 0xE
    /* 1B700 8002AF00 5E0C010C */  jal        func_80043178
    /* 1B704 8002AF04 320002A6 */   sh        $v0, 0x32($s0)
    /* 1B708 8002AF08 00FC0224 */  addiu      $v0, $zero, -0x400
    /* 1B70C 8002AF0C 600002A6 */  sh         $v0, 0x60($s0)
  .L8002AF10:
    /* 1B710 8002AF10 60000296 */  lhu        $v0, 0x60($s0)
    /* 1B714 8002AF14 00000000 */  nop
    /* 1B718 8002AF18 33004224 */  addiu      $v0, $v0, 0x33
    /* 1B71C 8002AF1C 600002A6 */  sh         $v0, 0x60($s0)
    /* 1B720 8002AF20 00140200 */  sll        $v0, $v0, 16
    /* 1B724 8002AF24 033C0200 */  sra        $a3, $v0, 16
    /* 1B728 8002AF28 1500E104 */  bgez       $a3, .L8002AF80
    /* 1B72C 8002AF2C 94000224 */   addiu     $v0, $zero, 0x94
    /* 1B730 8002AF30 21200002 */  addu       $a0, $s0, $zero
    /* 1B734 8002AF34 E6AB0008 */  j          .L8002AF98
    /* 1B738 8002AF38 94000524 */   addiu     $a1, $zero, 0x94
  .L8002AF3C:
    /* 1B73C 8002AF3C 4C00708E */  lw         $s0, 0x4C($s3)
    /* 1B740 8002AF40 06004014 */  bnez       $v0, .L8002AF5C
    /* 1B744 8002AF44 21200002 */   addu      $a0, $s0, $zero
    /* 1B748 8002AF48 80006234 */  ori        $v0, $v1, 0x80
    /* 1B74C 8002AF4C 5E0C010C */  jal        func_80043178
    /* 1B750 8002AF50 030062A2 */   sb        $v0, 0x3($s3)
    /* 1B754 8002AF54 00040224 */  addiu      $v0, $zero, 0x400
    /* 1B758 8002AF58 600002A6 */  sh         $v0, 0x60($s0)
  .L8002AF5C:
    /* 1B75C 8002AF5C 60000296 */  lhu        $v0, 0x60($s0)
    /* 1B760 8002AF60 00000000 */  nop
    /* 1B764 8002AF64 CDFF4224 */  addiu      $v0, $v0, -0x33
    /* 1B768 8002AF68 600002A6 */  sh         $v0, 0x60($s0)
    /* 1B76C 8002AF6C 00140200 */  sll        $v0, $v0, 16
    /* 1B770 8002AF70 033C0200 */  sra        $a3, $v0, 16
    /* 1B774 8002AF74 0700E01C */  bgtz       $a3, .L8002AF94
    /* 1B778 8002AF78 48010524 */   addiu     $a1, $zero, 0x148
    /* 1B77C 8002AF7C 48010224 */  addiu      $v0, $zero, 0x148
  .L8002AF80:
    /* 1B780 8002AF80 300002A6 */  sh         $v0, 0x30($s0)
    /* 1B784 8002AF84 0E000224 */  addiu      $v0, $zero, 0xE
    /* 1B788 8002AF88 320002A6 */  sh         $v0, 0x32($s0)
    /* 1B78C 8002AF8C E8AB0008 */  j          .L8002AFA0
    /* 1B790 8002AF90 030060A2 */   sb        $zero, 0x3($s3)
  .L8002AF94:
    /* 1B794 8002AF94 21200002 */  addu       $a0, $s0, $zero
  .L8002AF98:
    /* 1B798 8002AF98 8C0C010C */  jal        func_80043230
    /* 1B79C 8002AF9C 0E000624 */   addiu     $a2, $zero, 0xE
  .L8002AFA0:
    /* 1B7A0 8002AFA0 0F80043C */  lui        $a0, %hi(D_800EB0F8)
    /* 1B7A4 8002AFA4 30000586 */  lh         $a1, 0x30($s0)
    /* 1B7A8 8002AFA8 32000686 */  lh         $a2, 0x32($s0)
    /* 1B7AC 8002AFAC 4DE6000C */  jal        func_80039934
    /* 1B7B0 8002AFB0 F8B08424 */   addiu     $a0, $a0, %lo(D_800EB0F8)
  .L8002AFB4:
    /* 1B7B4 8002AFB4 01006292 */  lbu        $v0, 0x1($s3)
    /* 1B7B8 8002AFB8 00000000 */  nop
    /* 1B7BC 8002AFBC 1F004330 */  andi       $v1, $v0, 0x1F
    /* 1B7C0 8002AFC0 0900622C */  sltiu      $v0, $v1, 0x9
    /* 1B7C4 8002AFC4 AB024010 */  beqz       $v0, .L8002BA74
    /* 1B7C8 8002AFC8 0180023C */   lui       $v0, %hi(jtbl_800101E0)
    /* 1B7CC 8002AFCC E0014224 */  addiu      $v0, $v0, %lo(jtbl_800101E0)
    /* 1B7D0 8002AFD0 80180300 */  sll        $v1, $v1, 2
    /* 1B7D4 8002AFD4 21186200 */  addu       $v1, $v1, $v0
    /* 1B7D8 8002AFD8 0000628C */  lw         $v0, 0x0($v1)
    /* 1B7DC 8002AFDC 00000000 */  nop
    /* 1B7E0 8002AFE0 08004000 */  jr         $v0
    /* 1B7E4 8002AFE4 00000000 */   nop
  jlabel .L8002AFE8
    /* 1B7E8 8002AFE8 21200000 */  addu       $a0, $zero, $zero
    /* 1B7EC 8002AFEC 06006396 */  lhu        $v1, 0x6($s3)
    /* 1B7F0 8002AFF0 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 1B7F4 8002AFF4 80180300 */  sll        $v1, $v1, 2
    /* 1B7F8 8002AFF8 21186302 */  addu       $v1, $s3, $v1
    /* 1B7FC 8002AFFC 56006290 */  lbu        $v0, 0x56($v1)
    /* 1B800 8002B000 2130A000 */  addu       $a2, $a1, $zero
    /* 1B804 8002B004 7F004230 */  andi       $v0, $v0, 0x7F
    /* 1B808 8002B008 78A4000C */  jal        func_800291E0
    /* 1B80C 8002B00C 560062A0 */   sb        $v0, 0x56($v1)
    /* 1B810 8002B010 21804000 */  addu       $s0, $v0, $zero
    /* 1B814 8002B014 FFF7043C */  lui        $a0, (0xF7FFFFFF >> 16)
    /* 1B818 8002B018 FFFF8434 */  ori        $a0, $a0, (0xF7FFFFFF & 0xFFFF)
    /* 1B81C 8002B01C 08000296 */  lhu        $v0, 0x8($s0)
    /* 1B820 8002B020 0400038E */  lw         $v1, 0x4($s0)
    /* 1B824 8002B024 4A000596 */  lhu        $a1, 0x4A($s0)
    /* 1B828 8002B028 04004234 */  ori        $v0, $v0, 0x4
    /* 1B82C 8002B02C 24186400 */  and        $v1, $v1, $a0
    /* 1B830 8002B030 080002A6 */  sh         $v0, 0x8($s0)
    /* 1B834 8002B034 040003AE */  sw         $v1, 0x4($s0)
    /* 1B838 8002B038 12006296 */  lhu        $v0, 0x12($s3)
    /* 1B83C 8002B03C 0A80033C */  lui        $v1, %hi(D_8009B146)
    /* 1B840 8002B040 46B16394 */  lhu        $v1, %lo(D_8009B146)($v1)
    /* 1B844 8002B044 48000496 */  lhu        $a0, 0x48($s0)
    /* 1B848 8002B048 23104300 */  subu       $v0, $v0, $v1
    /* 1B84C 8002B04C 23104400 */  subu       $v0, $v0, $a0
    /* 1B850 8002B050 300002A6 */  sh         $v0, 0x30($s0)
    /* 1B854 8002B054 14006296 */  lhu        $v0, 0x14($s3)
    /* 1B858 8002B058 0A80033C */  lui        $v1, %hi(D_8009B148)
    /* 1B85C 8002B05C 48B16394 */  lhu        $v1, %lo(D_8009B148)($v1)
    /* 1B860 8002B060 21200002 */  addu       $a0, $s0, $zero
    /* 1B864 8002B064 460000A6 */  sh         $zero, 0x46($s0)
    /* 1B868 8002B068 440000A6 */  sh         $zero, 0x44($s0)
    /* 1B86C 8002B06C 23104300 */  subu       $v0, $v0, $v1
    /* 1B870 8002B070 23104500 */  subu       $v0, $v0, $a1
    /* 1B874 8002B074 5E0C010C */  jal        func_80043178
    /* 1B878 8002B078 320002A6 */   sh        $v0, 0x32($s0)
    /* 1B87C 8002B07C 32000424 */  addiu      $a0, $zero, 0x32
    /* 1B880 8002B080 B8FF000C */  jal        func_8003FEE0
    /* 1B884 8002B084 600000A6 */   sh        $zero, 0x60($s0)
    /* 1B888 8002B088 0400C48E */  lw         $a0, 0x4($s6)
    /* 1B88C 8002B08C 00000000 */  nop
    /* 1B890 8002B090 0400828C */  lw         $v0, 0x4($a0)
    /* 1B894 8002B094 0080033C */  lui        $v1, (0x80000000 >> 16)
    /* 1B898 8002B098 25104300 */  or         $v0, $v0, $v1
    /* 1B89C 8002B09C 0B00010C */  jal        func_8004002C
    /* 1B8A0 8002B0A0 040082AC */   sw        $v0, 0x4($a0)
    /* 1B8A4 8002B0A4 21204000 */  addu       $a0, $v0, $zero
    /* 1B8A8 8002B0A8 2B00010C */  jal        func_800400AC
    /* 1B8AC 8002B0AC 02000524 */   addiu     $a1, $zero, 0x2
    /* 1B8B0 8002B0B0 21804000 */  addu       $s0, $v0, $zero
    /* 1B8B4 8002B0B4 21200002 */  addu       $a0, $s0, $zero
    /* 1B8B8 8002B0B8 48010524 */  addiu      $a1, $zero, 0x148
    /* 1B8BC 8002B0BC 0E000624 */  addiu      $a2, $zero, 0xE
    /* 1B8C0 8002B0C0 21380000 */  addu       $a3, $zero, $zero
    /* 1B8C4 8002B0C4 02000224 */  addiu      $v0, $zero, 0x2
    /* 1B8C8 8002B0C8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1B8CC 8002B0CC 1B000224 */  addiu      $v0, $zero, 0x1B
    /* 1B8D0 8002B0D0 1800A2AF */  sw         $v0, 0x18($sp)
    /* 1B8D4 8002B0D4 07010224 */  addiu      $v0, $zero, 0x107
    /* 1B8D8 8002B0D8 1400A0AF */  sw         $zero, 0x14($sp)
    /* 1B8DC 8002B0DC 3301010C */  jal        func_800404CC
    /* 1B8E0 8002B0E0 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* 1B8E4 8002B0E4 21200002 */  addu       $a0, $s0, $zero
    /* 1B8E8 8002B0E8 80000224 */  addiu      $v0, $zero, 0x80
    /* 1B8EC 8002B0EC 5F0002A2 */  sb         $v0, 0x5F($s0)
    /* 1B8F0 8002B0F0 08000296 */  lhu        $v0, 0x8($s0)
    /* 1B8F4 8002B0F4 00FC0324 */  addiu      $v1, $zero, -0x400
    /* 1B8F8 8002B0F8 600003A6 */  sh         $v1, 0x60($s0)
    /* 1B8FC 8002B0FC 08004234 */  ori        $v0, $v0, 0x8
    /* 1B900 8002B100 460A010C */  jal        func_80042918
    /* 1B904 8002B104 080002A6 */   sh        $v0, 0x8($s0)
    /* 1B908 8002B108 21200002 */  addu       $a0, $s0, $zero
    /* 1B90C 8002B10C 3B0A010C */  jal        func_800428EC
    /* 1B910 8002B110 04000524 */   addiu     $a1, $zero, 0x4
    /* 1B914 8002B114 4C0070AE */  sw         $s0, 0x4C($s3)
    /* 1B918 8002B118 01001024 */  addiu      $s0, $zero, 0x1
    /* 1B91C 8002B11C 1D80033C */  lui        $v1, %hi(D_801D4244)
    /* 1B920 8002B120 06006496 */  lhu        $a0, 0x6($s3)
    /* 1B924 8002B124 44426324 */  addiu      $v1, $v1, %lo(D_801D4244)
    /* 1B928 8002B128 030070A2 */  sb         $s0, 0x3($s3)
    /* 1B92C 8002B12C 00140400 */  sll        $v0, $a0, 16
    /* 1B930 8002B130 83130200 */  sra        $v0, $v0, 14
    /* 1B934 8002B134 21104300 */  addu       $v0, $v0, $v1
    /* 1B938 8002B138 FCFF428C */  lw         $v0, -0x4($v0)
    /* 1B93C 8002B13C 0A80013C */  lui        $at, %hi(D_8009B338)
    /* 1B940 8002B140 38B324A4 */  sh         $a0, %lo(D_8009B338)($at)
    /* 1B944 8002B144 83160200 */  sra        $v0, $v0, 26
    /* 1B948 8002B148 1F004230 */  andi       $v0, $v0, 0x1F
    /* 1B94C 8002B14C 14004228 */  slti       $v0, $v0, 0x14
    /* 1B950 8002B150 02004014 */  bnez       $v0, .L8002B15C
    /* 1B954 8002B154 03000524 */   addiu     $a1, $zero, 0x3
    /* 1B958 8002B158 04000524 */  addiu      $a1, $zero, 0x4
  .L8002B15C:
    /* 1B95C 8002B15C 21200000 */  addu       $a0, $zero, $zero
    /* 1B960 8002B160 94000624 */  addiu      $a2, $zero, 0x94
    /* 1B964 8002B164 0E000724 */  addiu      $a3, $zero, 0xE
    /* 1B968 8002B168 A8000224 */  addiu      $v0, $zero, 0xA8
    /* 1B96C 8002B16C 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1B970 8002B170 C0000224 */  addiu      $v0, $zero, 0xC0
    /* 1B974 8002B174 F9D6000C */  jal        func_80035BE4
    /* 1B978 8002B178 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1B97C 8002B17C 04000324 */  addiu      $v1, $zero, 0x4
    /* 1B980 8002B180 540040A0 */  sb         $zero, 0x54($v0)
    /* 1B984 8002B184 530050A0 */  sb         $s0, 0x53($v0)
    /* 1B988 8002B188 590043A0 */  sb         $v1, 0x59($v0)
    /* 1B98C 8002B18C 9DAE0008 */  j          .L8002BA74
    /* 1B990 8002B190 010070A2 */   sb        $s0, 0x1($s3)
  jlabel .L8002B194
    /* 1B994 8002B194 0000D08E */  lw         $s0, 0x0($s6)
    /* 1B998 8002B198 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 1B99C 8002B19C EDAA000C */  jal        func_8002ABB4
    /* 1B9A0 8002B1A0 21200002 */   addu      $a0, $s0, $zero
    /* 1B9A4 8002B1A4 0400028E */  lw         $v0, 0x4($s0)
    /* 1B9A8 8002B1A8 0008113C */  lui        $s1, (0x8000000 >> 16)
    /* 1B9AC 8002B1AC 24105100 */  and        $v0, $v0, $s1
    /* 1B9B0 8002B1B0 2E004014 */  bnez       $v0, .L8002B26C
    /* 1B9B4 8002B1B4 21200002 */   addu      $a0, $s0, $zero
    /* 1B9B8 8002B1B8 02000524 */  addiu      $a1, $zero, 0x2
    /* 1B9BC 8002B1BC 04000624 */  addiu      $a2, $zero, 0x4
    /* 1B9C0 8002B1C0 60000896 */  lhu        $t0, 0x60($s0)
    /* 1B9C4 8002B1C4 22000292 */  lbu        $v0, 0x22($s0)
    /* 1B9C8 8002B1C8 44000396 */  lhu        $v1, 0x44($s0)
    /* 1B9CC 8002B1CC 66000825 */  addiu      $t0, $t0, 0x66
    /* 1B9D0 8002B1D0 003C0800 */  sll        $a3, $t0, 16
    /* 1B9D4 8002B1D4 033C0700 */  sra        $a3, $a3, 16
    /* 1B9D8 8002B1D8 0C004224 */  addiu      $v0, $v0, 0xC
    /* 1B9DC 8002B1DC 220002A2 */  sb         $v0, 0x22($s0)
    /* 1B9E0 8002B1E0 21000292 */  lbu        $v0, 0x21($s0)
    /* 1B9E4 8002B1E4 CC006324 */  addiu      $v1, $v1, 0xCC
    /* 1B9E8 8002B1E8 440003A6 */  sh         $v1, 0x44($s0)
    /* 1B9EC 8002B1EC 460003A6 */  sh         $v1, 0x46($s0)
    /* 1B9F0 8002B1F0 600008A6 */  sh         $t0, 0x60($s0)
    /* 1B9F4 8002B1F4 06004224 */  addiu      $v0, $v0, 0x6
    /* 1B9F8 8002B1F8 630C010C */  jal        func_8004318C
    /* 1B9FC 8002B1FC 210002A2 */   sb        $v0, 0x21($s0)
    /* 1BA00 8002B200 60000286 */  lh         $v0, 0x60($s0)
    /* 1BA04 8002B204 00000000 */  nop
    /* 1BA08 8002B208 00084228 */  slti       $v0, $v0, 0x800
    /* 1BA0C 8002B20C 12004014 */  bnez       $v0, .L8002B258
    /* 1BA10 8002B210 0400043C */   lui       $a0, (0x40002 >> 16)
    /* 1BA14 8002B214 02008434 */  ori        $a0, $a0, (0x40002 & 0xFFFF)
    /* 1BA18 8002B218 0010033C */  lui        $v1, (0x10001000 >> 16)
    /* 1BA1C 8002B21C 00106334 */  ori        $v1, $v1, (0x10001000 & 0xFFFF)
    /* 1BA20 8002B220 00800234 */  ori        $v0, $zero, 0x8000
    /* 1BA24 8002B224 200002AE */  sw         $v0, 0x20($s0)
    /* 1BA28 8002B228 300004AE */  sw         $a0, 0x30($s0)
    /* 1BA2C 8002B22C 440003AE */  sw         $v1, 0x44($s0)
    /* 1BA30 8002B230 0400C48E */  lw         $a0, 0x4($s6)
    /* 1BA34 8002B234 FF7F033C */  lui        $v1, (0x7FFFFFFF >> 16)
    /* 1BA38 8002B238 0400828C */  lw         $v0, 0x4($a0)
    /* 1BA3C 8002B23C FFFF6334 */  ori        $v1, $v1, (0x7FFFFFFF & 0xFFFF)
    /* 1BA40 8002B240 24104300 */  and        $v0, $v0, $v1
    /* 1BA44 8002B244 040082AC */  sw         $v0, 0x4($a0)
    /* 1BA48 8002B248 0400028E */  lw         $v0, 0x4($s0)
    /* 1BA4C 8002B24C 00000000 */  nop
    /* 1BA50 8002B250 25105100 */  or         $v0, $v0, $s1
    /* 1BA54 8002B254 040002AE */  sw         $v0, 0x4($s0)
  .L8002B258:
    /* 1BA58 8002B258 0400028E */  lw         $v0, 0x4($s0)
    /* 1BA5C 8002B25C 00000000 */  nop
    /* 1BA60 8002B260 24105100 */  and        $v0, $v0, $s1
    /* 1BA64 8002B264 03024010 */  beqz       $v0, .L8002BA74
    /* 1BA68 8002B268 00000000 */   nop
  .L8002B26C:
    /* 1BA6C 8002B26C 03006292 */  lbu        $v0, 0x3($s3)
    /* 1BA70 8002B270 00000000 */  nop
    /* 1BA74 8002B274 FF014014 */  bnez       $v0, .L8002BA74
    /* 1BA78 8002B278 02000224 */   addiu     $v0, $zero, 0x2
    /* 1BA7C 8002B27C 9DAE0008 */  j          .L8002BA74
    /* 1BA80 8002B280 010062A2 */   sb        $v0, 0x1($s3)
  jlabel .L8002B284
    /* 1BA84 8002B284 04006392 */  lbu        $v1, 0x4($s3)
    /* 1BA88 8002B288 01000224 */  addiu      $v0, $zero, 0x1
    /* 1BA8C 8002B28C F9016210 */  beq        $v1, $v0, .L8002BA74
    /* 1BA90 8002B290 0F80023C */   lui       $v0, %hi(D_800E9ECE)
    /* 1BA94 8002B294 CE9E4290 */  lbu        $v0, %lo(D_800E9ECE)($v0)
    /* 1BA98 8002B298 00000000 */  nop
    /* 1BA9C 8002B29C 80004230 */  andi       $v0, $v0, 0x80
    /* 1BAA0 8002B2A0 F4014014 */  bnez       $v0, .L8002BA74
    /* 1BAA4 8002B2A4 0F80023C */   lui       $v0, %hi(D_800E9DBC)
    /* 1BAA8 8002B2A8 BC9D40AC */  sw         $zero, %lo(D_800E9DBC)($v0)
    /* 1BAAC 8002B2AC 21200000 */  addu       $a0, $zero, $zero
    /* 1BAB0 8002B2B0 21286002 */  addu       $a1, $s3, $zero
  .L8002B2B4:
    /* 1BAB4 8002B2B4 2400A28C */  lw         $v0, 0x24($a1)
    /* 1BAB8 8002B2B8 00000000 */  nop
    /* 1BABC 8002B2BC 08004394 */  lhu        $v1, 0x8($v0)
    /* 1BAC0 8002B2C0 01008424 */  addiu      $a0, $a0, 0x1
    /* 1BAC4 8002B2C4 BFFF6330 */  andi       $v1, $v1, 0xFFBF
    /* 1BAC8 8002B2C8 080043A4 */  sh         $v1, 0x8($v0)
    /* 1BACC 8002B2CC 09008228 */  slti       $v0, $a0, 0x9
    /* 1BAD0 8002B2D0 F8FF4014 */  bnez       $v0, .L8002B2B4
    /* 1BAD4 8002B2D4 0400A524 */   addiu     $a1, $a1, 0x4
    /* 1BAD8 8002B2D8 0F80023C */  lui        $v0, %hi(D_800EB24C)
    /* 1BADC 8002B2DC 4CB2438C */  lw         $v1, %lo(D_800EB24C)($v0)
    /* 1BAE0 8002B2E0 00000000 */  nop
    /* 1BAE4 8002B2E4 08006294 */  lhu        $v0, 0x8($v1)
    /* 1BAE8 8002B2E8 31000424 */  addiu      $a0, $zero, 0x31
    /* 1BAEC 8002B2EC BFFF4230 */  andi       $v0, $v0, 0xFFBF
    /* 1BAF0 8002B2F0 080062A4 */  sh         $v0, 0x8($v1)
    /* 1BAF4 8002B2F4 03000224 */  addiu      $v0, $zero, 0x3
    /* 1BAF8 8002B2F8 B8FF000C */  jal        func_8003FEE0
    /* 1BAFC 8002B2FC 010062A2 */   sb        $v0, 0x1($s3)
  jlabel .L8002B300
    /* 1BB00 8002B300 0000D08E */  lw         $s0, 0x0($s6)
    /* 1BB04 8002B304 00000000 */  nop
    /* 1BB08 8002B308 21000292 */  lbu        $v0, 0x21($s0)
    /* 1BB0C 8002B30C 00000000 */  nop
    /* 1BB10 8002B310 08004224 */  addiu      $v0, $v0, 0x8
    /* 1BB14 8002B314 210002A2 */  sb         $v0, 0x21($s0)
    /* 1BB18 8002B318 FF004230 */  andi       $v0, $v0, 0xFF
    /* 1BB1C 8002B31C D5014014 */  bnez       $v0, .L8002BA74
    /* 1BB20 8002B320 00000000 */   nop
    /* 1BB24 8002B324 08000296 */  lhu        $v0, 0x8($s0)
    /* 1BB28 8002B328 00000000 */  nop
    /* 1BB2C 8002B32C FBFF4230 */  andi       $v0, $v0, 0xFFFB
    /* 1BB30 8002B330 F2AD0008 */  j          .L8002B7C8
    /* 1BB34 8002B334 080002A6 */   sh        $v0, 0x8($s0)
  jlabel .L8002B338
    /* 1BB38 8002B338 21200000 */  addu       $a0, $zero, $zero
    /* 1BB3C 8002B33C 7064010C */  jal        func_800591C0
    /* 1BB40 8002B340 02000524 */   addiu     $a1, $zero, 0x2
    /* 1BB44 8002B344 21804000 */  addu       $s0, $v0, $zero
    /* 1BB48 8002B348 0F80173C */  lui        $s7, %hi(D_800F2848)
    /* 1BB4C 8002B34C 4828F526 */  addiu      $s5, $s7, %lo(D_800F2848)
    /* 1BB50 8002B350 4828E286 */  lh         $v0, %lo(D_800F2848)($s7)
    /* 1BB54 8002B354 0400A486 */  lh         $a0, 0x4($s5)
    /* 1BB58 8002B358 DC19020C */  jal        func_80086770
    /* 1BB5C 8002B35C 23900200 */   negu      $s2, $v0
    /* 1BB60 8002B360 18004202 */  mult       $s2, $v0
    /* 1BB64 8002B364 12100000 */  mflo       $v0
    /* 1BB68 8002B368 02004104 */  bgez       $v0, .L8002B374
    /* 1BB6C 8002B36C 00000000 */   nop
    /* 1BB70 8002B370 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8002B374:
    /* 1BB74 8002B374 0400A486 */  lh         $a0, 0x4($s5)
    /* 1BB78 8002B378 A819020C */  jal        func_800866A0
    /* 1BB7C 8002B37C 038B0200 */   sra       $s1, $v0, 12
    /* 1BB80 8002B380 18004202 */  mult       $s2, $v0
    /* 1BB84 8002B384 12100000 */  mflo       $v0
    /* 1BB88 8002B388 02004104 */  bgez       $v0, .L8002B394
    /* 1BB8C 8002B38C 00000000 */   nop
    /* 1BB90 8002B390 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8002B394:
    /* 1BB94 8002B394 0200A486 */  lh         $a0, 0x2($s5)
    /* 1BB98 8002B398 03A30200 */  sra        $s4, $v0, 12
    /* 1BB9C 8002B39C A819020C */  jal        func_800866A0
    /* 1BBA0 8002B3A0 00088424 */   addiu     $a0, $a0, 0x800
    /* 1BBA4 8002B3A4 18002202 */  mult       $s1, $v0
    /* 1BBA8 8002B3A8 12100000 */  mflo       $v0
    /* 1BBAC 8002B3AC 02004104 */  bgez       $v0, .L8002B3B8
    /* 1BBB0 8002B3B0 00000000 */   nop
    /* 1BBB4 8002B3B4 FF0F4224 */  addiu      $v0, $v0, 0xFFF
  .L8002B3B8:
    /* 1BBB8 8002B3B8 0200A486 */  lh         $a0, 0x2($s5)
    /* 1BBBC 8002B3BC 03930200 */  sra        $s2, $v0, 12
    /* 1BBC0 8002B3C0 DC19020C */  jal        func_80086770
    /* 1BBC4 8002B3C4 00088424 */   addiu     $a0, $a0, 0x800
    /* 1BBC8 8002B3C8 18002202 */  mult       $s1, $v0
    /* 1BBCC 8002B3CC 12100000 */  mflo       $v0
    /* 1BBD0 8002B3D0 03004104 */  bgez       $v0, .L8002B3E0
    /* 1BBD4 8002B3D4 038B0200 */   sra       $s1, $v0, 12
    /* 1BBD8 8002B3D8 FF0F4224 */  addiu      $v0, $v0, 0xFFF
    /* 1BBDC 8002B3DC 038B0200 */  sra        $s1, $v0, 12
  .L8002B3E0:
    /* 1BBE0 8002B3E0 000011AE */  sw         $s1, 0x0($s0)
    /* 1BBE4 8002B3E4 040014AE */  sw         $s4, 0x4($s0)
    /* 1BBE8 8002B3E8 080012AE */  sw         $s2, 0x8($s0)
    /* 1BBEC 8002B3EC 01006392 */  lbu        $v1, 0x1($s3)
    /* 1BBF0 8002B3F0 00000000 */  nop
    /* 1BBF4 8002B3F4 80006230 */  andi       $v0, $v1, 0x80
    /* 1BBF8 8002B3F8 5F004014 */  bnez       $v0, .L8002B578
    /* 1BBFC 8002B3FC 01000224 */   addiu     $v0, $zero, 0x1
    /* 1BC00 8002B400 80006234 */  ori        $v0, $v1, 0x80
    /* 1BC04 8002B404 010062A2 */  sb         $v0, 0x1($s3)
    /* 1BC08 8002B408 01000224 */  addiu      $v0, $zero, 0x1
    /* 1BC0C 8002B40C 0F80033C */  lui        $v1, %hi(D_800E9DB8)
    /* 1BC10 8002B410 020060A2 */  sb         $zero, 0x2($s3)
    /* 1BC14 8002B414 0A80013C */  lui        $at, %hi(D_8009B0C0)
    /* 1BC18 8002B418 C0B022A0 */  sb         $v0, %lo(D_8009B0C0)($at)
    /* 1BC1C 8002B41C 0380023C */  lui        $v0, %hi(func_80029934)
    /* 1BC20 8002B420 34994224 */  addiu      $v0, $v0, %lo(func_80029934)
    /* 1BC24 8002B424 B89D62AC */  sw         $v0, %lo(D_800E9DB8)($v1)
    /* 1BC28 8002B428 00006392 */  lbu        $v1, 0x0($s3)
    /* 1BC2C 8002B42C 00000000 */  nop
    /* 1BC30 8002B430 40006230 */  andi       $v0, $v1, 0x40
    /* 1BC34 8002B434 36004014 */  bnez       $v0, .L8002B510
    /* 1BC38 8002B438 100060A6 */   sh        $zero, 0x10($s3)
    /* 1BC3C 8002B43C 21200000 */  addu       $a0, $zero, $zero
    /* 1BC40 8002B440 21288000 */  addu       $a1, $a0, $zero
    /* 1BC44 8002B444 40006234 */  ori        $v0, $v1, 0x40
    /* 1BC48 8002B448 7064010C */  jal        func_800591C0
    /* 1BC4C 8002B44C 000062A2 */   sb        $v0, 0x0($s3)
    /* 1BC50 8002B450 21804000 */  addu       $s0, $v0, $zero
    /* 1BC54 8002B454 FF00033C */  lui        $v1, (0xFFFFFF >> 16)
    /* 1BC58 8002B458 FFFF6334 */  ori        $v1, $v1, (0xFFFFFF & 0xFFFF)
    /* 1BC5C 8002B45C 4000093C */  lui        $t1, (0x404040 >> 16)
    /* 1BC60 8002B460 40402935 */  ori        $t1, $t1, (0x404040 & 0xFFFF)
    /* 1BC64 8002B464 C000083C */  lui        $t0, (0xC0C0C0 >> 16)
    /* 1BC68 8002B468 C0C00835 */  ori        $t0, $t0, (0xC0C0C0 & 0xFFFF)
    /* 1BC6C 8002B46C 21200000 */  addu       $a0, $zero, $zero
    /* 1BC70 8002B470 00040524 */  addiu      $a1, $zero, 0x400
    /* 1BC74 8002B474 2130A000 */  addu       $a2, $a1, $zero
    /* 1BC78 8002B478 2138A000 */  addu       $a3, $a1, $zero
    /* 1BC7C 8002B47C 00F00224 */  addiu      $v0, $zero, -0x1000
    /* 1BC80 8002B480 040002AE */  sw         $v0, 0x4($s0)
    /* 1BC84 8002B484 00100224 */  addiu      $v0, $zero, 0x1000
    /* 1BC88 8002B488 000000AE */  sw         $zero, 0x0($s0)
    /* 1BC8C 8002B48C 080000AE */  sw         $zero, 0x8($s0)
    /* 1BC90 8002B490 0C0003AE */  sw         $v1, 0xC($s0)
    /* 1BC94 8002B494 100000AE */  sw         $zero, 0x10($s0)
    /* 1BC98 8002B498 140002AE */  sw         $v0, 0x14($s0)
    /* 1BC9C 8002B49C 180000AE */  sw         $zero, 0x18($s0)
    /* 1BCA0 8002B4A0 1C0009AE */  sw         $t1, 0x1C($s0)
    /* 1BCA4 8002B4A4 7265010C */  jal        func_800595C8
    /* 1BCA8 8002B4A8 2C0008AE */   sw        $t0, 0x2C($s0)
    /* 1BCAC 8002B4AC 21200000 */  addu       $a0, $zero, $zero
    /* 1BCB0 8002B4B0 1880053C */  lui        $a1, (0x80181000 >> 16)
    /* 1BCB4 8002B4B4 EC63010C */  jal        func_80058FB0
    /* 1BCB8 8002B4B8 0010A534 */   ori       $a1, $a1, (0x80181000 & 0xFFFF)
    /* 1BCBC 8002B4BC 1880023C */  lui        $v0, (0x80181000 >> 16)
    /* 1BCC0 8002B4C0 00104234 */  ori        $v0, $v0, (0x80181000 & 0xFFFF)
    /* 1BCC4 8002B4C4 21200000 */  addu       $a0, $zero, $zero
    /* 1BCC8 8002B4C8 34030524 */  addiu      $a1, $zero, 0x334
    /* 1BCCC 8002B4CC 02004394 */  lhu        $v1, 0x2($v0)
    /* 1BCD0 8002B4D0 00004684 */  lh         $a2, 0x0($v0)
    /* 1BCD4 8002B4D4 001C0300 */  sll        $v1, $v1, 16
    /* 1BCD8 8002B4D8 1C00A6AE */  sw         $a2, 0x1C($s5)
    /* 1BCDC 8002B4DC 04004294 */  lhu        $v0, 0x4($v0)
    /* 1BCE0 8002B4E0 031C0300 */  sra        $v1, $v1, 16
    /* 1BCE4 8002B4E4 2000A3AE */  sw         $v1, 0x20($s5)
    /* 1BCE8 8002B4E8 00140200 */  sll        $v0, $v0, 16
    /* 1BCEC 8002B4EC 03140200 */  sra        $v0, $v0, 16
    /* 1BCF0 8002B4F0 6E7C010C */  jal        func_8005F1B8
    /* 1BCF4 8002B4F4 2400A2AE */   sw        $v0, 0x24($s5)
    /* 1BCF8 8002B4F8 21200000 */  addu       $a0, $zero, $zero
    /* 1BCFC 8002B4FC 01000524 */  addiu      $a1, $zero, 0x1
    /* 1BD00 8002B500 AA66010C */  jal        func_80059AA8
    /* 1BD04 8002B504 4828E2A6 */   sh        $v0, %lo(D_800F2848)($s7)
    /* 1BD08 8002B508 B866010C */  jal        func_80059AE0
    /* 1BD0C 8002B50C 21200000 */   addu      $a0, $zero, $zero
  .L8002B510:
    /* 1BD10 8002B510 21200000 */  addu       $a0, $zero, $zero
    /* 1BD14 8002B514 21288000 */  addu       $a1, $a0, $zero
    /* 1BD18 8002B518 BD5E010C */  jal        func_80057AF4
    /* 1BD1C 8002B51C 01000624 */   addiu     $a2, $zero, 0x1
    /* 1BD20 8002B520 21200000 */  addu       $a0, $zero, $zero
    /* 1BD24 8002B524 01000524 */  addiu      $a1, $zero, 0x1
    /* 1BD28 8002B528 F265010C */  jal        func_800597C8
    /* 1BD2C 8002B52C 21308000 */   addu      $a2, $a0, $zero
    /* 1BD30 8002B530 2C010224 */  addiu      $v0, $zero, 0x12C
    /* 1BD34 8002B534 200062AE */  sw         $v0, 0x20($s3)
    /* 1BD38 8002B538 02000224 */  addiu      $v0, $zero, 0x2
    /* 1BD3C 8002B53C 030062A2 */  sb         $v0, 0x3($s3)
    /* 1BD40 8002B540 0000D08E */  lw         $s0, 0x0($s6)
    /* 1BD44 8002B544 00000000 */  nop
    /* 1BD48 8002B548 08000296 */  lhu        $v0, 0x8($s0)
    /* 1BD4C 8002B54C 21200002 */  addu       $a0, $s0, $zero
    /* 1BD50 8002B550 04004234 */  ori        $v0, $v0, 0x4
    /* 1BD54 8002B554 5E0C010C */  jal        func_80043178
    /* 1BD58 8002B558 080002A6 */   sh        $v0, 0x8($s0)
    /* 1BD5C 8002B55C 34000424 */  addiu      $a0, $zero, 0x34
    /* 1BD60 8002B560 B8FF000C */  jal        func_8003FEE0
    /* 1BD64 8002B564 600000A6 */   sh        $zero, 0x60($s0)
    /* 1BD68 8002B568 0357000C */  jal        func_80015C0C
    /* 1BD6C 8002B56C 00000000 */   nop
    /* 1BD70 8002B570 9DAE0008 */  j          .L8002BA74
    /* 1BD74 8002B574 00000000 */   nop
  .L8002B578:
    /* 1BD78 8002B578 02007192 */  lbu        $s1, 0x2($s3)
    /* 1BD7C 8002B57C 00000000 */  nop
    /* 1BD80 8002B580 49002212 */  beq        $s1, $v0, .L8002B6A8
    /* 1BD84 8002B584 0200222A */   slti      $v0, $s1, 0x2
    /* 1BD88 8002B588 05004010 */  beqz       $v0, .L8002B5A0
    /* 1BD8C 8002B58C 00000000 */   nop
    /* 1BD90 8002B590 08002012 */  beqz       $s1, .L8002B5B4
    /* 1BD94 8002B594 00000000 */   nop
    /* 1BD98 8002B598 9DAE0008 */  j          .L8002BA74
    /* 1BD9C 8002B59C 00000000 */   nop
  .L8002B5A0:
    /* 1BDA0 8002B5A0 02000224 */  addiu      $v0, $zero, 0x2
    /* 1BDA4 8002B5A4 52002212 */  beq        $s1, $v0, .L8002B6F0
    /* 1BDA8 8002B5A8 00000000 */   nop
    /* 1BDAC 8002B5AC 9DAE0008 */  j          .L8002BA74
    /* 1BDB0 8002B5B0 00000000 */   nop
  .L8002B5B4:
    /* 1BDB4 8002B5B4 0000D08E */  lw         $s0, 0x0($s6)
    /* 1BDB8 8002B5B8 00000000 */  nop
    /* 1BDBC 8002B5BC 60000286 */  lh         $v0, 0x60($s0)
    /* 1BDC0 8002B5C0 00000000 */  nop
    /* 1BDC4 8002B5C4 00084228 */  slti       $v0, $v0, 0x800
    /* 1BDC8 8002B5C8 1D004010 */  beqz       $v0, .L8002B640
    /* 1BDCC 8002B5CC 00000000 */   nop
    /* 1BDD0 8002B5D0 21000292 */  lbu        $v0, 0x21($s0)
    /* 1BDD4 8002B5D4 00000000 */  nop
    /* 1BDD8 8002B5D8 FCFF4224 */  addiu      $v0, $v0, -0x4
    /* 1BDDC 8002B5DC 210002A2 */  sb         $v0, 0x21($s0)
    /* 1BDE0 8002B5E0 FF004230 */  andi       $v0, $v0, 0xFF
    /* 1BDE4 8002B5E4 D800422C */  sltiu      $v0, $v0, 0xD8
    /* 1BDE8 8002B5E8 02004010 */  beqz       $v0, .L8002B5F4
    /* 1BDEC 8002B5EC D8000224 */   addiu     $v0, $zero, 0xD8
    /* 1BDF0 8002B5F0 210002A2 */  sb         $v0, 0x21($s0)
  .L8002B5F4:
    /* 1BDF4 8002B5F4 21200002 */  addu       $a0, $s0, $zero
    /* 1BDF8 8002B5F8 EAFF0524 */  addiu      $a1, $zero, -0x16
    /* 1BDFC 8002B5FC 60000296 */  lhu        $v0, 0x60($s0)
    /* 1BE00 8002B600 04000624 */  addiu      $a2, $zero, 0x4
    /* 1BE04 8002B604 CC004224 */  addiu      $v0, $v0, 0xCC
    /* 1BE08 8002B608 003C0200 */  sll        $a3, $v0, 16
    /* 1BE0C 8002B60C 033C0700 */  sra        $a3, $a3, 16
    /* 1BE10 8002B610 630C010C */  jal        func_8004318C
    /* 1BE14 8002B614 600002A6 */   sh        $v0, 0x60($s0)
    /* 1BE18 8002B618 60000286 */  lh         $v0, 0x60($s0)
    /* 1BE1C 8002B61C 00000000 */  nop
    /* 1BE20 8002B620 00084228 */  slti       $v0, $v0, 0x800
    /* 1BE24 8002B624 06004014 */  bnez       $v0, .L8002B640
    /* 1BE28 8002B628 D8000224 */   addiu     $v0, $zero, 0xD8
    /* 1BE2C 8002B62C 210002A2 */  sb         $v0, 0x21($s0)
    /* 1BE30 8002B630 EAFF0224 */  addiu      $v0, $zero, -0x16
    /* 1BE34 8002B634 300002A6 */  sh         $v0, 0x30($s0)
    /* 1BE38 8002B638 04000224 */  addiu      $v0, $zero, 0x4
    /* 1BE3C 8002B63C 320002A6 */  sh         $v0, 0x32($s0)
  .L8002B640:
    /* 1BE40 8002B640 10006296 */  lhu        $v0, 0x10($s3)
    /* 1BE44 8002B644 00000000 */  nop
    /* 1BE48 8002B648 2A004224 */  addiu      $v0, $v0, 0x2A
    /* 1BE4C 8002B64C 100062A6 */  sh         $v0, 0x10($s3)
    /* 1BE50 8002B650 00140200 */  sll        $v0, $v0, 16
    /* 1BE54 8002B654 03140200 */  sra        $v0, $v0, 16
    /* 1BE58 8002B658 00044228 */  slti       $v0, $v0, 0x400
    /* 1BE5C 8002B65C 05014014 */  bnez       $v0, .L8002BA74
    /* 1BE60 8002B660 00040224 */   addiu     $v0, $zero, 0x400
    /* 1BE64 8002B664 100062A6 */  sh         $v0, 0x10($s3)
    /* 1BE68 8002B668 0F80023C */  lui        $v0, %hi(D_800E9ECE)
    /* 1BE6C 8002B66C CE9E4290 */  lbu        $v0, %lo(D_800E9ECE)($v0)
    /* 1BE70 8002B670 00000000 */  nop
    /* 1BE74 8002B674 80004230 */  andi       $v0, $v0, 0x80
    /* 1BE78 8002B678 FE004014 */  bnez       $v0, .L8002BA74
    /* 1BE7C 8002B67C 00000000 */   nop
    /* 1BE80 8002B680 03006292 */  lbu        $v0, 0x3($s3)
    /* 1BE84 8002B684 00000000 */  nop
    /* 1BE88 8002B688 FA004014 */  bnez       $v0, .L8002BA74
    /* 1BE8C 8002B68C 01000524 */   addiu     $a1, $zero, 0x1
    /* 1BE90 8002B690 5000648E */  lw         $a0, 0x50($s3)
    /* 1BE94 8002B694 2110A000 */  addu       $v0, $a1, $zero
    /* 1BE98 8002B698 0401010C */  jal        func_80040410
    /* 1BE9C 8002B69C 020062A2 */   sb        $v0, 0x2($s3)
    /* 1BEA0 8002B6A0 9DAE0008 */  j          .L8002BA74
    /* 1BEA4 8002B6A4 00000000 */   nop
  .L8002B6A8:
    /* 1BEA8 8002B6A8 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* 1BEAC 8002B6AC 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* 1BEB0 8002B6B0 00000000 */  nop
    /* 1BEB4 8002B6B4 E0804230 */  andi       $v0, $v0, 0x80E0
    /* 1BEB8 8002B6B8 EE004010 */  beqz       $v0, .L8002BA74
    /* 1BEBC 8002B6BC 00000000 */   nop
    /* 1BEC0 8002B6C0 2157000C */  jal        func_80015C84
    /* 1BEC4 8002B6C4 00000000 */   nop
    /* 1BEC8 8002B6C8 34000424 */  addiu      $a0, $zero, 0x34
    /* 1BECC 8002B6CC 02000224 */  addiu      $v0, $zero, 0x2
    /* 1BED0 8002B6D0 030071A2 */  sb         $s1, 0x3($s3)
    /* 1BED4 8002B6D4 B8FF000C */  jal        func_8003FEE0
    /* 1BED8 8002B6D8 020062A2 */   sb        $v0, 0x2($s3)
    /* 1BEDC 8002B6DC 0000D08E */  lw         $s0, 0x0($s6)
    /* 1BEE0 8002B6E0 5E0C010C */  jal        func_80043178
    /* 1BEE4 8002B6E4 21200002 */   addu      $a0, $s0, $zero
    /* 1BEE8 8002B6E8 9DAE0008 */  j          .L8002BA74
    /* 1BEEC 8002B6EC 600000A6 */   sh        $zero, 0x60($s0)
  .L8002B6F0:
    /* 1BEF0 8002B6F0 0000D08E */  lw         $s0, 0x0($s6)
    /* 1BEF4 8002B6F4 00000000 */  nop
    /* 1BEF8 8002B6F8 08000296 */  lhu        $v0, 0x8($s0)
    /* 1BEFC 8002B6FC 00000000 */  nop
    /* 1BF00 8002B700 04004230 */  andi       $v0, $v0, 0x4
    /* 1BF04 8002B704 1C004010 */  beqz       $v0, .L8002B778
    /* 1BF08 8002B708 21200002 */   addu      $a0, $s0, $zero
    /* 1BF0C 8002B70C 02000524 */  addiu      $a1, $zero, 0x2
    /* 1BF10 8002B710 04000624 */  addiu      $a2, $zero, 0x4
    /* 1BF14 8002B714 60000396 */  lhu        $v1, 0x60($s0)
    /* 1BF18 8002B718 21000292 */  lbu        $v0, 0x21($s0)
    /* 1BF1C 8002B71C CC006324 */  addiu      $v1, $v1, 0xCC
    /* 1BF20 8002B720 003C0300 */  sll        $a3, $v1, 16
    /* 1BF24 8002B724 033C0700 */  sra        $a3, $a3, 16
    /* 1BF28 8002B728 21104600 */  addu       $v0, $v0, $a2
    /* 1BF2C 8002B72C 210002A2 */  sb         $v0, 0x21($s0)
    /* 1BF30 8002B730 630C010C */  jal        func_8004318C
    /* 1BF34 8002B734 600003A6 */   sh        $v1, 0x60($s0)
    /* 1BF38 8002B738 60000286 */  lh         $v0, 0x60($s0)
    /* 1BF3C 8002B73C 00000000 */  nop
    /* 1BF40 8002B740 00084228 */  slti       $v0, $v0, 0x800
    /* 1BF44 8002B744 07004014 */  bnez       $v0, .L8002B764
    /* 1BF48 8002B748 04000324 */   addiu     $v1, $zero, 0x4
    /* 1BF4C 8002B74C 08000296 */  lhu        $v0, 0x8($s0)
    /* 1BF50 8002B750 210000A2 */  sb         $zero, 0x21($s0)
    /* 1BF54 8002B754 300011A6 */  sh         $s1, 0x30($s0)
    /* 1BF58 8002B758 320003A6 */  sh         $v1, 0x32($s0)
    /* 1BF5C 8002B75C FBFF4230 */  andi       $v0, $v0, 0xFFFB
    /* 1BF60 8002B760 080002A6 */  sh         $v0, 0x8($s0)
  .L8002B764:
    /* 1BF64 8002B764 08000296 */  lhu        $v0, 0x8($s0)
    /* 1BF68 8002B768 00000000 */  nop
    /* 1BF6C 8002B76C 04004230 */  andi       $v0, $v0, 0x4
    /* 1BF70 8002B770 C0004014 */  bnez       $v0, .L8002BA74
    /* 1BF74 8002B774 00000000 */   nop
  .L8002B778:
    /* 1BF78 8002B778 0F80023C */  lui        $v0, %hi(D_800E9ECE)
    /* 1BF7C 8002B77C CE9E4290 */  lbu        $v0, %lo(D_800E9ECE)($v0)
    /* 1BF80 8002B780 00000000 */  nop
    /* 1BF84 8002B784 80004230 */  andi       $v0, $v0, 0x80
    /* 1BF88 8002B788 BA004014 */  bnez       $v0, .L8002BA74
    /* 1BF8C 8002B78C 00000000 */   nop
    /* 1BF90 8002B790 03006292 */  lbu        $v0, 0x3($s3)
    /* 1BF94 8002B794 00000000 */  nop
    /* 1BF98 8002B798 B6004014 */  bnez       $v0, .L8002BA74
    /* 1BF9C 8002B79C 00000000 */   nop
    /* 1BFA0 8002B7A0 B11F010C */  jal        func_80047EC4
    /* 1BFA4 8002B7A4 00000000 */   nop
    /* 1BFA8 8002B7A8 0F80023C */  lui        $v0, %hi(D_800E9DB8)
    /* 1BFAC 8002B7AC B89D40AC */  sw         $zero, %lo(D_800E9DB8)($v0)
    /* 1BFB0 8002B7B0 5000648E */  lw         $a0, 0x50($s3)
    /* 1BFB4 8002B7B4 02000524 */  addiu      $a1, $zero, 0x2
    /* 1BFB8 8002B7B8 0A80013C */  lui        $at, %hi(D_8009B0C0)
    /* 1BFBC 8002B7BC C0B020A0 */  sb         $zero, %lo(D_8009B0C0)($at)
    /* 1BFC0 8002B7C0 0401010C */  jal        func_80040410
    /* 1BFC4 8002B7C4 00000000 */   nop
  .L8002B7C8:
    /* 1BFC8 8002B7C8 05000224 */  addiu      $v0, $zero, 0x5
    /* 1BFCC 8002B7CC 9DAE0008 */  j          .L8002BA74
    /* 1BFD0 8002B7D0 010062A2 */   sb        $v0, 0x1($s3)
  jlabel .L8002B7D4
    /* 1BFD4 8002B7D4 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* 1BFD8 8002B7D8 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* 1BFDC 8002B7DC 00000000 */  nop
    /* 1BFE0 8002B7E0 20004230 */  andi       $v0, $v0, 0x20
    /* 1BFE4 8002B7E4 12004010 */  beqz       $v0, .L8002B830
    /* 1BFE8 8002B7E8 00000000 */   nop
    /* 1BFEC 8002B7EC 0000C28E */  lw         $v0, 0x0($s6)
    /* 1BFF0 8002B7F0 00000000 */  nop
    /* 1BFF4 8002B7F4 08004394 */  lhu        $v1, 0x8($v0)
    /* 1BFF8 8002B7F8 00000000 */  nop
    /* 1BFFC 8002B7FC 04006334 */  ori        $v1, $v1, 0x4
    /* 1C000 8002B800 080043A4 */  sh         $v1, 0x8($v0)
    /* 1C004 8002B804 5000648E */  lw         $a0, 0x50($s3)
    /* 1C008 8002B808 06000224 */  addiu      $v0, $zero, 0x6
    /* 1C00C 8002B80C 010062A2 */  sb         $v0, 0x1($s3)
    /* 1C010 8002B810 DB00010C */  jal        func_8004036C
    /* 1C014 8002B814 040060A2 */   sb        $zero, 0x4($s3)
    /* 1C018 8002B818 E953000C */  jal        func_80014FA4
    /* 1C01C 8002B81C 00000000 */   nop
    /* 1C020 8002B820 B8FF000C */  jal        func_8003FEE0
    /* 1C024 8002B824 31000424 */   addiu     $a0, $zero, 0x31
    /* 1C028 8002B828 9DAE0008 */  j          .L8002BA74
    /* 1C02C 8002B82C 00000000 */   nop
  .L8002B830:
    /* 1C030 8002B830 04006292 */  lbu        $v0, 0x4($s3)
    /* 1C034 8002B834 00000000 */  nop
    /* 1C038 8002B838 8E004014 */  bnez       $v0, .L8002BA74
    /* 1C03C 8002B83C 00000000 */   nop
    /* 1C040 8002B840 0A80023C */  lui        $v0, %hi(D_8009B398)
    /* 1C044 8002B844 98B34294 */  lhu        $v0, %lo(D_8009B398)($v0)
    /* 1C048 8002B848 00000000 */  nop
    /* 1C04C 8002B84C C0204230 */  andi       $v0, $v0, 0x20C0
    /* 1C050 8002B850 88004010 */  beqz       $v0, .L8002BA74
    /* 1C054 8002B854 1D80033C */   lui       $v1, %hi(D_801D4244)
    /* 1C058 8002B858 06006296 */  lhu        $v0, 0x6($s3)
    /* 1C05C 8002B85C 44426324 */  addiu      $v1, $v1, %lo(D_801D4244)
    /* 1C060 8002B860 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 1C064 8002B864 80100200 */  sll        $v0, $v0, 2
    /* 1C068 8002B868 21104300 */  addu       $v0, $v0, $v1
    /* 1C06C 8002B86C 0000428C */  lw         $v0, 0x0($v0)
    /* 1C070 8002B870 00000000 */  nop
    /* 1C074 8002B874 83160200 */  sra        $v0, $v0, 26
    /* 1C078 8002B878 1F004230 */  andi       $v0, $v0, 0x1F
    /* 1C07C 8002B87C 14004228 */  slti       $v0, $v0, 0x14
    /* 1C080 8002B880 7C004010 */  beqz       $v0, .L8002BA74
    /* 1C084 8002B884 00000000 */   nop
    /* 1C088 8002B888 03006292 */  lbu        $v0, 0x3($s3)
    /* 1C08C 8002B88C 00000000 */  nop
    /* 1C090 8002B890 78004014 */  bnez       $v0, .L8002BA74
    /* 1C094 8002B894 04000224 */   addiu     $v0, $zero, 0x4
    /* 1C098 8002B898 9DAE0008 */  j          .L8002BA74
    /* 1C09C 8002B89C 010062A2 */   sb        $v0, 0x1($s3)
  jlabel .L8002B8A0
    /* 1C0A0 8002B8A0 0000D08E */  lw         $s0, 0x0($s6)
    /* 1C0A4 8002B8A4 00000000 */  nop
    /* 1C0A8 8002B8A8 21000292 */  lbu        $v0, 0x21($s0)
    /* 1C0AC 8002B8AC 00000000 */  nop
    /* 1C0B0 8002B8B0 08004224 */  addiu      $v0, $v0, 0x8
    /* 1C0B4 8002B8B4 210002A2 */  sb         $v0, 0x21($s0)
    /* 1C0B8 8002B8B8 00160200 */  sll        $v0, $v0, 24
    /* 1C0BC 8002B8BC 6D004104 */  bgez       $v0, .L8002BA74
    /* 1C0C0 8002B8C0 FFF7053C */   lui       $a1, (0xF7FFFFFF >> 16)
    /* 1C0C4 8002B8C4 0400C48E */  lw         $a0, 0x4($s6)
    /* 1C0C8 8002B8C8 FFFFA534 */  ori        $a1, $a1, (0xF7FFFFFF & 0xFFFF)
    /* 1C0CC 8002B8CC 0400828C */  lw         $v0, 0x4($a0)
    /* 1C0D0 8002B8D0 0080033C */  lui        $v1, (0x80000000 >> 16)
    /* 1C0D4 8002B8D4 25104300 */  or         $v0, $v0, $v1
    /* 1C0D8 8002B8D8 040082AC */  sw         $v0, 0x4($a0)
    /* 1C0DC 8002B8DC 0400028E */  lw         $v0, 0x4($s0)
    /* 1C0E0 8002B8E0 21200002 */  addu       $a0, $s0, $zero
    /* 1C0E4 8002B8E4 24104500 */  and        $v0, $v0, $a1
    /* 1C0E8 8002B8E8 5E0C010C */  jal        func_80043178
    /* 1C0EC 8002B8EC 040002AE */   sw        $v0, 0x4($s0)
    /* 1C0F0 8002B8F0 21200000 */  addu       $a0, $zero, $zero
    /* 1C0F4 8002B8F4 21286002 */  addu       $a1, $s3, $zero
    /* 1C0F8 8002B8F8 600000A6 */  sh         $zero, 0x60($s0)
  .L8002B8FC:
    /* 1C0FC 8002B8FC 2400A28C */  lw         $v0, 0x24($a1)
    /* 1C100 8002B900 00000000 */  nop
    /* 1C104 8002B904 08004394 */  lhu        $v1, 0x8($v0)
    /* 1C108 8002B908 01008424 */  addiu      $a0, $a0, 0x1
    /* 1C10C 8002B90C 40006334 */  ori        $v1, $v1, 0x40
    /* 1C110 8002B910 080043A4 */  sh         $v1, 0x8($v0)
    /* 1C114 8002B914 09008228 */  slti       $v0, $a0, 0x9
    /* 1C118 8002B918 F8FF4014 */  bnez       $v0, .L8002B8FC
    /* 1C11C 8002B91C 0400A524 */   addiu     $a1, $a1, 0x4
    /* 1C120 8002B920 0F80023C */  lui        $v0, %hi(D_800EB24C)
    /* 1C124 8002B924 4CB2438C */  lw         $v1, %lo(D_800EB24C)($v0)
    /* 1C128 8002B928 00000000 */  nop
    /* 1C12C 8002B92C 08006294 */  lhu        $v0, 0x8($v1)
    /* 1C130 8002B930 00000000 */  nop
    /* 1C134 8002B934 40004234 */  ori        $v0, $v0, 0x40
    /* 1C138 8002B938 080062A4 */  sh         $v0, 0x8($v1)
    /* 1C13C 8002B93C 0F80033C */  lui        $v1, %hi(D_800E9DBC)
    /* 1C140 8002B940 0380023C */  lui        $v0, %hi(func_80029EC4)
    /* 1C144 8002B944 C49E4224 */  addiu      $v0, $v0, %lo(func_80029EC4)
    /* 1C148 8002B948 0357000C */  jal        func_80015C0C
    /* 1C14C 8002B94C BC9D62AC */   sw        $v0, %lo(D_800E9DBC)($v1)
    /* 1C150 8002B950 33000424 */  addiu      $a0, $zero, 0x33
    /* 1C154 8002B954 02000224 */  addiu      $v0, $zero, 0x2
    /* 1C158 8002B958 030062A2 */  sb         $v0, 0x3($s3)
    /* 1C15C 8002B95C 07000224 */  addiu      $v0, $zero, 0x7
    /* 1C160 8002B960 B8FF000C */  jal        func_8003FEE0
    /* 1C164 8002B964 010062A2 */   sb        $v0, 0x1($s3)
    /* 1C168 8002B968 9DAE0008 */  j          .L8002BA74
    /* 1C16C 8002B96C 00000000 */   nop
  jlabel .L8002B970
    /* 1C170 8002B970 0000D08E */  lw         $s0, 0x0($s6)
    /* 1C174 8002B974 00000000 */  nop
    /* 1C178 8002B978 2E000012 */  beqz       $s0, .L8002BA34
    /* 1C17C 8002B97C 21200002 */   addu      $a0, $s0, $zero
    /* 1C180 8002B980 EDAA000C */  jal        func_8002ABB4
    /* 1C184 8002B984 01000524 */   addiu     $a1, $zero, 0x1
    /* 1C188 8002B988 21200002 */  addu       $a0, $s0, $zero
    /* 1C18C 8002B98C 60000596 */  lhu        $a1, 0x60($s0)
    /* 1C190 8002B990 22000292 */  lbu        $v0, 0x22($s0)
    /* 1C194 8002B994 21000392 */  lbu        $v1, 0x21($s0)
    /* 1C198 8002B998 6600A524 */  addiu      $a1, $a1, 0x66
    /* 1C19C 8002B99C 003C0500 */  sll        $a3, $a1, 16
    /* 1C1A0 8002B9A0 033C0700 */  sra        $a3, $a3, 16
    /* 1C1A4 8002B9A4 0C004224 */  addiu      $v0, $v0, 0xC
    /* 1C1A8 8002B9A8 06006324 */  addiu      $v1, $v1, 0x6
    /* 1C1AC 8002B9AC 220002A2 */  sb         $v0, 0x22($s0)
    /* 1C1B0 8002B9B0 210003A2 */  sb         $v1, 0x21($s0)
    /* 1C1B4 8002B9B4 600005A6 */  sh         $a1, 0x60($s0)
    /* 1C1B8 8002B9B8 08006586 */  lh         $a1, 0x8($s3)
    /* 1C1BC 8002B9BC 48000286 */  lh         $v0, 0x48($s0)
    /* 1C1C0 8002B9C0 0A80033C */  lui        $v1, %hi(D_8009B146)
    /* 1C1C4 8002B9C4 46B16384 */  lh         $v1, %lo(D_8009B146)($v1)
    /* 1C1C8 8002B9C8 0A006686 */  lh         $a2, 0xA($s3)
    /* 1C1CC 8002B9CC 2328A200 */  subu       $a1, $a1, $v0
    /* 1C1D0 8002B9D0 2328A300 */  subu       $a1, $a1, $v1
    /* 1C1D4 8002B9D4 4A000286 */  lh         $v0, 0x4A($s0)
    /* 1C1D8 8002B9D8 0A80033C */  lui        $v1, %hi(D_8009B148)
    /* 1C1DC 8002B9DC 48B16384 */  lh         $v1, %lo(D_8009B148)($v1)
    /* 1C1E0 8002B9E0 2330C200 */  subu       $a2, $a2, $v0
    /* 1C1E4 8002B9E4 630C010C */  jal        func_8004318C
    /* 1C1E8 8002B9E8 2330C300 */   subu      $a2, $a2, $v1
    /* 1C1EC 8002B9EC 44000296 */  lhu        $v0, 0x44($s0)
    /* 1C1F0 8002B9F0 60000386 */  lh         $v1, 0x60($s0)
    /* 1C1F4 8002B9F4 34FF4224 */  addiu      $v0, $v0, -0xCC
    /* 1C1F8 8002B9F8 00086328 */  slti       $v1, $v1, 0x800
    /* 1C1FC 8002B9FC 440002A6 */  sh         $v0, 0x44($s0)
    /* 1C200 8002BA00 1C006014 */  bnez       $v1, .L8002BA74
    /* 1C204 8002BA04 460002A6 */   sh        $v0, 0x46($s0)
    /* 1C208 8002BA08 4AA5000C */  jal        func_80029528
    /* 1C20C 8002BA0C 21200000 */   addu      $a0, $zero, $zero
    /* 1C210 8002BA10 06006396 */  lhu        $v1, 0x6($s3)
    /* 1C214 8002BA14 00000000 */  nop
    /* 1C218 8002BA18 80180300 */  sll        $v1, $v1, 2
    /* 1C21C 8002BA1C 21186302 */  addu       $v1, $s3, $v1
    /* 1C220 8002BA20 56006290 */  lbu        $v0, 0x56($v1)
    /* 1C224 8002BA24 00000000 */  nop
    /* 1C228 8002BA28 80004234 */  ori        $v0, $v0, 0x80
    /* 1C22C 8002BA2C 9DAE0008 */  j          .L8002BA74
    /* 1C230 8002BA30 560062A0 */   sb        $v0, 0x56($v1)
  .L8002BA34:
    /* 1C234 8002BA34 03006292 */  lbu        $v0, 0x3($s3)
    /* 1C238 8002BA38 00000000 */  nop
    /* 1C23C 8002BA3C 0D004014 */  bnez       $v0, .L8002BA74
    /* 1C240 8002BA40 00000000 */   nop
    /* 1C244 8002BA44 4C00648E */  lw         $a0, 0x4C($s3)
    /* 1C248 8002BA48 DB00010C */  jal        func_8004036C
    /* 1C24C 8002BA4C 00000000 */   nop
    /* 1C250 8002BA50 0F80043C */  lui        $a0, %hi(D_800EB0F8)
    /* 1C254 8002BA54 F8B08424 */  addiu      $a0, $a0, %lo(D_800EB0F8)
    /* 1C258 8002BA58 DFD6000C */  jal        func_80035B7C
    /* 1C25C 8002BA5C 4C0060AE */   sw        $zero, 0x4C($s3)
    /* 1C260 8002BA60 08000224 */  addiu      $v0, $zero, 0x8
    /* 1C264 8002BA64 9DAE0008 */  j          .L8002BA74
    /* 1C268 8002BA68 010062A2 */   sb        $v0, 0x1($s3)
  jlabel .L8002BA6C
    /* 1C26C 8002BA6C 01000224 */  addiu      $v0, $zero, 0x1
    /* 1C270 8002BA70 000062A2 */  sb         $v0, 0x0($s3)
  .L8002BA74:
    /* 1C274 8002BA74 4000BF8F */  lw         $ra, 0x40($sp)
    /* 1C278 8002BA78 3C00B78F */  lw         $s7, 0x3C($sp)
    /* 1C27C 8002BA7C 3800B68F */  lw         $s6, 0x38($sp)
    /* 1C280 8002BA80 3400B58F */  lw         $s5, 0x34($sp)
    /* 1C284 8002BA84 3000B48F */  lw         $s4, 0x30($sp)
    /* 1C288 8002BA88 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 1C28C 8002BA8C 2800B28F */  lw         $s2, 0x28($sp)
    /* 1C290 8002BA90 2400B18F */  lw         $s1, 0x24($sp)
    /* 1C294 8002BA94 2000B08F */  lw         $s0, 0x20($sp)
    /* 1C298 8002BA98 0800E003 */  jr         $ra
    /* 1C29C 8002BA9C 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_8002ACA4
