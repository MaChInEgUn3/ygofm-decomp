nonmatching func_8005C768, 0x54

glabel func_8005C768
    /* 4CF68 8005C768 FFFF023C */  lui        $v0, (0xFFFF0000 >> 16)
    /* 4CF6C 8005C76C 24108200 */  and        $v0, $a0, $v0
    /* 4CF70 8005C770 0003033C */  lui        $v1, (0x3000000 >> 16)
    /* 4CF74 8005C774 0F004314 */  bne        $v0, $v1, .L8005C7B4
    /* 4CF78 8005C778 0980023C */   lui       $v0, %hi(func_80089E20)
    /* 4CF7C 8005C77C FFFF8430 */  andi       $a0, $a0, 0xFFFF
    /* 4CF80 8005C780 19200224 */  addiu      $v0, $zero, 0x2019
    /* 4CF84 8005C784 06008210 */  beq        $a0, $v0, .L8005C7A0
    /* 4CF88 8005C788 0680023C */   lui       $v0, %hi(func_8005CEF0)
    /* 4CF8C 8005C78C 19210224 */  addiu      $v0, $zero, 0x2119
    /* 4CF90 8005C790 05008210 */  beq        $a0, $v0, .L8005C7A8
    /* 4CF94 8005C794 00000000 */   nop
    /* 4CF98 8005C798 ED710108 */  j          .L8005C7B4
    /* 4CF9C 8005C79C 0980023C */   lui       $v0, %hi(func_80089E20)
  .L8005C7A0:
    /* 4CFA0 8005C7A0 0800E003 */  jr         $ra
    /* 4CFA4 8005C7A4 F0CE4224 */   addiu     $v0, $v0, %lo(func_8005CEF0)
  .L8005C7A8:
    /* 4CFA8 8005C7A8 0680023C */  lui        $v0, %hi(func_8005D378)
    /* 4CFAC 8005C7AC 0800E003 */  jr         $ra
    /* 4CFB0 8005C7B0 78D34224 */   addiu     $v0, $v0, %lo(func_8005D378)
  .L8005C7B4:
    /* 4CFB4 8005C7B4 0800E003 */  jr         $ra
    /* 4CFB8 8005C7B8 209E4224 */   addiu     $v0, $v0, %lo(func_80089E20)
endlabel func_8005C768
