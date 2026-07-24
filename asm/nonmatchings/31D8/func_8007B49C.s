nonmatching func_8007B49C, 0x3A0

glabel func_8007B49C
    /* 6BC9C 8007B49C 78FFBD27 */  addiu      $sp, $sp, -0x88
    /* 6BCA0 8007B4A0 6C00B3AF */  sw         $s3, 0x6C($sp)
    /* 6BCA4 8007B4A4 2198A000 */  addu       $s3, $a1, $zero
    /* 6BCA8 8007B4A8 7400B5AF */  sw         $s5, 0x74($sp)
    /* 6BCAC 8007B4AC 21A8E000 */  addu       $s5, $a3, $zero
    /* 6BCB0 8007B4B0 21288000 */  addu       $a1, $a0, $zero
    /* 6BCB4 8007B4B4 6800B2AF */  sw         $s2, 0x68($sp)
    /* 6BCB8 8007B4B8 2190C000 */  addu       $s2, $a2, $zero
    /* 6BCBC 8007B4BC 6000B0AF */  sw         $s0, 0x60($sp)
    /* 6BCC0 8007B4C0 21800000 */  addu       $s0, $zero, $zero
    /* 6BCC4 8007B4C4 7C00B7AF */  sw         $s7, 0x7C($sp)
    /* 6BCC8 8007B4C8 9800B78F */  lw         $s7, 0x98($sp)
    /* 6BCCC 8007B4CC 9C00A48F */  lw         $a0, 0x9C($sp)
    /* 6BCD0 8007B4D0 1000A327 */  addiu      $v1, $sp, 0x10
    /* 6BCD4 8007B4D4 8000BFAF */  sw         $ra, 0x80($sp)
    /* 6BCD8 8007B4D8 7800B6AF */  sw         $s6, 0x78($sp)
    /* 6BCDC 8007B4DC 7000B4AF */  sw         $s4, 0x70($sp)
    /* 6BCE0 8007B4E0 6400B1AF */  sw         $s1, 0x64($sp)
  .L8007B4E4:
    /* 6BCE4 8007B4E4 000060A0 */  sb         $zero, 0x0($v1)
    /* 6BCE8 8007B4E8 080060AC */  sw         $zero, 0x8($v1)
    /* 6BCEC 8007B4EC 0C0060AC */  sw         $zero, 0xC($v1)
    /* 6BCF0 8007B4F0 01001026 */  addiu      $s0, $s0, 0x1
    /* 6BCF4 8007B4F4 0500022A */  slti       $v0, $s0, 0x5
    /* 6BCF8 8007B4F8 FAFF4014 */  bnez       $v0, .L8007B4E4
    /* 6BCFC 8007B4FC 10006324 */   addiu     $v1, $v1, 0x10
    /* 6BD00 8007B500 04008010 */  beqz       $a0, .L8007B514
    /* 6BD04 8007B504 21800000 */   addu      $s0, $zero, $zero
    /* 6BD08 8007B508 09000224 */  addiu      $v0, $zero, 0x9
    /* 6BD0C 8007B50C 1000A2A3 */  sb         $v0, 0x10($sp)
    /* 6BD10 8007B510 01001024 */  addiu      $s0, $zero, 0x1
  .L8007B514:
    /* 6BD14 8007B514 00111000 */  sll        $v0, $s0, 4
    /* 6BD18 8007B518 01001026 */  addiu      $s0, $s0, 0x1
    /* 6BD1C 8007B51C 21206002 */  addu       $a0, $s3, $zero
    /* 6BD20 8007B520 1000B127 */  addiu      $s1, $sp, 0x10
    /* 6BD24 8007B524 21102202 */  addu       $v0, $s1, $v0
    /* 6BD28 8007B528 0E000324 */  addiu      $v1, $zero, 0xE
    /* 6BD2C 8007B52C 000043A0 */  sb         $v1, 0x0($v0)
    /* 6BD30 8007B530 01004324 */  addiu      $v1, $v0, 0x1
    /* 6BD34 8007B534 010045A0 */  sb         $a1, 0x1($v0)
    /* 6BD38 8007B538 C4F9010C */  jal        func_8007E710
    /* 6BD3C 8007B53C 080043AC */   sw        $v1, 0x8($v0)
    /* 6BD40 8007B540 B2004004 */  bltz       $v0, .L8007B80C
    /* 6BD44 8007B544 00111000 */   sll       $v0, $s0, 4
    /* 6BD48 8007B548 21102202 */  addu       $v0, $s1, $v0
    /* 6BD4C 8007B54C 02000324 */  addiu      $v1, $zero, 0x2
    /* 6BD50 8007B550 000043A0 */  sb         $v1, 0x0($v0)
    /* 6BD54 8007B554 0300638A */  lwl        $v1, 0x3($s3)
    /* 6BD58 8007B558 0000639A */  lwr        $v1, 0x0($s3)
    /* 6BD5C 8007B55C 00000000 */  nop
    /* 6BD60 8007B560 040043A8 */  swl        $v1, 0x4($v0)
    /* 6BD64 8007B564 010043B8 */  swr        $v1, 0x1($v0)
    /* 6BD68 8007B568 01004324 */  addiu      $v1, $v0, 0x1
    /* 6BD6C 8007B56C 080043AC */  sw         $v1, 0x8($v0)
    /* 6BD70 8007B570 FF004232 */  andi       $v0, $s2, 0xFF
    /* 6BD74 8007B574 FDFF4324 */  addiu      $v1, $v0, -0x3
    /* 6BD78 8007B578 1900622C */  sltiu      $v0, $v1, 0x19
    /* 6BD7C 8007B57C A3004010 */  beqz       $v0, .L8007B80C
    /* 6BD80 8007B580 01001026 */   addiu     $s0, $s0, 0x1
    /* 6BD84 8007B584 80100300 */  sll        $v0, $v1, 2
    /* 6BD88 8007B588 0180013C */  lui        $at, %hi(jtbl_80011DD8)
    /* 6BD8C 8007B58C 21082200 */  addu       $at, $at, $v0
    /* 6BD90 8007B590 D81D228C */  lw         $v0, %lo(jtbl_80011DD8)($at)
    /* 6BD94 8007B594 00000000 */  nop
    /* 6BD98 8007B598 08004000 */  jr         $v0
    /* 6BD9C 8007B59C 00000000 */   nop
  jlabel .L8007B5A0
    /* 6BDA0 8007B5A0 1000A227 */  addiu      $v0, $sp, 0x10
    /* 6BDA4 8007B5A4 21A04000 */  addu       $s4, $v0, $zero
    /* 6BDA8 8007B5A8 00111000 */  sll        $v0, $s0, 4
    /* 6BDAC 8007B5AC 21108202 */  addu       $v0, $s4, $v0
    /* 6BDB0 8007B5B0 000052A0 */  sb         $s2, 0x0($v0)
    /* 6BDB4 8007B5B4 0C0055AC */  sw         $s5, 0xC($v0)
    /* 6BDB8 8007B5B8 0F80023C */  lui        $v0, %hi(D_800F5EE8)
    /* 6BDBC 8007B5BC E85E428C */  lw         $v0, %lo(D_800F5EE8)($v0)
    /* 6BDC0 8007B5C0 01001626 */  addiu      $s6, $s0, 0x1
    /* 6BDC4 8007B5C4 21105600 */  addu       $v0, $v0, $s6
    /* 6BDC8 8007B5C8 09004228 */  slti       $v0, $v0, 0x9
    /* 6BDCC 8007B5CC 90004010 */  beqz       $v0, .L8007B810
    /* 6BDD0 8007B5D0 21100000 */   addu      $v0, $zero, $zero
    /* 6BDD4 8007B5D4 0980033C */  lui        $v1, %hi(D_80093868)
    /* 6BDD8 8007B5D8 6838638C */  lw         $v1, %lo(D_80093868)($v1)
    /* 6BDDC 8007B5DC 00000000 */  nop
    /* 6BDE0 8007B5E0 01006224 */  addiu      $v0, $v1, 0x1
    /* 6BDE4 8007B5E4 0980013C */  lui        $at, %hi(D_80093868)
    /* 6BDE8 8007B5E8 683822AC */  sw         $v0, %lo(D_80093868)($at)
    /* 6BDEC 8007B5EC 05004014 */  bnez       $v0, .L8007B604
    /* 6BDF0 8007B5F0 21A84000 */   addu      $s5, $v0, $zero
    /* 6BDF4 8007B5F4 02006224 */  addiu      $v0, $v1, 0x2
    /* 6BDF8 8007B5F8 0980013C */  lui        $at, %hi(D_80093868)
    /* 6BDFC 8007B5FC 683822AC */  sw         $v0, %lo(D_80093868)($at)
    /* 6BE00 8007B600 21A84000 */  addu       $s5, $v0, $zero
  .L8007B604:
    /* 6BE04 8007B604 6C00C01A */  blez       $s6, .L8007B7B8
    /* 6BE08 8007B608 21980000 */   addu      $s3, $zero, $zero
    /* 6BE0C 8007B60C 0C009226 */  addiu      $s2, $s4, 0xC
  .L8007B610:
    /* 6BE10 8007B610 83EA010C */  jal        func_8007AA0C
    /* 6BE14 8007B614 00000000 */   nop
    /* 6BE18 8007B618 21884000 */  addu       $s1, $v0, $zero
    /* 6BE1C 8007B61C 7C002012 */  beqz       $s1, .L8007B810
    /* 6BE20 8007B620 21100000 */   addu      $v0, $zero, $zero
    /* 6BE24 8007B624 000035AE */  sw         $s5, 0x0($s1)
    /* 6BE28 8007B628 00008292 */  lbu        $v0, 0x0($s4)
    /* 6BE2C 8007B62C 00000000 */  nop
    /* 6BE30 8007B630 040022A2 */  sb         $v0, 0x4($s1)
    /* 6BE34 8007B634 FCFF428E */  lw         $v0, -0x4($s2)
    /* 6BE38 8007B638 00000000 */  nop
    /* 6BE3C 8007B63C 06004010 */  beqz       $v0, .L8007B658
    /* 6BE40 8007B640 05003026 */   addiu     $s0, $s1, 0x5
    /* 6BE44 8007B644 21200002 */  addu       $a0, $s0, $zero
    /* 6BE48 8007B648 49F3010C */  jal        func_8007CD24
    /* 6BE4C 8007B64C 01008526 */   addiu     $a1, $s4, 0x1
    /* 6BE50 8007B650 97ED0108 */  j          .L8007B65C
    /* 6BE54 8007B654 0C0030AE */   sw        $s0, 0xC($s1)
  .L8007B658:
    /* 6BE58 8007B658 0C0020AE */  sw         $zero, 0xC($s1)
  .L8007B65C:
    /* 6BE5C 8007B65C 0000428E */  lw         $v0, 0x0($s2)
    /* 6BE60 8007B660 10005226 */  addiu      $s2, $s2, 0x10
    /* 6BE64 8007B664 10009426 */  addiu      $s4, $s4, 0x10
    /* 6BE68 8007B668 21200000 */  addu       $a0, $zero, $zero
    /* 6BE6C 8007B66C 01007326 */  addiu      $s3, $s3, 0x1
    /* 6BE70 8007B670 140037AE */  sw         $s7, 0x14($s1)
    /* 6BE74 8007B674 43D1010C */  jal        func_8007450C
    /* 6BE78 8007B678 100022AE */   sw        $v0, 0x10($s1)
    /* 6BE7C 8007B67C 0F80033C */  lui        $v1, %hi(D_800F5EE8)
    /* 6BE80 8007B680 E85E638C */  lw         $v1, %lo(D_800F5EE8)($v1)
    /* 6BE84 8007B684 00000000 */  nop
    /* 6BE88 8007B688 01006324 */  addiu      $v1, $v1, 0x1
    /* 6BE8C 8007B68C 0F80013C */  lui        $at, %hi(D_800F5EE8)
    /* 6BE90 8007B690 E85E23AC */  sw         $v1, %lo(D_800F5EE8)($at)
    /* 6BE94 8007B694 43D1010C */  jal        func_8007450C
    /* 6BE98 8007B698 21204000 */   addu      $a0, $v0, $zero
    /* 6BE9C 8007B69C 2A107602 */  slt        $v0, $s3, $s6
    /* 6BEA0 8007B6A0 45004010 */  beqz       $v0, .L8007B7B8
    /* 6BEA4 8007B6A4 00000000 */   nop
    /* 6BEA8 8007B6A8 84ED0108 */  j          .L8007B610
    /* 6BEAC 8007B6AC 00000000 */   nop
  jlabel .L8007B6B0
    /* 6BEB0 8007B6B0 1000A227 */  addiu      $v0, $sp, 0x10
    /* 6BEB4 8007B6B4 21A04000 */  addu       $s4, $v0, $zero
    /* 6BEB8 8007B6B8 00111000 */  sll        $v0, $s0, 4
    /* 6BEBC 8007B6BC 21108202 */  addu       $v0, $s4, $v0
    /* 6BEC0 8007B6C0 000052A0 */  sb         $s2, 0x0($v0)
    /* 6BEC4 8007B6C4 0C0055AC */  sw         $s5, 0xC($v0)
    /* 6BEC8 8007B6C8 0F80023C */  lui        $v0, %hi(D_800F5EE8)
    /* 6BECC 8007B6CC E85E428C */  lw         $v0, %lo(D_800F5EE8)($v0)
    /* 6BED0 8007B6D0 01001626 */  addiu      $s6, $s0, 0x1
    /* 6BED4 8007B6D4 21105600 */  addu       $v0, $v0, $s6
    /* 6BED8 8007B6D8 09004228 */  slti       $v0, $v0, 0x9
    /* 6BEDC 8007B6DC 4C004010 */  beqz       $v0, .L8007B810
    /* 6BEE0 8007B6E0 21100000 */   addu      $v0, $zero, $zero
    /* 6BEE4 8007B6E4 0980033C */  lui        $v1, %hi(D_80093868)
    /* 6BEE8 8007B6E8 6838638C */  lw         $v1, %lo(D_80093868)($v1)
    /* 6BEEC 8007B6EC 00000000 */  nop
    /* 6BEF0 8007B6F0 01006224 */  addiu      $v0, $v1, 0x1
    /* 6BEF4 8007B6F4 0980013C */  lui        $at, %hi(D_80093868)
    /* 6BEF8 8007B6F8 683822AC */  sw         $v0, %lo(D_80093868)($at)
    /* 6BEFC 8007B6FC 05004014 */  bnez       $v0, .L8007B714
    /* 6BF00 8007B700 21A84000 */   addu      $s5, $v0, $zero
    /* 6BF04 8007B704 02006224 */  addiu      $v0, $v1, 0x2
    /* 6BF08 8007B708 0980013C */  lui        $at, %hi(D_80093868)
    /* 6BF0C 8007B70C 683822AC */  sw         $v0, %lo(D_80093868)($at)
    /* 6BF10 8007B710 21A84000 */  addu       $s5, $v0, $zero
  .L8007B714:
    /* 6BF14 8007B714 2800C01A */  blez       $s6, .L8007B7B8
    /* 6BF18 8007B718 21980000 */   addu      $s3, $zero, $zero
    /* 6BF1C 8007B71C 0C009226 */  addiu      $s2, $s4, 0xC
  .L8007B720:
    /* 6BF20 8007B720 83EA010C */  jal        func_8007AA0C
    /* 6BF24 8007B724 00000000 */   nop
    /* 6BF28 8007B728 21884000 */  addu       $s1, $v0, $zero
    /* 6BF2C 8007B72C 38002012 */  beqz       $s1, .L8007B810
    /* 6BF30 8007B730 21100000 */   addu      $v0, $zero, $zero
    /* 6BF34 8007B734 000035AE */  sw         $s5, 0x0($s1)
    /* 6BF38 8007B738 00008292 */  lbu        $v0, 0x0($s4)
    /* 6BF3C 8007B73C 00000000 */  nop
    /* 6BF40 8007B740 040022A2 */  sb         $v0, 0x4($s1)
    /* 6BF44 8007B744 FCFF428E */  lw         $v0, -0x4($s2)
    /* 6BF48 8007B748 00000000 */  nop
    /* 6BF4C 8007B74C 06004010 */  beqz       $v0, .L8007B768
    /* 6BF50 8007B750 05003026 */   addiu     $s0, $s1, 0x5
    /* 6BF54 8007B754 21200002 */  addu       $a0, $s0, $zero
    /* 6BF58 8007B758 49F3010C */  jal        func_8007CD24
    /* 6BF5C 8007B75C 01008526 */   addiu     $a1, $s4, 0x1
    /* 6BF60 8007B760 DBED0108 */  j          .L8007B76C
    /* 6BF64 8007B764 0C0030AE */   sw        $s0, 0xC($s1)
  .L8007B768:
    /* 6BF68 8007B768 0C0020AE */  sw         $zero, 0xC($s1)
  .L8007B76C:
    /* 6BF6C 8007B76C 0000428E */  lw         $v0, 0x0($s2)
    /* 6BF70 8007B770 10005226 */  addiu      $s2, $s2, 0x10
    /* 6BF74 8007B774 10009426 */  addiu      $s4, $s4, 0x10
    /* 6BF78 8007B778 21200000 */  addu       $a0, $zero, $zero
    /* 6BF7C 8007B77C 01007326 */  addiu      $s3, $s3, 0x1
    /* 6BF80 8007B780 140037AE */  sw         $s7, 0x14($s1)
    /* 6BF84 8007B784 43D1010C */  jal        func_8007450C
    /* 6BF88 8007B788 100022AE */   sw        $v0, 0x10($s1)
    /* 6BF8C 8007B78C 0F80033C */  lui        $v1, %hi(D_800F5EE8)
    /* 6BF90 8007B790 E85E638C */  lw         $v1, %lo(D_800F5EE8)($v1)
    /* 6BF94 8007B794 00000000 */  nop
    /* 6BF98 8007B798 01006324 */  addiu      $v1, $v1, 0x1
    /* 6BF9C 8007B79C 0F80013C */  lui        $at, %hi(D_800F5EE8)
    /* 6BFA0 8007B7A0 E85E23AC */  sw         $v1, %lo(D_800F5EE8)($at)
    /* 6BFA4 8007B7A4 43D1010C */  jal        func_8007450C
    /* 6BFA8 8007B7A8 21204000 */   addu      $a0, $v0, $zero
    /* 6BFAC 8007B7AC 2A107602 */  slt        $v0, $s3, $s6
    /* 6BFB0 8007B7B0 DBFF4014 */  bnez       $v0, .L8007B720
    /* 6BFB4 8007B7B4 00000000 */   nop
  .L8007B7B8:
    /* 6BFB8 8007B7B8 BBEF010C */  jal        func_8007BEEC
    /* 6BFBC 8007B7BC 21200000 */   addu      $a0, $zero, $zero
    /* 6BFC0 8007B7C0 01000324 */  addiu      $v1, $zero, 0x1
    /* 6BFC4 8007B7C4 12004314 */  bne        $v0, $v1, .L8007B810
    /* 6BFC8 8007B7C8 2110A002 */   addu      $v0, $s5, $zero
    /* 6BFCC 8007B7CC 0F80023C */  lui        $v0, %hi(D_800F5EE4)
    /* 6BFD0 8007B7D0 E45E428C */  lw         $v0, %lo(D_800F5EE4)($v0)
    /* 6BFD4 8007B7D4 00000000 */  nop
    /* 6BFD8 8007B7D8 40180200 */  sll        $v1, $v0, 1
    /* 6BFDC 8007B7DC 21186200 */  addu       $v1, $v1, $v0
    /* 6BFE0 8007B7E0 C0180300 */  sll        $v1, $v1, 3
    /* 6BFE4 8007B7E4 0F80023C */  lui        $v0, %hi(D_800F5E20)
    /* 6BFE8 8007B7E8 21104300 */  addu       $v0, $v0, $v1
    /* 6BFEC 8007B7EC 205E428C */  lw         $v0, %lo(D_800F5E20)($v0)
    /* 6BFF0 8007B7F0 00000000 */  nop
    /* 6BFF4 8007B7F4 06005514 */  bne        $v0, $s5, .L8007B810
    /* 6BFF8 8007B7F8 2110A002 */   addu      $v0, $s5, $zero
    /* 6BFFC 8007B7FC 21EB010C */  jal        func_8007AC84
    /* 6C000 8007B800 00000000 */   nop
    /* 6C004 8007B804 04EE0108 */  j          .L8007B810
    /* 6C008 8007B808 2110A002 */   addu      $v0, $s5, $zero
  jlabel .L8007B80C
    /* 6C00C 8007B80C 21100000 */  addu       $v0, $zero, $zero
  .L8007B810:
    /* 6C010 8007B810 8000BF8F */  lw         $ra, 0x80($sp)
    /* 6C014 8007B814 7C00B78F */  lw         $s7, 0x7C($sp)
    /* 6C018 8007B818 7800B68F */  lw         $s6, 0x78($sp)
    /* 6C01C 8007B81C 7400B58F */  lw         $s5, 0x74($sp)
    /* 6C020 8007B820 7000B48F */  lw         $s4, 0x70($sp)
    /* 6C024 8007B824 6C00B38F */  lw         $s3, 0x6C($sp)
    /* 6C028 8007B828 6800B28F */  lw         $s2, 0x68($sp)
    /* 6C02C 8007B82C 6400B18F */  lw         $s1, 0x64($sp)
    /* 6C030 8007B830 6000B08F */  lw         $s0, 0x60($sp)
    /* 6C034 8007B834 0800E003 */  jr         $ra
    /* 6C038 8007B838 8800BD27 */   addiu     $sp, $sp, 0x88
endlabel func_8007B49C
