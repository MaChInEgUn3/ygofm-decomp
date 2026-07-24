nonmatching func_8003C628, 0x178

glabel func_8003C628
    /* 2CE28 8003C628 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 2CE2C 8003C62C 3400BFAF */  sw         $ra, 0x34($sp)
    /* 2CE30 8003C630 3000B2AF */  sw         $s2, 0x30($sp)
    /* 2CE34 8003C634 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 2CE38 8003C638 0B00010C */  jal        func_8004002C
    /* 2CE3C 8003C63C 2800B0AF */   sw        $s0, 0x28($sp)
    /* 2CE40 8003C640 21204000 */  addu       $a0, $v0, $zero
    /* 2CE44 8003C644 2B00010C */  jal        func_800400AC
    /* 2CE48 8003C648 02000524 */   addiu     $a1, $zero, 0x2
    /* 2CE4C 8003C64C 21884000 */  addu       $s1, $v0, $zero
    /* 2CE50 8003C650 21202002 */  addu       $a0, $s1, $zero
    /* 2CE54 8003C654 21280000 */  addu       $a1, $zero, $zero
    /* 2CE58 8003C658 2130A000 */  addu       $a2, $a1, $zero
    /* 2CE5C 8003C65C 2138A000 */  addu       $a3, $a1, $zero
    /* 2CE60 8003C660 10001224 */  addiu      $s2, $zero, 0x10
    /* 2CE64 8003C664 00010224 */  addiu      $v0, $zero, 0x100
    /* 2CE68 8003C668 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 2CE6C 8003C66C 1B80023C */  lui        $v0, %hi(D_801AF000)
    /* 2CE70 8003C670 00F04224 */  addiu      $v0, $v0, %lo(D_801AF000)
    /* 2CE74 8003C674 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2CE78 8003C678 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2CE7C 8003C67C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2CE80 8003C680 2A0A010C */  jal        func_800428A8
    /* 2CE84 8003C684 2000A2AF */   sw        $v0, 0x20($sp)
    /* 2CE88 8003C688 21202002 */  addu       $a0, $s1, $zero
    /* 2CE8C 8003C68C 3B0A010C */  jal        func_800428EC
    /* 2CE90 8003C690 FBFF0524 */   addiu     $a1, $zero, -0x5
    /* 2CE94 8003C694 01000224 */  addiu      $v0, $zero, 0x1
    /* 2CE98 8003C698 740482A3 */  sb         $v0, %gp_rel(D_8009B37C)($gp)
    /* 2CE9C 8003C69C 08002296 */  lhu        $v0, 0x8($s1)
    /* 2CEA0 8003C6A0 0A80033C */  lui        $v1, %hi(D_8009B408)
    /* 2CEA4 8003C6A4 08B46390 */  lbu        $v1, %lo(D_8009B408)($v1)
    /* 2CEA8 8003C6A8 28004234 */  ori        $v0, $v0, 0x28
    /* 2CEAC 8003C6AC 750483A3 */  sb         $v1, %gp_rel(D_8009B37D)($gp)
    /* 2CEB0 8003C6B0 001E0300 */  sll        $v1, $v1, 24
    /* 2CEB4 8003C6B4 02006104 */  bgez       $v1, .L8003C6C0
    /* 2CEB8 8003C6B8 080022A6 */   sh        $v0, 0x8($s1)
    /* 2CEBC 8003C6BC 750480A3 */  sb         $zero, %gp_rel(D_8009B37D)($gp)
  .L8003C6C0:
    /* 2CEC0 8003C6C0 7C0480A3 */  sb         $zero, %gp_rel(D_8009B384)($gp)
    /* 2CEC4 8003C6C4 38F1000C */  jal        func_8003C4E0
    /* 2CEC8 8003C6C8 21200000 */   addu      $a0, $zero, $zero
    /* 2CECC 8003C6CC 0B00010C */  jal        func_8004002C
    /* 2CED0 8003C6D0 0B001024 */   addiu     $s0, $zero, 0xB
    /* 2CED4 8003C6D4 21204000 */  addu       $a0, $v0, $zero
    /* 2CED8 8003C6D8 2B00010C */  jal        func_800400AC
    /* 2CEDC 8003C6DC 02000524 */   addiu     $a1, $zero, 0x2
    /* 2CEE0 8003C6E0 21884000 */  addu       $s1, $v0, $zero
    /* 2CEE4 8003C6E4 21202002 */  addu       $a0, $s1, $zero
    /* 2CEE8 8003C6E8 18000524 */  addiu      $a1, $zero, 0x18
    /* 2CEEC 8003C6EC 48000624 */  addiu      $a2, $zero, 0x48
    /* 2CEF0 8003C6F0 03000724 */  addiu      $a3, $zero, 0x3
    /* 2CEF4 8003C6F4 04000224 */  addiu      $v0, $zero, 0x4
    /* 2CEF8 8003C6F8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2CEFC 8003C6FC 0C020224 */  addiu      $v0, $zero, 0x20C
    /* 2CF00 8003C700 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2CF04 8003C704 1800B0AF */  sw         $s0, 0x18($sp)
    /* 2CF08 8003C708 3301010C */  jal        func_800404CC
    /* 2CF0C 8003C70C 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* 2CF10 8003C710 08002296 */  lhu        $v0, 0x8($s1)
    /* 2CF14 8003C714 800491AF */  sw         $s1, %gp_rel(D_8009B388)($gp)
    /* 2CF18 8003C718 28004234 */  ori        $v0, $v0, 0x28
    /* 2CF1C 8003C71C 0B00010C */  jal        func_8004002C
    /* 2CF20 8003C720 080022A6 */   sh        $v0, 0x8($s1)
    /* 2CF24 8003C724 21204000 */  addu       $a0, $v0, $zero
    /* 2CF28 8003C728 2B00010C */  jal        func_800400AC
    /* 2CF2C 8003C72C 01000524 */   addiu     $a1, $zero, 0x1
    /* 2CF30 8003C730 21884000 */  addu       $s1, $v0, $zero
    /* 2CF34 8003C734 21202002 */  addu       $a0, $s1, $zero
    /* 2CF38 8003C738 68000524 */  addiu      $a1, $zero, 0x68
    /* 2CF3C 8003C73C 48000624 */  addiu      $a2, $zero, 0x48
    /* 2CF40 8003C740 10000724 */  addiu      $a3, $zero, 0x10
    /* 2CF44 8003C744 50000224 */  addiu      $v0, $zero, 0x50
    /* 2CF48 8003C748 1400A2AF */  sw         $v0, 0x14($sp)
    /* 2CF4C 8003C74C 80000224 */  addiu      $v0, $zero, 0x80
    /* 2CF50 8003C750 1800A2AF */  sw         $v0, 0x18($sp)
    /* 2CF54 8003C754 10020224 */  addiu      $v0, $zero, 0x210
    /* 2CF58 8003C758 2000A2AF */  sw         $v0, 0x20($sp)
    /* 2CF5C 8003C75C FC000224 */  addiu      $v0, $zero, 0xFC
    /* 2CF60 8003C760 1000B2AF */  sw         $s2, 0x10($sp)
    /* 2CF64 8003C764 1C00B0AF */  sw         $s0, 0x1C($sp)
    /* 2CF68 8003C768 4401010C */  jal        func_80040510
    /* 2CF6C 8003C76C 2400A2AF */   sw        $v0, 0x24($sp)
    /* 2CF70 8003C770 7C048483 */  lb         $a0, %gp_rel(D_8009B384)($gp)
    /* 2CF74 8003C774 780491AF */  sw         $s1, %gp_rel(D_8009B380)($gp)
    /* 2CF78 8003C778 5AF1000C */  jal        func_8003C568
    /* 2CF7C 8003C77C 00000000 */   nop
    /* 2CF80 8003C780 C2FF000C */  jal        func_8003FF08
    /* 2CF84 8003C784 50730424 */   addiu     $a0, $zero, 0x7350
    /* 2CF88 8003C788 3400BF8F */  lw         $ra, 0x34($sp)
    /* 2CF8C 8003C78C 3000B28F */  lw         $s2, 0x30($sp)
    /* 2CF90 8003C790 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 2CF94 8003C794 2800B08F */  lw         $s0, 0x28($sp)
    /* 2CF98 8003C798 0800E003 */  jr         $ra
    /* 2CF9C 8003C79C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8003C628
