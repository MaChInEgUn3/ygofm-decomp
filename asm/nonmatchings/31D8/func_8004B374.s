nonmatching func_8004B374, 0x128

glabel func_8004B374
    /* 3BB74 8004B374 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3BB78 8004B378 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3BB7C 8004B37C D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 3BB80 8004B380 2800B6AF */  sw         $s6, 0x28($sp)
    /* 3BB84 8004B384 21B08000 */  addu       $s6, $a0, $zero
    /* 3BB88 8004B388 2400B5AF */  sw         $s5, 0x24($sp)
    /* 3BB8C 8004B38C 21A8A000 */  addu       $s5, $a1, $zero
    /* 3BB90 8004B390 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3BB94 8004B394 21800000 */  addu       $s0, $zero, $zero
    /* 3BB98 8004B398 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 3BB9C 8004B39C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 3BBA0 8004B3A0 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3BBA4 8004B3A4 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3BBA8 8004B3A8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3BBAC 8004B3AC 10056284 */  lh         $v0, 0x510($v1)
    /* 3BBB0 8004B3B0 00000000 */  nop
    /* 3BBB4 8004B3B4 1C004018 */  blez       $v0, .L8004B428
    /* 3BBB8 8004B3B8 21880002 */   addu      $s1, $s0, $zero
    /* 3BBBC 8004B3BC FF00D432 */  andi       $s4, $s6, 0xFF
    /* 3BBC0 8004B3C0 0180023C */  lui        $v0, %hi(D_80011434)
    /* 3BBC4 8004B3C4 34145324 */  addiu      $s3, $v0, %lo(D_80011434)
    /* 3BBC8 8004B3C8 21900002 */  addu       $s2, $s0, $zero
  .L8004B3CC:
    /* 3BBCC 8004B3CC 21187200 */  addu       $v1, $v1, $s2
    /* 3BBD0 8004B3D0 83016290 */  lbu        $v0, 0x183($v1)
    /* 3BBD4 8004B3D4 00000000 */  nop
    /* 3BBD8 8004B3D8 0A005414 */  bne        $v0, $s4, .L8004B404
    /* 3BBDC 8004B3DC FF00A232 */   andi      $v0, $s5, 0xFF
    /* 3BBE0 8004B3E0 85016390 */  lbu        $v1, 0x185($v1)
    /* 3BBE4 8004B3E4 00000000 */  nop
    /* 3BBE8 8004B3E8 06006214 */  bne        $v1, $v0, .L8004B404
    /* 3BBEC 8004B3EC 00000000 */   nop
    /* 3BBF0 8004B3F0 F029010C */  jal        func_8004A7C0
    /* 3BBF4 8004B3F4 21200002 */   addu      $a0, $s0, $zero
    /* 3BBF8 8004B3F8 0000628E */  lw         $v0, 0x0($s3)
    /* 3BBFC 8004B3FC 00000000 */  nop
    /* 3BC00 8004B400 25882202 */  or         $s1, $s1, $v0
  .L8004B404:
    /* 3BC04 8004B404 04007326 */  addiu      $s3, $s3, 0x4
    /* 3BC08 8004B408 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3BC0C 8004B40C 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3BC10 8004B410 00000000 */  nop
    /* 3BC14 8004B414 10056284 */  lh         $v0, 0x510($v1)
    /* 3BC18 8004B418 01001026 */  addiu      $s0, $s0, 0x1
    /* 3BC1C 8004B41C 2A100202 */  slt        $v0, $s0, $v0
    /* 3BC20 8004B420 EAFF4014 */  bnez       $v0, .L8004B3CC
    /* 3BC24 8004B424 28005226 */   addiu     $s2, $s2, 0x28
  .L8004B428:
    /* 3BC28 8004B428 0A002012 */  beqz       $s1, .L8004B454
    /* 3BC2C 8004B42C 02001024 */   addiu     $s0, $zero, 0x2
  .L8004B430:
    /* 3BC30 8004B430 21200000 */  addu       $a0, $zero, $zero
    /* 3BC34 8004B434 B4DB010C */  jal        func_80076ED0
    /* 3BC38 8004B438 21282002 */   addu      $a1, $s1, $zero
    /* 3BC3C 8004B43C 24DC010C */  jal        func_80077090
    /* 3BC40 8004B440 21202002 */   addu      $a0, $s1, $zero
    /* 3BC44 8004B444 03005010 */  beq        $v0, $s0, .L8004B454
    /* 3BC48 8004B448 00000000 */   nop
    /* 3BC4C 8004B44C F8FF4014 */  bnez       $v0, .L8004B430
    /* 3BC50 8004B450 00000000 */   nop
  .L8004B454:
    /* 3BC54 8004B454 FF00C232 */  andi       $v0, $s6, 0xFF
    /* 3BC58 8004B458 40180200 */  sll        $v1, $v0, 1
    /* 3BC5C 8004B45C 21186200 */  addu       $v1, $v1, $v0
    /* 3BC60 8004B460 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3BC64 8004B464 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3BC68 8004B468 C0180300 */  sll        $v1, $v1, 3
    /* 3BC6C 8004B46C 21104300 */  addu       $v0, $v0, $v1
    /* 3BC70 8004B470 040040A0 */  sb         $zero, 0x4($v0)
    /* 3BC74 8004B474 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 3BC78 8004B478 2800B68F */  lw         $s6, 0x28($sp)
    /* 3BC7C 8004B47C 2400B58F */  lw         $s5, 0x24($sp)
    /* 3BC80 8004B480 2000B48F */  lw         $s4, 0x20($sp)
    /* 3BC84 8004B484 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3BC88 8004B488 1800B28F */  lw         $s2, 0x18($sp)
    /* 3BC8C 8004B48C 1400B18F */  lw         $s1, 0x14($sp)
    /* 3BC90 8004B490 1000B08F */  lw         $s0, 0x10($sp)
    /* 3BC94 8004B494 0800E003 */  jr         $ra
    /* 3BC98 8004B498 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8004B374
