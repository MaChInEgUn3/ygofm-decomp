nonmatching func_8005F714, 0x9C

glabel func_8005F714
    /* 4FF14 8005F714 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4FF18 8005F718 1000BFAF */  sw         $ra, 0x10($sp)
    /* 4FF1C 8005F71C 06008004 */  bltz       $a0, .L8005F738
    /* 4FF20 8005F720 2138C000 */   addu      $a3, $a2, $zero
    /* 4FF24 8005F724 C0180400 */  sll        $v1, $a0, 3
    /* 4FF28 8005F728 0980023C */  lui        $v0, %hi(D_80091550)
    /* 4FF2C 8005F72C 50154224 */  addiu      $v0, $v0, %lo(D_80091550)
    /* 4FF30 8005F730 CF7D0108 */  j          .L8005F73C
    /* 4FF34 8005F734 21406200 */   addu      $t0, $v1, $v0
  .L8005F738:
    /* 4FF38 8005F738 21400000 */  addu       $t0, $zero, $zero
  .L8005F73C:
    /* 4FF3C 8005F73C 0500A004 */  bltz       $a1, .L8005F754
    /* 4FF40 8005F740 C0180500 */   sll       $v1, $a1, 3
    /* 4FF44 8005F744 0980023C */  lui        $v0, %hi(D_80091550)
    /* 4FF48 8005F748 50154224 */  addiu      $v0, $v0, %lo(D_80091550)
    /* 4FF4C 8005F74C D67D0108 */  j          .L8005F758
    /* 4FF50 8005F750 21306200 */   addu      $a2, $v1, $v0
  .L8005F754:
    /* 4FF54 8005F754 21300000 */  addu       $a2, $zero, $zero
  .L8005F758:
    /* 4FF58 8005F758 73018493 */  lbu        $a0, %gp_rel(D_8009B07B)($gp)
    /* 4FF5C 8005F75C 01000224 */  addiu      $v0, $zero, 0x1
    /* 4FF60 8005F760 05008214 */  bne        $a0, $v0, .L8005F778
    /* 4FF64 8005F764 00000000 */   nop
    /* 4FF68 8005F768 74018293 */  lbu        $v0, %gp_rel(D_8009B07C)($gp)
    /* 4FF6C 8005F76C 00000000 */  nop
    /* 4FF70 8005F770 0B004410 */  beq        $v0, $a0, .L8005F7A0
    /* 4FF74 8005F774 00000000 */   nop
  .L8005F778:
    /* 4FF78 8005F778 72018483 */  lb         $a0, %gp_rel(D_8009B07A)($gp)
    /* 4FF7C 8005F77C 72018293 */  lbu        $v0, %gp_rel(D_8009B07A)($gp)
    /* 4FF80 8005F780 03008104 */  bgez       $a0, .L8005F790
    /* 4FF84 8005F784 01004224 */   addiu     $v0, $v0, 0x1
    /* 4FF88 8005F788 E67D0108 */  j          .L8005F798
    /* 4FF8C 8005F78C 21200000 */   addu      $a0, $zero, $zero
  .L8005F790:
    /* 4FF90 8005F790 720182A3 */  sb         $v0, %gp_rel(D_8009B07A)($gp)
    /* 4FF94 8005F794 2A200400 */  slt        $a0, $zero, $a0
  .L8005F798:
    /* 4FF98 8005F798 477E010C */  jal        func_8005F91C
    /* 4FF9C 8005F79C 21280001 */   addu      $a1, $t0, $zero
  .L8005F7A0:
    /* 4FFA0 8005F7A0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4FFA4 8005F7A4 00000000 */  nop
    /* 4FFA8 8005F7A8 0800E003 */  jr         $ra
    /* 4FFAC 8005F7AC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8005F714
