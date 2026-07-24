/* Handwritten function */
nonmatching func_80087870, 0x20

glabel func_80087870
    /* 78070 80087870 00210400 */  sll        $a0, $a0, 4
    /* 78074 80087874 00290500 */  sll        $a1, $a1, 4
    /* 78078 80087878 00310600 */  sll        $a2, $a2, 4
    /* 7807C 8008787C 0068C448 */  ctc2       $a0, $13 /* handwritten instruction */
    /* 78080 80087880 0070C548 */  ctc2       $a1, $14 /* handwritten instruction */
    /* 78084 80087884 0078C648 */  ctc2       $a2, $15 /* handwritten instruction */
    /* 78088 80087888 0800E003 */  jr         $ra
    /* 7808C 8008788C 00000000 */   nop
endlabel func_80087870
