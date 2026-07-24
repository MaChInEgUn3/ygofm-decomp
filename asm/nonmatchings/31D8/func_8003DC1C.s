nonmatching func_8003DC1C, 0x850

glabel func_8003DC1C
    /* 2E41C 8003DC1C C8FFBD27 */  addiu      $sp, $sp, -0x38
    /* 2E420 8003DC20 D5048393 */  lbu        $v1, %gp_rel(D_8009B3DD)($gp)
    /* 2E424 8003DC24 0F80023C */  lui        $v0, %hi(D_800EF6D0)
    /* 2E428 8003DC28 2000B2AF */  sw         $s2, 0x20($sp)
    /* 2E42C 8003DC2C D0F65224 */  addiu      $s2, $v0, %lo(D_800EF6D0)
    /* 2E430 8003DC30 2C00B5AF */  sw         $s5, 0x2C($sp)
    /* 2E434 8003DC34 2400B3AF */  sw         $s3, 0x24($sp)
    /* 2E438 8003DC38 80100300 */  sll        $v0, $v1, 2
    /* 2E43C 8003DC3C 21104300 */  addu       $v0, $v0, $v1
    /* 2E440 8003DC40 80100200 */  sll        $v0, $v0, 2
    /* 2E444 8003DC44 23104300 */  subu       $v0, $v0, $v1
    /* 2E448 8003DC48 80100200 */  sll        $v0, $v0, 2
    /* 2E44C 8003DC4C 21104300 */  addu       $v0, $v0, $v1
    /* 2E450 8003DC50 C0100200 */  sll        $v0, $v0, 3
    /* 2E454 8003DC54 1C004326 */  addiu      $v1, $s2, 0x1C
    /* 2E458 8003DC58 21984300 */  addu       $s3, $v0, $v1
    /* 2E45C 8003DC5C C4048297 */  lhu        $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E460 8003DC60 21A80000 */  addu       $s5, $zero, $zero
    /* 2E464 8003DC64 3000BFAF */  sw         $ra, 0x30($sp)
    /* 2E468 8003DC68 2800B4AF */  sw         $s4, 0x28($sp)
    /* 2E46C 8003DC6C 1C00B1AF */  sw         $s1, 0x1C($sp)
    /* 2E470 8003DC70 00204230 */  andi       $v0, $v0, 0x2000
    /* 2E474 8003DC74 19004010 */  beqz       $v0, .L8003DCDC
    /* 2E478 8003DC78 1800B0AF */   sw        $s0, 0x18($sp)
    /* 2E47C 8003DC7C 0A80023C */  lui        $v0, %hi(D_8009B440)
    /* 2E480 8003DC80 40B4428C */  lw         $v0, %lo(D_8009B440)($v0)
    /* 2E484 8003DC84 00000000 */  nop
    /* 2E488 8003DC88 2A10A202 */  slt        $v0, $s5, $v0
    /* 2E48C 8003DC8C 0F004010 */  beqz       $v0, .L8003DCCC
    /* 2E490 8003DC90 2188A002 */   addu      $s1, $s5, $zero
    /* 2E494 8003DC94 0A80143C */  lui        $s4, %hi(D_8009AF6C)
    /* 2E498 8003DC98 2180A002 */  addu       $s0, $s5, $zero
  .L8003DC9C:
    /* 2E49C 8003DC9C 6CAF8426 */  addiu      $a0, $s4, %lo(D_8009AF6C)
    /* 2E4A0 8003DCA0 0A80053C */  lui        $a1, %hi(D_8009B444)
    /* 2E4A4 8003DCA4 44B4A58C */  lw         $a1, %lo(D_8009B444)($a1)
    /* 2E4A8 8003DCA8 01003126 */  addiu      $s1, $s1, 0x1
    /* 2E4AC 8003DCAC E1FB010C */  jal        func_8007EF84
    /* 2E4B0 8003DCB0 2128B000 */   addu      $a1, $a1, $s0
    /* 2E4B4 8003DCB4 0A80023C */  lui        $v0, %hi(D_8009B440)
    /* 2E4B8 8003DCB8 40B4428C */  lw         $v0, %lo(D_8009B440)($v0)
    /* 2E4BC 8003DCBC 00000000 */  nop
    /* 2E4C0 8003DCC0 2A102202 */  slt        $v0, $s1, $v0
    /* 2E4C4 8003DCC4 F5FF4014 */  bnez       $v0, .L8003DC9C
    /* 2E4C8 8003DCC8 28001026 */   addiu     $s0, $s0, 0x28
  .L8003DCCC:
    /* 2E4CC 8003DCCC 0C006592 */  lbu        $a1, 0xC($s3)
    /* 2E4D0 8003DCD0 0180043C */  lui        $a0, %hi(D_80010378)
    /* 2E4D4 8003DCD4 E1FB010C */  jal        func_8007EF84
    /* 2E4D8 8003DCD8 78038424 */   addiu     $a0, $a0, %lo(D_80010378)
  .L8003DCDC:
    /* 2E4DC 8003DCDC C4048297 */  lhu        $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E4E0 8003DCE0 00000000 */  nop
    /* 2E4E4 8003DCE4 00404230 */  andi       $v0, $v0, 0x4000
    /* 2E4E8 8003DCE8 06004010 */  beqz       $v0, .L8003DD04
    /* 2E4EC 8003DCEC FFFF1024 */   addiu     $s0, $zero, -0x1
    /* 2E4F0 8003DCF0 DC048527 */  addiu      $a1, $gp, %gp_rel(D_8009B3E4)
    /* 2E4F4 8003DCF4 C0048627 */  addiu      $a2, $gp, %gp_rel(D_8009B3C8)
    /* 2E4F8 8003DCF8 0E12010C */  jal        func_80044838
    /* 2E4FC 8003DCFC 01000424 */   addiu     $a0, $zero, 0x1
    /* 2E500 8003DD00 21804000 */  addu       $s0, $v0, $zero
  .L8003DD04:
    /* 2E504 8003DD04 C4048297 */  lhu        $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E508 8003DD08 00000000 */  nop
    /* 2E50C 8003DD0C 00104230 */  andi       $v0, $v0, 0x1000
    /* 2E510 8003DD10 67004010 */  beqz       $v0, .L8003DEB0
    /* 2E514 8003DD14 00000000 */   nop
    /* 2E518 8003DD18 65000012 */  beqz       $s0, .L8003DEB0
    /* 2E51C 8003DD1C 01000224 */   addiu     $v0, $zero, 0x1
    /* 2E520 8003DD20 63000216 */  bne        $s0, $v0, .L8003DEB0
    /* 2E524 8003DD24 00000000 */   nop
    /* 2E528 8003DD28 DC04828F */  lw         $v0, %gp_rel(D_8009B3E4)($gp)
    /* 2E52C 8003DD2C 00000000 */  nop
    /* 2E530 8003DD30 FEFF4324 */  addiu      $v1, $v0, -0x2
    /* 2E534 8003DD34 0B00622C */  sltiu      $v0, $v1, 0xB
    /* 2E538 8003DD38 5D004010 */  beqz       $v0, .L8003DEB0
    /* 2E53C 8003DD3C 0180023C */   lui       $v0, %hi(jtbl_800103B0)
    /* 2E540 8003DD40 B0034224 */  addiu      $v0, $v0, %lo(jtbl_800103B0)
    /* 2E544 8003DD44 80180300 */  sll        $v1, $v1, 2
    /* 2E548 8003DD48 21186200 */  addu       $v1, $v1, $v0
    /* 2E54C 8003DD4C 0000628C */  lw         $v0, 0x0($v1)
    /* 2E550 8003DD50 00000000 */  nop
    /* 2E554 8003DD54 08004000 */  jr         $v0
    /* 2E558 8003DD58 00000000 */   nop
  jlabel .L8003DD5C
    /* 2E55C 8003DD5C 01000524 */  addiu      $a1, $zero, 0x1
    /* 2E560 8003DD60 C4048497 */  lhu        $a0, %gp_rel(D_8009B3CC)($gp)
    /* 2E564 8003DD64 C004838F */  lw         $v1, %gp_rel(D_8009B3C8)($gp)
    /* 2E568 8003DD68 00208234 */  ori        $v0, $a0, 0x2000
    /* 2E56C 8003DD6C C40482A7 */  sh         $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E570 8003DD70 18006510 */  beq        $v1, $a1, .L8003DDD4
    /* 2E574 8003DD74 02006228 */   slti      $v0, $v1, 0x2
    /* 2E578 8003DD78 05004010 */  beqz       $v0, .L8003DD90
    /* 2E57C 8003DD7C 03000224 */   addiu     $v0, $zero, 0x3
    /* 2E580 8003DD80 0B006010 */  beqz       $v1, .L8003DDB0
    /* 2E584 8003DD84 02000224 */   addiu     $v0, $zero, 0x2
    /* 2E588 8003DD88 76F70008 */  j          .L8003DDD8
    /* 2E58C 8003DD8C 00000000 */   nop
  .L8003DD90:
    /* 2E590 8003DD90 05006210 */  beq        $v1, $v0, .L8003DDA8
    /* 2E594 8003DD94 04000224 */   addiu     $v0, $zero, 0x4
    /* 2E598 8003DD98 09006210 */  beq        $v1, $v0, .L8003DDC0
    /* 2E59C 8003DD9C 02000224 */   addiu     $v0, $zero, 0x2
    /* 2E5A0 8003DDA0 76F70008 */  j          .L8003DDD8
    /* 2E5A4 8003DDA4 00000000 */   nop
  .L8003DDA8:
    /* 2E5A8 8003DDA8 00288234 */  ori        $v0, $a0, 0x2800
    /* 2E5AC 8003DDAC C40482A7 */  sh         $v0, %gp_rel(D_8009B3CC)($gp)
  .L8003DDB0:
    /* 2E5B0 8003DDB0 0A80023C */  lui        $v0, %hi(D_8009B438)
    /* 2E5B4 8003DDB4 38B44290 */  lbu        $v0, %lo(D_8009B438)($v0)
    /* 2E5B8 8003DDB8 ABF70008 */  j          .L8003DEAC
    /* 2E5BC 8003DDBC 0C0062A2 */   sb        $v0, 0xC($s3)
  .L8003DDC0:
    /* 2E5C0 8003DDC0 02208234 */  ori        $v0, $a0, 0x2002
    /* 2E5C4 8003DDC4 C40482A7 */  sh         $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E5C8 8003DDC8 CD0485A3 */  sb         $a1, %gp_rel(D_8009B3D5)($gp)
    /* 2E5CC 8003DDCC ACF70008 */  j          .L8003DEB0
    /* 2E5D0 8003DDD0 00000000 */   nop
  .L8003DDD4:
    /* 2E5D4 8003DDD4 02000224 */  addiu      $v0, $zero, 0x2
  .L8003DDD8:
    /* 2E5D8 8003DDD8 CD0482A3 */  sb         $v0, %gp_rel(D_8009B3D5)($gp)
    /* 2E5DC 8003DDDC ACF70008 */  j          .L8003DEB0
    /* 2E5E0 8003DDE0 00000000 */   nop
  jlabel .L8003DDE4
    /* 2E5E4 8003DDE4 C004828F */  lw         $v0, %gp_rel(D_8009B3C8)($gp)
    /* 2E5E8 8003DDE8 00000000 */  nop
    /* 2E5EC 8003DDEC 27004014 */  bnez       $v0, .L8003DE8C
    /* 2E5F0 8003DDF0 01000224 */   addiu     $v0, $zero, 0x1
    /* 2E5F4 8003DDF4 16005186 */  lh         $s1, 0x16($s2)
    /* 2E5F8 8003DDF8 12004296 */  lhu        $v0, 0x12($s2)
    /* 2E5FC 8003DDFC 00000000 */  nop
    /* 2E600 8003DE00 23105100 */  subu       $v0, $v0, $s1
    /* 2E604 8003DE04 120042A6 */  sh         $v0, 0x12($s2)
    /* 2E608 8003DE08 00140200 */  sll        $v0, $v0, 16
    /* 2E60C 8003DE0C 27004018 */  blez       $v0, .L8003DEAC
    /* 2E610 8003DE10 00000000 */   nop
    /* 2E614 8003DE14 0000628E */  lw         $v0, 0x0($s3)
    /* 2E618 8003DE18 97F70008 */  j          .L8003DE5C
    /* 2E61C 8003DE1C 21105100 */   addu      $v0, $v0, $s1
  jlabel .L8003DE20
    /* 2E620 8003DE20 C004828F */  lw         $v0, %gp_rel(D_8009B3C8)($gp)
    /* 2E624 8003DE24 00000000 */  nop
    /* 2E628 8003DE28 18004014 */  bnez       $v0, .L8003DE8C
    /* 2E62C 8003DE2C 01000224 */   addiu     $v0, $zero, 0x1
    /* 2E630 8003DE30 16005186 */  lh         $s1, 0x16($s2)
    /* 2E634 8003DE34 12004296 */  lhu        $v0, 0x12($s2)
    /* 2E638 8003DE38 00000000 */  nop
    /* 2E63C 8003DE3C 23105100 */  subu       $v0, $v0, $s1
    /* 2E640 8003DE40 120042A6 */  sh         $v0, 0x12($s2)
    /* 2E644 8003DE44 00140200 */  sll        $v0, $v0, 16
    /* 2E648 8003DE48 18004018 */  blez       $v0, .L8003DEAC
    /* 2E64C 8003DE4C 00000000 */   nop
    /* 2E650 8003DE50 0000628E */  lw         $v0, 0x0($s3)
    /* 2E654 8003DE54 00000000 */  nop
    /* 2E658 8003DE58 21105100 */  addu       $v0, $v0, $s1
  .L8003DE5C:
    /* 2E65C 8003DE5C 000062AE */  sw         $v0, 0x0($s3)
    /* 2E660 8003DE60 14004296 */  lhu        $v0, 0x14($s2)
    /* 2E664 8003DE64 12004386 */  lh         $v1, 0x12($s2)
    /* 2E668 8003DE68 16004486 */  lh         $a0, 0x16($s2)
    /* 2E66C 8003DE6C 21105100 */  addu       $v0, $v0, $s1
    /* 2E670 8003DE70 2A186400 */  slt        $v1, $v1, $a0
    /* 2E674 8003DE74 140042A6 */  sh         $v0, 0x14($s2)
    /* 2E678 8003DE78 12004296 */  lhu        $v0, 0x12($s2)
    /* 2E67C 8003DE7C 0C006010 */  beqz       $v1, .L8003DEB0
    /* 2E680 8003DE80 00000000 */   nop
    /* 2E684 8003DE84 ACF70008 */  j          .L8003DEB0
    /* 2E688 8003DE88 160042A6 */   sh        $v0, 0x16($s2)
  .L8003DE8C:
    /* 2E68C 8003DE8C CD0482A3 */  sb         $v0, %gp_rel(D_8009B3D5)($gp)
    /* 2E690 8003DE90 ACF70008 */  j          .L8003DEB0
    /* 2E694 8003DE94 00000000 */   nop
  jlabel .L8003DE98
    /* 2E698 8003DE98 C004838F */  lw         $v1, %gp_rel(D_8009B3C8)($gp)
    /* 2E69C 8003DE9C 01000224 */  addiu      $v0, $zero, 0x1
    /* 2E6A0 8003DEA0 CD0482A3 */  sb         $v0, %gp_rel(D_8009B3D5)($gp)
    /* 2E6A4 8003DEA4 02006014 */  bnez       $v1, .L8003DEB0
    /* 2E6A8 8003DEA8 00000000 */   nop
  .L8003DEAC:
    /* 2E6AC 8003DEAC CD0480A3 */  sb         $zero, %gp_rel(D_8009B3D5)($gp)
  jlabel .L8003DEB0
    /* 2E6B0 8003DEB0 B9048293 */  lbu        $v0, %gp_rel(D_8009B3C1)($gp)
    /* 2E6B4 8003DEB4 00000000 */  nop
    /* 2E6B8 8003DEB8 0F004330 */  andi       $v1, $v0, 0xF
    /* 2E6BC 8003DEBC 0A006010 */  beqz       $v1, .L8003DEE8
    /* 2E6C0 8003DEC0 21204002 */   addu      $a0, $s2, $zero
    /* 2E6C4 8003DEC4 01001024 */  addiu      $s0, $zero, 0x1
    /* 2E6C8 8003DEC8 0980023C */  lui        $v0, %hi(D_80090F88)
    /* 2E6CC 8003DECC 880F4224 */  addiu      $v0, $v0, %lo(D_80090F88)
    /* 2E6D0 8003DED0 80180300 */  sll        $v1, $v1, 2
    /* 2E6D4 8003DED4 21186200 */  addu       $v1, $v1, $v0
    /* 2E6D8 8003DED8 0000628C */  lw         $v0, 0x0($v1)
    /* 2E6DC 8003DEDC 00000000 */  nop
    /* 2E6E0 8003DEE0 09F84000 */  jalr       $v0
    /* 2E6E4 8003DEE4 21286002 */   addu      $a1, $s3, $zero
  .L8003DEE8:
    /* 2E6E8 8003DEE8 57010106 */  bgez       $s0, .L8003E448
    /* 2E6EC 8003DEEC 00000000 */   nop
    /* 2E6F0 8003DEF0 C4048297 */  lhu        $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E6F4 8003DEF4 00000000 */  nop
    /* 2E6F8 8003DEF8 00044230 */  andi       $v0, $v0, 0x400
    /* 2E6FC 8003DEFC 17004010 */  beqz       $v0, .L8003DF5C
    /* 2E700 8003DF00 00000000 */   nop
    /* 2E704 8003DF04 1A004292 */  lbu        $v0, 0x1A($s2)
    /* 2E708 8003DF08 00000000 */  nop
    /* 2E70C 8003DF0C 40800200 */  sll        $s0, $v0, 1
    /* 2E710 8003DF10 21800202 */  addu       $s0, $s0, $v0
    /* 2E714 8003DF14 C0801000 */  sll        $s0, $s0, 3
    /* 2E718 8003DF18 21800202 */  addu       $s0, $s0, $v0
    /* 2E71C 8003DF1C 80801000 */  sll        $s0, $s0, 2
    /* 2E720 8003DF20 0F80023C */  lui        $v0, %hi(D_800EB0F8)
    /* 2E724 8003DF24 F8B04224 */  addiu      $v0, $v0, %lo(D_800EB0F8)
    /* 2E728 8003DF28 E5E5000C */  jal        func_80039794
    /* 2E72C 8003DF2C 21800202 */   addu      $s0, $s0, $v0
    /* 2E730 8003DF30 3400028E */  lw         $v0, 0x34($s0)
    /* 2E734 8003DF34 00200324 */  addiu      $v1, $zero, 0x2000
    /* 2E738 8003DF38 08204230 */  andi       $v0, $v0, 0x2008
    /* 2E73C 8003DF3C 42014314 */  bne        $v0, $v1, .L8003E448
    /* 2E740 8003DF40 00000000 */   nop
    /* 2E744 8003DF44 C4048297 */  lhu        $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E748 8003DF48 00000000 */  nop
    /* 2E74C 8003DF4C FFFB4230 */  andi       $v0, $v0, 0xFBFF
    /* 2E750 8003DF50 C40482A7 */  sh         $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E754 8003DF54 12F90008 */  j          .L8003E448
    /* 2E758 8003DF58 00000000 */   nop
  .L8003DF5C:
    /* 2E75C 8003DF5C C7048293 */  lbu        $v0, %gp_rel(D_8009B3CF)($gp)
    /* 2E760 8003DF60 00000000 */  nop
    /* 2E764 8003DF64 0F004330 */  andi       $v1, $v0, 0xF
    /* 2E768 8003DF68 0B00622C */  sltiu      $v0, $v1, 0xB
    /* 2E76C 8003DF6C 36014010 */  beqz       $v0, .L8003E448
    /* 2E770 8003DF70 0180023C */   lui       $v0, %hi(jtbl_800103E0)
    /* 2E774 8003DF74 E0034224 */  addiu      $v0, $v0, %lo(jtbl_800103E0)
    /* 2E778 8003DF78 80180300 */  sll        $v1, $v1, 2
    /* 2E77C 8003DF7C 21186200 */  addu       $v1, $v1, $v0
    /* 2E780 8003DF80 0000628C */  lw         $v0, 0x0($v1)
    /* 2E784 8003DF84 00000000 */  nop
    /* 2E788 8003DF88 08004000 */  jr         $v0
    /* 2E78C 8003DF8C 00000000 */   nop
  jlabel .L8003DF90
    /* 2E790 8003DF90 C7048393 */  lbu        $v1, %gp_rel(D_8009B3CF)($gp)
    /* 2E794 8003DF94 00000000 */  nop
    /* 2E798 8003DF98 80006230 */  andi       $v0, $v1, 0x80
    /* 2E79C 8003DF9C 06004014 */  bnez       $v0, .L8003DFB8
    /* 2E7A0 8003DFA0 80006234 */   ori       $v0, $v1, 0x80
    /* 2E7A4 8003DFA4 C70482A3 */  sb         $v0, %gp_rel(D_8009B3CF)($gp)
    /* 2E7A8 8003DFA8 01000224 */  addiu      $v0, $zero, 0x1
    /* 2E7AC 8003DFAC B90482A3 */  sb         $v0, %gp_rel(D_8009B3C1)($gp)
    /* 2E7B0 8003DFB0 12F90008 */  j          .L8003E448
    /* 2E7B4 8003DFB4 00000000 */   nop
  .L8003DFB8:
    /* 2E7B8 8003DFB8 0A80023C */  lui        $v0, %hi(D_8009B34D)
    /* 2E7BC 8003DFBC 4DB34280 */  lb         $v0, %lo(D_8009B34D)($v0)
    /* 2E7C0 8003DFC0 00000000 */  nop
    /* 2E7C4 8003DFC4 04004010 */  beqz       $v0, .L8003DFD8
    /* 2E7C8 8003DFC8 02000224 */   addiu     $v0, $zero, 0x2
    /* 2E7CC 8003DFCC B90482A3 */  sb         $v0, %gp_rel(D_8009B3C1)($gp)
    /* 2E7D0 8003DFD0 12F90008 */  j          .L8003E448
    /* 2E7D4 8003DFD4 00000000 */   nop
  .L8003DFD8:
    /* 2E7D8 8003DFD8 8C0F010C */  jal        func_80043E30
    /* 2E7DC 8003DFDC 01000424 */   addiu     $a0, $zero, 0x1
    /* 2E7E0 8003DFE0 AF0F010C */  jal        func_80043EBC
    /* 2E7E4 8003DFE4 00000000 */   nop
    /* 2E7E8 8003DFE8 C4048297 */  lhu        $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E7EC 8003DFEC 01000324 */  addiu      $v1, $zero, 0x1
    /* 2E7F0 8003DFF0 C70483A3 */  sb         $v1, %gp_rel(D_8009B3CF)($gp)
    /* 2E7F4 8003DFF4 00404234 */  ori        $v0, $v0, 0x4000
    /* 2E7F8 8003DFF8 C40482A7 */  sh         $v0, %gp_rel(D_8009B3CC)($gp)
  jlabel .L8003DFFC
    /* 2E7FC 8003DFFC C7048393 */  lbu        $v1, %gp_rel(D_8009B3CF)($gp)
    /* 2E800 8003E000 00000000 */  nop
    /* 2E804 8003E004 80006230 */  andi       $v0, $v1, 0x80
    /* 2E808 8003E008 0A004014 */  bnez       $v0, .L8003E034
    /* 2E80C 8003E00C 04000224 */   addiu     $v0, $zero, 0x4
    /* 2E810 8003E010 C4048297 */  lhu        $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E814 8003E014 80006334 */  ori        $v1, $v1, 0x80
    /* 2E818 8003E018 C70483A3 */  sb         $v1, %gp_rel(D_8009B3CF)($gp)
    /* 2E81C 8003E01C 00104234 */  ori        $v0, $v0, 0x1000
    /* 2E820 8003E020 C40482A7 */  sh         $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E824 8003E024 4F10010C */  jal        func_8004413C
    /* 2E828 8003E028 2120A002 */   addu      $a0, $s5, $zero
    /* 2E82C 8003E02C 12F90008 */  j          .L8003E448
    /* 2E830 8003E030 00000000 */   nop
  .L8003E034:
    /* 2E834 8003E034 C70482A3 */  sb         $v0, %gp_rel(D_8009B3CF)($gp)
  jlabel .L8003E038
    /* 2E838 8003E038 C4048397 */  lhu        $v1, %gp_rel(D_8009B3CC)($gp)
    /* 2E83C 8003E03C 00000000 */  nop
    /* 2E840 8003E040 00206230 */  andi       $v0, $v1, 0x2000
    /* 2E844 8003E044 00014010 */  beqz       $v0, .L8003E448
    /* 2E848 8003E048 FFEF6230 */   andi      $v0, $v1, 0xEFFF
    /* 2E84C 8003E04C CD048393 */  lbu        $v1, %gp_rel(D_8009B3D5)($gp)
    /* 2E850 8003E050 C40482A7 */  sh         $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E854 8003E054 02000224 */  addiu      $v0, $zero, 0x2
    /* 2E858 8003E058 D7006210 */  beq        $v1, $v0, .L8003E3B8
    /* 2E85C 8003E05C D2000424 */   addiu     $a0, $zero, 0xD2
    /* 2E860 8003E060 BF048293 */  lbu        $v0, %gp_rel(D_8009B3C7)($gp)
    /* 2E864 8003E064 00000000 */  nop
    /* 2E868 8003E068 01004230 */  andi       $v0, $v0, 0x1
    /* 2E86C 8003E06C 05004014 */  bnez       $v0, .L8003E084
    /* 2E870 8003E070 07000224 */   addiu     $v0, $zero, 0x7
    /* 2E874 8003E074 05000224 */  addiu      $v0, $zero, 0x5
    /* 2E878 8003E078 C70482A3 */  sb         $v0, %gp_rel(D_8009B3CF)($gp)
    /* 2E87C 8003E07C 12F90008 */  j          .L8003E448
    /* 2E880 8003E080 00000000 */   nop
  .L8003E084:
    /* 2E884 8003E084 C70482A3 */  sb         $v0, %gp_rel(D_8009B3CF)($gp)
    /* 2E888 8003E088 12F90008 */  j          .L8003E448
    /* 2E88C 8003E08C 00000000 */   nop
  jlabel .L8003E090
    /* 2E890 8003E090 C7048393 */  lbu        $v1, %gp_rel(D_8009B3CF)($gp)
    /* 2E894 8003E094 00000000 */  nop
    /* 2E898 8003E098 80006230 */  andi       $v0, $v1, 0x80
    /* 2E89C 8003E09C 1E004014 */  bnez       $v0, .L8003E118
    /* 2E8A0 8003E0A0 80006234 */   ori       $v0, $v1, 0x80
    /* 2E8A4 8003E0A4 C70482A3 */  sb         $v0, %gp_rel(D_8009B3CF)($gp)
    /* 2E8A8 8003E0A8 0180043C */  lui        $a0, %hi(D_80010384)
    /* 2E8AC 8003E0AC 3513010C */  jal        func_80044CD4
    /* 2E8B0 8003E0B0 84038424 */   addiu     $a0, $a0, %lo(D_80010384)
    /* 2E8B4 8003E0B4 21884000 */  addu       $s1, $v0, $zero
    /* 2E8B8 8003E0B8 06002006 */  bltz       $s1, .L8003E0D4
    /* 2E8BC 8003E0BC 00000000 */   nop
    /* 2E8C0 8003E0C0 C4048297 */  lhu        $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E8C4 8003E0C4 00000000 */  nop
    /* 2E8C8 8003E0C8 02004230 */  andi       $v0, $v0, 0x2
    /* 2E8CC 8003E0CC 03004010 */  beqz       $v0, .L8003E0DC
    /* 2E8D0 8003E0D0 80101100 */   sll       $v0, $s1, 2
  .L8003E0D4:
    /* 2E8D4 8003E0D4 EEF80008 */  j          .L8003E3B8
    /* 2E8D8 8003E0D8 D3000424 */   addiu     $a0, $zero, 0xD3
  .L8003E0DC:
    /* 2E8DC 8003E0DC 21105100 */  addu       $v0, $v0, $s1
    /* 2E8E0 8003E0E0 0A80033C */  lui        $v1, %hi(D_8009B444)
    /* 2E8E4 8003E0E4 44B4638C */  lw         $v1, %lo(D_8009B444)($v1)
    /* 2E8E8 8003E0E8 C0100200 */  sll        $v0, $v0, 3
    /* 2E8EC 8003E0EC 21104300 */  addu       $v0, $v0, $v1
    /* 2E8F0 8003E0F0 2000468C */  lw         $a2, 0x20($v0)
    /* 2E8F4 8003E0F4 00000000 */  nop
    /* 2E8F8 8003E0F8 0200C104 */  bgez       $a2, .L8003E104
    /* 2E8FC 8003E0FC 2120A002 */   addu      $a0, $s5, $zero
    /* 2E900 8003E100 3F00C624 */  addiu      $a2, $a2, 0x3F
  .L8003E104:
    /* 2E904 8003E104 2180053C */  lui        $a1, (0x80210000 >> 16)
    /* 2E908 8003E108 9E10010C */  jal        func_80044278
    /* 2E90C 8003E10C 83310600 */   sra       $a2, $a2, 6
    /* 2E910 8003E110 12F90008 */  j          .L8003E448
    /* 2E914 8003E114 00000000 */   nop
  .L8003E118:
    /* 2E918 8003E118 CD048293 */  lbu        $v0, %gp_rel(D_8009B3D5)($gp)
    /* 2E91C 8003E11C 00000000 */  nop
    /* 2E920 8003E120 A5004014 */  bnez       $v0, .L8003E3B8
    /* 2E924 8003E124 D8000424 */   addiu     $a0, $zero, 0xD8
    /* 2E928 8003E128 06000224 */  addiu      $v0, $zero, 0x6
    /* 2E92C 8003E12C C70482A3 */  sb         $v0, %gp_rel(D_8009B3CF)($gp)
  jlabel .L8003E130
    /* 2E930 8003E130 C7048393 */  lbu        $v1, %gp_rel(D_8009B3CF)($gp)
    /* 2E934 8003E134 00000000 */  nop
    /* 2E938 8003E138 80006230 */  andi       $v0, $v1, 0x80
    /* 2E93C 8003E13C 1F004014 */  bnez       $v0, .L8003E1BC
    /* 2E940 8003E140 01000224 */   addiu     $v0, $zero, 0x1
    /* 2E944 8003E144 80006234 */  ori        $v0, $v1, 0x80
    /* 2E948 8003E148 C70482A3 */  sb         $v0, %gp_rel(D_8009B3CF)($gp)
    /* 2E94C 8003E14C 0180023C */  lui        $v0, %hi(D_80010384)
    /* 2E950 8003E150 84035024 */  addiu      $s0, $v0, %lo(D_80010384)
    /* 2E954 8003E154 3513010C */  jal        func_80044CD4
    /* 2E958 8003E158 21200002 */   addu      $a0, $s0, $zero
    /* 2E95C 8003E15C 21884000 */  addu       $s1, $v0, $zero
    /* 2E960 8003E160 95002006 */  bltz       $s1, .L8003E3B8
    /* 2E964 8003E164 D3000424 */   addiu     $a0, $zero, 0xD3
    /* 2E968 8003E168 C4048297 */  lhu        $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E96C 8003E16C 00000000 */  nop
    /* 2E970 8003E170 02004230 */  andi       $v0, $v0, 0x2
    /* 2E974 8003E174 90004014 */  bnez       $v0, .L8003E3B8
    /* 2E978 8003E178 00000000 */   nop
    /* 2E97C 8003E17C D5800434 */  ori        $a0, $zero, 0x80D5
    /* 2E980 8003E180 1BF5000C */  jal        func_8003D46C
    /* 2E984 8003E184 21280000 */   addu      $a1, $zero, $zero
    /* 2E988 8003E188 2120A002 */  addu       $a0, $s5, $zero
    /* 2E98C 8003E18C 21280002 */  addu       $a1, $s0, $zero
    /* 2E990 8003E190 2080063C */  lui        $a2, (0x80200000 >> 16)
    /* 2E994 8003E194 0D0071A2 */  sb         $s1, 0xD($s3)
    /* 2E998 8003E198 C4048297 */  lhu        $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E99C 8003E19C 001E0324 */  addiu      $v1, $zero, 0x1E00
    /* 2E9A0 8003E1A0 1000A3AF */  sw         $v1, 0x10($sp)
    /* 2E9A4 8003E1A4 00104234 */  ori        $v0, $v0, 0x1000
    /* 2E9A8 8003E1A8 C40482A7 */  sh         $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E9AC 8003E1AC 7710010C */  jal        func_800441DC
    /* 2E9B0 8003E1B0 00020724 */   addiu     $a3, $zero, 0x200
    /* 2E9B4 8003E1B4 12F90008 */  j          .L8003E448
    /* 2E9B8 8003E1B8 00000000 */   nop
  .L8003E1BC:
    /* 2E9BC 8003E1BC CD048393 */  lbu        $v1, %gp_rel(D_8009B3D5)($gp)
    /* 2E9C0 8003E1C0 00000000 */  nop
    /* 2E9C4 8003E1C4 7C006214 */  bne        $v1, $v0, .L8003E3B8
    /* 2E9C8 8003E1C8 D7000424 */   addiu     $a0, $zero, 0xD7
    /* 2E9CC 8003E1CC EEF80008 */  j          .L8003E3B8
    /* 2E9D0 8003E1D0 D8000424 */   addiu     $a0, $zero, 0xD8
  jlabel .L8003E1D4
    /* 2E9D4 8003E1D4 C7048393 */  lbu        $v1, %gp_rel(D_8009B3CF)($gp)
    /* 2E9D8 8003E1D8 00000000 */  nop
    /* 2E9DC 8003E1DC 80006230 */  andi       $v0, $v1, 0x80
    /* 2E9E0 8003E1E0 2D004014 */  bnez       $v0, .L8003E298
    /* 2E9E4 8003E1E4 01000224 */   addiu     $v0, $zero, 0x1
    /* 2E9E8 8003E1E8 C4048297 */  lhu        $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2E9EC 8003E1EC 80006334 */  ori        $v1, $v1, 0x80
    /* 2E9F0 8003E1F0 C70483A3 */  sb         $v1, %gp_rel(D_8009B3CF)($gp)
    /* 2E9F4 8003E1F4 02004230 */  andi       $v0, $v0, 0x2
    /* 2E9F8 8003E1F8 04004010 */  beqz       $v0, .L8003E20C
    /* 2E9FC 8003E1FC 09000224 */   addiu     $v0, $zero, 0x9
    /* 2EA00 8003E200 C70482A3 */  sb         $v0, %gp_rel(D_8009B3CF)($gp)
    /* 2EA04 8003E204 12F90008 */  j          .L8003E448
    /* 2EA08 8003E208 00000000 */   nop
  .L8003E20C:
    /* 2EA0C 8003E20C 0180023C */  lui        $v0, %hi(D_80010384)
    /* 2EA10 8003E210 84035024 */  addiu      $s0, $v0, %lo(D_80010384)
    /* 2EA14 8003E214 3513010C */  jal        func_80044CD4
    /* 2EA18 8003E218 21200002 */   addu      $a0, $s0, $zero
    /* 2EA1C 8003E21C 04004104 */  bgez       $v0, .L8003E230
    /* 2EA20 8003E220 0A000224 */   addiu     $v0, $zero, 0xA
    /* 2EA24 8003E224 C70482A3 */  sb         $v0, %gp_rel(D_8009B3CF)($gp)
    /* 2EA28 8003E228 12F90008 */  j          .L8003E448
    /* 2EA2C 8003E22C 00000000 */   nop
  .L8003E230:
    /* 2EA30 8003E230 D6800434 */  ori        $a0, $zero, 0x80D6
    /* 2EA34 8003E234 1BF5000C */  jal        func_8003D46C
    /* 2EA38 8003E238 21280000 */   addu      $a1, $zero, $zero
    /* 2EA3C 8003E23C 3080043C */  lui        $a0, (0x80300000 >> 16)
    /* 2EA40 8003E240 1D80053C */  lui        $a1, %hi(D_801D4000)
    /* 2EA44 8003E244 0040A524 */  addiu      $a1, $a1, %lo(D_801D4000)
    /* 2EA48 8003E248 A8D5000C */  jal        func_800356A0
    /* 2EA4C 8003E24C 00020624 */   addiu     $a2, $zero, 0x200
    /* 2EA50 8003E250 3080043C */  lui        $a0, (0x80300200 >> 16)
    /* 2EA54 8003E254 00028434 */  ori        $a0, $a0, (0x80300200 & 0xFFFF)
    /* 2EA58 8003E258 86000524 */  addiu      $a1, $zero, 0x86
    /* 2EA5C 8003E25C D2D5000C */  jal        func_80035748
    /* 2EA60 8003E260 00080624 */   addiu     $a2, $zero, 0x800
    /* 2EA64 8003E264 2120A002 */  addu       $a0, $s5, $zero
    /* 2EA68 8003E268 21280002 */  addu       $a1, $s0, $zero
    /* 2EA6C 8003E26C 3080063C */  lui        $a2, (0x80300000 >> 16)
    /* 2EA70 8003E270 21380000 */  addu       $a3, $zero, $zero
    /* 2EA74 8003E274 000A0224 */  addiu      $v0, $zero, 0xA00
    /* 2EA78 8003E278 B910010C */  jal        func_800442E4
    /* 2EA7C 8003E27C 1000A2AF */   sw        $v0, 0x10($sp)
    /* 2EA80 8003E280 C4048297 */  lhu        $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2EA84 8003E284 00000000 */  nop
    /* 2EA88 8003E288 00104234 */  ori        $v0, $v0, 0x1000
    /* 2EA8C 8003E28C C40482A7 */  sh         $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2EA90 8003E290 12F90008 */  j          .L8003E448
    /* 2EA94 8003E294 00000000 */   nop
  .L8003E298:
    /* 2EA98 8003E298 CD048393 */  lbu        $v1, %gp_rel(D_8009B3D5)($gp)
    /* 2EA9C 8003E29C 00000000 */  nop
    /* 2EAA0 8003E2A0 04006214 */  bne        $v1, $v0, .L8003E2B4
    /* 2EAA4 8003E2A4 D7000424 */   addiu     $a0, $zero, 0xD7
    /* 2EAA8 8003E2A8 D9000424 */  addiu      $a0, $zero, 0xD9
    /* 2EAAC 8003E2AC B0F80008 */  j          .L8003E2C0
    /* 2EAB0 8003E2B0 21284000 */   addu      $a1, $v0, $zero
  .L8003E2B4:
    /* 2EAB4 8003E2B4 01000524 */  addiu      $a1, $zero, 0x1
    /* 2EAB8 8003E2B8 08000224 */  addiu      $v0, $zero, 0x8
    /* 2EABC 8003E2BC C70482A3 */  sb         $v0, %gp_rel(D_8009B3CF)($gp)
  .L8003E2C0:
    /* 2EAC0 8003E2C0 1BF5000C */  jal        func_8003D46C
    /* 2EAC4 8003E2C4 00000000 */   nop
    /* 2EAC8 8003E2C8 C4048297 */  lhu        $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2EACC 8003E2CC 00000000 */  nop
    /* 2EAD0 8003E2D0 00044234 */  ori        $v0, $v0, 0x400
    /* 2EAD4 8003E2D4 C40482A7 */  sh         $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2EAD8 8003E2D8 08000224 */  addiu      $v0, $zero, 0x8
    /* 2EADC 8003E2DC C70482A3 */  sb         $v0, %gp_rel(D_8009B3CF)($gp)
  jlabel .L8003E2E0
    /* 2EAE0 8003E2E0 C7048393 */  lbu        $v1, %gp_rel(D_8009B3CF)($gp)
    /* 2EAE4 8003E2E4 00000000 */  nop
    /* 2EAE8 8003E2E8 80006230 */  andi       $v0, $v1, 0x80
    /* 2EAEC 8003E2EC 2D004014 */  bnez       $v0, .L8003E3A4
    /* 2EAF0 8003E2F0 0180043C */   lui       $a0, %hi(D_80010384)
    /* 2EAF4 8003E2F4 80006234 */  ori        $v0, $v1, 0x80
    /* 2EAF8 8003E2F8 C70482A3 */  sb         $v0, %gp_rel(D_8009B3CF)($gp)
    /* 2EAFC 8003E2FC 3513010C */  jal        func_80044CD4
    /* 2EB00 8003E300 84038424 */   addiu     $a0, $a0, %lo(D_80010384)
    /* 2EB04 8003E304 21884000 */  addu       $s1, $v0, $zero
    /* 2EB08 8003E308 21200000 */  addu       $a0, $zero, $zero
    /* 2EB0C 8003E30C 21188000 */  addu       $v1, $a0, $zero
    /* 2EB10 8003E310 2180053C */  lui        $a1, %hi(D_80210000)
    /* 2EB14 8003E314 01000224 */  addiu      $v0, $zero, 0x1
    /* 2EB18 8003E318 2180013C */  lui        $at, %hi(D_8021007E)
    /* 2EB1C 8003E31C 7E0022A0 */  sb         $v0, %lo(D_8021007E)($at)
    /* 2EB20 8003E320 FF000224 */  addiu      $v0, $zero, 0xFF
    /* 2EB24 8003E324 2180013C */  lui        $at, %hi(D_8021007D)
    /* 2EB28 8003E328 7D0022A0 */  sb         $v0, %lo(D_8021007D)($at)
    /* 2EB2C 8003E32C 2180013C */  lui        $at, %hi(D_8021007C)
    /* 2EB30 8003E330 7C0022A0 */  sb         $v0, %lo(D_8021007C)($at)
    /* 2EB34 8003E334 2180013C */  lui        $at, %hi(D_8021007B)
    /* 2EB38 8003E338 7B0022A0 */  sb         $v0, %lo(D_8021007B)($at)
    /* 2EB3C 8003E33C 2180013C */  lui        $at, %hi(D_8021007A)
    /* 2EB40 8003E340 7A0022A0 */  sb         $v0, %lo(D_8021007A)($at)
    /* 2EB44 8003E344 21106500 */  addu       $v0, $v1, $a1
  .L8003E348:
    /* 2EB48 8003E348 00004290 */  lbu        $v0, %lo(D_80210000)($v0)
    /* 2EB4C 8003E34C 01006324 */  addiu      $v1, $v1, 0x1
    /* 2EB50 8003E350 26208200 */  xor        $a0, $a0, $v0
    /* 2EB54 8003E354 7F006228 */  slti       $v0, $v1, 0x7F
    /* 2EB58 8003E358 FBFF4014 */  bnez       $v0, .L8003E348
    /* 2EB5C 8003E35C 21106500 */   addu      $v0, $v1, $a1
    /* 2EB60 8003E360 80101100 */  sll        $v0, $s1, 2
    /* 2EB64 8003E364 21105100 */  addu       $v0, $v0, $s1
    /* 2EB68 8003E368 0A80033C */  lui        $v1, %hi(D_8009B444)
    /* 2EB6C 8003E36C 44B4638C */  lw         $v1, %lo(D_8009B444)($v1)
    /* 2EB70 8003E370 C0100200 */  sll        $v0, $v0, 3
    /* 2EB74 8003E374 21104300 */  addu       $v0, $v0, $v1
    /* 2EB78 8003E378 2000468C */  lw         $a2, 0x20($v0)
    /* 2EB7C 8003E37C 2180013C */  lui        $at, %hi(D_8021007F)
    /* 2EB80 8003E380 7F0024A0 */  sb         $a0, %lo(D_8021007F)($at)
    /* 2EB84 8003E384 0200C104 */  bgez       $a2, .L8003E390
    /* 2EB88 8003E388 2120A002 */   addu      $a0, $s5, $zero
    /* 2EB8C 8003E38C 3F00C624 */  addiu      $a2, $a2, 0x3F
  .L8003E390:
    /* 2EB90 8003E390 2180053C */  lui        $a1, (0x80210000 >> 16)
    /* 2EB94 8003E394 E010010C */  jal        func_80044380
    /* 2EB98 8003E398 83310600 */   sra       $a2, $a2, 6
    /* 2EB9C 8003E39C 12F90008 */  j          .L8003E448
    /* 2EBA0 8003E3A0 00000000 */   nop
  .L8003E3A4:
    /* 2EBA4 8003E3A4 CD048293 */  lbu        $v0, %gp_rel(D_8009B3D5)($gp)
    /* 2EBA8 8003E3A8 00000000 */  nop
    /* 2EBAC 8003E3AC 26004010 */  beqz       $v0, .L8003E448
    /* 2EBB0 8003E3B0 00000000 */   nop
    /* 2EBB4 8003E3B4 D9000424 */  addiu      $a0, $zero, 0xD9
  .L8003E3B8:
    /* 2EBB8 8003E3B8 1BF5000C */  jal        func_8003D46C
    /* 2EBBC 8003E3BC 01000524 */   addiu     $a1, $zero, 0x1
    /* 2EBC0 8003E3C0 C4048297 */  lhu        $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2EBC4 8003E3C4 00000000 */  nop
    /* 2EBC8 8003E3C8 00044234 */  ori        $v0, $v0, 0x400
    /* 2EBCC 8003E3CC C40482A7 */  sh         $v0, %gp_rel(D_8009B3CC)($gp)
    /* 2EBD0 8003E3D0 12F90008 */  j          .L8003E448
    /* 2EBD4 8003E3D4 00000000 */   nop
  jlabel .L8003E3D8
    /* 2EBD8 8003E3D8 C7048393 */  lbu        $v1, %gp_rel(D_8009B3CF)($gp)
    /* 2EBDC 8003E3DC 00000000 */  nop
    /* 2EBE0 8003E3E0 80006230 */  andi       $v0, $v1, 0x80
    /* 2EBE4 8003E3E4 0E004014 */  bnez       $v0, .L8003E420
    /* 2EBE8 8003E3E8 80006234 */   ori       $v0, $v1, 0x80
    /* 2EBEC 8003E3EC C70482A3 */  sb         $v0, %gp_rel(D_8009B3CF)($gp)
    /* 2EBF0 8003E3F0 0C006292 */  lbu        $v0, 0xC($s3)
    /* 2EBF4 8003E3F4 10004392 */  lbu        $v1, 0x10($s2)
    /* 2EBF8 8003E3F8 00000000 */  nop
    /* 2EBFC 8003E3FC 2B104300 */  sltu       $v0, $v0, $v1
    /* 2EC00 8003E400 11004014 */  bnez       $v0, .L8003E448
    /* 2EC04 8003E404 21306000 */   addu      $a2, $v1, $zero
    /* 2EC08 8003E408 2120A002 */  addu       $a0, $s5, $zero
    /* 2EC0C 8003E40C 0180053C */  lui        $a1, %hi(D_80010384)
    /* 2EC10 8003E410 FB10010C */  jal        func_800443EC
    /* 2EC14 8003E414 8403A524 */   addiu     $a1, $a1, %lo(D_80010384)
    /* 2EC18 8003E418 12F90008 */  j          .L8003E448
    /* 2EC1C 8003E41C 00000000 */   nop
  .L8003E420:
    /* 2EC20 8003E420 CD048293 */  lbu        $v0, %gp_rel(D_8009B3D5)($gp)
    /* 2EC24 8003E424 00000000 */  nop
    /* 2EC28 8003E428 04004014 */  bnez       $v0, .L8003E43C
    /* 2EC2C 8003E42C 00000000 */   nop
    /* 2EC30 8003E430 0180043C */  lui        $a0, %hi(D_80010398)
    /* 2EC34 8003E434 1C3A020C */  jal        func_8008E870
    /* 2EC38 8003E438 98038424 */   addiu     $a0, $a0, %lo(D_80010398)
  .L8003E43C:
    /* 2EC3C 8003E43C 0180043C */  lui        $a0, %hi(D_800103A4)
    /* 2EC40 8003E440 1C3A020C */  jal        func_8008E870
    /* 2EC44 8003E444 A4038424 */   addiu     $a0, $a0, %lo(D_800103A4)
  jlabel .L8003E448
    /* 2EC48 8003E448 3000BF8F */  lw         $ra, 0x30($sp)
    /* 2EC4C 8003E44C 2C00B58F */  lw         $s5, 0x2C($sp)
    /* 2EC50 8003E450 2800B48F */  lw         $s4, 0x28($sp)
    /* 2EC54 8003E454 2400B38F */  lw         $s3, 0x24($sp)
    /* 2EC58 8003E458 2000B28F */  lw         $s2, 0x20($sp)
    /* 2EC5C 8003E45C 1C00B18F */  lw         $s1, 0x1C($sp)
    /* 2EC60 8003E460 1800B08F */  lw         $s0, 0x18($sp)
    /* 2EC64 8003E464 0800E003 */  jr         $ra
    /* 2EC68 8003E468 3800BD27 */   addiu     $sp, $sp, 0x38
endlabel func_8003DC1C
