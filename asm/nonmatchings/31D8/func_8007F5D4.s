nonmatching func_8007F5D4, 0x60

glabel func_8007F5D4
    /* 6FDD4 8007F5D4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6FDD8 8007F5D8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6FDDC 8007F5DC 0980103C */  lui        $s0, %hi(D_8009466A)
    /* 6FDE0 8007F5E0 6A461026 */  addiu      $s0, $s0, %lo(D_8009466A)
    /* 6FDE4 8007F5E4 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6FDE8 8007F5E8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6FDEC 8007F5EC 00000292 */  lbu        $v0, 0x0($s0)
    /* 6FDF0 8007F5F0 00000000 */  nop
    /* 6FDF4 8007F5F4 0200422C */  sltiu      $v0, $v0, 0x2
    /* 6FDF8 8007F5F8 07004014 */  bnez       $v0, .L8007F618
    /* 6FDFC 8007F5FC 21888000 */   addu      $s1, $a0, $zero
    /* 6FE00 8007F600 0980023C */  lui        $v0, %hi(D_80094664)
    /* 6FE04 8007F604 6446428C */  lw         $v0, %lo(D_80094664)($v0)
    /* 6FE08 8007F608 0180043C */  lui        $a0, %hi(D_800121F4)
    /* 6FE0C 8007F60C F4218424 */  addiu      $a0, $a0, %lo(D_800121F4)
    /* 6FE10 8007F610 09F84000 */  jalr       $v0
    /* 6FE14 8007F614 21282002 */   addu      $a1, $s1, $zero
  .L8007F618:
    /* 6FE18 8007F618 0A00028E */  lw         $v0, 0xA($s0)
    /* 6FE1C 8007F61C 0A0011AE */  sw         $s1, 0xA($s0)
    /* 6FE20 8007F620 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6FE24 8007F624 1400B18F */  lw         $s1, 0x14($sp)
    /* 6FE28 8007F628 1000B08F */  lw         $s0, 0x10($sp)
    /* 6FE2C 8007F62C 0800E003 */  jr         $ra
    /* 6FE30 8007F630 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007F5D4
