nonmatching func_80074B90, 0x24

glabel func_80074B90
    /* 65390 80074B90 0600A010 */  beqz       $a1, .L80074BAC
    /* 65394 80074B94 FFFFA224 */   addiu     $v0, $a1, -0x1
    /* 65398 80074B98 FFFF0324 */  addiu      $v1, $zero, -0x1
  .L80074B9C:
    /* 6539C 80074B9C 000080AC */  sw         $zero, 0x0($a0)
    /* 653A0 80074BA0 FFFF4224 */  addiu      $v0, $v0, -0x1
    /* 653A4 80074BA4 FDFF4314 */  bne        $v0, $v1, .L80074B9C
    /* 653A8 80074BA8 04008424 */   addiu     $a0, $a0, 0x4
  .L80074BAC:
    /* 653AC 80074BAC 0800E003 */  jr         $ra
    /* 653B0 80074BB0 00000000 */   nop
endlabel func_80074B90
    /* 653B4 80074BB4 00000000 */  nop
    /* 653B8 80074BB8 00000000 */  nop
    /* 653BC 80074BBC 00000000 */  nop
