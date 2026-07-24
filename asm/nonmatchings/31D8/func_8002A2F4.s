nonmatching func_8002A2F4, 0xD8

glabel func_8002A2F4
    /* 1AAF4 8002A2F4 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1AAF8 8002A2F8 2000B2AF */  sw         $s2, 0x20($sp)
    /* 1AAFC 8002A2FC 21908000 */  addu       $s2, $a0, $zero
    /* 1AB00 8002A300 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 1AB04 8002A304 21880000 */  addu       $s1, $zero, $zero
    /* 1AB08 8002A308 2400BFAF */  sw         $ra, 0x24($sp)
    /* 1AB0C 8002A30C AEA9000C */  jal        func_8002A6B8
    /* 1AB10 8002A310 1800B0AF */   sw        $s0, 0x18($sp)
    /* 1AB14 8002A314 1D80033C */  lui        $v1, %hi(D_801D5608)
    /* 1AB18 8002A318 0A80013C */  lui        $at, %hi(D_8009B338)
    /* 1AB1C 8002A31C 38B322A4 */  sh         $v0, %lo(D_8009B338)($at)
    /* 1AB20 8002A320 00140200 */  sll        $v0, $v0, 16
    /* 1AB24 8002A324 03140200 */  sra        $v0, $v0, 16
    /* 1AB28 8002A328 21804000 */  addu       $s0, $v0, $zero
    /* 1AB2C 8002A32C 09000012 */  beqz       $s0, .L8002A354
    /* 1AB30 8002A330 085662AC */   sw        $v0, %lo(D_801D5608)($v1)
    /* 1AB34 8002A334 21204002 */  addu       $a0, $s2, $zero
    /* 1AB38 8002A338 ACA7000C */  jal        func_80029EB0
    /* 1AB3C 8002A33C 21280002 */   addu      $a1, $s0, $zero
    /* 1AB40 8002A340 80004230 */  andi       $v0, $v0, 0x80
    /* 1AB44 8002A344 03004014 */  bnez       $v0, .L8002A354
    /* 1AB48 8002A348 05001124 */   addiu     $s1, $zero, 0x5
    /* 1AB4C 8002A34C 0A80013C */  lui        $at, %hi(D_8009B338)
    /* 1AB50 8002A350 38B320A4 */  sh         $zero, %lo(D_8009B338)($at)
  .L8002A354:
    /* 1AB54 8002A354 01000424 */  addiu      $a0, $zero, 0x1
    /* 1AB58 8002A358 21282002 */  addu       $a1, $s1, $zero
    /* 1AB5C 8002A35C 20010224 */  addiu      $v0, $zero, 0x120
    /* 1AB60 8002A360 1000A2AF */  sw         $v0, 0x10($sp)
    /* 1AB64 8002A364 30000224 */  addiu      $v0, $zero, 0x30
    /* 1AB68 8002A368 10000624 */  addiu      $a2, $zero, 0x10
    /* 1AB6C 8002A36C CA000724 */  addiu      $a3, $zero, 0xCA
    /* 1AB70 8002A370 F9D6000C */  jal        func_80035BE4
    /* 1AB74 8002A374 1400A2AF */   sw        $v0, 0x14($sp)
    /* 1AB78 8002A378 54004290 */  lbu        $v0, 0x54($v0)
    /* 1AB7C 8002A37C 0A80013C */  lui        $at, %hi(D_8009B320)
    /* 1AB80 8002A380 20B322A0 */  sb         $v0, %lo(D_8009B320)($at)
    /* 1AB84 8002A384 80101000 */  sll        $v0, $s0, 2
    /* 1AB88 8002A388 21104202 */  addu       $v0, $s2, $v0
    /* 1AB8C 8002A38C 56004290 */  lbu        $v0, 0x56($v0)
    /* 1AB90 8002A390 00000000 */  nop
    /* 1AB94 8002A394 01004230 */  andi       $v0, $v0, 0x1
    /* 1AB98 8002A398 03004010 */  beqz       $v0, .L8002A3A8
    /* 1AB9C 8002A39C 04000224 */   addiu     $v0, $zero, 0x4
    /* 1ABA0 8002A3A0 0A80013C */  lui        $at, %hi(D_8009B320)
    /* 1ABA4 8002A3A4 20B322A0 */  sb         $v0, %lo(D_8009B320)($at)
  .L8002A3A8:
    /* 1ABA8 8002A3A8 0F80043C */  lui        $a0, %hi(D_800EB15C)
    /* 1ABAC 8002A3AC 98E6000C */  jal        func_80039A60
    /* 1ABB0 8002A3B0 5CB18424 */   addiu     $a0, $a0, %lo(D_800EB15C)
    /* 1ABB4 8002A3B4 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1ABB8 8002A3B8 2000B28F */  lw         $s2, 0x20($sp)
    /* 1ABBC 8002A3BC 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 1ABC0 8002A3C0 1800B08F */  lw         $s0, 0x18($sp)
    /* 1ABC4 8002A3C4 0800E003 */  jr         $ra
    /* 1ABC8 8002A3C8 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8002A2F4
