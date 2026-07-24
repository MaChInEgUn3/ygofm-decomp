nonmatching func_8003D614, 0x138

glabel func_8003D614
    /* 2DE14 8003D614 B9048393 */  lbu        $v1, %gp_rel(D_8009B3C1)($gp)
    /* 2DE18 8003D618 E0FFBD27 */  addiu      $sp, $sp, -0x20
    /* 2DE1C 8003D61C 1400B1AF */  sw         $s1, 0x14($sp)
    /* 2DE20 8003D620 21888000 */  addu       $s1, $a0, $zero
    /* 2DE24 8003D624 1C00BFAF */  sw         $ra, 0x1C($sp)
    /* 2DE28 8003D628 1800B2AF */  sw         $s2, 0x18($sp)
    /* 2DE2C 8003D62C 80006230 */  andi       $v0, $v1, 0x80
    /* 2DE30 8003D630 08004014 */  bnez       $v0, .L8003D654
    /* 2DE34 8003D634 1000B0AF */   sw        $s0, 0x10($sp)
    /* 2DE38 8003D638 0000308E */  lw         $s0, 0x0($s1)
    /* 2DE3C 8003D63C 80006234 */  ori        $v0, $v1, 0x80
    /* 2DE40 8003D640 B90482A3 */  sb         $v0, %gp_rel(D_8009B3C1)($gp)
    /* 2DE44 8003D644 5E0C010C */  jal        func_80043178
    /* 2DE48 8003D648 21200002 */   addu      $a0, $s0, $zero
    /* 2DE4C 8003D64C 00040224 */  addiu      $v0, $zero, 0x400
    /* 2DE50 8003D650 600002A6 */  sh         $v0, 0x60($s0)
  .L8003D654:
    /* 2DE54 8003D654 1A002292 */  lbu        $v0, 0x1A($s1)
    /* 2DE58 8003D658 0000308E */  lw         $s0, 0x0($s1)
    /* 2DE5C 8003D65C 40180200 */  sll        $v1, $v0, 1
    /* 2DE60 8003D660 21186200 */  addu       $v1, $v1, $v0
    /* 2DE64 8003D664 C0180300 */  sll        $v1, $v1, 3
    /* 2DE68 8003D668 21186200 */  addu       $v1, $v1, $v0
    /* 2DE6C 8003D66C 80180300 */  sll        $v1, $v1, 2
    /* 2DE70 8003D670 0F80023C */  lui        $v0, %hi(D_800EB0F8)
    /* 2DE74 8003D674 F8B04224 */  addiu      $v0, $v0, %lo(D_800EB0F8)
    /* 2DE78 8003D678 14000012 */  beqz       $s0, .L8003D6CC
    /* 2DE7C 8003D67C 21906200 */   addu      $s2, $v1, $v0
    /* 2DE80 8003D680 60000296 */  lhu        $v0, 0x60($s0)
    /* 2DE84 8003D684 00000000 */  nop
    /* 2DE88 8003D688 C0FF4224 */  addiu      $v0, $v0, -0x40
    /* 2DE8C 8003D68C 600002A6 */  sh         $v0, 0x60($s0)
    /* 2DE90 8003D690 00140200 */  sll        $v0, $v0, 16
    /* 2DE94 8003D694 033C0200 */  sra        $a3, $v0, 16
    /* 2DE98 8003D698 0500E01C */  bgtz       $a3, .L8003D6B0
    /* 2DE9C 8003D69C 21200002 */   addu      $a0, $s0, $zero
    /* 2DEA0 8003D6A0 DB00010C */  jal        func_8004036C
    /* 2DEA4 8003D6A4 21200002 */   addu      $a0, $s0, $zero
    /* 2DEA8 8003D6A8 B3F50008 */  j          .L8003D6CC
    /* 2DEAC 8003D6AC 000020AE */   sw        $zero, 0x0($s1)
  .L8003D6B0:
    /* 2DEB0 8003D6B0 20000524 */  addiu      $a1, $zero, 0x20
    /* 2DEB4 8003D6B4 8C0C010C */  jal        func_80043230
    /* 2DEB8 8003D6B8 C0FF0624 */   addiu     $a2, $zero, -0x40
    /* 2DEBC 8003D6BC 30000586 */  lh         $a1, 0x30($s0)
    /* 2DEC0 8003D6C0 32000686 */  lh         $a2, 0x32($s0)
    /* 2DEC4 8003D6C4 4DE6000C */  jal        func_80039934
    /* 2DEC8 8003D6C8 21204002 */   addu      $a0, $s2, $zero
  .L8003D6CC:
    /* 2DECC 8003D6CC 0400308E */  lw         $s0, 0x4($s1)
    /* 2DED0 8003D6D0 00000000 */  nop
    /* 2DED4 8003D6D4 0E000012 */  beqz       $s0, .L8003D710
    /* 2DED8 8003D6D8 00000000 */   nop
    /* 2DEDC 8003D6DC 4A000396 */  lhu        $v1, 0x4A($s0)
    /* 2DEE0 8003D6E0 48000296 */  lhu        $v0, 0x48($s0)
    /* 2DEE4 8003D6E4 08006324 */  addiu      $v1, $v1, 0x8
    /* 2DEE8 8003D6E8 08004224 */  addiu      $v0, $v0, 0x8
    /* 2DEEC 8003D6EC 480002A6 */  sh         $v0, 0x48($s0)
    /* 2DEF0 8003D6F0 00140200 */  sll        $v0, $v0, 16
    /* 2DEF4 8003D6F4 03140200 */  sra        $v0, $v0, 16
    /* 2DEF8 8003D6F8 C0004228 */  slti       $v0, $v0, 0xC0
    /* 2DEFC 8003D6FC 04004014 */  bnez       $v0, .L8003D710
    /* 2DF00 8003D700 4A0003A6 */   sh        $v1, 0x4A($s0)
    /* 2DF04 8003D704 DB00010C */  jal        func_8004036C
    /* 2DF08 8003D708 21200002 */   addu      $a0, $s0, $zero
    /* 2DF0C 8003D70C 040020AE */  sw         $zero, 0x4($s1)
  .L8003D710:
    /* 2DF10 8003D710 0000228E */  lw         $v0, 0x0($s1)
    /* 2DF14 8003D714 00000000 */  nop
    /* 2DF18 8003D718 06004014 */  bnez       $v0, .L8003D734
    /* 2DF1C 8003D71C 00000000 */   nop
    /* 2DF20 8003D720 0400228E */  lw         $v0, 0x4($s1)
    /* 2DF24 8003D724 00000000 */  nop
    /* 2DF28 8003D728 02004014 */  bnez       $v0, .L8003D734
    /* 2DF2C 8003D72C 00000000 */   nop
    /* 2DF30 8003D730 B90480A3 */  sb         $zero, %gp_rel(D_8009B3C1)($gp)
  .L8003D734:
    /* 2DF34 8003D734 1C00BF8F */  lw         $ra, 0x1C($sp)
    /* 2DF38 8003D738 1800B28F */  lw         $s2, 0x18($sp)
    /* 2DF3C 8003D73C 1400B18F */  lw         $s1, 0x14($sp)
    /* 2DF40 8003D740 1000B08F */  lw         $s0, 0x10($sp)
    /* 2DF44 8003D744 0800E003 */  jr         $ra
    /* 2DF48 8003D748 2000BD27 */   addiu     $sp, $sp, 0x20
endlabel func_8003D614
