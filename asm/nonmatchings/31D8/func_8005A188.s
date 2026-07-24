nonmatching func_8005A188, 0x6C

glabel func_8005A188
    /* 4A988 8005A188 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4A98C 8005A18C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 4A990 8005A190 21888000 */  addu       $s1, $a0, $zero
    /* 4A994 8005A194 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4A998 8005A198 5D7C010C */  jal        func_8005F174
    /* 4A99C 8005A19C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 4A9A0 8005A1A0 01001024 */  addiu      $s0, $zero, 0x1
    /* 4A9A4 8005A1A4 05005014 */  bne        $v0, $s0, .L8005A1BC
    /* 4A9A8 8005A1A8 00000000 */   nop
    /* 4A9AC 8005A1AC 637C010C */  jal        func_8005F18C
    /* 4A9B0 8005A1B0 00000000 */   nop
    /* 4A9B4 8005A1B4 0A005010 */  beq        $v0, $s0, .L8005A1E0
    /* 4A9B8 8005A1B8 00000000 */   nop
  .L8005A1BC:
    /* 4A9BC 8005A1BC 04002006 */  bltz       $s1, .L8005A1D0
    /* 4A9C0 8005A1C0 FF000224 */   addiu     $v0, $zero, 0xFF
    /* 4A9C4 8005A1C4 910090A3 */  sb         $s0, %gp_rel(D_8009AF99)($gp)
    /* 4A9C8 8005A1C8 77680108 */  j          .L8005A1DC
    /* 4A9CC 8005A1CC 00000000 */   nop
  .L8005A1D0:
    /* 4A9D0 8005A1D0 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 4A9D4 8005A1D4 910082A3 */  sb         $v0, %gp_rel(D_8009AF99)($gp)
    /* 4A9D8 8005A1D8 FF000224 */  addiu      $v0, $zero, 0xFF
  .L8005A1DC:
    /* 4A9DC 8005A1DC 900082A3 */  sb         $v0, %gp_rel(D_8009AF98)($gp)
  .L8005A1E0:
    /* 4A9E0 8005A1E0 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4A9E4 8005A1E4 1400B18F */  lw         $s1, 0x14($sp)
    /* 4A9E8 8005A1E8 1000B08F */  lw         $s0, 0x10($sp)
    /* 4A9EC 8005A1EC 0800E003 */  jr         $ra
    /* 4A9F0 8005A1F0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8005A188
