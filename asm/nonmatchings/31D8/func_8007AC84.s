nonmatching func_8007AC84, 0x70

glabel func_8007AC84
    /* 6B484 8007AC84 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6B488 8007AC88 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6B48C 8007AC8C BBEF010C */  jal        func_8007BEEC
    /* 6B490 8007AC90 21200000 */   addu      $a0, $zero, $zero
    /* 6B494 8007AC94 01000324 */  addiu      $v1, $zero, 0x1
    /* 6B498 8007AC98 12004314 */  bne        $v0, $v1, .L8007ACE4
    /* 6B49C 8007AC9C 21100000 */   addu      $v0, $zero, $zero
    /* 6B4A0 8007ACA0 0F80033C */  lui        $v1, %hi(D_800F5EE4)
    /* 6B4A4 8007ACA4 E45E6324 */  addiu      $v1, $v1, %lo(D_800F5EE4)
    /* 6B4A8 8007ACA8 0000648C */  lw         $a0, 0x0($v1)
    /* 6B4AC 8007ACAC 3CFF6324 */  addiu      $v1, $v1, -0xC4
    /* 6B4B0 8007ACB0 40100400 */  sll        $v0, $a0, 1
    /* 6B4B4 8007ACB4 21104400 */  addu       $v0, $v0, $a0
    /* 6B4B8 8007ACB8 C0100200 */  sll        $v0, $v0, 3
    /* 6B4BC 8007ACBC 21184300 */  addu       $v1, $v0, $v1
    /* 6B4C0 8007ACC0 0000628C */  lw         $v0, 0x0($v1)
    /* 6B4C4 8007ACC4 00000000 */  nop
    /* 6B4C8 8007ACC8 06004010 */  beqz       $v0, .L8007ACE4
    /* 6B4CC 8007ACCC 21100000 */   addu      $v0, $zero, $zero
    /* 6B4D0 8007ACD0 04006490 */  lbu        $a0, 0x4($v1)
    /* 6B4D4 8007ACD4 0C00658C */  lw         $a1, 0xC($v1)
    /* 6B4D8 8007ACD8 90EF010C */  jal        func_8007BE40
    /* 6B4DC 8007ACDC 00000000 */   nop
    /* 6B4E0 8007ACE0 2B100200 */  sltu       $v0, $zero, $v0
  .L8007ACE4:
    /* 6B4E4 8007ACE4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6B4E8 8007ACE8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6B4EC 8007ACEC 0800E003 */  jr         $ra
    /* 6B4F0 8007ACF0 00000000 */   nop
endlabel func_8007AC84
