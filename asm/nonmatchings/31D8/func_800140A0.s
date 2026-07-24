nonmatching func_800140A0, 0x94

glabel func_800140A0
    /* 48A0 800140A0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 48A4 800140A4 FF008430 */  andi       $a0, $a0, 0xFF
    /* 48A8 800140A8 05000224 */  addiu      $v0, $zero, 0x5
    /* 48AC 800140AC 0E008214 */  bne        $a0, $v0, .L800140E8
    /* 48B0 800140B0 1800BFAF */   sw        $ra, 0x18($sp)
    /* 48B4 800140B4 A0000424 */  addiu      $a0, $zero, 0xA0
    /* 48B8 800140B8 FC018527 */  addiu      $a1, $gp, %gp_rel(D_8009B104)
    /* 48BC 800140BC FFFF0324 */  addiu      $v1, $zero, -0x1
    /* 48C0 800140C0 0180073C */  lui        $a3, %hi(func_800140A0)
    /* 48C4 800140C4 06000624 */  addiu      $a2, $zero, 0x6
    /* 48C8 800140C8 2802828F */  lw         $v0, %gp_rel(D_8009B130)($gp)
    /* 48CC 800140CC 1000A3AF */  sw         $v1, 0x10($sp)
    /* 48D0 800140D0 01004224 */  addiu      $v0, $v0, 0x1
    /* 48D4 800140D4 280282AF */  sw         $v0, %gp_rel(D_8009B130)($gp)
    /* 48D8 800140D8 1AED010C */  jal        func_8007B468
    /* 48DC 800140DC A040E724 */   addiu     $a3, $a3, %lo(func_800140A0)
    /* 48E0 800140E0 49500008 */  j          .L80014124
    /* 48E4 800140E4 00000000 */   nop
  .L800140E8:
    /* 48E8 800140E8 02000224 */  addiu      $v0, $zero, 0x2
    /* 48EC 800140EC 0D008214 */  bne        $a0, $v0, .L80014124
    /* 48F0 800140F0 00000000 */   nop
    /* 48F4 800140F4 8EF7010C */  jal        func_8007DE38
    /* 48F8 800140F8 01000424 */   addiu     $a0, $zero, 0x1
    /* 48FC 800140FC 0180043C */  lui        $a0, %hi(func_80013C28)
    /* 4900 80014100 283C8424 */  addiu      $a0, $a0, %lo(func_80013C28)
    /* 4904 80014104 54F7010C */  jal        func_8007DD50
    /* 4908 80014108 FFFF0524 */   addiu     $a1, $zero, -0x1
    /* 490C 8001410C EC01828F */  lw         $v0, %gp_rel(D_8009B0F4)($gp)
    /* 4910 80014110 FFFB0324 */  addiu      $v1, $zero, -0x401
    /* 4914 80014114 0C0280A3 */  sb         $zero, %gp_rel(D_8009B114)($gp)
    /* 4918 80014118 300280AF */  sw         $zero, %gp_rel(D_8009B138)($gp)
    /* 491C 8001411C 24104300 */  and        $v0, $v0, $v1
    /* 4920 80014120 EC0182AF */  sw         $v0, %gp_rel(D_8009B0F4)($gp)
  .L80014124:
    /* 4924 80014124 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4928 80014128 00000000 */  nop
    /* 492C 8001412C 0800E003 */  jr         $ra
    /* 4930 80014130 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_800140A0
