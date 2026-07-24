nonmatching func_8005C464, 0x8C

glabel func_8005C464
    /* 4CC64 8005C464 D0FFBD27 */  addiu      $sp, $sp, -0x30
    /* 4CC68 8005C468 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 4CC6C 8005C46C 2188A000 */  addu       $s1, $a1, $zero
    /* 4CC70 8005C470 2400B3AF */  sw         $s3, 0x24($sp)
    /* 4CC74 8005C474 2198C000 */  addu       $s3, $a2, $zero
    /* 4CC78 8005C478 2000B2AF */  sw         $s2, 0x20($sp)
    /* 4CC7C 8005C47C 2190E000 */  addu       $s2, $a3, $zero
    /* 4CC80 8005C480 0F80023C */  lui        $v0, %hi(D_800F5750)
    /* 4CC84 8005C484 1800B0AF */  sw         $s0, 0x18($sp)
    /* 4CC88 8005C488 50575024 */  addiu      $s0, $v0, %lo(D_800F5750)
    /* 4CC8C 8005C48C 2800BFAF */  sw         $ra, 0x28($sp)
    /* 4CC90 8005C490 3C71010C */  jal        func_8005C4F0
    /* 4CC94 8005C494 21280002 */   addu      $a1, $s0, $zero
    /* 4CC98 8005C498 0E004014 */  bnez       $v0, .L8005C4D4
    /* 4CC9C 8005C49C FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 4CCA0 8005C4A0 C4F9010C */  jal        func_8007E710
    /* 4CCA4 8005C4A4 21200002 */   addu      $a0, $s0, $zero
    /* 4CCA8 8005C4A8 21200002 */  addu       $a0, $s0, $zero
    /* 4CCAC 8005C4AC 21282002 */  addu       $a1, $s1, $zero
    /* 4CCB0 8005C4B0 0400878C */  lw         $a3, 0x4($a0)
    /* 4CCB4 8005C4B4 4000A38F */  lw         $v1, 0x40($sp)
    /* 4CCB8 8005C4B8 21306002 */  addu       $a2, $s3, $zero
    /* 4CCBC 8005C4BC 1000B2AF */  sw         $s2, 0x10($sp)
    /* 4CCC0 8005C4C0 FF07E724 */  addiu      $a3, $a3, 0x7FF
    /* 4CCC4 8005C4C4 C23A0700 */  srl        $a3, $a3, 11
    /* 4CCC8 8005C4C8 21384700 */  addu       $a3, $v0, $a3
    /* 4CCCC 8005C4CC 286E010C */  jal        func_8005B8A0
    /* 4CCD0 8005C4D0 1400A3AF */   sw        $v1, 0x14($sp)
  .L8005C4D4:
    /* 4CCD4 8005C4D4 2800BF8F */  lw         $ra, 0x28($sp)
    /* 4CCD8 8005C4D8 2400B38F */  lw         $s3, 0x24($sp)
    /* 4CCDC 8005C4DC 2000B28F */  lw         $s2, 0x20($sp)
    /* 4CCE0 8005C4E0 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 4CCE4 8005C4E4 1800B08F */  lw         $s0, 0x18($sp)
    /* 4CCE8 8005C4E8 0800E003 */  jr         $ra
    /* 4CCEC 8005C4EC 3000BD27 */   addiu     $sp, $sp, 0x30
endlabel func_8005C464
