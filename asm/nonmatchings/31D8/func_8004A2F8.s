nonmatching func_8004A2F8, 0xC4

glabel func_8004A2F8
    /* 3AAF8 8004A2F8 0A80063C */  lui        $a2, %hi(D_8009B458)
    /* 3AAFC 8004A2FC 58B4C68C */  lw         $a2, %lo(D_8009B458)($a2)
    /* 3AB00 8004A300 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 3AB04 8004A304 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 3AB08 8004A308 1800B2AF */  sw         $s2, 0x18($sp)
    /* 3AB0C 8004A30C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3AB10 8004A310 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3AB14 8004A314 1005C284 */  lh         $v0, 0x510($a2)
    /* 3AB18 8004A318 00000000 */  nop
    /* 3AB1C 8004A31C 21004018 */  blez       $v0, .L8004A3A4
    /* 3AB20 8004A320 21880000 */   addu      $s1, $zero, $zero
    /* 3AB24 8004A324 80011224 */  addiu      $s2, $zero, 0x180
    /* 3AB28 8004A328 21802002 */  addu       $s0, $s1, $zero
  .L8004A32C:
    /* 3AB2C 8004A32C 2118D000 */  addu       $v1, $a2, $s0
    /* 3AB30 8004A330 83016290 */  lbu        $v0, 0x183($v1)
    /* 3AB34 8004A334 00000000 */  nop
    /* 3AB38 8004A338 1000422C */  sltiu      $v0, $v0, 0x10
    /* 3AB3C 8004A33C 10004010 */  beqz       $v0, .L8004A380
    /* 3AB40 8004A340 00000000 */   nop
    /* 3AB44 8004A344 83016290 */  lbu        $v0, 0x183($v1)
    /* 3AB48 8004A348 2120D200 */  addu       $a0, $a2, $s2
    /* 3AB4C 8004A34C 40280200 */  sll        $a1, $v0, 1
    /* 3AB50 8004A350 2128A200 */  addu       $a1, $a1, $v0
    /* 3AB54 8004A354 C0280500 */  sll        $a1, $a1, 3
    /* 3AB58 8004A358 3F28010C */  jal        func_8004A0FC
    /* 3AB5C 8004A35C 2128C500 */   addu      $a1, $a2, $a1
    /* 3AB60 8004A360 0A80023C */  lui        $v0, %hi(D_8009B458)
    /* 3AB64 8004A364 58B4428C */  lw         $v0, %lo(D_8009B458)($v0)
    /* 3AB68 8004A368 00000000 */  nop
    /* 3AB6C 8004A36C 21105000 */  addu       $v0, $v0, $s0
    /* 3AB70 8004A370 94014594 */  lhu        $a1, 0x194($v0)
    /* 3AB74 8004A374 96014694 */  lhu        $a2, 0x196($v0)
    /* 3AB78 8004A378 9F28010C */  jal        func_8004A27C
    /* 3AB7C 8004A37C 21202002 */   addu      $a0, $s1, $zero
  .L8004A380:
    /* 3AB80 8004A380 28005226 */  addiu      $s2, $s2, 0x28
    /* 3AB84 8004A384 0A80063C */  lui        $a2, %hi(D_8009B458)
    /* 3AB88 8004A388 58B4C68C */  lw         $a2, %lo(D_8009B458)($a2)
    /* 3AB8C 8004A38C 00000000 */  nop
    /* 3AB90 8004A390 1005C284 */  lh         $v0, 0x510($a2)
    /* 3AB94 8004A394 01003126 */  addiu      $s1, $s1, 0x1
    /* 3AB98 8004A398 2A102202 */  slt        $v0, $s1, $v0
    /* 3AB9C 8004A39C E3FF4014 */  bnez       $v0, .L8004A32C
    /* 3ABA0 8004A3A0 28001026 */   addiu     $s0, $s0, 0x28
  .L8004A3A4:
    /* 3ABA4 8004A3A4 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 3ABA8 8004A3A8 1800B28F */  lw         $s2, 0x18($sp)
    /* 3ABAC 8004A3AC 1400B18F */  lw         $s1, 0x14($sp)
    /* 3ABB0 8004A3B0 1000B08F */  lw         $s0, 0x10($sp)
    /* 3ABB4 8004A3B4 0800E003 */  jr         $ra
    /* 3ABB8 8004A3B8 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8004A2F8
