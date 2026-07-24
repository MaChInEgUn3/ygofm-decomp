nonmatching func_8005C5D4, 0x58

glabel func_8005C5D4
    /* 4CDD4 8005C5D4 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 4CDD8 8005C5D8 5A018293 */  lbu        $v0, %gp_rel(D_8009B062)($gp)
    /* 4CDDC 8005C5DC 8000033C */  lui        $v1, %hi(D_7FFFFF)
    /* 4CDE0 8005C5E0 0D004014 */  bnez       $v0, .L8005C618
    /* 4CDE4 8005C5E4 1000BFAF */   sw        $ra, 0x10($sp)
    /* 4CDE8 8005C5E8 FFFF6324 */  addiu      $v1, $v1, %lo(D_7FFFFF)
  .L8005C5EC:
    /* 4CDEC 8005C5EC 0500601C */  bgtz       $v1, .L8005C604
    /* 4CDF0 8005C5F0 00000000 */   nop
    /* 4CDF4 8005C5F4 F83E020C */  jal        func_8008FBE0
    /* 4CDF8 8005C5F8 01000424 */   addiu     $a0, $zero, 0x1
    /* 4CDFC 8005C5FC 86710108 */  j          .L8005C618
    /* 4CE00 8005C600 00000000 */   nop
  .L8005C604:
    /* 4CE04 8005C604 5A018293 */  lbu        $v0, %gp_rel(D_8009B062)($gp)
    /* 4CE08 8005C608 00000000 */  nop
    /* 4CE0C 8005C60C F7FF4010 */  beqz       $v0, .L8005C5EC
    /* 4CE10 8005C610 FFFF6324 */   addiu     $v1, $v1, -0x1
    /* 4CE14 8005C614 01006324 */  addiu      $v1, $v1, 0x1
  .L8005C618:
    /* 4CE18 8005C618 1000BF8F */  lw         $ra, 0x10($sp)
    /* 4CE1C 8005C61C 21100000 */  addu       $v0, $zero, $zero
    /* 4CE20 8005C620 5A0180A3 */  sb         $zero, %gp_rel(D_8009B062)($gp)
    /* 4CE24 8005C624 0800E003 */  jr         $ra
    /* 4CE28 8005C628 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8005C5D4
