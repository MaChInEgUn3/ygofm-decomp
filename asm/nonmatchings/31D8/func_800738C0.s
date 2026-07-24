/* Handwritten function */
nonmatching func_800738C0, 0x10

glabel func_800738C0
    /* 640C0 800738C0 02000424 */  addiu      $a0, $zero, 0x2
    /* 640C4 800738C4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 640C8 800738C8 0800E003 */  jr         $ra
    /* 640CC 800738CC 00000000 */   nop
endlabel func_800738C0
