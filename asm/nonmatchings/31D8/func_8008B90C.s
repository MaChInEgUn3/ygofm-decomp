nonmatching func_8008B90C, 0x68

glabel func_8008B90C
    /* 7C10C 8008B90C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7C110 8008B910 1080033C */  lui        $v1, %hi(D_800FE348)
    /* 7C114 8008B914 48E36324 */  addiu      $v1, $v1, %lo(D_800FE348)
    /* 7C118 8008B918 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7C11C 8008B91C 0000628C */  lw         $v0, 0x0($v1)
    /* 7C120 8008B920 00000000 */  nop
    /* 7C124 8008B924 0B00401C */  bgtz       $v0, .L8008B954
    /* 7C128 8008B928 21288000 */   addu      $a1, $a0, $zero
    /* 7C12C 8008B92C 0980043C */  lui        $a0, %hi(func_8008B974)
    /* 7C130 8008B930 74B98424 */  addiu      $a0, $a0, %lo(func_8008B974)
    /* 7C134 8008B934 01000224 */  addiu      $v0, $zero, 0x1
    /* 7C138 8008B938 000062AC */  sw         $v0, 0x0($v1)
    /* 7C13C 8008B93C 040060AC */  sw         $zero, 0x4($v1)
    /* 7C140 8008B940 080060AC */  sw         $zero, 0x8($v1)
    /* 7C144 8008B944 3834020C */  jal        func_8008D0E0
    /* 7C148 8008B948 100065AC */   sw        $a1, 0x10($v1)
    /* 7C14C 8008B94C 592E0208 */  j          .L8008B964
    /* 7C150 8008B950 01000224 */   addiu     $v0, $zero, 0x1
  .L8008B954:
    /* 7C154 8008B954 0180043C */  lui        $a0, %hi(D_80012478)
    /* 7C158 8008B958 1C3A020C */  jal        func_8008E870
    /* 7C15C 8008B95C 78248424 */   addiu     $a0, $a0, %lo(D_80012478)
    /* 7C160 8008B960 21100000 */  addu       $v0, $zero, $zero
  .L8008B964:
    /* 7C164 8008B964 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7C168 8008B968 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7C16C 8008B96C 0800E003 */  jr         $ra
    /* 7C170 8008B970 00000000 */   nop
endlabel func_8008B90C
