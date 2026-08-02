nonmatching func_80030FD0, 0x30

glabel func_80030FD0
    /* 217D0 80030FD0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 217D4 80030FD4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 217D8 80030FD8 B656000C */  jal        func_80015AD8
    /* 217DC 80030FDC 00000000 */   nop
    /* 217E0 80030FE0 FC00010C */  jal        func_800403F0
    /* 217E4 80030FE4 00000000 */   nop
    /* 217E8 80030FE8 99D6000C */  jal        func_80035A64
    /* 217EC 80030FEC 00000000 */   nop
    /* 217F0 80030FF0 0F80043C */  lui        $a0, %hi(D_800E9DC0)
    /* 217F4 80030FF4 C09D8424 */  addiu      $a0, $a0, %lo(D_800E9DC0)
    /* 217F8 80030FF8 E33E020C */  jal        func_8008FB8C
    /* 217FC 80030FFC 02000524 */   addiu     $a1, $zero, 0x2
endlabel func_80030FD0
