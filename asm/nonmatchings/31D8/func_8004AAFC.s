nonmatching func_8004AAFC, 0x1E8

glabel func_8004AAFC
    /* 3B2FC 8004AAFC B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 3B300 8004AB00 1000A427 */  addiu      $a0, $sp, 0x10
    /* 3B304 8004AB04 4400BFAF */  sw         $ra, 0x44($sp)
    /* 3B308 8004AB08 4000B6AF */  sw         $s6, 0x40($sp)
    /* 3B30C 8004AB0C 3C00B5AF */  sw         $s5, 0x3C($sp)
    /* 3B310 8004AB10 3800B4AF */  sw         $s4, 0x38($sp)
    /* 3B314 8004AB14 3400B3AF */  sw         $s3, 0x34($sp)
    /* 3B318 8004AB18 3000B2AF */  sw         $s2, 0x30($sp)
    /* 3B31C 8004AB1C 2C00B1AF */  sw         $s1, 0x2C($sp)
    /* 3B320 8004AB20 F1DC010C */  jal        func_800773C4
    /* 3B324 8004AB24 2800B0AF */   sw        $s0, 0x28($sp)
    /* 3B328 8004AB28 0A80043C */  lui        $a0, %hi(D_8009B458)
    /* 3B32C 8004AB2C 58B4848C */  lw         $a0, %lo(D_8009B458)($a0)
    /* 3B330 8004AB30 21A00000 */  addu       $s4, $zero, $zero
    /* 3B334 8004AB34 10058284 */  lh         $v0, 0x510($a0)
    /* 3B338 8004AB38 00000000 */  nop
    /* 3B33C 8004AB3C 5B004018 */  blez       $v0, .L8004ACAC
    /* 3B340 8004AB40 21908002 */   addu      $s2, $s4, $zero
    /* 3B344 8004AB44 02001624 */  addiu      $s6, $zero, 0x2
    /* 3B348 8004AB48 0180023C */  lui        $v0, %hi(D_80011434)
    /* 3B34C 8004AB4C 34145324 */  addiu      $s3, $v0, %lo(D_80011434)
    /* 3B350 8004AB50 1000B127 */  addiu      $s1, $sp, 0x10
    /* 3B354 8004AB54 80011524 */  addiu      $s5, $zero, 0x180
  .L8004AB58:
    /* 3B358 8004AB58 21809500 */  addu       $s0, $a0, $s5
    /* 3B35C 8004AB5C 03000292 */  lbu        $v0, 0x3($s0)
    /* 3B360 8004AB60 00000000 */  nop
    /* 3B364 8004AB64 1000422C */  sltiu      $v0, $v0, 0x10
    /* 3B368 8004AB68 03004010 */  beqz       $v0, .L8004AB78
    /* 3B36C 8004AB6C 21200002 */   addu      $a0, $s0, $zero
    /* 3B370 8004AB70 0F29010C */  jal        func_8004A43C
    /* 3B374 8004AB74 21280000 */   addu      $a1, $zero, $zero
  .L8004AB78:
    /* 3B378 8004AB78 00002292 */  lbu        $v0, 0x0($s1)
    /* 3B37C 8004AB7C 00000000 */  nop
    /* 3B380 8004AB80 17004014 */  bnez       $v0, .L8004ABE0
    /* 3B384 8004AB84 00000000 */   nop
    /* 3B388 8004AB88 0D000292 */  lbu        $v0, 0xD($s0)
    /* 3B38C 8004AB8C 00000000 */  nop
    /* 3B390 8004AB90 25004010 */  beqz       $v0, .L8004AC28
    /* 3B394 8004AB94 00000000 */   nop
    /* 3B398 8004AB98 03000392 */  lbu        $v1, 0x3($s0)
    /* 3B39C 8004AB9C 00000000 */  nop
    /* 3B3A0 8004ABA0 40100300 */  sll        $v0, $v1, 1
    /* 3B3A4 8004ABA4 21104300 */  addu       $v0, $v0, $v1
    /* 3B3A8 8004ABA8 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3B3AC 8004ABAC 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3B3B0 8004ABB0 C0100200 */  sll        $v0, $v0, 3
    /* 3B3B4 8004ABB4 21186200 */  addu       $v1, $v1, $v0
    /* 3B3B8 8004ABB8 06006490 */  lbu        $a0, 0x6($v1)
    /* 3B3BC 8004ABBC 00000000 */  nop
    /* 3B3C0 8004ABC0 0F008230 */  andi       $v0, $a0, 0xF
    /* 3B3C4 8004ABC4 02004010 */  beqz       $v0, .L8004ABD0
    /* 3B3C8 8004ABC8 FFFF8224 */   addiu     $v0, $a0, -0x1
    /* 3B3CC 8004ABCC 060062A0 */  sb         $v0, 0x6($v1)
  .L8004ABD0:
    /* 3B3D0 8004ABD0 63000224 */  addiu      $v0, $zero, 0x63
    /* 3B3D4 8004ABD4 0D0000A2 */  sb         $zero, 0xD($s0)
    /* 3B3D8 8004ABD8 1E0000A6 */  sh         $zero, 0x1E($s0)
    /* 3B3DC 8004ABDC 030002A2 */  sb         $v0, 0x3($s0)
  .L8004ABE0:
    /* 3B3E0 8004ABE0 0D000592 */  lbu        $a1, 0xD($s0)
    /* 3B3E4 8004ABE4 00000000 */  nop
    /* 3B3E8 8004ABE8 FF00A430 */  andi       $a0, $a1, 0xFF
    /* 3B3EC 8004ABEC 0E008010 */  beqz       $a0, .L8004AC28
    /* 3B3F0 8004ABF0 03000224 */   addiu     $v0, $zero, 0x3
    /* 3B3F4 8004ABF4 00002392 */  lbu        $v1, 0x0($s1)
    /* 3B3F8 8004ABF8 00000000 */  nop
    /* 3B3FC 8004ABFC 0A006214 */  bne        $v1, $v0, .L8004AC28
    /* 3B400 8004AC00 0200822C */   sltiu     $v0, $a0, 0x2
    /* 3B404 8004AC04 07004014 */  bnez       $v0, .L8004AC24
    /* 3B408 8004AC08 0100A224 */   addiu     $v0, $a1, 0x1
    /* 3B40C 8004AC0C 0000628E */  lw         $v0, 0x0($s3)
    /* 3B410 8004AC10 21208002 */  addu       $a0, $s4, $zero
    /* 3B414 8004AC14 F029010C */  jal        func_8004A7C0
    /* 3B418 8004AC18 25904202 */   or        $s2, $s2, $v0
    /* 3B41C 8004AC1C 0A2B0108 */  j          .L8004AC28
    /* 3B420 8004AC20 00000000 */   nop
  .L8004AC24:
    /* 3B424 8004AC24 0D0002A2 */  sb         $v0, 0xD($s0)
  .L8004AC28:
    /* 3B428 8004AC28 0F000292 */  lbu        $v0, 0xF($s0)
    /* 3B42C 8004AC2C 00000000 */  nop
    /* 3B430 8004AC30 14004014 */  bnez       $v0, .L8004AC84
    /* 3B434 8004AC34 00000000 */   nop
    /* 3B438 8004AC38 00002292 */  lbu        $v0, 0x0($s1)
    /* 3B43C 8004AC3C 00000000 */  nop
    /* 3B440 8004AC40 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 3B444 8004AC44 0200422C */  sltiu      $v0, $v0, 0x2
    /* 3B448 8004AC48 0E004010 */  beqz       $v0, .L8004AC84
    /* 3B44C 8004AC4C 21806002 */   addu      $s0, $s3, $zero
  .L8004AC50:
    /* 3B450 8004AC50 0000058E */  lw         $a1, 0x0($s0)
    /* 3B454 8004AC54 B4DB010C */  jal        func_80076ED0
    /* 3B458 8004AC58 21200000 */   addu      $a0, $zero, $zero
    /* 3B45C 8004AC5C 0000048E */  lw         $a0, 0x0($s0)
    /* 3B460 8004AC60 24DC010C */  jal        func_80077090
    /* 3B464 8004AC64 00000000 */   nop
    /* 3B468 8004AC68 03005610 */  beq        $v0, $s6, .L8004AC78
    /* 3B46C 8004AC6C 00000000 */   nop
    /* 3B470 8004AC70 F7FF4014 */  bnez       $v0, .L8004AC50
    /* 3B474 8004AC74 00000000 */   nop
  .L8004AC78:
    /* 3B478 8004AC78 0000028E */  lw         $v0, 0x0($s0)
    /* 3B47C 8004AC7C 00000000 */  nop
    /* 3B480 8004AC80 25904202 */  or         $s2, $s2, $v0
  .L8004AC84:
    /* 3B484 8004AC84 04007326 */  addiu      $s3, $s3, 0x4
    /* 3B488 8004AC88 01003126 */  addiu      $s1, $s1, 0x1
    /* 3B48C 8004AC8C 0A80043C */  lui        $a0, %hi(D_8009B458)
    /* 3B490 8004AC90 58B4848C */  lw         $a0, %lo(D_8009B458)($a0)
    /* 3B494 8004AC94 00000000 */  nop
    /* 3B498 8004AC98 10058284 */  lh         $v0, 0x510($a0)
    /* 3B49C 8004AC9C 01009426 */  addiu      $s4, $s4, 0x1
    /* 3B4A0 8004ACA0 2A108202 */  slt        $v0, $s4, $v0
    /* 3B4A4 8004ACA4 ACFF4014 */  bnez       $v0, .L8004AB58
    /* 3B4A8 8004ACA8 2800B526 */   addiu     $s5, $s5, 0x28
  .L8004ACAC:
    /* 3B4AC 8004ACAC 03004012 */  beqz       $s2, .L8004ACBC
    /* 3B4B0 8004ACB0 21200000 */   addu      $a0, $zero, $zero
    /* 3B4B4 8004ACB4 B4DB010C */  jal        func_80076ED0
    /* 3B4B8 8004ACB8 21284002 */   addu      $a1, $s2, $zero
  .L8004ACBC:
    /* 3B4BC 8004ACBC 4400BF8F */  lw         $ra, 0x44($sp)
    /* 3B4C0 8004ACC0 4000B68F */  lw         $s6, 0x40($sp)
    /* 3B4C4 8004ACC4 3C00B58F */  lw         $s5, 0x3C($sp)
    /* 3B4C8 8004ACC8 3800B48F */  lw         $s4, 0x38($sp)
    /* 3B4CC 8004ACCC 3400B38F */  lw         $s3, 0x34($sp)
    /* 3B4D0 8004ACD0 3000B28F */  lw         $s2, 0x30($sp)
    /* 3B4D4 8004ACD4 2C00B18F */  lw         $s1, 0x2C($sp)
    /* 3B4D8 8004ACD8 2800B08F */  lw         $s0, 0x28($sp)
    /* 3B4DC 8004ACDC 0800E003 */  jr         $ra
    /* 3B4E0 8004ACE0 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_8004AAFC
