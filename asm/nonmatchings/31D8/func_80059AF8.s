nonmatching func_80059AF8, 0x98

glabel func_80059AF8
    /* 4A2F8 80059AF8 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 4A2FC 80059AFC FF00083C */  lui        $t0, (0xFFFFFF >> 16)
    /* 4A300 80059B00 7F00A530 */  andi       $a1, $a1, 0x7F
    /* 4A304 80059B04 3000A28F */  lw         $v0, 0x30($sp)
    /* 4A308 80059B08 FFFF0835 */  ori        $t0, $t0, (0xFFFFFF & 0xFFFF)
    /* 4A30C 80059B0C 1800BFAF */  sw         $ra, 0x18($sp)
    /* 4A310 80059B10 2800A6AF */  sw         $a2, 0x28($sp)
    /* 4A314 80059B14 2C00A7AF */  sw         $a3, 0x2C($sp)
    /* 4A318 80059B18 2B00A5A3 */  sb         $a1, 0x2B($sp)
    /* 4A31C 80059B1C 1400A0AF */  sw         $zero, 0x14($sp)
    /* 4A320 80059B20 1000A2AF */  sw         $v0, 0x10($sp)
    /* 4A324 80059B24 2900A393 */  lbu        $v1, 0x29($sp)
    /* 4A328 80059B28 2800A693 */  lbu        $a2, 0x28($sp)
    /* 4A32C 80059B2C 2A00A293 */  lbu        $v0, 0x2A($sp)
    /* 4A330 80059B30 2C00A793 */  lbu        $a3, 0x2C($sp)
    /* 4A334 80059B34 001A0300 */  sll        $v1, $v1, 8
    /* 4A338 80059B38 2530C300 */  or         $a2, $a2, $v1
    /* 4A33C 80059B3C 00140200 */  sll        $v0, $v0, 16
    /* 4A340 80059B40 2530C200 */  or         $a2, $a2, $v0
    /* 4A344 80059B44 2D00A393 */  lbu        $v1, 0x2D($sp)
    /* 4A348 80059B48 2E00A293 */  lbu        $v0, 0x2E($sp)
    /* 4A34C 80059B4C 001A0300 */  sll        $v1, $v1, 8
    /* 4A350 80059B50 2538E300 */  or         $a3, $a3, $v1
    /* 4A354 80059B54 00140200 */  sll        $v0, $v0, 16
    /* 4A358 80059B58 2538E200 */  or         $a3, $a3, $v0
    /* 4A35C 80059B5C 2438E800 */  and        $a3, $a3, $t0
    /* 4A360 80059B60 FF00A230 */  andi       $v0, $a1, 0xFF
    /* 4A364 80059B64 00160200 */  sll        $v0, $v0, 24
    /* 4A368 80059B68 21280000 */  addu       $a1, $zero, $zero
    /* 4A36C 80059B6C 2F00A393 */  lbu        $v1, 0x2F($sp)
    /* 4A370 80059B70 2530C200 */  or         $a2, $a2, $v0
    /* 4A374 80059B74 001E0300 */  sll        $v1, $v1, 24
    /* 4A378 80059B78 4E62010C */  jal        func_80058938
    /* 4A37C 80059B7C 2538E300 */   or        $a3, $a3, $v1
    /* 4A380 80059B80 1800BF8F */  lw         $ra, 0x18($sp)
    /* 4A384 80059B84 00000000 */  nop
    /* 4A388 80059B88 0800E003 */  jr         $ra
    /* 4A38C 80059B8C 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80059AF8
