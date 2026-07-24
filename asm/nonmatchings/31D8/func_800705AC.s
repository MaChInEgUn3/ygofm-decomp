nonmatching func_800705AC, 0x2C

glabel func_800705AC
    /* 60DAC 800705AC 0F80023C */  lui        $v0, %hi(D_800F5BE8)
    /* 60DB0 800705B0 E85B4224 */  addiu      $v0, $v0, %lo(D_800F5BE8)
    /* 60DB4 800705B4 0800438C */  lw         $v1, 0x8($v0)
    /* 60DB8 800705B8 00000000 */  nop
    /* 60DBC 800705BC 02006424 */  addiu      $a0, $v1, 0x2
    /* 60DC0 800705C0 080044AC */  sw         $a0, 0x8($v0)
    /* 60DC4 800705C4 01006290 */  lbu        $v0, 0x1($v1)
    /* 60DC8 800705C8 00006390 */  lbu        $v1, 0x0($v1)
    /* 60DCC 800705CC 00120200 */  sll        $v0, $v0, 8
    /* 60DD0 800705D0 0800E003 */  jr         $ra
    /* 60DD4 800705D4 25106200 */   or        $v0, $v1, $v0
endlabel func_800705AC
