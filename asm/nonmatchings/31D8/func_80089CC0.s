/* Handwritten function */
nonmatching func_80089CC0, 0x30

glabel func_80089CC0
    /* 7A4C0 80089CC0 000080C8 */  lwc2       $0, 0x0($a0)
    /* 7A4C4 80089CC4 040081C8 */  lwc2       $1, 0x4($a0)
    /* 7A4C8 80089CC8 00000000 */  nop
    /* 7A4CC 80089CCC 1200484A */  mvmva      1, 0, 0, 0, 0
    /* 7A4D0 80089CD0 00480248 */  mfc2       $v0, $9 /* handwritten instruction */
    /* 7A4D4 80089CD4 00500348 */  mfc2       $v1, $10 /* handwritten instruction */
    /* 7A4D8 80089CD8 0400ABE8 */  swc2       $11, 0x4($a1)
    /* 7A4DC 80089CDC 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 7A4E0 80089CE0 0200A3A4 */  sh         $v1, 0x2($a1)
    /* 7A4E4 80089CE4 00F84248 */  cfc2       $v0, $31 /* handwritten instruction */
    /* 7A4E8 80089CE8 0800E003 */  jr         $ra
    /* 7A4EC 80089CEC 0000C2AC */   sw        $v0, 0x0($a2)
endlabel func_80089CC0
