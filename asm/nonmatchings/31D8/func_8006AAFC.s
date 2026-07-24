/* Handwritten function */
nonmatching func_8006AAFC, 0x18C

glabel func_8006AAFC
    /* 5B2FC 8006AAFC 0000878C */  lw         $a3, 0x0($a0)
    /* 5B300 8006AB00 1000998C */  lw         $t9, 0x10($a0)
    /* 5B304 8006AB04 0200F894 */  lhu        $t8, 0x2($a3)
    /* 5B308 8006AB08 0400E68C */  lw         $a2, 0x4($a3)
    /* 5B30C 8006AB0C 1400858C */  lw         $a1, 0x14($a0)
    /* 5B310 8006AB10 80300600 */  sll        $a2, $a2, 2
    /* 5B314 8006AB14 280090AC */  sw         $s0, 0x28($a0)
    /* 5B318 8006AB18 2C0091AC */  sw         $s1, 0x2C($a0)
    /* 5B31C 8006AB1C 300092AC */  sw         $s2, 0x30($a0)
    /* 5B320 8006AB20 0A800D3C */  lui        $t5, %hi(D_8009AFE4)
    /* 5B324 8006AB24 E4AFAD8D */  lw         $t5, %lo(D_8009AFE4)($t5)
    /* 5B328 8006AB28 4E000013 */  beqz       $t8, .L8006AC64
    /* 5B32C 8006AB2C 00000000 */   nop
    /* 5B330 8006AB30 01000124 */  addiu      $at, $zero, 0x1
    /* 5B334 8006AB34 4B00A111 */  beq        $t5, $at, .L8006AC64
    /* 5B338 8006AB38 2138A600 */   addu      $a3, $a1, $a2
    /* 5B33C 8006AB3C 0A80103C */  lui        $s0, %hi(D_8009AFCC)
    /* 5B340 8006AB40 CCAF108E */  lw         $s0, %lo(D_8009AFCC)($s0)
    /* 5B344 8006AB44 0A80113C */  lui        $s1, %hi(D_8009AFD4)
    /* 5B348 8006AB48 D4AF318E */  lw         $s1, %lo(D_8009AFD4)($s1)
    /* 5B34C 8006AB4C 5555123C */  lui        $s2, (0x55555555 >> 16)
    /* 5B350 8006AB50 55555236 */  ori        $s2, $s2, (0x55555555 & 0xFFFF)
    /* 5B354 8006AB54 1C00858C */  lw         $a1, 0x1C($a0)
    /* 5B358 8006AB58 2400868C */  lw         $a2, 0x24($a0)
    /* 5B35C 8006AB5C 04008D8C */  lw         $t5, 0x4($a0)
    /* 5B360 8006AB60 08008E8C */  lw         $t6, 0x8($a0)
    /* 5B364 8006AB64 0400AF8D */  lw         $t7, 0x4($t5)
  .L8006AB68:
    /* 5B368 8006AB68 FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 5B36C 8006AB6C 0C00E88C */  lw         $t0, 0xC($a3)
    /* 5B370 8006AB70 1000E98C */  lw         $t1, 0x10($a3)
    /* 5B374 8006AB74 1400EA8C */  lw         $t2, 0x14($a3)
    /* 5B378 8006AB78 1800EB8C */  lw         $t3, 0x18($a3)
    /* 5B37C 8006AB7C 026C0800 */  srl        $t5, $t0, 16
    /* 5B380 8006AB80 C0680D00 */  sll        $t5, $t5, 3
    /* 5B384 8006AB84 2168A501 */  addu       $t5, $t5, $a1
    /* 5B388 8006AB88 0400A28D */  lw         $v0, 0x4($t5)
    /* 5B38C 8006AB8C 0000AD8D */  lw         $t5, 0x0($t5)
    /* 5B390 8006AB90 31004310 */  beq        $v0, $v1, .L8006AC58
    /* 5B394 8006AB94 0C002DAF */   sw        $t5, 0xC($t9)
    /* 5B398 8006AB98 00808248 */  mtc2       $v0, $16 /* handwritten instruction */
    /* 5B39C 8006AB9C 28002DAF */  sw         $t5, 0x28($t9)
    /* 5B3A0 8006ABA0 026C0900 */  srl        $t5, $t1, 16
    /* 5B3A4 8006ABA4 C0680D00 */  sll        $t5, $t5, 3
    /* 5B3A8 8006ABA8 2168A501 */  addu       $t5, $t5, $a1
    /* 5B3AC 8006ABAC 0400A28D */  lw         $v0, 0x4($t5)
    /* 5B3B0 8006ABB0 0000AD8D */  lw         $t5, 0x0($t5)
    /* 5B3B4 8006ABB4 28004310 */  beq        $v0, $v1, .L8006AC58
    /* 5B3B8 8006ABB8 10002DAF */   sw        $t5, 0x10($t9)
    /* 5B3BC 8006ABBC 00888248 */  mtc2       $v0, $17 /* handwritten instruction */
    /* 5B3C0 8006ABC0 026C0A00 */  srl        $t5, $t2, 16
    /* 5B3C4 8006ABC4 C0680D00 */  sll        $t5, $t5, 3
    /* 5B3C8 8006ABC8 2168A501 */  addu       $t5, $t5, $a1
    /* 5B3CC 8006ABCC 0400A28D */  lw         $v0, 0x4($t5)
    /* 5B3D0 8006ABD0 0000AD8D */  lw         $t5, 0x0($t5)
    /* 5B3D4 8006ABD4 20004310 */  beq        $v0, $v1, .L8006AC58
    /* 5B3D8 8006ABD8 24002DAF */   sw        $t5, 0x24($t9)
    /* 5B3DC 8006ABDC 00908248 */  mtc2       $v0, $18 /* handwritten instruction */
    /* 5B3E0 8006ABE0 026C0B00 */  srl        $t5, $t3, 16
    /* 5B3E4 8006ABE4 C0680D00 */  sll        $t5, $t5, 3
    /* 5B3E8 8006ABE8 2168A501 */  addu       $t5, $t5, $a1
    /* 5B3EC 8006ABEC 0400A28D */  lw         $v0, 0x4($t5)
    /* 5B3F0 8006ABF0 0000AD8D */  lw         $t5, 0x0($t5)
    /* 5B3F4 8006ABF4 18004310 */  beq        $v0, $v1, .L8006AC58
    /* 5B3F8 8006ABF8 14002DAF */   sw        $t5, 0x14($t9)
    /* 5B3FC 8006ABFC 00988248 */  mtc2       $v0, $19 /* handwritten instruction */
    /* 5B400 8006AC00 20002DAF */  sw         $t5, 0x20($t9)
    /* 5B404 8006AC04 180032AF */  sw         $s2, 0x18($t9)
    /* 5B408 8006AC08 2C0032AF */  sw         $s2, 0x2C($t9)
    /* 5B40C 8006AC0C 2E00684B */  avsz4
    /* 5B410 8006AC10 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 5B414 8006AC14 080030AF */  sw         $s0, 0x8($t9)
    /* 5B418 8006AC18 1C0030AF */  sw         $s0, 0x1C($t9)
    /* 5B41C 8006AC1C 0610C201 */  srlv       $v0, $v0, $t6
    /* 5B420 8006AC20 80100200 */  sll        $v0, $v0, 2
    /* 5B424 8006AC24 21104F00 */  addu       $v0, $v0, $t7
    /* 5B428 8006AC28 00004D8C */  lw         $t5, 0x0($v0)
    /* 5B42C 8006AC2C 040031AF */  sw         $s1, 0x4($t9)
    /* 5B430 8006AC30 006A0D00 */  sll        $t5, $t5, 8
    /* 5B434 8006AC34 0B00AD35 */  ori        $t5, $t5, 0xB
    /* 5B438 8006AC38 020A0D00 */  srl        $at, $t5, 8
    /* 5B43C 8006AC3C 006E0D00 */  sll        $t5, $t5, 24
    /* 5B440 8006AC40 2568A101 */  or         $t5, $t5, $at
    /* 5B444 8006AC44 00002DAF */  sw         $t5, 0x0($t9)
    /* 5B448 8006AC48 006A1900 */  sll        $t5, $t9, 8
    /* 5B44C 8006AC4C 026A0D00 */  srl        $t5, $t5, 8
    /* 5B450 8006AC50 00004DAC */  sw         $t5, 0x0($v0)
    /* 5B454 8006AC54 30003927 */  addiu      $t9, $t9, 0x30
  .L8006AC58:
    /* 5B458 8006AC58 FFFF1827 */  addiu      $t8, $t8, -0x1
    /* 5B45C 8006AC5C C2FF0017 */  bnez       $t8, .L8006AB68
    /* 5B460 8006AC60 1C00E724 */   addiu     $a3, $a3, 0x1C
  .L8006AC64:
    /* 5B464 8006AC64 2800908C */  lw         $s0, 0x28($a0)
    /* 5B468 8006AC68 2C00918C */  lw         $s1, 0x2C($a0)
    /* 5B46C 8006AC6C 3000928C */  lw         $s2, 0x30($a0)
    /* 5B470 8006AC70 0000828C */  lw         $v0, 0x0($a0)
    /* 5B474 8006AC74 1080013C */  lui        $at, %hi(D_800FE240)
    /* 5B478 8006AC78 40E239AC */  sw         $t9, %lo(D_800FE240)($at)
    /* 5B47C 8006AC7C 08004224 */  addiu      $v0, $v0, 0x8
    /* 5B480 8006AC80 0800E003 */  jr         $ra
    /* 5B484 8006AC84 00000000 */   nop
endlabel func_8006AAFC
