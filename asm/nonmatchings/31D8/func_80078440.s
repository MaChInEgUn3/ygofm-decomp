nonmatching func_80078440, 0x84

glabel func_80078440
    /* 68C40 80078440 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 68C44 80078444 1000B0AF */  sw         $s0, 0x10($sp)
    /* 68C48 80078448 21808000 */  addu       $s0, $a0, $zero
    /* 68C4C 8007844C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 68C50 80078450 2188E000 */  addu       $s1, $a3, $zero
    /* 68C54 80078454 1800B2AF */  sw         $s2, 0x18($sp)
    /* 68C58 80078458 3000B28F */  lw         $s2, 0x30($sp)
    /* 68C5C 8007845C 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 68C60 80078460 A0E1010C */  jal        func_80078680
    /* 68C64 80078464 01000424 */   addiu     $a0, $zero, 0x1
    /* 68C68 80078468 01001032 */  andi       $s0, $s0, 0x1
    /* 68C6C 8007846C 0F80013C */  lui        $at, %hi(D_800F5D68)
    /* 68C70 80078470 685D20AC */  sw         $zero, %lo(D_800F5D68)($at)
    /* 68C74 80078474 0F80013C */  lui        $at, %hi(D_800F5D90)
    /* 68C78 80078478 905D31AC */  sw         $s1, %lo(D_800F5D90)($at)
    /* 68C7C 8007847C 0F80013C */  lui        $at, %hi(D_800F5D40)
    /* 68C80 80078480 405D30AC */  sw         $s0, %lo(D_800F5D40)($at)
    /* 68C84 80078484 0F80013C */  lui        $at, %hi(D_800F5D50)
    /* 68C88 80078488 505D20AC */  sw         $zero, %lo(D_800F5D50)($at)
    /* 68C8C 8007848C 0F80013C */  lui        $at, %hi(D_800F5D48)
    /* 68C90 80078490 485D20AC */  sw         $zero, %lo(D_800F5D48)($at)
    /* 68C94 80078494 0F80013C */  lui        $at, %hi(D_800F5D3C)
    /* 68C98 80078498 3C5D20A4 */  sh         $zero, %lo(D_800F5D3C)($at)
    /* 68C9C 8007849C 0F80013C */  lui        $at, %hi(D_800F5D38)
    /* 68CA0 800784A0 385D20AC */  sw         $zero, %lo(D_800F5D38)($at)
    /* 68CA4 800784A4 0F80013C */  lui        $at, %hi(D_800F5D94)
    /* 68CA8 800784A8 945D32AC */  sw         $s2, %lo(D_800F5D94)($at)
    /* 68CAC 800784AC 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 68CB0 800784B0 1800B28F */  lw         $s2, 0x18($sp)
    /* 68CB4 800784B4 1400B18F */  lw         $s1, 0x14($sp)
    /* 68CB8 800784B8 1000B08F */  lw         $s0, 0x10($sp)
    /* 68CBC 800784BC 0800E003 */  jr         $ra
    /* 68CC0 800784C0 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_80078440
    /* 68CC4 800784C4 00000000 */  nop
    /* 68CC8 800784C8 00000000 */  nop
    /* 68CCC 800784CC 00000000 */  nop
