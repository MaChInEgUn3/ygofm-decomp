nonmatching func_80078270, 0x60

glabel func_80078270
    /* 68A70 80078270 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 68A74 80078274 0F80053C */  lui        $a1, %hi(D_800F5D7C)
    /* 68A78 80078278 7C5DA58C */  lw         $a1, %lo(D_800F5D7C)($a1)
    /* 68A7C 8007827C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 68A80 80078280 0F80013C */  lui        $at, %hi(D_800F5D64)
    /* 68A84 80078284 645D20AC */  sw         $zero, %lo(D_800F5D64)($at)
    /* 68A88 80078288 0F80013C */  lui        $at, %hi(D_800F5D60)
    /* 68A8C 8007828C 605D20AC */  sw         $zero, %lo(D_800F5D60)($at)
    /* 68A90 80078290 0F80013C */  lui        $at, %hi(D_800F5D5C)
    /* 68A94 80078294 5C5D20AC */  sw         $zero, %lo(D_800F5D5C)($at)
    /* 68A98 80078298 0F80013C */  lui        $at, %hi(D_800F5D54)
    /* 68A9C 8007829C 545D20AC */  sw         $zero, %lo(D_800F5D54)($at)
    /* 68AA0 800782A0 60E1010C */  jal        func_80078580
    /* 68AA4 800782A4 21200000 */   addu      $a0, $zero, $zero
    /* 68AA8 800782A8 0F80013C */  lui        $at, %hi(D_800F5D44)
    /* 68AAC 800782AC 445D20AC */  sw         $zero, %lo(D_800F5D44)($at)
    /* 68AB0 800782B0 0F80013C */  lui        $at, %hi(D_800F5D3C)
    /* 68AB4 800782B4 3C5D20A4 */  sh         $zero, %lo(D_800F5D3C)($at)
    /* 68AB8 800782B8 0F80013C */  lui        $at, %hi(D_800F5D38)
    /* 68ABC 800782BC 385D20AC */  sw         $zero, %lo(D_800F5D38)($at)
    /* 68AC0 800782C0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 68AC4 800782C4 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 68AC8 800782C8 0800E003 */  jr         $ra
    /* 68ACC 800782CC 00000000 */   nop
endlabel func_80078270
