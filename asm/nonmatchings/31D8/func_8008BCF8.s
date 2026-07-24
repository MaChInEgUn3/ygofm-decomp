nonmatching func_8008BCF8, 0x2A8

glabel func_8008BCF8
    /* 7C4F8 8008BCF8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7C4FC 8008BCFC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7C500 8008BD00 21808000 */  addu       $s0, $a0, $zero
    /* 7C504 8008BD04 1800BFAF */  sw         $ra, 0x18($sp)
    /* 7C508 8008BD08 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7C50C 8008BD0C 0000038E */  lw         $v1, 0x0($s0)
    /* 7C510 8008BD10 00000000 */  nop
    /* 7C514 8008BD14 3300622C */  sltiu      $v0, $v1, 0x33
    /* 7C518 8008BD18 9B004010 */  beqz       $v0, .L8008BF88
    /* 7C51C 8008BD1C 80100300 */   sll       $v0, $v1, 2
    /* 7C520 8008BD20 0180013C */  lui        $at, %hi(jtbl_800124A8)
    /* 7C524 8008BD24 21082200 */  addu       $at, $at, $v0
    /* 7C528 8008BD28 A824228C */  lw         $v0, %lo(jtbl_800124A8)($at)
    /* 7C52C 8008BD2C 00000000 */  nop
    /* 7C530 8008BD30 08004000 */  jr         $v0
    /* 7C534 8008BD34 00000000 */   nop
  jlabel .L8008BD38
    /* 7C538 8008BD38 1080013C */  lui        $at, %hi(D_800FE324)
    /* 7C53C 8008BD3C 24E320AC */  sw         $zero, %lo(D_800FE324)($at)
    /* 7C540 8008BD40 1080013C */  lui        $at, %hi(D_800FE328)
    /* 7C544 8008BD44 28E320AC */  sw         $zero, %lo(D_800FE328)($at)
    /* 7C548 8008BD48 1080013C */  lui        $at, %hi(D_800FE320)
    /* 7C54C 8008BD4C 20E320AC */  sw         $zero, %lo(D_800FE320)($at)
    /* 7C550 8008BD50 1080013C */  lui        $at, %hi(D_800FE330)
    /* 7C554 8008BD54 30E320AC */  sw         $zero, %lo(D_800FE330)($at)
    /* 7C558 8008BD58 1080013C */  lui        $at, %hi(D_800FE32C)
    /* 7C55C 8008BD5C 2CE320AC */  sw         $zero, %lo(D_800FE32C)($at)
    /* 7C560 8008BD60 0000028E */  lw         $v0, 0x0($s0)
    /* 7C564 8008BD64 00000000 */  nop
    /* 7C568 8008BD68 01004224 */  addiu      $v0, $v0, 0x1
    /* 7C56C 8008BD6C 000002AE */  sw         $v0, 0x0($s0)
  jlabel .L8008BD70
    /* 7C570 8008BD70 0980043C */  lui        $a0, %hi(func_8008B974)
    /* 7C574 8008BD74 3834020C */  jal        func_8008D0E0
    /* 7C578 8008BD78 74B98424 */   addiu     $a0, $a0, %lo(func_8008B974)
    /* 7C57C 8008BD7C E12F0208 */  j          .L8008BF84
    /* 7C580 8008BD80 0A000224 */   addiu     $v0, $zero, 0xA
  jlabel .L8008BD84
    /* 7C584 8008BD84 1080113C */  lui        $s1, %hi(D_800FE34C)
    /* 7C588 8008BD88 4CE33126 */  addiu      $s1, $s1, %lo(D_800FE34C)
    /* 7C58C 8008BD8C 0000238E */  lw         $v1, 0x0($s1)
    /* 7C590 8008BD90 01000524 */  addiu      $a1, $zero, 0x1
    /* 7C594 8008BD94 4B006510 */  beq        $v1, $a1, .L8008BEC4
    /* 7C598 8008BD98 02006228 */   slti      $v0, $v1, 0x2
    /* 7C59C 8008BD9C 05004010 */  beqz       $v0, .L8008BDB4
    /* 7C5A0 8008BDA0 03000224 */   addiu     $v0, $zero, 0x3
    /* 7C5A4 8008BDA4 13006010 */  beqz       $v1, .L8008BDF4
    /* 7C5A8 8008BDA8 01000224 */   addiu     $v0, $zero, 0x1
    /* 7C5AC 8008BDAC E32F0208 */  j          .L8008BF8C
    /* 7C5B0 8008BDB0 00000000 */   nop
  .L8008BDB4:
    /* 7C5B4 8008BDB4 43006214 */  bne        $v1, $v0, .L8008BEC4
    /* 7C5B8 8008BDB8 00000000 */   nop
    /* 7C5BC 8008BDBC 0C00228E */  lw         $v0, 0xC($s1)
    /* 7C5C0 8008BDC0 0800238E */  lw         $v1, 0x8($s1)
    /* 7C5C4 8008BDC4 FCFF2426 */  addiu      $a0, $s1, -0x4
    /* 7C5C8 8008BDC8 1080013C */  lui        $at, %hi(D_800FE330)
    /* 7C5CC 8008BDCC 30E325AC */  sw         $a1, %lo(D_800FE330)($at)
    /* 7C5D0 8008BDD0 04104500 */  sllv       $v0, $a1, $v0
    /* 7C5D4 8008BDD4 25186200 */  or         $v1, $v1, $v0
    /* 7C5D8 8008BDD8 5835020C */  jal        func_8008D560
    /* 7C5DC 8008BDDC 0C0083AC */   sw        $v1, 0xC($a0)
    /* 7C5E0 8008BDE0 0C00248E */  lw         $a0, 0xC($s1)
    /* 7C5E4 8008BDE4 E82C020C */  jal        func_8008B3A0
    /* 7C5E8 8008BDE8 00000000 */   nop
    /* 7C5EC 8008BDEC E12F0208 */  j          .L8008BF84
    /* 7C5F0 8008BDF0 15000224 */   addiu     $v0, $zero, 0x15
  .L8008BDF4:
    /* 7C5F4 8008BDF4 E12F0208 */  j          .L8008BF84
    /* 7C5F8 8008BDF8 1E000224 */   addiu     $v0, $zero, 0x1E
  jlabel .L8008BDFC
    /* 7C5FC 8008BDFC 1536020C */  jal        func_8008D854
    /* 7C600 8008BE00 00000000 */   nop
    /* 7C604 8008BE04 60004010 */  beqz       $v0, .L8008BF88
    /* 7C608 8008BE08 00000000 */   nop
    /* 7C60C 8008BE0C D035020C */  jal        func_8008D740
    /* 7C610 8008BE10 00000000 */   nop
    /* 7C614 8008BE14 1E000224 */  addiu      $v0, $zero, 0x1E
    /* 7C618 8008BE18 000002AE */  sw         $v0, 0x0($s0)
  jlabel .L8008BE1C
    /* 7C61C 8008BE1C 5835020C */  jal        func_8008D560
    /* 7C620 8008BE20 00000000 */   nop
    /* 7C624 8008BE24 1080043C */  lui        $a0, %hi(D_800FE358)
    /* 7C628 8008BE28 58E3848C */  lw         $a0, %lo(D_800FE358)($a0)
    /* 7C62C 8008BE2C D02C020C */  jal        func_8008B340
    /* 7C630 8008BE30 00000000 */   nop
    /* 7C634 8008BE34 0000028E */  lw         $v0, 0x0($s0)
    /* 7C638 8008BE38 E12F0208 */  j          .L8008BF84
    /* 7C63C 8008BE3C 01004224 */   addiu     $v0, $v0, 0x1
  jlabel .L8008BE40
    /* 7C640 8008BE40 0636020C */  jal        func_8008D818
    /* 7C644 8008BE44 00000000 */   nop
    /* 7C648 8008BE48 50004010 */  beqz       $v0, .L8008BF8C
    /* 7C64C 8008BE4C 21100000 */   addu      $v0, $zero, $zero
    /* 7C650 8008BE50 9A35020C */  jal        func_8008D668
    /* 7C654 8008BE54 00000000 */   nop
    /* 7C658 8008BE58 21184000 */  addu       $v1, $v0, $zero
    /* 7C65C 8008BE5C 1080013C */  lui        $at, %hi(D_800FE32C)
    /* 7C660 8008BE60 2CE322AC */  sw         $v0, %lo(D_800FE32C)($at)
    /* 7C664 8008BE64 01000424 */  addiu      $a0, $zero, 0x1
    /* 7C668 8008BE68 22006410 */  beq        $v1, $a0, .L8008BEF4
    /* 7C66C 8008BE6C 02006228 */   slti      $v0, $v1, 0x2
    /* 7C670 8008BE70 05004010 */  beqz       $v0, .L8008BE88
    /* 7C674 8008BE74 02000224 */   addiu     $v0, $zero, 0x2
    /* 7C678 8008BE78 09006010 */  beqz       $v1, .L8008BEA0
    /* 7C67C 8008BE7C 00000000 */   nop
    /* 7C680 8008BE80 C62F0208 */  j          .L8008BF18
    /* 7C684 8008BE84 00000000 */   nop
  .L8008BE88:
    /* 7C688 8008BE88 18006210 */  beq        $v1, $v0, .L8008BEEC
    /* 7C68C 8008BE8C 04000224 */   addiu     $v0, $zero, 0x4
    /* 7C690 8008BE90 0E006210 */  beq        $v1, $v0, .L8008BECC
    /* 7C694 8008BE94 00000000 */   nop
    /* 7C698 8008BE98 C62F0208 */  j          .L8008BF18
    /* 7C69C 8008BE9C 00000000 */   nop
  .L8008BEA0:
    /* 7C6A0 8008BEA0 1080023C */  lui        $v0, %hi(D_800FE330)
    /* 7C6A4 8008BEA4 30E3428C */  lw         $v0, %lo(D_800FE330)($v0)
    /* 7C6A8 8008BEA8 00000000 */  nop
    /* 7C6AC 8008BEAC 02004010 */  beqz       $v0, .L8008BEB8
    /* 7C6B0 8008BEB0 21180000 */   addu      $v1, $zero, $zero
    /* 7C6B4 8008BEB4 03000324 */  addiu      $v1, $zero, 0x3
  .L8008BEB8:
    /* 7C6B8 8008BEB8 1080023C */  lui        $v0, %hi(D_800FE348)
    /* 7C6BC 8008BEBC 48E34224 */  addiu      $v0, $v0, %lo(D_800FE348)
    /* 7C6C0 8008BEC0 040043AC */  sw         $v1, 0x4($v0)
  .L8008BEC4:
    /* 7C6C4 8008BEC4 E32F0208 */  j          .L8008BF8C
    /* 7C6C8 8008BEC8 01000224 */   addiu     $v0, $zero, 0x1
  .L8008BECC:
    /* 7C6CC 8008BECC 5835020C */  jal        func_8008D560
    /* 7C6D0 8008BED0 00000000 */   nop
    /* 7C6D4 8008BED4 1080043C */  lui        $a0, %hi(D_800FE358)
    /* 7C6D8 8008BED8 58E3848C */  lw         $a0, %lo(D_800FE358)($a0)
    /* 7C6DC 8008BEDC CC2C020C */  jal        func_8008B330
    /* 7C6E0 8008BEE0 00000000 */   nop
    /* 7C6E4 8008BEE4 E12F0208 */  j          .L8008BF84
    /* 7C6E8 8008BEE8 32000224 */   addiu     $v0, $zero, 0x32
  .L8008BEEC:
    /* 7C6EC 8008BEEC E22F0208 */  j          .L8008BF88
    /* 7C6F0 8008BEF0 000004AE */   sw        $a0, 0x0($s0)
  .L8008BEF4:
    /* 7C6F4 8008BEF4 1080023C */  lui        $v0, %hi(D_800FE324)
    /* 7C6F8 8008BEF8 24E3428C */  lw         $v0, %lo(D_800FE324)($v0)
    /* 7C6FC 8008BEFC 00000000 */  nop
    /* 7C700 8008BF00 01004224 */  addiu      $v0, $v0, 0x1
    /* 7C704 8008BF04 1080013C */  lui        $at, %hi(D_800FE324)
    /* 7C708 8008BF08 24E322AC */  sw         $v0, %lo(D_800FE324)($at)
    /* 7C70C 8008BF0C 11004228 */  slti       $v0, $v0, 0x11
    /* 7C710 8008BF10 1C004014 */  bnez       $v0, .L8008BF84
    /* 7C714 8008BF14 1E000224 */   addiu     $v0, $zero, 0x1E
  .L8008BF18:
    /* 7C718 8008BF18 1080043C */  lui        $a0, %hi(D_800FE32C)
    /* 7C71C 8008BF1C 2CE3848C */  lw         $a0, %lo(D_800FE32C)($a0)
    /* 7C720 8008BF20 DD33020C */  jal        func_8008CF74
    /* 7C724 8008BF24 00000000 */   nop
    /* 7C728 8008BF28 21204000 */  addu       $a0, $v0, $zero
    /* 7C72C 8008BF2C 01000224 */  addiu      $v0, $zero, 0x1
    /* 7C730 8008BF30 1080033C */  lui        $v1, %hi(D_800FE348)
    /* 7C734 8008BF34 48E36324 */  addiu      $v1, $v1, %lo(D_800FE348)
    /* 7C738 8008BF38 E32F0208 */  j          .L8008BF8C
    /* 7C73C 8008BF3C 040064AC */   sw        $a0, 0x4($v1)
  jlabel .L8008BF40
    /* 7C740 8008BF40 0636020C */  jal        func_8008D818
    /* 7C744 8008BF44 00000000 */   nop
    /* 7C748 8008BF48 10004010 */  beqz       $v0, .L8008BF8C
    /* 7C74C 8008BF4C 21100000 */   addu      $v0, $zero, $zero
    /* 7C750 8008BF50 9A35020C */  jal        func_8008D668
    /* 7C754 8008BF54 00000000 */   nop
    /* 7C758 8008BF58 21184000 */  addu       $v1, $v0, $zero
    /* 7C75C 8008BF5C 1080013C */  lui        $at, %hi(D_800FE32C)
    /* 7C760 8008BF60 2CE322AC */  sw         $v0, %lo(D_800FE32C)($at)
    /* 7C764 8008BF64 07006014 */  bnez       $v1, .L8008BF84
    /* 7C768 8008BF68 01000224 */   addiu     $v0, $zero, 0x1
    /* 7C76C 8008BF6C 1080033C */  lui        $v1, %hi(D_800FE348)
    /* 7C770 8008BF70 48E36324 */  addiu      $v1, $v1, %lo(D_800FE348)
    /* 7C774 8008BF74 04000224 */  addiu      $v0, $zero, 0x4
    /* 7C778 8008BF78 040062AC */  sw         $v0, 0x4($v1)
    /* 7C77C 8008BF7C E32F0208 */  j          .L8008BF8C
    /* 7C780 8008BF80 01000224 */   addiu     $v0, $zero, 0x1
  .L8008BF84:
    /* 7C784 8008BF84 000002AE */  sw         $v0, 0x0($s0)
  jlabel .L8008BF88
    /* 7C788 8008BF88 21100000 */  addu       $v0, $zero, $zero
  .L8008BF8C:
    /* 7C78C 8008BF8C 1800BF8F */  lw         $ra, 0x18($sp)
    /* 7C790 8008BF90 1400B18F */  lw         $s1, 0x14($sp)
    /* 7C794 8008BF94 1000B08F */  lw         $s0, 0x10($sp)
    /* 7C798 8008BF98 0800E003 */  jr         $ra
    /* 7C79C 8008BF9C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008BCF8
