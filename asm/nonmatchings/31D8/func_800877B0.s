/* Handwritten function */
nonmatching func_800877B0, 0x30

glabel func_800877B0
    /* 77FB0 800877B0 0000888C */  lw         $t0, 0x0($a0)
    /* 77FB4 800877B4 0400898C */  lw         $t1, 0x4($a0)
    /* 77FB8 800877B8 08008A8C */  lw         $t2, 0x8($a0)
    /* 77FBC 800877BC 0C008B8C */  lw         $t3, 0xC($a0)
    /* 77FC0 800877C0 10008C8C */  lw         $t4, 0x10($a0)
    /* 77FC4 800877C4 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 77FC8 800877C8 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 77FCC 800877CC 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 77FD0 800877D0 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 77FD4 800877D4 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 77FD8 800877D8 0800E003 */  jr         $ra
    /* 77FDC 800877DC 00000000 */   nop
endlabel func_800877B0
