/* Handwritten function */
nonmatching func_80087970, 0x28

glabel func_80087970
    /* 78170 80087970 000080C8 */  lwc2       $0, 0x0($a0)
    /* 78174 80087974 040081C8 */  lwc2       $1, 0x4($a0)
    /* 78178 80087978 00000000 */  nop
    /* 7817C 8008797C 1200484A */  mvmva      1, 0, 0, 0, 0
    /* 78180 80087980 0000B9E8 */  swc2       $25, 0x0($a1)
    /* 78184 80087984 0400BAE8 */  swc2       $26, 0x4($a1) /* handwritten instruction */
    /* 78188 80087988 0800BBE8 */  swc2       $27, 0x8($a1) /* handwritten instruction */
    /* 7818C 8008798C 00F84248 */  cfc2       $v0, $31 /* handwritten instruction */
    /* 78190 80087990 0800E003 */  jr         $ra
    /* 78194 80087994 0000C2AC */   sw        $v0, 0x0($a2)
endlabel func_80087970
    /* 78198 80087998 00000000 */  nop
    /* 7819C 8008799C 00000000 */  nop
