nonmatching func_8003D334, 0x138

glabel func_8003D334
    /* 2DB34 8003D334 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 2DB38 8003D338 2400B5AF */  sw         $s5, 0x24($sp)
    /* 2DB3C 8003D33C 21A8A000 */  addu       $s5, $a1, $zero
    /* 2DB40 8003D340 2000033C */  lui        $v1, (0x200020 >> 16)
    /* 2DB44 8003D344 20006334 */  ori        $v1, $v1, (0x200020 & 0xFFFF)
    /* 2DB48 8003D348 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 2DB4C 8003D34C 21980000 */  addu       $s3, $zero, $zero
    /* 2DB50 8003D350 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2DB54 8003D354 21906002 */  addu       $s2, $s3, $zero
    /* 2DB58 8003D358 2800BFAF */  sw         $ra, 0x28($sp)
    /* 2DB5C 8003D35C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 2DB60 8003D360 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2DB64 8003D364 1000B0AF */  sw         $s0, 0x10($sp)
    /* 2DB68 8003D368 0400828C */  lw         $v0, 0x4($a0)
    /* 2DB6C 8003D36C 801F113C */  lui        $s1, (0x1F800004 >> 16)
    /* 2DB70 8003D370 080023AE */  sw         $v1, (0x1F800008 & 0xFFFF)($s1)
    /* 2DB74 8003D374 000022AE */  sw         $v0, (0x1F800000 & 0xFFFF)($s1)
    /* 2DB78 8003D378 0C00838C */  lw         $v1, 0xC($a0)
    /* 2DB7C 8003D37C 0B000224 */  addiu      $v0, $zero, 0xB
    /* 2DB80 8003D380 0C0022A6 */  sh         $v0, (0x1F80000C & 0xFFFF)($s1)
    /* 2DB84 8003D384 C0020224 */  addiu      $v0, $zero, 0x2C0
    /* 2DB88 8003D388 100022A6 */  sh         $v0, (0x1F800010 & 0xFFFF)($s1)
    /* 2DB8C 8003D38C FC000224 */  addiu      $v0, $zero, 0xFC
    /* 2DB90 8003D390 120022A6 */  sh         $v0, (0x1F800012 & 0xFFFF)($s1)
    /* 2DB94 8003D394 14009484 */  lh         $s4, 0x14($a0)
    /* 2DB98 8003D398 30300224 */  addiu      $v0, $zero, 0x3030
    /* 2DB9C 8003D39C 0E0022A6 */  sh         $v0, (0x1F80000E & 0xFFFF)($s1)
    /* 2DBA0 8003D3A0 140023AE */  sw         $v1, (0x1F800014 & 0xFFFF)($s1)
  .L8003D3A4:
    /* 2DBA4 8003D3A4 21800000 */  addu       $s0, $zero, $zero
    /* 2DBA8 8003D3A8 40111300 */  sll        $v0, $s3, 5
    /* 2DBAC 8003D3AC 040022A6 */  sh         $v0, (0x1F800004 & 0xFFFF)($s1)
    /* 2DBB0 8003D3B0 30000224 */  addiu      $v0, $zero, 0x30
    /* 2DBB4 8003D3B4 0E0022A2 */  sb         $v0, (0x1F80000E & 0xFFFF)($s1)
    /* 2DBB8 8003D3B8 C0020224 */  addiu      $v0, $zero, 0x2C0
    /* 2DBBC 8003D3BC 060032A6 */  sh         $s2, (0x1F800006 & 0xFFFF)($s1)
    /* 2DBC0 8003D3C0 100022A6 */  sh         $v0, (0x1F800010 & 0xFFFF)($s1)
    /* 2DBC4 8003D3C4 21202002 */  addu       $a0, $s1, $zero
  .L8003D3C8:
    /* 2DBC8 8003D3C8 2128A002 */  addu       $a1, $s5, $zero
    /* 2DBCC 8003D3CC 7C12020C */  jal        func_800849F0
    /* 2DBD0 8003D3D0 FFFF8632 */   andi      $a2, $s4, 0xFFFF
    /* 2DBD4 8003D3D4 04002296 */  lhu        $v0, (0x1F800004 & 0xFFFF)($s1)
    /* 2DBD8 8003D3D8 40001026 */  addiu      $s0, $s0, 0x40
    /* 2DBDC 8003D3DC 40004224 */  addiu      $v0, $v0, 0x40
    /* 2DBE0 8003D3E0 040022A6 */  sh         $v0, (0x1F800004 & 0xFFFF)($s1)
    /* 2DBE4 8003D3E4 4001022A */  slti       $v0, $s0, 0x140
    /* 2DBE8 8003D3E8 F7FF4014 */  bnez       $v0, .L8003D3C8
    /* 2DBEC 8003D3EC 21202002 */   addu      $a0, $s1, $zero
    /* 2DBF0 8003D3F0 21800000 */  addu       $s0, $zero, $zero
    /* 2DBF4 8003D3F4 0100623A */  xori       $v0, $s3, 0x1
    /* 2DBF8 8003D3F8 40110200 */  sll        $v0, $v0, 5
    /* 2DBFC 8003D3FC 040022A6 */  sh         $v0, (0x1F800004 & 0xFFFF)($s1)
    /* 2DC00 8003D400 50000224 */  addiu      $v0, $zero, 0x50
    /* 2DC04 8003D404 0E0022A2 */  sb         $v0, (0x1F80000E & 0xFFFF)($s1)
    /* 2DC08 8003D408 D0020224 */  addiu      $v0, $zero, 0x2D0
    /* 2DC0C 8003D40C 100022A6 */  sh         $v0, (0x1F800010 & 0xFFFF)($s1)
  .L8003D410:
    /* 2DC10 8003D410 2128A002 */  addu       $a1, $s5, $zero
    /* 2DC14 8003D414 7C12020C */  jal        func_800849F0
    /* 2DC18 8003D418 FFFF8632 */   andi      $a2, $s4, 0xFFFF
    /* 2DC1C 8003D41C 04002296 */  lhu        $v0, (0x1F800004 & 0xFFFF)($s1)
    /* 2DC20 8003D420 40001026 */  addiu      $s0, $s0, 0x40
    /* 2DC24 8003D424 40004224 */  addiu      $v0, $v0, 0x40
    /* 2DC28 8003D428 040022A6 */  sh         $v0, (0x1F800004 & 0xFFFF)($s1)
    /* 2DC2C 8003D42C 4001022A */  slti       $v0, $s0, 0x140
    /* 2DC30 8003D430 F7FF4014 */  bnez       $v0, .L8003D410
    /* 2DC34 8003D434 21202002 */   addu      $a0, $s1, $zero
    /* 2DC38 8003D438 20005226 */  addiu      $s2, $s2, 0x20
    /* 2DC3C 8003D43C F000422A */  slti       $v0, $s2, 0xF0
    /* 2DC40 8003D440 D8FF4014 */  bnez       $v0, .L8003D3A4
    /* 2DC44 8003D444 0100733A */   xori      $s3, $s3, 0x1
    /* 2DC48 8003D448 2800BF8F */  lw         $ra, 0x28($sp)
    /* 2DC4C 8003D44C 2400B58F */  lw         $s5, 0x24($sp)
    /* 2DC50 8003D450 2000B48F */  lw         $s4, 0x20($sp)
    /* 2DC54 8003D454 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 2DC58 8003D458 1800B28F */  lw         $s2, 0x18($sp)
    /* 2DC5C 8003D45C 1400B18F */  lw         $s1, 0x14($sp)
    /* 2DC60 8003D460 1000B08F */  lw         $s0, 0x10($sp)
    /* 2DC64 8003D464 0800E003 */  jr         $ra
    /* 2DC68 8003D468 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8003D334
