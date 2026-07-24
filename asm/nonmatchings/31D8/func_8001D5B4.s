nonmatching func_8001D5B4, 0xBC

glabel func_8001D5B4
    /* DDB4 8001D5B4 5A028297 */  lhu        $v0, %gp_rel(D_8009B162)($gp)
    /* DDB8 8001D5B8 E8FFBD27 */  addiu      $sp, $sp, -0x18
    /* DDBC 8001D5BC 1000B0AF */  sw         $s0, 0x10($sp)
    /* DDC0 8001D5C0 21808000 */  addu       $s0, $a0, $zero
    /* DDC4 8001D5C4 03004010 */  beqz       $v0, .L8001D5D4
    /* DDC8 8001D5C8 1400BFAF */   sw        $ra, 0x14($sp)
    /* DDCC 8001D5CC 96750008 */  j          .L8001D658
    /* DDD0 8001D5D0 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8001D5D4:
    /* DDD4 8001D5D4 58028583 */  lb         $a1, %gp_rel(D_8009B160)($gp)
    /* DDD8 8001D5D8 2290000C */  jal        func_80024088
    /* DDDC 8001D5DC 21200002 */   addu      $a0, $s0, $zero
    /* DDE0 8001D5E0 03004010 */  beqz       $v0, .L8001D5F0
    /* DDE4 8001D5E4 FFFF0224 */   addiu     $v0, $zero, -0x1
  .L8001D5E8:
    /* DDE8 8001D5E8 98750008 */  j          .L8001D660
    /* DDEC 8001D5EC 01000224 */   addiu     $v0, $zero, 0x1
  .L8001D5F0:
    /* DDF0 8001D5F0 CF028383 */  lb         $v1, %gp_rel(D_8009B1D7)($gp)
    /* DDF4 8001D5F4 580282A3 */  sb         $v0, %gp_rel(D_8009B160)($gp)
    /* DDF8 8001D5F8 10000282 */  lb         $v0, 0x10($s0)
    /* DDFC 8001D5FC 00000000 */  nop
    /* DE00 8001D600 0A006210 */  beq        $v1, $v0, .L8001D62C
    /* DE04 8001D604 01000224 */   addiu     $v0, $zero, 0x1
    /* DE08 8001D608 580282A3 */  sb         $v0, %gp_rel(D_8009B160)($gp)
    /* DE0C 8001D60C 10000282 */  lb         $v0, 0x10($s0)
    /* DE10 8001D610 00000000 */  nop
    /* DE14 8001D614 2A106200 */  slt        $v0, $v1, $v0
    /* DE18 8001D618 F3FF4010 */  beqz       $v0, .L8001D5E8
    /* DE1C 8001D61C 03000224 */   addiu     $v0, $zero, 0x3
    /* DE20 8001D620 580282A3 */  sb         $v0, %gp_rel(D_8009B160)($gp)
    /* DE24 8001D624 98750008 */  j          .L8001D660
    /* DE28 8001D628 01000224 */   addiu     $v0, $zero, 0x1
  .L8001D62C:
    /* DE2C 8001D62C CE028383 */  lb         $v1, %gp_rel(D_8009B1D6)($gp)
    /* DE30 8001D630 0F000282 */  lb         $v0, 0xF($s0)
    /* DE34 8001D634 00000000 */  nop
    /* DE38 8001D638 09006210 */  beq        $v1, $v0, .L8001D660
    /* DE3C 8001D63C 21100000 */   addu      $v0, $zero, $zero
    /* DE40 8001D640 580280A3 */  sb         $zero, %gp_rel(D_8009B160)($gp)
    /* DE44 8001D644 0F000282 */  lb         $v0, 0xF($s0)
    /* DE48 8001D648 00000000 */  nop
    /* DE4C 8001D64C 2A106200 */  slt        $v0, $v1, $v0
    /* DE50 8001D650 E5FF4010 */  beqz       $v0, .L8001D5E8
    /* DE54 8001D654 02000224 */   addiu     $v0, $zero, 0x2
  .L8001D658:
    /* DE58 8001D658 580282A3 */  sb         $v0, %gp_rel(D_8009B160)($gp)
    /* DE5C 8001D65C 01000224 */  addiu      $v0, $zero, 0x1
  .L8001D660:
    /* DE60 8001D660 1400BF8F */  lw         $ra, 0x14($sp)
    /* DE64 8001D664 1000B08F */  lw         $s0, 0x10($sp)
    /* DE68 8001D668 0800E003 */  jr         $ra
    /* DE6C 8001D66C 1800BD27 */   addiu     $sp, $sp, 0x18
endlabel func_8001D5B4
