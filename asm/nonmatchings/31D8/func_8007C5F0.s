nonmatching func_8007C5F0, 0x1E4

glabel func_8007C5F0
    /* 6CDF0 8007C5F0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6CDF4 8007C5F4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6CDF8 8007C5F8 21388000 */  addu       $a3, $a0, $zero
    /* 6CDFC 8007C5FC FF00E230 */  andi       $v0, $a3, 0xFF
    /* 6CE00 8007C600 02000624 */  addiu      $a2, $zero, 0x2
    /* 6CE04 8007C604 53004614 */  bne        $v0, $a2, .L8007C754
    /* 6CE08 8007C608 2140A000 */   addu      $t0, $a1, $zero
    /* 6CE0C 8007C60C 0980043C */  lui        $a0, %hi(D_80093884)
    /* 6CE10 8007C610 84388424 */  addiu      $a0, $a0, %lo(D_80093884)
    /* 6CE14 8007C614 00008590 */  lbu        $a1, 0x0($a0)
    /* 6CE18 8007C618 0E000224 */  addiu      $v0, $zero, 0xE
    /* 6CE1C 8007C61C FF00A330 */  andi       $v1, $a1, 0xFF
    /* 6CE20 8007C620 16006214 */  bne        $v1, $v0, .L8007C67C
    /* 6CE24 8007C624 03000224 */   addiu     $v0, $zero, 0x3
    /* 6CE28 8007C628 29008290 */  lbu        $v0, 0x29($a0)
    /* 6CE2C 8007C62C 01008390 */  lbu        $v1, 0x1($a0)
    /* 6CE30 8007C630 00000000 */  nop
    /* 6CE34 8007C634 26104300 */  xor        $v0, $v0, $v1
    /* 6CE38 8007C638 80004230 */  andi       $v0, $v0, 0x80
    /* 6CE3C 8007C63C 06004010 */  beqz       $v0, .L8007C658
    /* 6CE40 8007C640 0F000224 */   addiu     $v0, $zero, 0xF
    /* 6CE44 8007C644 200082AC */  sw         $v0, 0x20($a0)
    /* 6CE48 8007C648 03000224 */  addiu      $v0, $zero, 0x3
    /* 6CE4C 8007C64C 1C0086AC */  sw         $a2, 0x1C($a0)
    /* 6CE50 8007C650 9AF10108 */  j          .L8007C668
    /* 6CE54 8007C654 3C0082AC */   sw        $v0, 0x3C($a0)
  .L8007C658:
    /* 6CE58 8007C658 01000224 */  addiu      $v0, $zero, 0x1
    /* 6CE5C 8007C65C 1C0082AC */  sw         $v0, 0x1C($a0)
    /* 6CE60 8007C660 0B000224 */  addiu      $v0, $zero, 0xB
    /* 6CE64 8007C664 200082AC */  sw         $v0, 0x20($a0)
  .L8007C668:
    /* 6CE68 8007C668 0980033C */  lui        $v1, %hi(D_800938AD)
    /* 6CE6C 8007C66C AD386324 */  addiu      $v1, $v1, %lo(D_800938AD)
    /* 6CE70 8007C670 D8FF6290 */  lbu        $v0, -0x28($v1)
    /* 6CE74 8007C674 E2F10108 */  j          .L8007C788
    /* 6CE78 8007C678 000062A0 */   sb        $v0, 0x0($v1)
  .L8007C67C:
    /* 6CE7C 8007C67C 03006214 */  bne        $v1, $v0, .L8007C68C
    /* 6CE80 8007C680 06000224 */   addiu     $v0, $zero, 0x6
    /* 6CE84 8007C684 A8F10108 */  j          .L8007C6A0
    /* 6CE88 8007C688 10000224 */   addiu     $v0, $zero, 0x10
  .L8007C68C:
    /* 6CE8C 8007C68C 03006210 */  beq        $v1, $v0, .L8007C69C
    /* 6CE90 8007C690 1B000224 */   addiu     $v0, $zero, 0x1B
    /* 6CE94 8007C694 08006214 */  bne        $v1, $v0, .L8007C6B8
    /* 6CE98 8007C698 00000000 */   nop
  .L8007C69C:
    /* 6CE9C 8007C69C 11000224 */  addiu      $v0, $zero, 0x11
  .L8007C6A0:
    /* 6CEA0 8007C6A0 200082AC */  sw         $v0, 0x20($a0)
    /* 6CEA4 8007C6A4 B0040224 */  addiu      $v0, $zero, 0x4B0
    /* 6CEA8 8007C6A8 1C0086AC */  sw         $a2, 0x1C($a0)
    /* 6CEAC 8007C6AC 2F0085A0 */  sb         $a1, 0x2F($a0)
    /* 6CEB0 8007C6B0 E2F10108 */  j          .L8007C788
    /* 6CEB4 8007C6B4 480082AC */   sw        $v0, 0x48($a0)
  .L8007C6B8:
    /* 6CEB8 8007C6B8 00008290 */  lbu        $v0, 0x0($a0)
    /* 6CEBC 8007C6BC 00000000 */  nop
    /* 6CEC0 8007C6C0 FEFF4324 */  addiu      $v1, $v0, -0x2
    /* 6CEC4 8007C6C4 1A00622C */  sltiu      $v0, $v1, 0x1A
    /* 6CEC8 8007C6C8 1B004010 */  beqz       $v0, .L8007C738
    /* 6CECC 8007C6CC 80100300 */   sll       $v0, $v1, 2
    /* 6CED0 8007C6D0 0180013C */  lui        $at, %hi(jtbl_80011E48)
    /* 6CED4 8007C6D4 21082200 */  addu       $at, $at, $v0
    /* 6CED8 8007C6D8 481E228C */  lw         $v0, %lo(jtbl_80011E48)($at)
    /* 6CEDC 8007C6DC 00000000 */  nop
    /* 6CEE0 8007C6E0 08004000 */  jr         $v0
    /* 6CEE4 8007C6E4 00000000 */   nop
  jlabel .L8007C6E8
    /* 6CEE8 8007C6E8 0980053C */  lui        $a1, %hi(D_80093884 + 0x1)
    /* 6CEEC 8007C6EC 8538A524 */  addiu      $a1, $a1, %lo(D_80093884 + 0x1)
    /* 6CEF0 8007C6F0 0980043C */  lui        $a0, %hi(D_800938AE)
    /* 6CEF4 8007C6F4 AE388424 */  addiu      $a0, $a0, %lo(D_800938AE)
    /* 6CEF8 8007C6F8 0300A288 */  lwl        $v0, 0x3($a1)
    /* 6CEFC 8007C6FC 0000A298 */  lwr        $v0, 0x0($a1)
    /* 6CF00 8007C700 00000000 */  nop
    /* 6CF04 8007C704 030082A8 */  swl        $v0, 0x3($a0)
    /* 6CF08 8007C708 CEF10108 */  j          .L8007C738
    /* 6CF0C 8007C70C 000082B8 */   swr       $v0, 0x0($a0)
  jlabel .L8007C710
    /* 6CF10 8007C710 0980033C */  lui        $v1, %hi(D_800938B2)
    /* 6CF14 8007C714 B2386324 */  addiu      $v1, $v1, %lo(D_800938B2)
    /* 6CF18 8007C718 D2FF6290 */  lbu        $v0, -0x2E($v1)
    /* 6CF1C 8007C71C CEF10108 */  j          .L8007C738
    /* 6CF20 8007C720 000062A0 */   sb        $v0, 0x0($v1)
  jlabel .L8007C724
    /* 6CF24 8007C724 0980033C */  lui        $v1, %hi(D_800938B3)
    /* 6CF28 8007C728 B3386324 */  addiu      $v1, $v1, %lo(D_800938B3)
    /* 6CF2C 8007C72C D1FF6290 */  lbu        $v0, -0x2F($v1)
    /* 6CF30 8007C730 00000000 */  nop
    /* 6CF34 8007C734 000062A0 */  sb         $v0, 0x0($v1)
  jlabel .L8007C738
    /* 6CF38 8007C738 0980023C */  lui        $v0, %hi(D_800938A0)
    /* 6CF3C 8007C73C A0384224 */  addiu      $v0, $v0, %lo(D_800938A0)
    /* 6CF40 8007C740 01000324 */  addiu      $v1, $zero, 0x1
    /* 6CF44 8007C744 000043AC */  sw         $v1, 0x0($v0)
    /* 6CF48 8007C748 0B000324 */  addiu      $v1, $zero, 0xB
    /* 6CF4C 8007C74C E2F10108 */  j          .L8007C788
    /* 6CF50 8007C750 040043AC */   sw        $v1, 0x4($v0)
  .L8007C754:
    /* 6CF54 8007C754 0980033C */  lui        $v1, %hi(D_80093898)
    /* 6CF58 8007C758 98386324 */  addiu      $v1, $v1, %lo(D_80093898)
    /* 6CF5C 8007C75C 00006290 */  lbu        $v0, 0x0($v1)
    /* 6CF60 8007C760 00000000 */  nop
    /* 6CF64 8007C764 10004230 */  andi       $v0, $v0, 0x10
    /* 6CF68 8007C768 03004010 */  beqz       $v0, .L8007C778
    /* 6CF6C 8007C76C 0C000224 */   addiu     $v0, $zero, 0xC
    /* 6CF70 8007C770 E1F10108 */  j          .L8007C784
    /* 6CF74 8007C774 080066AC */   sw        $a2, 0x8($v1)
  .L8007C778:
    /* 6CF78 8007C778 01000224 */  addiu      $v0, $zero, 0x1
    /* 6CF7C 8007C77C 080062AC */  sw         $v0, 0x8($v1)
    /* 6CF80 8007C780 0B000224 */  addiu      $v0, $zero, 0xB
  .L8007C784:
    /* 6CF84 8007C784 0C0062AC */  sw         $v0, 0xC($v1)
  .L8007C788:
    /* 6CF88 8007C788 0F80023C */  lui        $v0, %hi(D_800F5F84)
    /* 6CF8C 8007C78C 845F428C */  lw         $v0, %lo(D_800F5F84)($v0)
    /* 6CF90 8007C790 00000000 */  nop
    /* 6CF94 8007C794 0B004010 */  beqz       $v0, .L8007C7C4
    /* 6CF98 8007C798 00000000 */   nop
    /* 6CF9C 8007C79C 0980023C */  lui        $v0, %hi(D_80093880)
    /* 6CFA0 8007C7A0 8038428C */  lw         $v0, %lo(D_80093880)($v0)
    /* 6CFA4 8007C7A4 00000000 */  nop
    /* 6CFA8 8007C7A8 06004010 */  beqz       $v0, .L8007C7C4
    /* 6CFAC 8007C7AC 00000000 */   nop
    /* 6CFB0 8007C7B0 0F80023C */  lui        $v0, %hi(D_800F5F84)
    /* 6CFB4 8007C7B4 845F428C */  lw         $v0, %lo(D_800F5F84)($v0)
    /* 6CFB8 8007C7B8 FF00E430 */  andi       $a0, $a3, 0xFF
    /* 6CFBC 8007C7BC 09F84000 */  jalr       $v0
    /* 6CFC0 8007C7C0 21280001 */   addu      $a1, $t0, $zero
  .L8007C7C4:
    /* 6CFC4 8007C7C4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6CFC8 8007C7C8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6CFCC 8007C7CC 0800E003 */  jr         $ra
    /* 6CFD0 8007C7D0 00000000 */   nop
endlabel func_8007C5F0
