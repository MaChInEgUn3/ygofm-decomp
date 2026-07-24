/* Handwritten function */
nonmatching func_80089CF0, 0x34

glabel func_80089CF0
    /* 7A4F0 80089CF0 000080C8 */  lwc2       $0, 0x0($a0)
    /* 7A4F4 80089CF4 040081C8 */  lwc2       $1, 0x4($a0)
    /* 7A4F8 80089CF8 0000A2C8 */  lwc2       $2, 0x0($a1)
    /* 7A4FC 80089CFC 0400A3C8 */  lwc2       $3, 0x4($a1)
    /* 7A500 80089D00 0000C4C8 */  lwc2       $4, 0x0($a2)
    /* 7A504 80089D04 0400C5C8 */  lwc2       $5, 0x4($a2)
    /* 7A508 80089D08 00000000 */  nop
    /* 7A50C 80089D0C 3000284A */  rtpt
    /* 7A510 80089D10 00F84248 */  cfc2       $v0, $31 /* handwritten instruction */
    /* 7A514 80089D14 2D00584B */  avsz3
    /* 7A518 80089D18 0600404B */  nclip
    /* 7A51C 80089D1C 0800E003 */  jr         $ra
    /* 7A520 80089D20 00000000 */   nop
endlabel func_80089CF0
    /* 7A524 80089D24 00000000 */  nop
    /* 7A528 80089D28 00000000 */  nop
    /* 7A52C 80089D2C 00000000 */  nop
