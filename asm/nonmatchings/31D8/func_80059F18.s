nonmatching func_80059F18, 0x94

glabel func_80059F18
    /* 4A718 80059F18 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4A71C 80059F1C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 4A720 80059F20 21988000 */  addu       $s3, $a0, $zero
    /* 4A724 80059F24 2000B4AF */  sw         $s4, 0x20($sp)
    /* 4A728 80059F28 21A0E000 */  addu       $s4, $a3, $zero
    /* 4A72C 80059F2C 1800B2AF */  sw         $s2, 0x18($sp)
    /* 4A730 80059F30 21900000 */  addu       $s2, $zero, $zero
    /* 4A734 80059F34 2400BFAF */  sw         $ra, 0x24($sp)
    /* 4A738 80059F38 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4A73C 80059F3C 0200A004 */  bltz       $a1, .L80059F48
    /* 4A740 80059F40 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4A744 80059F44 0100B224 */  addiu      $s2, $a1, 0x1
  .L80059F48:
    /* 4A748 80059F48 0200C004 */  bltz       $a2, .L80059F54
    /* 4A74C 80059F4C 21880000 */   addu      $s1, $zero, $zero
    /* 4A750 80059F50 0100D124 */  addiu      $s1, $a2, 0x1
  .L80059F54:
    /* 4A754 80059F54 5D7C010C */  jal        func_8005F174
    /* 4A758 80059F58 00000000 */   nop
    /* 4A75C 80059F5C 21804000 */  addu       $s0, $v0, $zero
    /* 4A760 80059F60 01000224 */  addiu      $v0, $zero, 0x1
    /* 4A764 80059F64 05000216 */  bne        $s0, $v0, .L80059F7C
    /* 4A768 80059F68 21206002 */   addu      $a0, $s3, $zero
    /* 4A76C 80059F6C 637C010C */  jal        func_8005F18C
    /* 4A770 80059F70 00000000 */   nop
    /* 4A774 80059F74 05005010 */  beq        $v0, $s0, .L80059F8C
    /* 4A778 80059F78 21206002 */   addu      $a0, $s3, $zero
  .L80059F7C:
    /* 4A77C 80059F7C 21284002 */  addu       $a1, $s2, $zero
    /* 4A780 80059F80 21302002 */  addu       $a2, $s1, $zero
    /* 4A784 80059F84 4B4B010C */  jal        func_80052D2C
    /* 4A788 80059F88 21388002 */   addu      $a3, $s4, $zero
  .L80059F8C:
    /* 4A78C 80059F8C 2400BF8F */  lw         $ra, 0x24($sp)
    /* 4A790 80059F90 2000B48F */  lw         $s4, 0x20($sp)
    /* 4A794 80059F94 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 4A798 80059F98 1800B28F */  lw         $s2, 0x18($sp)
    /* 4A79C 80059F9C 1400B18F */  lw         $s1, 0x14($sp)
    /* 4A7A0 80059FA0 1000B08F */  lw         $s0, 0x10($sp)
    /* 4A7A4 80059FA4 0800E003 */  jr         $ra
    /* 4A7A8 80059FA8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80059F18
