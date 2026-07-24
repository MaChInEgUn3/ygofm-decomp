nonmatching func_8003B5C8, 0xE4

glabel func_8003B5C8
    /* 2BDC8 8003B5C8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2BDCC 8003B5CC 0F80023C */  lui        $v0, %hi(D_800EAFF8)
    /* 2BDD0 8003B5D0 F8AF4924 */  addiu      $t1, $v0, %lo(D_800EAFF8)
    /* 2BDD4 8003B5D4 01000824 */  addiu      $t0, $zero, 0x1
    /* 2BDD8 8003B5D8 2138A003 */  addu       $a3, $sp, $zero
    /* 2BDDC 8003B5DC 1400AC27 */  addiu      $t4, $sp, 0x14
    /* 2BDE0 8003B5E0 1E800A3C */  lui        $t2, %hi(D_801D9004)
    /* 2BDE4 8003B5E4 04904B8D */  lw         $t3, %lo(D_801D9004)($t2)
    /* 2BDE8 8003B5E8 0180023C */  lui        $v0, %hi(D_80010330)
    /* 2BDEC 8003B5EC 30035824 */  addiu      $t8, $v0, %lo(D_80010330)
    /* 2BDF0 8003B5F0 03000D8B */  lwl        $t5, 0x3($t8)
    /* 2BDF4 8003B5F4 00000D9B */  lwr        $t5, 0x0($t8)
    /* 2BDF8 8003B5F8 07000E8B */  lwl        $t6, 0x7($t8)
    /* 2BDFC 8003B5FC 04000E9B */  lwr        $t6, 0x4($t8)
    /* 2BE00 8003B600 0B000F8B */  lwl        $t7, 0xB($t8)
    /* 2BE04 8003B604 08000F9B */  lwr        $t7, 0x8($t8)
    /* 2BE08 8003B608 0300ADAB */  swl        $t5, 0x3($sp)
    /* 2BE0C 8003B60C 0000ADBB */  swr        $t5, 0x0($sp)
    /* 2BE10 8003B610 0700AEAB */  swl        $t6, 0x7($sp)
    /* 2BE14 8003B614 0400AEBB */  swr        $t6, 0x4($sp)
    /* 2BE18 8003B618 0B00AFAB */  swl        $t7, 0xB($sp)
    /* 2BE1C 8003B61C 0800AFBB */  swr        $t7, 0x8($sp)
    /* 2BE20 8003B620 0F000D8B */  lwl        $t5, 0xF($t8)
    /* 2BE24 8003B624 0C000D9B */  lwr        $t5, 0xC($t8)
    /* 2BE28 8003B628 13000E8B */  lwl        $t6, 0x13($t8)
    /* 2BE2C 8003B62C 10000E9B */  lwr        $t6, 0x10($t8)
    /* 2BE30 8003B630 0F00ADAB */  swl        $t5, 0xF($sp)
    /* 2BE34 8003B634 0C00ADBB */  swr        $t5, 0xC($sp)
    /* 2BE38 8003B638 1300AEAB */  swl        $t6, 0x13($sp)
    /* 2BE3C 8003B63C 1000AEBB */  swr        $t6, 0x10($sp)
  .L8003B640:
    /* 2BE40 8003B640 04904425 */  addiu      $a0, $t2, %lo(D_801D9004)
    /* 2BE44 8003B644 01000524 */  addiu      $a1, $zero, 0x1
    /* 2BE48 8003B648 2110A803 */  addu       $v0, $sp, $t0
    /* 2BE4C 8003B64C 0000E390 */  lbu        $v1, 0x0($a3)
    /* 2BE50 8003B650 00004290 */  lbu        $v0, 0x0($v0)
    /* 2BE54 8003B654 001A0300 */  sll        $v1, $v1, 8
    /* 2BE58 8003B658 0D006011 */  beqz       $t3, .L8003B690
    /* 2BE5C 8003B65C 25186200 */   or        $v1, $v1, $v0
    /* 2BE60 8003B660 21302001 */  addu       $a2, $t1, $zero
  .L8003B664:
    /* 2BE64 8003B664 00008294 */  lhu        $v0, 0x0($a0)
    /* 2BE68 8003B668 00000000 */  nop
    /* 2BE6C 8003B66C 03006214 */  bne        $v1, $v0, .L8003B67C
    /* 2BE70 8003B670 00000000 */   nop
    /* 2BE74 8003B674 A4ED0008 */  j          .L8003B690
    /* 2BE78 8003B678 0000C5A4 */   sh        $a1, 0x0($a2)
  .L8003B67C:
    /* 2BE7C 8003B67C 04008424 */  addiu      $a0, $a0, 0x4
    /* 2BE80 8003B680 0000828C */  lw         $v0, 0x0($a0)
    /* 2BE84 8003B684 00000000 */  nop
    /* 2BE88 8003B688 F6FF4014 */  bnez       $v0, .L8003B664
    /* 2BE8C 8003B68C 0100A524 */   addiu     $a1, $a1, 0x1
  .L8003B690:
    /* 2BE90 8003B690 02002925 */  addiu      $t1, $t1, 0x2
    /* 2BE94 8003B694 0200E724 */  addiu      $a3, $a3, 0x2
    /* 2BE98 8003B698 2A10EC00 */  slt        $v0, $a3, $t4
    /* 2BE9C 8003B69C E8FF4014 */  bnez       $v0, .L8003B640
    /* 2BEA0 8003B6A0 02000825 */   addiu     $t0, $t0, 0x2
    /* 2BEA4 8003B6A4 0800E003 */  jr         $ra
    /* 2BEA8 8003B6A8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003B5C8
