nonmatching func_8003CB7C, 0x6C

glabel func_8003CB7C
    /* 2D37C 8003CB7C 01000324 */  addiu      $v1, $zero, 0x1
    /* 2D380 8003CB80 9E048627 */  addiu      $a2, $gp, %gp_rel(D_8009B3A6)
    /* 2D384 8003CB84 92048527 */  addiu      $a1, $gp, %gp_rel(D_8009B39A)
    /* 2D388 8003CB88 8E048427 */  addiu      $a0, $gp, %gp_rel(D_8009B396)
  .L8003CB8C:
    /* 2D38C 8003CB8C 000080A4 */  sh         $zero, 0x0($a0)
    /* 2D390 8003CB90 00008294 */  lhu        $v0, 0x0($a0)
    /* 2D394 8003CB94 FEFF8424 */  addiu      $a0, $a0, -0x2
    /* 2D398 8003CB98 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 2D39C 8003CB9C 0000A2A4 */  sh         $v0, 0x0($a1)
    /* 2D3A0 8003CBA0 0000A294 */  lhu        $v0, 0x0($a1)
    /* 2D3A4 8003CBA4 FEFFA524 */  addiu      $a1, $a1, -0x2
    /* 2D3A8 8003CBA8 0000C2A4 */  sh         $v0, 0x0($a2)
    /* 2D3AC 8003CBAC F7FF6104 */  bgez       $v1, .L8003CB8C
    /* 2D3B0 8003CBB0 FEFFC624 */   addiu     $a2, $a2, -0x2
    /* 2D3B4 8003CBB4 1F000324 */  addiu      $v1, $zero, 0x1F
    /* 2D3B8 8003CBB8 0F80023C */  lui        $v0, %hi(D_800EF6B0)
    /* 2D3BC 8003CBBC B0F64424 */  addiu      $a0, $v0, %lo(D_800EF6B0)
  .L8003CBC0:
    /* 2D3C0 8003CBC0 21106400 */  addu       $v0, $v1, $a0
    /* 2D3C4 8003CBC4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 2D3C8 8003CBC8 FDFF6104 */  bgez       $v1, .L8003CBC0
    /* 2D3CC 8003CBCC 000040A0 */   sb        $zero, 0x0($v0)
    /* 2D3D0 8003CBD0 880480AF */  sw         $zero, %gp_rel(D_8009B390)($gp)
    /* 2D3D4 8003CBD4 A80480AF */  sw         $zero, %gp_rel(D_8009B3B0)($gp)
    /* 2D3D8 8003CBD8 AC0480AF */  sw         $zero, %gp_rel(D_8009B3B4)($gp)
    /* 2D3DC 8003CBDC A00480AF */  sw         $zero, %gp_rel(D_8009B3A8)($gp)
    /* 2D3E0 8003CBE0 0800E003 */  jr         $ra
    /* 2D3E4 8003CBE4 00000000 */   nop
endlabel func_8003CB7C
