nonmatching func_80089D30, 0xA8

glabel func_80089D30
    /* 7A530 80089D30 21308000 */  addu       $a2, $a0, $zero
    /* 7A534 80089D34 1400C010 */  beqz       $a2, .L80089D88
    /* 7A538 80089D38 FF7F043C */   lui       $a0, (0x7FFFFFFF >> 16)
    /* 7A53C 80089D3C F8FFC28C */  lw         $v0, -0x8($a2)
    /* 7A540 80089D40 00000000 */  nop
    /* 7A544 80089D44 0800438C */  lw         $v1, 0x8($v0)
    /* 7A548 80089D48 1080013C */  lui        $at, %hi(D_800FE26C)
    /* 7A54C 80089D4C 6CE223AC */  sw         $v1, %lo(D_800FE26C)($at)
    /* 7A550 80089D50 0000628C */  lw         $v0, 0x0($v1)
    /* 7A554 80089D54 FFFF8434 */  ori        $a0, $a0, (0x7FFFFFFF & 0xFFFF)
    /* 7A558 80089D58 24104400 */  and        $v0, $v0, $a0
    /* 7A55C 80089D5C 1080013C */  lui        $at, %hi(D_800FE268)
    /* 7A560 80089D60 68E222AC */  sw         $v0, %lo(D_800FE268)($at)
    /* 7A564 80089D64 000062AC */  sw         $v0, 0x0($v1)
    /* 7A568 80089D68 1080033C */  lui        $v1, %hi(D_800FE26C)
    /* 7A56C 80089D6C 6CE2638C */  lw         $v1, %lo(D_800FE26C)($v1)
    /* 7A570 80089D70 00000000 */  nop
    /* 7A574 80089D74 04006324 */  addiu      $v1, $v1, 0x4
    /* 7A578 80089D78 1080013C */  lui        $at, %hi(D_800FE270)
    /* 7A57C 80089D7C 70E223AC */  sw         $v1, %lo(D_800FE270)($at)
    /* 7A580 80089D80 74270208 */  j          .L80089DD0
    /* 7A584 80089D84 2110C000 */   addu      $v0, $a2, $zero
  .L80089D88:
    /* 7A588 80089D88 1080063C */  lui        $a2, %hi(D_800FE268)
    /* 7A58C 80089D8C 68E2C68C */  lw         $a2, %lo(D_800FE268)($a2)
    /* 7A590 80089D90 00000000 */  nop
    /* 7A594 80089D94 0E00C010 */  beqz       $a2, .L80089DD0
    /* 7A598 80089D98 21100000 */   addu      $v0, $zero, $zero
    /* 7A59C 80089D9C 1080033C */  lui        $v1, %hi(D_800FE270)
    /* 7A5A0 80089DA0 70E2638C */  lw         $v1, %lo(D_800FE270)($v1)
    /* 7A5A4 80089DA4 00000000 */  nop
    /* 7A5A8 80089DA8 0400A3AC */  sw         $v1, 0x4($a1)
    /* 7A5AC 80089DAC 0400A28C */  lw         $v0, 0x4($a1)
    /* 7A5B0 80089DB0 0000648C */  lw         $a0, 0x0($v1)
    /* 7A5B4 80089DB4 04006324 */  addiu      $v1, $v1, 0x4
    /* 7A5B8 80089DB8 1080013C */  lui        $at, %hi(D_800FE270)
    /* 7A5BC 80089DBC 70E223AC */  sw         $v1, %lo(D_800FE270)($at)
    /* 7A5C0 80089DC0 FFFFC324 */  addiu      $v1, $a2, -0x1
    /* 7A5C4 80089DC4 1080013C */  lui        $at, %hi(D_800FE268)
    /* 7A5C8 80089DC8 68E223AC */  sw         $v1, %lo(D_800FE268)($at)
    /* 7A5CC 80089DCC 0000A4AC */  sw         $a0, 0x0($a1)
  .L80089DD0:
    /* 7A5D0 80089DD0 0800E003 */  jr         $ra
    /* 7A5D4 80089DD4 00000000 */   nop
endlabel func_80089D30
