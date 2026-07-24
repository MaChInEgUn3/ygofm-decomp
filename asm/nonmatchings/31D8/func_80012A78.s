nonmatching func_80012A78, 0x70

glabel func_80012A78
    /* 3278 80012A78 0980083C */  lui        $t0, %hi(D_800906E0)
    /* 327C 80012A7C E006088D */  lw         $t0, %lo(D_800906E0)($t0)
    /* 3280 80012A80 F0FFBD27 */  addiu      $sp, $sp, -0x10
    /* 3284 80012A84 0400B0AF */  sw         $s0, 0x4($sp)
    /* 3288 80012A88 0800B1AF */  sw         $s1, 0x8($sp)
    /* 328C 80012A8C 0C00BFAF */  sw         $ra, 0xC($sp)
    /* 3290 80012A90 0F000015 */  bnez       $t0, .L80012AD0
    /* 3294 80012A94 01000834 */   ori       $t0, $zero, 0x1
    /* 3298 80012A98 0980013C */  lui        $at, %hi(D_800906E0)
    /* 329C 80012A9C E00628AC */  sw         $t0, %lo(D_800906E0)($at)
    /* 32A0 80012AA0 0180103C */  lui        $s0, %hi(D_80010000)
    /* 32A4 80012AA4 00001026 */  addiu      $s0, $s0, %lo(D_80010000)
    /* 32A8 80012AA8 0000113C */  lui        $s1, (0x0 >> 16)
    /* 32AC 80012AAC 00003126 */  addiu      $s1, $s1, 0x0
    /* 32B0 80012AB0 07002012 */  beqz       $s1, .L80012AD0
    /* 32B4 80012AB4 00000000 */   nop
  .L80012AB8:
    /* 32B8 80012AB8 0000088E */  lw         $t0, 0x0($s0)
    /* 32BC 80012ABC 04001026 */  addiu      $s0, $s0, 0x4
    /* 32C0 80012AC0 09F80001 */  jalr       $t0
    /* 32C4 80012AC4 FFFF3126 */   addiu     $s1, $s1, -0x1
    /* 32C8 80012AC8 FBFF2016 */  bnez       $s1, .L80012AB8
    /* 32CC 80012ACC 00000000 */   nop
  .L80012AD0:
    /* 32D0 80012AD0 0C00BF8F */  lw         $ra, 0xC($sp)
    /* 32D4 80012AD4 0800B18F */  lw         $s1, 0x8($sp)
    /* 32D8 80012AD8 0400B08F */  lw         $s0, 0x4($sp)
    /* 32DC 80012ADC 1000BD27 */  addiu      $sp, $sp, 0x10
    /* 32E0 80012AE0 0800E003 */  jr         $ra
    /* 32E4 80012AE4 00000000 */   nop
endlabel func_80012A78
