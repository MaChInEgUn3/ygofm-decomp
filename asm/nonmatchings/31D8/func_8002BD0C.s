nonmatching func_8002BD0C, 0x230

glabel func_8002BD0C
    /* 1C50C 8002BD0C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1C510 8002BD10 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1C514 8002BD14 21908000 */  addu       $s2, $a0, $zero
    /* 1C518 8002BD18 0700A22C */  sltiu      $v0, $a1, 0x7
    /* 1C51C 8002BD1C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1C520 8002BD20 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1C524 8002BD24 7F004010 */  beqz       $v0, .L8002BF24
    /* 1C528 8002BD28 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1C52C 8002BD2C 0180023C */  lui        $v0, %hi(jtbl_80010208)
    /* 1C530 8002BD30 08024224 */  addiu      $v0, $v0, %lo(jtbl_80010208)
    /* 1C534 8002BD34 80180500 */  sll        $v1, $a1, 2
    /* 1C538 8002BD38 21186200 */  addu       $v1, $v1, $v0
    /* 1C53C 8002BD3C 0000628C */  lw         $v0, 0x0($v1)
    /* 1C540 8002BD40 00000000 */  nop
    /* 1C544 8002BD44 08004000 */  jr         $v0
    /* 1C548 8002BD48 00000000 */   nop
  jlabel .L8002BD4C
    /* 1C54C 8002BD4C DDFF043C */  lui        $a0, (0xFFDDFFFF >> 16)
    /* 1C550 8002BD50 FFFF8434 */  ori        $a0, $a0, (0xFFDDFFFF & 0xFFFF)
    /* 1C554 8002BD54 00030224 */  addiu      $v0, $zero, 0x300
    /* 1C558 8002BD58 300042A6 */  sh         $v0, 0x30($s2)
    /* 1C55C 8002BD5C 00010224 */  addiu      $v0, $zero, 0x100
    /* 1C560 8002BD60 320042A6 */  sh         $v0, 0x32($s2)
    /* 1C564 8002BD64 40000224 */  addiu      $v0, $zero, 0x40
    /* 1C568 8002BD68 040042A6 */  sh         $v0, 0x4($s2)
    /* 1C56C 8002BD6C 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 1C570 8002BD70 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 1C574 8002BD74 10000324 */  addiu      $v1, $zero, 0x10
    /* 1C578 8002BD78 060043A6 */  sh         $v1, 0x6($s2)
    /* 1C57C 8002BD7C 24104400 */  and        $v0, $v0, $a0
    /* 1C580 8002BD80 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 1C584 8002BD84 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 1C588 8002BD88 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 1C58C 8002BD8C F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 1C590 8002BD90 0100033C */  lui        $v1, (0x10000 >> 16)
    /* 1C594 8002BD94 25104300 */  or         $v0, $v0, $v1
    /* 1C598 8002BD98 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 1C59C 8002BD9C F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 1C5A0 8002BDA0 02000224 */  addiu      $v0, $zero, 0x2
    /* 1C5A4 8002BDA4 460042A2 */  sb         $v0, 0x46($s2)
    /* 1C5A8 8002BDA8 0A80023C */  lui        $v0, %hi(D_8009B118)
    /* 1C5AC 8002BDAC 18B1428C */  lw         $v0, %lo(D_8009B118)($v0)
    /* 1C5B0 8002BDB0 B0AF0008 */  j          .L8002BEC0
    /* 1C5B4 8002BDB4 0200033C */   lui       $v1, (0x20000 >> 16)
  jlabel .L8002BDB8
    /* 1C5B8 8002BDB8 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 1C5BC 8002BDBC FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 1C5C0 8002BDC0 B8AF0008 */  j          .L8002BEE0
    /* 1C5C4 8002BDC4 00200224 */   addiu     $v0, $zero, 0x2000
  jlabel .L8002BDC8
    /* 1C5C8 8002BDC8 0F80023C */  lui        $v0, %hi(D_800E9D70)
    /* 1C5CC 8002BDCC 709D4424 */  addiu      $a0, $v0, %lo(D_800E9D70)
    /* 1C5D0 8002BDD0 00011024 */  addiu      $s0, $zero, 0x100
    /* 1C5D4 8002BDD4 709D50A4 */  sh         $s0, %lo(D_800E9D70)($v0)
    /* 1C5D8 8002BDD8 F0000224 */  addiu      $v0, $zero, 0xF0
    /* 1C5DC 8002BDDC 0A80053C */  lui        $a1, %hi(D_8009B118)
    /* 1C5E0 8002BDE0 18B1A58C */  lw         $a1, %lo(D_8009B118)($a1)
    /* 1C5E4 8002BDE4 10001124 */  addiu      $s1, $zero, 0x10
    /* 1C5E8 8002BDE8 020082A4 */  sh         $v0, 0x2($a0)
    /* 1C5EC 8002BDEC 040090A4 */  sh         $s0, 0x4($a0)
    /* 1C5F0 8002BDF0 7A07020C */  jal        func_80081DE8
    /* 1C5F4 8002BDF4 060091A4 */   sh        $s1, 0x6($a0)
    /* 1C5F8 8002BDF8 DDFF043C */  lui        $a0, (0xFFDDFFFF >> 16)
    /* 1C5FC 8002BDFC FFFF8434 */  ori        $a0, $a0, (0xFFDDFFFF & 0xFFFF)
    /* 1C600 8002BE00 0100053C */  lui        $a1, (0x18000 >> 16)
    /* 1C604 8002BE04 0080A534 */  ori        $a1, $a1, (0x18000 & 0xFFFF)
    /* 1C608 8002BE08 0A80033C */  lui        $v1, %hi(D_8009B0F4)
    /* 1C60C 8002BE0C F4B0638C */  lw         $v1, %lo(D_8009B0F4)($v1)
    /* 1C610 8002BE10 40020224 */  addiu      $v0, $zero, 0x240
    /* 1C614 8002BE14 300042A6 */  sh         $v0, 0x30($s2)
    /* 1C618 8002BE18 320050A6 */  sh         $s0, 0x32($s2)
    /* 1C61C 8002BE1C 060051A6 */  sh         $s1, 0x6($s2)
    /* 1C620 8002BE20 1C0045AE */  sw         $a1, 0x1C($s2)
    /* 1C624 8002BE24 24186400 */  and        $v1, $v1, $a0
    /* 1C628 8002BE28 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 1C62C 8002BE2C F4B023AC */  sw         $v1, %lo(D_8009B0F4)($at)
    /* 1C630 8002BE30 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 1C634 8002BE34 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 1C638 8002BE38 0100033C */  lui        $v1, (0x10000 >> 16)
    /* 1C63C 8002BE3C 25104300 */  or         $v0, $v0, $v1
    /* 1C640 8002BE40 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 1C644 8002BE44 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 1C648 8002BE48 02000224 */  addiu      $v0, $zero, 0x2
    /* 1C64C 8002BE4C 460042A2 */  sb         $v0, 0x46($s2)
    /* 1C650 8002BE50 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 1C654 8002BE54 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 1C658 8002BE58 40000224 */  addiu      $v0, $zero, 0x40
    /* 1C65C 8002BE5C 040042A6 */  sh         $v0, 0x4($s2)
    /* 1C660 8002BE60 080043AE */  sw         $v1, 0x8($s2)
    /* 1C664 8002BE64 00086324 */  addiu      $v1, $v1, 0x800
    /* 1C668 8002BE68 C9AF0008 */  j          .L8002BF24
    /* 1C66C 8002BE6C 0C0043AE */   sw        $v1, 0xC($s2)
  jlabel .L8002BE70
    /* 1C670 8002BE70 0F80023C */  lui        $v0, %hi(D_800E9D70)
    /* 1C674 8002BE74 709D4424 */  addiu      $a0, $v0, %lo(D_800E9D70)
    /* 1C678 8002BE78 0A80053C */  lui        $a1, %hi(D_8009B118)
    /* 1C67C 8002BE7C 18B1A58C */  lw         $a1, %lo(D_8009B118)($a1)
    /* 1C680 8002BE80 00010324 */  addiu      $v1, $zero, 0x100
    /* 1C684 8002BE84 709D43A4 */  sh         $v1, %lo(D_800E9D70)($v0)
    /* 1C688 8002BE88 F6000224 */  addiu      $v0, $zero, 0xF6
    /* 1C68C 8002BE8C 020082A4 */  sh         $v0, 0x2($a0)
    /* 1C690 8002BE90 02000224 */  addiu      $v0, $zero, 0x2
    /* 1C694 8002BE94 040083A4 */  sh         $v1, 0x4($a0)
    /* 1C698 8002BE98 7A07020C */  jal        func_80081DE8
    /* 1C69C 8002BE9C 060082A4 */   sh        $v0, 0x6($a0)
    /* 1C6A0 8002BEA0 0200033C */  lui        $v1, (0x26810 >> 16)
    /* 1C6A4 8002BEA4 03000224 */  addiu      $v0, $zero, 0x3
    /* 1C6A8 8002BEA8 460042A2 */  sb         $v0, 0x46($s2)
    /* 1C6AC 8002BEAC 0A80023C */  lui        $v0, %hi(D_8009B118)
    /* 1C6B0 8002BEB0 18B1428C */  lw         $v0, %lo(D_8009B118)($v0)
    /* 1C6B4 8002BEB4 10686334 */  ori        $v1, $v1, (0x26810 & 0xFFFF)
    /* 1C6B8 8002BEB8 300043AE */  sw         $v1, 0x30($s2)
    /* 1C6BC 8002BEBC 00A00334 */  ori        $v1, $zero, 0xA000
  .L8002BEC0:
    /* 1C6C0 8002BEC0 1C0043AE */  sw         $v1, 0x1C($s2)
    /* 1C6C4 8002BEC4 080042AE */  sw         $v0, 0x8($s2)
    /* 1C6C8 8002BEC8 00084224 */  addiu      $v0, $v0, 0x800
    /* 1C6CC 8002BECC C9AF0008 */  j          .L8002BF24
    /* 1C6D0 8002BED0 0C0042AE */   sw        $v0, 0xC($s2)
  jlabel .L8002BED4
    /* 1C6D4 8002BED4 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 1C6D8 8002BED8 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 1C6DC 8002BEDC 00080224 */  addiu      $v0, $zero, 0x800
  .L8002BEE0:
    /* 1C6E0 8002BEE0 1C0042AE */  sw         $v0, 0x1C($s2)
    /* 1C6E4 8002BEE4 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 1C6E8 8002BEE8 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 1C6EC 8002BEEC 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 1C6F0 8002BEF0 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 1C6F4 8002BEF4 24104400 */  and        $v0, $v0, $a0
    /* 1C6F8 8002BEF8 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 1C6FC 8002BEFC F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 1C700 8002BF00 01000224 */  addiu      $v0, $zero, 0x1
    /* 1C704 8002BF04 0C0043AE */  sw         $v1, 0xC($s2)
    /* 1C708 8002BF08 080043AE */  sw         $v1, 0x8($s2)
    /* 1C70C 8002BF0C C9AF0008 */  j          .L8002BF24
    /* 1C710 8002BF10 460042A2 */   sb        $v0, 0x46($s2)
  jlabel .L8002BF14
    /* 1C714 8002BF14 0A80053C */  lui        $a1, %hi(D_8009B118)
    /* 1C718 8002BF18 18B1A58C */  lw         $a1, %lo(D_8009B118)($a1)
    /* 1C71C 8002BF1C 4223010C */  jal        func_80048D08
    /* 1C720 8002BF20 01000424 */   addiu     $a0, $zero, 0x1
  .L8002BF24:
    /* 1C724 8002BF24 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1C728 8002BF28 1800B28F */  lw         $s2, 0x18($sp)
    /* 1C72C 8002BF2C 1400B18F */  lw         $s1, 0x14($sp)
    /* 1C730 8002BF30 1000B08F */  lw         $s0, 0x10($sp)
    /* 1C734 8002BF34 0800E003 */  jr         $ra
    /* 1C738 8002BF38 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8002BD0C
