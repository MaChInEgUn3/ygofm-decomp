nonmatching func_8007BAD0, 0xA4

glabel func_8007BAD0
    /* 6C2D0 8007BAD0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6C2D4 8007BAD4 21200000 */  addu       $a0, $zero, $zero
    /* 6C2D8 8007BAD8 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6C2DC 8007BADC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6C2E0 8007BAE0 BBEF010C */  jal        func_8007BEEC
    /* 6C2E4 8007BAE4 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6C2E8 8007BAE8 21804000 */  addu       $s0, $v0, $zero
    /* 6C2EC 8007BAEC 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C2F0 8007BAF0 1B000216 */  bne        $s0, $v0, .L8007BB60
    /* 6C2F4 8007BAF4 00000000 */   nop
    /* 6C2F8 8007BAF8 0F80113C */  lui        $s1, %hi(D_800F5EE8)
    /* 6C2FC 8007BAFC E85E3126 */  addiu      $s1, $s1, %lo(D_800F5EE8)
    /* 6C300 8007BB00 0000228E */  lw         $v0, 0x0($s1)
    /* 6C304 8007BB04 00000000 */  nop
    /* 6C308 8007BB08 15004018 */  blez       $v0, .L8007BB60
    /* 6C30C 8007BB0C 00000000 */   nop
    /* 6C310 8007BB10 BBEF010C */  jal        func_8007BEEC
    /* 6C314 8007BB14 21200000 */   addu      $a0, $zero, $zero
    /* 6C318 8007BB18 11005014 */  bne        $v0, $s0, .L8007BB60
    /* 6C31C 8007BB1C 00000000 */   nop
    /* 6C320 8007BB20 0F80033C */  lui        $v1, %hi(D_800F5EE4)
    /* 6C324 8007BB24 E45E638C */  lw         $v1, %lo(D_800F5EE4)($v1)
    /* 6C328 8007BB28 00000000 */  nop
    /* 6C32C 8007BB2C 40100300 */  sll        $v0, $v1, 1
    /* 6C330 8007BB30 21104300 */  addu       $v0, $v0, $v1
    /* 6C334 8007BB34 C0100200 */  sll        $v0, $v0, 3
    /* 6C338 8007BB38 38FF2326 */  addiu      $v1, $s1, -0xC8
    /* 6C33C 8007BB3C 21184300 */  addu       $v1, $v0, $v1
    /* 6C340 8007BB40 0000628C */  lw         $v0, 0x0($v1)
    /* 6C344 8007BB44 00000000 */  nop
    /* 6C348 8007BB48 05004010 */  beqz       $v0, .L8007BB60
    /* 6C34C 8007BB4C 00000000 */   nop
    /* 6C350 8007BB50 04006490 */  lbu        $a0, 0x4($v1)
    /* 6C354 8007BB54 0C00658C */  lw         $a1, 0xC($v1)
    /* 6C358 8007BB58 90EF010C */  jal        func_8007BE40
    /* 6C35C 8007BB5C 00000000 */   nop
  .L8007BB60:
    /* 6C360 8007BB60 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6C364 8007BB64 1400B18F */  lw         $s1, 0x14($sp)
    /* 6C368 8007BB68 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C36C 8007BB6C 0800E003 */  jr         $ra
    /* 6C370 8007BB70 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007BAD0
