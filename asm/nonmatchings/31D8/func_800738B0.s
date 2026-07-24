/* Handwritten function */
nonmatching func_800738B0, 0x10

glabel func_800738B0
    /* 640B0 800738B0 01000424 */  addiu      $a0, $zero, 0x1
    /* 640B4 800738B4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 640B8 800738B8 0800E003 */  jr         $ra
    /* 640BC 800738BC 00000000 */   nop
endlabel func_800738B0
