nonmatching func_80019BA0, 0x30

glabel func_80019BA0
    /* A3A0 80019BA0 01000224 */  addiu      $v0, $zero, 0x1
    /* A3A4 80019BA4 6C0082A0 */  sb         $v0, 0x6C($a0)
    /* A3A8 80019BA8 0280023C */  lui        $v0, %hi(func_80019B2C)
    /* A3AC 80019BAC 08008394 */  lhu        $v1, 0x8($a0)
    /* A3B0 80019BB0 2C9B4224 */  addiu      $v0, $v0, %lo(func_80019B2C)
    /* A3B4 80019BB4 210085A0 */  sb         $a1, 0x21($a0)
    /* A3B8 80019BB8 280086A4 */  sh         $a2, 0x28($a0)
    /* A3BC 80019BBC 2A0087A4 */  sh         $a3, 0x2A($a0)
    /* A3C0 80019BC0 240082AC */  sw         $v0, 0x24($a0)
    /* A3C4 80019BC4 04006334 */  ori        $v1, $v1, 0x4
    /* A3C8 80019BC8 0800E003 */  jr         $ra
    /* A3CC 80019BCC 080083A4 */   sh        $v1, 0x8($a0)
endlabel func_80019BA0
