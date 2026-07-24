/* Handwritten function */
nonmatching func_800878B0, 0x18

glabel func_800878B0
    /* 780B0 800878B0 00240400 */  sll        $a0, $a0, 16
    /* 780B4 800878B4 002C0500 */  sll        $a1, $a1, 16
    /* 780B8 800878B8 00C0C448 */  ctc2       $a0, $24 /* handwritten instruction */
    /* 780BC 800878BC 00C8C548 */  ctc2       $a1, $25 /* handwritten instruction */
    /* 780C0 800878C0 0800E003 */  jr         $ra
    /* 780C4 800878C4 00000000 */   nop
endlabel func_800878B0
    /* 780C8 800878C8 00000000 */  nop
    /* 780CC 800878CC 00000000 */  nop
