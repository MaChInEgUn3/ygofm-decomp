nonmatching func_8004C0AC, 0x68

glabel func_8004C0AC
    /* 3C8AC 8004C0AC D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 3C8B0 8004C0B0 1400B1AF */  sw         $s1, 0x14($sp)
    /* 3C8B4 8004C0B4 21888000 */  addu       $s1, $a0, $zero
    /* 3C8B8 8004C0B8 1000B0AF */  sw         $s0, 0x10($sp)
    /* 3C8BC 8004C0BC 21800000 */  addu       $s0, $zero, $zero
    /* 3C8C0 8004C0C0 2000BFAF */  sw         $ra, 0x20($sp)
    /* 3C8C4 8004C0C4 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 3C8C8 8004C0C8 CD2E010C */  jal        func_8004BB34
    /* 3C8CC 8004C0CC 1800B2AF */   sw        $s2, 0x18($sp)
    /* 3C8D0 8004C0D0 21904000 */  addu       $s2, $v0, $zero
    /* 3C8D4 8004C0D4 F7001324 */  addiu      $s3, $zero, 0xF7
    /* 3C8D8 8004C0D8 01001026 */  addiu      $s0, $s0, 0x1
  .L8004C0DC:
    /* 3C8DC 8004C0DC B92E010C */  jal        func_8004BAE4
    /* 3C8E0 8004C0E0 21202002 */   addu      $a0, $s1, $zero
    /* 3C8E4 8004C0E4 FF004230 */  andi       $v0, $v0, 0xFF
    /* 3C8E8 8004C0E8 03005310 */  beq        $v0, $s3, .L8004C0F8
    /* 3C8EC 8004C0EC 2B101202 */   sltu      $v0, $s0, $s2
    /* 3C8F0 8004C0F0 FAFF4014 */  bnez       $v0, .L8004C0DC
    /* 3C8F4 8004C0F4 01001026 */   addiu     $s0, $s0, 0x1
  .L8004C0F8:
    /* 3C8F8 8004C0F8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 3C8FC 8004C0FC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 3C900 8004C100 1800B28F */  lw         $s2, 0x18($sp)
    /* 3C904 8004C104 1400B18F */  lw         $s1, 0x14($sp)
    /* 3C908 8004C108 1000B08F */  lw         $s0, 0x10($sp)
    /* 3C90C 8004C10C 0800E003 */  jr         $ra
    /* 3C910 8004C110 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8004C0AC
