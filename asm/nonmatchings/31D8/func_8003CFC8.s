nonmatching func_8003CFC8, 0x74

glabel func_8003CFC8
    /* 2D7C8 8003CFC8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2D7CC 8003CFCC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2D7D0 8003CFD0 21808000 */  addu       $s0, $a0, $zero
    /* 2D7D4 8003CFD4 00040426 */  addiu      $a0, $s0, 0x400
    /* 2D7D8 8003CFD8 04020524 */  addiu      $a1, $zero, 0x204
    /* 2D7DC 8003CFDC 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 2D7E0 8003CFE0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2D7E4 8003CFE4 AEF3000C */  jal        func_8003CEB8
    /* 2D7E8 8003CFE8 1400B1AF */   sw        $s1, 0x14($sp)
    /* 2D7EC 8003CFEC 24061226 */  addiu      $s2, $s0, 0x624
    /* 2D7F0 8003CFF0 08001124 */  addiu      $s1, $zero, 0x8
    /* 2D7F4 8003CFF4 060602A6 */  sh         $v0, 0x606($s0)
    /* 2D7F8 8003CFF8 040602A6 */  sh         $v0, 0x604($s0)
    /* 2D7FC 8003CFFC FFFF4230 */  andi       $v0, $v0, 0xFFFF
    /* 2D800 8003D000 001C0200 */  sll        $v1, $v0, 16
    /* 2D804 8003D004 25104300 */  or         $v0, $v0, $v1
    /* 2D808 8003D008 600082AF */  sw         $v0, %gp_rel(D_8009AF68)($gp)
    /* 2D80C 8003D00C 5C0082AF */  sw         $v0, %gp_rel(D_8009AF64)($gp)
  .L8003D010:
    /* 2D810 8003D010 9DF3000C */  jal        func_8003CE74
    /* 2D814 8003D014 FFFF3126 */   addiu     $s1, $s1, -0x1
    /* 2D818 8003D018 000042AE */  sw         $v0, 0x0($s2)
    /* 2D81C 8003D01C FCFF2016 */  bnez       $s1, .L8003D010
    /* 2D820 8003D020 FCFF5226 */   addiu     $s2, $s2, -0x4
    /* 2D824 8003D024 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2D828 8003D028 1800B28F */  lw         $s2, 0x18($sp)
    /* 2D82C 8003D02C 1400B18F */  lw         $s1, 0x14($sp)
    /* 2D830 8003D030 1000B08F */  lw         $s0, 0x10($sp)
    /* 2D834 8003D034 0800E003 */  jr         $ra
    /* 2D838 8003D038 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003CFC8
