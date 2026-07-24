nonmatching func_80084F60, 0x68

glabel func_80084F60
    /* 75760 80084F60 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 75764 80084F64 1080023C */  lui        $v0, %hi(D_800FE05C)
    /* 75768 80084F68 5CE04224 */  addiu      $v0, $v0, %lo(D_800FE05C)
    /* 7576C 80084F6C 2800A897 */  lhu        $t0, 0x28($sp)
    /* 75770 80084F70 1080033C */  lui        $v1, %hi(D_800FE0AC)
    /* 75774 80084F74 ACE06324 */  addiu      $v1, $v1, %lo(D_800FE0AC)
    /* 75778 80084F78 1000BFAF */  sw         $ra, 0x10($sp)
    /* 7577C 80084F7C 000040A4 */  sh         $zero, 0x0($v0)
    /* 75780 80084F80 020047A0 */  sb         $a3, 0x2($v0)
    /* 75784 80084F84 030040A0 */  sb         $zero, 0x3($v0)
    /* 75788 80084F88 040040A0 */  sb         $zero, 0x4($v0)
    /* 7578C 80084F8C 0100C230 */  andi       $v0, $a2, 0x1
    /* 75790 80084F90 0400C630 */  andi       $a2, $a2, 0x4
    /* 75794 80084F94 000064A4 */  sh         $a0, 0x0($v1)
    /* 75798 80084F98 FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 7579C 80084F9C 020065A4 */  sh         $a1, 0x2($v1)
    /* 757A0 80084FA0 FFFFA530 */  andi       $a1, $a1, 0xFFFF
    /* 757A4 80084FA4 0C0062A0 */  sb         $v0, 0xC($v1)
    /* 757A8 80084FA8 1080013C */  lui        $at, %hi(D_800FE0CE)
    /* 757AC 80084FAC CEE026A4 */  sh         $a2, %lo(D_800FE0CE)($at)
    /* 757B0 80084FB0 F213020C */  jal        func_80084FC8
    /* 757B4 80084FB4 0D0068A0 */   sb        $t0, 0xD($v1)
    /* 757B8 80084FB8 1000BF8F */  lw         $ra, 0x10($sp)
    /* 757BC 80084FBC 1800BD27 */  addiu      $sp, $sp, 0x18
    /* 757C0 80084FC0 0800E003 */  jr         $ra
    /* 757C4 80084FC4 00000000 */   nop
endlabel func_80084F60
