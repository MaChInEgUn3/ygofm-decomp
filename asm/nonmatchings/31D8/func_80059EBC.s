nonmatching func_80059EBC, 0x5C

glabel func_80059EBC
    /* 4A6BC 80059EBC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4A6C0 80059EC0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4A6C4 80059EC4 21888000 */  addu       $s1, $a0, $zero
    /* 4A6C8 80059EC8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4A6CC 80059ECC 5D7C010C */  jal        func_8005F174
    /* 4A6D0 80059ED0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4A6D4 80059ED4 21804000 */  addu       $s0, $v0, $zero
    /* 4A6D8 80059ED8 01000224 */  addiu      $v0, $zero, 0x1
    /* 4A6DC 80059EDC 05000216 */  bne        $s0, $v0, .L80059EF4
    /* 4A6E0 80059EE0 21202002 */   addu      $a0, $s1, $zero
    /* 4A6E4 80059EE4 637C010C */  jal        func_8005F18C
    /* 4A6E8 80059EE8 00000000 */   nop
    /* 4A6EC 80059EEC 05005010 */  beq        $v0, $s0, .L80059F04
    /* 4A6F0 80059EF0 21202002 */   addu      $a0, $s1, $zero
  .L80059EF4:
    /* 4A6F4 80059EF4 21280000 */  addu       $a1, $zero, $zero
    /* 4A6F8 80059EF8 2130A000 */  addu       $a2, $a1, $zero
    /* 4A6FC 80059EFC 4B4B010C */  jal        func_80052D2C
    /* 4A700 80059F00 2138A000 */   addu      $a3, $a1, $zero
  .L80059F04:
    /* 4A704 80059F04 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4A708 80059F08 1400B18F */  lw         $s1, 0x14($sp)
    /* 4A70C 80059F0C 1000B08F */  lw         $s0, 0x10($sp)
    /* 4A710 80059F10 0800E003 */  jr         $ra
    /* 4A714 80059F14 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80059EBC
