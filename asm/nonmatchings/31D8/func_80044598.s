nonmatching func_80044598, 0x70

glabel func_80044598
    /* 34D98 80044598 D8FFBD27 */  addiu      $sp, $sp, -0x28
    /* 34D9C 8004459C 1C00B3AF */  sw         $s3, 0x1C($sp)
    /* 34DA0 800445A0 21988000 */  addu       $s3, $a0, $zero
    /* 34DA4 800445A4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 34DA8 800445A8 2188A000 */  addu       $s1, $a1, $zero
    /* 34DAC 800445AC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 34DB0 800445B0 2190C000 */  addu       $s2, $a2, $zero
    /* 34DB4 800445B4 1000B0AF */  sw         $s0, 0x10($sp)
    /* 34DB8 800445B8 21800000 */  addu       $s0, $zero, $zero
    /* 34DBC 800445BC 0A00401A */  blez       $s2, .L800445E8
    /* 34DC0 800445C0 2000BFAF */   sw        $ra, 0x20($sp)
  .L800445C4:
    /* 34DC4 800445C4 21202002 */  addu       $a0, $s1, $zero
    /* 34DC8 800445C8 A039020C */  jal        func_8008E680
    /* 34DCC 800445CC 21286002 */   addu      $a1, $s3, $zero
    /* 34DD0 800445D0 06004010 */  beqz       $v0, .L800445EC
    /* 34DD4 800445D4 21100002 */   addu      $v0, $s0, $zero
    /* 34DD8 800445D8 01001026 */  addiu      $s0, $s0, 0x1
    /* 34DDC 800445DC 2A101202 */  slt        $v0, $s0, $s2
    /* 34DE0 800445E0 F8FF4014 */  bnez       $v0, .L800445C4
    /* 34DE4 800445E4 28003126 */   addiu     $s1, $s1, 0x28
  .L800445E8:
    /* 34DE8 800445E8 FFFF0224 */  addiu      $v0, $zero, -0x1
  .L800445EC:
    /* 34DEC 800445EC 2000BF8F */  lw         $ra, 0x20($sp)
    /* 34DF0 800445F0 1C00B38F */  lw         $s3, 0x1C($sp)
    /* 34DF4 800445F4 1800B28F */  lw         $s2, 0x18($sp)
    /* 34DF8 800445F8 1400B18F */  lw         $s1, 0x14($sp)
    /* 34DFC 800445FC 1000B08F */  lw         $s0, 0x10($sp)
    /* 34E00 80044600 0800E003 */  jr         $ra
    /* 34E04 80044604 2800BD27 */   addiu     $sp, $sp, 0x28
endlabel func_80044598
