/* Handwritten function */
nonmatching func_80086F60, 0x10C

glabel func_80086F60
    /* 77760 80086F60 0000888C */  lw         $t0, 0x0($a0)
    /* 77764 80086F64 0400898C */  lw         $t1, 0x4($a0)
    /* 77768 80086F68 08008A8C */  lw         $t2, 0x8($a0)
    /* 7776C 80086F6C 0C008B8C */  lw         $t3, 0xC($a0)
    /* 77770 80086F70 10008C8C */  lw         $t4, 0x10($a0)
    /* 77774 80086F74 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 77778 80086F78 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 7777C 80086F7C 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 77780 80086F80 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 77784 80086F84 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 77788 80086F88 0000A894 */  lhu        $t0, 0x0($a1)
    /* 7778C 80086F8C 0400A98C */  lw         $t1, 0x4($a1)
    /* 77790 80086F90 0C00AA8C */  lw         $t2, 0xC($a1)
    /* 77794 80086F94 FFFF013C */  lui        $at, (0xFFFF0000 >> 16)
    /* 77798 80086F98 24482101 */  and        $t1, $t1, $at
    /* 7779C 80086F9C 25400901 */  or         $t0, $t0, $t1
    /* 777A0 80086FA0 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 777A4 80086FA4 00088A48 */  mtc2       $t2, $1 /* handwritten instruction */
    /* 777A8 80086FA8 00000000 */  nop
    /* 777AC 80086FAC 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 777B0 80086FB0 0200A894 */  lhu        $t0, 0x2($a1)
    /* 777B4 80086FB4 0800A98C */  lw         $t1, 0x8($a1)
    /* 777B8 80086FB8 0E00AA84 */  lh         $t2, 0xE($a1)
    /* 777BC 80086FBC 004C0900 */  sll        $t1, $t1, 16
    /* 777C0 80086FC0 25400901 */  or         $t0, $t0, $t1
    /* 777C4 80086FC4 00480B48 */  mfc2       $t3, $9 /* handwritten instruction */
    /* 777C8 80086FC8 00500C48 */  mfc2       $t4, $10 /* handwritten instruction */
    /* 777CC 80086FCC 00580D48 */  mfc2       $t5, $11 /* handwritten instruction */
    /* 777D0 80086FD0 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 777D4 80086FD4 00088A48 */  mtc2       $t2, $1 /* handwritten instruction */
    /* 777D8 80086FD8 00000000 */  nop
    /* 777DC 80086FDC 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 777E0 80086FE0 0400A894 */  lhu        $t0, 0x4($a1)
    /* 777E4 80086FE4 0800A98C */  lw         $t1, 0x8($a1)
    /* 777E8 80086FE8 1000AA8C */  lw         $t2, 0x10($a1)
    /* 777EC 80086FEC FFFF013C */  lui        $at, (0xFFFF0000 >> 16)
    /* 777F0 80086FF0 24482101 */  and        $t1, $t1, $at
    /* 777F4 80086FF4 25400901 */  or         $t0, $t0, $t1
    /* 777F8 80086FF8 00480E48 */  mfc2       $t6, $9 /* handwritten instruction */
    /* 777FC 80086FFC 00500F48 */  mfc2       $t7, $10 /* handwritten instruction */
    /* 77800 80087000 00581848 */  mfc2       $t8, $11 /* handwritten instruction */
    /* 77804 80087004 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 77808 80087008 00088A48 */  mtc2       $t2, $1 /* handwritten instruction */
    /* 7780C 8008700C 00000000 */  nop
    /* 77810 80087010 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 77814 80087014 FFFF6B31 */  andi       $t3, $t3, 0xFFFF
    /* 77818 80087018 00740E00 */  sll        $t6, $t6, 16
    /* 7781C 8008701C 2570CB01 */  or         $t6, $t6, $t3
    /* 77820 80087020 0000CEAC */  sw         $t6, 0x0($a2)
    /* 77824 80087024 FFFFAD31 */  andi       $t5, $t5, 0xFFFF
    /* 77828 80087028 00C41800 */  sll        $t8, $t8, 16
    /* 7782C 8008702C 25C00D03 */  or         $t8, $t8, $t5
    /* 77830 80087030 0C00D8AC */  sw         $t8, 0xC($a2)
    /* 77834 80087034 00480848 */  mfc2       $t0, $9 /* handwritten instruction */
    /* 77838 80087038 00500948 */  mfc2       $t1, $10 /* handwritten instruction */
    /* 7783C 8008703C FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 77840 80087040 00640C00 */  sll        $t4, $t4, 16
    /* 77844 80087044 25400C01 */  or         $t0, $t0, $t4
    /* 77848 80087048 0400C8AC */  sw         $t0, 0x4($a2)
    /* 7784C 8008704C FFFFEF31 */  andi       $t7, $t7, 0xFFFF
    /* 77850 80087050 004C0900 */  sll        $t1, $t1, 16
    /* 77854 80087054 25482F01 */  or         $t1, $t1, $t7
    /* 77858 80087058 0800C9AC */  sw         $t1, 0x8($a2)
    /* 7785C 8008705C 1000CBE8 */  swc2       $11, 0x10($a2)
    /* 77860 80087060 2110C000 */  addu       $v0, $a2, $zero
    /* 77864 80087064 0800E003 */  jr         $ra
    /* 77868 80087068 00000000 */   nop
endlabel func_80086F60
    /* 7786C 8008706C 00000000 */  nop
