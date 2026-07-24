nonmatching func_8008D4AC, 0xB4

glabel func_8008D4AC
    /* 7DCAC 8008D4AC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7DCB0 8008D4B0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 7DCB4 8008D4B4 2CCE010C */  jal        func_800738B0
    /* 7DCB8 8008D4B8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 7DCBC 8008D4BC 1080043C */  lui        $a0, %hi(D_800FE3F8)
    /* 7DCC0 8008D4C0 F8E3848C */  lw         $a0, %lo(D_800FE3F8)($a0)
    /* 7DCC4 8008D4C4 1CCE010C */  jal        func_80073870
    /* 7DCC8 8008D4C8 21804000 */   addu      $s0, $v0, $zero
    /* 7DCCC 8008D4CC 1080043C */  lui        $a0, %hi(D_800FE3FC)
    /* 7DCD0 8008D4D0 FCE3848C */  lw         $a0, %lo(D_800FE3FC)($a0)
    /* 7DCD4 8008D4D4 1CCE010C */  jal        func_80073870
    /* 7DCD8 8008D4D8 00000000 */   nop
    /* 7DCDC 8008D4DC 1080043C */  lui        $a0, %hi(D_800FE400)
    /* 7DCE0 8008D4E0 00E4848C */  lw         $a0, %lo(D_800FE400)($a0)
    /* 7DCE4 8008D4E4 1CCE010C */  jal        func_80073870
    /* 7DCE8 8008D4E8 00000000 */   nop
    /* 7DCEC 8008D4EC 1080043C */  lui        $a0, %hi(D_800FE404)
    /* 7DCF0 8008D4F0 04E4848C */  lw         $a0, %lo(D_800FE404)($a0)
    /* 7DCF4 8008D4F4 1CCE010C */  jal        func_80073870
    /* 7DCF8 8008D4F8 00000000 */   nop
    /* 7DCFC 8008D4FC 1080043C */  lui        $a0, %hi(D_800FE408)
    /* 7DD00 8008D500 08E4848C */  lw         $a0, %lo(D_800FE408)($a0)
    /* 7DD04 8008D504 1CCE010C */  jal        func_80073870
    /* 7DD08 8008D508 00000000 */   nop
    /* 7DD0C 8008D50C 1080043C */  lui        $a0, %hi(D_800FE40C)
    /* 7DD10 8008D510 0CE4848C */  lw         $a0, %lo(D_800FE40C)($a0)
    /* 7DD14 8008D514 1CCE010C */  jal        func_80073870
    /* 7DD18 8008D518 00000000 */   nop
    /* 7DD1C 8008D51C 1080043C */  lui        $a0, %hi(D_800FE410)
    /* 7DD20 8008D520 10E4848C */  lw         $a0, %lo(D_800FE410)($a0)
    /* 7DD24 8008D524 1CCE010C */  jal        func_80073870
    /* 7DD28 8008D528 00000000 */   nop
    /* 7DD2C 8008D52C 1080043C */  lui        $a0, %hi(D_800FE414)
    /* 7DD30 8008D530 14E4848C */  lw         $a0, %lo(D_800FE414)($a0)
    /* 7DD34 8008D534 1CCE010C */  jal        func_80073870
    /* 7DD38 8008D538 00000000 */   nop
    /* 7DD3C 8008D53C 01000224 */  addiu      $v0, $zero, 0x1
    /* 7DD40 8008D540 03000216 */  bne        $s0, $v0, .L8008D550
    /* 7DD44 8008D544 00000000 */   nop
    /* 7DD48 8008D548 30CE010C */  jal        func_800738C0
    /* 7DD4C 8008D54C 00000000 */   nop
  .L8008D550:
    /* 7DD50 8008D550 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7DD54 8008D554 1000B08F */  lw         $s0, 0x10($sp)
    /* 7DD58 8008D558 0800E003 */  jr         $ra
    /* 7DD5C 8008D55C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008D4AC
