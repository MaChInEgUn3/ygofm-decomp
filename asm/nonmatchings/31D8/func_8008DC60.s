nonmatching func_8008DC60, 0x6B4

glabel func_8008DC60
    /* 7E460 8008DC60 B8FFBD27 */  addiu      $sp, $sp, -0x48
    /* 7E464 8008DC64 3800B6AF */  sw         $s6, 0x38($sp)
    /* 7E468 8008DC68 21B08000 */  addu       $s6, $a0, $zero
    /* 7E46C 8008DC6C 3400B5AF */  sw         $s5, 0x34($sp)
    /* 7E470 8008DC70 21A80000 */  addu       $s5, $zero, $zero
    /* 7E474 8008DC74 2000B0AF */  sw         $s0, 0x20($sp)
    /* 7E478 8008DC78 1080103C */  lui        $s0, %hi(D_800FE678)
    /* 7E47C 8008DC7C 78E61026 */  addiu      $s0, $s0, %lo(D_800FE678)
    /* 7E480 8008DC80 21200002 */  addu       $a0, $s0, $zero
    /* 7E484 8008DC84 1000A5AF */  sw         $a1, 0x10($sp)
    /* 7E488 8008DC88 80000524 */  addiu      $a1, $zero, 0x80
    /* 7E48C 8008DC8C 4400BFAF */  sw         $ra, 0x44($sp)
    /* 7E490 8008DC90 4000BEAF */  sw         $fp, 0x40($sp)
    /* 7E494 8008DC94 3C00B7AF */  sw         $s7, 0x3C($sp)
    /* 7E498 8008DC98 3000B4AF */  sw         $s4, 0x30($sp)
    /* 7E49C 8008DC9C 2C00B3AF */  sw         $s3, 0x2C($sp)
    /* 7E4A0 8008DCA0 2800B2AF */  sw         $s2, 0x28($sp)
    /* 7E4A4 8008DCA4 2400B1AF */  sw         $s1, 0x24($sp)
    /* 7E4A8 8008DCA8 1400A6AF */  sw         $a2, 0x14($sp)
    /* 7E4AC 8008DCAC D838020C */  jal        func_8008E360
    /* 7E4B0 8008DCB0 1800A0AF */   sw        $zero, 0x18($sp)
    /* 7E4B4 8008DCB4 21880000 */  addu       $s1, $zero, $zero
    /* 7E4B8 8008DCB8 21200002 */  addu       $a0, $s0, $zero
    /* 7E4BC 8008DCBC D838020C */  jal        func_8008E360
    /* 7E4C0 8008DCC0 80000524 */   addiu     $a1, $zero, 0x80
    /* 7E4C4 8008DCC4 04001224 */  addiu      $s2, $zero, 0x4
  .L8008DCC8:
    /* 7E4C8 8008DCC8 5835020C */  jal        func_8008D560
    /* 7E4CC 8008DCCC 00000000 */   nop
    /* 7E4D0 8008DCD0 2120C002 */  addu       $a0, $s6, $zero
    /* 7E4D4 8008DCD4 1080063C */  lui        $a2, %hi(D_800FE678)
    /* 7E4D8 8008DCD8 78E6C624 */  addiu      $a2, $a2, %lo(D_800FE678)
    /* 7E4DC 8008DCDC D82C020C */  jal        func_8008B360
    /* 7E4E0 8008DCE0 21280000 */   addu      $a1, $zero, $zero
    /* 7E4E4 8008DCE4 D035020C */  jal        func_8008D740
    /* 7E4E8 8008DCE8 00000000 */   nop
    /* 7E4EC 8008DCEC 21804000 */  addu       $s0, $v0, $zero
    /* 7E4F0 8008DCF0 0D000012 */  beqz       $s0, .L8008DD28
    /* 7E4F4 8008DCF4 00000000 */   nop
    /* 7E4F8 8008DCF8 07001216 */  bne        $s0, $s2, .L8008DD18
    /* 7E4FC 8008DCFC 00000000 */   nop
    /* 7E500 8008DD00 5835020C */  jal        func_8008D560
    /* 7E504 8008DD04 00000000 */   nop
    /* 7E508 8008DD08 E82C020C */  jal        func_8008B3A0
    /* 7E50C 8008DD0C 2120C002 */   addu      $a0, $s6, $zero
    /* 7E510 8008DD10 D035020C */  jal        func_8008D740
    /* 7E514 8008DD14 00000000 */   nop
  .L8008DD18:
    /* 7E518 8008DD18 01003126 */  addiu      $s1, $s1, 0x1
    /* 7E51C 8008DD1C 0800222A */  slti       $v0, $s1, 0x8
    /* 7E520 8008DD20 E9FF4014 */  bnez       $v0, .L8008DCC8
    /* 7E524 8008DD24 00000000 */   nop
  .L8008DD28:
    /* 7E528 8008DD28 6E010016 */  bnez       $s0, .L8008E2E4
    /* 7E52C 8008DD2C 21100002 */   addu      $v0, $s0, $zero
    /* 7E530 8008DD30 1080043C */  lui        $a0, %hi(D_800FE678)
    /* 7E534 8008DD34 78E68424 */  addiu      $a0, $a0, %lo(D_800FE678)
    /* 7E538 8008DD38 00008390 */  lbu        $v1, 0x0($a0)
    /* 7E53C 8008DD3C 4D000224 */  addiu      $v0, $zero, 0x4D
    /* 7E540 8008DD40 68016214 */  bne        $v1, $v0, .L8008E2E4
    /* 7E544 8008DD44 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 7E548 8008DD48 01008390 */  lbu        $v1, 0x1($a0)
    /* 7E54C 8008DD4C 43000224 */  addiu      $v0, $zero, 0x43
    /* 7E550 8008DD50 64016214 */  bne        $v1, $v0, .L8008E2E4
    /* 7E554 8008DD54 FEFF0224 */   addiu     $v0, $zero, -0x2
    /* 7E558 8008DD58 21880000 */  addu       $s1, $zero, $zero
    /* 7E55C 8008DD5C 21B88000 */  addu       $s7, $a0, $zero
    /* 7E560 8008DD60 04001E24 */  addiu      $fp, $zero, 0x4
    /* 7E564 8008DD64 1080143C */  lui        $s4, %hi(D_800FE438)
    /* 7E568 8008DD68 38E49426 */  addiu      $s4, $s4, %lo(D_800FE438)
    /* 7E56C 8008DD6C 01001324 */  addiu      $s3, $zero, 0x1
  .L8008DD70:
    /* 7E570 8008DD70 1080013C */  lui        $at, %hi(D_800FE667)
    /* 7E574 8008DD74 21083300 */  addu       $at, $at, $s3
    /* 7E578 8008DD78 67E620A0 */  sb         $zero, %lo(D_800FE667)($at)
    /* 7E57C 8008DD7C 2120E002 */  addu       $a0, $s7, $zero
    /* 7E580 8008DD80 D838020C */  jal        func_8008E360
    /* 7E584 8008DD84 80000524 */   addiu     $a1, $zero, 0x80
    /* 7E588 8008DD88 21900000 */  addu       $s2, $zero, $zero
    /* 7E58C 8008DD8C 2120E002 */  addu       $a0, $s7, $zero
    /* 7E590 8008DD90 D838020C */  jal        func_8008E360
    /* 7E594 8008DD94 80000524 */   addiu     $a1, $zero, 0x80
  .L8008DD98:
    /* 7E598 8008DD98 5835020C */  jal        func_8008D560
    /* 7E59C 8008DD9C 00000000 */   nop
    /* 7E5A0 8008DDA0 2120C002 */  addu       $a0, $s6, $zero
    /* 7E5A4 8008DDA4 1080063C */  lui        $a2, %hi(D_800FE678)
    /* 7E5A8 8008DDA8 78E6C624 */  addiu      $a2, $a2, %lo(D_800FE678)
    /* 7E5AC 8008DDAC D82C020C */  jal        func_8008B360
    /* 7E5B0 8008DDB0 21286002 */   addu      $a1, $s3, $zero
    /* 7E5B4 8008DDB4 D035020C */  jal        func_8008D740
    /* 7E5B8 8008DDB8 00000000 */   nop
    /* 7E5BC 8008DDBC 21804000 */  addu       $s0, $v0, $zero
    /* 7E5C0 8008DDC0 0D000012 */  beqz       $s0, .L8008DDF8
    /* 7E5C4 8008DDC4 00000000 */   nop
    /* 7E5C8 8008DDC8 07001E16 */  bne        $s0, $fp, .L8008DDE8
    /* 7E5CC 8008DDCC 00000000 */   nop
    /* 7E5D0 8008DDD0 5835020C */  jal        func_8008D560
    /* 7E5D4 8008DDD4 00000000 */   nop
    /* 7E5D8 8008DDD8 E82C020C */  jal        func_8008B3A0
    /* 7E5DC 8008DDDC 2120C002 */   addu      $a0, $s6, $zero
    /* 7E5E0 8008DDE0 D035020C */  jal        func_8008D740
    /* 7E5E4 8008DDE4 00000000 */   nop
  .L8008DDE8:
    /* 7E5E8 8008DDE8 01005226 */  addiu      $s2, $s2, 0x1
    /* 7E5EC 8008DDEC 0800422A */  slti       $v0, $s2, 0x8
    /* 7E5F0 8008DDF0 E9FF4014 */  bnez       $v0, .L8008DD98
    /* 7E5F4 8008DDF4 00000000 */   nop
  .L8008DDF8:
    /* 7E5F8 8008DDF8 39010016 */  bnez       $s0, .L8008E2E0
    /* 7E5FC 8008DDFC 01003126 */   addiu     $s1, $s1, 0x1
    /* 7E600 8008DE00 1080053C */  lui        $a1, %hi(D_800FE678)
    /* 7E604 8008DE04 78E6A524 */  addiu      $a1, $a1, %lo(D_800FE678)
    /* 7E608 8008DE08 0300A288 */  lwl        $v0, 0x3($a1)
    /* 7E60C 8008DE0C 0000A298 */  lwr        $v0, 0x0($a1)
    /* 7E610 8008DE10 0700A388 */  lwl        $v1, 0x7($a1)
    /* 7E614 8008DE14 0400A398 */  lwr        $v1, 0x4($a1)
    /* 7E618 8008DE18 0B00A488 */  lwl        $a0, 0xB($a1)
    /* 7E61C 8008DE1C 0800A498 */  lwr        $a0, 0x8($a1)
    /* 7E620 8008DE20 030082AA */  swl        $v0, 0x3($s4)
    /* 7E624 8008DE24 000082BA */  swr        $v0, 0x0($s4)
    /* 7E628 8008DE28 070083AA */  swl        $v1, 0x7($s4)
    /* 7E62C 8008DE2C 040083BA */  swr        $v1, 0x4($s4)
    /* 7E630 8008DE30 0B0084AA */  swl        $a0, 0xB($s4)
    /* 7E634 8008DE34 080084BA */  swr        $a0, 0x8($s4)
    /* 7E638 8008DE38 0F00A288 */  lwl        $v0, 0xF($a1)
    /* 7E63C 8008DE3C 0C00A298 */  lwr        $v0, 0xC($a1)
    /* 7E640 8008DE40 1300A388 */  lwl        $v1, 0x13($a1)
    /* 7E644 8008DE44 1000A398 */  lwr        $v1, 0x10($a1)
    /* 7E648 8008DE48 1700A488 */  lwl        $a0, 0x17($a1)
    /* 7E64C 8008DE4C 1400A498 */  lwr        $a0, 0x14($a1)
    /* 7E650 8008DE50 0F0082AA */  swl        $v0, 0xF($s4)
    /* 7E654 8008DE54 0C0082BA */  swr        $v0, 0xC($s4)
    /* 7E658 8008DE58 130083AA */  swl        $v1, 0x13($s4)
    /* 7E65C 8008DE5C 100083BA */  swr        $v1, 0x10($s4)
    /* 7E660 8008DE60 170084AA */  swl        $a0, 0x17($s4)
    /* 7E664 8008DE64 140084BA */  swr        $a0, 0x14($s4)
    /* 7E668 8008DE68 1B00A288 */  lwl        $v0, 0x1B($a1)
    /* 7E66C 8008DE6C 1800A298 */  lwr        $v0, 0x18($a1)
    /* 7E670 8008DE70 1F00A388 */  lwl        $v1, 0x1F($a1)
    /* 7E674 8008DE74 1C00A398 */  lwr        $v1, 0x1C($a1)
    /* 7E678 8008DE78 1B0082AA */  swl        $v0, 0x1B($s4)
    /* 7E67C 8008DE7C 180082BA */  swr        $v0, 0x18($s4)
    /* 7E680 8008DE80 1F0083AA */  swl        $v1, 0x1F($s4)
    /* 7E684 8008DE84 1C0083BA */  swr        $v1, 0x1C($s4)
    /* 7E688 8008DE88 20009426 */  addiu      $s4, $s4, 0x20
    /* 7E68C 8008DE8C 0F00222A */  slti       $v0, $s1, 0xF
    /* 7E690 8008DE90 B7FF4014 */  bnez       $v0, .L8008DD70
    /* 7E694 8008DE94 01007326 */   addiu     $s3, $s3, 0x1
    /* 7E698 8008DE98 21880000 */  addu       $s1, $zero, $zero
    /* 7E69C 8008DE9C 51000724 */  addiu      $a3, $zero, 0x51
    /* 7E6A0 8008DEA0 01000524 */  addiu      $a1, $zero, 0x1
    /* 7E6A4 8008DEA4 FFFF0634 */  ori        $a2, $zero, 0xFFFF
    /* 7E6A8 8008DEA8 40191100 */  sll        $v1, $s1, 5
  .L8008DEAC:
    /* 7E6AC 8008DEAC 1080023C */  lui        $v0, %hi(D_800FE438)
    /* 7E6B0 8008DEB0 21104300 */  addu       $v0, $v0, $v1
    /* 7E6B4 8008DEB4 38E4428C */  lw         $v0, %lo(D_800FE438)($v0)
    /* 7E6B8 8008DEB8 00000000 */  nop
    /* 7E6BC 8008DEBC 1C004714 */  bne        $v0, $a3, .L8008DF30
    /* 7E6C0 8008DEC0 00000000 */   nop
    /* 7E6C4 8008DEC4 1080013C */  lui        $at, %hi(D_800FE668)
    /* 7E6C8 8008DEC8 21083100 */  addu       $at, $at, $s1
    /* 7E6CC 8008DECC 68E625A0 */  sb         $a1, %lo(D_800FE668)($at)
    /* 7E6D0 8008DED0 1080023C */  lui        $v0, %hi(D_800FE440)
    /* 7E6D4 8008DED4 21104300 */  addu       $v0, $v0, $v1
    /* 7E6D8 8008DED8 40E44294 */  lhu        $v0, %lo(D_800FE440)($v0)
    /* 7E6DC 8008DEDC 00000000 */  nop
    /* 7E6E0 8008DEE0 13004610 */  beq        $v0, $a2, .L8008DF30
    /* 7E6E4 8008DEE4 21182002 */   addu      $v1, $s1, $zero
    /* 7E6E8 8008DEE8 FFFF0434 */  ori        $a0, $zero, 0xFFFF
    /* 7E6EC 8008DEEC 40110300 */  sll        $v0, $v1, 5
  .L8008DEF0:
    /* 7E6F0 8008DEF0 1080033C */  lui        $v1, %hi(D_800FE440)
    /* 7E6F4 8008DEF4 21186200 */  addu       $v1, $v1, $v0
    /* 7E6F8 8008DEF8 40E46394 */  lhu        $v1, %lo(D_800FE440)($v1)
    /* 7E6FC 8008DEFC 00000000 */  nop
    /* 7E700 8008DF00 0F00622C */  sltiu      $v0, $v1, 0xF
    /* 7E704 8008DF04 0A004010 */  beqz       $v0, .L8008DF30
    /* 7E708 8008DF08 40110300 */   sll       $v0, $v1, 5
    /* 7E70C 8008DF0C 1080013C */  lui        $at, %hi(D_800FE668)
    /* 7E710 8008DF10 21082300 */  addu       $at, $at, $v1
    /* 7E714 8008DF14 68E625A0 */  sb         $a1, %lo(D_800FE668)($at)
    /* 7E718 8008DF18 1080013C */  lui        $at, %hi(D_800FE440)
    /* 7E71C 8008DF1C 21082200 */  addu       $at, $at, $v0
    /* 7E720 8008DF20 40E42294 */  lhu        $v0, %lo(D_800FE440)($at)
    /* 7E724 8008DF24 00000000 */  nop
    /* 7E728 8008DF28 F1FF4414 */  bne        $v0, $a0, .L8008DEF0
    /* 7E72C 8008DF2C 40110300 */   sll       $v0, $v1, 5
  .L8008DF30:
    /* 7E730 8008DF30 01003126 */  addiu      $s1, $s1, 0x1
    /* 7E734 8008DF34 0F00222A */  slti       $v0, $s1, 0xF
    /* 7E738 8008DF38 DCFF4014 */  bnez       $v0, .L8008DEAC
    /* 7E73C 8008DF3C 40191100 */   sll       $v1, $s1, 5
    /* 7E740 8008DF40 21880000 */  addu       $s1, $zero, $zero
    /* 7E744 8008DF44 A0000324 */  addiu      $v1, $zero, 0xA0
  .L8008DF48:
    /* 7E748 8008DF48 1080023C */  lui        $v0, %hi(D_800FE668)
    /* 7E74C 8008DF4C 21105100 */  addu       $v0, $v0, $s1
    /* 7E750 8008DF50 68E64280 */  lb         $v0, %lo(D_800FE668)($v0)
    /* 7E754 8008DF54 00000000 */  nop
    /* 7E758 8008DF58 04004014 */  bnez       $v0, .L8008DF6C
    /* 7E75C 8008DF5C 40111100 */   sll       $v0, $s1, 5
    /* 7E760 8008DF60 1080013C */  lui        $at, %hi(D_800FE438)
    /* 7E764 8008DF64 21082200 */  addu       $at, $at, $v0
    /* 7E768 8008DF68 38E423AC */  sw         $v1, %lo(D_800FE438)($at)
  .L8008DF6C:
    /* 7E76C 8008DF6C 01003126 */  addiu      $s1, $s1, 0x1
    /* 7E770 8008DF70 0F00222A */  slti       $v0, $s1, 0xF
    /* 7E774 8008DF74 F4FF4014 */  bnez       $v0, .L8008DF48
    /* 7E778 8008DF78 00000000 */   nop
    /* 7E77C 8008DF7C 21880000 */  addu       $s1, $zero, $zero
    /* 7E780 8008DF80 51001224 */  addiu      $s2, $zero, 0x51
    /* 7E784 8008DF84 1080103C */  lui        $s0, %hi(D_800FE442)
    /* 7E788 8008DF88 42E41026 */  addiu      $s0, $s0, %lo(D_800FE442)
  .L8008DF8C:
    /* 7E78C 8008DF8C 40111100 */  sll        $v0, $s1, 5
    /* 7E790 8008DF90 1080013C */  lui        $at, %hi(D_800FE438)
    /* 7E794 8008DF94 21082200 */  addu       $at, $at, $v0
    /* 7E798 8008DF98 38E4228C */  lw         $v0, %lo(D_800FE438)($at)
    /* 7E79C 8008DF9C 00000000 */  nop
    /* 7E7A0 8008DFA0 06005214 */  bne        $v0, $s2, .L8008DFBC
    /* 7E7A4 8008DFA4 00000000 */   nop
    /* 7E7A8 8008DFA8 1000A58F */  lw         $a1, 0x10($sp)
    /* 7E7AC 8008DFAC A039020C */  jal        func_8008E680
    /* 7E7B0 8008DFB0 21200002 */   addu      $a0, $s0, $zero
    /* 7E7B4 8008DFB4 1D004010 */  beqz       $v0, .L8008E02C
    /* 7E7B8 8008DFB8 00000000 */   nop
  .L8008DFBC:
    /* 7E7BC 8008DFBC 01003126 */  addiu      $s1, $s1, 0x1
    /* 7E7C0 8008DFC0 0F00222A */  slti       $v0, $s1, 0xF
    /* 7E7C4 8008DFC4 F1FF4014 */  bnez       $v0, .L8008DF8C
    /* 7E7C8 8008DFC8 20001026 */   addiu     $s0, $s0, 0x20
    /* 7E7CC 8008DFCC 21880000 */  addu       $s1, $zero, $zero
    /* 7E7D0 8008DFD0 A0000324 */  addiu      $v1, $zero, 0xA0
    /* 7E7D4 8008DFD4 40111100 */  sll        $v0, $s1, 5
  .L8008DFD8:
    /* 7E7D8 8008DFD8 1080013C */  lui        $at, %hi(D_800FE438)
    /* 7E7DC 8008DFDC 21082200 */  addu       $at, $at, $v0
    /* 7E7E0 8008DFE0 38E4228C */  lw         $v0, %lo(D_800FE438)($at)
    /* 7E7E4 8008DFE4 1080013C */  lui        $at, %hi(D_800FE668)
    /* 7E7E8 8008DFE8 21083100 */  addu       $at, $at, $s1
    /* 7E7EC 8008DFEC 68E620A0 */  sb         $zero, %lo(D_800FE668)($at)
    /* 7E7F0 8008DFF0 F0004230 */  andi       $v0, $v0, 0xF0
    /* 7E7F4 8008DFF4 02004314 */  bne        $v0, $v1, .L8008E000
    /* 7E7F8 8008DFF8 00000000 */   nop
    /* 7E7FC 8008DFFC 0100B526 */  addiu      $s5, $s5, 0x1
  .L8008E000:
    /* 7E800 8008E000 01003126 */  addiu      $s1, $s1, 0x1
    /* 7E804 8008E004 0F00222A */  slti       $v0, $s1, 0xF
    /* 7E808 8008E008 F3FF4014 */  bnez       $v0, .L8008DFD8
    /* 7E80C 8008E00C 40111100 */   sll       $v0, $s1, 5
    /* 7E810 8008E010 1400A88F */  lw         $t0, 0x14($sp)
    /* 7E814 8008E014 00000000 */  nop
    /* 7E818 8008E018 2A10A802 */  slt        $v0, $s5, $t0
    /* 7E81C 8008E01C 0A004010 */  beqz       $v0, .L8008E048
    /* 7E820 8008E020 FFFF0224 */   addiu     $v0, $zero, -0x1
    /* 7E824 8008E024 B9380208 */  j          .L8008E2E4
    /* 7E828 8008E028 00000000 */   nop
  .L8008E02C:
    /* 7E82C 8008E02C 0180043C */  lui        $a0, %hi(D_80012668)
    /* 7E830 8008E030 68268424 */  addiu      $a0, $a0, %lo(D_80012668)
    /* 7E834 8008E034 1000A68F */  lw         $a2, 0x10($sp)
    /* 7E838 8008E038 1C3A020C */  jal        func_8008E870
    /* 7E83C 8008E03C 21280002 */   addu      $a1, $s0, $zero
    /* 7E840 8008E040 B9380208 */  j          .L8008E2E4
    /* 7E844 8008E044 FDFF0224 */   addiu     $v0, $zero, -0x3
  .L8008E048:
    /* 7E848 8008E048 21A80000 */  addu       $s5, $zero, $zero
    /* 7E84C 8008E04C 21180000 */  addu       $v1, $zero, $zero
    /* 7E850 8008E050 21880000 */  addu       $s1, $zero, $zero
    /* 7E854 8008E054 1400A88F */  lw         $t0, 0x14($sp)
    /* 7E858 8008E058 01001724 */  addiu      $s7, $zero, 0x1
    /* 7E85C 8008E05C 1080023C */  lui        $v0, %hi(D_800FE442)
    /* 7E860 8008E060 42E44224 */  addiu      $v0, $v0, %lo(D_800FE442)
    /* 7E864 8008E064 F6FF5024 */  addiu      $s0, $v0, -0xA
    /* 7E868 8008E068 21980000 */  addu       $s3, $zero, $zero
    /* 7E86C 8008E06C 1080123C */  lui        $s2, %hi(D_800FE668)
    /* 7E870 8008E070 68E65226 */  addiu      $s2, $s2, %lo(D_800FE668)
    /* 7E874 8008E074 21A04000 */  addu       $s4, $v0, $zero
    /* 7E878 8008E078 40F30800 */  sll        $fp, $t0, 13
  .L8008E07C:
    /* 7E87C 8008E07C 0000028E */  lw         $v0, 0x0($s0)
    /* 7E880 8008E080 A0000824 */  addiu      $t0, $zero, 0xA0
    /* 7E884 8008E084 F0004230 */  andi       $v0, $v0, 0xF0
    /* 7E888 8008E088 22004814 */  bne        $v0, $t0, .L8008E114
    /* 7E88C 8008E08C 00000000 */   nop
    /* 7E890 8008E090 0C00A016 */  bnez       $s5, .L8008E0C4
    /* 7E894 8008E094 40110300 */   sll       $v0, $v1, 5
    /* 7E898 8008E098 21208002 */  addu       $a0, $s4, $zero
    /* 7E89C 8008E09C 1000A58F */  lw         $a1, 0x10($sp)
    /* 7E8A0 8008E0A0 51000824 */  addiu      $t0, $zero, 0x51
    /* 7E8A4 8008E0A4 000008AE */  sw         $t0, 0x0($s0)
    /* 7E8A8 8008E0A8 1080013C */  lui        $at, %hi(D_800FE43C)
    /* 7E8AC 8008E0AC 21083300 */  addu       $at, $at, $s3
    /* 7E8B0 8008E0B0 3CE43EAC */  sw         $fp, %lo(D_800FE43C)($at)
    /* 7E8B4 8008E0B4 003A020C */  jal        func_8008E800
    /* 7E8B8 8008E0B8 14000624 */   addiu     $a2, $zero, 0x14
    /* 7E8BC 8008E0BC 37380208 */  j          .L8008E0DC
    /* 7E8C0 8008E0C0 21182002 */   addu      $v1, $s1, $zero
  .L8008E0C4:
    /* 7E8C4 8008E0C4 21182002 */  addu       $v1, $s1, $zero
    /* 7E8C8 8008E0C8 1080013C */  lui        $at, %hi(D_800FE440)
    /* 7E8CC 8008E0CC 21082200 */  addu       $at, $at, $v0
    /* 7E8D0 8008E0D0 40E431A4 */  sh         $s1, %lo(D_800FE440)($at)
    /* 7E8D4 8008E0D4 52000824 */  addiu      $t0, $zero, 0x52
    /* 7E8D8 8008E0D8 000008AE */  sw         $t0, 0x0($s0)
  .L8008E0DC:
    /* 7E8DC 8008E0DC 000057A2 */  sb         $s7, 0x0($s2)
    /* 7E8E0 8008E0E0 1400A88F */  lw         $t0, 0x14($sp)
    /* 7E8E4 8008E0E4 0100B526 */  addiu      $s5, $s5, 0x1
    /* 7E8E8 8008E0E8 2A10A802 */  slt        $v0, $s5, $t0
    /* 7E8EC 8008E0EC 09004014 */  bnez       $v0, .L8008E114
    /* 7E8F0 8008E0F0 FFFF0834 */   ori       $t0, $zero, 0xFFFF
    /* 7E8F4 8008E0F4 1080013C */  lui        $at, %hi(D_800FE440)
    /* 7E8F8 8008E0F8 21083300 */  addu       $at, $at, $s3
    /* 7E8FC 8008E0FC 40E428A4 */  sh         $t0, %lo(D_800FE440)($at)
    /* 7E900 8008E100 0200A22A */  slti       $v0, $s5, 0x2
    /* 7E904 8008E104 0A004014 */  bnez       $v0, .L8008E130
    /* 7E908 8008E108 53000224 */   addiu     $v0, $zero, 0x53
    /* 7E90C 8008E10C 4C380208 */  j          .L8008E130
    /* 7E910 8008E110 000002AE */   sw        $v0, 0x0($s0)
  .L8008E114:
    /* 7E914 8008E114 20001026 */  addiu      $s0, $s0, 0x20
    /* 7E918 8008E118 20007326 */  addiu      $s3, $s3, 0x20
    /* 7E91C 8008E11C 01005226 */  addiu      $s2, $s2, 0x1
    /* 7E920 8008E120 01003126 */  addiu      $s1, $s1, 0x1
    /* 7E924 8008E124 0F00222A */  slti       $v0, $s1, 0xF
    /* 7E928 8008E128 D4FF4014 */  bnez       $v0, .L8008E07C
    /* 7E92C 8008E12C 20009426 */   addiu     $s4, $s4, 0x20
  .L8008E130:
    /* 7E930 8008E130 0E001124 */  addiu      $s1, $zero, 0xE
    /* 7E934 8008E134 1080153C */  lui        $s5, %hi(D_800FE678)
    /* 7E938 8008E138 78E6B526 */  addiu      $s5, $s5, %lo(D_800FE678)
    /* 7E93C 8008E13C 04001724 */  addiu      $s7, $zero, 0x4
    /* 7E940 8008E140 1080143C */  lui        $s4, %hi(D_800FE5F8)
    /* 7E944 8008E144 F8E59426 */  addiu      $s4, $s4, %lo(D_800FE5F8)
  .L8008E148:
    /* 7E948 8008E148 1080023C */  lui        $v0, %hi(D_800FE668)
    /* 7E94C 8008E14C 21105100 */  addu       $v0, $v0, $s1
    /* 7E950 8008E150 68E64280 */  lb         $v0, %lo(D_800FE668)($v0)
    /* 7E954 8008E154 00000000 */  nop
    /* 7E958 8008E158 49004010 */  beqz       $v0, .L8008E280
    /* 7E95C 8008E15C 2120A002 */   addu      $a0, $s5, $zero
    /* 7E960 8008E160 D838020C */  jal        func_8008E360
    /* 7E964 8008E164 80000524 */   addiu     $a1, $zero, 0x80
    /* 7E968 8008E168 0300828A */  lwl        $v0, 0x3($s4)
    /* 7E96C 8008E16C 0000829A */  lwr        $v0, 0x0($s4)
    /* 7E970 8008E170 0700838A */  lwl        $v1, 0x7($s4)
    /* 7E974 8008E174 0400839A */  lwr        $v1, 0x4($s4)
    /* 7E978 8008E178 0B00848A */  lwl        $a0, 0xB($s4)
    /* 7E97C 8008E17C 0800849A */  lwr        $a0, 0x8($s4)
    /* 7E980 8008E180 0F00858A */  lwl        $a1, 0xF($s4)
    /* 7E984 8008E184 0C00859A */  lwr        $a1, 0xC($s4)
    /* 7E988 8008E188 0300A2AA */  swl        $v0, 0x3($s5)
    /* 7E98C 8008E18C 0000A2BA */  swr        $v0, 0x0($s5)
    /* 7E990 8008E190 0700A3AA */  swl        $v1, 0x7($s5)
    /* 7E994 8008E194 0400A3BA */  swr        $v1, 0x4($s5)
    /* 7E998 8008E198 0B00A4AA */  swl        $a0, 0xB($s5)
    /* 7E99C 8008E19C 0800A4BA */  swr        $a0, 0x8($s5)
    /* 7E9A0 8008E1A0 0F00A5AA */  swl        $a1, 0xF($s5)
    /* 7E9A4 8008E1A4 0C00A5BA */  swr        $a1, 0xC($s5)
    /* 7E9A8 8008E1A8 1300828A */  lwl        $v0, 0x13($s4)
    /* 7E9AC 8008E1AC 1000829A */  lwr        $v0, 0x10($s4)
    /* 7E9B0 8008E1B0 1700838A */  lwl        $v1, 0x17($s4)
    /* 7E9B4 8008E1B4 1400839A */  lwr        $v1, 0x14($s4)
    /* 7E9B8 8008E1B8 1B00848A */  lwl        $a0, 0x1B($s4)
    /* 7E9BC 8008E1BC 1800849A */  lwr        $a0, 0x18($s4)
    /* 7E9C0 8008E1C0 1F00858A */  lwl        $a1, 0x1F($s4)
    /* 7E9C4 8008E1C4 1C00859A */  lwr        $a1, 0x1C($s4)
    /* 7E9C8 8008E1C8 1300A2AA */  swl        $v0, 0x13($s5)
    /* 7E9CC 8008E1CC 1000A2BA */  swr        $v0, 0x10($s5)
    /* 7E9D0 8008E1D0 1700A3AA */  swl        $v1, 0x17($s5)
    /* 7E9D4 8008E1D4 1400A3BA */  swr        $v1, 0x14($s5)
    /* 7E9D8 8008E1D8 1B00A4AA */  swl        $a0, 0x1B($s5)
    /* 7E9DC 8008E1DC 1800A4BA */  swr        $a0, 0x18($s5)
    /* 7E9E0 8008E1E0 1F00A5AA */  swl        $a1, 0x1F($s5)
    /* 7E9E4 8008E1E4 1C00A5BA */  swr        $a1, 0x1C($s5)
    /* 7E9E8 8008E1E8 01003326 */  addiu      $s3, $s1, 0x1
    /* 7E9EC 8008E1EC 21900000 */  addu       $s2, $zero, $zero
    /* 7E9F0 8008E1F0 2120A002 */  addu       $a0, $s5, $zero
    /* 7E9F4 8008E1F4 21280000 */  addu       $a1, $zero, $zero
    /* 7E9F8 8008E1F8 7E000324 */  addiu      $v1, $zero, 0x7E
  .L8008E1FC:
    /* 7E9FC 8008E1FC 00008290 */  lbu        $v0, 0x0($a0)
    /* 7EA00 8008E200 01008424 */  addiu      $a0, $a0, 0x1
    /* 7EA04 8008E204 FFFF6324 */  addiu      $v1, $v1, -0x1
    /* 7EA08 8008E208 2610A200 */  xor        $v0, $a1, $v0
    /* 7EA0C 8008E20C FBFF6104 */  bgez       $v1, .L8008E1FC
    /* 7EA10 8008E210 21284000 */   addu      $a1, $v0, $zero
    /* 7EA14 8008E214 000082A0 */  sb         $v0, 0x0($a0)
  .L8008E218:
    /* 7EA18 8008E218 5835020C */  jal        func_8008D560
    /* 7EA1C 8008E21C 00000000 */   nop
    /* 7EA20 8008E220 2120C002 */  addu       $a0, $s6, $zero
    /* 7EA24 8008E224 1080063C */  lui        $a2, %hi(D_800FE678)
    /* 7EA28 8008E228 78E6C624 */  addiu      $a2, $a2, %lo(D_800FE678)
    /* 7EA2C 8008E22C D42C020C */  jal        func_8008B350
    /* 7EA30 8008E230 21286002 */   addu      $a1, $s3, $zero
    /* 7EA34 8008E234 D035020C */  jal        func_8008D740
    /* 7EA38 8008E238 00000000 */   nop
    /* 7EA3C 8008E23C 21804000 */  addu       $s0, $v0, $zero
    /* 7EA40 8008E240 0D000012 */  beqz       $s0, .L8008E278
    /* 7EA44 8008E244 00000000 */   nop
    /* 7EA48 8008E248 07001716 */  bne        $s0, $s7, .L8008E268
    /* 7EA4C 8008E24C 00000000 */   nop
    /* 7EA50 8008E250 5835020C */  jal        func_8008D560
    /* 7EA54 8008E254 00000000 */   nop
    /* 7EA58 8008E258 E82C020C */  jal        func_8008B3A0
    /* 7EA5C 8008E25C 2120C002 */   addu      $a0, $s6, $zero
    /* 7EA60 8008E260 D035020C */  jal        func_8008D740
    /* 7EA64 8008E264 00000000 */   nop
  .L8008E268:
    /* 7EA68 8008E268 01005226 */  addiu      $s2, $s2, 0x1
    /* 7EA6C 8008E26C 0800422A */  slti       $v0, $s2, 0x8
    /* 7EA70 8008E270 E9FF4014 */  bnez       $v0, .L8008E218
    /* 7EA74 8008E274 00000000 */   nop
  .L8008E278:
    /* 7EA78 8008E278 1A000016 */  bnez       $s0, .L8008E2E4
    /* 7EA7C 8008E27C 21100002 */   addu      $v0, $s0, $zero
  .L8008E280:
    /* 7EA80 8008E280 FFFF3126 */  addiu      $s1, $s1, -0x1
    /* 7EA84 8008E284 B0FF2106 */  bgez       $s1, .L8008E148
    /* 7EA88 8008E288 E0FF9426 */   addiu     $s4, $s4, -0x20
  .L8008E28C:
    /* 7EA8C 8008E28C 5835020C */  jal        func_8008D560
    /* 7EA90 8008E290 00000000 */   nop
    /* 7EA94 8008E294 D02C020C */  jal        func_8008B340
    /* 7EA98 8008E298 2120C002 */   addu      $a0, $s6, $zero
    /* 7EA9C 8008E29C 9A35020C */  jal        func_8008D668
    /* 7EAA0 8008E2A0 00000000 */   nop
    /* 7EAA4 8008E2A4 21804000 */  addu       $s0, $v0, $zero
    /* 7EAA8 8008E2A8 0E000012 */  beqz       $s0, .L8008E2E4
    /* 7EAAC 8008E2AC 21100000 */   addu      $v0, $zero, $zero
    /* 7EAB0 8008E2B0 5835020C */  jal        func_8008D560
    /* 7EAB4 8008E2B4 00000000 */   nop
    /* 7EAB8 8008E2B8 E82C020C */  jal        func_8008B3A0
    /* 7EABC 8008E2BC 2120C002 */   addu      $a0, $s6, $zero
    /* 7EAC0 8008E2C0 D035020C */  jal        func_8008D740
    /* 7EAC4 8008E2C4 00000000 */   nop
    /* 7EAC8 8008E2C8 1800A88F */  lw         $t0, 0x18($sp)
    /* 7EACC 8008E2CC 00000000 */  nop
    /* 7EAD0 8008E2D0 01000825 */  addiu      $t0, $t0, 0x1
    /* 7EAD4 8008E2D4 08000229 */  slti       $v0, $t0, 0x8
    /* 7EAD8 8008E2D8 ECFF4014 */  bnez       $v0, .L8008E28C
    /* 7EADC 8008E2DC 1800A8AF */   sw        $t0, 0x18($sp)
  .L8008E2E0:
    /* 7EAE0 8008E2E0 21100002 */  addu       $v0, $s0, $zero
  .L8008E2E4:
    /* 7EAE4 8008E2E4 4400BF8F */  lw         $ra, 0x44($sp)
    /* 7EAE8 8008E2E8 4000BE8F */  lw         $fp, 0x40($sp)
    /* 7EAEC 8008E2EC 3C00B78F */  lw         $s7, 0x3C($sp)
    /* 7EAF0 8008E2F0 3800B68F */  lw         $s6, 0x38($sp)
    /* 7EAF4 8008E2F4 3400B58F */  lw         $s5, 0x34($sp)
    /* 7EAF8 8008E2F8 3000B48F */  lw         $s4, 0x30($sp)
    /* 7EAFC 8008E2FC 2C00B38F */  lw         $s3, 0x2C($sp)
    /* 7EB00 8008E300 2800B28F */  lw         $s2, 0x28($sp)
    /* 7EB04 8008E304 2400B18F */  lw         $s1, 0x24($sp)
    /* 7EB08 8008E308 2000B08F */  lw         $s0, 0x20($sp)
    /* 7EB0C 8008E30C 0800E003 */  jr         $ra
    /* 7EB10 8008E310 4800BD27 */   addiu     $sp, $sp, 0x48
endlabel func_8008DC60
    /* 7EB14 8008E314 00000000 */  nop
    /* 7EB18 8008E318 00000000 */  nop
    /* 7EB1C 8008E31C 00000000 */  nop
