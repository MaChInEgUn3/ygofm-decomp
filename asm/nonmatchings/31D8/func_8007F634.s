nonmatching func_8007F634, 0x98

glabel func_8007F634
    /* 6FE34 8007F634 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6FE38 8007F638 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6FE3C 8007F63C 0980113C */  lui        $s1, %hi(D_8009466A)
    /* 6FE40 8007F640 6A463126 */  addiu      $s1, $s1, %lo(D_8009466A)
    /* 6FE44 8007F644 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6FE48 8007F648 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6FE4C 8007F64C 00002292 */  lbu        $v0, 0x0($s1)
    /* 6FE50 8007F650 00000000 */  nop
    /* 6FE54 8007F654 0200422C */  sltiu      $v0, $v0, 0x2
    /* 6FE58 8007F658 08004014 */  bnez       $v0, .L8007F67C
    /* 6FE5C 8007F65C 21808000 */   addu      $s0, $a0, $zero
    /* 6FE60 8007F660 0180043C */  lui        $a0, %hi(D_80012210)
    /* 6FE64 8007F664 10228424 */  addiu      $a0, $a0, %lo(D_80012210)
    /* 6FE68 8007F668 0980023C */  lui        $v0, %hi(D_80094664)
    /* 6FE6C 8007F66C 6446428C */  lw         $v0, %lo(D_80094664)($v0)
    /* 6FE70 8007F670 00000000 */  nop
    /* 6FE74 8007F674 09F84000 */  jalr       $v0
    /* 6FE78 8007F678 21280002 */   addu      $a1, $s0, $zero
  .L8007F67C:
    /* 6FE7C 8007F67C 04000016 */  bnez       $s0, .L8007F690
    /* 6FE80 8007F680 6A002426 */   addiu     $a0, $s1, 0x6A
    /* 6FE84 8007F684 FFFF0524 */  addiu      $a1, $zero, -0x1
    /* 6FE88 8007F688 8A08020C */  jal        func_80082228
    /* 6FE8C 8007F68C 14000624 */   addiu     $a2, $zero, 0x14
  .L8007F690:
    /* 6FE90 8007F690 0003043C */  lui        $a0, (0x3000001 >> 16)
    /* 6FE94 8007F694 0980023C */  lui        $v0, %hi(D_80094660)
    /* 6FE98 8007F698 6046428C */  lw         $v0, %lo(D_80094660)($v0)
    /* 6FE9C 8007F69C 02000012 */  beqz       $s0, .L8007F6A8
    /* 6FEA0 8007F6A0 01008434 */   ori       $a0, $a0, (0x3000001 & 0xFFFF)
    /* 6FEA4 8007F6A4 0003043C */  lui        $a0, (0x3000000 >> 16)
  .L8007F6A8:
    /* 6FEA8 8007F6A8 1000428C */  lw         $v0, 0x10($v0)
    /* 6FEAC 8007F6AC 00000000 */  nop
    /* 6FEB0 8007F6B0 09F84000 */  jalr       $v0
    /* 6FEB4 8007F6B4 00000000 */   nop
    /* 6FEB8 8007F6B8 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6FEBC 8007F6BC 1400B18F */  lw         $s1, 0x14($sp)
    /* 6FEC0 8007F6C0 1000B08F */  lw         $s0, 0x10($sp)
    /* 6FEC4 8007F6C4 0800E003 */  jr         $ra
    /* 6FEC8 8007F6C8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007F634
