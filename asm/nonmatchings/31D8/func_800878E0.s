/* Handwritten function */
nonmatching func_800878E0, 0x2C

glabel func_800878E0
    /* 780E0 800878E0 000080C8 */  lwc2       $0, 0x0($a0)
    /* 780E4 800878E4 040081C8 */  lwc2       $1, 0x4($a0)
    /* 780E8 800878E8 00000000 */  nop
    /* 780EC 800878EC 0100184A */  rtps
    /* 780F0 800878F0 0000AEE8 */  swc2       $14, 0x0($a1)
    /* 780F4 800878F4 0000C8E8 */  swc2       $8, 0x0($a2)
    /* 780F8 800878F8 00F84348 */  cfc2       $v1, $31 /* handwritten instruction */
    /* 780FC 800878FC 00980248 */  mfc2       $v0, $19 /* handwritten instruction */
    /* 78100 80087900 0000E3AC */  sw         $v1, 0x0($a3)
    /* 78104 80087904 0800E003 */  jr         $ra
    /* 78108 80087908 83100200 */   sra       $v0, $v0, 2
endlabel func_800878E0
    /* 7810C 8008790C 00000000 */  nop
