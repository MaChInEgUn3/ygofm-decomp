/* Handwritten function */
nonmatching func_80088E50, 0x210

glabel func_80088E50
    /* 79650 80088E50 25100500 */  or         $v0, $zero, $a1
    /* 79654 80088E54 04008884 */  lh         $t0, 0x4($a0)
    /* 79658 80088E58 0980033C */  lui        $v1, %hi(D_80095638)
    /* 7965C 80088E5C 38566324 */  addiu      $v1, $v1, %lo(D_80095638)
    /* 79660 80088E60 00008C8C */  lw         $t4, 0x0($a0)
    /* 79664 80088E64 C35F0800 */  sra        $t3, $t0, 31
    /* 79668 80088E68 20400B01 */  add        $t0, $t0, $t3 /* handwritten instruction */
    /* 7966C 80088E6C 26400B01 */  xor        $t0, $t0, $t3
    /* 79670 80088E70 80400800 */  sll        $t0, $t0, 2
    /* 79674 80088E74 FC3F0831 */  andi       $t0, $t0, 0x3FFC
    /* 79678 80088E78 20400301 */  add        $t0, $t0, $v1 /* handwritten instruction */
    /* 7967C 80088E7C 0000068D */  lw         $a2, 0x0($t0)
    /* 79680 80088E80 03440C00 */  sra        $t0, $t4, 16
    /* 79684 80088E84 C3570800 */  sra        $t2, $t0, 31
    /* 79688 80088E88 20400A01 */  add        $t0, $t0, $t2 /* handwritten instruction */
    /* 7968C 80088E8C 26400A01 */  xor        $t0, $t0, $t2
    /* 79690 80088E90 80400800 */  sll        $t0, $t0, 2
    /* 79694 80088E94 FC3F0831 */  andi       $t0, $t0, 0x3FFC
    /* 79698 80088E98 20400301 */  add        $t0, $t0, $v1 /* handwritten instruction */
    /* 7969C 80088E9C 0000058D */  lw         $a1, 0x0($t0)
    /* 796A0 80088EA0 00440C00 */  sll        $t0, $t4, 16
    /* 796A4 80088EA4 03440800 */  sra        $t0, $t0, 16
    /* 796A8 80088EA8 C34F0800 */  sra        $t1, $t0, 31
    /* 796AC 80088EAC 20400901 */  add        $t0, $t0, $t1 /* handwritten instruction */
    /* 796B0 80088EB0 26400901 */  xor        $t0, $t0, $t1
    /* 796B4 80088EB4 80400800 */  sll        $t0, $t0, 2
    /* 796B8 80088EB8 FC3F0831 */  andi       $t0, $t0, 0x3FFC
    /* 796BC 80088EBC 20400301 */  add        $t0, $t0, $v1 /* handwritten instruction */
    /* 796C0 80088EC0 0000048D */  lw         $a0, 0x0($t0)
    /* 796C4 80088EC4 000C0600 */  sll        $at, $a2, 16
    /* 796C8 80088EC8 03340600 */  sra        $a2, $a2, 16
    /* 796CC 80088ECC 00340600 */  sll        $a2, $a2, 16
    /* 796D0 80088ED0 20082B00 */  add        $at, $at, $t3 /* handwritten instruction */
    /* 796D4 80088ED4 26082B00 */  xor        $at, $at, $t3
    /* 796D8 80088ED8 020C0100 */  srl        $at, $at, 16
    /* 796DC 80088EDC 2530C100 */  or         $a2, $a2, $at
    /* 796E0 80088EE0 000C0500 */  sll        $at, $a1, 16
    /* 796E4 80088EE4 032C0500 */  sra        $a1, $a1, 16
    /* 796E8 80088EE8 002C0500 */  sll        $a1, $a1, 16
    /* 796EC 80088EEC 20082A00 */  add        $at, $at, $t2 /* handwritten instruction */
    /* 796F0 80088EF0 26082A00 */  xor        $at, $at, $t2
    /* 796F4 80088EF4 020C0100 */  srl        $at, $at, 16
    /* 796F8 80088EF8 2528A100 */  or         $a1, $a1, $at
    /* 796FC 80088EFC 000C0400 */  sll        $at, $a0, 16
    /* 79700 80088F00 03240400 */  sra        $a0, $a0, 16
    /* 79704 80088F04 00240400 */  sll        $a0, $a0, 16
    /* 79708 80088F08 20082900 */  add        $at, $at, $t1 /* handwritten instruction */
    /* 7970C 80088F0C 26082900 */  xor        $at, $at, $t1
    /* 79710 80088F10 020C0100 */  srl        $at, $at, 16
    /* 79714 80088F14 25208100 */  or         $a0, $a0, $at
    /* 79718 80088F18 03440400 */  sra        $t0, $a0, 16
    /* 7971C 80088F1C 00408848 */  mtc2       $t0, $8 /* handwritten instruction */
    /* 79720 80088F20 003C0500 */  sll        $a3, $a1, 16
    /* 79724 80088F24 033C0700 */  sra        $a3, $a3, 16
    /* 79728 80088F28 00488748 */  mtc2       $a3, $9 /* handwritten instruction */
    /* 7972C 80088F2C 001C0600 */  sll        $v1, $a2, 16
    /* 79730 80088F30 031C0300 */  sra        $v1, $v1, 16
    /* 79734 80088F34 00508348 */  mtc2       $v1, $10 /* handwritten instruction */
    /* 79738 80088F38 030C0600 */  sra        $at, $a2, 16
    /* 7973C 80088F3C 00588148 */  mtc2       $at, $11 /* handwritten instruction */
    /* 79740 80088F40 00000000 */  nop
    /* 79744 80088F44 00000000 */  nop
    /* 79748 80088F48 3D00984B */  gpf        1
    /* 7974C 80088F4C 030C0500 */  sra        $at, $a1, 16
    /* 79750 80088F50 18002800 */  mult       $at, $t0
    /* 79754 80088F54 00480848 */  mfc2       $t0, $9 /* handwritten instruction */
    /* 79758 80088F58 00500948 */  mfc2       $t1, $10 /* handwritten instruction */
    /* 7975C 80088F5C 00740400 */  sll        $t6, $a0, 16
    /* 79760 80088F60 00580A48 */  mfc2       $t2, $11 /* handwritten instruction */
    /* 79764 80088F64 03740E00 */  sra        $t6, $t6, 16
    /* 79768 80088F68 00408E48 */  mtc2       $t6, $8 /* handwritten instruction */
    /* 7976C 80088F6C 00488748 */  mtc2       $a3, $9 /* handwritten instruction */
    /* 79770 80088F70 00508348 */  mtc2       $v1, $10 /* handwritten instruction */
    /* 79774 80088F74 030C0600 */  sra        $at, $a2, 16
    /* 79778 80088F78 00588148 */  mtc2       $at, $11 /* handwritten instruction */
    /* 7977C 80088F7C 00000000 */  nop
    /* 79780 80088F80 00000000 */  nop
    /* 79784 80088F84 3D00984B */  gpf        1
    /* 79788 80088F88 12080000 */  mflo       $at
    /* 7978C 80088F8C 030B0100 */  sra        $at, $at, 12
    /* 79790 80088F90 100041A4 */  sh         $at, 0x10($v0)
    /* 79794 80088F94 00480B48 */  mfc2       $t3, $9 /* handwritten instruction */
    /* 79798 80088F98 00500C48 */  mfc2       $t4, $10 /* handwritten instruction */
    /* 7979C 80088F9C 00580D48 */  mfc2       $t5, $11 /* handwritten instruction */
    /* 797A0 80088FA0 030C0600 */  sra        $at, $a2, 16
    /* 797A4 80088FA4 00408148 */  mtc2       $at, $8 /* handwritten instruction */
    /* 797A8 80088FA8 030C0500 */  sra        $at, $a1, 16
    /* 797AC 80088FAC 00488148 */  mtc2       $at, $9 /* handwritten instruction */
    /* 797B0 80088FB0 18002E00 */  mult       $at, $t6
    /* 797B4 80088FB4 00508B48 */  mtc2       $t3, $10 /* handwritten instruction */
    /* 797B8 80088FB8 00588848 */  mtc2       $t0, $11 /* handwritten instruction */
    /* 797BC 80088FBC 00000000 */  nop
    /* 797C0 80088FC0 00000000 */  nop
    /* 797C4 80088FC4 3D00984B */  gpf        1
    /* 797C8 80088FC8 00480448 */  mfc2       $a0, $9 /* handwritten instruction */
    /* 797CC 80088FCC 00500548 */  mfc2       $a1, $10 /* handwritten instruction */
    /* 797D0 80088FD0 00580648 */  mfc2       $a2, $11 /* handwritten instruction */
    /* 797D4 80088FD4 00408348 */  mtc2       $v1, $8 /* handwritten instruction */
    /* 797D8 80088FD8 00488148 */  mtc2       $at, $9 /* handwritten instruction */
    /* 797DC 80088FDC 00508B48 */  mtc2       $t3, $10 /* handwritten instruction */
    /* 797E0 80088FE0 00588848 */  mtc2       $t0, $11 /* handwritten instruction */
    /* 797E4 80088FE4 00000000 */  nop
    /* 797E8 80088FE8 00000000 */  nop
    /* 797EC 80088FEC 3D00984B */  gpf        1
    /* 797F0 80088FF0 2048A900 */  add        $t1, $a1, $t1 /* handwritten instruction */
    /* 797F4 80088FF4 004C0900 */  sll        $t1, $t1, 16
    /* 797F8 80088FF8 FFFFE730 */  andi       $a3, $a3, 0xFFFF
    /* 797FC 80088FFC 25482701 */  or         $t1, $t1, $a3
    /* 79800 80089000 040049AC */  sw         $t1, 0x4($v0)
    /* 79804 80089004 00480148 */  mfc2       $at, $9 /* handwritten instruction */
    /* 79808 80089008 FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 7980C 8008900C 22080100 */  neg        $at, $at /* handwritten instruction */
    /* 79810 80089010 000C0100 */  sll        $at, $at, 16
    /* 79814 80089014 25082400 */  or         $at, $at, $a0
    /* 79818 80089018 000041AC */  sw         $at, 0x0($v0)
    /* 7981C 8008901C 00500E48 */  mfc2       $t6, $10 /* handwritten instruction */
    /* 79820 80089020 12080000 */  mflo       $at
    /* 79824 80089024 00580F48 */  mfc2       $t7, $11 /* handwritten instruction */
    /* 79828 80089028 22504E01 */  sub        $t2, $t2, $t6 /* handwritten instruction */
    /* 7982C 8008902C 030B0100 */  sra        $at, $at, 12
    /* 79830 80089030 22080100 */  neg        $at, $at /* handwritten instruction */
    /* 79834 80089034 FFFF4A31 */  andi       $t2, $t2, 0xFFFF
    /* 79838 80089038 000C0100 */  sll        $at, $at, 16
    /* 7983C 8008903C 25082A00 */  or         $at, $at, $t2
    /* 79840 80089040 080041AC */  sw         $at, 0x8($v0)
    /* 79844 80089044 22608601 */  sub        $t4, $t4, $a2 /* handwritten instruction */
    /* 79848 80089048 FFFF8C31 */  andi       $t4, $t4, 0xFFFF
    /* 7984C 8008904C 2068AF01 */  add        $t5, $t5, $t7 /* handwritten instruction */
    /* 79850 80089050 006C0D00 */  sll        $t5, $t5, 16
    /* 79854 80089054 25608D01 */  or         $t4, $t4, $t5
    /* 79858 80089058 0800E003 */  jr         $ra
    /* 7985C 8008905C 0C004CAC */   sw        $t4, 0xC($v0)
endlabel func_80088E50
