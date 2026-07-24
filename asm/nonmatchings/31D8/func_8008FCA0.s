nonmatching func_8008FCA0, 0x98

glabel func_8008FCA0
    /* 804A0 8008FCA0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 804A4 8008FCA4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 804A8 8008FCA8 21808000 */  addu       $s0, $a0, $zero
    /* 804AC 8008FCAC 0A80053C */  lui        $a1, %hi(D_80099F7C)
    /* 804B0 8008FCB0 7C9FA524 */  addiu      $a1, $a1, %lo(D_80099F7C)
    /* 804B4 8008FCB4 0F000324 */  addiu      $v1, $zero, 0xF
    /* 804B8 8008FCB8 FFFF0624 */  addiu      $a2, $zero, -0x1
    /* 804BC 8008FCBC 1400BFAF */  sw         $ra, 0x14($sp)
  .L8008FCC0:
    /* 804C0 8008FCC0 0000828C */  lw         $v0, 0x0($a0)
    /* 804C4 8008FCC4 04008424 */  addiu      $a0, $a0, 0x4
    /* 804C8 8008FCC8 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 804CC 8008FCCC 0000A2AC */  sw         $v0, 0x0($a1)
    /* 804D0 8008FCD0 FBFF6614 */  bne        $v1, $a2, .L8008FCC0
    /* 804D4 8008FCD4 0400A524 */   addiu     $a1, $a1, 0x4
    /* 804D8 8008FCD8 0A80053C */  lui        $a1, %hi(D_80099FBC)
    /* 804DC 8008FCDC BC9FA524 */  addiu      $a1, $a1, %lo(D_80099FBC)
    /* 804E0 8008FCE0 40000426 */  addiu      $a0, $s0, 0x40
    /* 804E4 8008FCE4 0F000324 */  addiu      $v1, $zero, 0xF
    /* 804E8 8008FCE8 FFFF0624 */  addiu      $a2, $zero, -0x1
  .L8008FCEC:
    /* 804EC 8008FCEC 0000828C */  lw         $v0, 0x0($a0)
    /* 804F0 8008FCF0 04008424 */  addiu      $a0, $a0, 0x4
    /* 804F4 8008FCF4 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 804F8 8008FCF8 0000A2AC */  sw         $v0, 0x0($a1)
    /* 804FC 8008FCFC FBFF6614 */  bne        $v1, $a2, .L8008FCEC
    /* 80500 8008FD00 0400A524 */   addiu     $a1, $a1, 0x4
    /* 80504 8008FD04 0A80043C */  lui        $a0, %hi(D_80099F78)
    /* 80508 8008FD08 789F8424 */  addiu      $a0, $a0, %lo(D_80099F78)
    /* 8050C 8008FD0C E43F020C */  jal        func_8008FF90
    /* 80510 8008FD10 20000524 */   addiu     $a1, $zero, 0x20
    /* 80514 8008FD14 0A80043C */  lui        $a0, %hi(D_80099FFC)
    /* 80518 8008FD18 FC9F8424 */  addiu      $a0, $a0, %lo(D_80099FFC)
    /* 8051C 8008FD1C E43F020C */  jal        func_8008FF90
    /* 80520 8008FD20 20000524 */   addiu     $a1, $zero, 0x20
    /* 80524 8008FD24 21100002 */  addu       $v0, $s0, $zero
    /* 80528 8008FD28 1400BF8F */  lw         $ra, 0x14($sp)
    /* 8052C 8008FD2C 1000B08F */  lw         $s0, 0x10($sp)
    /* 80530 8008FD30 0800E003 */  jr         $ra
    /* 80534 8008FD34 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008FCA0
