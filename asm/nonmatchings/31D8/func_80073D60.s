nonmatching func_80073D60, 0x1C

glabel func_80073D60
    /* 64560 80073D60 B0000A24 */  addiu      $t2, $zero, 0xB0
    /* 64564 80073D64 08004001 */  jr         $t2
    /* 64568 80073D68 42000924 */   addiu     $t1, $zero, 0x42
    /* 6456C 80073D6C 00000000 */  nop
    /* 64570 80073D70 0980013C */  lui        $at, %hi(D_80091978)
    /* 64574 80073D74 0800E003 */  jr         $ra
    /* 64578 80073D78 781924AC */   sw        $a0, %lo(D_80091978)($at)
endlabel func_80073D60
