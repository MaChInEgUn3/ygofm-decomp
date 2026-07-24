nonmatching func_8002A9C0, 0x1F4

glabel func_8002A9C0
    /* 1B1C0 8002A9C0 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 1B1C4 8002A9C4 3C00B3AF */  sw         $s3, 0x3C($sp)
    /* 1B1C8 8002A9C8 21988000 */  addu       $s3, $a0, $zero
    /* 1B1CC 8002A9CC 4400BFAF */  sw         $ra, 0x44($sp)
    /* 1B1D0 8002A9D0 4000B4AF */  sw         $s4, 0x40($sp)
    /* 1B1D4 8002A9D4 3800B2AF */  sw         $s2, 0x38($sp)
    /* 1B1D8 8002A9D8 3400B1AF */  sw         $s1, 0x34($sp)
    /* 1B1DC 8002A9DC 3000B0AF */  sw         $s0, 0x30($sp)
    /* 1B1E0 8002A9E0 60006296 */  lhu        $v0, 0x60($s3)
    /* 1B1E4 8002A9E4 00000000 */  nop
    /* 1B1E8 8002A9E8 F0FF4224 */  addiu      $v0, $v0, -0x10
    /* 1B1EC 8002A9EC 600062A6 */  sh         $v0, 0x60($s3)
    /* 1B1F0 8002A9F0 00140200 */  sll        $v0, $v0, 16
    /* 1B1F4 8002A9F4 0500401C */  bgtz       $v0, .L8002AA0C
    /* 1B1F8 8002A9F8 21A0A000 */   addu      $s4, $a1, $zero
    /* 1B1FC 8002A9FC DB00010C */  jal        func_8004036C
    /* 1B200 8002AA00 00000000 */   nop
    /* 1B204 8002AA04 E5AA0008 */  j          .L8002AB94
    /* 1B208 8002AA08 00000000 */   nop
  .L8002AA0C:
    /* 1B20C 8002AA0C 801F113C */  lui        $s1, (0x1F800398 >> 16)
    /* 1B210 8002AA10 98033136 */  ori        $s1, $s1, (0x1F800398 & 0xFFFF)
    /* 1B214 8002AA14 21206002 */  addu       $a0, $s3, $zero
    /* 1B218 8002AA18 801F073C */  lui        $a3, (0x1F800398 >> 16)
    /* 1B21C 8002AA1C 9803E734 */  ori        $a3, $a3, (0x1F800398 & 0xFFFF)
    /* 1B220 8002AA20 801F103C */  lui        $s0, (0x1F8002A0 >> 16)
    /* 1B224 8002AA24 A0021036 */  ori        $s0, $s0, (0x1F8002A0 & 0xFFFF)
    /* 1B228 8002AA28 30006286 */  lh         $v0, 0x30($s3)
    /* 1B22C 8002AA2C 18006586 */  lh         $a1, 0x18($s3)
    /* 1B230 8002AA30 32006386 */  lh         $v1, 0x32($s3)
    /* 1B234 8002AA34 1A006686 */  lh         $a2, 0x1A($s3)
    /* 1B238 8002AA38 21284500 */  addu       $a1, $v0, $a1
    /* 1B23C 8002AA3C 60006292 */  lbu        $v0, 0x60($s3)
    /* 1B240 8002AA40 21306600 */  addu       $a2, $v1, $a2
    /* 1B244 8002AA44 E407010C */  jal        func_80041F90
    /* 1B248 8002AA48 0E0062A2 */   sb        $v0, 0xE($s3)
    /* 1B24C 8002AA4C 801F083C */  lui        $t0, (0x1F800300 >> 16)
    /* 1B250 8002AA50 00030835 */  ori        $t0, $t0, (0x1F800300 & 0xFFFF)
    /* 1B254 8002AA54 5555063C */  lui        $a2, (0x55555555 >> 16)
    /* 1B258 8002AA58 5555C634 */  ori        $a2, $a2, (0x55555555 & 0xFFFF)
    /* 1B25C 8002AA5C 801F0C3C */  lui        $t4, (0x1F800310 >> 16)
    /* 1B260 8002AA60 10038C35 */  ori        $t4, $t4, (0x1F800310 & 0xFFFF)
    /* 1B264 8002AA64 801F093C */  lui        $t1, (0x1F800318 >> 16)
    /* 1B268 8002AA68 18032935 */  ori        $t1, $t1, (0x1F800318 & 0xFFFF)
    /* 1B26C 8002AA6C 801F0B3C */  lui        $t3, (0x1F800308 >> 16)
    /* 1B270 8002AA70 08036B35 */  ori        $t3, $t3, (0x1F800308 & 0xFFFF)
    /* 1B274 8002AA74 801F123C */  lui        $s2, (0x1F8002A8 >> 16)
    /* 1B278 8002AA78 A8025236 */  ori        $s2, $s2, (0x1F8002A8 & 0xFFFF)
    /* 1B27C 8002AA7C 801F0F3C */  lui        $t7, (0x1F8002AC >> 16)
    /* 1B280 8002AA80 AC02EF35 */  ori        $t7, $t7, (0x1F8002AC & 0xFFFF)
    /* 1B284 8002AA84 801F0E3C */  lui        $t6, (0x1F8002B4 >> 16)
    /* 1B288 8002AA88 B402CE35 */  ori        $t6, $t6, (0x1F8002B4 & 0xFFFF)
    /* 1B28C 8002AA8C 801F0D3C */  lui        $t5, (0x1F8002B0 >> 16)
    /* 1B290 8002AA90 B002AD35 */  ori        $t5, $t5, (0x1F8002B0 & 0xFFFF)
    /* 1B294 8002AA94 801F043C */  lui        $a0, (0x1F800300 >> 16)
    /* 1B298 8002AA98 00038434 */  ori        $a0, $a0, (0x1F800300 & 0xFFFF)
    /* 1B29C 8002AA9C 801F053C */  lui        $a1, (0x1F800308 >> 16)
    /* 1B2A0 8002AAA0 0803A534 */  ori        $a1, $a1, (0x1F800308 & 0xFFFF)
    /* 1B2A4 8002AAA4 0C00638E */  lw         $v1, 0xC($s3)
    /* 1B2A8 8002AAA8 06000224 */  addiu      $v0, $zero, 0x6
    /* 1B2AC 8002AAAC 030002A2 */  sb         $v0, 0x3($s0)
    /* 1B2B0 8002AAB0 4C000224 */  addiu      $v0, $zero, 0x4C
    /* 1B2B4 8002AAB4 180006AE */  sw         $a2, 0x18($s0)
    /* 1B2B8 8002AAB8 801F063C */  lui        $a2, (0x1F800310 >> 16)
    /* 1B2BC 8002AABC 040003AE */  sw         $v1, 0x4($s0)
    /* 1B2C0 8002AAC0 070002A2 */  sb         $v0, 0x7($s0)
    /* 1B2C4 8002AAC4 30006296 */  lhu        $v0, 0x30($s3)
    /* 1B2C8 8002AAC8 00002396 */  lhu        $v1, 0x0($s1)
    /* 1B2CC 8002AACC 1003C634 */  ori        $a2, $a2, (0x1F800310 & 0xFFFF)
    /* 1B2D0 8002AAD0 23104300 */  subu       $v0, $v0, $v1
    /* 1B2D4 8002AAD4 000082A5 */  sh         $v0, 0x0($t4)
    /* 1B2D8 8002AAD8 000002A5 */  sh         $v0, 0x0($t0)
    /* 1B2DC 8002AADC 3C006396 */  lhu        $v1, 0x3C($s3)
    /* 1B2E0 8002AAE0 801F073C */  lui        $a3, (0x1F800318 >> 16)
    /* 1B2E4 8002AAE4 21104300 */  addu       $v0, $v0, $v1
    /* 1B2E8 8002AAE8 000022A5 */  sh         $v0, 0x0($t1)
    /* 1B2EC 8002AAEC 080002A5 */  sh         $v0, 0x8($t0)
    /* 1B2F0 8002AAF0 32006396 */  lhu        $v1, 0x32($s3)
    /* 1B2F4 8002AAF4 02002296 */  lhu        $v0, 0x2($s1)
    /* 1B2F8 8002AAF8 1803E734 */  ori        $a3, $a3, (0x1F800318 & 0xFFFF)
    /* 1B2FC 8002AAFC 23186200 */  subu       $v1, $v1, $v0
    /* 1B300 8002AB00 020063A5 */  sh         $v1, 0x2($t3)
    /* 1B304 8002AB04 020003A5 */  sh         $v1, 0x2($t0)
    /* 1B308 8002AB08 3E006A96 */  lhu        $t2, 0x3E($s3)
    /* 1B30C 8002AB0C 2800A227 */  addiu      $v0, $sp, 0x28
    /* 1B310 8002AB10 040020A5 */  sh         $zero, 0x4($t1)
    /* 1B314 8002AB14 040080A5 */  sh         $zero, 0x4($t4)
    /* 1B318 8002AB18 040060A5 */  sh         $zero, 0x4($t3)
    /* 1B31C 8002AB1C 040000A5 */  sh         $zero, 0x4($t0)
    /* 1B320 8002AB20 2000A2AF */  sw         $v0, 0x20($sp)
    /* 1B324 8002AB24 2C00A227 */  addiu      $v0, $sp, 0x2C
    /* 1B328 8002AB28 1000B2AF */  sw         $s2, 0x10($sp)
    /* 1B32C 8002AB2C 1400AFAF */  sw         $t7, 0x14($sp)
    /* 1B330 8002AB30 1800AEAF */  sw         $t6, 0x18($sp)
    /* 1B334 8002AB34 1C00ADAF */  sw         $t5, 0x1C($sp)
    /* 1B338 8002AB38 2400A2AF */  sw         $v0, 0x24($sp)
    /* 1B33C 8002AB3C 21186A00 */  addu       $v1, $v1, $t2
    /* 1B340 8002AB40 020023A5 */  sh         $v1, 0x2($t1)
    /* 1B344 8002AB44 AC1E020C */  jal        func_80087AB0
    /* 1B348 8002AB48 120003A5 */   sh        $v1, 0x12($t0)
    /* 1B34C 8002AB4C 801F043C */  lui        $a0, (0x1F8002A0 >> 16)
    /* 1B350 8002AB50 A0028434 */  ori        $a0, $a0, (0x1F8002A0 & 0xFFFF)
    /* 1B354 8002AB54 21288002 */  addu       $a1, $s4, $zero
    /* 1B358 8002AB58 14006696 */  lhu        $a2, 0x14($s3)
    /* 1B35C 8002AB5C 986C010C */  jal        func_8005B260
    /* 1B360 8002AB60 01000724 */   addiu     $a3, $zero, 0x1
    /* 1B364 8002AB64 801F043C */  lui        $a0, (0x1F8002A0 >> 16)
    /* 1B368 8002AB68 A0028434 */  ori        $a0, $a0, (0x1F8002A0 & 0xFFFF)
    /* 1B36C 8002AB6C 21288002 */  addu       $a1, $s4, $zero
    /* 1B370 8002AB70 03000224 */  addiu      $v0, $zero, 0x3
    /* 1B374 8002AB74 030002A2 */  sb         $v0, 0x3($s0)
    /* 1B378 8002AB78 40000224 */  addiu      $v0, $zero, 0x40
    /* 1B37C 8002AB7C 070002A2 */  sb         $v0, 0x7($s0)
    /* 1B380 8002AB80 14006696 */  lhu        $a2, 0x14($s3)
    /* 1B384 8002AB84 1400028E */  lw         $v0, 0x14($s0)
    /* 1B388 8002AB88 01000724 */  addiu      $a3, $zero, 0x1
    /* 1B38C 8002AB8C 986C010C */  jal        func_8005B260
    /* 1B390 8002AB90 0C0002AE */   sw        $v0, 0xC($s0)
  .L8002AB94:
    /* 1B394 8002AB94 4400BF8F */  lw         $ra, 0x44($sp)
    /* 1B398 8002AB98 4000B48F */  lw         $s4, 0x40($sp)
    /* 1B39C 8002AB9C 3C00B38F */  lw         $s3, 0x3C($sp)
    /* 1B3A0 8002ABA0 3800B28F */  lw         $s2, 0x38($sp)
    /* 1B3A4 8002ABA4 3400B18F */  lw         $s1, 0x34($sp)
    /* 1B3A8 8002ABA8 3000B08F */  lw         $s0, 0x30($sp)
    /* 1B3AC 8002ABAC 0800E003 */  jr         $ra
    /* 1B3B0 8002ABB0 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_8002A9C0
