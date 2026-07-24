/* Handwritten function */
nonmatching func_80087890, 0x20

glabel func_80087890
    /* 78090 80087890 00210400 */  sll        $a0, $a0, 4
    /* 78094 80087894 00290500 */  sll        $a1, $a1, 4
    /* 78098 80087898 00310600 */  sll        $a2, $a2, 4
    /* 7809C 8008789C 00A8C448 */  ctc2       $a0, $21 /* handwritten instruction */
    /* 780A0 800878A0 00B0C548 */  ctc2       $a1, $22 /* handwritten instruction */
    /* 780A4 800878A4 00B8C648 */  ctc2       $a2, $23 /* handwritten instruction */
    /* 780A8 800878A8 0800E003 */  jr         $ra
    /* 780AC 800878AC 00000000 */   nop
endlabel func_80087890
