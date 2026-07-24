nonmatching func_8007BB74, 0xD4

glabel func_8007BB74
    /* 6C374 8007BB74 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 6C378 8007BB78 1400B1AF */  sw         $s1, 0x14($sp)
    /* 6C37C 8007BB7C 2188A000 */  addu       $s1, $a1, $zero
    /* 6C380 8007BB80 1000B0AF */  sw         $s0, 0x10($sp)
    /* 6C384 8007BB84 21808000 */  addu       $s0, $a0, $zero
    /* 6C388 8007BB88 FF000332 */  andi       $v1, $s0, 0xFF
    /* 6C38C 8007BB8C 05000224 */  addiu      $v0, $zero, 0x5
    /* 6C390 8007BB90 09006214 */  bne        $v1, $v0, .L8007BBB8
    /* 6C394 8007BB94 1800BFAF */   sw        $ra, 0x18($sp)
    /* 6C398 8007BB98 00002292 */  lbu        $v0, 0x0($s1)
    /* 6C39C 8007BB9C 00000000 */  nop
    /* 6C3A0 8007BBA0 10004230 */  andi       $v0, $v0, 0x10
    /* 6C3A4 8007BBA4 05004010 */  beqz       $v0, .L8007BBBC
    /* 6C3A8 8007BBA8 04000224 */   addiu     $v0, $zero, 0x4
    /* 6C3AC 8007BBAC A5EA010C */  jal        func_8007AA94
    /* 6C3B0 8007BBB0 05000424 */   addiu     $a0, $zero, 0x5
    /* 6C3B4 8007BBB4 FF000332 */  andi       $v1, $s0, 0xFF
  .L8007BBB8:
    /* 6C3B8 8007BBB8 04000224 */  addiu      $v0, $zero, 0x4
  .L8007BBBC:
    /* 6C3BC 8007BBBC 0E006210 */  beq        $v1, $v0, .L8007BBF8
    /* 6C3C0 8007BBC0 05006228 */   slti      $v0, $v1, 0x5
    /* 6C3C4 8007BBC4 05004010 */  beqz       $v0, .L8007BBDC
    /* 6C3C8 8007BBC8 01000224 */   addiu     $v0, $zero, 0x1
    /* 6C3CC 8007BBCC 06006210 */  beq        $v1, $v0, .L8007BBE8
    /* 6C3D0 8007BBD0 00000000 */   nop
    /* 6C3D4 8007BBD4 06EF0108 */  j          .L8007BC18
    /* 6C3D8 8007BBD8 00000000 */   nop
  .L8007BBDC:
    /* 6C3DC 8007BBDC 05000224 */  addiu      $v0, $zero, 0x5
    /* 6C3E0 8007BBE0 0D006214 */  bne        $v1, $v0, .L8007BC18
    /* 6C3E4 8007BBE4 00000000 */   nop
  .L8007BBE8:
    /* 6C3E8 8007BBE8 0F80033C */  lui        $v1, %hi(D_800F5E00)
    /* 6C3EC 8007BBEC 005E6324 */  addiu      $v1, $v1, %lo(D_800F5E00)
    /* 6C3F0 8007BBF0 01EF0108 */  j          .L8007BC04
    /* 6C3F4 8007BBF4 05006424 */   addiu     $a0, $v1, 0x5
  .L8007BBF8:
    /* 6C3F8 8007BBF8 0F80033C */  lui        $v1, %hi(D_800F5E10)
    /* 6C3FC 8007BBFC 105E6324 */  addiu      $v1, $v1, %lo(D_800F5E10)
    /* 6C400 8007BC00 05006424 */  addiu      $a0, $v1, 0x5
  .L8007BC04:
    /* 6C404 8007BC04 21282002 */  addu       $a1, $s1, $zero
    /* 6C408 8007BC08 01000224 */  addiu      $v0, $zero, 0x1
    /* 6C40C 8007BC0C 000062AC */  sw         $v0, 0x0($v1)
    /* 6C410 8007BC10 5BF3010C */  jal        func_8007CD6C
    /* 6C414 8007BC14 040070A0 */   sb        $s0, 0x4($v1)
  .L8007BC18:
    /* 6C418 8007BC18 1080023C */  lui        $v0, %hi(D_800F8394)
    /* 6C41C 8007BC1C 9483428C */  lw         $v0, %lo(D_800F8394)($v0)
    /* 6C420 8007BC20 00000000 */  nop
    /* 6C424 8007BC24 03004010 */  beqz       $v0, .L8007BC34
    /* 6C428 8007BC28 FF000432 */   andi      $a0, $s0, 0xFF
    /* 6C42C 8007BC2C 09F84000 */  jalr       $v0
    /* 6C430 8007BC30 21282002 */   addu      $a1, $s1, $zero
  .L8007BC34:
    /* 6C434 8007BC34 1800BF8F */  lw         $ra, 0x18($sp)
    /* 6C438 8007BC38 1400B18F */  lw         $s1, 0x14($sp)
    /* 6C43C 8007BC3C 1000B08F */  lw         $s0, 0x10($sp)
    /* 6C440 8007BC40 0800E003 */  jr         $ra
    /* 6C444 8007BC44 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007BB74
