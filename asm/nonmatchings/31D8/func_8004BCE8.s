nonmatching func_8004BCE8, 0x184

glabel func_8004BCE8
    /* 3C4E8 8004BCE8 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3C4EC 8004BCEC 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3C4F0 8004BCF0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3C4F4 8004BCF4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 3C4F8 8004BCF8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3C4FC 8004BCFC 18057024 */  addiu      $s0, $v1, 0x518
    /* 3C500 8004BD00 010860A0 */  sb         $zero, 0x801($v1)
    /* 3C504 8004BD04 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3C508 8004BD08 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3C50C 8004BD0C 21200002 */  addu       $a0, $s0, $zero
    /* 3C510 8004BD10 F00740AC */  sw         $zero, 0x7F0($v0)
    /* 3C514 8004BD14 F40740AC */  sw         $zero, 0x7F4($v0)
    /* 3C518 8004BD18 08000224 */  addiu      $v0, $zero, 0x8
    /* 3C51C 8004BD1C 2A2F010C */  jal        func_8004BCA8
    /* 3C520 8004BD20 180562AC */   sw        $v0, 0x518($v1)
    /* 3C524 8004BD24 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3C528 8004BD28 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3C52C 8004BD2C 21200002 */  addu       $a0, $s0, $zero
    /* 3C530 8004BD30 FC0762A4 */  sh         $v0, 0x7FC($v1)
    /* 3C534 8004BD34 01000224 */  addiu      $v0, $zero, 0x1
    /* 3C538 8004BD38 FA0762A4 */  sh         $v0, 0x7FA($v1)
    /* 3C53C 8004BD3C 0100023C */  lui        $v0, (0x10000 >> 16)
    /* 3C540 8004BD40 F80760A4 */  sh         $zero, 0x7F8($v1)
    /* 3C544 8004BD44 0B2F010C */  jal        func_8004BC2C
    /* 3C548 8004BD48 EC0762AC */   sw        $v0, 0x7EC($v1)
    /* 3C54C 8004BD4C 022A0200 */  srl        $a1, $v0, 8
    /* 3C550 8004BD50 9303023C */  lui        $v0, (0x3938700 >> 16)
    /* 3C554 8004BD54 0A80043C */  lui        $a0, %hi(D_8009B458)
    /* 3C558 8004BD58 58B4848C */  lw         $a0, %lo(D_8009B458)($a0)
    /* 3C55C 8004BD5C 00874234 */  ori        $v0, $v0, (0x3938700 & 0xFFFF)
    /* 3C560 8004BD60 080885AC */  sw         $a1, 0x808($a0)
    /* 3C564 8004BD64 1B004500 */  divu       $zero, $v0, $a1
    /* 3C568 8004BD68 0200A014 */  bnez       $a1, .L8004BD74
    /* 3C56C 8004BD6C 00000000 */   nop
    /* 3C570 8004BD70 0D000700 */  break      7
  .L8004BD74:
    /* 3C574 8004BD74 12280000 */  mflo       $a1
    /* 3C578 8004BD78 F01C033C */  lui        $v1, (0x1CF06ADB >> 16)
    /* 3C57C 8004BD7C DB6A6334 */  ori        $v1, $v1, (0x1CF06ADB & 0xFFFF)
    /* 3C580 8004BD80 40100500 */  sll        $v0, $a1, 1
    /* 3C584 8004BD84 21104500 */  addu       $v0, $v0, $a1
    /* 3C588 8004BD88 C0100200 */  sll        $v0, $v0, 3
    /* 3C58C 8004BD8C 21104500 */  addu       $v0, $v0, $a1
    /* 3C590 8004BD90 80100200 */  sll        $v0, $v0, 2
    /* 3C594 8004BD94 19004300 */  multu      $v0, $v1
    /* 3C598 8004BD98 10180000 */  mfhi       $v1
    /* 3C59C 8004BD9C 23104300 */  subu       $v0, $v0, $v1
    /* 3C5A0 8004BDA0 42100200 */  srl        $v0, $v0, 1
    /* 3C5A4 8004BDA4 21186200 */  addu       $v1, $v1, $v0
    /* 3C5A8 8004BDA8 82290300 */  srl        $a1, $v1, 6
    /* 3C5AC 8004BDAC 0001A22C */  sltiu      $v0, $a1, 0x100
    /* 3C5B0 8004BDB0 02004014 */  bnez       $v0, .L8004BDBC
    /* 3C5B4 8004BDB4 00000000 */   nop
    /* 3C5B8 8004BDB8 FF000524 */  addiu      $a1, $zero, 0xFF
  .L8004BDBC:
    /* 3C5BC 8004BDBC FC078394 */  lhu        $v1, 0x7FC($a0)
    /* 3C5C0 8004BDC0 1E000224 */  addiu      $v0, $zero, 0x1E
    /* 3C5C4 8004BDC4 0C006210 */  beq        $v1, $v0, .L8004BDF8
    /* 3C5C8 8004BDC8 1F006228 */   slti      $v0, $v1, 0x1F
    /* 3C5CC 8004BDCC 05004010 */  beqz       $v0, .L8004BDE4
    /* 3C5D0 8004BDD0 18000224 */   addiu     $v0, $zero, 0x18
    /* 3C5D4 8004BDD4 06006210 */  beq        $v1, $v0, .L8004BDF0
    /* 3C5D8 8004BDD8 21200002 */   addu      $a0, $s0, $zero
    /* 3C5DC 8004BDDC 812F0108 */  j          .L8004BE04
    /* 3C5E0 8004BDE0 FF00A230 */   andi      $v0, $a1, 0xFF
  .L8004BDE4:
    /* 3C5E4 8004BDE4 3C000224 */  addiu      $v0, $zero, 0x3C
    /* 3C5E8 8004BDE8 05006214 */  bne        $v1, $v0, .L8004BE00
    /* 3C5EC 8004BDEC 21200002 */   addu      $a0, $s0, $zero
  .L8004BDF0:
    /* 3C5F0 8004BDF0 7F2F0108 */  j          .L8004BDFC
    /* 3C5F4 8004BDF4 42280500 */   srl       $a1, $a1, 1
  .L8004BDF8:
    /* 3C5F8 8004BDF8 82280500 */  srl        $a1, $a1, 2
  .L8004BDFC:
    /* 3C5FC 8004BDFC 21200002 */  addu       $a0, $s0, $zero
  .L8004BE00:
    /* 3C600 8004BE00 FF00A230 */  andi       $v0, $a1, 0xFF
  .L8004BE04:
    /* 3C604 8004BE04 160082A4 */  sh         $v0, 0x16($a0)
    /* 3C608 8004BE08 B92E010C */  jal        func_8004BAE4
    /* 3C60C 8004BE0C 140082A4 */   sh        $v0, 0x14($a0)
    /* 3C610 8004BE10 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3C614 8004BE14 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3C618 8004BE18 00000000 */  nop
    /* 3C61C 8004BE1C FC076294 */  lhu        $v0, 0x7FC($v1)
    /* 3C620 8004BE20 00000000 */  nop
    /* 3C624 8004BE24 6000422C */  sltiu      $v0, $v0, 0x60
    /* 3C628 8004BE28 04004014 */  bnez       $v0, .L8004BE3C
    /* 3C62C 8004BE2C 00000000 */   nop
    /* 3C630 8004BE30 FC076294 */  lhu        $v0, 0x7FC($v1)
    /* 3C634 8004BE34 902F0108 */  j          .L8004BE40
    /* 3C638 8004BE38 040862AC */   sw        $v0, 0x804($v1)
  .L8004BE3C:
    /* 3C63C 8004BE3C 040860AC */  sw         $zero, 0x804($v1)
  .L8004BE40:
    /* 3C640 8004BE40 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3C644 8004BE44 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3C648 8004BE48 00000000 */  nop
    /* 3C64C 8004BE4C FC076494 */  lhu        $a0, 0x7FC($v1)
    /* 3C650 8004BE50 00000000 */  nop
    /* 3C654 8004BE54 040864AC */  sw         $a0, 0x804($v1)
    /* 3C658 8004BE58 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3C65C 8004BE5C 1000B08F */  lw         $s0, 0x10($sp)
    /* 3C660 8004BE60 01000224 */  addiu      $v0, $zero, 0x1
    /* 3C664 8004BE64 0800E003 */  jr         $ra
    /* 3C668 8004BE68 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004BCE8
