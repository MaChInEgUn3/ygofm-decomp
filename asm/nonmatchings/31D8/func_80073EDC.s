nonmatching func_80073EDC, 0x78

glabel func_80073EDC
    /* 646DC 80073EDC E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 646E0 80073EE0 1400BFAF */  sw         $ra, 0x14($sp)
    /* 646E4 80073EE4 2CCE010C */  jal        func_800738B0
    /* 646E8 80073EE8 1000B0AF */   sw        $s0, 0x10($sp)
    /* 646EC 80073EEC 01000424 */  addiu      $a0, $zero, 0x1
    /* 646F0 80073EF0 0F80033C */  lui        $v1, %hi(D_800F5CF4)
    /* 646F4 80073EF4 F45C6324 */  addiu      $v1, $v1, %lo(D_800F5CF4)
    /* 646F8 80073EF8 FCFF7024 */  addiu      $s0, $v1, -0x4
    /* 646FC 80073EFC 0780023C */  lui        $v0, %hi(func_80073F54)
    /* 64700 80073F00 543F4224 */  addiu      $v0, $v0, %lo(func_80073F54)
    /* 64704 80073F04 000062AC */  sw         $v0, 0x0($v1)
    /* 64708 80073F08 0780023C */  lui        $v0, %hi(func_80073FBC)
    /* 6470C 80073F0C BC3F4224 */  addiu      $v0, $v0, %lo(func_80073FBC)
    /* 64710 80073F10 040062AC */  sw         $v0, 0x4($v1)
    /* 64714 80073F14 0F80013C */  lui        $at, %hi(D_800F5CF0)
    /* 64718 80073F18 F05C20AC */  sw         $zero, %lo(D_800F5CF0)($at)
    /* 6471C 80073F1C 0F80013C */  lui        $at, %hi(D_800F5CFC)
    /* 64720 80073F20 FC5C20AC */  sw         $zero, %lo(D_800F5CFC)($at)
    /* 64724 80073F24 10D0010C */  jal        func_80074040
    /* 64728 80073F28 21280002 */   addu      $a1, $s0, $zero
    /* 6472C 80073F2C 01000424 */  addiu      $a0, $zero, 0x1
    /* 64730 80073F30 0CD0010C */  jal        func_80074030
    /* 64734 80073F34 21280002 */   addu      $a1, $s0, $zero
    /* 64738 80073F38 30CE010C */  jal        func_800738C0
    /* 6473C 80073F3C 00000000 */   nop
    /* 64740 80073F40 01000224 */  addiu      $v0, $zero, 0x1
    /* 64744 80073F44 1400BF8F */  lw         $ra, 0x14($sp)
    /* 64748 80073F48 1000B08F */  lw         $s0, 0x10($sp)
    /* 6474C 80073F4C 0800E003 */  jr         $ra
    /* 64750 80073F50 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_80073EDC
