nonmatching func_8007AA0C, 0x88

glabel func_8007AA0C
    /* 6B20C 8007AA0C E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6B210 8007AA10 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6B214 8007AA14 0F80113C */  lui        $s1, %hi(D_800F5EE8)
    /* 6B218 8007AA18 E85E3126 */  addiu      $s1, $s1, %lo(D_800F5EE8)
    /* 6B21C 8007AA1C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6B220 8007AA20 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6B224 8007AA24 0000228E */  lw         $v0, 0x0($s1)
    /* 6B228 8007AA28 00000000 */  nop
    /* 6B22C 8007AA2C 08004228 */  slti       $v0, $v0, 0x8
    /* 6B230 8007AA30 13004010 */  beqz       $v0, .L8007AA80
    /* 6B234 8007AA34 21100000 */   addu      $v0, $zero, $zero
    /* 6B238 8007AA38 43D1010C */  jal        func_8007450C
    /* 6B23C 8007AA3C 21200000 */   addu      $a0, $zero, $zero
    /* 6B240 8007AA40 F8FF238E */  lw         $v1, -0x8($s1)
    /* 6B244 8007AA44 0000248E */  lw         $a0, 0x0($s1)
    /* 6B248 8007AA48 00000000 */  nop
    /* 6B24C 8007AA4C 21806400 */  addu       $s0, $v1, $a0
    /* 6B250 8007AA50 21204000 */  addu       $a0, $v0, $zero
    /* 6B254 8007AA54 0800022A */  slti       $v0, $s0, 0x8
    /* 6B258 8007AA58 02004014 */  bnez       $v0, .L8007AA64
    /* 6B25C 8007AA5C 00000000 */   nop
    /* 6B260 8007AA60 F8FF1026 */  addiu      $s0, $s0, -0x8
  .L8007AA64:
    /* 6B264 8007AA64 43D1010C */  jal        func_8007450C
    /* 6B268 8007AA68 00000000 */   nop
    /* 6B26C 8007AA6C 40101000 */  sll        $v0, $s0, 1
    /* 6B270 8007AA70 21105000 */  addu       $v0, $v0, $s0
    /* 6B274 8007AA74 C0100200 */  sll        $v0, $v0, 3
    /* 6B278 8007AA78 38FF2326 */  addiu      $v1, $s1, -0xC8
    /* 6B27C 8007AA7C 21104300 */  addu       $v0, $v0, $v1
  .L8007AA80:
    /* 6B280 8007AA80 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6B284 8007AA84 1400B18F */  lw         $s1, 0x14($sp)
    /* 6B288 8007AA88 1000B08F */  lw         $s0, 0x10($sp)
    /* 6B28C 8007AA8C 0800E003 */  jr         $ra
    /* 6B290 8007AA90 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007AA0C
