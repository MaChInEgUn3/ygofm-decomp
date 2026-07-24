nonmatching func_8004B49C, 0x24C

glabel func_8004B49C
    /* 3BC9C 8004B49C D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3BCA0 8004B4A0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3BCA4 8004B4A4 21908000 */  addu       $s2, $a0, $zero
    /* 3BCA8 8004B4A8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3BCAC 8004B4AC 21800000 */  addu       $s0, $zero, $zero
    /* 3BCB0 8004B4B0 2140C000 */  addu       $t0, $a2, $zero
    /* 3BCB4 8004B4B4 FF004732 */  andi       $a3, $s2, 0xFF
    /* 3BCB8 8004B4B8 40100700 */  sll        $v0, $a3, 1
    /* 3BCBC 8004B4BC 21104700 */  addu       $v0, $v0, $a3
    /* 3BCC0 8004B4C0 C0100200 */  sll        $v0, $v0, 3
    /* 3BCC4 8004B4C4 FF00A530 */  andi       $a1, $a1, 0xFF
    /* 3BCC8 8004B4C8 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3BCCC 8004B4CC 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3BCD0 8004B4D0 1E000924 */  addiu      $t1, $zero, 0x1E
    /* 3BCD4 8004B4D4 2400BFAF */  sw         $ra, 0x24($sp)
    /* 3BCD8 8004B4D8 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3BCDC 8004B4DC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3BCE0 8004B4E0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3BCE4 8004B4E4 3900A910 */  beq        $a1, $t1, .L8004B5CC
    /* 3BCE8 8004B4E8 21206200 */   addu      $a0, $v1, $v0
    /* 3BCEC 8004B4EC 1F00A228 */  slti       $v0, $a1, 0x1F
    /* 3BCF0 8004B4F0 10004010 */  beqz       $v0, .L8004B534
    /* 3BCF4 8004B4F4 07000224 */   addiu     $v0, $zero, 0x7
    /* 3BCF8 8004B4F8 2800A210 */  beq        $a1, $v0, .L8004B59C
    /* 3BCFC 8004B4FC 0800A228 */   slti      $v0, $a1, 0x8
    /* 3BD00 8004B500 05004010 */  beqz       $v0, .L8004B518
    /* 3BD04 8004B504 06000224 */   addiu     $v0, $zero, 0x6
    /* 3BD08 8004B508 1A00A210 */  beq        $a1, $v0, .L8004B574
    /* 3BD0C 8004B50C FF000232 */   andi      $v0, $s0, 0xFF
    /* 3BD10 8004B510 862D0108 */  j          .L8004B618
    /* 3BD14 8004B514 00000000 */   nop
  .L8004B518:
    /* 3BD18 8004B518 0A000224 */  addiu      $v0, $zero, 0xA
    /* 3BD1C 8004B51C 2200A210 */  beq        $a1, $v0, .L8004B5A8
    /* 3BD20 8004B520 0B000224 */   addiu     $v0, $zero, 0xB
    /* 3BD24 8004B524 2700A210 */  beq        $a1, $v0, .L8004B5C4
    /* 3BD28 8004B528 FF000232 */   andi      $v0, $s0, 0xFF
    /* 3BD2C 8004B52C 862D0108 */  j          .L8004B618
    /* 3BD30 8004B530 00000000 */   nop
  .L8004B534:
    /* 3BD34 8004B534 62000224 */  addiu      $v0, $zero, 0x62
    /* 3BD38 8004B538 3300A210 */  beq        $a1, $v0, .L8004B608
    /* 3BD3C 8004B53C 6300A228 */   slti      $v0, $a1, 0x63
    /* 3BD40 8004B540 07004010 */  beqz       $v0, .L8004B560
    /* 3BD44 8004B544 30000224 */   addiu     $v0, $zero, 0x30
    /* 3BD48 8004B548 2500A210 */  beq        $a1, $v0, .L8004B5E0
    /* 3BD4C 8004B54C 5B000224 */   addiu     $v0, $zero, 0x5B
    /* 3BD50 8004B550 2A00A210 */  beq        $a1, $v0, .L8004B5FC
    /* 3BD54 8004B554 FF000232 */   andi      $v0, $s0, 0xFF
    /* 3BD58 8004B558 862D0108 */  j          .L8004B618
    /* 3BD5C 8004B55C 00000000 */   nop
  .L8004B560:
    /* 3BD60 8004B560 63000224 */  addiu      $v0, $zero, 0x63
    /* 3BD64 8004B564 2A00A210 */  beq        $a1, $v0, .L8004B610
    /* 3BD68 8004B568 FF000232 */   andi      $v0, $s0, 0xFF
    /* 3BD6C 8004B56C 862D0108 */  j          .L8004B618
    /* 3BD70 8004B570 00000000 */   nop
  .L8004B574:
    /* 3BD74 8004B574 12008390 */  lbu        $v1, 0x12($a0)
    /* 3BD78 8004B578 14000224 */  addiu      $v0, $zero, 0x14
    /* 3BD7C 8004B57C 25006210 */  beq        $v1, $v0, .L8004B614
    /* 3BD80 8004B580 130086A0 */   sb        $a2, 0x13($a0)
    /* 3BD84 8004B584 24006910 */  beq        $v1, $t1, .L8004B618
    /* 3BD88 8004B588 FF000232 */   andi      $v0, $s0, 0xFF
    /* 3BD8C 8004B58C 392B010C */  jal        func_8004ACE4
    /* 3BD90 8004B590 2128E000 */   addu      $a1, $a3, $zero
    /* 3BD94 8004B594 862D0108 */  j          .L8004B618
    /* 3BD98 8004B598 FF000232 */   andi      $v0, $s0, 0xFF
  .L8004B59C:
    /* 3BD9C 8004B59C 030086A0 */  sb         $a2, 0x3($a0)
  .L8004B5A0:
    /* 3BDA0 8004B5A0 852D0108 */  j          .L8004B614
    /* 3BDA4 8004B5A4 01001024 */   addiu     $s0, $zero, 0x1
  .L8004B5A8:
    /* 3BDA8 8004B5A8 FF000231 */  andi       $v0, $t0, 0xFF
    /* 3BDAC 8004B5AC 03004010 */  beqz       $v0, .L8004B5BC
    /* 3BDB0 8004B5B0 01000224 */   addiu     $v0, $zero, 0x1
    /* 3BDB4 8004B5B4 682D0108 */  j          .L8004B5A0
    /* 3BDB8 8004B5B8 010086A0 */   sb        $a2, 0x1($a0)
  .L8004B5BC:
    /* 3BDBC 8004B5BC 682D0108 */  j          .L8004B5A0
    /* 3BDC0 8004B5C0 010082A0 */   sb        $v0, 0x1($a0)
  .L8004B5C4:
    /* 3BDC4 8004B5C4 682D0108 */  j          .L8004B5A0
    /* 3BDC8 8004B5C8 050086A0 */   sb        $a2, 0x5($a0)
  .L8004B5CC:
    /* 3BDCC 8004B5CC FF000231 */  andi       $v0, $t0, 0xFF
    /* 3BDD0 8004B5D0 BE28010C */  jal        func_8004A2F8
    /* 3BDD4 8004B5D4 120562A4 */   sh        $v0, 0x512($v1)
    /* 3BDD8 8004B5D8 862D0108 */  j          .L8004B618
    /* 3BDDC 8004B5DC FF000232 */   andi      $v0, $s0, 0xFF
  .L8004B5E0:
    /* 3BDE0 8004B5E0 0F00C230 */  andi       $v0, $a2, 0xF
    /* 3BDE4 8004B5E4 06008390 */  lbu        $v1, 0x6($a0)
    /* 3BDE8 8004B5E8 00110200 */  sll        $v0, $v0, 4
    /* 3BDEC 8004B5EC 0F006330 */  andi       $v1, $v1, 0xF
    /* 3BDF0 8004B5F0 25186200 */  or         $v1, $v1, $v0
    /* 3BDF4 8004B5F4 852D0108 */  j          .L8004B614
    /* 3BDF8 8004B5F8 060083A0 */   sb        $v1, 0x6($a0)
  .L8004B5FC:
    /* 3BDFC 8004B5FC 7F00C230 */  andi       $v0, $a2, 0x7F
    /* 3BE00 8004B600 852D0108 */  j          .L8004B614
    /* 3BE04 8004B604 100082A0 */   sb        $v0, 0x10($a0)
  .L8004B608:
    /* 3BE08 8004B608 852D0108 */  j          .L8004B614
    /* 3BE0C 8004B60C 110086A0 */   sb        $a2, 0x11($a0)
  .L8004B610:
    /* 3BE10 8004B610 120086A0 */  sb         $a2, 0x12($a0)
  .L8004B614:
    /* 3BE14 8004B614 FF000232 */  andi       $v0, $s0, 0xFF
  .L8004B618:
    /* 3BE18 8004B618 2B004010 */  beqz       $v0, .L8004B6C8
    /* 3BE1C 8004B61C 00000000 */   nop
    /* 3BE20 8004B620 0A80053C */  lui        $a1, %hi(D_8009B458)
    /* 3BE24 8004B624 58B4A58C */  lw         $a1, %lo(D_8009B458)($a1)
    /* 3BE28 8004B628 00000000 */  nop
    /* 3BE2C 8004B62C 1005A284 */  lh         $v0, 0x510($a1)
    /* 3BE30 8004B630 00000000 */  nop
    /* 3BE34 8004B634 24004018 */  blez       $v0, .L8004B6C8
    /* 3BE38 8004B638 21880000 */   addu      $s1, $zero, $zero
    /* 3BE3C 8004B63C FF005332 */  andi       $s3, $s2, 0xFF
    /* 3BE40 8004B640 40101300 */  sll        $v0, $s3, 1
    /* 3BE44 8004B644 21105300 */  addu       $v0, $v0, $s3
    /* 3BE48 8004B648 C0A00200 */  sll        $s4, $v0, 3
    /* 3BE4C 8004B64C 80011224 */  addiu      $s2, $zero, 0x180
    /* 3BE50 8004B650 21802002 */  addu       $s0, $s1, $zero
  .L8004B654:
    /* 3BE54 8004B654 2118B000 */  addu       $v1, $a1, $s0
    /* 3BE58 8004B658 83016290 */  lbu        $v0, 0x183($v1)
    /* 3BE5C 8004B65C 00000000 */  nop
    /* 3BE60 8004B660 10006216 */  bne        $s3, $v0, .L8004B6A4
    /* 3BE64 8004B664 00000000 */   nop
    /* 3BE68 8004B668 8D016290 */  lbu        $v0, 0x18D($v1)
    /* 3BE6C 8004B66C 00000000 */  nop
    /* 3BE70 8004B670 0C004010 */  beqz       $v0, .L8004B6A4
    /* 3BE74 8004B674 00000000 */   nop
    /* 3BE78 8004B678 2120B200 */  addu       $a0, $a1, $s2
    /* 3BE7C 8004B67C 3F28010C */  jal        func_8004A0FC
    /* 3BE80 8004B680 2128B400 */   addu      $a1, $a1, $s4
    /* 3BE84 8004B684 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3BE88 8004B688 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3BE8C 8004B68C 00000000 */  nop
    /* 3BE90 8004B690 21105000 */  addu       $v0, $v0, $s0
    /* 3BE94 8004B694 94014594 */  lhu        $a1, 0x194($v0)
    /* 3BE98 8004B698 96014694 */  lhu        $a2, 0x196($v0)
    /* 3BE9C 8004B69C 9F28010C */  jal        func_8004A27C
    /* 3BEA0 8004B6A0 21202002 */   addu      $a0, $s1, $zero
  .L8004B6A4:
    /* 3BEA4 8004B6A4 28005226 */  addiu      $s2, $s2, 0x28
    /* 3BEA8 8004B6A8 0A80053C */  lui        $a1, %hi(D_8009B458)
    /* 3BEAC 8004B6AC 58B4A58C */  lw         $a1, %lo(D_8009B458)($a1)
    /* 3BEB0 8004B6B0 00000000 */  nop
    /* 3BEB4 8004B6B4 1005A284 */  lh         $v0, 0x510($a1)
    /* 3BEB8 8004B6B8 01003126 */  addiu      $s1, $s1, 0x1
    /* 3BEBC 8004B6BC 2A102202 */  slt        $v0, $s1, $v0
    /* 3BEC0 8004B6C0 E4FF4014 */  bnez       $v0, .L8004B654
    /* 3BEC4 8004B6C4 28001026 */   addiu     $s0, $s0, 0x28
  .L8004B6C8:
    /* 3BEC8 8004B6C8 2400BF8F */  lw         $ra, 0x24($sp)
    /* 3BECC 8004B6CC 2000B48F */  lw         $s4, 0x20($sp)
    /* 3BED0 8004B6D0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3BED4 8004B6D4 1800B28F */  lw         $s2, 0x18($sp)
    /* 3BED8 8004B6D8 1400B18F */  lw         $s1, 0x14($sp)
    /* 3BEDC 8004B6DC 1000B08F */  lw         $s0, 0x10($sp)
    /* 3BEE0 8004B6E0 0800E003 */  jr         $ra
    /* 3BEE4 8004B6E4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8004B49C
