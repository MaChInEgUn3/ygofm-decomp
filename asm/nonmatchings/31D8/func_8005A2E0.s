nonmatching func_8005A2E0, 0xF0

glabel func_8005A2E0
    /* 4AAE0 8005A2E0 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4AAE4 8005A2E4 21108000 */  addu       $v0, $a0, $zero
    /* 4AAE8 8005A2E8 1800A427 */  addiu      $a0, $sp, 0x18
    /* 4AAEC 8005A2EC 2000B0AF */  sw         $s0, 0x20($sp)
    /* 4AAF0 8005A2F0 C0800200 */  sll        $s0, $v0, 3
    /* 4AAF4 8005A2F4 23800202 */  subu       $s0, $s0, $v0
    /* 4AAF8 8005A2F8 00811000 */  sll        $s0, $s0, 4
    /* 4AAFC 8005A2FC 21800202 */  addu       $s0, $s0, $v0
    /* 4AB00 8005A300 40811000 */  sll        $s0, $s0, 5
    /* 4AB04 8005A304 0F80023C */  lui        $v0, %hi(D_800F3A10)
    /* 4AB08 8005A308 103A4224 */  addiu      $v0, $v0, %lo(D_800F3A10)
    /* 4AB0C 8005A30C 21800202 */  addu       $s0, $s0, $v0
    /* 4AB10 8005A310 21280000 */  addu       $a1, $zero, $zero
    /* 4AB14 8005A314 2400BFAF */  sw         $ra, 0x24($sp)
    /* 4AB18 8005A318 F438020C */  jal        func_8008E3D0
    /* 4AB1C 8005A31C 08000624 */   addiu     $a2, $zero, 0x8
    /* 4AB20 8005A320 0F80043C */  lui        $a0, %hi(D_800F56F0)
    /* 4AB24 8005A324 F0568424 */  addiu      $a0, $a0, %lo(D_800F56F0)
    /* 4AB28 8005A328 0C008294 */  lhu        $v0, 0xC($a0)
    /* 4AB2C 8005A32C 00000396 */  lhu        $v1, 0x0($s0)
    /* 4AB30 8005A330 00000000 */  nop
    /* 4AB34 8005A334 23104300 */  subu       $v0, $v0, $v1
    /* 4AB38 8005A338 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 4AB3C 8005A33C 10008294 */  lhu        $v0, 0x10($a0)
    /* 4AB40 8005A340 02000396 */  lhu        $v1, 0x2($s0)
    /* 4AB44 8005A344 00000000 */  nop
    /* 4AB48 8005A348 23104300 */  subu       $v0, $v0, $v1
    /* 4AB4C 8005A34C 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 4AB50 8005A350 14008294 */  lhu        $v0, 0x14($a0)
    /* 4AB54 8005A354 04000396 */  lhu        $v1, 0x4($s0)
    /* 4AB58 8005A358 00000000 */  nop
    /* 4AB5C 8005A35C 23104300 */  subu       $v0, $v0, $v1
    /* 4AB60 8005A360 1C00A2A7 */  sh         $v0, 0x1C($sp)
    /* 4AB64 8005A364 1B00A78B */  lwl        $a3, 0x1B($sp)
    /* 4AB68 8005A368 1800A79B */  lwr        $a3, 0x18($sp)
    /* 4AB6C 8005A36C 1F00A88B */  lwl        $t0, 0x1F($sp)
    /* 4AB70 8005A370 1C00A89B */  lwr        $t0, 0x1C($sp)
    /* 4AB74 8005A374 1300A7AB */  swl        $a3, 0x13($sp)
    /* 4AB78 8005A378 1000A7BB */  swr        $a3, 0x10($sp)
    /* 4AB7C 8005A37C 1700A8AB */  swl        $t0, 0x17($sp)
    /* 4AB80 8005A380 1400A8BB */  swr        $t0, 0x14($sp)
    /* 4AB84 8005A384 1000A287 */  lh         $v0, 0x10($sp)
    /* 4AB88 8005A388 00000000 */  nop
    /* 4AB8C 8005A38C 18004200 */  mult       $v0, $v0
    /* 4AB90 8005A390 12200000 */  mflo       $a0
    /* 4AB94 8005A394 1200A287 */  lh         $v0, 0x12($sp)
    /* 4AB98 8005A398 00000000 */  nop
    /* 4AB9C 8005A39C 18004200 */  mult       $v0, $v0
    /* 4ABA0 8005A3A0 12180000 */  mflo       $v1
    /* 4ABA4 8005A3A4 1400A287 */  lh         $v0, 0x14($sp)
    /* 4ABA8 8005A3A8 00000000 */  nop
    /* 4ABAC 8005A3AC 18004200 */  mult       $v0, $v0
    /* 4ABB0 8005A3B0 21208300 */  addu       $a0, $a0, $v1
    /* 4ABB4 8005A3B4 12580000 */  mflo       $t3
    /* 4ABB8 8005A3B8 941B020C */  jal        func_80086E50
    /* 4ABBC 8005A3BC 21208B00 */   addu      $a0, $a0, $t3
    /* 4ABC0 8005A3C0 2400BF8F */  lw         $ra, 0x24($sp)
    /* 4ABC4 8005A3C4 2000B08F */  lw         $s0, 0x20($sp)
    /* 4ABC8 8005A3C8 0800E003 */  jr         $ra
    /* 4ABCC 8005A3CC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8005A2E0
