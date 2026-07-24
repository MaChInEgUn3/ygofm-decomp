/* Handwritten function */
nonmatching func_800875E0, 0x5C

glabel func_800875E0
    /* 77DE0 800875E0 0000888C */  lw         $t0, 0x0($a0)
    /* 77DE4 800875E4 0400898C */  lw         $t1, 0x4($a0)
    /* 77DE8 800875E8 08008A8C */  lw         $t2, 0x8($a0)
    /* 77DEC 800875EC 0C008B8C */  lw         $t3, 0xC($a0)
    /* 77DF0 800875F0 10008C8C */  lw         $t4, 0x10($a0)
    /* 77DF4 800875F4 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 77DF8 800875F8 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 77DFC 800875FC 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 77E00 80087600 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 77E04 80087604 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 77E08 80087608 0000A0C8 */  lwc2       $0, 0x0($a1)
    /* 77E0C 8008760C 0400A1C8 */  lwc2       $1, 0x4($a1)
    /* 77E10 80087610 00000000 */  nop
    /* 77E14 80087614 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 77E18 80087618 00480848 */  mfc2       $t0, $9 /* handwritten instruction */
    /* 77E1C 8008761C 00500948 */  mfc2       $t1, $10 /* handwritten instruction */
    /* 77E20 80087620 00580A48 */  mfc2       $t2, $11 /* handwritten instruction */
    /* 77E24 80087624 0000C8A4 */  sh         $t0, 0x0($a2)
    /* 77E28 80087628 0200C9A4 */  sh         $t1, 0x2($a2)
    /* 77E2C 8008762C 0400CAA4 */  sh         $t2, 0x4($a2)
    /* 77E30 80087630 2110C000 */  addu       $v0, $a2, $zero
    /* 77E34 80087634 0800E003 */  jr         $ra
    /* 77E38 80087638 00000000 */   nop
endlabel func_800875E0
    /* 77E3C 8008763C 00000000 */  nop
