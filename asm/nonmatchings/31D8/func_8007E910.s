nonmatching func_8007E910, 0xA0

glabel func_8007E910
    /* 6F110 8007E910 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 6F114 8007E914 2800B2AF */  sw         $s2, 0x28($sp)
    /* 6F118 8007E918 21908000 */  addu       $s2, $a0, $zero
    /* 6F11C 8007E91C 2400B1AF */  sw         $s1, 0x24($sp)
    /* 6F120 8007E920 2188A000 */  addu       $s1, $a1, $zero
    /* 6F124 8007E924 2000B0AF */  sw         $s0, 0x20($sp)
    /* 6F128 8007E928 0980103C */  lui        $s0, %hi(D_80093C10)
    /* 6F12C 8007E92C 103C1026 */  addiu      $s0, $s0, %lo(D_80093C10)
    /* 6F130 8007E930 21200002 */  addu       $a0, $s0, $zero
    /* 6F134 8007E934 21284002 */  addu       $a1, $s2, $zero
    /* 6F138 8007E938 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 6F13C 8007E93C 8409020C */  jal        func_80082610
    /* 6F140 8007E940 80002626 */   addiu     $a2, $s1, 0x80
    /* 6F144 8007E944 00020426 */  addiu      $a0, $s0, 0x200
    /* 6F148 8007E948 21280000 */  addu       $a1, $zero, $zero
    /* 6F14C 8007E94C 21300000 */  addu       $a2, $zero, $zero
    /* 6F150 8007E950 1080013C */  lui        $at, %hi(D_800FC7A2)
    /* 6F154 8007E954 A2C722A4 */  sh         $v0, %lo(D_800FC7A2)($at)
    /* 6F158 8007E958 80000224 */  addiu      $v0, $zero, 0x80
    /* 6F15C 8007E95C 1400A2AF */  sw         $v0, 0x14($sp)
    /* 6F160 8007E960 20000224 */  addiu      $v0, $zero, 0x20
    /* 6F164 8007E964 21384002 */  addu       $a3, $s2, $zero
    /* 6F168 8007E968 1000B1AF */  sw         $s1, 0x10($sp)
    /* 6F16C 8007E96C 2C09020C */  jal        func_800824B0
    /* 6F170 8007E970 1800A2AF */   sw        $v0, 0x18($sp)
    /* 6F174 8007E974 0980043C */  lui        $a0, %hi(D_80093A88)
    /* 6F178 8007E978 883A8424 */  addiu      $a0, $a0, %lo(D_80093A88)
    /* 6F17C 8007E97C 21280000 */  addu       $a1, $zero, $zero
    /* 6F180 8007E980 1080013C */  lui        $at, %hi(D_800FC7A0)
    /* 6F184 8007E984 A0C722A4 */  sh         $v0, %lo(D_800FC7A0)($at)
    /* 6F188 8007E988 0980013C */  lui        $at, %hi(D_80093C08)
    /* 6F18C 8007E98C 083C20AC */  sw         $zero, %lo(D_80093C08)($at)
    /* 6F190 8007E990 F438020C */  jal        func_8008E3D0
    /* 6F194 8007E994 80010624 */   addiu     $a2, $zero, 0x180
    /* 6F198 8007E998 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 6F19C 8007E99C 2800B28F */  lw         $s2, 0x28($sp)
    /* 6F1A0 8007E9A0 2400B18F */  lw         $s1, 0x24($sp)
    /* 6F1A4 8007E9A4 2000B08F */  lw         $s0, 0x20($sp)
    /* 6F1A8 8007E9A8 0800E003 */  jr         $ra
    /* 6F1AC 8007E9AC 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8007E910
