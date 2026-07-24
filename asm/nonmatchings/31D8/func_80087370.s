/* Handwritten function */
nonmatching func_80087370, 0x10C

glabel func_80087370
    /* 77B70 80087370 0000888C */  lw         $t0, 0x0($a0)
    /* 77B74 80087374 0400898C */  lw         $t1, 0x4($a0)
    /* 77B78 80087378 08008A8C */  lw         $t2, 0x8($a0)
    /* 77B7C 8008737C 0C008B8C */  lw         $t3, 0xC($a0)
    /* 77B80 80087380 10008C8C */  lw         $t4, 0x10($a0)
    /* 77B84 80087384 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 77B88 80087388 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 77B8C 8008738C 0010CA48 */  ctc2       $t2, $2 /* handwritten instruction */
    /* 77B90 80087390 0018CB48 */  ctc2       $t3, $3 /* handwritten instruction */
    /* 77B94 80087394 0020CC48 */  ctc2       $t4, $4 /* handwritten instruction */
    /* 77B98 80087398 0000A894 */  lhu        $t0, 0x0($a1)
    /* 77B9C 8008739C 0400A98C */  lw         $t1, 0x4($a1)
    /* 77BA0 800873A0 0C00AA8C */  lw         $t2, 0xC($a1)
    /* 77BA4 800873A4 FFFF013C */  lui        $at, (0xFFFF0000 >> 16)
    /* 77BA8 800873A8 24482101 */  and        $t1, $t1, $at
    /* 77BAC 800873AC 25400901 */  or         $t0, $t0, $t1
    /* 77BB0 800873B0 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 77BB4 800873B4 00088A48 */  mtc2       $t2, $1 /* handwritten instruction */
    /* 77BB8 800873B8 00000000 */  nop
    /* 77BBC 800873BC 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 77BC0 800873C0 0200A894 */  lhu        $t0, 0x2($a1)
    /* 77BC4 800873C4 0800A98C */  lw         $t1, 0x8($a1)
    /* 77BC8 800873C8 0E00AA84 */  lh         $t2, 0xE($a1)
    /* 77BCC 800873CC 004C0900 */  sll        $t1, $t1, 16
    /* 77BD0 800873D0 25400901 */  or         $t0, $t0, $t1
    /* 77BD4 800873D4 00480B48 */  mfc2       $t3, $9 /* handwritten instruction */
    /* 77BD8 800873D8 00500C48 */  mfc2       $t4, $10 /* handwritten instruction */
    /* 77BDC 800873DC 00580D48 */  mfc2       $t5, $11 /* handwritten instruction */
    /* 77BE0 800873E0 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 77BE4 800873E4 00088A48 */  mtc2       $t2, $1 /* handwritten instruction */
    /* 77BE8 800873E8 00000000 */  nop
    /* 77BEC 800873EC 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 77BF0 800873F0 0400A894 */  lhu        $t0, 0x4($a1)
    /* 77BF4 800873F4 0800A98C */  lw         $t1, 0x8($a1)
    /* 77BF8 800873F8 1000AA8C */  lw         $t2, 0x10($a1)
    /* 77BFC 800873FC FFFF013C */  lui        $at, (0xFFFF0000 >> 16)
    /* 77C00 80087400 24482101 */  and        $t1, $t1, $at
    /* 77C04 80087404 25400901 */  or         $t0, $t0, $t1
    /* 77C08 80087408 00480E48 */  mfc2       $t6, $9 /* handwritten instruction */
    /* 77C0C 8008740C 00500F48 */  mfc2       $t7, $10 /* handwritten instruction */
    /* 77C10 80087410 00581848 */  mfc2       $t8, $11 /* handwritten instruction */
    /* 77C14 80087414 00008848 */  mtc2       $t0, $0 /* handwritten instruction */
    /* 77C18 80087418 00088A48 */  mtc2       $t2, $1 /* handwritten instruction */
    /* 77C1C 8008741C 00000000 */  nop
    /* 77C20 80087420 1260484A */  mvmva      1, 0, 0, 3, 0
    /* 77C24 80087424 FFFF6B31 */  andi       $t3, $t3, 0xFFFF
    /* 77C28 80087428 00740E00 */  sll        $t6, $t6, 16
    /* 77C2C 8008742C 2570CB01 */  or         $t6, $t6, $t3
    /* 77C30 80087430 00008EAC */  sw         $t6, 0x0($a0)
    /* 77C34 80087434 FFFFAD31 */  andi       $t5, $t5, 0xFFFF
    /* 77C38 80087438 00C41800 */  sll        $t8, $t8, 16
    /* 77C3C 8008743C 25C00D03 */  or         $t8, $t8, $t5
    /* 77C40 80087440 0C0098AC */  sw         $t8, 0xC($a0)
    /* 77C44 80087444 00480848 */  mfc2       $t0, $9 /* handwritten instruction */
    /* 77C48 80087448 00500948 */  mfc2       $t1, $10 /* handwritten instruction */
    /* 77C4C 8008744C FFFF0831 */  andi       $t0, $t0, 0xFFFF
    /* 77C50 80087450 00640C00 */  sll        $t4, $t4, 16
    /* 77C54 80087454 25400C01 */  or         $t0, $t0, $t4
    /* 77C58 80087458 040088AC */  sw         $t0, 0x4($a0)
    /* 77C5C 8008745C FFFFEF31 */  andi       $t7, $t7, 0xFFFF
    /* 77C60 80087460 004C0900 */  sll        $t1, $t1, 16
    /* 77C64 80087464 25482F01 */  or         $t1, $t1, $t7
    /* 77C68 80087468 080089AC */  sw         $t1, 0x8($a0)
    /* 77C6C 8008746C 10008BE8 */  swc2       $11, 0x10($a0)
    /* 77C70 80087470 21108000 */  addu       $v0, $a0, $zero
    /* 77C74 80087474 0800E003 */  jr         $ra
    /* 77C78 80087478 00000000 */   nop
endlabel func_80087370
    /* 77C7C 8008747C 00000000 */  nop
