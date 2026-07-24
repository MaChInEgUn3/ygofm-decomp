/* Handwritten function */
nonmatching func_80089C70, 0x20

glabel func_80089C70
    /* 7A470 80089C70 00888448 */  mtc2       $a0, $17 /* handwritten instruction */
    /* 7A474 80089C74 00908548 */  mtc2       $a1, $18 /* handwritten instruction */
    /* 7A478 80089C78 00988648 */  mtc2       $a2, $19 /* handwritten instruction */
    /* 7A47C 80089C7C 00000000 */  nop
    /* 7A480 80089C80 2D00584B */  avsz3
    /* 7A484 80089C84 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 7A488 80089C88 0800E003 */  jr         $ra
    /* 7A48C 80089C8C 00000000 */   nop
endlabel func_80089C70
