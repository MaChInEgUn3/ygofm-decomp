nonmatching func_8008D0E0, 0x7C

glabel func_8008D0E0
    /* 7D8E0 8008D0E0 0A80023C */  lui        $v0, %hi(D_80099EA8)
    /* 7D8E4 8008D0E4 A89E428C */  lw         $v0, %lo(D_80099EA8)($v0)
    /* 7D8E8 8008D0E8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7D8EC 8008D0EC 01004624 */  addiu      $a2, $v0, 0x1
    /* 7D8F0 8008D0F0 0400C228 */  slti       $v0, $a2, 0x4
    /* 7D8F4 8008D0F4 06004014 */  bnez       $v0, .L8008D110
    /* 7D8F8 8008D0F8 1000BFAF */   sw        $ra, 0x10($sp)
    /* 7D8FC 8008D0FC 0180043C */  lui        $a0, %hi(D_80012648)
    /* 7D900 8008D100 1C3A020C */  jal        func_8008E870
    /* 7D904 8008D104 48268424 */   addiu     $a0, $a0, %lo(D_80012648)
    /* 7D908 8008D108 53340208 */  j          .L8008D14C
    /* 7D90C 8008D10C 00000000 */   nop
  .L8008D110:
    /* 7D910 8008D110 03000524 */  addiu      $a1, $zero, 0x3
    /* 7D914 8008D114 00110600 */  sll        $v0, $a2, 4
    /* 7D918 8008D118 1080033C */  lui        $v1, %hi(D_800FE3B4)
    /* 7D91C 8008D11C B4E36324 */  addiu      $v1, $v1, %lo(D_800FE3B4)
    /* 7D920 8008D120 21184300 */  addu       $v1, $v0, $v1
    /* 7D924 8008D124 80100600 */  sll        $v0, $a2, 2
    /* 7D928 8008D128 0A80013C */  lui        $at, %hi(D_80099EA8)
    /* 7D92C 8008D12C A89E26AC */  sw         $a2, %lo(D_80099EA8)($at)
    /* 7D930 8008D130 1080013C */  lui        $at, %hi(D_800FE3E8)
    /* 7D934 8008D134 21082200 */  addu       $at, $at, $v0
    /* 7D938 8008D138 E8E324AC */  sw         $a0, %lo(D_800FE3E8)($at)
  .L8008D13C:
    /* 7D93C 8008D13C 000060AC */  sw         $zero, 0x0($v1)
    /* 7D940 8008D140 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 7D944 8008D144 FDFFA104 */  bgez       $a1, .L8008D13C
    /* 7D948 8008D148 FCFF6324 */   addiu     $v1, $v1, -0x4
  .L8008D14C:
    /* 7D94C 8008D14C 1000BF8F */  lw         $ra, 0x10($sp)
    /* 7D950 8008D150 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 7D954 8008D154 0800E003 */  jr         $ra
    /* 7D958 8008D158 00000000 */   nop
endlabel func_8008D0E0
