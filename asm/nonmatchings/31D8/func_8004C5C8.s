nonmatching func_8004C5C8, 0x1B4

glabel func_8004C5C8
    /* 3CDC8 8004C5C8 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3CDCC 8004C5CC 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3CDD0 8004C5D0 00000000 */  nop
    /* 3CDD4 8004C5D4 FC074394 */  lhu        $v1, 0x7FC($v0)
    /* 3CDD8 8004C5D8 20010224 */  addiu      $v0, $zero, 0x120
    /* 3CDDC 8004C5DC 49006210 */  beq        $v1, $v0, .L8004C704
    /* 3CDE0 8004C5E0 21288000 */   addu      $a1, $a0, $zero
    /* 3CDE4 8004C5E4 21016228 */  slti       $v0, $v1, 0x121
    /* 3CDE8 8004C5E8 10004010 */  beqz       $v0, .L8004C62C
    /* 3CDEC 8004C5EC 60000224 */   addiu     $v0, $zero, 0x60
    /* 3CDF0 8004C5F0 2E006210 */  beq        $v1, $v0, .L8004C6AC
    /* 3CDF4 8004C5F4 61006228 */   slti      $v0, $v1, 0x61
    /* 3CDF8 8004C5F8 05004010 */  beqz       $v0, .L8004C610
    /* 3CDFC 8004C5FC 30000224 */   addiu     $v0, $zero, 0x30
    /* 3CE00 8004C600 1C006210 */  beq        $v1, $v0, .L8004C674
    /* 3CE04 8004C604 00000000 */   nop
    /* 3CE08 8004C608 0800E003 */  jr         $ra
    /* 3CE0C 8004C60C 00000000 */   nop
  .L8004C610:
    /* 3CE10 8004C610 C0000224 */  addiu      $v0, $zero, 0xC0
    /* 3CE14 8004C614 31006210 */  beq        $v1, $v0, .L8004C6DC
    /* 3CE18 8004C618 F0000224 */   addiu     $v0, $zero, 0xF0
    /* 3CE1C 8004C61C 2F006210 */  beq        $v1, $v0, .L8004C6DC
    /* 3CE20 8004C620 00000000 */   nop
    /* 3CE24 8004C624 0800E003 */  jr         $ra
    /* 3CE28 8004C628 00000000 */   nop
  .L8004C62C:
    /* 3CE2C 8004C62C E0010224 */  addiu      $v0, $zero, 0x1E0
    /* 3CE30 8004C630 3C006210 */  beq        $v1, $v0, .L8004C724
    /* 3CE34 8004C634 E1016228 */   slti      $v0, $v1, 0x1E1
    /* 3CE38 8004C638 07004010 */  beqz       $v0, .L8004C658
    /* 3CE3C 8004C63C 68010224 */   addiu     $v0, $zero, 0x168
    /* 3CE40 8004C640 30006210 */  beq        $v1, $v0, .L8004C704
    /* 3CE44 8004C644 80010224 */   addiu     $v0, $zero, 0x180
    /* 3CE48 8004C648 36006210 */  beq        $v1, $v0, .L8004C724
    /* 3CE4C 8004C64C 00000000 */   nop
    /* 3CE50 8004C650 0800E003 */  jr         $ra
    /* 3CE54 8004C654 00000000 */   nop
  .L8004C658:
    /* 3CE58 8004C658 00030224 */  addiu      $v0, $zero, 0x300
    /* 3CE5C 8004C65C 3B006210 */  beq        $v1, $v0, .L8004C74C
    /* 3CE60 8004C660 C0030224 */   addiu     $v0, $zero, 0x3C0
    /* 3CE64 8004C664 39006210 */  beq        $v1, $v0, .L8004C74C
    /* 3CE68 8004C668 00000000 */   nop
    /* 3CE6C 8004C66C 0800E003 */  jr         $ra
    /* 3CE70 8004C670 00000000 */   nop
  .L8004C674:
    /* 3CE74 8004C674 1C00A38C */  lw         $v1, 0x1C($a1)
    /* 3CE78 8004C678 00000000 */  nop
    /* 3CE7C 8004C67C 80100300 */  sll        $v0, $v1, 2
    /* 3CE80 8004C680 21104300 */  addu       $v0, $v0, $v1
    /* 3CE84 8004C684 1800A394 */  lhu        $v1, 0x18($a1)
    /* 3CE88 8004C688 40100200 */  sll        $v0, $v0, 1
    /* 3CE8C 8004C68C 1C00A2AC */  sw         $v0, 0x1C($a1)
    /* 3CE90 8004C690 21104300 */  addu       $v0, $v0, $v1
    /* 3CE94 8004C694 1C00A2AC */  sw         $v0, 0x1C($a1)
    /* 3CE98 8004C698 1C00A294 */  lhu        $v0, 0x1C($a1)
    /* 3CE9C 8004C69C 1C00A38C */  lw         $v1, 0x1C($a1)
    /* 3CEA0 8004C6A0 03004230 */  andi       $v0, $v0, 0x3
    /* 3CEA4 8004C6A4 DC310108 */  j          .L8004C770
    /* 3CEA8 8004C6A8 82180300 */   srl       $v1, $v1, 2
  .L8004C6AC:
    /* 3CEAC 8004C6AC 1C00A38C */  lw         $v1, 0x1C($a1)
    /* 3CEB0 8004C6B0 1800A494 */  lhu        $a0, 0x18($a1)
    /* 3CEB4 8004C6B4 80100300 */  sll        $v0, $v1, 2
    /* 3CEB8 8004C6B8 21104300 */  addu       $v0, $v0, $v1
    /* 3CEBC 8004C6BC 1C00A2AC */  sw         $v0, 0x1C($a1)
    /* 3CEC0 8004C6C0 21104400 */  addu       $v0, $v0, $a0
    /* 3CEC4 8004C6C4 1C00A2AC */  sw         $v0, 0x1C($a1)
    /* 3CEC8 8004C6C8 1C00A294 */  lhu        $v0, 0x1C($a1)
    /* 3CECC 8004C6CC 1C00A38C */  lw         $v1, 0x1C($a1)
    /* 3CED0 8004C6D0 03004230 */  andi       $v0, $v0, 0x3
    /* 3CED4 8004C6D4 DC310108 */  j          .L8004C770
    /* 3CED8 8004C6D8 82180300 */   srl       $v1, $v1, 2
  .L8004C6DC:
    /* 3CEDC 8004C6DC 1800A394 */  lhu        $v1, 0x18($a1)
    /* 3CEE0 8004C6E0 1C00A28C */  lw         $v0, 0x1C($a1)
    /* 3CEE4 8004C6E4 00000000 */  nop
    /* 3CEE8 8004C6E8 21104300 */  addu       $v0, $v0, $v1
    /* 3CEEC 8004C6EC 1C00A2AC */  sw         $v0, 0x1C($a1)
    /* 3CEF0 8004C6F0 1C00A294 */  lhu        $v0, 0x1C($a1)
    /* 3CEF4 8004C6F4 1C00A38C */  lw         $v1, 0x1C($a1)
    /* 3CEF8 8004C6F8 01004230 */  andi       $v0, $v0, 0x1
    /* 3CEFC 8004C6FC DC310108 */  j          .L8004C770
    /* 3CF00 8004C700 42180300 */   srl       $v1, $v1, 1
  .L8004C704:
    /* 3CF04 8004C704 1C00A38C */  lw         $v1, 0x1C($a1)
    /* 3CF08 8004C708 AAAA023C */  lui        $v0, (0xAAAAAAAB >> 16)
    /* 3CF0C 8004C70C ABAA4234 */  ori        $v0, $v0, (0xAAAAAAAB & 0xFFFF)
    /* 3CF10 8004C710 19006200 */  multu      $v1, $v0
    /* 3CF14 8004C714 10300000 */  mfhi       $a2
    /* 3CF18 8004C718 42100600 */  srl        $v0, $a2, 1
    /* 3CF1C 8004C71C 0800E003 */  jr         $ra
    /* 3CF20 8004C720 1C00A2AC */   sw        $v0, 0x1C($a1)
  .L8004C724:
    /* 3CF24 8004C724 1800A394 */  lhu        $v1, 0x18($a1)
    /* 3CF28 8004C728 1C00A28C */  lw         $v0, 0x1C($a1)
    /* 3CF2C 8004C72C 00000000 */  nop
    /* 3CF30 8004C730 21104300 */  addu       $v0, $v0, $v1
    /* 3CF34 8004C734 1C00A2AC */  sw         $v0, 0x1C($a1)
    /* 3CF38 8004C738 1C00A294 */  lhu        $v0, 0x1C($a1)
    /* 3CF3C 8004C73C 1C00A38C */  lw         $v1, 0x1C($a1)
    /* 3CF40 8004C740 03004230 */  andi       $v0, $v0, 0x3
    /* 3CF44 8004C744 DC310108 */  j          .L8004C770
    /* 3CF48 8004C748 82180300 */   srl       $v1, $v1, 2
  .L8004C74C:
    /* 3CF4C 8004C74C 1800A394 */  lhu        $v1, 0x18($a1)
    /* 3CF50 8004C750 1C00A28C */  lw         $v0, 0x1C($a1)
    /* 3CF54 8004C754 00000000 */  nop
    /* 3CF58 8004C758 21104300 */  addu       $v0, $v0, $v1
    /* 3CF5C 8004C75C 1C00A2AC */  sw         $v0, 0x1C($a1)
    /* 3CF60 8004C760 1C00A294 */  lhu        $v0, 0x1C($a1)
    /* 3CF64 8004C764 1C00A38C */  lw         $v1, 0x1C($a1)
    /* 3CF68 8004C768 07004230 */  andi       $v0, $v0, 0x7
    /* 3CF6C 8004C76C C2180300 */  srl        $v1, $v1, 3
  .L8004C770:
    /* 3CF70 8004C770 1800A2A4 */  sh         $v0, 0x18($a1)
    /* 3CF74 8004C774 0800E003 */  jr         $ra
    /* 3CF78 8004C778 1C00A3AC */   sw        $v1, 0x1C($a1)
endlabel func_8004C5C8
