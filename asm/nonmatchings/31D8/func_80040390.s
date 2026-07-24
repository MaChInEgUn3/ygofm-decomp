nonmatching func_80040390, 0x60

glabel func_80040390
    /* 30B90 80040390 21180000 */  addu       $v1, $zero, $zero
    /* 30B94 80040394 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 30B98 80040398 0F80023C */  lui        $v0, %hi(D_800F2878)
    /* 30B9C 8004039C 78284524 */  addiu      $a1, $v0, %lo(D_800F2878)
    /* 30BA0 800403A0 0F80023C */  lui        $v0, %hi(D_800EFE38)
    /* 30BA4 800403A4 38FE4424 */  addiu      $a0, $v0, %lo(D_800EFE38)
    /* 30BA8 800403A8 080580A7 */  sh         $zero, %gp_rel(D_8009B410)($gp)
    /* 30BAC 800403AC 0A0580A7 */  sh         $zero, %gp_rel(D_8009B412)($gp)
  .L800403B0:
    /* 30BB0 800403B0 000086A4 */  sh         $a2, 0x0($a0)
    /* 30BB4 800403B4 0000A6A4 */  sh         $a2, 0x0($a1)
    /* 30BB8 800403B8 0200A524 */  addiu      $a1, $a1, 0x2
    /* 30BBC 800403BC 01006324 */  addiu      $v1, $v1, 0x1
    /* 30BC0 800403C0 07006228 */  slti       $v0, $v1, 0x7
    /* 30BC4 800403C4 FAFF4014 */  bnez       $v0, .L800403B0
    /* 30BC8 800403C8 02008424 */   addiu     $a0, $a0, 0x2
    /* 30BCC 800403CC 0F80023C */  lui        $v0, %hi(D_800EFE48)
    /* 30BD0 800403D0 48FE4224 */  addiu      $v0, $v0, %lo(D_800EFE48)
    /* 30BD4 800403D4 5F000324 */  addiu      $v1, $zero, 0x5F
  .L800403D8:
    /* 30BD8 800403D8 080040A4 */  sh         $zero, 0x8($v0)
    /* 30BDC 800403DC FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 30BE0 800403E0 FDFF6104 */  bgez       $v1, .L800403D8
    /* 30BE4 800403E4 70004224 */   addiu     $v0, $v0, 0x70
    /* 30BE8 800403E8 0800E003 */  jr         $ra
    /* 30BEC 800403EC 00000000 */   nop
endlabel func_80040390
