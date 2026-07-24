/* Handwritten function */
nonmatching func_80087CC0, 0x64

glabel func_80087CC0
    /* 784C0 80087CC0 1400A88F */  lw         $t0, 0x14($sp)
    /* 784C4 80087CC4 1000AB8F */  lw         $t3, 0x10($sp)
    /* 784C8 80087CC8 00000000 */  nop
  .L80087CCC:
    /* 784CC 80087CCC 000080C8 */  lwc2       $0, 0x0($a0)
    /* 784D0 80087CD0 040081C8 */  lwc2       $1, 0x4($a0)
    /* 784D4 80087CD4 00000000 */  nop
    /* 784D8 80087CD8 0100184A */  rtps
    /* 784DC 80087CDC 08008420 */  addi       $a0, $a0, 0x8 /* handwritten instruction */
    /* 784E0 80087CE0 FFFF0821 */  addi       $t0, $t0, -0x1 /* handwritten instruction */
    /* 784E4 80087CE4 0000AEE8 */  swc2       $14, 0x0($a1)
    /* 784E8 80087CE8 00980A48 */  mfc2       $t2, $19 /* handwritten instruction */
    /* 784EC 80087CEC 00400C48 */  mfc2       $t4, $8 /* handwritten instruction */
    /* 784F0 80087CF0 00F84948 */  cfc2       $t1, $31 /* handwritten instruction */
    /* 784F4 80087CF4 0000CAA4 */  sh         $t2, 0x0($a2)
    /* 784F8 80087CF8 0000ECA4 */  sh         $t4, 0x0($a3)
    /* 784FC 80087CFC 024B0900 */  srl        $t1, $t1, 12
    /* 78500 80087D00 000069A5 */  sh         $t1, 0x0($t3)
    /* 78504 80087D04 0400A520 */  addi       $a1, $a1, 0x4 /* handwritten instruction */
    /* 78508 80087D08 0200C620 */  addi       $a2, $a2, 0x2 /* handwritten instruction */
    /* 7850C 80087D0C 0200E720 */  addi       $a3, $a3, 0x2 /* handwritten instruction */
    /* 78510 80087D10 02006B21 */  addi       $t3, $t3, 0x2 /* handwritten instruction */
    /* 78514 80087D14 EDFF001D */  bgtz       $t0, .L80087CCC
    /* 78518 80087D18 00000000 */   nop
    /* 7851C 80087D1C 0800E003 */  jr         $ra
    /* 78520 80087D20 00000000 */   nop
endlabel func_80087CC0
    /* 78524 80087D24 00000000 */  nop
    /* 78528 80087D28 00000000 */  nop
    /* 7852C 80087D2C 00000000 */  nop
