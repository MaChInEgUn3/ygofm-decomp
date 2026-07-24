nonmatching func_8007D190, 0x70

glabel func_8007D190
    /* 6D990 8007D190 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6D994 8007D194 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6D998 8007D198 21888000 */  addu       $s1, $a0, $zero
    /* 6D99C 8007D19C FFFF0424 */  addiu      $a0, $zero, -0x1
    /* 6D9A0 8007D1A0 1800BFAF */  sw         $ra, 0x18($sp)
    /* 6D9A4 8007D1A4 5CD0010C */  jal        func_80074170
    /* 6D9A8 8007D1A8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 6D9AC 8007D1AC 0980043C */  lui        $a0, %hi(D_800939F0)
    /* 6D9B0 8007D1B0 F0398424 */  addiu      $a0, $a0, %lo(D_800939F0)
    /* 6D9B4 8007D1B4 0000838C */  lw         $v1, 0x0($a0)
    /* 6D9B8 8007D1B8 00000000 */  nop
    /* 6D9BC 8007D1BC B0046324 */  addiu      $v1, $v1, 0x4B0
    /* 6D9C0 8007D1C0 2A186200 */  slt        $v1, $v1, $v0
    /* 6D9C4 8007D1C4 05006010 */  beqz       $v1, .L8007D1DC
    /* 6D9C8 8007D1C8 FFFF1024 */   addiu     $s0, $zero, -0x1
    /* 6D9CC 8007D1CC 8DF4010C */  jal        func_8007D234
    /* 6D9D0 8007D1D0 01000424 */   addiu     $a0, $zero, 0x1
    /* 6D9D4 8007D1D4 78F40108 */  j          .L8007D1E0
    /* 6D9D8 8007D1D8 00000000 */   nop
  .L8007D1DC:
    /* 6D9DC 8007D1DC F0FF908C */  lw         $s0, -0x10($a0)
  .L8007D1E0:
    /* 6D9E0 8007D1E0 8BEE010C */  jal        func_8007BA2C
    /* 6D9E4 8007D1E4 21202002 */   addu      $a0, $s1, $zero
    /* 6D9E8 8007D1E8 21100002 */  addu       $v0, $s0, $zero
    /* 6D9EC 8007D1EC 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6D9F0 8007D1F0 1400B18F */  lw         $s1, 0x14($sp)
    /* 6D9F4 8007D1F4 1000B08F */  lw         $s0, 0x10($sp)
    /* 6D9F8 8007D1F8 0800E003 */  jr         $ra
    /* 6D9FC 8007D1FC 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007D190
