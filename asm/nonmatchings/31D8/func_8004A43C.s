nonmatching func_8004A43C, 0xDC

glabel func_8004A43C
    /* 3AC3C 8004A43C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3AC40 8004A440 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3AC44 8004A444 21808000 */  addu       $s0, $a0, $zero
    /* 3AC48 8004A448 1400BFAF */  sw         $ra, 0x14($sp)
    /* 3AC4C 8004A44C 03000392 */  lbu        $v1, 0x3($s0)
    /* 3AC50 8004A450 00000000 */  nop
    /* 3AC54 8004A454 40100300 */  sll        $v0, $v1, 1
    /* 3AC58 8004A458 21104300 */  addu       $v0, $v0, $v1
    /* 3AC5C 8004A45C 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3AC60 8004A460 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3AC64 8004A464 C0100200 */  sll        $v0, $v0, 3
    /* 3AC68 8004A468 21206200 */  addu       $a0, $v1, $v0
    /* 3AC6C 8004A46C 07008390 */  lbu        $v1, 0x7($a0)
    /* 3AC70 8004A470 1A000286 */  lh         $v0, 0x1A($s0)
    /* 3AC74 8004A474 00000000 */  nop
    /* 3AC78 8004A478 03006214 */  bne        $v1, $v0, .L8004A488
    /* 3AC7C 8004A47C 00000000 */   nop
    /* 3AC80 8004A480 2100A010 */  beqz       $a1, .L8004A508
    /* 3AC84 8004A484 00000000 */   nop
  .L8004A488:
    /* 3AC88 8004A488 07008290 */  lbu        $v0, 0x7($a0)
    /* 3AC8C 8004A48C 00000000 */  nop
    /* 3AC90 8004A490 1A0002A6 */  sh         $v0, 0x1A($s0)
    /* 3AC94 8004A494 07008590 */  lbu        $a1, 0x7($a0)
    /* 3AC98 8004A498 EF28010C */  jal        func_8004A3BC
    /* 3AC9C 8004A49C 21200002 */   addu      $a0, $s0, $zero
    /* 3ACA0 8004A4A0 10000324 */  addiu      $v1, $zero, 0x10
    /* 3ACA4 8004A4A4 0180053C */  lui        $a1, %hi(D_80011434)
    /* 3ACA8 8004A4A8 06000492 */  lbu        $a0, 0x6($s0)
    /* 3ACAC 8004A4AC 0A80063C */  lui        $a2, %hi(D_8009B458)
    /* 3ACB0 8004A4B0 58B4C68C */  lw         $a2, %lo(D_8009B458)($a2)
    /* 3ACB4 8004A4B4 C0210400 */  sll        $a0, $a0, 7
    /* 3ACB8 8004A4B8 21104400 */  addu       $v0, $v0, $a0
    /* 3ACBC 8004A4BC 04206200 */  sllv       $a0, $v0, $v1
    /* 3ACC0 8004A4C0 C404C3AC */  sw         $v1, 0x4C4($a2)
    /* 3ACC4 8004A4C4 00000392 */  lbu        $v1, 0x0($s0)
    /* 3ACC8 8004A4C8 3414A524 */  addiu      $a1, $a1, %lo(D_80011434)
    /* 3ACCC 8004A4CC 80180300 */  sll        $v1, $v1, 2
    /* 3ACD0 8004A4D0 21186500 */  addu       $v1, $v1, $a1
    /* 3ACD4 8004A4D4 0000638C */  lw         $v1, 0x0($v1)
    /* 3ACD8 8004A4D8 C3250400 */  sra        $a0, $a0, 23
    /* 3ACDC 8004A4DC C004C3AC */  sw         $v1, 0x4C0($a2)
    /* 3ACE0 8004A4E0 12000692 */  lbu        $a2, 0x12($s0)
    /* 3ACE4 8004A4E4 13000792 */  lbu        $a3, 0x13($s0)
    /* 3ACE8 8004A4E8 ED27010C */  jal        func_80049FB4
    /* 3ACEC 8004A4EC 7F004530 */   andi      $a1, $v0, 0x7F
    /* 3ACF0 8004A4F0 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3ACF4 8004A4F4 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3ACF8 8004A4F8 00000000 */  nop
    /* 3ACFC 8004A4FC C0046424 */  addiu      $a0, $v1, 0x4C0
    /* 3AD00 8004A500 14DD010C */  jal        func_80077450
    /* 3AD04 8004A504 D40462A4 */   sh        $v0, 0x4D4($v1)
  .L8004A508:
    /* 3AD08 8004A508 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3AD0C 8004A50C 1000B08F */  lw         $s0, 0x10($sp)
    /* 3AD10 8004A510 0800E003 */  jr         $ra
    /* 3AD14 8004A514 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004A43C
