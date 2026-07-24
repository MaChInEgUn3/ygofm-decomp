nonmatching func_8007AF18, 0x8C

glabel func_8007AF18
    /* 6B718 8007AF18 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6B71C 8007AF1C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6B720 8007AF20 0F80103C */  lui        $s0, %hi(D_800F5F70)
    /* 6B724 8007AF24 705F1026 */  addiu      $s0, $s0, %lo(D_800F5F70)
    /* 6B728 8007AF28 1400BFAF */  sw         $ra, 0x14($sp)
    /* 6B72C 8007AF2C 0000028E */  lw         $v0, 0x0($s0)
    /* 6B730 8007AF30 00000000 */  nop
    /* 6B734 8007AF34 00110200 */  sll        $v0, $v0, 4
    /* 6B738 8007AF38 0F80013C */  lui        $at, %hi(D_800F5EF0)
    /* 6B73C 8007AF3C 21082200 */  addu       $at, $at, $v0
    /* 6B740 8007AF40 F05E24AC */  sw         $a0, %lo(D_800F5EF0)($at)
    /* 6B744 8007AF44 0000028E */  lw         $v0, 0x0($s0)
    /* 6B748 8007AF48 00000000 */  nop
    /* 6B74C 8007AF4C 00110200 */  sll        $v0, $v0, 4
    /* 6B750 8007AF50 0F80013C */  lui        $at, %hi(D_800F5EF4)
    /* 6B754 8007AF54 21082200 */  addu       $at, $at, $v0
    /* 6B758 8007AF58 F45E25A0 */  sb         $a1, %lo(D_800F5EF4)($at)
    /* 6B75C 8007AF5C 85FF0226 */  addiu      $v0, $s0, -0x7B
    /* 6B760 8007AF60 0000048E */  lw         $a0, 0x0($s0)
    /* 6B764 8007AF64 2128C000 */  addu       $a1, $a2, $zero
    /* 6B768 8007AF68 00210400 */  sll        $a0, $a0, 4
    /* 6B76C 8007AF6C 5BF3010C */  jal        func_8007CD6C
    /* 6B770 8007AF70 21208200 */   addu      $a0, $a0, $v0
    /* 6B774 8007AF74 0000028E */  lw         $v0, 0x0($s0)
    /* 6B778 8007AF78 00000000 */  nop
    /* 6B77C 8007AF7C 01004224 */  addiu      $v0, $v0, 0x1
    /* 6B780 8007AF80 000002AE */  sw         $v0, 0x0($s0)
    /* 6B784 8007AF84 08004228 */  slti       $v0, $v0, 0x8
    /* 6B788 8007AF88 02004014 */  bnez       $v0, .L8007AF94
    /* 6B78C 8007AF8C 00000000 */   nop
    /* 6B790 8007AF90 000000AE */  sw         $zero, 0x0($s0)
  .L8007AF94:
    /* 6B794 8007AF94 1400BF8F */  lw         $ra, 0x14($sp)
    /* 6B798 8007AF98 1000B08F */  lw         $s0, 0x10($sp)
    /* 6B79C 8007AF9C 0800E003 */  jr         $ra
    /* 6B7A0 8007AFA0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8007AF18
