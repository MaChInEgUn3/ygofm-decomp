nonmatching func_8002FA28, 0x2C

glabel func_8002FA28
    /* 20228 8002FA28 01000224 */  addiu      $v0, $zero, 0x1
    /* 2022C 8002FA2C 0A80013C */  lui        $at, %hi(D_8009B268)
    /* 20230 8002FA30 68B222A0 */  sb         $v0, %lo(D_8009B268)($at)
    /* 20234 8002FA34 05000224 */  addiu      $v0, $zero, 0x5
    /* 20238 8002FA38 0A80013C */  lui        $at, %hi(D_8009B26D)
    /* 2023C 8002FA3C 6DB222A0 */  sb         $v0, %lo(D_8009B26D)($at)
    /* 20240 8002FA40 08000224 */  addiu      $v0, $zero, 0x8
    /* 20244 8002FA44 0A80013C */  lui        $at, %hi(D_8009B26C)
    /* 20248 8002FA48 6CB222A0 */  sb         $v0, %lo(D_8009B26C)($at)
    /* 2024C 8002FA4C 0800E003 */  jr         $ra
    /* 20250 8002FA50 00000000 */   nop
endlabel func_8002FA28
