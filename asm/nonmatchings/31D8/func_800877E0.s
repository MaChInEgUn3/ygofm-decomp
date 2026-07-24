/* Handwritten function */
nonmatching func_800877E0, 0x30

glabel func_800877E0
    /* 77FE0 800877E0 0000888C */  lw         $t0, 0x0($a0)
    /* 77FE4 800877E4 0400898C */  lw         $t1, 0x4($a0)
    /* 77FE8 800877E8 08008A8C */  lw         $t2, 0x8($a0)
    /* 77FEC 800877EC 0C008B8C */  lw         $t3, 0xC($a0)
    /* 77FF0 800877F0 10008C8C */  lw         $t4, 0x10($a0)
    /* 77FF4 800877F4 0040C848 */  ctc2       $t0, $8 /* handwritten instruction */
    /* 77FF8 800877F8 0048C948 */  ctc2       $t1, $9 /* handwritten instruction */
    /* 77FFC 800877FC 0050CA48 */  ctc2       $t2, $10 /* handwritten instruction */
    /* 78000 80087800 0058CB48 */  ctc2       $t3, $11 /* handwritten instruction */
    /* 78004 80087804 0060CC48 */  ctc2       $t4, $12 /* handwritten instruction */
    /* 78008 80087808 0800E003 */  jr         $ra
    /* 7800C 8008780C 00000000 */   nop
endlabel func_800877E0
