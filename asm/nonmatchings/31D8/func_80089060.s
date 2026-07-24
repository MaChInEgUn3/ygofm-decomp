/* Handwritten function */
nonmatching func_80089060, 0x1FC

glabel func_80089060
    /* 79860 80089060 04008884 */  lh         $t0, 0x4($a0)
    /* 79864 80089064 25100500 */  or         $v0, $zero, $a1
    /* 79868 80089068 0980033C */  lui        $v1, %hi(D_80095638)
    /* 7986C 8008906C 38566324 */  addiu      $v1, $v1, %lo(D_80095638)
    /* 79870 80089070 00008C8C */  lw         $t4, 0x0($a0)
    /* 79874 80089074 C35F0800 */  sra        $t3, $t0, 31
    /* 79878 80089078 20400B01 */  add        $t0, $t0, $t3 /* handwritten instruction */
    /* 7987C 8008907C 26400B01 */  xor        $t0, $t0, $t3
    /* 79880 80089080 80400800 */  sll        $t0, $t0, 2
    /* 79884 80089084 FC3F0831 */  andi       $t0, $t0, 0x3FFC
    /* 79888 80089088 20400301 */  add        $t0, $t0, $v1 /* handwritten instruction */
    /* 7988C 8008908C 0000068D */  lw         $a2, 0x0($t0)
    /* 79890 80089090 03440C00 */  sra        $t0, $t4, 16
    /* 79894 80089094 C3570800 */  sra        $t2, $t0, 31
    /* 79898 80089098 20400A01 */  add        $t0, $t0, $t2 /* handwritten instruction */
    /* 7989C 8008909C 26400A01 */  xor        $t0, $t0, $t2
    /* 798A0 800890A0 80400800 */  sll        $t0, $t0, 2
    /* 798A4 800890A4 FC3F0831 */  andi       $t0, $t0, 0x3FFC
    /* 798A8 800890A8 20400301 */  add        $t0, $t0, $v1 /* handwritten instruction */
    /* 798AC 800890AC 0000058D */  lw         $a1, 0x0($t0)
    /* 798B0 800890B0 00440C00 */  sll        $t0, $t4, 16
    /* 798B4 800890B4 03440800 */  sra        $t0, $t0, 16
    /* 798B8 800890B8 C34F0800 */  sra        $t1, $t0, 31
    /* 798BC 800890BC 20400901 */  add        $t0, $t0, $t1 /* handwritten instruction */
    /* 798C0 800890C0 26400901 */  xor        $t0, $t0, $t1
    /* 798C4 800890C4 80400800 */  sll        $t0, $t0, 2
    /* 798C8 800890C8 FC3F0831 */  andi       $t0, $t0, 0x3FFC
    /* 798CC 800890CC 20400301 */  add        $t0, $t0, $v1 /* handwritten instruction */
    /* 798D0 800890D0 0000048D */  lw         $a0, 0x0($t0)
    /* 798D4 800890D4 000C0600 */  sll        $at, $a2, 16
    /* 798D8 800890D8 03340600 */  sra        $a2, $a2, 16
    /* 798DC 800890DC 00340600 */  sll        $a2, $a2, 16
    /* 798E0 800890E0 20082B00 */  add        $at, $at, $t3 /* handwritten instruction */
    /* 798E4 800890E4 26082B00 */  xor        $at, $at, $t3
    /* 798E8 800890E8 020C0100 */  srl        $at, $at, 16
    /* 798EC 800890EC 2530C100 */  or         $a2, $a2, $at
    /* 798F0 800890F0 000C0500 */  sll        $at, $a1, 16
    /* 798F4 800890F4 032C0500 */  sra        $a1, $a1, 16
    /* 798F8 800890F8 002C0500 */  sll        $a1, $a1, 16
    /* 798FC 800890FC 20082A00 */  add        $at, $at, $t2 /* handwritten instruction */
    /* 79900 80089100 26082A00 */  xor        $at, $at, $t2
    /* 79904 80089104 020C0100 */  srl        $at, $at, 16
    /* 79908 80089108 2528A100 */  or         $a1, $a1, $at
    /* 7990C 8008910C 000C0400 */  sll        $at, $a0, 16
    /* 79910 80089110 03240400 */  sra        $a0, $a0, 16
    /* 79914 80089114 00240400 */  sll        $a0, $a0, 16
    /* 79918 80089118 20082900 */  add        $at, $at, $t1 /* handwritten instruction */
    /* 7991C 8008911C 26082900 */  xor        $at, $at, $t1
    /* 79920 80089120 020C0100 */  srl        $at, $at, 16
    /* 79924 80089124 25208100 */  or         $a0, $a0, $at
    /* 79928 80089128 03440500 */  sra        $t0, $a1, 16
    /* 7992C 8008912C 00408848 */  mtc2       $t0, $8 /* handwritten instruction */
    /* 79930 80089130 003C0400 */  sll        $a3, $a0, 16
    /* 79934 80089134 033C0700 */  sra        $a3, $a3, 16
    /* 79938 80089138 00488748 */  mtc2       $a3, $9 /* handwritten instruction */
    /* 7993C 8008913C 001C0600 */  sll        $v1, $a2, 16
    /* 79940 80089140 031C0300 */  sra        $v1, $v1, 16
    /* 79944 80089144 00508348 */  mtc2       $v1, $10 /* handwritten instruction */
    /* 79948 80089148 030C0600 */  sra        $at, $a2, 16
    /* 7994C 8008914C 00588148 */  mtc2       $at, $11 /* handwritten instruction */
    /* 79950 80089150 00000000 */  nop
    /* 79954 80089154 030C0400 */  sra        $at, $a0, 16
    /* 79958 80089158 3D00984B */  gpf        1
    /* 7995C 8008915C 18002800 */  mult       $at, $t0
    /* 79960 80089160 00480848 */  mfc2       $t0, $9 /* handwritten instruction */
    /* 79964 80089164 00500948 */  mfc2       $t1, $10 /* handwritten instruction */
    /* 79968 80089168 00740500 */  sll        $t6, $a1, 16
    /* 7996C 8008916C 00580A48 */  mfc2       $t2, $11 /* handwritten instruction */
    /* 79970 80089170 03740E00 */  sra        $t6, $t6, 16
    /* 79974 80089174 00408E48 */  mtc2       $t6, $8 /* handwritten instruction */
    /* 79978 80089178 00488748 */  mtc2       $a3, $9 /* handwritten instruction */
    /* 7997C 8008917C 00508348 */  mtc2       $v1, $10 /* handwritten instruction */
    /* 79980 80089180 030C0600 */  sra        $at, $a2, 16
    /* 79984 80089184 00588148 */  mtc2       $at, $11 /* handwritten instruction */
    /* 79988 80089188 00000000 */  nop
    /* 7998C 8008918C 3D00984B */  gpf        1
    /* 79990 80089190 12080000 */  mflo       $at
    /* 79994 80089194 030B0100 */  sra        $at, $at, 12
    /* 79998 80089198 100041A4 */  sh         $at, 0x10($v0)
    /* 7999C 8008919C 00480B48 */  mfc2       $t3, $9 /* handwritten instruction */
    /* 799A0 800891A0 00500C48 */  mfc2       $t4, $10 /* handwritten instruction */
    /* 799A4 800891A4 00580D48 */  mfc2       $t5, $11 /* handwritten instruction */
    /* 799A8 800891A8 030C0600 */  sra        $at, $a2, 16
    /* 799AC 800891AC 00408148 */  mtc2       $at, $8 /* handwritten instruction */
    /* 799B0 800891B0 030C0400 */  sra        $at, $a0, 16
    /* 799B4 800891B4 00488148 */  mtc2       $at, $9 /* handwritten instruction */
    /* 799B8 800891B8 18002E00 */  mult       $at, $t6
    /* 799BC 800891BC 00508B48 */  mtc2       $t3, $10 /* handwritten instruction */
    /* 799C0 800891C0 00588848 */  mtc2       $t0, $11 /* handwritten instruction */
    /* 799C4 800891C4 00000000 */  nop
    /* 799C8 800891C8 3D00984B */  gpf        1
    /* 799CC 800891CC 00480448 */  mfc2       $a0, $9 /* handwritten instruction */
    /* 799D0 800891D0 00500548 */  mfc2       $a1, $10 /* handwritten instruction */
    /* 799D4 800891D4 00580648 */  mfc2       $a2, $11 /* handwritten instruction */
    /* 799D8 800891D8 00408348 */  mtc2       $v1, $8 /* handwritten instruction */
    /* 799DC 800891DC 00488148 */  mtc2       $at, $9 /* handwritten instruction */
    /* 799E0 800891E0 00508B48 */  mtc2       $t3, $10 /* handwritten instruction */
    /* 799E4 800891E4 00588848 */  mtc2       $t0, $11 /* handwritten instruction */
    /* 799E8 800891E8 00000000 */  nop
    /* 799EC 800891EC 3D00984B */  gpf        1
    /* 799F0 800891F0 FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 799F4 800891F4 22380700 */  neg        $a3, $a3 /* handwritten instruction */
    /* 799F8 800891F8 003C0700 */  sll        $a3, $a3, 16
    /* 799FC 800891FC 25208700 */  or         $a0, $a0, $a3
    /* 79A00 80089200 080044AC */  sw         $a0, 0x8($v0)
    /* 79A04 80089204 00480148 */  mfc2       $at, $9 /* handwritten instruction */
    /* 79A08 80089208 2248A900 */  sub        $t1, $a1, $t1 /* handwritten instruction */
    /* 79A0C 8008920C 00500E48 */  mfc2       $t6, $10 /* handwritten instruction */
    /* 79A10 80089210 004C0900 */  sll        $t1, $t1, 16
    /* 79A14 80089214 00580F48 */  mfc2       $t7, $11 /* handwritten instruction */
    /* 79A18 80089218 20504E01 */  add        $t2, $t2, $t6 /* handwritten instruction */
    /* 79A1C 8008921C FFFF4A31 */  andi       $t2, $t2, 0xFFFF
    /* 79A20 80089220 25482A01 */  or         $t1, $t1, $t2
    /* 79A24 80089224 000049AC */  sw         $t1, 0x0($v0)
    /* 79A28 80089228 12480000 */  mflo       $t1
    /* 79A2C 8008922C 034B0900 */  sra        $t1, $t1, 12
    /* 79A30 80089230 FFFF2931 */  andi       $t1, $t1, 0xFFFF
    /* 79A34 80089234 000C0100 */  sll        $at, $at, 16
    /* 79A38 80089238 25082900 */  or         $at, $at, $t1
    /* 79A3C 8008923C 040041AC */  sw         $at, 0x4($v0)
    /* 79A40 80089240 2268ED01 */  sub        $t5, $t7, $t5 /* handwritten instruction */
    /* 79A44 80089244 FFFFAD31 */  andi       $t5, $t5, 0xFFFF
    /* 79A48 80089248 2060CC00 */  add        $t4, $a2, $t4 /* handwritten instruction */
    /* 79A4C 8008924C 00640C00 */  sll        $t4, $t4, 16
    /* 79A50 80089250 25608D01 */  or         $t4, $t4, $t5
    /* 79A54 80089254 0800E003 */  jr         $ra
    /* 79A58 80089258 0C004CAC */   sw        $t4, 0xC($v0)
endlabel func_80089060
    /* 79A5C 8008925C 00000000 */  nop
