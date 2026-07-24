nonmatching func_8004A764, 0x5C

glabel func_8004A764
    /* 3AF64 8004A764 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 3AF68 8004A768 0600053C */  lui        $a1, (0x60100 >> 16)
    /* 3AF6C 8004A76C 0180023C */  lui        $v0, %hi(D_80011434)
    /* 3AF70 8004A770 34144224 */  addiu      $v0, $v0, %lo(D_80011434)
    /* 3AF74 8004A774 80200400 */  sll        $a0, $a0, 2
    /* 3AF78 8004A778 21208200 */  addu       $a0, $a0, $v0
    /* 3AF7C 8004A77C 0A80033C */  lui        $v1, %hi(D_8009B458)
    /* 3AF80 8004A780 58B4638C */  lw         $v1, %lo(D_8009B458)($v1)
    /* 3AF84 8004A784 0000828C */  lw         $v0, 0x0($a0)
    /* 3AF88 8004A788 0001A534 */  ori        $a1, $a1, (0x60100 & 0xFFFF)
    /* 3AF8C 8004A78C 1000BFAF */  sw         $ra, 0x10($sp)
    /* 3AF90 8004A790 C00462AC */  sw         $v0, 0x4C0($v1)
    /* 3AF94 8004A794 05000224 */  addiu      $v0, $zero, 0x5
    /* 3AF98 8004A798 C0046424 */  addiu      $a0, $v1, 0x4C0
    /* 3AF9C 8004A79C C40465AC */  sw         $a1, 0x4C4($v1)
    /* 3AFA0 8004A7A0 FA0460A4 */  sh         $zero, 0x4FA($v1)
    /* 3AFA4 8004A7A4 FC0460A4 */  sh         $zero, 0x4FC($v1)
    /* 3AFA8 8004A7A8 14DD010C */  jal        func_80077450
    /* 3AFAC 8004A7AC E40462AC */   sw        $v0, 0x4E4($v1)
    /* 3AFB0 8004A7B0 1000BF8F */  lw         $ra, 0x10($sp)
    /* 3AFB4 8004A7B4 00000000 */  nop
    /* 3AFB8 8004A7B8 0800E003 */  jr         $ra
    /* 3AFBC 8004A7BC 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8004A764
