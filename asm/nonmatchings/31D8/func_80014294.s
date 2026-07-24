nonmatching func_80014294, 0x74

glabel func_80014294
    /* 4A94 80014294 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4A98 80014298 FF008430 */  andi       $a0, $a0, 0xFF
    /* 4A9C 8001429C 05000224 */  addiu      $v0, $zero, 0x5
    /* 4AA0 800142A0 0D008214 */  bne        $a0, $v0, .L800142D8
    /* 4AA4 800142A4 1000BFAF */   sw        $ra, 0x10($sp)
    /* 4AA8 800142A8 0180063C */  lui        $a2, %hi(func_80014294)
    /* 4AAC 800142AC 0D000424 */  addiu      $a0, $zero, 0xD
    /* 4AB0 800142B0 14028527 */  addiu      $a1, $gp, %gp_rel(D_8009B11C)
    /* 4AB4 800142B4 9442C624 */  addiu      $a2, $a2, %lo(func_80014294)
    /* 4AB8 800142B8 2802828F */  lw         $v0, %gp_rel(D_8009B130)($gp)
    /* 4ABC 800142BC 00000000 */  nop
    /* 4AC0 800142C0 01004224 */  addiu      $v0, $v0, 0x1
    /* 4AC4 800142C4 280282AF */  sw         $v0, %gp_rel(D_8009B130)($gp)
    /* 4AC8 800142C8 7DEC010C */  jal        func_8007B1F4
    /* 4ACC 800142CC FFFF0724 */   addiu     $a3, $zero, -0x1
    /* 4AD0 800142D0 BE500008 */  j          .L800142F8
    /* 4AD4 800142D4 00000000 */   nop
  .L800142D8:
    /* 4AD8 800142D8 02000224 */  addiu      $v0, $zero, 0x2
    /* 4ADC 800142DC 06008214 */  bne        $a0, $v0, .L800142F8
    /* 4AE0 800142E0 04000224 */   addiu     $v0, $zero, 0x4
    /* 4AE4 800142E4 F80182A7 */  sh         $v0, %gp_rel(D_8009B100)($gp)
    /* 4AE8 800142E8 EC01828F */  lw         $v0, %gp_rel(D_8009B0F4)($gp)
    /* 4AEC 800142EC FFFB0324 */  addiu      $v1, $zero, -0x401
    /* 4AF0 800142F0 24104300 */  and        $v0, $v0, $v1
    /* 4AF4 800142F4 EC0182AF */  sw         $v0, %gp_rel(D_8009B0F4)($gp)
  .L800142F8:
    /* 4AF8 800142F8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4AFC 800142FC 00000000 */  nop
    /* 4B00 80014300 0800E003 */  jr         $ra
    /* 4B04 80014304 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80014294
