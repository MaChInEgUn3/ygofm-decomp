nonmatching func_800141A8, 0x78

glabel func_800141A8
    /* 49A8 800141A8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 49AC 800141AC FF008430 */  andi       $a0, $a0, 0xFF
    /* 49B0 800141B0 05000224 */  addiu      $v0, $zero, 0x5
    /* 49B4 800141B4 0D008214 */  bne        $a0, $v0, .L800141EC
    /* 49B8 800141B8 1000BFAF */   sw        $ra, 0x10($sp)
    /* 49BC 800141BC 0180063C */  lui        $a2, %hi(func_800141A8)
    /* 49C0 800141C0 09000424 */  addiu      $a0, $zero, 0x9
    /* 49C4 800141C4 21280000 */  addu       $a1, $zero, $zero
    /* 49C8 800141C8 A841C624 */  addiu      $a2, $a2, %lo(func_800141A8)
    /* 49CC 800141CC 2802828F */  lw         $v0, %gp_rel(D_8009B130)($gp)
    /* 49D0 800141D0 00000000 */  nop
    /* 49D4 800141D4 01004224 */  addiu      $v0, $v0, 0x1
    /* 49D8 800141D8 280282AF */  sw         $v0, %gp_rel(D_8009B130)($gp)
    /* 49DC 800141DC 7DEC010C */  jal        func_8007B1F4
    /* 49E0 800141E0 FFFF0724 */   addiu     $a3, $zero, -0x1
    /* 49E4 800141E4 84500008 */  j          .L80014210
    /* 49E8 800141E8 00000000 */   nop
  .L800141EC:
    /* 49EC 800141EC 02000224 */  addiu      $v0, $zero, 0x2
    /* 49F0 800141F0 07008214 */  bne        $a0, $v0, .L80014210
    /* 49F4 800141F4 0F80033C */   lui       $v1, %hi(D_800E9EA7)
    /* 49F8 800141F8 01000224 */  addiu      $v0, $zero, 0x1
    /* 49FC 800141FC A79E62A0 */  sb         $v0, %lo(D_800E9EA7)($v1)
    /* 4A00 80014200 EC01828F */  lw         $v0, %gp_rel(D_8009B0F4)($gp)
    /* 4A04 80014204 FFFB0324 */  addiu      $v1, $zero, -0x401
    /* 4A08 80014208 24104300 */  and        $v0, $v0, $v1
    /* 4A0C 8001420C EC0182AF */  sw         $v0, %gp_rel(D_8009B0F4)($gp)
  .L80014210:
    /* 4A10 80014210 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4A14 80014214 00000000 */  nop
    /* 4A18 80014218 0800E003 */  jr         $ra
    /* 4A1C 8001421C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800141A8
