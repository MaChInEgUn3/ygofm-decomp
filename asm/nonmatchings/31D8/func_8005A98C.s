nonmatching func_8005A98C, 0x214

glabel func_8005A98C
    /* 4B18C 8005A98C F0FFBD27 */  addiu      $sp, $sp, -0x10
    /* 4B190 8005A990 21588000 */  addu       $t3, $a0, $zero
    /* 4B194 8005A994 21480000 */  addu       $t1, $zero, $zero
    /* 4B198 8005A998 21402001 */  addu       $t0, $t1, $zero
    /* 4B19C 8005A99C 2000AA93 */  lbu        $t2, 0x20($sp)
    /* 4B1A0 8005A9A0 01000424 */  addiu      $a0, $zero, 0x1
    /* 4B1A4 8005A9A4 0000A5A3 */  sb         $a1, 0x0($sp)
    /* 4B1A8 8005A9A8 0100A6A3 */  sb         $a2, 0x1($sp)
    /* 4B1AC 8005A9AC 0200A7A3 */  sb         $a3, 0x2($sp)
    /* 4B1B0 8005A9B0 2110A403 */  addu       $v0, $sp, $a0
  .L8005A9B4:
    /* 4B1B4 8005A9B4 2118A903 */  addu       $v1, $sp, $t1
    /* 4B1B8 8005A9B8 00004590 */  lbu        $a1, 0x0($v0)
    /* 4B1BC 8005A9BC 00006290 */  lbu        $v0, 0x0($v1)
    /* 4B1C0 8005A9C0 00000000 */  nop
    /* 4B1C4 8005A9C4 2B104500 */  sltu       $v0, $v0, $a1
    /* 4B1C8 8005A9C8 02004010 */  beqz       $v0, .L8005A9D4
    /* 4B1CC 8005A9CC 2110A803 */   addu      $v0, $sp, $t0
    /* 4B1D0 8005A9D0 21488000 */  addu       $t1, $a0, $zero
  .L8005A9D4:
    /* 4B1D4 8005A9D4 00004290 */  lbu        $v0, 0x0($v0)
    /* 4B1D8 8005A9D8 00000000 */  nop
    /* 4B1DC 8005A9DC 2B10A200 */  sltu       $v0, $a1, $v0
    /* 4B1E0 8005A9E0 02004010 */  beqz       $v0, .L8005A9EC
    /* 4B1E4 8005A9E4 00000000 */   nop
    /* 4B1E8 8005A9E8 21408000 */  addu       $t0, $a0, $zero
  .L8005A9EC:
    /* 4B1EC 8005A9EC 01008424 */  addiu      $a0, $a0, 0x1
    /* 4B1F0 8005A9F0 03008228 */  slti       $v0, $a0, 0x3
    /* 4B1F4 8005A9F4 EFFF4014 */  bnez       $v0, .L8005A9B4
    /* 4B1F8 8005A9F8 2110A403 */   addu      $v0, $sp, $a0
    /* 4B1FC 8005A9FC 2110A903 */  addu       $v0, $sp, $t1
    /* 4B200 8005AA00 2118A803 */  addu       $v1, $sp, $t0
    /* 4B204 8005AA04 00004590 */  lbu        $a1, 0x0($v0)
    /* 4B208 8005AA08 FF004231 */  andi       $v0, $t2, 0xFF
    /* 4B20C 8005AA0C 00006490 */  lbu        $a0, 0x0($v1)
    /* 4B210 8005AA10 40300200 */  sll        $a2, $v0, 1
    /* 4B214 8005AA14 2138A400 */  addu       $a3, $a1, $a0
    /* 4B218 8005AA18 001B0700 */  sll        $v1, $a3, 12
    /* 4B21C 8005AA1C 1A006600 */  div        $zero, $v1, $a2
    /* 4B220 8005AA20 0200C014 */  bnez       $a2, .L8005AA2C
    /* 4B224 8005AA24 00000000 */   nop
    /* 4B228 8005AA28 0D000700 */  break      7
  .L8005AA2C:
    /* 4B22C 8005AA2C FFFF0124 */  addiu      $at, $zero, -0x1
    /* 4B230 8005AA30 0400C114 */  bne        $a2, $at, .L8005AA44
    /* 4B234 8005AA34 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 4B238 8005AA38 02006114 */  bne        $v1, $at, .L8005AA44
    /* 4B23C 8005AA3C 00000000 */   nop
    /* 4B240 8005AA40 0D000600 */  break      6
  .L8005AA44:
    /* 4B244 8005AA44 12180000 */  mflo       $v1
    /* 4B248 8005AA48 0E00A0A7 */  sh         $zero, 0xE($sp)
    /* 4B24C 8005AA4C 0800A0AF */  sw         $zero, 0x8($sp)
    /* 4B250 8005AA50 2328A400 */  subu       $a1, $a1, $a0
    /* 4B254 8005AA54 4B00A010 */  beqz       $a1, .L8005AB84
    /* 4B258 8005AA58 0C00A3A7 */   sh        $v1, 0xC($sp)
    /* 4B25C 8005AA5C FFFF6230 */  andi       $v0, $v1, 0xFFFF
    /* 4B260 8005AA60 0108422C */  sltiu      $v0, $v0, 0x801
    /* 4B264 8005AA64 0E004010 */  beqz       $v0, .L8005AAA0
    /* 4B268 8005AA68 00130500 */   sll       $v0, $a1, 12
    /* 4B26C 8005AA6C 1A004700 */  div        $zero, $v0, $a3
    /* 4B270 8005AA70 0200E014 */  bnez       $a3, .L8005AA7C
    /* 4B274 8005AA74 00000000 */   nop
    /* 4B278 8005AA78 0D000700 */  break      7
  .L8005AA7C:
    /* 4B27C 8005AA7C FFFF0124 */  addiu      $at, $zero, -0x1
    /* 4B280 8005AA80 0400E114 */  bne        $a3, $at, .L8005AA94
    /* 4B284 8005AA84 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 4B288 8005AA88 02004114 */  bne        $v0, $at, .L8005AA94
    /* 4B28C 8005AA8C 00000000 */   nop
    /* 4B290 8005AA90 0D000600 */  break      6
  .L8005AA94:
    /* 4B294 8005AA94 12100000 */  mflo       $v0
    /* 4B298 8005AA98 B66A0108 */  j          .L8005AAD8
    /* 4B29C 8005AA9C 0E00A2A7 */   sh        $v0, 0xE($sp)
  .L8005AAA0:
    /* 4B2A0 8005AAA0 2318C700 */  subu       $v1, $a2, $a3
    /* 4B2A4 8005AAA4 1A004300 */  div        $zero, $v0, $v1
    /* 4B2A8 8005AAA8 02006014 */  bnez       $v1, .L8005AAB4
    /* 4B2AC 8005AAAC 00000000 */   nop
    /* 4B2B0 8005AAB0 0D000700 */  break      7
  .L8005AAB4:
    /* 4B2B4 8005AAB4 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 4B2B8 8005AAB8 04006114 */  bne        $v1, $at, .L8005AACC
    /* 4B2BC 8005AABC 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 4B2C0 8005AAC0 02004114 */  bne        $v0, $at, .L8005AACC
    /* 4B2C4 8005AAC4 00000000 */   nop
    /* 4B2C8 8005AAC8 0D000600 */  break      6
  .L8005AACC:
    /* 4B2CC 8005AACC 12100000 */  mflo       $v0
    /* 4B2D0 8005AAD0 00000000 */  nop
    /* 4B2D4 8005AAD4 0E00A2A7 */  sh         $v0, 0xE($sp)
  .L8005AAD8:
    /* 4B2D8 8005AAD8 5555023C */  lui        $v0, (0x55555556 >> 16)
    /* 4B2DC 8005AADC 56554234 */  ori        $v0, $v0, (0x55555556 & 0xFFFF)
    /* 4B2E0 8005AAE0 01002325 */  addiu      $v1, $t1, 0x1
    /* 4B2E4 8005AAE4 18006200 */  mult       $v1, $v0
    /* 4B2E8 8005AAE8 10400000 */  mfhi       $t0
    /* 4B2EC 8005AAEC 02002425 */  addiu      $a0, $t1, 0x2
    /* 4B2F0 8005AAF0 00000000 */  nop
    /* 4B2F4 8005AAF4 18008200 */  mult       $a0, $v0
    /* 4B2F8 8005AAF8 C3170300 */  sra        $v0, $v1, 31
    /* 4B2FC 8005AAFC 23300201 */  subu       $a2, $t0, $v0
    /* 4B300 8005AB00 40100600 */  sll        $v0, $a2, 1
    /* 4B304 8005AB04 21104600 */  addu       $v0, $v0, $a2
    /* 4B308 8005AB08 23306200 */  subu       $a2, $v1, $v0
    /* 4B30C 8005AB0C C3170400 */  sra        $v0, $a0, 31
    /* 4B310 8005AB10 10380000 */  mfhi       $a3
    /* 4B314 8005AB14 2318E200 */  subu       $v1, $a3, $v0
    /* 4B318 8005AB18 40100300 */  sll        $v0, $v1, 1
    /* 4B31C 8005AB1C 21104300 */  addu       $v0, $v0, $v1
    /* 4B320 8005AB20 23188200 */  subu       $v1, $a0, $v0
    /* 4B324 8005AB24 2110A603 */  addu       $v0, $sp, $a2
    /* 4B328 8005AB28 2118A303 */  addu       $v1, $sp, $v1
    /* 4B32C 8005AB2C 00004290 */  lbu        $v0, 0x0($v0)
    /* 4B330 8005AB30 00006390 */  lbu        $v1, 0x0($v1)
    /* 4B334 8005AB34 00000000 */  nop
    /* 4B338 8005AB38 23104300 */  subu       $v0, $v0, $v1
    /* 4B33C 8005AB3C 00130200 */  sll        $v0, $v0, 12
    /* 4B340 8005AB40 1A004500 */  div        $zero, $v0, $a1
    /* 4B344 8005AB44 0200A014 */  bnez       $a1, .L8005AB50
    /* 4B348 8005AB48 00000000 */   nop
    /* 4B34C 8005AB4C 0D000700 */  break      7
  .L8005AB50:
    /* 4B350 8005AB50 FFFF0124 */  addiu      $at, $zero, -0x1
    /* 4B354 8005AB54 0400A114 */  bne        $a1, $at, .L8005AB68
    /* 4B358 8005AB58 0080013C */   lui       $at, (0x80000000 >> 16)
    /* 4B35C 8005AB5C 02004114 */  bne        $v0, $at, .L8005AB68
    /* 4B360 8005AB60 00000000 */   nop
    /* 4B364 8005AB64 0D000600 */  break      6
  .L8005AB68:
    /* 4B368 8005AB68 12100000 */  mflo       $v0
    /* 4B36C 8005AB6C 401B0900 */  sll        $v1, $t1, 13
    /* 4B370 8005AB70 21106200 */  addu       $v0, $v1, $v0
    /* 4B374 8005AB74 03004104 */  bgez       $v0, .L8005AB84
    /* 4B378 8005AB78 0800A2AF */   sw        $v0, 0x8($sp)
    /* 4B37C 8005AB7C 00604224 */  addiu      $v0, $v0, 0x6000
    /* 4B380 8005AB80 0800A2AF */  sw         $v0, 0x8($sp)
  .L8005AB84:
    /* 4B384 8005AB84 0800AC8F */  lw         $t4, 0x8($sp)
    /* 4B388 8005AB88 0C00AD8F */  lw         $t5, 0xC($sp)
    /* 4B38C 8005AB8C 00006CAD */  sw         $t4, 0x0($t3)
    /* 4B390 8005AB90 04006DAD */  sw         $t5, 0x4($t3)
    /* 4B394 8005AB94 21106001 */  addu       $v0, $t3, $zero
    /* 4B398 8005AB98 0800E003 */  jr         $ra
    /* 4B39C 8005AB9C 1000BD27 */   addiu     $sp, $sp, 0x10
endlabel func_8005A98C
