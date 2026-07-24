nonmatching func_8003BD14, 0x1A4

glabel func_8003BD14
    /* 2C514 8003BD14 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2C518 8003BD18 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2C51C 8003BD1C 21808000 */  addu       $s0, $a0, $zero
    /* 2C520 8003BD20 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2C524 8003BD24 01001124 */  addiu      $s1, $zero, 0x1
    /* 2C528 8003BD28 2D00B110 */  beq        $a1, $s1, .L8003BDE0
    /* 2C52C 8003BD2C 1800BFAF */   sw        $ra, 0x18($sp)
    /* 2C530 8003BD30 0200A228 */  slti       $v0, $a1, 0x2
    /* 2C534 8003BD34 05004010 */  beqz       $v0, .L8003BD4C
    /* 2C538 8003BD38 00000000 */   nop
    /* 2C53C 8003BD3C 0A00A010 */  beqz       $a1, .L8003BD68
    /* 2C540 8003BD40 DDFF043C */   lui       $a0, (0xFFDDFFFF >> 16)
    /* 2C544 8003BD44 A9EF0008 */  j          .L8003BEA4
    /* 2C548 8003BD48 00000000 */   nop
  .L8003BD4C:
    /* 2C54C 8003BD4C 02000224 */  addiu      $v0, $zero, 0x2
    /* 2C550 8003BD50 2D00A210 */  beq        $a1, $v0, .L8003BE08
    /* 2C554 8003BD54 03000224 */   addiu     $v0, $zero, 0x3
    /* 2C558 8003BD58 4500A210 */  beq        $a1, $v0, .L8003BE70
    /* 2C55C 8003BD5C DCFF043C */   lui       $a0, (0xFFDCFFFF >> 16)
    /* 2C560 8003BD60 A9EF0008 */  j          .L8003BEA4
    /* 2C564 8003BD64 00000000 */   nop
  .L8003BD68:
    /* 2C568 8003BD68 FFFF8434 */  ori        $a0, $a0, (0xFFDDFFFF & 0xFFFF)
    /* 2C56C 8003BD6C 00030224 */  addiu      $v0, $zero, 0x300
    /* 2C570 8003BD70 300002A6 */  sh         $v0, 0x30($s0)
    /* 2C574 8003BD74 00010224 */  addiu      $v0, $zero, 0x100
    /* 2C578 8003BD78 320002A6 */  sh         $v0, 0x32($s0)
    /* 2C57C 8003BD7C 40000224 */  addiu      $v0, $zero, 0x40
    /* 2C580 8003BD80 040002A6 */  sh         $v0, 0x4($s0)
    /* 2C584 8003BD84 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C588 8003BD88 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C58C 8003BD8C 10000324 */  addiu      $v1, $zero, 0x10
    /* 2C590 8003BD90 060003A6 */  sh         $v1, 0x6($s0)
    /* 2C594 8003BD94 24104400 */  and        $v0, $v0, $a0
    /* 2C598 8003BD98 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C59C 8003BD9C F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C5A0 8003BDA0 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C5A4 8003BDA4 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C5A8 8003BDA8 0100033C */  lui        $v1, (0x10000 >> 16)
    /* 2C5AC 8003BDAC 25104300 */  or         $v0, $v0, $v1
    /* 2C5B0 8003BDB0 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C5B4 8003BDB4 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C5B8 8003BDB8 02000224 */  addiu      $v0, $zero, 0x2
    /* 2C5BC 8003BDBC 460002A2 */  sb         $v0, 0x46($s0)
    /* 2C5C0 8003BDC0 0A80023C */  lui        $v0, %hi(D_8009B118)
    /* 2C5C4 8003BDC4 18B1428C */  lw         $v0, %lo(D_8009B118)($v0)
    /* 2C5C8 8003BDC8 0200033C */  lui        $v1, (0x20000 >> 16)
    /* 2C5CC 8003BDCC 1C0003AE */  sw         $v1, 0x1C($s0)
    /* 2C5D0 8003BDD0 080002AE */  sw         $v0, 0x8($s0)
    /* 2C5D4 8003BDD4 00084224 */  addiu      $v0, $v0, 0x800
    /* 2C5D8 8003BDD8 A9EF0008 */  j          .L8003BEA4
    /* 2C5DC 8003BDDC 0C0002AE */   sw        $v0, 0xC($s0)
  .L8003BDE0:
    /* 2C5E0 8003BDE0 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2C5E4 8003BDE4 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2C5E8 8003BDE8 00200224 */  addiu      $v0, $zero, 0x2000
    /* 2C5EC 8003BDEC 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 2C5F0 8003BDF0 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C5F4 8003BDF4 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C5F8 8003BDF8 0A80033C */  lui        $v1, %hi(D_8009B118)
    /* 2C5FC 8003BDFC 18B1638C */  lw         $v1, %lo(D_8009B118)($v1)
    /* 2C600 8003BE00 A4EF0008 */  j          .L8003BE90
    /* 2C604 8003BE04 24104400 */   and       $v0, $v0, $a0
  .L8003BE08:
    /* 2C608 8003BE08 00010324 */  addiu      $v1, $zero, 0x100
    /* 2C60C 8003BE0C F0000224 */  addiu      $v0, $zero, 0xF0
    /* 2C610 8003BE10 020002A6 */  sh         $v0, 0x2($s0)
    /* 2C614 8003BE14 10000224 */  addiu      $v0, $zero, 0x10
    /* 2C618 8003BE18 0A80053C */  lui        $a1, %hi(D_8009B118)
    /* 2C61C 8003BE1C 18B1A58C */  lw         $a1, %lo(D_8009B118)($a1)
    /* 2C620 8003BE20 21200002 */  addu       $a0, $s0, $zero
    /* 2C624 8003BE24 000003A6 */  sh         $v1, 0x0($s0)
    /* 2C628 8003BE28 040003A6 */  sh         $v1, 0x4($s0)
    /* 2C62C 8003BE2C 7A07020C */  jal        func_80081DE8
    /* 2C630 8003BE30 060002A6 */   sh        $v0, 0x6($s0)
    /* 2C634 8003BE34 DCFF043C */  lui        $a0, (0xFFDCFFFF >> 16)
    /* 2C638 8003BE38 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2C63C 8003BE3C 1B80023C */  lui        $v0, %hi(D_801A8000)
    /* 2C640 8003BE40 00804224 */  addiu      $v0, $v0, %lo(D_801A8000)
    /* 2C644 8003BE44 0C0002AE */  sw         $v0, 0xC($s0)
    /* 2C648 8003BE48 080002AE */  sw         $v0, 0x8($s0)
    /* 2C64C 8003BE4C 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C650 8003BE50 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C654 8003BE54 00180324 */  addiu      $v1, $zero, 0x1800
    /* 2C658 8003BE58 1C0003AE */  sw         $v1, 0x1C($s0)
    /* 2C65C 8003BE5C 24104400 */  and        $v0, $v0, $a0
    /* 2C660 8003BE60 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C664 8003BE64 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C668 8003BE68 A9EF0008 */  j          .L8003BEA4
    /* 2C66C 8003BE6C 460011A2 */   sb        $s1, 0x46($s0)
  .L8003BE70:
    /* 2C670 8003BE70 FFFF8434 */  ori        $a0, $a0, (0xFFDCFFFF & 0xFFFF)
    /* 2C674 8003BE74 00780224 */  addiu      $v0, $zero, 0x7800
    /* 2C678 8003BE78 1C0002AE */  sw         $v0, 0x1C($s0)
    /* 2C67C 8003BE7C 0A80023C */  lui        $v0, %hi(D_8009B0F4)
    /* 2C680 8003BE80 F4B0428C */  lw         $v0, %lo(D_8009B0F4)($v0)
    /* 2C684 8003BE84 0180033C */  lui        $v1, %hi(D_800101D8)
    /* 2C688 8003BE88 D801638C */  lw         $v1, %lo(D_800101D8)($v1)
    /* 2C68C 8003BE8C 24104400 */  and        $v0, $v0, $a0
  .L8003BE90:
    /* 2C690 8003BE90 0A80013C */  lui        $at, %hi(D_8009B0F4)
    /* 2C694 8003BE94 F4B022AC */  sw         $v0, %lo(D_8009B0F4)($at)
    /* 2C698 8003BE98 0C0003AE */  sw         $v1, 0xC($s0)
    /* 2C69C 8003BE9C 080003AE */  sw         $v1, 0x8($s0)
    /* 2C6A0 8003BEA0 460011A2 */  sb         $s1, 0x46($s0)
  .L8003BEA4:
    /* 2C6A4 8003BEA4 1800BF8F */  lw         $ra, 0x18($sp)
    /* 2C6A8 8003BEA8 1400B18F */  lw         $s1, 0x14($sp)
    /* 2C6AC 8003BEAC 1000B08F */  lw         $s0, 0x10($sp)
    /* 2C6B0 8003BEB0 0800E003 */  jr         $ra
    /* 2C6B4 8003BEB4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003BD14
