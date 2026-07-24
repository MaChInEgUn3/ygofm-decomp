nonmatching func_8003F388, 0xCC

glabel func_8003F388
    /* 2FB88 8003F388 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 2FB8C 8003F38C 21180000 */  addu       $v1, $zero, $zero
    /* 2FB90 8003F390 0F80023C */  lui        $v0, %hi(D_800EB0F8)
    /* 2FB94 8003F394 F8B04424 */  addiu      $a0, $v0, %lo(D_800EB0F8)
    /* 2FB98 8003F398 2400BFAF */  sw         $ra, 0x24($sp)
    /* 2FB9C 8003F39C 2000B0AF */  sw         $s0, 0x20($sp)
    /* 2FBA0 8003F3A0 E60480A3 */  sb         $zero, %gp_rel(D_8009B3EE)($gp)
  .L8003F3A4:
    /* 2FBA4 8003F3A4 34008294 */  lhu        $v0, 0x34($a0)
    /* 2FBA8 8003F3A8 00000000 */  nop
    /* 2FBAC 8003F3AC 00804230 */  andi       $v0, $v0, 0x8000
    /* 2FBB0 8003F3B0 04004014 */  bnez       $v0, .L8003F3C4
    /* 2FBB4 8003F3B4 00000000 */   nop
    /* 2FBB8 8003F3B8 E60483A3 */  sb         $v1, %gp_rel(D_8009B3EE)($gp)
    /* 2FBBC 8003F3BC F5FC0008 */  j          .L8003F3D4
    /* 2FBC0 8003F3C0 00000000 */   nop
  .L8003F3C4:
    /* 2FBC4 8003F3C4 01006324 */  addiu      $v1, $v1, 0x1
    /* 2FBC8 8003F3C8 04006228 */  slti       $v0, $v1, 0x4
    /* 2FBCC 8003F3CC F5FF4014 */  bnez       $v0, .L8003F3A4
    /* 2FBD0 8003F3D0 64008424 */   addiu     $a0, $a0, 0x64
  .L8003F3D4:
    /* 2FBD4 8003F3D4 0B00010C */  jal        func_8004002C
    /* 2FBD8 8003F3D8 00000000 */   nop
    /* 2FBDC 8003F3DC 21204000 */  addu       $a0, $v0, $zero
    /* 2FBE0 8003F3E0 2B00010C */  jal        func_800400AC
    /* 2FBE4 8003F3E4 02000524 */   addiu     $a1, $zero, 0x2
    /* 2FBE8 8003F3E8 21804000 */  addu       $s0, $v0, $zero
    /* 2FBEC 8003F3EC 21200002 */  addu       $a0, $s0, $zero
    /* 2FBF0 8003F3F0 20000524 */  addiu      $a1, $zero, 0x20
    /* 2FBF4 8003F3F4 02000224 */  addiu      $v0, $zero, 0x2
    /* 2FBF8 8003F3F8 1000A2AF */  sw         $v0, 0x10($sp)
    /* 2FBFC 8003F3FC 01000224 */  addiu      $v0, $zero, 0x1
    /* 2FC00 8003F400 1400A2AF */  sw         $v0, 0x14($sp)
    /* 2FC04 8003F404 0B000224 */  addiu      $v0, $zero, 0xB
    /* 2FC08 8003F408 1800A2AF */  sw         $v0, 0x18($sp)
    /* 2FC0C 8003F40C 0C020224 */  addiu      $v0, $zero, 0x20C
    /* 2FC10 8003F410 C0FF0624 */  addiu      $a2, $zero, -0x40
    /* 2FC14 8003F414 03000724 */  addiu      $a3, $zero, 0x3
    /* 2FC18 8003F418 3301010C */  jal        func_800404CC
    /* 2FC1C 8003F41C 1C00A2AF */   sw        $v0, 0x1C($sp)
    /* 2FC20 8003F420 08000296 */  lhu        $v0, 0x8($s0)
    /* 2FC24 8003F424 21200002 */  addu       $a0, $s0, $zero
    /* 2FC28 8003F428 28004234 */  ori        $v0, $v0, 0x28
    /* 2FC2C 8003F42C 460A010C */  jal        func_80042918
    /* 2FC30 8003F430 080002A6 */   sh        $v0, 0x8($s0)
    /* 2FC34 8003F434 21200002 */  addu       $a0, $s0, $zero
    /* 2FC38 8003F438 3B0A010C */  jal        func_800428EC
    /* 2FC3C 8003F43C 0F000524 */   addiu     $a1, $zero, 0xF
    /* 2FC40 8003F440 2400BF8F */  lw         $ra, 0x24($sp)
    /* 2FC44 8003F444 D00490AF */  sw         $s0, %gp_rel(D_8009B3D8)($gp)
    /* 2FC48 8003F448 2000B08F */  lw         $s0, 0x20($sp)
    /* 2FC4C 8003F44C 0800E003 */  jr         $ra
    /* 2FC50 8003F450 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8003F388
