nonmatching func_8003CF14, 0xB4

glabel func_8003CF14
    /* 2D714 8003CF14 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2D718 8003CF18 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2D71C 8003CF1C 21908000 */  addu       $s2, $a0, $zero
    /* 2D720 8003CF20 40030524 */  addiu      $a1, $zero, 0x340
    /* 2D724 8003CF24 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 2D728 8003CF28 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2D72C 8003CF2C AEF3000C */  jal        func_8003CEB8
    /* 2D730 8003CF30 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2D734 8003CF34 FFFF4330 */  andi       $v1, $v0, 0xFFFF
    /* 2D738 8003CF38 78035126 */  addiu      $s1, $s2, 0x378
    /* 2D73C 8003CF3C 0F001024 */  addiu      $s0, $zero, 0xF
    /* 2D740 8003CF40 7E0342A6 */  sh         $v0, 0x37E($s2)
    /* 2D744 8003CF44 7C0342A6 */  sh         $v0, 0x37C($s2)
    /* 2D748 8003CF48 00140300 */  sll        $v0, $v1, 16
    /* 2D74C 8003CF4C 25106200 */  or         $v0, $v1, $v0
    /* 2D750 8003CF50 600082AF */  sw         $v0, %gp_rel(D_8009AF68)($gp)
    /* 2D754 8003CF54 5C0082AF */  sw         $v0, %gp_rel(D_8009AF64)($gp)
  .L8003CF58:
    /* 2D758 8003CF58 9DF3000C */  jal        func_8003CE74
    /* 2D75C 8003CF5C FFFF1026 */   addiu     $s0, $s0, -0x1
    /* 2D760 8003CF60 000022AE */  sw         $v0, 0x0($s1)
    /* 2D764 8003CF64 FCFF0016 */  bnez       $s0, .L8003CF58
    /* 2D768 8003CF68 FCFF3126 */   addiu     $s1, $s1, -0x4
    /* 2D76C 8003CF6C 80034426 */  addiu      $a0, $s2, 0x380
    /* 2D770 8003CF70 AEF3000C */  jal        func_8003CEB8
    /* 2D774 8003CF74 6C000524 */   addiu     $a1, $zero, 0x6C
    /* 2D778 8003CF78 FFFF4330 */  andi       $v1, $v0, 0xFFFF
    /* 2D77C 8003CF7C F8035126 */  addiu      $s1, $s2, 0x3F8
    /* 2D780 8003CF80 04001024 */  addiu      $s0, $zero, 0x4
    /* 2D784 8003CF84 FE0342A6 */  sh         $v0, 0x3FE($s2)
    /* 2D788 8003CF88 FC0342A6 */  sh         $v0, 0x3FC($s2)
    /* 2D78C 8003CF8C 00140300 */  sll        $v0, $v1, 16
    /* 2D790 8003CF90 25106200 */  or         $v0, $v1, $v0
    /* 2D794 8003CF94 600082AF */  sw         $v0, %gp_rel(D_8009AF68)($gp)
    /* 2D798 8003CF98 5C0082AF */  sw         $v0, %gp_rel(D_8009AF64)($gp)
  .L8003CF9C:
    /* 2D79C 8003CF9C 9DF3000C */  jal        func_8003CE74
    /* 2D7A0 8003CFA0 FFFF1026 */   addiu     $s0, $s0, -0x1
    /* 2D7A4 8003CFA4 000022AE */  sw         $v0, 0x0($s1)
    /* 2D7A8 8003CFA8 FCFF0016 */  bnez       $s0, .L8003CF9C
    /* 2D7AC 8003CFAC FCFF3126 */   addiu     $s1, $s1, -0x4
    /* 2D7B0 8003CFB0 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2D7B4 8003CFB4 1800B28F */  lw         $s2, 0x18($sp)
    /* 2D7B8 8003CFB8 1400B18F */  lw         $s1, 0x14($sp)
    /* 2D7BC 8003CFBC 1000B08F */  lw         $s0, 0x10($sp)
    /* 2D7C0 8003CFC0 0800E003 */  jr         $ra
    /* 2D7C4 8003CFC4 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003CF14
