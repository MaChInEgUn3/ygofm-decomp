nonmatching func_800860B0, 0x4C

glabel func_800860B0
    /* 768B0 800860B0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 768B4 800860B4 1000BFAF */  sw         $ra, 0x10($sp)
    /* 768B8 800860B8 721B020C */  jal        func_80086DC8
    /* 768BC 800860BC 00000000 */   nop
    /* 768C0 800860C0 21200000 */  addu       $a0, $zero, $zero
    /* 768C4 800860C4 21280000 */  addu       $a1, $zero, $zero
    /* 768C8 800860C8 241E020C */  jal        func_80087890
    /* 768CC 800860CC 21300000 */   addu      $a2, $zero, $zero
    /* 768D0 800860D0 21200000 */  addu       $a0, $zero, $zero
    /* 768D4 800860D4 2C1E020C */  jal        func_800878B0
    /* 768D8 800860D8 21280000 */   addu      $a1, $zero, $zero
    /* 768DC 800860DC 1080013C */  lui        $at, %hi(D_800FE0BE)
    /* 768E0 800860E0 BEE020A4 */  sh         $zero, %lo(D_800FE0BE)($at)
    /* 768E4 800860E4 1080013C */  lui        $at, %hi(D_800FE0BC)
    /* 768E8 800860E8 BCE020A4 */  sh         $zero, %lo(D_800FE0BC)($at)
    /* 768EC 800860EC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 768F0 800860F0 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 768F4 800860F4 0800E003 */  jr         $ra
    /* 768F8 800860F8 00000000 */   nop
endlabel func_800860B0
    /* 768FC 800860FC 00000000 */  nop
