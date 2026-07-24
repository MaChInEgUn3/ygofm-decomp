nonmatching func_8007D9B4, 0xA4

glabel func_8007D9B4
    /* 6E1B4 8007D9B4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 6E1B8 8007D9B8 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 6E1BC 8007D9BC 21988000 */  addu       $s3, $a0, $zero
    /* 6E1C0 8007D9C0 2000B4AF */  sw         $s4, 0x20($sp)
    /* 6E1C4 8007D9C4 21A0A000 */  addu       $s4, $a1, $zero
    /* 6E1C8 8007D9C8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6E1CC 8007D9CC 21800000 */  addu       $s0, $zero, $zero
    /* 6E1D0 8007D9D0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 6E1D4 8007D9D4 0F80123C */  lui        $s2, %hi(D_800F659C)
    /* 6E1D8 8007D9D8 9C655226 */  addiu      $s2, $s2, %lo(D_800F659C)
    /* 6E1DC 8007D9DC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6E1E0 8007D9E0 21880000 */  addu       $s1, $zero, $zero
    /* 6E1E4 8007D9E4 2400BFAF */  sw         $ra, 0x24($sp)
  .L8007D9E8:
    /* 6E1E8 8007D9E8 0F80023C */  lui        $v0, %hi(D_800F6594)
    /* 6E1EC 8007D9EC 21105100 */  addu       $v0, $v0, $s1
    /* 6E1F0 8007D9F0 9465428C */  lw         $v0, %lo(D_800F6594)($v0)
    /* 6E1F4 8007D9F4 00000000 */  nop
    /* 6E1F8 8007D9F8 0E004010 */  beqz       $v0, .L8007DA34
    /* 6E1FC 8007D9FC 00000000 */   nop
    /* 6E200 8007DA00 07005314 */  bne        $v0, $s3, .L8007DA20
    /* 6E204 8007DA04 21208002 */   addu      $a0, $s4, $zero
    /* 6E208 8007DA08 A039020C */  jal        func_8008E680
    /* 6E20C 8007DA0C 21284002 */   addu      $a1, $s2, $zero
    /* 6E210 8007DA10 04004014 */  bnez       $v0, .L8007DA24
    /* 6E214 8007DA14 2C005226 */   addiu     $s2, $s2, 0x2C
    /* 6E218 8007DA18 8EF60108 */  j          .L8007DA38
    /* 6E21C 8007DA1C 01000226 */   addiu     $v0, $s0, 0x1
  .L8007DA20:
    /* 6E220 8007DA20 2C005226 */  addiu      $s2, $s2, 0x2C
  .L8007DA24:
    /* 6E224 8007DA24 01001026 */  addiu      $s0, $s0, 0x1
    /* 6E228 8007DA28 8000022A */  slti       $v0, $s0, 0x80
    /* 6E22C 8007DA2C EEFF4014 */  bnez       $v0, .L8007D9E8
    /* 6E230 8007DA30 2C003126 */   addiu     $s1, $s1, 0x2C
  .L8007DA34:
    /* 6E234 8007DA34 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8007DA38:
    /* 6E238 8007DA38 2400BF8F */  lw         $ra, 0x24($sp)
    /* 6E23C 8007DA3C 2000B48F */  lw         $s4, 0x20($sp)
    /* 6E240 8007DA40 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 6E244 8007DA44 1800B28F */  lw         $s2, 0x18($sp)
    /* 6E248 8007DA48 1400B18F */  lw         $s1, 0x14($sp)
    /* 6E24C 8007DA4C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6E250 8007DA50 0800E003 */  jr         $ra
    /* 6E254 8007DA54 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8007D9B4
