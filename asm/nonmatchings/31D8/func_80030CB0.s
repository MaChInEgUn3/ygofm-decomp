nonmatching func_80030CB0, 0xAC

glabel func_80030CB0
    /* 214B0 80030CB0 E3038393 */  lbu        $v1, %gp_rel(D_8009B2EB)($gp)
    /* 214B4 80030CB4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 214B8 80030CB8 80006230 */  andi       $v0, $v1, 0x80
    /* 214BC 80030CBC 12004014 */  bnez       $v0, .L80030D08
    /* 214C0 80030CC0 2000BFAF */   sw        $ra, 0x20($sp)
    /* 214C4 80030CC4 80006234 */  ori        $v0, $v1, 0x80
    /* 214C8 80030CC8 E30382A3 */  sb         $v0, %gp_rel(D_8009B2EB)($gp)
    /* 214CC 80030CCC 12000224 */  addiu      $v0, $zero, 0x12
    /* 214D0 80030CD0 1000A2AF */  sw         $v0, 0x10($sp)
    /* 214D4 80030CD4 02000224 */  addiu      $v0, $zero, 0x2
    /* 214D8 80030CD8 1400A2AF */  sw         $v0, 0x14($sp)
    /* 214DC 80030CDC 01000224 */  addiu      $v0, $zero, 0x1
    /* 214E0 80030CE0 0980043C */  lui        $a0, %hi(D_80090D28)
    /* 214E4 80030CE4 280D8424 */  addiu      $a0, $a0, %lo(D_80090D28)
    /* 214E8 80030CE8 15000524 */  addiu      $a1, $zero, 0x15
    /* 214EC 80030CEC 21300000 */  addu       $a2, $zero, $zero
    /* 214F0 80030CF0 0A80033C */  lui        $v1, %hi(D_8009B26D)
    /* 214F4 80030CF4 6DB26390 */  lbu        $v1, %lo(D_8009B26D)($v1)
    /* 214F8 80030CF8 1800A2AF */  sw         $v0, 0x18($sp)
    /* 214FC 80030CFC C00383A7 */  sh         $v1, %gp_rel(D_8009B2C8)($gp)
    /* 21500 80030D00 94C0000C */  jal        func_80030250
    /* 21504 80030D04 2138C000 */   addu      $a3, $a2, $zero
  .L80030D08:
    /* 21508 80030D08 A5C0000C */  jal        func_80030294
    /* 2150C 80030D0C 00000000 */   nop
    /* 21510 80030D10 0E004010 */  beqz       $v0, .L80030D4C
    /* 21514 80030D14 00000000 */   nop
    /* 21518 80030D18 04004104 */  bgez       $v0, .L80030D2C
    /* 2151C 80030D1C 01000224 */   addiu     $v0, $zero, 0x1
    /* 21520 80030D20 E30380A3 */  sb         $zero, %gp_rel(D_8009B2EB)($gp)
    /* 21524 80030D24 53C30008 */  j          .L80030D4C
    /* 21528 80030D28 00000000 */   nop
  .L80030D2C:
    /* 2152C 80030D2C C0038393 */  lbu        $v1, %gp_rel(D_8009B2C8)($gp)
    /* 21530 80030D30 0A80013C */  lui        $at, %hi(D_8009B268)
    /* 21534 80030D34 68B222A0 */  sb         $v0, %lo(D_8009B268)($at)
    /* 21538 80030D38 08000224 */  addiu      $v0, $zero, 0x8
    /* 2153C 80030D3C 0A80013C */  lui        $at, %hi(D_8009B26C)
    /* 21540 80030D40 6CB222A0 */  sb         $v0, %lo(D_8009B26C)($at)
    /* 21544 80030D44 0A80013C */  lui        $at, %hi(D_8009B26D)
    /* 21548 80030D48 6DB223A0 */  sb         $v1, %lo(D_8009B26D)($at)
  .L80030D4C:
    /* 2154C 80030D4C 2000BF8F */  lw         $ra, 0x20($sp)
    /* 21550 80030D50 00000000 */  nop
    /* 21554 80030D54 0800E003 */  jr         $ra
    /* 21558 80030D58 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80030CB0
