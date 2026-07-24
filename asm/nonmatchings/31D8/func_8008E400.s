nonmatching func_8008E400, 0x150

glabel func_8008E400
    /* 7EC00 8008E400 C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 7EC04 8008E404 2400B5AF */  sw         $s5, 0x24($sp)
    /* 7EC08 8008E408 21A8A000 */  addu       $s5, $a1, $zero
    /* 7EC0C 8008E40C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 7EC10 8008E410 2198C000 */  addu       $s3, $a2, $zero
    /* 7EC14 8008E414 2C00B7AF */  sw         $s7, 0x2C($sp)
    /* 7EC18 8008E418 21B8E000 */  addu       $s7, $a3, $zero
    /* 7EC1C 8008E41C 2000B4AF */  sw         $s4, 0x20($sp)
    /* 7EC20 8008E420 21A08000 */  addu       $s4, $a0, $zero
    /* 7EC24 8008E424 1800B2AF */  sw         $s2, 0x18($sp)
    /* 7EC28 8008E428 21909302 */  addu       $s2, $s4, $s3
    /* 7EC2C 8008E42C 2800B6AF */  sw         $s6, 0x28($sp)
    /* 7EC30 8008E430 21B00000 */  addu       $s6, $zero, $zero
    /* 7EC34 8008E434 0200A22E */  sltiu      $v0, $s5, 0x2
    /* 7EC38 8008E438 3000BFAF */  sw         $ra, 0x30($sp)
    /* 7EC3C 8008E43C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7EC40 8008E440 38004014 */  bnez       $v0, .L8008E524
    /* 7EC44 8008E444 1000B0AF */   sw        $s0, 0x10($sp)
    /* 7EC48 8008E448 02000224 */  addiu      $v0, $zero, 0x2
    /* 7EC4C 8008E44C 0A00A216 */  bne        $s5, $v0, .L8008E478
    /* 7EC50 8008E450 42101500 */   srl       $v0, $s5, 1
    /* 7EC54 8008E454 09F8E002 */  jalr       $s7
    /* 7EC58 8008E458 21284002 */   addu      $a1, $s2, $zero
    /* 7EC5C 8008E45C 31004018 */  blez       $v0, .L8008E524
    /* 7EC60 8008E460 21208002 */   addu      $a0, $s4, $zero
    /* 7EC64 8008E464 21284002 */  addu       $a1, $s2, $zero
    /* 7EC68 8008E468 5439020C */  jal        func_8008E550
    /* 7EC6C 8008E46C 21306002 */   addu      $a2, $s3, $zero
    /* 7EC70 8008E470 49390208 */  j          .L8008E524
    /* 7EC74 8008E474 00000000 */   nop
  .L8008E478:
    /* 7EC78 8008E478 18005300 */  mult       $v0, $s3
    /* 7EC7C 8008E47C 21208002 */  addu       $a0, $s4, $zero
    /* 7EC80 8008E480 21306002 */  addu       $a2, $s3, $zero
    /* 7EC84 8008E484 21888002 */  addu       $s1, $s4, $zero
    /* 7EC88 8008E488 01001024 */  addiu      $s0, $zero, 0x1
    /* 7EC8C 8008E48C 12180000 */  mflo       $v1
    /* 7EC90 8008E490 5439020C */  jal        func_8008E550
    /* 7EC94 8008E494 21288302 */   addu      $a1, $s4, $v1
    /* 7EC98 8008E498 2B101502 */  sltu       $v0, $s0, $s5
    /* 7EC9C 8008E49C 11004010 */  beqz       $v0, .L8008E4E4
    /* 7ECA0 8008E4A0 00000000 */   nop
  .L8008E4A4:
    /* 7ECA4 8008E4A4 21204002 */  addu       $a0, $s2, $zero
    /* 7ECA8 8008E4A8 09F8E002 */  jalr       $s7
    /* 7ECAC 8008E4AC 21288002 */   addu      $a1, $s4, $zero
    /* 7ECB0 8008E4B0 08004104 */  bgez       $v0, .L8008E4D4
    /* 7ECB4 8008E4B4 00000000 */   nop
    /* 7ECB8 8008E4B8 21883302 */  addu       $s1, $s1, $s3
    /* 7ECBC 8008E4BC 05005112 */  beq        $s2, $s1, .L8008E4D4
    /* 7ECC0 8008E4C0 0100D626 */   addiu     $s6, $s6, 0x1
    /* 7ECC4 8008E4C4 21204002 */  addu       $a0, $s2, $zero
    /* 7ECC8 8008E4C8 21282002 */  addu       $a1, $s1, $zero
    /* 7ECCC 8008E4CC 5439020C */  jal        func_8008E550
    /* 7ECD0 8008E4D0 21306002 */   addu      $a2, $s3, $zero
  .L8008E4D4:
    /* 7ECD4 8008E4D4 01001026 */  addiu      $s0, $s0, 0x1
    /* 7ECD8 8008E4D8 2B101502 */  sltu       $v0, $s0, $s5
    /* 7ECDC 8008E4DC F1FF4014 */  bnez       $v0, .L8008E4A4
    /* 7ECE0 8008E4E0 21905302 */   addu      $s2, $s2, $s3
  .L8008E4E4:
    /* 7ECE4 8008E4E4 04003412 */  beq        $s1, $s4, .L8008E4F8
    /* 7ECE8 8008E4E8 21208002 */   addu      $a0, $s4, $zero
    /* 7ECEC 8008E4EC 21282002 */  addu       $a1, $s1, $zero
    /* 7ECF0 8008E4F0 5439020C */  jal        func_8008E550
    /* 7ECF4 8008E4F4 21306002 */   addu      $a2, $s3, $zero
  .L8008E4F8:
    /* 7ECF8 8008E4F8 21208002 */  addu       $a0, $s4, $zero
    /* 7ECFC 8008E4FC 2128C002 */  addu       $a1, $s6, $zero
    /* 7ED00 8008E500 21306002 */  addu       $a2, $s3, $zero
    /* 7ED04 8008E504 0039020C */  jal        func_8008E400
    /* 7ED08 8008E508 2138E002 */   addu      $a3, $s7, $zero
    /* 7ED0C 8008E50C 21203302 */  addu       $a0, $s1, $s3
    /* 7ED10 8008E510 2328B602 */  subu       $a1, $s5, $s6
    /* 7ED14 8008E514 FFFFA524 */  addiu      $a1, $a1, -0x1
    /* 7ED18 8008E518 21306002 */  addu       $a2, $s3, $zero
    /* 7ED1C 8008E51C 0039020C */  jal        func_8008E400
    /* 7ED20 8008E520 2138E002 */   addu      $a3, $s7, $zero
  .L8008E524:
    /* 7ED24 8008E524 3000BF8F */  lw         $ra, 0x30($sp)
    /* 7ED28 8008E528 2C00B78F */  lw         $s7, 0x2C($sp)
    /* 7ED2C 8008E52C 2800B68F */  lw         $s6, 0x28($sp)
    /* 7ED30 8008E530 2400B58F */  lw         $s5, 0x24($sp)
    /* 7ED34 8008E534 2000B48F */  lw         $s4, 0x20($sp)
    /* 7ED38 8008E538 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 7ED3C 8008E53C 1800B28F */  lw         $s2, 0x18($sp)
    /* 7ED40 8008E540 1400B18F */  lw         $s1, 0x14($sp)
    /* 7ED44 8008E544 1000B08F */  lw         $s0, 0x10($sp)
    /* 7ED48 8008E548 0800E003 */  jr         $ra
    /* 7ED4C 8008E54C 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8008E400
