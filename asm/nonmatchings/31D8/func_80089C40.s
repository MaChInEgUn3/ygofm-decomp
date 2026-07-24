/* Handwritten function */
nonmatching func_80089C40, 0x28

glabel func_80089C40
    /* 7A440 80089C40 000089C8 */  lwc2       $9, 0x0($a0)
    /* 7A444 80089C44 04008AC8 */  lwc2       $10, 0x4($a0)
    /* 7A448 80089C48 08008BC8 */  lwc2       $11, 0x8($a0)
    /* 7A44C 80089C4C 00000000 */  nop
    /* 7A450 80089C50 2804A04A */  sqr        0
    /* 7A454 80089C54 0000B9E8 */  swc2       $25, 0x0($a1)
    /* 7A458 80089C58 0400BAE8 */  swc2       $26, 0x4($a1) /* handwritten instruction */
    /* 7A45C 80089C5C 0800BBE8 */  swc2       $27, 0x8($a1) /* handwritten instruction */
    /* 7A460 80089C60 0800E003 */  jr         $ra
    /* 7A464 80089C64 2110A000 */   addu      $v0, $a1, $zero
endlabel func_80089C40
    /* 7A468 80089C68 00000000 */  nop
    /* 7A46C 80089C6C 00000000 */  nop
