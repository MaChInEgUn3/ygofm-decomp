/* Handwritten function */
nonmatching func_80086E50, 0x84

glabel func_80086E50
    /* 77650 80086E50 00F08448 */  mtc2       $a0, $30 /* handwritten instruction */
    /* 77654 80086E54 00000000 */  nop
    /* 77658 80086E58 00000000 */  nop
    /* 7765C 80086E5C 00F80248 */  mfc2       $v0, $31 /* handwritten instruction */
    /* 77660 80086E60 20000124 */  addiu      $at, $zero, 0x20
    /* 77664 80086E64 19004110 */  beq        $v0, $at, .L80086ECC
    /* 77668 80086E68 00000000 */   nop
    /* 7766C 80086E6C 01004830 */  andi       $t0, $v0, 0x1
    /* 77670 80086E70 FEFF0124 */  addiu      $at, $zero, -0x2
    /* 77674 80086E74 24504100 */  and        $t2, $v0, $at
    /* 77678 80086E78 1F000924 */  addiu      $t1, $zero, 0x1F
    /* 7767C 80086E7C 22482A01 */  sub        $t1, $t1, $t2 /* handwritten instruction */
    /* 77680 80086E80 43480900 */  sra        $t1, $t1, 1
    /* 77684 80086E84 E8FF4B21 */  addi       $t3, $t2, -0x18 /* handwritten instruction */
    /* 77688 80086E88 03006005 */  bltz       $t3, .L80086E98
    /* 7768C 80086E8C 00000000 */   nop
    /* 77690 80086E90 04606401 */  sllv       $t4, $a0, $t3
    /* 77694 80086E94 03000010 */  b          .L80086EA4
  .L80086E98:
    /* 77698 80086E98 18000B24 */   addiu     $t3, $zero, 0x18
    /* 7769C 80086E9C 22586A01 */  sub        $t3, $t3, $t2 /* handwritten instruction */
    /* 776A0 80086EA0 07606401 */  srav       $t4, $a0, $t3
  .L80086EA4:
    /* 776A4 80086EA4 C0FF8C21 */  addi       $t4, $t4, -0x40 /* handwritten instruction */
    /* 776A8 80086EA8 40600C00 */  sll        $t4, $t4, 1
    /* 776AC 80086EAC 09800D3C */  lui        $t5, %hi(D_800951A8)
    /* 776B0 80086EB0 2168AC01 */  addu       $t5, $t5, $t4
    /* 776B4 80086EB4 A851AD85 */  lh         $t5, %lo(D_800951A8)($t5)
    /* 776B8 80086EB8 00000000 */  nop
    /* 776BC 80086EBC 04682D01 */  sllv       $t5, $t5, $t1
    /* 776C0 80086EC0 02130D00 */  srl        $v0, $t5, 12
    /* 776C4 80086EC4 0800E003 */  jr         $ra
    /* 776C8 80086EC8 00000000 */   nop
  .L80086ECC:
    /* 776CC 80086ECC 0800E003 */  jr         $ra
    /* 776D0 80086ED0 00000224 */   addiu     $v0, $zero, 0x0
endlabel func_80086E50
    /* 776D4 80086ED4 00000000 */  nop
    /* 776D8 80086ED8 00000000 */  nop
    /* 776DC 80086EDC 00000000 */  nop
