/* Handwritten function */
nonmatching func_8006A3F0, 0x150

glabel func_8006A3F0
    /* 5ABF0 8006A3F0 0000878C */  lw         $a3, 0x0($a0)
    /* 5ABF4 8006A3F4 1000998C */  lw         $t9, 0x10($a0)
    /* 5ABF8 8006A3F8 0200F894 */  lhu        $t8, 0x2($a3)
    /* 5ABFC 8006A3FC 0400E68C */  lw         $a2, 0x4($a3)
    /* 5AC00 8006A400 1400858C */  lw         $a1, 0x14($a0)
    /* 5AC04 8006A404 80300600 */  sll        $a2, $a2, 2
    /* 5AC08 8006A408 200090AC */  sw         $s0, 0x20($a0)
    /* 5AC0C 8006A40C 240091AC */  sw         $s1, 0x24($a0)
    /* 5AC10 8006A410 280092AC */  sw         $s2, 0x28($a0)
    /* 5AC14 8006A414 0A800D3C */  lui        $t5, %hi(D_8009AFE4)
    /* 5AC18 8006A418 E4AFAD8D */  lw         $t5, %lo(D_8009AFE4)($t5)
    /* 5AC1C 8006A41C 3F000013 */  beqz       $t8, .L8006A51C
    /* 5AC20 8006A420 00000000 */   nop
    /* 5AC24 8006A424 01000124 */  addiu      $at, $zero, 0x1
    /* 5AC28 8006A428 3C00A111 */  beq        $t5, $at, .L8006A51C
    /* 5AC2C 8006A42C 2138A600 */   addu      $a3, $a1, $a2
    /* 5AC30 8006A430 0A80103C */  lui        $s0, %hi(D_8009AFD0)
    /* 5AC34 8006A434 D0AF108E */  lw         $s0, %lo(D_8009AFD0)($s0)
    /* 5AC38 8006A438 0A80113C */  lui        $s1, %hi(D_8009AFD4)
    /* 5AC3C 8006A43C D4AF318E */  lw         $s1, %lo(D_8009AFD4)($s1)
    /* 5AC40 8006A440 5555123C */  lui        $s2, (0x55555555 >> 16)
    /* 5AC44 8006A444 55555236 */  ori        $s2, $s2, (0x55555555 & 0xFFFF)
    /* 5AC48 8006A448 1800858C */  lw         $a1, 0x18($a0)
    /* 5AC4C 8006A44C 1C00868C */  lw         $a2, 0x1C($a0)
    /* 5AC50 8006A450 04008D8C */  lw         $t5, 0x4($a0)
    /* 5AC54 8006A454 08008E8C */  lw         $t6, 0x8($a0)
    /* 5AC58 8006A458 0400AF8D */  lw         $t7, 0x4($t5)
  .L8006A45C:
    /* 5AC5C 8006A45C 1000E88C */  lw         $t0, 0x10($a3)
    /* 5AC60 8006A460 1400E98C */  lw         $t1, 0x14($a3)
    /* 5AC64 8006A464 026C0800 */  srl        $t5, $t0, 16
    /* 5AC68 8006A468 C0680D00 */  sll        $t5, $t5, 3
    /* 5AC6C 8006A46C 2168A501 */  addu       $t5, $t5, $a1
    /* 5AC70 8006A470 0000A0C9 */  lwc2       $0, 0x0($t5)
    /* 5AC74 8006A474 0400A1C9 */  lwc2       $1, 0x4($t5)
    /* 5AC78 8006A478 006C0900 */  sll        $t5, $t1, 16
    /* 5AC7C 8006A47C 426B0D00 */  srl        $t5, $t5, 13
    /* 5AC80 8006A480 2168A501 */  addu       $t5, $t5, $a1
    /* 5AC84 8006A484 0000A2C9 */  lwc2       $2, 0x0($t5)
    /* 5AC88 8006A488 0400A3C9 */  lwc2       $3, 0x4($t5)
    /* 5AC8C 8006A48C 026C0900 */  srl        $t5, $t1, 16
    /* 5AC90 8006A490 C0680D00 */  sll        $t5, $t5, 3
    /* 5AC94 8006A494 2168A501 */  addu       $t5, $t5, $a1
    /* 5AC98 8006A498 0000A4C9 */  lwc2       $4, 0x0($t5)
    /* 5AC9C 8006A49C 0400A5C9 */  lwc2       $5, 0x4($t5)
    /* 5ACA0 8006A4A0 040031AF */  sw         $s1, 0x4($t9)
    /* 5ACA4 8006A4A4 1C0032AF */  sw         $s2, 0x1C($t9)
    /* 5ACA8 8006A4A8 3000284A */  rtpt
    /* 5ACAC 8006A4AC 00F84248 */  cfc2       $v0, $31 /* handwritten instruction */
    /* 5ACB0 8006A4B0 00000000 */  nop
    /* 5ACB4 8006A4B4 16004004 */  bltz       $v0, .L8006A510
    /* 5ACB8 8006A4B8 00000000 */   nop
    /* 5ACBC 8006A4BC 2D00584B */  avsz3
    /* 5ACC0 8006A4C0 00380248 */  mfc2       $v0, $7 /* handwritten instruction */
    /* 5ACC4 8006A4C4 080030AF */  sw         $s0, 0x8($t9)
    /* 5ACC8 8006A4C8 0610C201 */  srlv       $v0, $v0, $t6
    /* 5ACCC 8006A4CC 80100200 */  sll        $v0, $v0, 2
    /* 5ACD0 8006A4D0 21104F00 */  addu       $v0, $v0, $t7
    /* 5ACD4 8006A4D4 00004D8C */  lw         $t5, 0x0($v0)
    /* 5ACD8 8006A4D8 0C002CEB */  swc2       $12, 0xC($t9)
    /* 5ACDC 8006A4DC 10002DEB */  swc2       $13, 0x10($t9)
    /* 5ACE0 8006A4E0 14002EEB */  swc2       $14, 0x14($t9)
    /* 5ACE4 8006A4E4 18002CEB */  swc2       $12, 0x18($t9)
    /* 5ACE8 8006A4E8 006A0D00 */  sll        $t5, $t5, 8
    /* 5ACEC 8006A4EC 0700AD35 */  ori        $t5, $t5, 0x7
    /* 5ACF0 8006A4F0 020A0D00 */  srl        $at, $t5, 8
    /* 5ACF4 8006A4F4 006E0D00 */  sll        $t5, $t5, 24
    /* 5ACF8 8006A4F8 2568A101 */  or         $t5, $t5, $at
    /* 5ACFC 8006A4FC 00002DAF */  sw         $t5, 0x0($t9)
    /* 5AD00 8006A500 006A1900 */  sll        $t5, $t9, 8
    /* 5AD04 8006A504 026A0D00 */  srl        $t5, $t5, 8
    /* 5AD08 8006A508 00004DAC */  sw         $t5, 0x0($v0)
    /* 5AD0C 8006A50C 20003927 */  addiu      $t9, $t9, 0x20
  .L8006A510:
    /* 5AD10 8006A510 FFFF1827 */  addiu      $t8, $t8, -0x1
    /* 5AD14 8006A514 D1FF0017 */  bnez       $t8, .L8006A45C
    /* 5AD18 8006A518 1800E724 */   addiu     $a3, $a3, 0x18
  .L8006A51C:
    /* 5AD1C 8006A51C 2000908C */  lw         $s0, 0x20($a0)
    /* 5AD20 8006A520 2400918C */  lw         $s1, 0x24($a0)
    /* 5AD24 8006A524 2800928C */  lw         $s2, 0x28($a0)
    /* 5AD28 8006A528 0000828C */  lw         $v0, 0x0($a0)
    /* 5AD2C 8006A52C 1080013C */  lui        $at, %hi(D_800FE240)
    /* 5AD30 8006A530 40E239AC */  sw         $t9, %lo(D_800FE240)($at)
    /* 5AD34 8006A534 08004224 */  addiu      $v0, $v0, 0x8
    /* 5AD38 8006A538 0800E003 */  jr         $ra
    /* 5AD3C 8006A53C 00000000 */   nop
endlabel func_8006A3F0
