nonmatching func_8007BA2C, 0x94

glabel func_8007BA2C
    /* 6C22C 8007BA2C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6C230 8007BA30 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C234 8007BA34 21808000 */  addu       $s0, $a0, $zero
    /* 6C238 8007BA38 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6C23C 8007BA3C C8F8010C */  jal        func_8007E320
    /* 6C240 8007BA40 21200000 */   addu      $a0, $zero, $zero
    /* 6C244 8007BA44 0F80033C */  lui        $v1, %hi(D_800F5E10)
    /* 6C248 8007BA48 105E638C */  lw         $v1, %lo(D_800F5E10)($v1)
    /* 6C24C 8007BA4C 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C250 8007BA50 06006210 */  beq        $v1, $v0, .L8007BA6C
    /* 6C254 8007BA54 04000324 */   addiu     $v1, $zero, 0x4
    /* 6C258 8007BA58 0F80023C */  lui        $v0, %hi(D_800F5E00)
    /* 6C25C 8007BA5C 005E428C */  lw         $v0, %lo(D_800F5E00)($v0)
    /* 6C260 8007BA60 00000000 */  nop
    /* 6C264 8007BA64 01004238 */  xori       $v0, $v0, 0x1
    /* 6C268 8007BA68 0100432C */  sltiu      $v1, $v0, 0x1
  .L8007BA6C:
    /* 6C26C 8007BA6C 04000224 */  addiu      $v0, $zero, 0x4
    /* 6C270 8007BA70 06006214 */  bne        $v1, $v0, .L8007BA8C
    /* 6C274 8007BA74 01000224 */   addiu     $v0, $zero, 0x1
    /* 6C278 8007BA78 21200002 */  addu       $a0, $s0, $zero
    /* 6C27C 8007BA7C 0F80103C */  lui        $s0, %hi(D_800F5E10)
    /* 6C280 8007BA80 105E1026 */  addiu      $s0, $s0, %lo(D_800F5E10)
    /* 6C284 8007BA84 A9EE0108 */  j          .L8007BAA4
    /* 6C288 8007BA88 05000526 */   addiu     $a1, $s0, 0x5
  .L8007BA8C:
    /* 6C28C 8007BA8C 08006214 */  bne        $v1, $v0, .L8007BAB0
    /* 6C290 8007BA90 21100000 */   addu      $v0, $zero, $zero
    /* 6C294 8007BA94 21200002 */  addu       $a0, $s0, $zero
    /* 6C298 8007BA98 0F80103C */  lui        $s0, %hi(D_800F5E00)
    /* 6C29C 8007BA9C 005E1026 */  addiu      $s0, $s0, %lo(D_800F5E00)
    /* 6C2A0 8007BAA0 05000526 */  addiu      $a1, $s0, 0x5
  .L8007BAA4:
    /* 6C2A4 8007BAA4 5BF3010C */  jal        func_8007CD6C
    /* 6C2A8 8007BAA8 000000AE */   sw        $zero, 0x0($s0)
    /* 6C2AC 8007BAAC 04000292 */  lbu        $v0, 0x4($s0)
  .L8007BAB0:
    /* 6C2B0 8007BAB0 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6C2B4 8007BAB4 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C2B8 8007BAB8 0800E003 */  jr         $ra
    /* 6C2BC 8007BABC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007BA2C
