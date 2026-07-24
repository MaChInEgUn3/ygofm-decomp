nonmatching func_8002D0E0, 0xA0

glabel func_8002D0E0
    /* 1D8E0 8002D0E0 64038393 */  lbu        $v1, %gp_rel(D_8009B26C)($gp)
    /* 1D8E4 8002D0E4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1D8E8 8002D0E8 40006230 */  andi       $v0, $v1, 0x40
    /* 1D8EC 8002D0EC 09004014 */  bnez       $v0, .L8002D114
    /* 1D8F0 8002D0F0 1000BFAF */   sw        $ra, 0x10($sp)
    /* 1D8F4 8002D0F4 40006234 */  ori        $v0, $v1, 0x40
    /* 1D8F8 8002D0F8 640382A3 */  sb         $v0, %gp_rel(D_8009B26C)($gp)
    /* 1D8FC 8002D0FC F3AF000C */  jal        func_8002BFCC
    /* 1D900 8002D100 00000000 */   nop
    /* 1D904 8002D104 8056000C */  jal        func_80015A00
    /* 1D908 8002D108 00000000 */   nop
    /* 1D90C 8002D10C 5CB40008 */  j          .L8002D170
    /* 1D910 8002D110 00000000 */   nop
  .L8002D114:
    /* 1D914 8002D114 ADAE000C */  jal        func_8002BAB4
    /* 1D918 8002D118 00000000 */   nop
    /* 1D91C 8002D11C 64038293 */  lbu        $v0, %gp_rel(D_8009B26C)($gp)
    /* 1D920 8002D120 00000000 */  nop
    /* 1D924 8002D124 40004230 */  andi       $v0, $v0, 0x40
    /* 1D928 8002D128 11004014 */  bnez       $v0, .L8002D170
    /* 1D92C 8002D12C 00000000 */   nop
    /* 1D930 8002D130 0A80013C */  lui        $at, %hi(D_8009B0C0)
    /* 1D934 8002D134 C0B020A0 */  sb         $zero, %lo(D_8009B0C0)($at)
    /* 1D938 8002D138 CDFF000C */  jal        func_8003FF34
    /* 1D93C 8002D13C 00000000 */   nop
    /* 1D940 8002D140 C056000C */  jal        func_80015B00
    /* 1D944 8002D144 00000000 */   nop
    /* 1D948 8002D148 2D4D000C */  jal        func_800134B4
    /* 1D94C 8002D14C 00000000 */   nop
    /* 1D950 8002D150 8F1D010C */  jal        func_8004763C
    /* 1D954 8002D154 00000000 */   nop
    /* 1D958 8002D158 B41E010C */  jal        func_80047AD0
    /* 1D95C 8002D15C 02000424 */   addiu     $a0, $zero, 0x2
    /* 1D960 8002D160 614B000C */  jal        func_80012D84
    /* 1D964 8002D164 04000424 */   addiu     $a0, $zero, 0x4
    /* 1D968 8002D168 F94D000C */  jal        func_800137E4
    /* 1D96C 8002D16C 00000000 */   nop
  .L8002D170:
    /* 1D970 8002D170 1000BF8F */  lw         $ra, 0x10($sp)
    /* 1D974 8002D174 00000000 */  nop
    /* 1D978 8002D178 0800E003 */  jr         $ra
    /* 1D97C 8002D17C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002D0E0
