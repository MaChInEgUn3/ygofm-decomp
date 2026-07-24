nonmatching func_80074BC0, 0x4C

glabel func_80074BC0
    /* 653C0 80074BC0 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 653C4 80074BC4 0980043C */  lui        $a0, %hi(D_80092ADC)
    /* 653C8 80074BC8 DC2A8424 */  addiu      $a0, $a0, %lo(D_80092ADC)
    /* 653CC 80074BCC 1000BFAF */  sw         $ra, 0x10($sp)
    /* 653D0 80074BD0 8ED3010C */  jal        func_80074E38
    /* 653D4 80074BD4 08000524 */   addiu     $a1, $zero, 0x8
    /* 653D8 80074BD8 03000424 */  addiu      $a0, $zero, 0x3
    /* 653DC 80074BDC 0980023C */  lui        $v0, %hi(D_80092AD8)
    /* 653E0 80074BE0 D82A428C */  lw         $v0, %lo(D_80092AD8)($v0)
    /* 653E4 80074BE4 0780053C */  lui        $a1, %hi(func_80074C0C)
    /* 653E8 80074BE8 0C4CA524 */  addiu      $a1, $a1, %lo(func_80074C0C)
    /* 653EC 80074BEC F0D0010C */  jal        func_800743C0
    /* 653F0 80074BF0 000040AC */   sw        $zero, 0x0($v0)
    /* 653F4 80074BF4 0780023C */  lui        $v0, %hi(func_80074D8C)
    /* 653F8 80074BF8 8C4D4224 */  addiu      $v0, $v0, %lo(func_80074D8C)
    /* 653FC 80074BFC 1000BF8F */  lw         $ra, 0x10($sp)
    /* 65400 80074C00 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 65404 80074C04 0800E003 */  jr         $ra
    /* 65408 80074C08 00000000 */   nop
endlabel func_80074BC0
