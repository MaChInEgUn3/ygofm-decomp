/* Handwritten function */
nonmatching func_80087480, 0x10C

glabel func_80087480
    /* 77C80 80087480 0000888C */  lw         $t0, 0x0($a0)
    /* 77C84 80087484 0400898C */  lw         $t1, 0x4($a0)
    /* 77C88 80087488 08008A8C */  lw         $t2, 0x8($a0)
    /* 77C8C 8008748C 0C008B8C */  lw         $t3, 0xC($a0)
    /* 77C90 80087490 10008C8C */  lw         $t4, 0x10($a0)
    /* 77C94 80087494 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 77C98 80087498 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 77C9C 8008749C 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 77CA0 800874A0 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 77CA4 800874A4 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 77CA8 800874A8 0000A894 */  lhu        $t0, 0x0($a1)
    /* 77CAC 800874AC 0400A98C */  lw         $t1, 0x4($a1)
    /* 77CB0 800874B0 0C00AA8C */  lw         $t2, 0xC($a1)
    /* 77CB4 800874B4 FFFF013C */  lui        $at, (0xFFFF0000 >> 16)
    /* 77CB8 800874B8 24482101 */  and        $t1, $t1, $at
    /* 77CBC 800874BC 25400901 */  or         $t0, $t0, $t1
    /* 77CC0 800874C0 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 77CC4 800874C4 00088A48 */  mtc2       $t2, $1 /* handwritten instruction */
    /* 77CC8 800874C8 00000000 */  nop
    /* 77CCC 800874CC 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 77CD0 800874D0 0200A894 */  lhu        $t0, 0x2($a1)
    /* 77CD4 800874D4 0800A98C */  lw         $t1, 0x8($a1)
    /* 77CD8 800874D8 0E00AA84 */  lh         $t2, 0xE($a1)
    /* 77CDC 800874DC 004C0900 */  sll        $t1, $t1, 16
    /* 77CE0 800874E0 25400901 */  or         $t0, $t0, $t1
    /* 77CE4 800874E4 00480B48 */  mfc2       $t3, $9 /* handwritten instruction */
    /* 77CE8 800874E8 00500C48 */  mfc2       $t4, $10 /* handwritten instruction */
    /* 77CEC 800874EC 00580D48 */  mfc2       $t5, $11 /* handwritten instruction */
    /* 77CF0 800874F0 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 77CF4 800874F4 00088A48 */  mtc2       $t2, $1 /* handwritten instruction */
    /* 77CF8 800874F8 00000000 */  nop
    /* 77CFC 800874FC 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 77D00 80087500 0400A894 */  lhu        $t0, 0x4($a1)
    /* 77D04 80087504 0800A98C */  lw         $t1, 0x8($a1)
    /* 77D08 80087508 1000AA8C */  lw         $t2, 0x10($a1)
    /* 77D0C 8008750C FFFF013C */  lui        $at, (0xFFFF0000 >> 16)
    /* 77D10 80087510 24482101 */  and        $t1, $t1, $at
    /* 77D14 80087514 25400901 */  or         $t0, $t0, $t1
    /* 77D18 80087518 00480E48 */  mfc2       $t6, $9 /* handwritten instruction */
    /* 77D1C 8008751C 00500F48 */  mfc2       $t7, $10 /* handwritten instruction */
    /* 77D20 80087520 00581848 */  mfc2       $t8, $11 /* handwritten instruction */
    /* 77D24 80087524 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 77D28 80087528 00088A48 */  mtc2       $t2, $1 /* handwritten instruction */
    /* 77D2C 8008752C 00000000 */  nop
    /* 77D30 80087530 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 77D34 80087534 FFFF6B31 */  andi       $t3, $t3, 0xFFFF
    /* 77D38 80087538 00740E00 */  sll        $t6, $t6, 16
    /* 77D3C 8008753C 2570CB01 */  or         $t6, $t6, $t3
    /* 77D40 80087540 0000AEAC */  sw         $t6, 0x0($a1)
    /* 77D44 80087544 FFFFAD31 */  andi       $t5, $t5, 0xFFFF
    /* 77D48 80087548 00C41800 */  sll        $t8, $t8, 16
    /* 77D4C 8008754C 25C00D03 */  or         $t8, $t8, $t5
    /* 77D50 80087550 0C00B8AC */  sw         $t8, 0xC($a1)
    /* 77D54 80087554 00480848 */  mfc2       $t0, $9 /* handwritten instruction */
    /* 77D58 80087558 00500948 */  mfc2       $t1, $10 /* handwritten instruction */
    /* 77D5C 8008755C FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 77D60 80087560 00640C00 */  sll        $t4, $t4, 16
    /* 77D64 80087564 25400C01 */  or         $t0, $t0, $t4
    /* 77D68 80087568 0400A8AC */  sw         $t0, 0x4($a1)
    /* 77D6C 8008756C FFFFEF31 */  andi       $t7, $t7, 0xFFFF
    /* 77D70 80087570 004C0900 */  sll        $t1, $t1, 16
    /* 77D74 80087574 25482F01 */  or         $t1, $t1, $t7
    /* 77D78 80087578 0800A9AC */  sw         $t1, 0x8($a1)
    /* 77D7C 8008757C 1000ABE8 */  swc2       $11, 0x10($a1)
    /* 77D80 80087580 2110A000 */  addu       $v0, $a1, $zero
    /* 77D84 80087584 0800E003 */  jr         $ra
    /* 77D88 80087588 00000000 */   nop
endlabel func_80087480
    /* 77D8C 8008758C 00000000 */  nop
