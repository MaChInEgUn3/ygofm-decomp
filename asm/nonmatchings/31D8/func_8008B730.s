nonmatching func_8008B730, 0x70

glabel func_8008B730
    /* 7BF30 8008B730 1080013C */  lui        $at, %hi(D_800FE308)
    /* 7BF34 8008B734 08E33FAC */  sw         $ra, %lo(D_800FE308)($at)
    /* 7BF38 8008B738 2CCE010C */  jal        func_800738B0
    /* 7BF3C 8008B73C 00000000 */   nop
    /* 7BF40 8008B740 56000924 */  addiu      $t1, $zero, 0x56
    /* 7BF44 8008B744 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 7BF48 8008B748 09F84001 */  jalr       $t2
    /* 7BF4C 8008B74C 00000000 */   nop
    /* 7BF50 8008B750 1800428C */  lw         $v0, 0x18($v0)
    /* 7BF54 8008B754 09800A3C */  lui        $t2, %hi(D_8008B7A0)
    /* 7BF58 8008B758 A0B74A25 */  addiu      $t2, $t2, %lo(D_8008B7A0)
    /* 7BF5C 8008B75C 0980093C */  lui        $t1, %hi(D_8008B7AC)
    /* 7BF60 8008B760 ACB72925 */  addiu      $t1, $t1, %lo(D_8008B7AC)
  .L8008B764:
    /* 7BF64 8008B764 0000438D */  lw         $v1, 0x0($t2)
    /* 7BF68 8008B768 00000000 */  nop
    /* 7BF6C 8008B76C 700043AC */  sw         $v1, 0x70($v0)
    /* 7BF70 8008B770 04004A25 */  addiu      $t2, $t2, 0x4
    /* 7BF74 8008B774 FBFF4915 */  bne        $t2, $t1, .L8008B764
    /* 7BF78 8008B778 04004224 */   addiu     $v0, $v0, 0x4
    /* 7BF7C 8008B77C 3CD0010C */  jal        func_800740F0
    /* 7BF80 8008B780 00000000 */   nop
    /* 7BF84 8008B784 30CE010C */  jal        func_800738C0
    /* 7BF88 8008B788 00000000 */   nop
    /* 7BF8C 8008B78C 10801F3C */  lui        $ra, %hi(D_800FE308)
    /* 7BF90 8008B790 08E3FF8F */  lw         $ra, %lo(D_800FE308)($ra)
    /* 7BF94 8008B794 00000000 */  nop
    /* 7BF98 8008B798 0800E003 */  jr         $ra
    /* 7BF9C 8008B79C 00000000 */   nop
endlabel func_8008B730
  alabel D_8008B7A0
    /* 7BFA0 8008B7A0 00000000 */  nop
    /* 7BFA4 8008B7A4 00000000 */  nop
    /* 7BFA8 8008B7A8 00000000 */  nop
  alabel D_8008B7AC
    /* 7BFAC 8008B7AC 00000000 */  nop
