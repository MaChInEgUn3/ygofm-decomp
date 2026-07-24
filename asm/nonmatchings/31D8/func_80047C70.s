nonmatching func_80047C70, 0x54

glabel func_80047C70
    /* 38470 80047C70 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 38474 80047C74 1400B1AF */  sw         $s1, 0x14($sp)
    /* 38478 80047C78 21888000 */  addu       $s1, $a0, $zero
    /* 3847C 80047C7C 1000B0AF */  sw         $s0, 0x10($sp)
    /* 38480 80047C80 21800000 */  addu       $s0, $zero, $zero
    /* 38484 80047C84 1800BFAF */  sw         $ra, 0x18($sp)
  .L80047C88:
    /* 38488 80047C88 21200000 */  addu       $a0, $zero, $zero
    /* 3848C 80047C8C B4DB010C */  jal        func_80076ED0
    /* 38490 80047C90 21282002 */   addu      $a1, $s1, $zero
    /* 38494 80047C94 24DC010C */  jal        func_80077090
    /* 38498 80047C98 21202002 */   addu      $a0, $s1, $zero
    /* 3849C 80047C9C 04004010 */  beqz       $v0, .L80047CB0
    /* 384A0 80047CA0 01001026 */   addiu     $s0, $s0, 0x1
    /* 384A4 80047CA4 0001022A */  slti       $v0, $s0, 0x100
    /* 384A8 80047CA8 F7FF4014 */  bnez       $v0, .L80047C88
    /* 384AC 80047CAC 00000000 */   nop
  .L80047CB0:
    /* 384B0 80047CB0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 384B4 80047CB4 1400B18F */  lw         $s1, 0x14($sp)
    /* 384B8 80047CB8 1000B08F */  lw         $s0, 0x10($sp)
    /* 384BC 80047CBC 0800E003 */  jr         $ra
    /* 384C0 80047CC0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80047C70
