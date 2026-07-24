nonmatching func_80039AD4, 0x28

glabel func_80039AD4
    /* 2A2D4 80039AD4 0F80023C */  lui        $v0, %hi(D_800EAF08)
    /* 2A2D8 80039AD8 10008390 */  lbu        $v1, 0x10($a0)
    /* 2A2DC 80039ADC 08AF4224 */  addiu      $v0, $v0, %lo(D_800EAF08)
    /* 2A2E0 80039AE0 21186200 */  addu       $v1, $v1, $v0
    /* 2A2E4 80039AE4 01000224 */  addiu      $v0, $zero, 0x1
    /* 2A2E8 80039AE8 000060A0 */  sb         $zero, 0x0($v1)
    /* 2A2EC 80039AEC 110080A0 */  sb         $zero, 0x11($a0)
    /* 2A2F0 80039AF0 280482AF */  sw         $v0, %gp_rel(D_8009B330)($gp)
    /* 2A2F4 80039AF4 0800E003 */  jr         $ra
    /* 2A2F8 80039AF8 00000000 */   nop
endlabel func_80039AD4
