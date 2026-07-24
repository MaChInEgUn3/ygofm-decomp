nonmatching func_8008B5EC, 0x94

glabel func_8008B5EC
    /* 7BDEC 8008B5EC 1080013C */  lui        $at, %hi(D_800FE2F8)
    /* 7BDF0 8008B5F0 F8E23FAC */  sw         $ra, %lo(D_800FE2F8)($at)
    /* 7BDF4 8008B5F4 2CCE010C */  jal        func_800738B0
    /* 7BDF8 8008B5F8 00000000 */   nop
    /* 7BDFC 8008B5FC 56000924 */  addiu      $t1, $zero, 0x56
    /* 7BE00 8008B600 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 7BE04 8008B604 09F84001 */  jalr       $t2
    /* 7BE08 8008B608 00000000 */   nop
    /* 7BE0C 8008B60C 1800428C */  lw         $v0, 0x18($v0)
    /* 7BE10 8008B610 00000000 */  nop
    /* 7BE14 8008B614 7000438C */  lw         $v1, 0x70($v0)
    /* 7BE18 8008B618 00000000 */  nop
    /* 7BE1C 8008B61C FFFF6930 */  andi       $t1, $v1, 0xFFFF
    /* 7BE20 8008B620 004C0900 */  sll        $t1, $t1, 16
    /* 7BE24 8008B624 7400438C */  lw         $v1, 0x74($v0)
    /* 7BE28 8008B628 00000000 */  nop
    /* 7BE2C 8008B62C FFFF6A30 */  andi       $t2, $v1, 0xFFFF
    /* 7BE30 8008B630 21182A01 */  addu       $v1, $t1, $t2
    /* 7BE34 8008B634 28006224 */  addiu      $v0, $v1, 0x28
    /* 7BE38 8008B638 09800A3C */  lui        $t2, %hi(func_8008B5C4)
    /* 7BE3C 8008B63C C4B54A25 */  addiu      $t2, $t2, %lo(func_8008B5C4)
    /* 7BE40 8008B640 0980093C */  lui        $t1, %hi(func_8008B5C4 + 0x14)
    /* 7BE44 8008B644 D8B52925 */  addiu      $t1, $t1, %lo(func_8008B5C4 + 0x14)
  .L8008B648:
    /* 7BE48 8008B648 0000438D */  lw         $v1, 0x0($t2)
    /* 7BE4C 8008B64C 00000000 */  nop
    /* 7BE50 8008B650 000043AC */  sw         $v1, 0x0($v0)
    /* 7BE54 8008B654 04004A25 */  addiu      $t2, $t2, 0x4
    /* 7BE58 8008B658 FBFF4915 */  bne        $t2, $t1, .L8008B648
    /* 7BE5C 8008B65C 04004224 */   addiu     $v0, $v0, 0x4
    /* 7BE60 8008B660 0100013C */  lui        $at, (0x10000 >> 16)
    /* 7BE64 8008B664 3CD0010C */  jal        func_800740F0
    /* 7BE68 8008B668 FCDF22AC */   sw        $v0, -0x2004($at)
    /* 7BE6C 8008B66C 10801F3C */  lui        $ra, %hi(D_800FE2F8)
    /* 7BE70 8008B670 F8E2FF8F */  lw         $ra, %lo(D_800FE2F8)($ra)
    /* 7BE74 8008B674 00000000 */  nop
    /* 7BE78 8008B678 0800E003 */  jr         $ra
    /* 7BE7C 8008B67C 00000000 */   nop
endlabel func_8008B5EC
