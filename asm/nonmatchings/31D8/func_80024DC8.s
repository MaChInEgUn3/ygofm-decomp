nonmatching func_80024DC8, 0x5C

glabel func_80024DC8
    /* 155C8 80024DC8 70720224 */  addiu      $v0, $zero, 0x7270
    /* 155CC 80024DCC 0A80013C */  lui        $at, %hi(D_8009B36A)
    /* 155D0 80024DD0 6AB322A4 */  sh         $v0, %lo(D_8009B36A)($at)
    /* 155D4 80024DD4 80720224 */  addiu      $v0, $zero, 0x7280
    /* 155D8 80024DD8 0A80013C */  lui        $at, %hi(D_8009B374)
    /* 155DC 80024DDC 74B322A4 */  sh         $v0, %lo(D_8009B374)($at)
    /* 155E0 80024DE0 03000224 */  addiu      $v0, $zero, 0x3
    /* 155E4 80024DE4 0A80013C */  lui        $at, %hi(D_8009B360)
    /* 155E8 80024DE8 60B324A0 */  sb         $a0, %lo(D_8009B360)($at)
    /* 155EC 80024DEC 0A80013C */  lui        $at, %hi(D_8009B361)
    /* 155F0 80024DF0 61B325A0 */  sb         $a1, %lo(D_8009B361)($at)
    /* 155F4 80024DF4 0A80013C */  lui        $at, %hi(D_8009B370)
    /* 155F8 80024DF8 70B326A4 */  sh         $a2, %lo(D_8009B370)($at)
    /* 155FC 80024DFC 0A80013C */  lui        $at, %hi(D_8009B372)
    /* 15600 80024E00 72B327A4 */  sh         $a3, %lo(D_8009B372)($at)
    /* 15604 80024E04 0A80013C */  lui        $at, %hi(D_8009B364)
    /* 15608 80024E08 64B320A0 */  sb         $zero, %lo(D_8009B364)($at)
    /* 1560C 80024E0C 0A80013C */  lui        $at, %hi(D_8009B369)
    /* 15610 80024E10 69B320A0 */  sb         $zero, %lo(D_8009B369)($at)
    /* 15614 80024E14 0A80013C */  lui        $at, %hi(D_8009B26C)
    /* 15618 80024E18 6CB222A0 */  sb         $v0, %lo(D_8009B26C)($at)
    /* 1561C 80024E1C 0800E003 */  jr         $ra
    /* 15620 80024E20 00000000 */   nop
endlabel func_80024DC8
