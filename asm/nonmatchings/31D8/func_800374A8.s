nonmatching func_800374A8, 0x4C

glabel func_800374A8
    /* 27CA8 800374A8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* 27CAC 800374AC 1000B0AF */  sw         $s0, 0x10($sp)
    /* 27CB0 800374B0 21808000 */  addu       $s0, $a0, $zero
    /* 27CB4 800374B4 1400BFAF */  sw         $ra, 0x14($sp)
    /* 27CB8 800374B8 51000392 */  lbu        $v1, 0x51($s0)
    /* 27CBC 800374BC 00000000 */  nop
    /* 27CC0 800374C0 80006230 */  andi       $v0, $v1, 0x80
    /* 27CC4 800374C4 07004014 */  bnez       $v0, .L800374E4
    /* 27CC8 800374C8 80006234 */   ori       $v0, $v1, 0x80
    /* 27CCC 800374CC 03000524 */  addiu      $a1, $zero, 0x3
    /* 27CD0 800374D0 21300000 */  addu       $a2, $zero, $zero
    /* 27CD4 800374D4 F2DC000C */  jal        func_800373C8
    /* 27CD8 800374D8 510002A2 */   sb        $v0, 0x51($s0)
    /* 27CDC 800374DC 82000224 */  addiu      $v0, $zero, 0x82
    /* 27CE0 800374E0 510002A2 */  sb         $v0, 0x51($s0)
  .L800374E4:
    /* 27CE4 800374E4 1400BF8F */  lw         $ra, 0x14($sp)
    /* 27CE8 800374E8 1000B08F */  lw         $s0, 0x10($sp)
    /* 27CEC 800374EC 0800E003 */  jr         $ra
    /* 27CF0 800374F0 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_800374A8
