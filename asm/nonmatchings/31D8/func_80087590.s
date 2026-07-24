/* Handwritten function */
nonmatching func_80087590, 0x50

glabel func_80087590
    /* 77D90 80087590 0000888C */  lw         $t0, 0x0($a0)
    /* 77D94 80087594 0400898C */  lw         $t1, 0x4($a0)
    /* 77D98 80087598 08008A8C */  lw         $t2, 0x8($a0)
    /* 77D9C 8008759C 0C008B8C */  lw         $t3, 0xC($a0)
    /* 77DA0 800875A0 10008C8C */  lw         $t4, 0x10($a0)
    /* 77DA4 800875A4 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 77DA8 800875A8 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 77DAC 800875AC 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 77DB0 800875B0 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 77DB4 800875B4 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 77DB8 800875B8 0000A0C8 */  lwc2       $0, 0x0($a1)
    /* 77DBC 800875BC 0400A1C8 */  lwc2       $1, 0x4($a1)
    /* 77DC0 800875C0 00000000 */  nop
    /* 77DC4 800875C4 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 77DC8 800875C8 0000D9E8 */  swc2       $25, 0x0($a2)
    /* 77DCC 800875CC 0400DAE8 */  swc2       $26, 0x4($a2) /* handwritten instruction */
    /* 77DD0 800875D0 0800DBE8 */  swc2       $27, 0x8($a2) /* handwritten instruction */
    /* 77DD4 800875D4 2110C000 */  addu       $v0, $a2, $zero
    /* 77DD8 800875D8 0800E003 */  jr         $ra
    /* 77DDC 800875DC 00000000 */   nop
endlabel func_80087590
