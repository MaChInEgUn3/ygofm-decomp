nonmatching func_8004BBBC, 0x70

glabel func_8004BBBC
    /* 3C3BC 8004BBBC E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3C3C0 8004BBC0 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3C3C4 8004BBC4 21808000 */  addu       $s0, $a0, $zero
    /* 3C3C8 8004BBC8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3C3CC 8004BBCC 0A80113C */  lui        $s1, %hi(D_8009AF80)
    /* 3C3D0 8004BBD0 1800BFAF */  sw         $ra, 0x18($sp)
  .L8004BBD4:
    /* 3C3D4 8004BBD4 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3C3D8 8004BBD8 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3C3DC 8004BBDC 80AF2426 */  addiu      $a0, $s1, %lo(D_8009AF80)
    /* 3C3E0 8004BBE0 DC07458C */  lw         $a1, 0x7DC($v0)
    /* 3C3E4 8004BBE4 04000624 */  addiu      $a2, $zero, 0x4
    /* 3C3E8 8004BBE8 A82E010C */  jal        func_8004BAA0
    /* 3C3EC 8004BBEC 2128B000 */   addu      $a1, $a1, $s0
    /* 3C3F0 8004BBF0 09004010 */  beqz       $v0, .L8004BC18
    /* 3C3F4 8004BBF4 04000226 */   addiu     $v0, $s0, 0x4
    /* 3C3F8 8004BBF8 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3C3FC 8004BBFC 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3C400 8004BC00 00000000 */  nop
    /* 3C404 8004BC04 EC07428C */  lw         $v0, 0x7EC($v0)
    /* 3C408 8004BC08 01001026 */  addiu      $s0, $s0, 0x1
    /* 3C40C 8004BC0C 2B105000 */  sltu       $v0, $v0, $s0
    /* 3C410 8004BC10 F0FF4010 */  beqz       $v0, .L8004BBD4
    /* 3C414 8004BC14 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8004BC18:
    /* 3C418 8004BC18 1800BF8F */  lw         $ra, 0x18($sp)
    /* 3C41C 8004BC1C 1400B18F */  lw         $s1, 0x14($sp)
    /* 3C420 8004BC20 1000B08F */  lw         $s0, 0x10($sp)
    /* 3C424 8004BC24 0800E003 */  jr         $ra
    /* 3C428 8004BC28 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8004BBBC
