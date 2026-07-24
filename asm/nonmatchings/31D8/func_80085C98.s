nonmatching func_80085C98, 0x64

glabel func_80085C98
    /* 76498 80085C98 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7649C 80085C9C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 764A0 80085CA0 1080063C */  lui        $a2, %hi(D_800FE108)
    /* 764A4 80085CA4 08E1C624 */  addiu      $a2, $a2, %lo(D_800FE108)
    /* 764A8 80085CA8 0000828C */  lw         $v0, 0x0($a0)
    /* 764AC 80085CAC 0400838C */  lw         $v1, 0x4($a0)
    /* 764B0 80085CB0 0800858C */  lw         $a1, 0x8($a0)
    /* 764B4 80085CB4 0000C2AC */  sw         $v0, 0x0($a2)
    /* 764B8 80085CB8 0400C3AC */  sw         $v1, 0x4($a2)
    /* 764BC 80085CBC 0800C5AC */  sw         $a1, 0x8($a2)
    /* 764C0 80085CC0 0C00828C */  lw         $v0, 0xC($a0)
    /* 764C4 80085CC4 1000838C */  lw         $v1, 0x10($a0)
    /* 764C8 80085CC8 1400858C */  lw         $a1, 0x14($a0)
    /* 764CC 80085CCC 0C00C2AC */  sw         $v0, 0xC($a2)
    /* 764D0 80085CD0 1000C3AC */  sw         $v1, 0x10($a2)
    /* 764D4 80085CD4 1400C5AC */  sw         $a1, 0x14($a2)
    /* 764D8 80085CD8 1800828C */  lw         $v0, 0x18($a0)
    /* 764DC 80085CDC 1C00838C */  lw         $v1, 0x1C($a0)
    /* 764E0 80085CE0 1800C2AC */  sw         $v0, 0x18($a2)
    /* 764E4 80085CE4 041E020C */  jal        func_80087810
    /* 764E8 80085CE8 1C00C3AC */   sw        $v1, 0x1C($a2)
    /* 764EC 80085CEC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 764F0 80085CF0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 764F4 80085CF4 0800E003 */  jr         $ra
    /* 764F8 80085CF8 00000000 */   nop
endlabel func_80085C98
