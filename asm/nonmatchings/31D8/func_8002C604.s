nonmatching func_8002C604, 0x88

glabel func_8002C604
    /* 1CE04 8002C604 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 1CE08 8002C608 1000B0AF */  sw         $s0, 0x10($sp)
    /* 1CE0C 8002C60C 1400BFAF */  sw         $ra, 0x14($sp)
    /* 1CE10 8002C610 73B1000C */  jal        func_8002C5CC
    /* 1CE14 8002C614 21808000 */   addu      $s0, $a0, $zero
    /* 1CE18 8002C618 21204000 */  addu       $a0, $v0, $zero
    /* 1CE1C 8002C61C 16008010 */  beqz       $a0, .L8002C678
    /* 1CE20 8002C620 80000224 */   addiu     $v0, $zero, 0x80
    /* 1CE24 8002C624 0180033C */  lui        $v1, %hi(D_80010000)
    /* 1CE28 8002C628 0000638C */  lw         $v1, %lo(D_80010000)($v1)
    /* 1CE2C 8002C62C 1C0082A0 */  sb         $v0, 0x1C($a0)
    /* 1CE30 8002C630 0F80023C */  lui        $v0, %hi(D_800E9D90)
    /* 1CE34 8002C634 909D4224 */  addiu      $v0, $v0, %lo(D_800E9D90)
    /* 1CE38 8002C638 180090A4 */  sh         $s0, 0x18($a0)
    /* 1CE3C 8002C63C 1A0080A4 */  sh         $zero, 0x1A($a0)
    /* 1CE40 8002C640 1D0080A0 */  sb         $zero, 0x1D($a0)
    /* 1CE44 8002C644 00386324 */  addiu      $v1, $v1, 0x3800
    /* 1CE48 8002C648 140083AC */  sw         $v1, 0x14($a0)
    /* 1CE4C 8002C64C 0800438C */  lw         $v1, 0x8($v0)
    /* 1CE50 8002C650 00000000 */  nop
    /* 1CE54 8002C654 080083AC */  sw         $v1, 0x8($a0)
    /* 1CE58 8002C658 0400438C */  lw         $v1, 0x4($v0)
    /* 1CE5C 8002C65C 08000224 */  addiu      $v0, $zero, 0x8
    /* 1CE60 8002C660 100082A4 */  sh         $v0, 0x10($a0)
    /* 1CE64 8002C664 000080A4 */  sh         $zero, 0x0($a0)
    /* 1CE68 8002C668 020080A4 */  sh         $zero, 0x2($a0)
    /* 1CE6C 8002C66C 040080A4 */  sh         $zero, 0x4($a0)
    /* 1CE70 8002C670 120080A4 */  sh         $zero, 0x12($a0)
    /* 1CE74 8002C674 0C0083AC */  sw         $v1, 0xC($a0)
  .L8002C678:
    /* 1CE78 8002C678 1400BF8F */  lw         $ra, 0x14($sp)
    /* 1CE7C 8002C67C 1000B08F */  lw         $s0, 0x10($sp)
    /* 1CE80 8002C680 21108000 */  addu       $v0, $a0, $zero
    /* 1CE84 8002C684 0800E003 */  jr         $ra
    /* 1CE88 8002C688 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8002C604
