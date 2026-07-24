nonmatching func_8008E5D0, 0xA4

glabel func_8008E5D0
    /* 7EDD0 8008E5D0 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 7EDD4 8008E5D4 1400B1AF */  sw         $s1, 0x14($sp)
    /* 7EDD8 8008E5D8 21888000 */  addu       $s1, $a0, $zero
    /* 7EDDC 8008E5DC 1800B2AF */  sw         $s2, 0x18($sp)
    /* 7EDE0 8008E5E0 2190A000 */  addu       $s2, $a1, $zero
    /* 7EDE4 8008E5E4 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 7EDE8 8008E5E8 1B002012 */  beqz       $s1, .L8008E658
    /* 7EDEC 8008E5EC 1000B0AF */   sw        $s0, 0x10($sp)
    /* 7EDF0 8008E5F0 1A004012 */  beqz       $s2, .L8008E65C
    /* 7EDF4 8008E5F4 21100000 */   addu      $v0, $zero, $zero
    /* 7EDF8 8008E5F8 D039020C */  jal        func_8008E740
    /* 7EDFC 8008E5FC 21202002 */   addu      $a0, $s1, $zero
    /* 7EE00 8008E600 21204002 */  addu       $a0, $s2, $zero
    /* 7EE04 8008E604 D039020C */  jal        func_8008E740
    /* 7EE08 8008E608 21802202 */   addu      $s0, $s1, $v0
    /* 7EE0C 8008E60C 21104202 */  addu       $v0, $s2, $v0
    /* 7EE10 8008E610 11000212 */  beq        $s0, $v0, .L8008E658
    /* 7EE14 8008E614 21182002 */   addu      $v1, $s1, $zero
    /* 7EE18 8008E618 00006280 */  lb         $v0, 0x0($v1)
    /* 7EE1C 8008E61C 00000000 */  nop
    /* 7EE20 8008E620 05004010 */  beqz       $v0, .L8008E638
    /* 7EE24 8008E624 01007124 */   addiu     $s1, $v1, 0x1
  .L8008E628:
    /* 7EE28 8008E628 00002282 */  lb         $v0, 0x0($s1)
    /* 7EE2C 8008E62C 00000000 */  nop
    /* 7EE30 8008E630 FDFF4014 */  bnez       $v0, .L8008E628
    /* 7EE34 8008E634 01003126 */   addiu     $s1, $s1, 0x1
  .L8008E638:
    /* 7EE38 8008E638 FFFF3126 */  addiu      $s1, $s1, -0x1
  .L8008E63C:
    /* 7EE3C 8008E63C 00004292 */  lbu        $v0, 0x0($s2)
    /* 7EE40 8008E640 01005226 */  addiu      $s2, $s2, 0x1
    /* 7EE44 8008E644 000022A2 */  sb         $v0, 0x0($s1)
    /* 7EE48 8008E648 FCFF4014 */  bnez       $v0, .L8008E63C
    /* 7EE4C 8008E64C 01003126 */   addiu     $s1, $s1, 0x1
    /* 7EE50 8008E650 97390208 */  j          .L8008E65C
    /* 7EE54 8008E654 21106000 */   addu      $v0, $v1, $zero
  .L8008E658:
    /* 7EE58 8008E658 21100000 */  addu       $v0, $zero, $zero
  .L8008E65C:
    /* 7EE5C 8008E65C 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 7EE60 8008E660 1800B28F */  lw         $s2, 0x18($sp)
    /* 7EE64 8008E664 1400B18F */  lw         $s1, 0x14($sp)
    /* 7EE68 8008E668 1000B08F */  lw         $s0, 0x10($sp)
    /* 7EE6C 8008E66C 0800E003 */  jr         $ra
    /* 7EE70 8008E670 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8008E5D0
    /* 7EE74 8008E674 00000000 */  nop
    /* 7EE78 8008E678 00000000 */  nop
    /* 7EE7C 8008E67C 00000000 */  nop
