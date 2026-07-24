nonmatching func_8007A1A4, 0xF0

glabel func_8007A1A4
    /* 6A9A4 8007A1A4 0980033C */  lui        $v1, %hi(D_800937B8)
    /* 6A9A8 8007A1A8 B837638C */  lw         $v1, %lo(D_800937B8)($v1)
    /* 6A9AC 8007A1AC 00000000 */  nop
    /* 6A9B0 8007A1B0 B8016294 */  lhu        $v0, 0x1B8($v1)
    /* 6A9B4 8007A1B4 00000000 */  nop
    /* 6A9B8 8007A1B8 09004014 */  bnez       $v0, .L8007A1E0
    /* 6A9BC 8007A1BC F8FFBD27 */   addiu     $sp, $sp, -0x8
    /* 6A9C0 8007A1C0 BA016294 */  lhu        $v0, 0x1BA($v1)
    /* 6A9C4 8007A1C4 00000000 */  nop
    /* 6A9C8 8007A1C8 06004014 */  bnez       $v0, .L8007A1E4
    /* 6A9CC 8007A1CC FF3F0224 */   addiu     $v0, $zero, 0x3FFF
    /* 6A9D0 8007A1D0 800162A4 */  sh         $v0, 0x180($v1)
    /* 6A9D4 8007A1D4 820162A4 */  sh         $v0, 0x182($v1)
    /* 6A9D8 8007A1D8 0980033C */  lui        $v1, %hi(D_800937B8)
    /* 6A9DC 8007A1DC B837638C */  lw         $v1, %lo(D_800937B8)($v1)
  .L8007A1E0:
    /* 6A9E0 8007A1E0 FF3F0224 */  addiu      $v0, $zero, 0x3FFF
  .L8007A1E4:
    /* 6A9E4 8007A1E4 B00162A4 */  sh         $v0, 0x1B0($v1)
    /* 6A9E8 8007A1E8 B20162A4 */  sh         $v0, 0x1B2($v1)
    /* 6A9EC 8007A1EC 01C00234 */  ori        $v0, $zero, 0xC001
    /* 6A9F0 8007A1F0 AA0162A4 */  sh         $v0, 0x1AA($v1)
    /* 6A9F4 8007A1F4 0980033C */  lui        $v1, %hi(D_800937A4)
    /* 6A9F8 8007A1F8 A437638C */  lw         $v1, %lo(D_800937A4)($v1)
    /* 6A9FC 8007A1FC 80000224 */  addiu      $v0, $zero, 0x80
    /* 6AA00 8007A200 0200A2A3 */  sb         $v0, 0x2($sp)
    /* 6AA04 8007A204 0000A2A3 */  sb         $v0, 0x0($sp)
    /* 6AA08 8007A208 02000224 */  addiu      $v0, $zero, 0x2
    /* 6AA0C 8007A20C 0300A0A3 */  sb         $zero, 0x3($sp)
    /* 6AA10 8007A210 0100A0A3 */  sb         $zero, 0x1($sp)
    /* 6AA14 8007A214 000062A0 */  sb         $v0, 0x0($v1)
    /* 6AA18 8007A218 0980033C */  lui        $v1, %hi(D_800937B4)
    /* 6AA1C 8007A21C B437638C */  lw         $v1, %lo(D_800937B4)($v1)
    /* 6AA20 8007A220 0000A293 */  lbu        $v0, 0x0($sp)
    /* 6AA24 8007A224 00000000 */  nop
    /* 6AA28 8007A228 000062A0 */  sb         $v0, 0x0($v1)
    /* 6AA2C 8007A22C 0980033C */  lui        $v1, %hi(D_800937A8)
    /* 6AA30 8007A230 A837638C */  lw         $v1, %lo(D_800937A8)($v1)
    /* 6AA34 8007A234 0100A293 */  lbu        $v0, 0x1($sp)
    /* 6AA38 8007A238 00000000 */  nop
    /* 6AA3C 8007A23C 000062A0 */  sb         $v0, 0x0($v1)
    /* 6AA40 8007A240 0980033C */  lui        $v1, %hi(D_800937A4)
    /* 6AA44 8007A244 A437638C */  lw         $v1, %lo(D_800937A4)($v1)
    /* 6AA48 8007A248 03000224 */  addiu      $v0, $zero, 0x3
    /* 6AA4C 8007A24C 000062A0 */  sb         $v0, 0x0($v1)
    /* 6AA50 8007A250 0980033C */  lui        $v1, %hi(D_800937B0)
    /* 6AA54 8007A254 B037638C */  lw         $v1, %lo(D_800937B0)($v1)
    /* 6AA58 8007A258 0200A293 */  lbu        $v0, 0x2($sp)
    /* 6AA5C 8007A25C 00000000 */  nop
    /* 6AA60 8007A260 000062A0 */  sb         $v0, 0x0($v1)
    /* 6AA64 8007A264 0980033C */  lui        $v1, %hi(D_800937B4)
    /* 6AA68 8007A268 B437638C */  lw         $v1, %lo(D_800937B4)($v1)
    /* 6AA6C 8007A26C 0300A293 */  lbu        $v0, 0x3($sp)
    /* 6AA70 8007A270 00000000 */  nop
    /* 6AA74 8007A274 000062A0 */  sb         $v0, 0x0($v1)
    /* 6AA78 8007A278 0980033C */  lui        $v1, %hi(D_800937A8)
    /* 6AA7C 8007A27C A837638C */  lw         $v1, %lo(D_800937A8)($v1)
    /* 6AA80 8007A280 20000224 */  addiu      $v0, $zero, 0x20
    /* 6AA84 8007A284 000062A0 */  sb         $v0, 0x0($v1)
    /* 6AA88 8007A288 21100000 */  addu       $v0, $zero, $zero
    /* 6AA8C 8007A28C 0800E003 */  jr         $ra
    /* 6AA90 8007A290 0800BD27 */   addiu     $sp, $sp, 0x8
endlabel func_8007A1A4
