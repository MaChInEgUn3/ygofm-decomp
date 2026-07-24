/* Handwritten function */
nonmatching func_8006A99C, 0x160

glabel func_8006A99C
    /* 5B19C 8006A99C 0000878C */  lw         $a3, 0x0($a0)
    /* 5B1A0 8006A9A0 1000998C */  lw         $t9, 0x10($a0)
    /* 5B1A4 8006A9A4 0200F894 */  lhu        $t8, 0x2($a3)
    /* 5B1A8 8006A9A8 0400E68C */  lw         $a2, 0x4($a3)
    /* 5B1AC 8006A9AC 1400858C */  lw         $a1, 0x14($a0)
    /* 5B1B0 8006A9B0 80300600 */  sll        $a2, $a2, 2
    /* 5B1B4 8006A9B4 280090AC */  sw         $s0, 0x28($a0)
    /* 5B1B8 8006A9B8 2C0091AC */  sw         $s1, 0x2C($a0)
    /* 5B1BC 8006A9BC 300092AC */  sw         $s2, 0x30($a0)
    /* 5B1C0 8006A9C0 0A800D3C */  lui        $t5, %hi(D_8009AFE4)
    /* 5B1C4 8006A9C4 E4AFAD8D */  lw         $t5, %lo(D_8009AFE4)($t5)
    /* 5B1C8 8006A9C8 43000013 */  beqz       $t8, .L8006AAD8
    /* 5B1CC 8006A9CC 00000000 */   nop
    /* 5B1D0 8006A9D0 01000124 */  addiu      $at, $zero, 0x1
    /* 5B1D4 8006A9D4 4000A111 */  beq        $t5, $at, .L8006AAD8
    /* 5B1D8 8006A9D8 2138A600 */   addu      $a3, $a1, $a2
    /* 5B1DC 8006A9DC 0A80103C */  lui        $s0, %hi(D_8009AFD0)
    /* 5B1E0 8006A9E0 D0AF108E */  lw         $s0, %lo(D_8009AFD0)($s0)
    /* 5B1E4 8006A9E4 0A80113C */  lui        $s1, %hi(D_8009AFD4)
    /* 5B1E8 8006A9E8 D4AF318E */  lw         $s1, %lo(D_8009AFD4)($s1)
    /* 5B1EC 8006A9EC 5555123C */  lui        $s2, (0x55555555 >> 16)
    /* 5B1F0 8006A9F0 55555236 */  ori        $s2, $s2, (0x55555555 & 0xFFFF)
    /* 5B1F4 8006A9F4 1C00858C */  lw         $a1, 0x1C($a0)
    /* 5B1F8 8006A9F8 2400868C */  lw         $a2, 0x24($a0)
    /* 5B1FC 8006A9FC 04008D8C */  lw         $t5, 0x4($a0)
    /* 5B200 8006AA00 08008E8C */  lw         $t6, 0x8($a0)
    /* 5B204 8006AA04 0400AF8D */  lw         $t7, 0x4($t5)
  .L8006AA08:
    /* 5B208 8006AA08 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 5B20C 8006AA0C 0C00E88C */  lw         $t0, 0xC($a3)
    /* 5B210 8006AA10 1000E98C */  lw         $t1, 0x10($a3)
    /* 5B214 8006AA14 1400EA8C */  lw         $t2, 0x14($a3)
    /* 5B218 8006AA18 026C0800 */  srl        $t5, $t0, 16
    /* 5B21C 8006AA1C C0680D00 */  sll        $t5, $t5, 3
    /* 5B220 8006AA20 2168A501 */  addu       $t5, $t5, $a1
    /* 5B224 8006AA24 0400A28D */  lw         $v0, 0x4($t5)
    /* 5B228 8006AA28 0000AD8D */  lw         $t5, 0x0($t5)
    /* 5B22C 8006AA2C 27004310 */  beq        $v0, $v1, .L8006AACC
    /* 5B230 8006AA30 0C002DAF */   sw        $t5, 0xC($t9)
    /* 5B234 8006AA34 00888248 */  mtc2       $v0, $17 /* handwritten instruction */
    /* 5B238 8006AA38 18002DAF */  sw         $t5, 0x18($t9)
    /* 5B23C 8006AA3C 026C0900 */  srl        $t5, $t1, 16
    /* 5B240 8006AA40 C0680D00 */  sll        $t5, $t5, 3
    /* 5B244 8006AA44 2168A501 */  addu       $t5, $t5, $a1
    /* 5B248 8006AA48 0400A28D */  lw         $v0, 0x4($t5)
    /* 5B24C 8006AA4C 0000AD8D */  lw         $t5, 0x0($t5)
    /* 5B250 8006AA50 1E004310 */  beq        $v0, $v1, .L8006AACC
    /* 5B254 8006AA54 10002DAF */   sw        $t5, 0x10($t9)
    /* 5B258 8006AA58 00908248 */  mtc2       $v0, $18 /* handwritten instruction */
    /* 5B25C 8006AA5C 026C0A00 */  srl        $t5, $t2, 16
    /* 5B260 8006AA60 C0680D00 */  sll        $t5, $t5, 3
    /* 5B264 8006AA64 2168A501 */  addu       $t5, $t5, $a1
    /* 5B268 8006AA68 0400A28D */  lw         $v0, 0x4($t5)
    /* 5B26C 8006AA6C 0000AD8D */  lw         $t5, 0x0($t5)
    /* 5B270 8006AA70 16004310 */  beq        $v0, $v1, .L8006AACC
    /* 5B274 8006AA74 14002DAF */   sw        $t5, 0x14($t9)
    /* 5B278 8006AA78 00988248 */  mtc2       $v0, $19 /* handwritten instruction */
    /* 5B27C 8006AA7C 040031AF */  sw         $s1, 0x4($t9)
    /* 5B280 8006AA80 1C0032AF */  sw         $s2, 0x1C($t9)
    /* 5B284 8006AA84 2D00584B */  avsz3
    /* 5B288 8006AA88 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 5B28C 8006AA8C 080030AF */  sw         $s0, 0x8($t9)
    /* 5B290 8006AA90 0610C201 */  srlv       $v0, $v0, $t6
    /* 5B294 8006AA94 80100200 */  sll        $v0, $v0, 2
    /* 5B298 8006AA98 21104F00 */  addu       $v0, $v0, $t7
    /* 5B29C 8006AA9C 00004D8C */  lw         $t5, 0x0($v0)
    /* 5B2A0 8006AAA0 00000000 */  nop
    /* 5B2A4 8006AAA4 006A0D00 */  sll        $t5, $t5, 8
    /* 5B2A8 8006AAA8 0700AD35 */  ori        $t5, $t5, 0x7
    /* 5B2AC 8006AAAC 020A0D00 */  srl        $at, $t5, 8
    /* 5B2B0 8006AAB0 006E0D00 */  sll        $t5, $t5, 24
    /* 5B2B4 8006AAB4 2568A101 */  or         $t5, $t5, $at
    /* 5B2B8 8006AAB8 00002DAF */  sw         $t5, 0x0($t9)
    /* 5B2BC 8006AABC 006A1900 */  sll        $t5, $t9, 8
    /* 5B2C0 8006AAC0 026A0D00 */  srl        $t5, $t5, 8
    /* 5B2C4 8006AAC4 00004DAC */  sw         $t5, 0x0($v0)
    /* 5B2C8 8006AAC8 20003927 */  addiu      $t9, $t9, 0x20
  .L8006AACC:
    /* 5B2CC 8006AACC FFFF1827 */  addiu      $t8, $t8, -0x1
    /* 5B2D0 8006AAD0 CDFF0017 */  bnez       $t8, .L8006AA08
    /* 5B2D4 8006AAD4 1800E724 */   addiu     $a3, $a3, 0x18
  .L8006AAD8:
    /* 5B2D8 8006AAD8 2800908C */  lw         $s0, 0x28($a0)
    /* 5B2DC 8006AADC 2C00918C */  lw         $s1, 0x2C($a0)
    /* 5B2E0 8006AAE0 3000928C */  lw         $s2, 0x30($a0)
    /* 5B2E4 8006AAE4 0000828C */  lw         $v0, 0x0($a0)
    /* 5B2E8 8006AAE8 1080013C */  lui        $at, %hi(D_800FE240)
    /* 5B2EC 8006AAEC 40E239AC */  sw         $t9, %lo(D_800FE240)($at)
    /* 5B2F0 8006AAF0 08004224 */  addiu      $v0, $v0, 0x8
    /* 5B2F4 8006AAF4 0800E003 */  jr         $ra
    /* 5B2F8 8006AAF8 00000000 */   nop
endlabel func_8006A99C
