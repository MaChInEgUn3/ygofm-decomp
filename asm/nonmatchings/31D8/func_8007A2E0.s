nonmatching func_8007A2E0, 0x1E0

glabel func_8007A2E0
    /* 6AAE0 8007A2E0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 6AAE4 8007A2E4 0180043C */  lui        $a0, %hi(D_80011DA8)
    /* 6AAE8 8007A2E8 A81D8424 */  addiu      $a0, $a0, %lo(D_80011DA8)
    /* 6AAEC 8007A2EC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 6AAF0 8007A2F0 BC3E020C */  jal        func_8008FAF0
    /* 6AAF4 8007A2F4 00000000 */   nop
    /* 6AAF8 8007A2F8 0180043C */  lui        $a0, %hi(D_80011DB4)
    /* 6AAFC 8007A2FC B41D8424 */  addiu      $a0, $a0, %lo(D_80011DB4)
    /* 6AB00 8007A300 0980053C */  lui        $a1, %hi(D_800937C0)
    /* 6AB04 8007A304 1C3A020C */  jal        func_8008E870
    /* 6AB08 8007A308 C037A524 */   addiu     $a1, $a1, %lo(D_800937C0)
    /* 6AB0C 8007A30C 0980013C */  lui        $at, %hi(D_800934FD)
    /* 6AB10 8007A310 FD3420A0 */  sb         $zero, %lo(D_800934FD)($at)
    /* 6AB14 8007A314 0980013C */  lui        $at, %hi(D_800934FC)
    /* 6AB18 8007A318 FC3420A0 */  sb         $zero, %lo(D_800934FC)($at)
    /* 6AB1C 8007A31C 0980013C */  lui        $at, %hi(D_800934E4)
    /* 6AB20 8007A320 E43420AC */  sw         $zero, %lo(D_800934E4)($at)
    /* 6AB24 8007A324 0980013C */  lui        $at, %hi(D_800934E0)
    /* 6AB28 8007A328 E03420AC */  sw         $zero, %lo(D_800934E0)($at)
    /* 6AB2C 8007A32C 0980013C */  lui        $at, %hi(D_800934F0)
    /* 6AB30 8007A330 F03420AC */  sw         $zero, %lo(D_800934F0)($at)
    /* 6AB34 8007A334 0980013C */  lui        $at, %hi(D_800934EC)
    /* 6AB38 8007A338 E4D0010C */  jal        func_80074390
    /* 6AB3C 8007A33C EC3420AC */   sw        $zero, %lo(D_800934EC)($at)
    /* 6AB40 8007A340 0880053C */  lui        $a1, %hi(func_8007A634)
    /* 6AB44 8007A344 34A6A524 */  addiu      $a1, $a1, %lo(func_8007A634)
    /* 6AB48 8007A348 F0D0010C */  jal        func_800743C0
    /* 6AB4C 8007A34C 02000424 */   addiu     $a0, $zero, 0x2
    /* 6AB50 8007A350 0980033C */  lui        $v1, %hi(D_800937A4)
    /* 6AB54 8007A354 A437638C */  lw         $v1, %lo(D_800937A4)($v1)
    /* 6AB58 8007A358 01000224 */  addiu      $v0, $zero, 0x1
    /* 6AB5C 8007A35C 000062A0 */  sb         $v0, 0x0($v1)
    /* 6AB60 8007A360 0980023C */  lui        $v0, %hi(D_800937A8)
    /* 6AB64 8007A364 A837428C */  lw         $v0, %lo(D_800937A8)($v0)
    /* 6AB68 8007A368 00000000 */  nop
    /* 6AB6C 8007A36C 00004290 */  lbu        $v0, 0x0($v0)
    /* 6AB70 8007A370 00000000 */  nop
    /* 6AB74 8007A374 07004230 */  andi       $v0, $v0, 0x7
    /* 6AB78 8007A378 16004010 */  beqz       $v0, .L8007A3D4
    /* 6AB7C 8007A37C 01000424 */   addiu     $a0, $zero, 0x1
    /* 6AB80 8007A380 07000324 */  addiu      $v1, $zero, 0x7
  .L8007A384:
    /* 6AB84 8007A384 0980023C */  lui        $v0, %hi(D_800937A4)
    /* 6AB88 8007A388 A437428C */  lw         $v0, %lo(D_800937A4)($v0)
    /* 6AB8C 8007A38C 00000000 */  nop
    /* 6AB90 8007A390 000044A0 */  sb         $a0, 0x0($v0)
    /* 6AB94 8007A394 0980023C */  lui        $v0, %hi(D_800937A8)
    /* 6AB98 8007A398 A837428C */  lw         $v0, %lo(D_800937A8)($v0)
    /* 6AB9C 8007A39C 00000000 */  nop
    /* 6ABA0 8007A3A0 000043A0 */  sb         $v1, 0x0($v0)
    /* 6ABA4 8007A3A4 0980023C */  lui        $v0, %hi(D_800937B4)
    /* 6ABA8 8007A3A8 B437428C */  lw         $v0, %lo(D_800937B4)($v0)
    /* 6ABAC 8007A3AC 00000000 */  nop
    /* 6ABB0 8007A3B0 000043A0 */  sb         $v1, 0x0($v0)
    /* 6ABB4 8007A3B4 0980023C */  lui        $v0, %hi(D_800937A8)
    /* 6ABB8 8007A3B8 A837428C */  lw         $v0, %lo(D_800937A8)($v0)
    /* 6ABBC 8007A3BC 00000000 */  nop
    /* 6ABC0 8007A3C0 00004290 */  lbu        $v0, 0x0($v0)
    /* 6ABC4 8007A3C4 00000000 */  nop
    /* 6ABC8 8007A3C8 07004230 */  andi       $v0, $v0, 0x7
    /* 6ABCC 8007A3CC EDFF4014 */  bnez       $v0, .L8007A384
    /* 6ABD0 8007A3D0 00000000 */   nop
  .L8007A3D4:
    /* 6ABD4 8007A3D4 01000424 */  addiu      $a0, $zero, 0x1
    /* 6ABD8 8007A3D8 21280000 */  addu       $a1, $zero, $zero
    /* 6ABDC 8007A3DC 0980033C */  lui        $v1, %hi(D_800937BC)
    /* 6ABE0 8007A3E0 BC376324 */  addiu      $v1, $v1, %lo(D_800937BC)
    /* 6ABE4 8007A3E4 020060A0 */  sb         $zero, 0x2($v1)
    /* 6ABE8 8007A3E8 02006290 */  lbu        $v0, 0x2($v1)
    /* 6ABEC 8007A3EC 21300000 */  addu       $a2, $zero, $zero
    /* 6ABF0 8007A3F0 010062A0 */  sb         $v0, 0x1($v1)
    /* 6ABF4 8007A3F4 0980073C */  lui        $a3, %hi(D_800937A4)
    /* 6ABF8 8007A3F8 A437E78C */  lw         $a3, %lo(D_800937A4)($a3)
    /* 6ABFC 8007A3FC 02000224 */  addiu      $v0, $zero, 0x2
    /* 6AC00 8007A400 000062A0 */  sb         $v0, 0x0($v1)
    /* 6AC04 8007A404 0000E0A0 */  sb         $zero, 0x0($a3)
    /* 6AC08 8007A408 0980023C */  lui        $v0, %hi(D_800937A8)
    /* 6AC0C 8007A40C A837428C */  lw         $v0, %lo(D_800937A8)($v0)
    /* 6AC10 8007A410 21380000 */  addu       $a3, $zero, $zero
    /* 6AC14 8007A414 000040A0 */  sb         $zero, 0x0($v0)
    /* 6AC18 8007A418 0980033C */  lui        $v1, %hi(D_800937AC)
    /* 6AC1C 8007A41C AC37638C */  lw         $v1, %lo(D_800937AC)($v1)
    /* 6AC20 8007A420 25130224 */  addiu      $v0, $zero, 0x1325
    /* 6AC24 8007A424 0FE7010C */  jal        func_80079C3C
    /* 6AC28 8007A428 000062AC */   sw        $v0, 0x0($v1)
    /* 6AC2C 8007A42C 0980023C */  lui        $v0, %hi(D_800934EC)
    /* 6AC30 8007A430 EC34428C */  lw         $v0, %lo(D_800934EC)($v0)
    /* 6AC34 8007A434 00000000 */  nop
    /* 6AC38 8007A438 10004230 */  andi       $v0, $v0, 0x10
    /* 6AC3C 8007A43C 05004010 */  beqz       $v0, .L8007A454
    /* 6AC40 8007A440 01000424 */   addiu     $a0, $zero, 0x1
    /* 6AC44 8007A444 21280000 */  addu       $a1, $zero, $zero
    /* 6AC48 8007A448 21300000 */  addu       $a2, $zero, $zero
    /* 6AC4C 8007A44C 0FE7010C */  jal        func_80079C3C
    /* 6AC50 8007A450 21380000 */   addu      $a3, $zero, $zero
  .L8007A454:
    /* 6AC54 8007A454 0A000424 */  addiu      $a0, $zero, 0xA
    /* 6AC58 8007A458 21280000 */  addu       $a1, $zero, $zero
    /* 6AC5C 8007A45C 21300000 */  addu       $a2, $zero, $zero
    /* 6AC60 8007A460 0FE7010C */  jal        func_80079C3C
    /* 6AC64 8007A464 21380000 */   addu      $a3, $zero, $zero
    /* 6AC68 8007A468 11004014 */  bnez       $v0, .L8007A4B0
    /* 6AC6C 8007A46C FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 6AC70 8007A470 0C000424 */  addiu      $a0, $zero, 0xC
    /* 6AC74 8007A474 21280000 */  addu       $a1, $zero, $zero
    /* 6AC78 8007A478 21300000 */  addu       $a2, $zero, $zero
    /* 6AC7C 8007A47C 0FE7010C */  jal        func_80079C3C
    /* 6AC80 8007A480 21380000 */   addu      $a3, $zero, $zero
    /* 6AC84 8007A484 09004014 */  bnez       $v0, .L8007A4AC
    /* 6AC88 8007A488 21200000 */   addu      $a0, $zero, $zero
    /* 6AC8C 8007A48C BDE5010C */  jal        func_800796F4
    /* 6AC90 8007A490 21280000 */   addu      $a1, $zero, $zero
    /* 6AC94 8007A494 21204000 */  addu       $a0, $v0, $zero
    /* 6AC98 8007A498 02000324 */  addiu      $v1, $zero, 0x2
    /* 6AC9C 8007A49C 04008314 */  bne        $a0, $v1, .L8007A4B0
    /* 6ACA0 8007A4A0 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 6ACA4 8007A4A4 2CE90108 */  j          .L8007A4B0
    /* 6ACA8 8007A4A8 21100000 */   addu      $v0, $zero, $zero
  .L8007A4AC:
    /* 6ACAC 8007A4AC FFFF0224 */  addiu      $v0, $zero, -0x1
  .L8007A4B0:
    /* 6ACB0 8007A4B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 6ACB4 8007A4B4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 6ACB8 8007A4B8 0800E003 */  jr         $ra
    /* 6ACBC 8007A4BC 00000000 */   nop
endlabel func_8007A2E0
