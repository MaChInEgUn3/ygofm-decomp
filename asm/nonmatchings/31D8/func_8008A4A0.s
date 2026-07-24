nonmatching func_8008A4A0, 0x2B8

glabel func_8008A4A0
    /* 7ACA0 8008A4A0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7ACA4 8008A4A4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 7ACA8 8008A4A8 2190A000 */  addu       $s2, $a1, $zero
    /* 7ACAC 8008A4AC 21388000 */  addu       $a3, $a0, $zero
    /* 7ACB0 8008A4B0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7ACB4 8008A4B4 21880000 */  addu       $s1, $zero, $zero
    /* 7ACB8 8008A4B8 64000524 */  addiu      $a1, $zero, 0x64
    /* 7ACBC 8008A4BC 1080063C */  lui        $a2, %hi(D_800FE278)
    /* 7ACC0 8008A4C0 78E2C624 */  addiu      $a2, $a2, %lo(D_800FE278)
    /* 7ACC4 8008A4C4 64000824 */  addiu      $t0, $zero, 0x64
    /* 7ACC8 8008A4C8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 7ACCC 8008A4CC 1000B0AF */  sw         $s0, 0x10($sp)
  .L8008A4D0:
    /* 7ACD0 8008A4D0 80101100 */  sll        $v0, $s1, 2
    /* 7ACD4 8008A4D4 21104600 */  addu       $v0, $v0, $a2
    /* 7ACD8 8008A4D8 000047AC */  sw         $a3, 0x0($v0)
    /* 7ACDC 8008A4DC 4C00E48C */  lw         $a0, 0x4C($a3)
    /* 7ACE0 8008A4E0 00000000 */  nop
    /* 7ACE4 8008A4E4 59008014 */  bnez       $a0, .L8008A64C
    /* 7ACE8 8008A4E8 00000000 */   nop
    /* 7ACEC 8008A4EC 0000E38C */  lw         $v1, 0x0($a3)
    /* 7ACF0 8008A4F0 1080023C */  lui        $v0, %hi(D_800FE0C8)
    /* 7ACF4 8008A4F4 C8E0428C */  lw         $v0, %lo(D_800FE0C8)($v0)
    /* 7ACF8 8008A4F8 00000000 */  nop
    /* 7ACFC 8008A4FC 03006210 */  beq        $v1, $v0, .L8008A50C
    /* 7AD00 8008A500 00000000 */   nop
    /* 7AD04 8008A504 25006014 */  bnez       $v1, .L8008A59C
    /* 7AD08 8008A508 00000000 */   nop
  .L8008A50C:
    /* 7AD0C 8008A50C 0400E28C */  lw         $v0, 0x4($a3)
    /* 7AD10 8008A510 0800E38C */  lw         $v1, 0x8($a3)
    /* 7AD14 8008A514 0C00E48C */  lw         $a0, 0xC($a3)
    /* 7AD18 8008A518 1000E58C */  lw         $a1, 0x10($a3)
    /* 7AD1C 8008A51C 2400E2AC */  sw         $v0, 0x24($a3)
    /* 7AD20 8008A520 2800E3AC */  sw         $v1, 0x28($a3)
    /* 7AD24 8008A524 2C00E4AC */  sw         $a0, 0x2C($a3)
    /* 7AD28 8008A528 3000E5AC */  sw         $a1, 0x30($a3)
    /* 7AD2C 8008A52C 1400E28C */  lw         $v0, 0x14($a3)
    /* 7AD30 8008A530 1800E38C */  lw         $v1, 0x18($a3)
    /* 7AD34 8008A534 1C00E48C */  lw         $a0, 0x1C($a3)
    /* 7AD38 8008A538 2000E58C */  lw         $a1, 0x20($a3)
    /* 7AD3C 8008A53C 3400E2AC */  sw         $v0, 0x34($a3)
    /* 7AD40 8008A540 3800E3AC */  sw         $v1, 0x38($a3)
    /* 7AD44 8008A544 3C00E4AC */  sw         $a0, 0x3C($a3)
    /* 7AD48 8008A548 4000E5AC */  sw         $a1, 0x40($a3)
    /* 7AD4C 8008A54C 1080023C */  lui        $v0, %hi(D_800FE0C8)
    /* 7AD50 8008A550 C8E0428C */  lw         $v0, %lo(D_800FE0C8)($v0)
    /* 7AD54 8008A554 2400E38C */  lw         $v1, 0x24($a3)
    /* 7AD58 8008A558 2800E48C */  lw         $a0, 0x28($a3)
    /* 7AD5C 8008A55C 2C00E58C */  lw         $a1, 0x2C($a3)
    /* 7AD60 8008A560 3000E68C */  lw         $a2, 0x30($a3)
    /* 7AD64 8008A564 000043AE */  sw         $v1, 0x0($s2)
    /* 7AD68 8008A568 040044AE */  sw         $a0, 0x4($s2)
    /* 7AD6C 8008A56C 080045AE */  sw         $a1, 0x8($s2)
    /* 7AD70 8008A570 0C0046AE */  sw         $a2, 0xC($s2)
    /* 7AD74 8008A574 3400E38C */  lw         $v1, 0x34($a3)
    /* 7AD78 8008A578 3800E48C */  lw         $a0, 0x38($a3)
    /* 7AD7C 8008A57C 3C00E58C */  lw         $a1, 0x3C($a3)
    /* 7AD80 8008A580 4000E68C */  lw         $a2, 0x40($a3)
    /* 7AD84 8008A584 100043AE */  sw         $v1, 0x10($s2)
    /* 7AD88 8008A588 140044AE */  sw         $a0, 0x14($s2)
    /* 7AD8C 8008A58C 180045AE */  sw         $a1, 0x18($s2)
    /* 7AD90 8008A590 1C0046AE */  sw         $a2, 0x1C($s2)
    /* 7AD94 8008A594 AF290208 */  j          .L8008A6BC
    /* 7AD98 8008A598 0000E2AC */   sw        $v0, 0x0($a3)
  .L8008A59C:
    /* 7AD9C 8008A59C 1600A814 */  bne        $a1, $t0, .L8008A5F8
    /* 7ADA0 8008A5A0 0100B124 */   addiu     $s1, $a1, 0x1
    /* 7ADA4 8008A5A4 1080023C */  lui        $v0, %hi(D_800FE278)
    /* 7ADA8 8008A5A8 78E2428C */  lw         $v0, %lo(D_800FE278)($v0)
    /* 7ADAC 8008A5AC 00000000 */  nop
    /* 7ADB0 8008A5B0 2400438C */  lw         $v1, 0x24($v0)
    /* 7ADB4 8008A5B4 2800448C */  lw         $a0, 0x28($v0)
    /* 7ADB8 8008A5B8 2C00458C */  lw         $a1, 0x2C($v0)
    /* 7ADBC 8008A5BC 3000468C */  lw         $a2, 0x30($v0)
    /* 7ADC0 8008A5C0 000043AE */  sw         $v1, 0x0($s2)
    /* 7ADC4 8008A5C4 040044AE */  sw         $a0, 0x4($s2)
    /* 7ADC8 8008A5C8 080045AE */  sw         $a1, 0x8($s2)
    /* 7ADCC 8008A5CC 0C0046AE */  sw         $a2, 0xC($s2)
    /* 7ADD0 8008A5D0 3400438C */  lw         $v1, 0x34($v0)
    /* 7ADD4 8008A5D4 3800448C */  lw         $a0, 0x38($v0)
    /* 7ADD8 8008A5D8 3C00458C */  lw         $a1, 0x3C($v0)
    /* 7ADDC 8008A5DC 4000468C */  lw         $a2, 0x40($v0)
    /* 7ADE0 8008A5E0 100043AE */  sw         $v1, 0x10($s2)
    /* 7ADE4 8008A5E4 140044AE */  sw         $a0, 0x14($s2)
    /* 7ADE8 8008A5E8 180045AE */  sw         $a1, 0x18($s2)
    /* 7ADEC 8008A5EC 1C0046AE */  sw         $a2, 0x1C($s2)
    /* 7ADF0 8008A5F0 AF290208 */  j          .L8008A6BC
    /* 7ADF4 8008A5F4 21880000 */   addu      $s1, $zero, $zero
  .L8008A5F8:
    /* 7ADF8 8008A5F8 80101100 */  sll        $v0, $s1, 2
    /* 7ADFC 8008A5FC 21104600 */  addu       $v0, $v0, $a2
    /* 7AE00 8008A600 0000428C */  lw         $v0, 0x0($v0)
    /* 7AE04 8008A604 00000000 */  nop
    /* 7AE08 8008A608 2400438C */  lw         $v1, 0x24($v0)
    /* 7AE0C 8008A60C 2800448C */  lw         $a0, 0x28($v0)
    /* 7AE10 8008A610 2C00458C */  lw         $a1, 0x2C($v0)
    /* 7AE14 8008A614 3000468C */  lw         $a2, 0x30($v0)
    /* 7AE18 8008A618 000043AE */  sw         $v1, 0x0($s2)
    /* 7AE1C 8008A61C 040044AE */  sw         $a0, 0x4($s2)
    /* 7AE20 8008A620 080045AE */  sw         $a1, 0x8($s2)
    /* 7AE24 8008A624 0C0046AE */  sw         $a2, 0xC($s2)
    /* 7AE28 8008A628 3400438C */  lw         $v1, 0x34($v0)
    /* 7AE2C 8008A62C 3800448C */  lw         $a0, 0x38($v0)
    /* 7AE30 8008A630 3C00458C */  lw         $a1, 0x3C($v0)
    /* 7AE34 8008A634 4000468C */  lw         $a2, 0x40($v0)
    /* 7AE38 8008A638 100043AE */  sw         $v1, 0x10($s2)
    /* 7AE3C 8008A63C 140044AE */  sw         $a0, 0x14($s2)
    /* 7AE40 8008A640 180045AE */  sw         $a1, 0x18($s2)
    /* 7AE44 8008A644 AF290208 */  j          .L8008A6BC
    /* 7AE48 8008A648 1C0046AE */   sw        $a2, 0x1C($s2)
  .L8008A64C:
    /* 7AE4C 8008A64C 0000E38C */  lw         $v1, 0x0($a3)
    /* 7AE50 8008A650 1080023C */  lui        $v0, %hi(D_800FE0C8)
    /* 7AE54 8008A654 C8E0428C */  lw         $v0, %lo(D_800FE0C8)($v0)
    /* 7AE58 8008A658 00000000 */  nop
    /* 7AE5C 8008A65C 12006214 */  bne        $v1, $v0, .L8008A6A8
    /* 7AE60 8008A660 00000000 */   nop
    /* 7AE64 8008A664 2400E28C */  lw         $v0, 0x24($a3)
    /* 7AE68 8008A668 2800E38C */  lw         $v1, 0x28($a3)
    /* 7AE6C 8008A66C 2C00E48C */  lw         $a0, 0x2C($a3)
    /* 7AE70 8008A670 3000E58C */  lw         $a1, 0x30($a3)
    /* 7AE74 8008A674 000042AE */  sw         $v0, 0x0($s2)
    /* 7AE78 8008A678 040043AE */  sw         $v1, 0x4($s2)
    /* 7AE7C 8008A67C 080044AE */  sw         $a0, 0x8($s2)
    /* 7AE80 8008A680 0C0045AE */  sw         $a1, 0xC($s2)
    /* 7AE84 8008A684 3400E28C */  lw         $v0, 0x34($a3)
    /* 7AE88 8008A688 3800E38C */  lw         $v1, 0x38($a3)
    /* 7AE8C 8008A68C 3C00E48C */  lw         $a0, 0x3C($a3)
    /* 7AE90 8008A690 4000E58C */  lw         $a1, 0x40($a3)
    /* 7AE94 8008A694 100042AE */  sw         $v0, 0x10($s2)
    /* 7AE98 8008A698 140043AE */  sw         $v1, 0x14($s2)
    /* 7AE9C 8008A69C 180044AE */  sw         $a0, 0x18($s2)
    /* 7AEA0 8008A6A0 AF290208 */  j          .L8008A6BC
    /* 7AEA4 8008A6A4 1C0045AE */   sw        $a1, 0x1C($s2)
  .L8008A6A8:
    /* 7AEA8 8008A6A8 02006014 */  bnez       $v1, .L8008A6B4
    /* 7AEAC 8008A6AC 21388000 */   addu      $a3, $a0, $zero
    /* 7AEB0 8008A6B0 21282002 */  addu       $a1, $s1, $zero
  .L8008A6B4:
    /* 7AEB4 8008A6B4 34290208 */  j          .L8008A4D0
    /* 7AEB8 8008A6B8 01003126 */   addiu     $s1, $s1, 0x1
  .L8008A6BC:
    /* 7AEBC 8008A6BC 2000201A */  blez       $s1, .L8008A740
    /* 7AEC0 8008A6C0 80101100 */   sll       $v0, $s1, 2
    /* 7AEC4 8008A6C4 1080033C */  lui        $v1, %hi(D_800FE274)
    /* 7AEC8 8008A6C8 74E26324 */  addiu      $v1, $v1, %lo(D_800FE274)
    /* 7AECC 8008A6CC 21804300 */  addu       $s0, $v0, $v1
  .L8008A6D0:
    /* 7AED0 8008A6D0 0000058E */  lw         $a1, 0x0($s0)
    /* 7AED4 8008A6D4 21204002 */  addu       $a0, $s2, $zero
    /* 7AED8 8008A6D8 8819020C */  jal        func_80086620
    /* 7AEDC 8008A6DC 0400A524 */   addiu     $a1, $a1, 0x4
    /* 7AEE0 8008A6E0 0000028E */  lw         $v0, 0x0($s0)
    /* 7AEE4 8008A6E4 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 7AEE8 8008A6E8 0000438E */  lw         $v1, 0x0($s2)
    /* 7AEEC 8008A6EC 0400448E */  lw         $a0, 0x4($s2)
    /* 7AEF0 8008A6F0 0800458E */  lw         $a1, 0x8($s2)
    /* 7AEF4 8008A6F4 0C00468E */  lw         $a2, 0xC($s2)
    /* 7AEF8 8008A6F8 240043AC */  sw         $v1, 0x24($v0)
    /* 7AEFC 8008A6FC 280044AC */  sw         $a0, 0x28($v0)
    /* 7AF00 8008A700 2C0045AC */  sw         $a1, 0x2C($v0)
    /* 7AF04 8008A704 300046AC */  sw         $a2, 0x30($v0)
    /* 7AF08 8008A708 1000438E */  lw         $v1, 0x10($s2)
    /* 7AF0C 8008A70C 1400448E */  lw         $a0, 0x14($s2)
    /* 7AF10 8008A710 1800458E */  lw         $a1, 0x18($s2)
    /* 7AF14 8008A714 1C00468E */  lw         $a2, 0x1C($s2)
    /* 7AF18 8008A718 340043AC */  sw         $v1, 0x34($v0)
    /* 7AF1C 8008A71C 380044AC */  sw         $a0, 0x38($v0)
    /* 7AF20 8008A720 3C0045AC */  sw         $a1, 0x3C($v0)
    /* 7AF24 8008A724 400046AC */  sw         $a2, 0x40($v0)
    /* 7AF28 8008A728 0000038E */  lw         $v1, 0x0($s0)
    /* 7AF2C 8008A72C 1080023C */  lui        $v0, %hi(D_800FE0C8)
    /* 7AF30 8008A730 C8E0428C */  lw         $v0, %lo(D_800FE0C8)($v0)
    /* 7AF34 8008A734 FCFF1026 */  addiu      $s0, $s0, -0x4
    /* 7AF38 8008A738 E5FF201E */  bgtz       $s1, .L8008A6D0
    /* 7AF3C 8008A73C 000062AC */   sw        $v0, 0x0($v1)
  .L8008A740:
    /* 7AF40 8008A740 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 7AF44 8008A744 1800B28F */  lw         $s2, 0x18($sp)
    /* 7AF48 8008A748 1400B18F */  lw         $s1, 0x14($sp)
    /* 7AF4C 8008A74C 1000B08F */  lw         $s0, 0x10($sp)
    /* 7AF50 8008A750 0800E003 */  jr         $ra
    /* 7AF54 8008A754 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008A4A0
    /* 7AF58 8008A758 00000000 */  nop
    /* 7AF5C 8008A75C 00000000 */  nop
