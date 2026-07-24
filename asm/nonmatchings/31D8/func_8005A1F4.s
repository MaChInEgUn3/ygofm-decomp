nonmatching func_8005A1F4, 0xEC

glabel func_8005A1F4
    /* 4A9F4 8005A1F4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 4A9F8 8005A1F8 21108000 */  addu       $v0, $a0, $zero
    /* 4A9FC 8005A1FC 1800A427 */  addiu      $a0, $sp, 0x18
    /* 4AA00 8005A200 2000B0AF */  sw         $s0, 0x20($sp)
    /* 4AA04 8005A204 C0800200 */  sll        $s0, $v0, 3
    /* 4AA08 8005A208 23800202 */  subu       $s0, $s0, $v0
    /* 4AA0C 8005A20C 00811000 */  sll        $s0, $s0, 4
    /* 4AA10 8005A210 21800202 */  addu       $s0, $s0, $v0
    /* 4AA14 8005A214 40811000 */  sll        $s0, $s0, 5
    /* 4AA18 8005A218 0F80023C */  lui        $v0, %hi(D_800F3A10)
    /* 4AA1C 8005A21C 103A4224 */  addiu      $v0, $v0, %lo(D_800F3A10)
    /* 4AA20 8005A220 21800202 */  addu       $s0, $s0, $v0
    /* 4AA24 8005A224 21280000 */  addu       $a1, $zero, $zero
    /* 4AA28 8005A228 2400BFAF */  sw         $ra, 0x24($sp)
    /* 4AA2C 8005A22C F438020C */  jal        func_8008E3D0
    /* 4AA30 8005A230 08000624 */   addiu     $a2, $zero, 0x8
    /* 4AA34 8005A234 0F80043C */  lui        $a0, %hi(D_800F56F0)
    /* 4AA38 8005A238 F0568294 */  lhu        $v0, %lo(D_800F56F0)($a0)
    /* 4AA3C 8005A23C 00000396 */  lhu        $v1, 0x0($s0)
    /* 4AA40 8005A240 F0568424 */  addiu      $a0, $a0, %lo(D_800F56F0)
    /* 4AA44 8005A244 23104300 */  subu       $v0, $v0, $v1
    /* 4AA48 8005A248 1800A2A7 */  sh         $v0, 0x18($sp)
    /* 4AA4C 8005A24C 04008294 */  lhu        $v0, 0x4($a0)
    /* 4AA50 8005A250 02000396 */  lhu        $v1, 0x2($s0)
    /* 4AA54 8005A254 00000000 */  nop
    /* 4AA58 8005A258 23104300 */  subu       $v0, $v0, $v1
    /* 4AA5C 8005A25C 1A00A2A7 */  sh         $v0, 0x1A($sp)
    /* 4AA60 8005A260 08008294 */  lhu        $v0, 0x8($a0)
    /* 4AA64 8005A264 04000396 */  lhu        $v1, 0x4($s0)
    /* 4AA68 8005A268 00000000 */  nop
    /* 4AA6C 8005A26C 23104300 */  subu       $v0, $v0, $v1
    /* 4AA70 8005A270 1C00A2A7 */  sh         $v0, 0x1C($sp)
    /* 4AA74 8005A274 1B00A78B */  lwl        $a3, 0x1B($sp)
    /* 4AA78 8005A278 1800A79B */  lwr        $a3, 0x18($sp)
    /* 4AA7C 8005A27C 1F00A88B */  lwl        $t0, 0x1F($sp)
    /* 4AA80 8005A280 1C00A89B */  lwr        $t0, 0x1C($sp)
    /* 4AA84 8005A284 1300A7AB */  swl        $a3, 0x13($sp)
    /* 4AA88 8005A288 1000A7BB */  swr        $a3, 0x10($sp)
    /* 4AA8C 8005A28C 1700A8AB */  swl        $t0, 0x17($sp)
    /* 4AA90 8005A290 1400A8BB */  swr        $t0, 0x14($sp)
    /* 4AA94 8005A294 1000A287 */  lh         $v0, 0x10($sp)
    /* 4AA98 8005A298 00000000 */  nop
    /* 4AA9C 8005A29C 18004200 */  mult       $v0, $v0
    /* 4AAA0 8005A2A0 12200000 */  mflo       $a0
    /* 4AAA4 8005A2A4 1200A287 */  lh         $v0, 0x12($sp)
    /* 4AAA8 8005A2A8 00000000 */  nop
    /* 4AAAC 8005A2AC 18004200 */  mult       $v0, $v0
    /* 4AAB0 8005A2B0 12180000 */  mflo       $v1
    /* 4AAB4 8005A2B4 1400A287 */  lh         $v0, 0x14($sp)
    /* 4AAB8 8005A2B8 00000000 */  nop
    /* 4AABC 8005A2BC 18004200 */  mult       $v0, $v0
    /* 4AAC0 8005A2C0 21208300 */  addu       $a0, $a0, $v1
    /* 4AAC4 8005A2C4 12580000 */  mflo       $t3
    /* 4AAC8 8005A2C8 941B020C */  jal        func_80086E50
    /* 4AACC 8005A2CC 21208B00 */   addu      $a0, $a0, $t3
    /* 4AAD0 8005A2D0 2400BF8F */  lw         $ra, 0x24($sp)
    /* 4AAD4 8005A2D4 2000B08F */  lw         $s0, 0x20($sp)
    /* 4AAD8 8005A2D8 0800E003 */  jr         $ra
    /* 4AADC 8005A2DC 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8005A1F4
