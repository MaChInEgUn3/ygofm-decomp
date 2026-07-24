nonmatching func_8003D0F4, 0x80

glabel func_8003D0F4
    /* 2D8F4 8003D0F4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 2D8F8 8003D0F8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2D8FC 8003D0FC 21808000 */  addu       $s0, $a0, $zero
    /* 2D900 8003D100 1B80043C */  lui        $a0, %hi(D_801B125A)
    /* 2D904 8003D104 5A128424 */  addiu      $a0, $a0, %lo(D_801B125A)
    /* 2D908 8003D108 0C040526 */  addiu      $a1, $s0, 0x40C
    /* 2D90C 8003D10C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 2D910 8003D110 10EF000C */  jal        func_8003BC40
    /* 2D914 8003D114 06000624 */   addiu     $a2, $zero, 0x6
    /* 2D918 8003D118 0804028E */  lw         $v0, 0x408($s0)
    /* 2D91C 8003D11C 0404038E */  lw         $v1, 0x404($s0)
    /* 2D920 8003D120 0A80013C */  lui        $at, %hi(D_8009B0C4)
    /* 2D924 8003D124 C4B022AC */  sw         $v0, %lo(D_8009B0C4)($at)
    /* 2D928 8003D128 B00483AF */  sw         $v1, %gp_rel(D_8009B3B8)($gp)
    /* 2D92C 8003D12C DC050292 */  lbu        $v0, 0x5DC($s0)
    /* 2D930 8003D130 0A80033C */  lui        $v1, %hi(D_8009B408)
    /* 2D934 8003D134 08B46380 */  lb         $v1, %lo(D_8009B408)($v1)
    /* 2D938 8003D138 0A80013C */  lui        $at, %hi(D_8009B27A)
    /* 2D93C 8003D13C 7AB222A0 */  sb         $v0, %lo(D_8009B27A)($at)
    /* 2D940 8003D140 08006104 */  bgez       $v1, .L8003D164
    /* 2D944 8003D144 00000000 */   nop
    /* 2D948 8003D148 DE050292 */  lbu        $v0, 0x5DE($s0)
    /* 2D94C 8003D14C 00000000 */  nop
    /* 2D950 8003D150 00260200 */  sll        $a0, $v0, 24
    /* 2D954 8003D154 0A80013C */  lui        $at, %hi(D_8009B408)
    /* 2D958 8003D158 08B422A0 */  sb         $v0, %lo(D_8009B408)($at)
    /* 2D95C 8003D15C E81B010C */  jal        func_80046FA0
    /* 2D960 8003D160 03260400 */   sra       $a0, $a0, 24
  .L8003D164:
    /* 2D964 8003D164 1400BF8F */  lw         $ra, 0x14($sp)
    /* 2D968 8003D168 1000B08F */  lw         $s0, 0x10($sp)
    /* 2D96C 8003D16C 0800E003 */  jr         $ra
    /* 2D970 8003D170 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8003D0F4
