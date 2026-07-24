/* Handwritten function */
nonmatching func_800871D0, 0xA4

glabel func_800871D0
    /* 779D0 800871D0 09800E3C */  lui        $t6, %hi(D_80095334)
    /* 779D4 800871D4 3453CE8D */  lw         $t6, %lo(D_80095334)($t6)
    /* 779D8 800871D8 00000000 */  nop
    /* 779DC 800871DC 8002C129 */  slti       $at, $t6, 0x280
    /* 779E0 800871E0 0B002014 */  bnez       $at, .L80087210
    /* 779E4 800871E4 00000000 */   nop
    /* 779E8 800871E8 0980013C */  lui        $at, %hi(D_80095328)
    /* 779EC 800871EC 28533FAC */  sw         $ra, %lo(D_80095328)($at)
    /* 779F0 800871F0 0980043C */  lui        $a0, %hi(D_800955B8)
    /* 779F4 800871F4 1C3A020C */  jal        func_8008E870
    /* 779F8 800871F8 B8558424 */   addiu     $a0, $a0, %lo(D_800955B8)
    /* 779FC 800871FC 09801F3C */  lui        $ra, %hi(D_80095328)
    /* 77A00 80087200 2853FF8F */  lw         $ra, %lo(D_80095328)($ra)
    /* 77A04 80087204 00000000 */  nop
    /* 77A08 80087208 0800E003 */  jr         $ra
    /* 77A0C 8008720C 00000000 */   nop
  .L80087210:
    /* 77A10 80087210 09800F3C */  lui        $t7, %hi(D_80095338)
    /* 77A14 80087214 3853EF25 */  addiu      $t7, $t7, %lo(D_80095338)
    /* 77A18 80087218 2178EE01 */  addu       $t7, $t7, $t6
    /* 77A1C 8008721C 00004848 */  cfc2       $t0, $0 /* handwritten instruction */
    /* 77A20 80087220 00084948 */  cfc2       $t1, $1 /* handwritten instruction */
    /* 77A24 80087224 0000E8AD */  sw         $t0, 0x0($t7)
    /* 77A28 80087228 0400E9AD */  sw         $t1, 0x4($t7)
    /* 77A2C 8008722C 00104848 */  cfc2       $t0, $2 /* handwritten instruction */
    /* 77A30 80087230 00184948 */  cfc2       $t1, $3 /* handwritten instruction */
    /* 77A34 80087234 0800E8AD */  sw         $t0, 0x8($t7)
    /* 77A38 80087238 0C00E9AD */  sw         $t1, 0xC($t7)
    /* 77A3C 8008723C 00204848 */  cfc2       $t0, $4 /* handwritten instruction */
    /* 77A40 80087240 00000000 */  nop
    /* 77A44 80087244 1000E8AD */  sw         $t0, 0x10($t7)
    /* 77A48 80087248 00284848 */  cfc2       $t0, $5 /* handwritten instruction */
    /* 77A4C 8008724C 00304948 */  cfc2       $t1, $6 /* handwritten instruction */
    /* 77A50 80087250 00384A48 */  cfc2       $t2, $7 /* handwritten instruction */
    /* 77A54 80087254 1400E8AD */  sw         $t0, 0x14($t7)
    /* 77A58 80087258 1800E9AD */  sw         $t1, 0x18($t7)
    /* 77A5C 8008725C 1C00EAAD */  sw         $t2, 0x1C($t7)
    /* 77A60 80087260 2000CE21 */  addi       $t6, $t6, 0x20 /* handwritten instruction */
    /* 77A64 80087264 0980013C */  lui        $at, %hi(D_80095334)
    /* 77A68 80087268 34532EAC */  sw         $t6, %lo(D_80095334)($at)
    /* 77A6C 8008726C 0800E003 */  jr         $ra
    /* 77A70 80087270 00000000 */   nop
endlabel func_800871D0
