nonmatching func_80022F98, 0x58

glabel func_80022F98
    /* 13798 80022F98 1300A010 */  beqz       $a1, .L80022FE8
    /* 1379C 80022F9C 21308000 */   addu      $a2, $a0, $zero
    /* 137A0 80022FA0 0000C48C */  lw         $a0, 0x0($a2)
    /* 137A4 80022FA4 3000A294 */  lhu        $v0, 0x30($a1)
    /* 137A8 80022FA8 30008394 */  lhu        $v1, 0x30($a0)
    /* 137AC 80022FAC 00000000 */  nop
    /* 137B0 80022FB0 23104300 */  subu       $v0, $v0, $v1
    /* 137B4 80022FB4 2800A2A4 */  sh         $v0, 0x28($a1)
    /* 137B8 80022FB8 3200A294 */  lhu        $v0, 0x32($a1)
    /* 137BC 80022FBC 32008394 */  lhu        $v1, 0x32($a0)
    /* 137C0 80022FC0 00000000 */  nop
    /* 137C4 80022FC4 23104300 */  subu       $v0, $v0, $v1
    /* 137C8 80022FC8 2A00A2A4 */  sh         $v0, 0x2A($a1)
    /* 137CC 80022FCC 1700C390 */  lbu        $v1, 0x17($a2)
    /* 137D0 80022FD0 01000224 */  addiu      $v0, $zero, 0x1
    /* 137D4 80022FD4 6C00A2A0 */  sb         $v0, 0x6C($a1)
    /* 137D8 80022FD8 0280023C */  lui        $v0, %hi(func_80022EEC)
    /* 137DC 80022FDC EC2E4224 */  addiu      $v0, $v0, %lo(func_80022EEC)
    /* 137E0 80022FE0 2400A2AC */  sw         $v0, 0x24($a1)
    /* 137E4 80022FE4 2C00A3A4 */  sh         $v1, 0x2C($a1)
  .L80022FE8:
    /* 137E8 80022FE8 0800E003 */  jr         $ra
    /* 137EC 80022FEC 00000000 */   nop
endlabel func_80022F98
