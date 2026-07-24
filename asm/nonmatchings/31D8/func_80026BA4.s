nonmatching func_80026BA4, 0x68

glabel func_80026BA4
    /* 173A4 80026BA4 D3FE8224 */  addiu      $v0, $a0, -0x12D
    /* 173A8 80026BA8 3200422C */  sltiu      $v0, $v0, 0x32
    /* 173AC 80026BAC 08004014 */  bnez       $v0, .L80026BD0
    /* 173B0 80026BB0 8B028228 */   slti      $v0, $a0, 0x28B
    /* 173B4 80026BB4 75FD8224 */  addiu      $v0, $a0, -0x28B
    /* 173B8 80026BB8 3200422C */  sltiu      $v0, $v0, 0x32
    /* 173BC 80026BBC 04004014 */  bnez       $v0, .L80026BD0
    /* 173C0 80026BC0 8B028228 */   slti      $v0, $a0, 0x28B
    /* 173C4 80026BC4 D1020224 */  addiu      $v0, $zero, 0x2D1
    /* 173C8 80026BC8 0E008214 */  bne        $a0, $v0, .L80026C04
    /* 173CC 80026BCC 8B028228 */   slti      $v0, $a0, 0x28B
  .L80026BD0:
    /* 173D0 80026BD0 05004014 */  bnez       $v0, .L80026BE8
    /* 173D4 80026BD4 D3FE8324 */   addiu     $v1, $a0, -0x12D
    /* 173D8 80026BD8 D1020224 */  addiu      $v0, $zero, 0x2D1
    /* 173DC 80026BDC 02008214 */  bne        $a0, $v0, .L80026BE8
    /* 173E0 80026BE0 A7FD8324 */   addiu     $v1, $a0, -0x259
    /* 173E4 80026BE4 64000324 */  addiu      $v1, $zero, 0x64
  .L80026BE8:
    /* 173E8 80026BE8 00800234 */  ori        $v0, $zero, 0x8000
    /* 173EC 80026BEC A00283A7 */  sh         $v1, %gp_rel(D_8009B1A8)($gp)
    /* 173F0 80026BF0 CA0284A7 */  sh         $a0, %gp_rel(D_8009B1D2)($gp)
    /* 173F4 80026BF4 180382A7 */  sh         $v0, %gp_rel(D_8009B220)($gp)
    /* 173F8 80026BF8 0200A010 */  beqz       $a1, .L80026C04
    /* 173FC 80026BFC 00C00234 */   ori       $v0, $zero, 0xC000
    /* 17400 80026C00 180382A7 */  sh         $v0, %gp_rel(D_8009B220)($gp)
  .L80026C04:
    /* 17404 80026C04 0800E003 */  jr         $ra
    /* 17408 80026C08 00000000 */   nop
endlabel func_80026BA4
