/* Handwritten function */
nonmatching func_80086EE0, 0x80

glabel func_80086EE0
    /* 776E0 80086EE0 C0300600 */  sll        $a2, $a2, 3
    /* 776E4 80086EE4 2030C500 */  add        $a2, $a2, $a1 /* handwritten instruction */
    /* 776E8 80086EE8 00408748 */  mtc2       $a3, $8 /* handwritten instruction */
  .L80086EEC:
    /* 776EC 80086EEC 0000A88C */  lw         $t0, 0x0($a1)
    /* 776F0 80086EF0 0400AA84 */  lh         $t2, 0x4($a1)
    /* 776F4 80086EF4 034C0800 */  sra        $t1, $t0, 16
    /* 776F8 80086EF8 FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 776FC 80086EFC 00488848 */  mtc2       $t0, $9 /* handwritten instruction */
    /* 77700 80086F00 00508948 */  mtc2       $t1, $10 /* handwritten instruction */
    /* 77704 80086F04 00588A48 */  mtc2       $t2, $11 /* handwritten instruction */
    /* 77708 80086F08 00000000 */  nop
    /* 7770C 80086F0C 00000000 */  nop
    /* 77710 80086F10 3D00984B */  gpf        1
    /* 77714 80086F14 0000828C */  lw         $v0, 0x0($a0)
    /* 77718 80086F18 04008784 */  lh         $a3, 0x4($a0)
    /* 7771C 80086F1C 031C0200 */  sra        $v1, $v0, 16
    /* 77720 80086F20 FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 77724 80086F24 0800A520 */  addi       $a1, $a1, 0x8 /* handwritten instruction */
    /* 77728 80086F28 00480848 */  mfc2       $t0, $9 /* handwritten instruction */
    /* 7772C 80086F2C 00500948 */  mfc2       $t1, $10 /* handwritten instruction */
    /* 77730 80086F30 00580A48 */  mfc2       $t2, $11 /* handwritten instruction */
    /* 77734 80086F34 20104800 */  add        $v0, $v0, $t0 /* handwritten instruction */
    /* 77738 80086F38 20186900 */  add        $v1, $v1, $t1 /* handwritten instruction */
    /* 7773C 80086F3C 2038EA00 */  add        $a3, $a3, $t2 /* handwritten instruction */
    /* 77740 80086F40 000082A4 */  sh         $v0, 0x0($a0)
    /* 77744 80086F44 020083A4 */  sh         $v1, 0x2($a0)
    /* 77748 80086F48 040087A4 */  sh         $a3, 0x4($a0)
    /* 7774C 80086F4C 08008420 */  addi       $a0, $a0, 0x8 /* handwritten instruction */
    /* 77750 80086F50 E6FFA614 */  bne        $a1, $a2, .L80086EEC
    /* 77754 80086F54 00000000 */   nop
    /* 77758 80086F58 0800E003 */  jr         $ra
    /* 7775C 80086F5C 00000000 */   nop
endlabel func_80086EE0
