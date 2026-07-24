nonmatching func_8007FDF0, 0xD8

glabel func_8007FDF0
    /* 705F0 8007FDF0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 705F4 8007FDF4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 705F8 8007FDF8 21908000 */  addu       $s2, $a0, $zero
    /* 705FC 8007FDFC 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 70600 8007FE00 0980133C */  lui        $s3, %hi(D_8009466A)
    /* 70604 8007FE04 6A467326 */  addiu      $s3, $s3, %lo(D_8009466A)
    /* 70608 8007FE08 2000BFAF */  sw         $ra, 0x20($sp)
    /* 7060C 8007FE0C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 70610 8007FE10 1000B0AF */  sw         $s0, 0x10($sp)
    /* 70614 8007FE14 00006292 */  lbu        $v0, 0x0($s3)
    /* 70618 8007FE18 00000000 */  nop
    /* 7061C 8007FE1C 0200422C */  sltiu      $v0, $v0, 0x2
    /* 70620 8007FE20 09004014 */  bnez       $v0, .L8007FE48
    /* 70624 8007FE24 2188A000 */   addu      $s1, $a1, $zero
    /* 70628 8007FE28 0180043C */  lui        $a0, %hi(D_800122F4)
    /* 7062C 8007FE2C F4228424 */  addiu      $a0, $a0, %lo(D_800122F4)
    /* 70630 8007FE30 21284002 */  addu       $a1, $s2, $zero
    /* 70634 8007FE34 0980023C */  lui        $v0, %hi(D_80094664)
    /* 70638 8007FE38 6446428C */  lw         $v0, %lo(D_80094664)($v0)
    /* 7063C 8007FE3C 00000000 */  nop
    /* 70640 8007FE40 09F84000 */  jalr       $v0
    /* 70644 8007FE44 21302002 */   addu      $a2, $s1, $zero
  .L8007FE48:
    /* 70648 8007FE48 1C003026 */  addiu      $s0, $s1, 0x1C
    /* 7064C 8007FE4C 21200002 */  addu       $a0, $s0, $zero
    /* 70650 8007FE50 C401020C */  jal        func_80080710
    /* 70654 8007FE54 21282002 */   addu      $a1, $s1, $zero
    /* 70658 8007FE58 FF00043C */  lui        $a0, (0xFFFFFF >> 16)
    /* 7065C 8007FE5C FFFF8434 */  ori        $a0, $a0, (0xFFFFFF & 0xFFFF)
    /* 70660 8007FE60 21280002 */  addu       $a1, $s0, $zero
    /* 70664 8007FE64 40000624 */  addiu      $a2, $zero, 0x40
    /* 70668 8007FE68 00FF033C */  lui        $v1, (0xFF000000 >> 16)
    /* 7066C 8007FE6C 1C00228E */  lw         $v0, 0x1C($s1)
    /* 70670 8007FE70 24204402 */  and        $a0, $s2, $a0
    /* 70674 8007FE74 24104300 */  and        $v0, $v0, $v1
    /* 70678 8007FE78 0980033C */  lui        $v1, %hi(D_80094660)
    /* 7067C 8007FE7C 6046638C */  lw         $v1, %lo(D_80094660)($v1)
    /* 70680 8007FE80 25104400 */  or         $v0, $v0, $a0
    /* 70684 8007FE84 1C0022AE */  sw         $v0, 0x1C($s1)
    /* 70688 8007FE88 1800648C */  lw         $a0, 0x18($v1)
    /* 7068C 8007FE8C 0800628C */  lw         $v0, 0x8($v1)
    /* 70690 8007FE90 00000000 */  nop
    /* 70694 8007FE94 09F84000 */  jalr       $v0
    /* 70698 8007FE98 21380000 */   addu      $a3, $zero, $zero
    /* 7069C 8007FE9C 0E006426 */  addiu      $a0, $s3, 0xE
    /* 706A0 8007FEA0 21282002 */  addu       $a1, $s1, $zero
    /* 706A4 8007FEA4 E438020C */  jal        func_8008E390
    /* 706A8 8007FEA8 5C000624 */   addiu     $a2, $zero, 0x5C
    /* 706AC 8007FEAC 2000BF8F */  lw         $ra, 0x20($sp)
    /* 706B0 8007FEB0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 706B4 8007FEB4 1800B28F */  lw         $s2, 0x18($sp)
    /* 706B8 8007FEB8 1400B18F */  lw         $s1, 0x14($sp)
    /* 706BC 8007FEBC 1000B08F */  lw         $s0, 0x10($sp)
    /* 706C0 8007FEC0 0800E003 */  jr         $ra
    /* 706C4 8007FEC4 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8007FDF0
