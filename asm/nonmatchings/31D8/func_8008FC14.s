nonmatching func_8008FC14, 0x8C

glabel func_8008FC14
    /* 80414 8008FC14 21308000 */  addu       $a2, $a0, $zero
    /* 80418 8008FC18 0A80053C */  lui        $a1, %hi(D_80099F7C)
    /* 8041C 8008FC1C 7C9FA524 */  addiu      $a1, $a1, %lo(D_80099F7C)
    /* 80420 8008FC20 0F000324 */  addiu      $v1, $zero, 0xF
    /* 80424 8008FC24 FFFF0724 */  addiu      $a3, $zero, -0x1
  .L8008FC28:
    /* 80428 8008FC28 0000A28C */  lw         $v0, 0x0($a1)
    /* 8042C 8008FC2C 0400A524 */  addiu      $a1, $a1, 0x4
    /* 80430 8008FC30 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 80434 8008FC34 0000C2AC */  sw         $v0, 0x0($a2)
    /* 80438 8008FC38 FBFF6714 */  bne        $v1, $a3, .L8008FC28
    /* 8043C 8008FC3C 0400C624 */   addiu     $a2, $a2, 0x4
    /* 80440 8008FC40 40008624 */  addiu      $a2, $a0, 0x40
    /* 80444 8008FC44 0A80053C */  lui        $a1, %hi(D_80099FBC)
    /* 80448 8008FC48 BC9FA524 */  addiu      $a1, $a1, %lo(D_80099FBC)
    /* 8044C 8008FC4C 0F000324 */  addiu      $v1, $zero, 0xF
    /* 80450 8008FC50 FFFF0724 */  addiu      $a3, $zero, -0x1
  .L8008FC54:
    /* 80454 8008FC54 0000A28C */  lw         $v0, 0x0($a1)
    /* 80458 8008FC58 0400A524 */  addiu      $a1, $a1, 0x4
    /* 8045C 8008FC5C FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 80460 8008FC60 0000C2AC */  sw         $v0, 0x0($a2)
    /* 80464 8008FC64 FBFF6714 */  bne        $v1, $a3, .L8008FC54
    /* 80468 8008FC68 0400C624 */   addiu     $a2, $a2, 0x4
    /* 8046C 8008FC6C 80008624 */  addiu      $a2, $a0, 0x80
    /* 80470 8008FC70 0A80053C */  lui        $a1, %hi(D_8009A000)
    /* 80474 8008FC74 00A0A524 */  addiu      $a1, $a1, %lo(D_8009A000)
    /* 80478 8008FC78 1F000324 */  addiu      $v1, $zero, 0x1F
    /* 8047C 8008FC7C FFFF0724 */  addiu      $a3, $zero, -0x1
  .L8008FC80:
    /* 80480 8008FC80 0000A28C */  lw         $v0, 0x0($a1)
    /* 80484 8008FC84 0400A524 */  addiu      $a1, $a1, 0x4
    /* 80488 8008FC88 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 8048C 8008FC8C 0000C2AC */  sw         $v0, 0x0($a2)
    /* 80490 8008FC90 FBFF6714 */  bne        $v1, $a3, .L8008FC80
    /* 80494 8008FC94 0400C624 */   addiu     $a2, $a2, 0x4
    /* 80498 8008FC98 0800E003 */  jr         $ra
    /* 8049C 8008FC9C 21108000 */   addu      $v0, $a0, $zero
endlabel func_8008FC14
