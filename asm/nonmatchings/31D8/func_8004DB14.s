nonmatching func_8004DB14, 0x124

glabel func_8004DB14
    /* 3E314 8004DB14 21500000 */  addu       $t2, $zero, $zero
    /* 3E318 8004DB18 80100500 */  sll        $v0, $a1, 2
    /* 3E31C 8004DB1C 21108200 */  addu       $v0, $a0, $v0
    /* 3E320 8004DB20 E0014B8C */  lw         $t3, 0x1E0($v0)
    /* 3E324 8004DB24 00000000 */  nop
    /* 3E328 8004DB28 03006015 */  bnez       $t3, .L8004DB38
    /* 3E32C 8004DB2C 01000824 */   addiu     $t0, $zero, 0x1
  .L8004DB30:
    /* 3E330 8004DB30 0800E003 */  jr         $ra
    /* 3E334 8004DB34 21100000 */   addu      $v0, $zero, $zero
  .L8004DB38:
    /* 3E338 8004DB38 16006295 */  lhu        $v0, 0x16($t3)
    /* 3E33C 8004DB3C D80D838C */  lw         $v1, 0xDD8($a0)
    /* 3E340 8004DB40 80100200 */  sll        $v0, $v0, 2
    /* 3E344 8004DB44 21306200 */  addu       $a2, $v1, $v0
    /* 3E348 8004DB48 0000C28C */  lw         $v0, 0x0($a2)
    /* 3E34C 8004DB4C 00000000 */  nop
    /* 3E350 8004DB50 F7FF4004 */  bltz       $v0, .L8004DB30
    /* 3E354 8004DB54 21486000 */   addu      $t1, $v1, $zero
    /* 3E358 8004DB58 FFFF0C34 */  ori        $t4, $zero, 0xFFFF
    /* 3E35C 8004DB5C 40100500 */  sll        $v0, $a1, 1
    /* 3E360 8004DB60 74004724 */  addiu      $a3, $v0, 0x74
  .L8004DB64:
    /* 3E364 8004DB64 21108700 */  addu       $v0, $a0, $a3
    /* 3E368 8004DB68 C8024394 */  lhu        $v1, 0x2C8($v0)
    /* 3E36C 8004DB6C 00000000 */  nop
    /* 3E370 8004DB70 80100300 */  sll        $v0, $v1, 2
    /* 3E374 8004DB74 0C006C10 */  beq        $v1, $t4, .L8004DBA8
    /* 3E378 8004DB78 21282201 */   addu      $a1, $t1, $v0
    /* 3E37C 8004DB7C FCFFA224 */  addiu      $v0, $a1, -0x4
    /* 3E380 8004DB80 2B10C200 */  sltu       $v0, $a2, $v0
    /* 3E384 8004DB84 08004014 */  bnez       $v0, .L8004DBA8
    /* 3E388 8004DB88 00000000 */   nop
    /* 3E38C 8004DB8C FCFFA294 */  lhu        $v0, -0x4($a1)
    /* 3E390 8004DB90 00000000 */  nop
    /* 3E394 8004DB94 80100200 */  sll        $v0, $v0, 2
    /* 3E398 8004DB98 21102201 */  addu       $v0, $t1, $v0
    /* 3E39C 8004DB9C 2B104600 */  sltu       $v0, $v0, $a2
    /* 3E3A0 8004DBA0 06004010 */  beqz       $v0, .L8004DBBC
    /* 3E3A4 8004DBA4 0A000229 */   slti      $v0, $t0, 0xA
  .L8004DBA8:
    /* 3E3A8 8004DBA8 01000825 */  addiu      $t0, $t0, 0x1
    /* 3E3AC 8004DBAC 0A000229 */  slti       $v0, $t0, 0xA
    /* 3E3B0 8004DBB0 ECFF4014 */  bnez       $v0, .L8004DB64
    /* 3E3B4 8004DBB4 7400E724 */   addiu     $a3, $a3, 0x74
    /* 3E3B8 8004DBB8 0A000229 */  slti       $v0, $t0, 0xA
  .L8004DBBC:
    /* 3E3BC 8004DBBC 1A004010 */  beqz       $v0, .L8004DC28
    /* 3E3C0 8004DBC0 00000000 */   nop
    /* 3E3C4 8004DBC4 2B10A600 */  sltu       $v0, $a1, $a2
    /* 3E3C8 8004DBC8 07004010 */  beqz       $v0, .L8004DBE8
    /* 3E3CC 8004DBCC 00000000 */   nop
  .L8004DBD0:
    /* 3E3D0 8004DBD0 0200A290 */  lbu        $v0, 0x2($a1)
    /* 3E3D4 8004DBD4 0400A524 */  addiu      $a1, $a1, 0x4
    /* 3E3D8 8004DBD8 21504201 */  addu       $t2, $t2, $v0
    /* 3E3DC 8004DBDC 2B10A600 */  sltu       $v0, $a1, $a2
    /* 3E3E0 8004DBE0 FBFF4014 */  bnez       $v0, .L8004DBD0
    /* 3E3E4 8004DBE4 00000000 */   nop
  .L8004DBE8:
    /* 3E3E8 8004DBE8 10006385 */  lh         $v1, 0x10($t3)
    /* 3E3EC 8004DBEC 00600224 */  addiu      $v0, $zero, 0x6000
    /* 3E3F0 8004DBF0 0F006210 */  beq        $v1, $v0, .L8004DC30
    /* 3E3F4 8004DBF4 00160800 */   sll       $v0, $t0, 24
    /* 3E3F8 8004DBF8 00700224 */  addiu      $v0, $zero, 0x7000
    /* 3E3FC 8004DBFC 0C006210 */  beq        $v1, $v0, .L8004DC30
    /* 3E400 8004DC00 00160800 */   sll       $v0, $t0, 24
    /* 3E404 8004DC04 12006295 */  lhu        $v0, 0x12($t3)
    /* 3E408 8004DC08 00000000 */  nop
    /* 3E40C 8004DC0C 23104300 */  subu       $v0, $v0, $v1
    /* 3E410 8004DC10 02004104 */  bgez       $v0, .L8004DC1C
    /* 3E414 8004DC14 00000000 */   nop
    /* 3E418 8004DC18 0F004224 */  addiu      $v0, $v0, 0xF
  .L8004DC1C:
    /* 3E41C 8004DC1C 03110200 */  sra        $v0, $v0, 4
    /* 3E420 8004DC20 0B370108 */  j          .L8004DC2C
    /* 3E424 8004DC24 21504201 */   addu      $t2, $t2, $v0
  .L8004DC28:
    /* 3E428 8004DC28 21400000 */  addu       $t0, $zero, $zero
  .L8004DC2C:
    /* 3E42C 8004DC2C 00160800 */  sll        $v0, $t0, 24
  .L8004DC30:
    /* 3E430 8004DC30 0800E003 */  jr         $ra
    /* 3E434 8004DC34 25104A00 */   or        $v0, $v0, $t2
endlabel func_8004DB14
