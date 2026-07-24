nonmatching func_8003C950, 0x10C

glabel func_8003C950
    /* 2D150 8003C950 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 2D154 8003C954 2C00BFAF */  sw         $ra, 0x2C($sp)
    /* 2D158 8003C958 0B00010C */  jal        func_8004002C
    /* 2D15C 8003C95C 2800B0AF */   sw        $s0, 0x28($sp)
    /* 2D160 8003C960 21204000 */  addu       $a0, $v0, $zero
    /* 2D164 8003C964 2B00010C */  jal        func_800400AC
    /* 2D168 8003C968 03000524 */   addiu     $a1, $zero, 0x3
    /* 2D16C 8003C96C 21804000 */  addu       $s0, $v0, $zero
    /* 2D170 8003C970 21200002 */  addu       $a0, $s0, $zero
    /* 2D174 8003C974 21280000 */  addu       $a1, $zero, $zero
    /* 2D178 8003C978 2130A000 */  addu       $a2, $a1, $zero
    /* 2D17C 8003C97C 40010724 */  addiu      $a3, $zero, 0x140
    /* 2D180 8003C980 F0000324 */  addiu      $v1, $zero, 0xF0
    /* 2D184 8003C984 10000224 */  addiu      $v0, $zero, 0x10
    /* 2D188 8003C988 1000A3AF */  sw         $v1, 0x10($sp)
    /* 2D18C 8003C98C 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2D190 8003C990 1800A0AF */  sw         $zero, 0x18($sp)
    /* 2D194 8003C994 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 2D198 8003C998 2000A0AF */  sw         $zero, 0x20($sp)
    /* 2D19C 8003C99C 4401010C */  jal        func_80040510
    /* 2D1A0 8003C9A0 2400A3AF */   sw        $v1, 0x24($sp)
    /* 2D1A4 8003C9A4 0400028E */  lw         $v0, 0x4($s0)
    /* 2D1A8 8003C9A8 0001033C */  lui        $v1, (0x1000000 >> 16)
    /* 2D1AC 8003C9AC 25104300 */  or         $v0, $v0, $v1
    /* 2D1B0 8003C9B0 0B00010C */  jal        func_8004002C
    /* 2D1B4 8003C9B4 040002AE */   sw        $v0, 0x4($s0)
    /* 2D1B8 8003C9B8 21204000 */  addu       $a0, $v0, $zero
    /* 2D1BC 8003C9BC 2B00010C */  jal        func_800400AC
    /* 2D1C0 8003C9C0 02000524 */   addiu     $a1, $zero, 0x2
    /* 2D1C4 8003C9C4 21804000 */  addu       $s0, $v0, $zero
    /* 2D1C8 8003C9C8 21200002 */  addu       $a0, $s0, $zero
    /* 2D1CC 8003C9CC C0010524 */  addiu      $a1, $zero, 0x1C0
    /* 2D1D0 8003C9D0 C0000624 */  addiu      $a2, $zero, 0xC0
    /* 2D1D4 8003C9D4 21380000 */  addu       $a3, $zero, $zero
    /* 2D1D8 8003C9D8 12000224 */  addiu      $v0, $zero, 0x12
    /* 2D1DC 8003C9DC 1800A2AF */  sw         $v0, 0x18($sp)
    /* 2D1E0 8003C9E0 01000224 */  addiu      $v0, $zero, 0x1
    /* 2D1E4 8003C9E4 1C00A2AF */  sw         $v0, 0x1C($sp)
    /* 2D1E8 8003C9E8 1B80023C */  lui        $v0, %hi(D_801AF000)
    /* 2D1EC 8003C9EC 00F04224 */  addiu      $v0, $v0, %lo(D_801AF000)
    /* 2D1F0 8003C9F0 1000A0AF */  sw         $zero, 0x10($sp)
    /* 2D1F4 8003C9F4 1400A0AF */  sw         $zero, 0x14($sp)
    /* 2D1F8 8003C9F8 2A0A010C */  jal        func_800428A8
    /* 2D1FC 8003C9FC 2000A2AF */   sw        $v0, 0x20($sp)
    /* 2D200 8003CA00 21200002 */  addu       $a0, $s0, $zero
    /* 2D204 8003CA04 04000524 */  addiu      $a1, $zero, 0x4
    /* 2D208 8003CA08 80000224 */  addiu      $v0, $zero, 0x80
    /* 2D20C 8003CA0C 3B0A010C */  jal        func_800428EC
    /* 2D210 8003CA10 5E0002A2 */   sb        $v0, 0x5E($s0)
    /* 2D214 8003CA14 08000296 */  lhu        $v0, 0x8($s0)
    /* 2D218 8003CA18 21200002 */  addu       $a0, $s0, $zero
    /* 2D21C 8003CA1C 6C0000A2 */  sb         $zero, 0x6C($s0)
    /* 2D220 8003CA20 28004234 */  ori        $v0, $v0, 0x28
    /* 2D224 8003CA24 760A010C */  jal        func_800429D8
    /* 2D228 8003CA28 080002A6 */   sh        $v0, 0x8($s0)
    /* 2D22C 8003CA2C 700490AF */  sw         $s0, %gp_rel(D_8009B378)($gp)
    /* 2D230 8003CA30 C2FF000C */  jal        func_8003FF08
    /* 2D234 8003CA34 00730424 */   addiu     $a0, $zero, 0x7300
    /* 2D238 8003CA38 F755000C */  jal        func_800157DC
    /* 2D23C 8003CA3C 00000000 */   nop
    /* 2D240 8003CA40 0F80033C */  lui        $v1, %hi(D_800E9ECF)
    /* 2D244 8003CA44 2C00BF8F */  lw         $ra, 0x2C($sp)
    /* 2D248 8003CA48 2800B08F */  lw         $s0, 0x28($sp)
    /* 2D24C 8003CA4C 02000224 */  addiu      $v0, $zero, 0x2
    /* 2D250 8003CA50 CF9E62A0 */  sb         $v0, %lo(D_800E9ECF)($v1)
    /* 2D254 8003CA54 0800E003 */  jr         $ra
    /* 2D258 8003CA58 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8003C950
