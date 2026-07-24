nonmatching func_8002E5AC, 0x10C

glabel func_8002E5AC
    /* 1EDAC 8002E5AC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1EDB0 8002E5B0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 1EDB4 8002E5B4 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1EDB8 8002E5B8 EDB8000C */  jal        func_8002E3B4
    /* 1EDBC 8002E5BC 1800B0AF */   sw        $s0, 0x18($sp)
    /* 1EDC0 8002E5C0 29004014 */  bnez       $v0, .L8002E668
    /* 1EDC4 8002E5C4 21200000 */   addu      $a0, $zero, $zero
    /* 1EDC8 8002E5C8 8803838F */  lw         $v1, %gp_rel(D_8009B290)($gp)
    /* 1EDCC 8002E5CC 02000524 */  addiu      $a1, $zero, 0x2
    /* 1EDD0 8002E5D0 21106500 */  addu       $v0, $v1, $a1
    /* 1EDD4 8002E5D4 880382AF */  sw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1EDD8 8002E5D8 00007090 */  lbu        $s0, 0x0($v1)
    /* 1EDDC 8002E5DC 9C038297 */  lhu        $v0, %gp_rel(D_8009B2A4)($gp)
    /* 1EDE0 8002E5E0 01006390 */  lbu        $v1, 0x1($v1)
    /* 1EDE4 8002E5E4 00404234 */  ori        $v0, $v0, 0x4000
    /* 1EDE8 8002E5E8 001A0300 */  sll        $v1, $v1, 8
    /* 1EDEC 8002E5EC 9C0382A7 */  sh         $v0, %gp_rel(D_8009B2A4)($gp)
    /* 1EDF0 8002E5F0 ABED000C */  jal        func_8003B6AC
    /* 1EDF4 8002E5F4 25800302 */   or        $s0, $s0, $v1
    /* 1EDF8 8002E5F8 21200000 */  addu       $a0, $zero, $zero
    /* 1EDFC 8002E5FC FF0F0532 */  andi       $a1, $s0, 0xFFF
    /* 1EE00 8002E600 20010224 */  addiu      $v0, $zero, 0x120
    /* 1EE04 8002E604 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1EE08 8002E608 30000224 */  addiu      $v0, $zero, 0x30
    /* 1EE0C 8002E60C 10000624 */  addiu      $a2, $zero, 0x10
    /* 1EE10 8002E610 B0000724 */  addiu      $a3, $zero, 0xB0
    /* 1EE14 8002E614 F9D6000C */  jal        func_80035BE4
    /* 1EE18 8002E618 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1EE1C 8002E61C 21884000 */  addu       $s1, $v0, $zero
    /* 1EE20 8002E620 DCB8000C */  jal        func_8002E370
    /* 1EE24 8002E624 21202002 */   addu      $a0, $s1, $zero
    /* 1EE28 8002E628 34002296 */  lhu        $v0, 0x34($s1)
    /* 1EE2C 8002E62C 00801032 */  andi       $s0, $s0, 0x8000
    /* 1EE30 8002E630 08004234 */  ori        $v0, $v0, 0x8
    /* 1EE34 8002E634 07000012 */  beqz       $s0, .L8002E654
    /* 1EE38 8002E638 340022A6 */   sh        $v0, 0x34($s1)
    /* 1EE3C 8002E63C 74038297 */  lhu        $v0, %gp_rel(D_8009B27C)($gp)
    /* 1EE40 8002E640 34002396 */  lhu        $v1, 0x34($s1)
    /* 1EE44 8002E644 00404234 */  ori        $v0, $v0, 0x4000
    /* 1EE48 8002E648 F7FF6330 */  andi       $v1, $v1, 0xFFF7
    /* 1EE4C 8002E64C 740382A7 */  sh         $v0, %gp_rel(D_8009B27C)($gp)
    /* 1EE50 8002E650 340023A6 */  sh         $v1, 0x34($s1)
  .L8002E654:
    /* 1EE54 8002E654 74038297 */  lhu        $v0, %gp_rel(D_8009B27C)($gp)
    /* 1EE58 8002E658 00000000 */  nop
    /* 1EE5C 8002E65C 840382A7 */  sh         $v0, %gp_rel(D_8009B28C)($gp)
    /* 1EE60 8002E660 A9B90008 */  j          .L8002E6A4
    /* 1EE64 8002E664 00000000 */   nop
  .L8002E668:
    /* 1EE68 8002E668 9C038297 */  lhu        $v0, %gp_rel(D_8009B2A4)($gp)
    /* 1EE6C 8002E66C 00000000 */  nop
    /* 1EE70 8002E670 00404230 */  andi       $v0, $v0, 0x4000
    /* 1EE74 8002E674 0B004014 */  bnez       $v0, .L8002E6A4
    /* 1EE78 8002E678 00000000 */   nop
    /* 1EE7C 8002E67C 74038297 */  lhu        $v0, %gp_rel(D_8009B27C)($gp)
    /* 1EE80 8002E680 00000000 */  nop
    /* 1EE84 8002E684 00404230 */  andi       $v0, $v0, 0x4000
    /* 1EE88 8002E688 04004014 */  bnez       $v0, .L8002E69C
    /* 1EE8C 8002E68C 00000000 */   nop
    /* 1EE90 8002E690 0F80043C */  lui        $a0, %hi(D_800EB0F8)
    /* 1EE94 8002E694 DFD6000C */  jal        func_80035B7C
    /* 1EE98 8002E698 F8B08424 */   addiu     $a0, $a0, %lo(D_800EB0F8)
  .L8002E69C:
    /* 1EE9C 8002E69C 840380A7 */  sh         $zero, %gp_rel(D_8009B28C)($gp)
    /* 1EEA0 8002E6A0 740380A7 */  sh         $zero, %gp_rel(D_8009B27C)($gp)
  .L8002E6A4:
    /* 1EEA4 8002E6A4 2000BF8F */  lw         $ra, 0x20($sp)
    /* 1EEA8 8002E6A8 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1EEAC 8002E6AC 1800B08F */  lw         $s0, 0x18($sp)
    /* 1EEB0 8002E6B0 0800E003 */  jr         $ra
    /* 1EEB4 8002E6B4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8002E5AC
