/* Handwritten function */
nonmatching func_80087810, 0x30

glabel func_80087810
    /* 78010 80087810 0000888C */  lw         $t0, 0x0($a0)
    /* 78014 80087814 0400898C */  lw         $t1, 0x4($a0)
    /* 78018 80087818 08008A8C */  lw         $t2, 0x8($a0)
    /* 7801C 8008781C 0C008B8C */  lw         $t3, 0xC($a0)
    /* 78020 80087820 10008C8C */  lw         $t4, 0x10($a0)
    /* 78024 80087824 0080C848 */  ctc2       $t0, $16 /* handwritten instruction */
    /* 78028 80087828 0088C948 */  ctc2       $t1, $17 /* handwritten instruction */
    /* 7802C 8008782C 0090CA48 */  ctc2       $t2, $18 /* handwritten instruction */
    /* 78030 80087830 0098CB48 */  ctc2       $t3, $19 /* handwritten instruction */
    /* 78034 80087834 00A0CC48 */  ctc2       $t4, $20 /* handwritten instruction */
    /* 78038 80087838 0800E003 */  jr         $ra
    /* 7803C 8008783C 00000000 */   nop
endlabel func_80087810
