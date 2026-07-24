/* Handwritten function */
nonmatching func_8006A268, 0x188

glabel func_8006A268
    /* 5AA68 8006A268 0000878C */  lw         $a3, 0x0($a0)
    /* 5AA6C 8006A26C 1000998C */  lw         $t9, 0x10($a0)
    /* 5AA70 8006A270 0200F894 */  lhu        $t8, 0x2($a3)
    /* 5AA74 8006A274 0400E68C */  lw         $a2, 0x4($a3)
    /* 5AA78 8006A278 1400858C */  lw         $a1, 0x14($a0)
    /* 5AA7C 8006A27C 80300600 */  sll        $a2, $a2, 2
    /* 5AA80 8006A280 200090AC */  sw         $s0, 0x20($a0)
    /* 5AA84 8006A284 240091AC */  sw         $s1, 0x24($a0)
    /* 5AA88 8006A288 280092AC */  sw         $s2, 0x28($a0)
    /* 5AA8C 8006A28C 0A800D3C */  lui        $t5, %hi(D_8009AFE4)
    /* 5AA90 8006A290 E4AFAD8D */  lw         $t5, %lo(D_8009AFE4)($t5)
    /* 5AA94 8006A294 4D000013 */  beqz       $t8, .L8006A3CC
    /* 5AA98 8006A298 00000000 */   nop
    /* 5AA9C 8006A29C 01000124 */  addiu      $at, $zero, 0x1
    /* 5AAA0 8006A2A0 4A00A111 */  beq        $t5, $at, .L8006A3CC
    /* 5AAA4 8006A2A4 2138A600 */   addu      $a3, $a1, $a2
    /* 5AAA8 8006A2A8 0A80103C */  lui        $s0, %hi(D_8009AFCC)
    /* 5AAAC 8006A2AC CCAF108E */  lw         $s0, %lo(D_8009AFCC)($s0)
    /* 5AAB0 8006A2B0 0A80113C */  lui        $s1, %hi(D_8009AFD4)
    /* 5AAB4 8006A2B4 D4AF318E */  lw         $s1, %lo(D_8009AFD4)($s1)
    /* 5AAB8 8006A2B8 5555123C */  lui        $s2, (0x55555555 >> 16)
    /* 5AABC 8006A2BC 55555236 */  ori        $s2, $s2, (0x55555555 & 0xFFFF)
    /* 5AAC0 8006A2C0 1800858C */  lw         $a1, 0x18($a0)
    /* 5AAC4 8006A2C4 1C00868C */  lw         $a2, 0x1C($a0)
    /* 5AAC8 8006A2C8 04008D8C */  lw         $t5, 0x4($a0)
    /* 5AACC 8006A2CC 08008E8C */  lw         $t6, 0x8($a0)
    /* 5AAD0 8006A2D0 0400AF8D */  lw         $t7, 0x4($t5)
  .L8006A2D4:
    /* 5AAD4 8006A2D4 0C00E88C */  lw         $t0, 0xC($a3)
    /* 5AAD8 8006A2D8 1000E98C */  lw         $t1, 0x10($a3)
    /* 5AADC 8006A2DC 1400EA8C */  lw         $t2, 0x14($a3)
    /* 5AAE0 8006A2E0 1800EB8C */  lw         $t3, 0x18($a3)
    /* 5AAE4 8006A2E4 026C0800 */  srl        $t5, $t0, 16
    /* 5AAE8 8006A2E8 C0680D00 */  sll        $t5, $t5, 3
    /* 5AAEC 8006A2EC 2168A501 */  addu       $t5, $t5, $a1
    /* 5AAF0 8006A2F0 0000A0C9 */  lwc2       $0, 0x0($t5)
    /* 5AAF4 8006A2F4 0400A1C9 */  lwc2       $1, 0x4($t5)
    /* 5AAF8 8006A2F8 026C0900 */  srl        $t5, $t1, 16
    /* 5AAFC 8006A2FC C0680D00 */  sll        $t5, $t5, 3
    /* 5AB00 8006A300 2168A501 */  addu       $t5, $t5, $a1
    /* 5AB04 8006A304 0000A2C9 */  lwc2       $2, 0x0($t5)
    /* 5AB08 8006A308 0400A3C9 */  lwc2       $3, 0x4($t5)
    /* 5AB0C 8006A30C 026C0A00 */  srl        $t5, $t2, 16
    /* 5AB10 8006A310 C0680D00 */  sll        $t5, $t5, 3
    /* 5AB14 8006A314 2168A501 */  addu       $t5, $t5, $a1
    /* 5AB18 8006A318 0000A4C9 */  lwc2       $4, 0x0($t5)
    /* 5AB1C 8006A31C 0400A5C9 */  lwc2       $5, 0x4($t5)
    /* 5AB20 8006A320 026C0B00 */  srl        $t5, $t3, 16
    /* 5AB24 8006A324 C0680D00 */  sll        $t5, $t5, 3
    /* 5AB28 8006A328 3000284A */  rtpt
    /* 5AB2C 8006A32C 00F84248 */  cfc2       $v0, $31 /* handwritten instruction */
    /* 5AB30 8006A330 2168A501 */  addu       $t5, $t5, $a1
    /* 5AB34 8006A334 22004004 */  bltz       $v0, .L8006A3C0
    /* 5AB38 8006A338 040031AF */   sw        $s1, 0x4($t9)
    /* 5AB3C 8006A33C 0000A0C9 */  lwc2       $0, 0x0($t5)
    /* 5AB40 8006A340 0400A1C9 */  lwc2       $1, 0x4($t5)
    /* 5AB44 8006A344 0C002CEB */  swc2       $12, 0xC($t9)
    /* 5AB48 8006A348 10002DEB */  swc2       $13, 0x10($t9)
    /* 5AB4C 8006A34C 24002EEB */  swc2       $14, 0x24($t9)
    /* 5AB50 8006A350 28002CEB */  swc2       $12, 0x28($t9)
    /* 5AB54 8006A354 180032AF */  sw         $s2, 0x18($t9)
    /* 5AB58 8006A358 2C0032AF */  sw         $s2, 0x2C($t9)
    /* 5AB5C 8006A35C 0100184A */  rtps
    /* 5AB60 8006A360 00F84248 */  cfc2       $v0, $31 /* handwritten instruction */
    /* 5AB64 8006A364 00000000 */  nop
    /* 5AB68 8006A368 15004004 */  bltz       $v0, .L8006A3C0
    /* 5AB6C 8006A36C 00000000 */   nop
    /* 5AB70 8006A370 2E00684B */  avsz4
    /* 5AB74 8006A374 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 5AB78 8006A378 080030AF */  sw         $s0, 0x8($t9)
    /* 5AB7C 8006A37C 1C0030AF */  sw         $s0, 0x1C($t9)
    /* 5AB80 8006A380 0610C201 */  srlv       $v0, $v0, $t6
    /* 5AB84 8006A384 80100200 */  sll        $v0, $v0, 2
    /* 5AB88 8006A388 21104F00 */  addu       $v0, $v0, $t7
    /* 5AB8C 8006A38C 00004D8C */  lw         $t5, 0x0($v0)
    /* 5AB90 8006A390 14002EEB */  swc2       $14, 0x14($t9)
    /* 5AB94 8006A394 20002EEB */  swc2       $14, 0x20($t9)
    /* 5AB98 8006A398 006A0D00 */  sll        $t5, $t5, 8
    /* 5AB9C 8006A39C 0B00AD35 */  ori        $t5, $t5, 0xB
    /* 5ABA0 8006A3A0 020A0D00 */  srl        $at, $t5, 8
    /* 5ABA4 8006A3A4 006E0D00 */  sll        $t5, $t5, 24
    /* 5ABA8 8006A3A8 2568A101 */  or         $t5, $t5, $at
    /* 5ABAC 8006A3AC 00002DAF */  sw         $t5, 0x0($t9)
    /* 5ABB0 8006A3B0 006A1900 */  sll        $t5, $t9, 8
    /* 5ABB4 8006A3B4 026A0D00 */  srl        $t5, $t5, 8
    /* 5ABB8 8006A3B8 00004DAC */  sw         $t5, 0x0($v0)
    /* 5ABBC 8006A3BC 30003927 */  addiu      $t9, $t9, 0x30
  .L8006A3C0:
    /* 5ABC0 8006A3C0 FFFF1827 */  addiu      $t8, $t8, -0x1
    /* 5ABC4 8006A3C4 C3FF0017 */  bnez       $t8, .L8006A2D4
    /* 5ABC8 8006A3C8 1C00E724 */   addiu     $a3, $a3, 0x1C
  .L8006A3CC:
    /* 5ABCC 8006A3CC 2000908C */  lw         $s0, 0x20($a0)
    /* 5ABD0 8006A3D0 2400918C */  lw         $s1, 0x24($a0)
    /* 5ABD4 8006A3D4 2800928C */  lw         $s2, 0x28($a0)
    /* 5ABD8 8006A3D8 0000828C */  lw         $v0, 0x0($a0)
    /* 5ABDC 8006A3DC 1080013C */  lui        $at, %hi(D_800FE240)
    /* 5ABE0 8006A3E0 40E239AC */  sw         $t9, %lo(D_800FE240)($at)
    /* 5ABE4 8006A3E4 08004224 */  addiu      $v0, $v0, 0x8
    /* 5ABE8 8006A3E8 0800E003 */  jr         $ra
    /* 5ABEC 8006A3EC 00000000 */   nop
endlabel func_8006A268
