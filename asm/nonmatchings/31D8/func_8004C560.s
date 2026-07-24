nonmatching func_8004C560, 0x68

glabel func_8004C560
    /* 3CD60 8004C560 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3CD64 8004C564 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3CD68 8004C568 21808000 */  addu       $s0, $a0, $zero
    /* 3CD6C 8004C56C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 3CD70 8004C570 0000048E */  lw         $a0, 0x0($s0)
    /* 3CD74 8004C574 EF2E010C */  jal        func_8004BBBC
    /* 3CD78 8004C578 00000000 */   nop
    /* 3CD7C 8004C57C FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 3CD80 8004C580 0C004310 */  beq        $v0, $v1, .L8004C5B4
    /* 3CD84 8004C584 000002AE */   sw        $v0, 0x0($s0)
    /* 3CD88 8004C588 0B2F010C */  jal        func_8004BC2C
    /* 3CD8C 8004C58C 21200002 */   addu      $a0, $s0, $zero
    /* 3CD90 8004C590 080002AE */  sw         $v0, 0x8($s0)
    /* 3CD94 8004C594 21284000 */  addu       $a1, $v0, $zero
    /* 3CD98 8004C598 0000038E */  lw         $v1, 0x0($s0)
    /* 3CD9C 8004C59C 21100000 */  addu       $v0, $zero, $zero
    /* 3CDA0 8004C5A0 21206000 */  addu       $a0, $v1, $zero
    /* 3CDA4 8004C5A4 21208500 */  addu       $a0, $a0, $a1
    /* 3CDA8 8004C5A8 100003AE */  sw         $v1, 0x10($s0)
    /* 3CDAC 8004C5AC 6E310108 */  j          .L8004C5B8
    /* 3CDB0 8004C5B0 0C0004AE */   sw        $a0, 0xC($s0)
  .L8004C5B4:
    /* 3CDB4 8004C5B4 01000224 */  addiu      $v0, $zero, 0x1
  .L8004C5B8:
    /* 3CDB8 8004C5B8 1400BF8F */  lw         $ra, 0x14($sp)
    /* 3CDBC 8004C5BC 1000B08F */  lw         $s0, 0x10($sp)
    /* 3CDC0 8004C5C0 0800E003 */  jr         $ra
    /* 3CDC4 8004C5C4 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004C560
