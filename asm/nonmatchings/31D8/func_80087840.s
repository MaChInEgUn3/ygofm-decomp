/* Handwritten function */
nonmatching func_80087840, 0x20

glabel func_80087840
    /* 78040 80087840 1400888C */  lw         $t0, 0x14($a0)
    /* 78044 80087844 1800898C */  lw         $t1, 0x18($a0)
    /* 78048 80087848 1C008A8C */  lw         $t2, 0x1C($a0)
    /* 7804C 8008784C 0028C848 */  ctc2       $t0, $5 /* handwritten instruction */
    /* 78050 80087850 0030C948 */  ctc2       $t1, $6 /* handwritten instruction */
    /* 78054 80087854 0038CA48 */  ctc2       $t2, $7 /* handwritten instruction */
    /* 78058 80087858 0800E003 */  jr         $ra
    /* 7805C 8008785C 00000000 */   nop
endlabel func_80087840
