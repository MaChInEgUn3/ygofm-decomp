nonmatching func_8008B85C, 0x70

glabel func_8008B85C
    /* 7C05C 8008B85C E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 7C060 8008B860 1000B0AF */  sw         $s0, 0x10($sp)
    /* 7C064 8008B864 1080103C */  lui        $s0, %hi(D_800FE348)
    /* 7C068 8008B868 48E31026 */  addiu      $s0, $s0, %lo(D_800FE348)
    /* 7C06C 8008B86C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 7C070 8008B870 0C0000AE */  sw         $zero, 0xC($s0)
    /* 7C074 8008B874 3434020C */  jal        func_8008D0D0
    /* 7C078 8008B878 440000AE */   sw        $zero, 0x44($s0)
    /* 7C07C 8008B87C 000000AE */  sw         $zero, 0x0($s0)
    /* 7C080 8008B880 040000AE */  sw         $zero, 0x4($s0)
    /* 7C084 8008B884 080000AE */  sw         $zero, 0x8($s0)
    /* 7C088 8008B888 540000AE */  sw         $zero, 0x54($s0)
    /* 7C08C 8008B88C 5400038E */  lw         $v1, 0x54($s0)
    /* 7C090 8008B890 FFFF0224 */  addiu      $v0, $zero, -0x1
    /* 7C094 8008B894 140002AE */  sw         $v0, 0x14($s0)
    /* 7C098 8008B898 01000224 */  addiu      $v0, $zero, 0x1
    /* 7C09C 8008B89C 4C0002AE */  sw         $v0, 0x4C($s0)
    /* 7C0A0 8008B8A0 480002AE */  sw         $v0, 0x48($s0)
    /* 7C0A4 8008B8A4 AC34020C */  jal        func_8008D2B0
    /* 7C0A8 8008B8A8 500003AE */   sw        $v1, 0x50($s0)
    /* 7C0AC 8008B8AC 0980053C */  lui        $a1, %hi(func_8008CFC8)
    /* 7C0B0 8008B8B0 C8CFA524 */  addiu      $a1, $a1, %lo(func_8008CFC8)
    /* 7C0B4 8008B8B4 15D1010C */  jal        func_80074454
    /* 7C0B8 8008B8B8 07000424 */   addiu     $a0, $zero, 0x7
    /* 7C0BC 8008B8BC 1400BF8F */  lw         $ra, 0x14($sp)
    /* 7C0C0 8008B8C0 1000B08F */  lw         $s0, 0x10($sp)
    /* 7C0C4 8008B8C4 0800E003 */  jr         $ra
    /* 7C0C8 8008B8C8 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8008B85C
