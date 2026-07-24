nonmatching func_8002ABB4, 0xF0

glabel func_8002ABB4
    /* 1B3B4 8002ABB4 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 1B3B8 8002ABB8 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1B3BC 8002ABBC 21888000 */  addu       $s1, $a0, $zero
    /* 1B3C0 8002ABC0 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1B3C4 8002ABC4 2190A000 */  addu       $s2, $a1, $zero
    /* 1B3C8 8002ABC8 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 1B3CC 8002ABCC 0B00010C */  jal        func_8004002C
    /* 1B3D0 8002ABD0 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1B3D4 8002ABD4 21204000 */  addu       $a0, $v0, $zero
    /* 1B3D8 8002ABD8 2B00010C */  jal        func_800400AC
    /* 1B3DC 8002ABDC 06000524 */   addiu     $a1, $zero, 0x6
    /* 1B3E0 8002ABE0 4800238E */  lw         $v1, 0x48($s1)
    /* 1B3E4 8002ABE4 21804000 */  addu       $s0, $v0, $zero
    /* 1B3E8 8002ABE8 480003AE */  sw         $v1, 0x48($s0)
    /* 1B3EC 8002ABEC 1800238E */  lw         $v1, 0x18($s1)
    /* 1B3F0 8002ABF0 00010224 */  addiu      $v0, $zero, 0x100
    /* 1B3F4 8002ABF4 600002A6 */  sh         $v0, 0x60($s0)
    /* 1B3F8 8002ABF8 180003AE */  sw         $v1, 0x18($s0)
    /* 1B3FC 8002ABFC 18000286 */  lh         $v0, 0x18($s0)
    /* 1B400 8002AC00 1A000386 */  lh         $v1, 0x1A($s0)
    /* 1B404 8002AC04 40100200 */  sll        $v0, $v0, 1
    /* 1B408 8002AC08 40180300 */  sll        $v1, $v1, 1
    /* 1B40C 8002AC0C 3C0002A6 */  sh         $v0, 0x3C($s0)
    /* 1B410 8002AC10 3E0003A6 */  sh         $v1, 0x3E($s0)
    /* 1B414 8002AC14 3000228E */  lw         $v0, 0x30($s1)
    /* 1B418 8002AC18 00000000 */  nop
    /* 1B41C 8002AC1C 300002AE */  sw         $v0, 0x30($s0)
    /* 1B420 8002AC20 2000228E */  lw         $v0, 0x20($s1)
    /* 1B424 8002AC24 00000000 */  nop
    /* 1B428 8002AC28 200002AE */  sw         $v0, 0x20($s0)
    /* 1B42C 8002AC2C 4400228E */  lw         $v0, 0x44($s1)
    /* 1B430 8002AC30 21200002 */  addu       $a0, $s0, $zero
    /* 1B434 8002AC34 0C0000AE */  sw         $zero, 0xC($s0)
    /* 1B438 8002AC38 460A010C */  jal        func_80042918
    /* 1B43C 8002AC3C 440002AE */   sw        $v0, 0x44($s0)
    /* 1B440 8002AC40 16002592 */  lbu        $a1, 0x16($s1)
    /* 1B444 8002AC44 21200002 */  addu       $a0, $s0, $zero
    /* 1B448 8002AC48 2128B200 */  addu       $a1, $a1, $s2
    /* 1B44C 8002AC4C 002E0500 */  sll        $a1, $a1, 24
    /* 1B450 8002AC50 3B0A010C */  jal        func_800428EC
    /* 1B454 8002AC54 032E0500 */   sra       $a1, $a1, 24
    /* 1B458 8002AC58 FFF7053C */  lui        $a1, (0xF7FFFFFF >> 16)
    /* 1B45C 8002AC5C FFFFA534 */  ori        $a1, $a1, (0xF7FFFFFF & 0xFFFF)
    /* 1B460 8002AC60 21100002 */  addu       $v0, $s0, $zero
    /* 1B464 8002AC64 01000324 */  addiu      $v1, $zero, 0x1
    /* 1B468 8002AC68 100043AC */  sw         $v1, 0x10($v0)
    /* 1B46C 8002AC6C 0380033C */  lui        $v1, %hi(func_8002A9C0)
    /* 1B470 8002AC70 C0A96324 */  addiu      $v1, $v1, %lo(func_8002A9C0)
    /* 1B474 8002AC74 4C0043AC */  sw         $v1, 0x4C($v0)
    /* 1B478 8002AC78 0400438C */  lw         $v1, 0x4($v0)
    /* 1B47C 8002AC7C 0050043C */  lui        $a0, (0x50000000 >> 16)
    /* 1B480 8002AC80 25186400 */  or         $v1, $v1, $a0
    /* 1B484 8002AC84 24186500 */  and        $v1, $v1, $a1
    /* 1B488 8002AC88 040043AC */  sw         $v1, 0x4($v0)
    /* 1B48C 8002AC8C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 1B490 8002AC90 1800B28F */  lw         $s2, 0x18($sp)
    /* 1B494 8002AC94 1400B18F */  lw         $s1, 0x14($sp)
    /* 1B498 8002AC98 1000B08F */  lw         $s0, 0x10($sp)
    /* 1B49C 8002AC9C 0800E003 */  jr         $ra
    /* 1B4A0 8002ACA0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8002ABB4
