nonmatching func_8005FB30, 0x94

glabel func_8005FB30
    /* 50330 8005FB30 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 50334 8005FB34 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 50338 8005FB38 21988000 */  addu       $s3, $a0, $zero
    /* 5033C 8005FB3C 2000BFAF */  sw         $ra, 0x20($sp)
    /* 50340 8005FB40 1800B2AF */  sw         $s2, 0x18($sp)
    /* 50344 8005FB44 1400B1AF */  sw         $s1, 0x14($sp)
    /* 50348 8005FB48 05006016 */  bnez       $s3, .L8005FB60
    /* 5034C 8005FB4C 1000B0AF */   sw        $s0, 0x10($sp)
    /* 50350 8005FB50 6C01938F */  lw         $s3, %gp_rel(D_8009B074)($gp)
    /* 50354 8005FB54 00000000 */  nop
    /* 50358 8005FB58 13006012 */  beqz       $s3, .L8005FBA8
    /* 5035C 8005FB5C 00000000 */   nop
  .L8005FB60:
    /* 50360 8005FB60 21900000 */  addu       $s2, $zero, $zero
    /* 50364 8005FB64 10001124 */  addiu      $s1, $zero, 0x10
    /* 50368 8005FB68 21806002 */  addu       $s0, $s3, $zero
  .L8005FB6C:
    /* 5036C 8005FB6C 06000386 */  lh         $v1, 0x6($s0)
    /* 50370 8005FB70 00000000 */  nop
    /* 50374 8005FB74 04006228 */  slti       $v0, $v1, 0x4
    /* 50378 8005FB78 06004010 */  beqz       $v0, .L8005FB94
    /* 5037C 8005FB7C 02006228 */   slti      $v0, $v1, 0x2
    /* 50380 8005FB80 04004014 */  bnez       $v0, .L8005FB94
    /* 50384 8005FB84 00000000 */   nop
    /* 50388 8005FB88 00000486 */  lh         $a0, 0x0($s0)
    /* 5038C 8005FB8C EC63010C */  jal        func_80058FB0
    /* 50390 8005FB90 21287102 */   addu      $a1, $s3, $s1
  .L8005FB94:
    /* 50394 8005FB94 08003126 */  addiu      $s1, $s1, 0x8
    /* 50398 8005FB98 01005226 */  addiu      $s2, $s2, 0x1
    /* 5039C 8005FB9C 0200422A */  slti       $v0, $s2, 0x2
    /* 503A0 8005FBA0 F2FF4014 */  bnez       $v0, .L8005FB6C
    /* 503A4 8005FBA4 08001026 */   addiu     $s0, $s0, 0x8
  .L8005FBA8:
    /* 503A8 8005FBA8 2000BF8F */  lw         $ra, 0x20($sp)
    /* 503AC 8005FBAC 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 503B0 8005FBB0 1800B28F */  lw         $s2, 0x18($sp)
    /* 503B4 8005FBB4 1400B18F */  lw         $s1, 0x14($sp)
    /* 503B8 8005FBB8 1000B08F */  lw         $s0, 0x10($sp)
    /* 503BC 8005FBBC 0800E003 */  jr         $ra
    /* 503C0 8005FBC0 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_8005FB30
