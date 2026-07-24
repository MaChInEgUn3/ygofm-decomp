nonmatching func_80075B60, 0x74

glabel func_80075B60
    /* 66360 80075B60 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 66364 80075B64 0980033C */  lui        $v1, %hi(D_80092B78)
    /* 66368 80075B68 782B638C */  lw         $v1, %lo(D_80092B78)($v1)
    /* 6636C 80075B6C 01000224 */  addiu      $v0, $zero, 0x1
    /* 66370 80075B70 14006214 */  bne        $v1, $v0, .L80075BC4
    /* 66374 80075B74 1000BFAF */   sw        $ra, 0x10($sp)
    /* 66378 80075B78 0980013C */  lui        $at, %hi(D_80092B78)
    /* 6637C 80075B7C 2CCE010C */  jal        func_800738B0
    /* 66380 80075B80 782B20AC */   sw        $zero, %lo(D_80092B78)($at)
    /* 66384 80075B84 21200000 */  addu       $a0, $zero, $zero
    /* 66388 80075B88 0980013C */  lui        $at, %hi(D_80092BC0)
    /* 6638C 80075B8C C02B20AC */  sw         $zero, %lo(D_80092BC0)($at)
    /* 66390 80075B90 0980013C */  lui        $at, %hi(D_80092BC4)
    /* 66394 80075B94 CCD6010C */  jal        func_80075B30
    /* 66398 80075B98 C42B20AC */   sw        $zero, %lo(D_80092BC4)($at)
    /* 6639C 80075B9C 0980043C */  lui        $a0, %hi(D_80092B10)
    /* 663A0 80075BA0 102B848C */  lw         $a0, %lo(D_80092B10)($a0)
    /* 663A4 80075BA4 1CCE010C */  jal        func_80073870
    /* 663A8 80075BA8 00000000 */   nop
    /* 663AC 80075BAC 0980043C */  lui        $a0, %hi(D_80092B10)
    /* 663B0 80075BB0 102B848C */  lw         $a0, %lo(D_80092B10)($a0)
    /* 663B4 80075BB4 28CE010C */  jal        func_800738A0
    /* 663B8 80075BB8 00000000 */   nop
    /* 663BC 80075BBC 30CE010C */  jal        func_800738C0
    /* 663C0 80075BC0 00000000 */   nop
  .L80075BC4:
    /* 663C4 80075BC4 1000BF8F */  lw         $ra, 0x10($sp)
    /* 663C8 80075BC8 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 663CC 80075BCC 0800E003 */  jr         $ra
    /* 663D0 80075BD0 00000000 */   nop
endlabel func_80075B60
    /* 663D4 80075BD4 00000000 */  nop
    /* 663D8 80075BD8 00000000 */  nop
    /* 663DC 80075BDC 00000000 */  nop
