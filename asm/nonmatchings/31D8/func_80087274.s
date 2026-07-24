/* Handwritten function */
nonmatching func_80087274, 0xA4

glabel func_80087274
    /* 77A74 80087274 09800E3C */  lui        $t6, %hi(D_80095334)
    /* 77A78 80087278 3453CE8D */  lw         $t6, %lo(D_80095334)($t6)
    /* 77A7C 8008727C 00000000 */  nop
    /* 77A80 80087280 0B00C01D */  bgtz       $t6, .L800872B0
    /* 77A84 80087284 00000000 */   nop
    /* 77A88 80087288 0980013C */  lui        $at, %hi(D_80095328)
    /* 77A8C 8008728C 28533FAC */  sw         $ra, %lo(D_80095328)($at)
    /* 77A90 80087290 0980043C */  lui        $a0, %hi(D_800955E9)
    /* 77A94 80087294 1C3A020C */  jal        func_8008E870
    /* 77A98 80087298 E9558424 */   addiu     $a0, $a0, %lo(D_800955E9)
    /* 77A9C 8008729C 09801F3C */  lui        $ra, %hi(D_80095328)
    /* 77AA0 800872A0 2853FF8F */  lw         $ra, %lo(D_80095328)($ra)
    /* 77AA4 800872A4 00000000 */  nop
    /* 77AA8 800872A8 0800E003 */  jr         $ra
    /* 77AAC 800872AC 00000000 */   nop
  .L800872B0:
    /* 77AB0 800872B0 E0FFCE21 */  addi       $t6, $t6, -0x20 /* handwritten instruction */
    /* 77AB4 800872B4 0980013C */  lui        $at, %hi(D_80095334)
    /* 77AB8 800872B8 34532EAC */  sw         $t6, %lo(D_80095334)($at)
    /* 77ABC 800872BC 09800F3C */  lui        $t7, %hi(D_80095338)
    /* 77AC0 800872C0 3853EF25 */  addiu      $t7, $t7, %lo(D_80095338)
    /* 77AC4 800872C4 2178EE01 */  addu       $t7, $t7, $t6
    /* 77AC8 800872C8 0000E88D */  lw         $t0, 0x0($t7)
    /* 77ACC 800872CC 0400E98D */  lw         $t1, 0x4($t7)
    /* 77AD0 800872D0 0000C848 */  ctc2       $t0, $0 /* handwritten instruction */
    /* 77AD4 800872D4 0008C948 */  ctc2       $t1, $1 /* handwritten instruction */
    /* 77AD8 800872D8 0800E88D */  lw         $t0, 0x8($t7)
    /* 77ADC 800872DC 0C00E98D */  lw         $t1, 0xC($t7)
    /* 77AE0 800872E0 0010C848 */  ctc2       $t0, $2 /* handwritten instruction */
    /* 77AE4 800872E4 0018C948 */  ctc2       $t1, $3 /* handwritten instruction */
    /* 77AE8 800872E8 1000E88D */  lw         $t0, 0x10($t7)
    /* 77AEC 800872EC 00000000 */  nop
    /* 77AF0 800872F0 0020C848 */  ctc2       $t0, $4 /* handwritten instruction */
    /* 77AF4 800872F4 00000000 */  nop
    /* 77AF8 800872F8 1400E88D */  lw         $t0, 0x14($t7)
    /* 77AFC 800872FC 1800E98D */  lw         $t1, 0x18($t7)
    /* 77B00 80087300 1C00EA8D */  lw         $t2, 0x1C($t7)
    /* 77B04 80087304 0028C848 */  ctc2       $t0, $5 /* handwritten instruction */
    /* 77B08 80087308 0030C948 */  ctc2       $t1, $6 /* handwritten instruction */
    /* 77B0C 8008730C 0038CA48 */  ctc2       $t2, $7 /* handwritten instruction */
    /* 77B10 80087310 0800E003 */  jr         $ra
    /* 77B14 80087314 00000000 */   nop
endlabel func_80087274
    /* 77B18 80087318 00000000 */  nop
    /* 77B1C 8008731C 00000000 */  nop
