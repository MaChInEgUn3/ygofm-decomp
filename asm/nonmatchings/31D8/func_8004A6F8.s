nonmatching func_8004A6F8, 0x6C

glabel func_8004A6F8
    /* 3AEF8 8004A6F8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3AEFC 8004A6FC 0600063C */  lui        $a2, (0x60100 >> 16)
    /* 3AF00 8004A700 0180023C */  lui        $v0, %hi(D_80011434)
    /* 3AF04 8004A704 34144224 */  addiu      $v0, $v0, %lo(D_80011434)
    /* 3AF08 8004A708 80200400 */  sll        $a0, $a0, 2
    /* 3AF0C 8004A70C 21208200 */  addu       $a0, $a0, $v0
    /* 3AF10 8004A710 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3AF14 8004A714 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3AF18 8004A718 0000828C */  lw         $v0, 0x0($a0)
    /* 3AF1C 8004A71C 0001C634 */  ori        $a2, $a2, (0x60100 & 0xFFFF)
    /* 3AF20 8004A720 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3AF24 8004A724 C40466AC */  sw         $a2, 0x4C4($v1)
    /* 3AF28 8004A728 C00462AC */  sw         $v0, 0x4C0($v1)
    /* 3AF2C 8004A72C 2000A294 */  lhu        $v0, 0x20($a1)
    /* 3AF30 8004A730 00000000 */  nop
    /* 3AF34 8004A734 FA0462A4 */  sh         $v0, 0x4FA($v1)
    /* 3AF38 8004A738 2200A294 */  lhu        $v0, 0x22($a1)
    /* 3AF3C 8004A73C 00000000 */  nop
    /* 3AF40 8004A740 FC0462A4 */  sh         $v0, 0x4FC($v1)
    /* 3AF44 8004A744 2400A294 */  lhu        $v0, 0x24($a1)
    /* 3AF48 8004A748 C0046424 */  addiu      $a0, $v1, 0x4C0
    /* 3AF4C 8004A74C 14DD010C */  jal        func_80077450
    /* 3AF50 8004A750 E40462AC */   sw        $v0, 0x4E4($v1)
    /* 3AF54 8004A754 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3AF58 8004A758 00000000 */  nop
    /* 3AF5C 8004A75C 0800E003 */  jr         $ra
    /* 3AF60 8004A760 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004A6F8
