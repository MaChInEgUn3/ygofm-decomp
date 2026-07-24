/* Handwritten function */
nonmatching func_80087C70, 0x4C

glabel func_80087C70
    /* 78470 80087C70 000080C8 */  lwc2       $0, 0x0($a0)
    /* 78474 80087C74 040081C8 */  lwc2       $1, 0x4($a0)
    /* 78478 80087C78 00000000 */  nop
    /* 7847C 80087C7C 0100184A */  rtps
    /* 78480 80087C80 1400A88F */  lw         $t0, 0x14($sp)
    /* 78484 80087C84 00F84248 */  cfc2       $v0, $31 /* handwritten instruction */
    /* 78488 80087C88 0000EEE8 */  swc2       $14, 0x0($a3)
    /* 7848C 80087C8C 000002AD */  sw         $v0, 0x0($t0)
    /* 78490 80087C90 0000A0C8 */  lwc2       $0, 0x0($a1)
    /* 78494 80087C94 0400A1C8 */  lwc2       $1, 0x4($a1)
    /* 78498 80087C98 0000C6C8 */  lwc2       $6, 0x0($a2)
    /* 7849C 80087C9C 00000000 */  nop
    /* 784A0 80087CA0 1304E84A */  ncds
    /* 784A4 80087CA4 1000A88F */  lw         $t0, 0x10($sp)
    /* 784A8 80087CA8 00000000 */  nop
    /* 784AC 80087CAC 00980248 */  mfc2       $v0, $19 /* handwritten instruction */
    /* 784B0 80087CB0 000016E9 */  swc2       $22, 0x0($t0)
    /* 784B4 80087CB4 0800E003 */  jr         $ra
    /* 784B8 80087CB8 83100200 */   sra       $v0, $v0, 2
endlabel func_80087C70
    /* 784BC 80087CBC 00000000 */  nop
