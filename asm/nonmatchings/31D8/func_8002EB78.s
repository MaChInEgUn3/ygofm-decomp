nonmatching func_8002EB78, 0xFC

glabel func_8002EB78
    /* 1F378 8002EB78 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 1F37C 8002EB7C 2400BFAF */  sw         $ra, 0x24($sp)
    /* 1F380 8002EB80 2000B4AF */  sw         $s4, 0x20($sp)
    /* 1F384 8002EB84 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 1F388 8002EB88 1800B2AF */  sw         $s2, 0x18($sp)
    /* 1F38C 8002EB8C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 1F390 8002EB90 EDB8000C */  jal        func_8002E3B4
    /* 1F394 8002EB94 1000B0AF */   sw        $s0, 0x10($sp)
    /* 1F398 8002EB98 25004014 */  bnez       $v0, .L8002EC30
    /* 1F39C 8002EB9C 0F80033C */   lui       $v1, %hi(D_800EB010)
    /* 1F3A0 8002EBA0 8803828F */  lw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1F3A4 8002EBA4 10B06324 */  addiu      $v1, $v1, %lo(D_800EB010)
    /* 1F3A8 8002EBA8 00005490 */  lbu        $s4, 0x0($v0)
    /* 1F3AC 8002EBAC 01004224 */  addiu      $v0, $v0, 0x1
    /* 1F3B0 8002EBB0 880382AF */  sw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1F3B4 8002EBB4 00005290 */  lbu        $s2, 0x0($v0)
    /* 1F3B8 8002EBB8 01004224 */  addiu      $v0, $v0, 0x1
    /* 1F3BC 8002EBBC 880382AF */  sw         $v0, %gp_rel(D_8009B290)($gp)
    /* 1F3C0 8002EBC0 80005332 */  andi       $s3, $s2, 0x80
    /* 1F3C4 8002EBC4 C3891300 */  sra        $s1, $s3, 7
    /* 1F3C8 8002EBC8 80101100 */  sll        $v0, $s1, 2
    /* 1F3CC 8002EBCC 21105100 */  addu       $v0, $v0, $s1
    /* 1F3D0 8002EBD0 80100200 */  sll        $v0, $v0, 2
    /* 1F3D4 8002EBD4 23105100 */  subu       $v0, $v0, $s1
    /* 1F3D8 8002EBD8 80100200 */  sll        $v0, $v0, 2
    /* 1F3DC 8002EBDC 21804300 */  addu       $s0, $v0, $v1
    /* 1F3E0 8002EBE0 6C0390AF */  sw         $s0, %gp_rel(D_8009B274)($gp)
    /* 1F3E4 8002EBE4 30000282 */  lb         $v0, 0x30($s0)
    /* 1F3E8 8002EBE8 00000000 */  nop
    /* 1F3EC 8002EBEC 03004004 */  bltz       $v0, .L8002EBFC
    /* 1F3F0 8002EBF0 00000000 */   nop
    /* 1F3F4 8002EBF4 F5E7000C */  jal        func_80039FD4
    /* 1F3F8 8002EBF8 21200002 */   addu      $a0, $s0, $zero
  .L8002EBFC:
    /* 1F3FC 8002EBFC A7E7000C */  jal        func_80039E9C
    /* 1F400 8002EC00 00000000 */   nop
    /* 1F404 8002EC04 D1E7000C */  jal        func_80039F44
    /* 1F408 8002EC08 21200002 */   addu      $a0, $s0, $zero
    /* 1F40C 8002EC0C 0F004232 */  andi       $v0, $s2, 0xF
    /* 1F410 8002EC10 310002A2 */  sb         $v0, 0x31($s0)
    /* 1F414 8002EC14 02000224 */  addiu      $v0, $zero, 0x2
    /* 1F418 8002EC18 300014A2 */  sb         $s4, 0x30($s0)
    /* 1F41C 8002EC1C 3C0011A2 */  sb         $s1, 0x3C($s0)
    /* 1F420 8002EC20 03006012 */  beqz       $s3, .L8002EC30
    /* 1F424 8002EC24 330002A2 */   sb        $v0, 0x33($s0)
    /* 1F428 8002EC28 D8000224 */  addiu      $v0, $zero, 0xD8
    /* 1F42C 8002EC2C 340002A6 */  sh         $v0, 0x34($s0)
  .L8002EC30:
    /* 1F430 8002EC30 43ED000C */  jal        func_8003B50C
    /* 1F434 8002EC34 21200000 */   addu      $a0, $zero, $zero
    /* 1F438 8002EC38 6C03828F */  lw         $v0, %gp_rel(D_8009B274)($gp)
    /* 1F43C 8002EC3C 00000000 */  nop
    /* 1F440 8002EC40 33004290 */  lbu        $v0, 0x33($v0)
    /* 1F444 8002EC44 00000000 */  nop
    /* 1F448 8002EC48 02004014 */  bnez       $v0, .L8002EC54
    /* 1F44C 8002EC4C 00000000 */   nop
    /* 1F450 8002EC50 740380A7 */  sh         $zero, %gp_rel(D_8009B27C)($gp)
  .L8002EC54:
    /* 1F454 8002EC54 2400BF8F */  lw         $ra, 0x24($sp)
    /* 1F458 8002EC58 2000B48F */  lw         $s4, 0x20($sp)
    /* 1F45C 8002EC5C 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 1F460 8002EC60 1800B28F */  lw         $s2, 0x18($sp)
    /* 1F464 8002EC64 1400B18F */  lw         $s1, 0x14($sp)
    /* 1F468 8002EC68 1000B08F */  lw         $s0, 0x10($sp)
    /* 1F46C 8002EC6C 0800E003 */  jr         $ra
    /* 1F470 8002EC70 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8002EB78
