nonmatching func_80089B20, 0xAC

glabel func_80089B20
    /* 7A320 80089B20 1080013C */  lui        $at, %hi(D_800FE258)
    /* 7A324 80089B24 58E23FAC */  sw         $ra, %lo(D_800FE258)($at)
    /* 7A328 80089B28 2CCE010C */  jal        func_800738B0
    /* 7A32C 80089B2C 00000000 */   nop
    /* 7A330 80089B30 56000924 */  addiu      $t1, $zero, 0x56
    /* 7A334 80089B34 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 7A338 80089B38 09F84001 */  jalr       $t2
    /* 7A33C 80089B3C 00000000 */   nop
    /* 7A340 80089B40 1800428C */  lw         $v0, 0x18($v0)
    /* 7A344 80089B44 00000000 */  nop
    /* 7A348 80089B48 28004224 */  addiu      $v0, $v0, 0x28
    /* 7A34C 80089B4C 21784000 */  addu       $t7, $v0, $zero
    /* 7A350 80089B50 09800A3C */  lui        $t2, %hi(func_80089BCC)
    /* 7A354 80089B54 CC9B4A25 */  addiu      $t2, $t2, %lo(func_80089BCC)
    /* 7A358 80089B58 0980093C */  lui        $t1, %hi(D_80089BE4)
    /* 7A35C 80089B5C E49B2925 */  addiu      $t1, $t1, %lo(D_80089BE4)
  .L80089B60:
    /* 7A360 80089B60 0000438D */  lw         $v1, 0x0($t2)
    /* 7A364 80089B64 00004B8C */  lw         $t3, 0x0($v0)
    /* 7A368 80089B68 04004A25 */  addiu      $t2, $t2, 0x4
    /* 7A36C 80089B6C 0E006B14 */  bne        $v1, $t3, .L80089BA8
    /* 7A370 80089B70 04004224 */   addiu     $v0, $v0, 0x4
    /* 7A374 80089B74 FAFF4915 */  bne        $t2, $t1, .L80089B60
    /* 7A378 80089B78 00000000 */   nop
    /* 7A37C 80089B7C 2110E001 */  addu       $v0, $t7, $zero
    /* 7A380 80089B80 09800A3C */  lui        $t2, %hi(D_80089BE4)
    /* 7A384 80089B84 E49B4A25 */  addiu      $t2, $t2, %lo(D_80089BE4)
    /* 7A388 80089B88 0980093C */  lui        $t1, %hi(D_80089BFC)
    /* 7A38C 80089B8C FC9B2925 */  addiu      $t1, $t1, %lo(D_80089BFC)
  .L80089B90:
    /* 7A390 80089B90 0000438D */  lw         $v1, 0x0($t2)
    /* 7A394 80089B94 00000000 */  nop
    /* 7A398 80089B98 000043AC */  sw         $v1, 0x0($v0)
    /* 7A39C 80089B9C 04004A25 */  addiu      $t2, $t2, 0x4
    /* 7A3A0 80089BA0 FBFF4915 */  bne        $t2, $t1, .L80089B90
    /* 7A3A4 80089BA4 04004224 */   addiu     $v0, $v0, 0x4
  .L80089BA8:
    /* 7A3A8 80089BA8 3CD0010C */  jal        func_800740F0
    /* 7A3AC 80089BAC 00000000 */   nop
    /* 7A3B0 80089BB0 30CE010C */  jal        func_800738C0
    /* 7A3B4 80089BB4 00000000 */   nop
    /* 7A3B8 80089BB8 10801F3C */  lui        $ra, %hi(D_800FE258)
    /* 7A3BC 80089BBC 58E2FF8F */  lw         $ra, %lo(D_800FE258)($ra)
    /* 7A3C0 80089BC0 00000000 */  nop
    /* 7A3C4 80089BC4 0800E003 */  jr         $ra
    /* 7A3C8 80089BC8 00000000 */   nop
endlabel func_80089B20
