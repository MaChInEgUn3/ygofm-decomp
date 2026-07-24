nonmatching func_8007FBB8, 0xAC

glabel func_8007FBB8
    /* 703B8 8007FBB8 0980023C */  lui        $v0, %hi(D_8009466A)
    /* 703BC 8007FBBC 6A464290 */  lbu        $v0, %lo(D_8009466A)($v0)
    /* 703C0 8007FBC0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 703C4 8007FBC4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 703C8 8007FBC8 21808000 */  addu       $s0, $a0, $zero
    /* 703CC 8007FBCC 1400B1AF */  sw         $s1, 0x14($sp)
    /* 703D0 8007FBD0 2188A000 */  addu       $s1, $a1, $zero
    /* 703D4 8007FBD4 0200422C */  sltiu      $v0, $v0, 0x2
    /* 703D8 8007FBD8 09004014 */  bnez       $v0, .L8007FC00
    /* 703DC 8007FBDC 1800BFAF */   sw        $ra, 0x18($sp)
    /* 703E0 8007FBE0 0180043C */  lui        $a0, %hi(D_800122B0)
    /* 703E4 8007FBE4 B0228424 */  addiu      $a0, $a0, %lo(D_800122B0)
    /* 703E8 8007FBE8 21280002 */  addu       $a1, $s0, $zero
    /* 703EC 8007FBEC 0980023C */  lui        $v0, %hi(D_80094664)
    /* 703F0 8007FBF0 6446428C */  lw         $v0, %lo(D_80094664)($v0)
    /* 703F4 8007FBF4 00000000 */  nop
    /* 703F8 8007FBF8 09F84000 */  jalr       $v0
    /* 703FC 8007FBFC 21302002 */   addu      $a2, $s1, $zero
  .L8007FC00:
    /* 70400 8007FC00 0980023C */  lui        $v0, %hi(D_80094660)
    /* 70404 8007FC04 6046428C */  lw         $v0, %lo(D_80094660)($v0)
    /* 70408 8007FC08 21200002 */  addu       $a0, $s0, $zero
    /* 7040C 8007FC0C 2C00428C */  lw         $v0, 0x2C($v0)
    /* 70410 8007FC10 00000000 */  nop
    /* 70414 8007FC14 09F84000 */  jalr       $v0
    /* 70418 8007FC18 21282002 */   addu      $a1, $s1, $zero
    /* 7041C 8007FC1C FF00063C */  lui        $a2, (0xFFFFFF >> 16)
    /* 70420 8007FC20 FFFFC634 */  ori        $a2, $a2, (0xFFFFFF & 0xFFFF)
    /* 70424 8007FC24 21100002 */  addu       $v0, $s0, $zero
    /* 70428 8007FC28 0980053C */  lui        $a1, %hi(D_80094728)
    /* 7042C 8007FC2C 2847A524 */  addiu      $a1, $a1, %lo(D_80094728)
    /* 70430 8007FC30 0980033C */  lui        $v1, %hi(D_80094714)
    /* 70434 8007FC34 14476324 */  addiu      $v1, $v1, %lo(D_80094714)
    /* 70438 8007FC38 24186600 */  and        $v1, $v1, $a2
    /* 7043C 8007FC3C 0004043C */  lui        $a0, (0x4000000 >> 16)
    /* 70440 8007FC40 25186400 */  or         $v1, $v1, $a0
    /* 70444 8007FC44 0000A3AC */  sw         $v1, 0x0($a1)
    /* 70448 8007FC48 2428A600 */  and        $a1, $a1, $a2
    /* 7044C 8007FC4C 000045AC */  sw         $a1, 0x0($v0)
    /* 70450 8007FC50 1800BF8F */  lw         $ra, 0x18($sp)
    /* 70454 8007FC54 1400B18F */  lw         $s1, 0x14($sp)
    /* 70458 8007FC58 1000B08F */  lw         $s0, 0x10($sp)
    /* 7045C 8007FC5C 0800E003 */  jr         $ra
    /* 70460 8007FC60 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8007FBB8
