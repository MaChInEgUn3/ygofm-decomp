nonmatching func_8002E3FC, 0x74

glabel func_8002E3FC
    /* 1EBFC 8002E3FC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1EC00 8002E400 2400BFAF */  sw         $ra, 0x24($sp)
    /* 1EC04 8002E404 1B00010C */  jal        func_8004006C
    /* 1EC08 8002E408 2000B0AF */   sw        $s0, 0x20($sp)
    /* 1EC0C 8002E40C 21204000 */  addu       $a0, $v0, $zero
    /* 1EC10 8002E410 2B00010C */  jal        func_800400AC
    /* 1EC14 8002E414 02000524 */   addiu     $a1, $zero, 0x2
    /* 1EC18 8002E418 21804000 */  addu       $s0, $v0, $zero
    /* 1EC1C 8002E41C 21200002 */  addu       $a0, $s0, $zero
    /* 1EC20 8002E420 10000524 */  addiu      $a1, $zero, 0x10
    /* 1EC24 8002E424 0D000224 */  addiu      $v0, $zero, 0xD
    /* 1EC28 8002E428 1800A2AF */  sw         $v0, 0x18($sp)
    /* 1EC2C 8002E42C 00010224 */  addiu      $v0, $zero, 0x100
    /* 1EC30 8002E430 B0000624 */  addiu      $a2, $zero, 0xB0
    /* 1EC34 8002E434 21380000 */  addu       $a3, $zero, $zero
    /* 1EC38 8002E438 1000A0AF */  sw         $zero, 0x10($sp)
    /* 1EC3C 8002E43C 1400A0AF */  sw         $zero, 0x14($sp)
    /* 1EC40 8002E440 3301010C */  jal        func_800404CC
    /* 1EC44 8002E444 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* 1EC48 8002E448 08000296 */  lhu        $v0, 0x8($s0)
    /* 1EC4C 8002E44C 21200002 */  addu       $a0, $s0, $zero
    /* 1EC50 8002E450 08004234 */  ori        $v0, $v0, 0x8
    /* 1EC54 8002E454 460A010C */  jal        func_80042918
    /* 1EC58 8002E458 080002A6 */   sh        $v0, 0x8($s0)
    /* 1EC5C 8002E45C 21100002 */  addu       $v0, $s0, $zero
    /* 1EC60 8002E460 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1EC64 8002E464 2000B08F */  lw         $s0, 0x20($sp)
    /* 1EC68 8002E468 0800E003 */  jr         $ra
    /* 1EC6C 8002E46C 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8002E3FC
